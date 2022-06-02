#ifndef TRANSITIONSCREEN_H__
#define TRANSITIONSCREEN_H__

#include "raylib.h"
#include "rlgl.h"

class TransitionScreen
{
private:
    float increment_line = .12f,
          increment_line_plus = .2f,
          initialIncrementStep = 0.1f,
          minHeightWindow = 0.0f,
          maxHeightWindow = 600.0f,
          minWidthWindow = 0.0f,
          maxWidthWindow = 800.0f;
    Color windowColor = BLACK;
    float initialHeightWindowLeft,
        initialHeightWindowRight,
        currentHeightWindowLeft,
        currentHeightWindowRight,
        currentIncrementStep;
    int sleepTime = 10;
    bool isOpen = true,
         inTransition = false;

    void drawWindowLeft()
    {
        DrawTriangle((Vector2){minWidthWindow, minWidthWindow},
                     (Vector2){minWidthWindow, currentHeightWindowLeft},
                     (Vector2){maxWidthWindow, minWidthWindow}, windowColor);
    }

    void drawWindowRight()
    {
        drawWindow(
            maxWidthWindow, currentHeightWindowRight,
            minHeightWindow, maxHeightWindow,
            maxWidthWindow, maxHeightWindow, windowColor);
    }

    void drawWindow(float a_x, float a_y, float b_x, float b_y, float c_x, float c_y, Color colorWindow)
    {
        DrawTriangle((Vector2){a_x, a_y},
                     (Vector2){b_x, b_y},
                     (Vector2){c_x, c_y}, colorWindow);
    }

public:
    TransitionScreen()
    {
        initialHeightWindowLeft = minHeightWindow;
        initialHeightWindowRight = maxHeightWindow;
        currentHeightWindowLeft = initialHeightWindowLeft;
        currentHeightWindowRight = initialHeightWindowRight;
        currentIncrementStep = initialIncrementStep;
    }

    bool isOpened()
    {
        return isOpen == true;
    }

    void execute()
    {
        drawWindows();
        if(isOpened()){
            if(isValidChangeWindowOpen()){
                changeOnValidWindowOpen();
            }else{
                onFinishedWindowOpen();
            }
        }
    }

    bool isValidChangeWindowOpen(){
        return currentHeightWindowLeft < maxHeightWindow && currentHeightWindowRight > minHeightWindow;
    }

    void changeOnValidWindowOpen(){
        currentHeightWindowLeft += currentIncrementStep;
        currentHeightWindowRight -= currentIncrementStep;
        currentIncrementStep += currentIncrementStep * increment_line + increment_line_plus;
    }

    void onFinishedWindowOpen(){
        isOpen = false;
        currentIncrementStep = initialIncrementStep;
    }

    void drawWindows(){
        drawWindowLeft();
        drawWindowRight();
    }
};

#endif