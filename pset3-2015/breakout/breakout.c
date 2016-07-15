//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// paddle sizes
double paddleWIDTH = WIDTH/8;
double paddleHEIGHT = HEIGHT/60;
    
// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    // velocity limits
    int minVel = 2;
    int maxVel = 4;
    
    // initial random velocity
    double velocity = 0 + drand48() * 2;
    double velocitx = 2;
    
    // wait before starting the game
    waitForClick(NULL);
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // TODO

        // move circle along x-axis
        move(ball, velocity, velocitx);

        // bounce off right edge of window
        if ((getX(ball) + getWidth(ball)) >= getWidth(window))
        {
            velocity = -velocity;
        }

        // bounce off left edge of window
        if (getX(ball) <= 0)
        {
            velocity = -velocity;
        }
        // bounce off bottom of window
        if ((getY(ball) + getHeight(ball)) >= getHeight(window))
        {   
            setLocation(ball, WIDTH/2,HEIGHT/2);
            
            lives = lives - 1;
            if(lives > 0)
            {
                waitForClick(NULL);
            }
        }
        // bounce off top of window
        if (getY(ball) <= 0)
        {
            velocitx = -velocitx;
        }

        // linger before moving again        
        pause(10);

        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // ensure paddle follows top cursor
                double x = getX(event);
                double y = getY(paddle);
                
                if (x <= paddleWIDTH/2)
                {
                    setLocation(paddle, 0, y);
                }
                else if (x >= WIDTH - paddleWIDTH/2)
                {
                    setLocation(paddle, WIDTH - paddleWIDTH, y);
                }
                else
                {
                    setLocation(paddle, x - paddleWIDTH / 2, y);
                }
            }
        }
        GObject object = detectCollision(window,ball);
        if(object != NULL)
        {
            if (strcmp(getType(object), "GRect") == 0)
            {
                if ( object == paddle)
                {
                    double xpad = getX(paddle) + paddleWIDTH/2;
                    double xbal = getX(ball) + getWidth(ball)/2;
                    if (xpad >= xbal)
                    {
                       velocity = fmod(velocity - drand48(),2); 
                    }
                    else
                    {
                    velocity = fmod(velocity + drand48(),2);
                    }
                    velocitx = -velocitx;
                }
                else
                {
                    removeGWindow(window,object);
                    points = points + 1;
                    bricks = bricks - 1;
                    velocitx = -velocitx;
                    updateScoreboard(window,label,points);
                } 
            }
        }
    }  
          
    // game over or won
    if(lives == 0)
    {
        closeGWindow(window);
        printf("You lose, your score was: %i\n",points);
    }
    else if (bricks == 0)
    {
        closeGWindow(window);
        printf("You won!!!\n");  
    }
    return 0;
}
/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    int brickheight = (HEIGHT/(ROWS+1))/8;
    int brickwidth = WIDTH/(COLS+1);
    int gap = brickwidth/(COLS-1);
    int x = 0 + gap/2;
    int y = 0 + brickheight*3;
    for(int i = 0; i < ROWS; i++)
    {
        for(int z = 0; z < COLS; z++)
        {
            GRect brick = newGRect(x,y,brickwidth,brickheight);
            x = x + brickwidth + gap;
            if(i == 0) setColor(brick, "YELLOW");
            if(i == 1) setColor(brick, "RED");
            if(i == 2) setColor(brick, "GREEN");
            if(i == 3) setColor(brick, "BLUE");
            if(i == 4) setColor(brick, "PINK");                                    
            setFilled(brick, true);
            add(window, brick);
        }
        y = y + brickheight + gap;
        x = 0 + gap/2;
    }   
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval(WIDTH/2-HEIGHT/25,HEIGHT/2- HEIGHT/25,HEIGHT/35,HEIGHT/35);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    GRect paddle = newGRect(WIDTH/2-WIDTH/5/2,HEIGHT-HEIGHT/5,paddleWIDTH,paddleHEIGHT);
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label = newGLabel("0");
    setFont(label, ("SansSerif-60"));
    setColor(label, "LIGHT_GRAY");
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    add(window, label);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
