#include "opencv2/core/version.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <curses.h>
#include <iostream>

bool gameover;
using namespace cv;
const int width = 500;
const int height = 500;
int x, y;

enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void Setup()
{
    gameover = false;
    dir = STOP;
    x = width / 2;
    y =height / 2;
}

void DrawAsnake(Mat &img)
{
    const int HEAD_SIZE = 10;
    const int BODY_SIZE = 10; //warning: unused variable ‘BODY_SIZE’ [-Wunused-variable]|
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == y && j == x)
            {
                circle(img, Point(x, y), HEAD_SIZE, Scalar(255, 0, 0), 2);

                rectangle(img, Point(x - 2 * HEAD_SIZE, y), Point(x - HEAD_SIZE, y + HEAD_SIZE / 2), Scalar(255, 0, 0), 2);

            }
            }
    }
}

void SnakeMove()
{



        if (_kbhit()) //error: ‘_kbhit’ was not declared in this scope|

        {


            switch (_getch()) //error: ‘_getch’ was not declared in this scope|
            {
            case 'a'://75
                dir = LEFT;
                break;


            case'w' ://72
                dir = UP;
                break;


            case 'd'://77
                dir = RIGHT;
                break;


            case 's'://80
                dir = DOWN;
                break;


            }

        }

}

void GameLogic()
{
    switch (dir)
    {
    case LEFT:


        x--;
        break;

    case RIGHT:
        x--;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
    default:
        break;
    }
}

int main()
{
    Mat img(500, 800, CV_32FC3);

    Setup();

    while(!gameover)
    {


        imshow("main window", img);
        DrawAsnake(img);
        SnakeMove();
        GameLogic();
        waitKey(20);
        img = Mat::zeros(img.rows, img.cols, CV_32FC3);
        imshow("main window", img);
        x++;
    }
}
