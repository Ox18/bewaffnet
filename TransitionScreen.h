#ifndef TRANSITIONSCREEN_H__
#define TRANSITIONSCREEN_H__

#include "raylib.h"
#include "rlgl.h"

class TransitionScreen
{
private:
    float increment_line = .09f,
          increment_line_plus = .2f,
          initialIncrementStep = 0.1f,
          minWindow = 0.0f,
          maxHeightWindow,
          maxWidthWindow;
    Color windowColor = BLACK;
    float initialHeightWindowLeft,
        initialHeightWindowRight,
        currentHeightWindowLeft,
        currentHeightWindowRight,
        currentIncrementStep;
    bool isOpen = true;

public:
    TransitionScreen(float maxWidthWindow, float maxHeightWindow)
    {
        this->maxHeightWindow = maxHeightWindow;
        this->maxWidthWindow = maxWidthWindow;
        initialHeightWindowLeft = minWindow;
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
            if(currentHeightWindowLeft < maxHeightWindow && currentHeightWindowRight > minWindow){
                currentHeightWindowLeft += currentIncrementStep;
                currentHeightWindowRight -= currentIncrementStep;
                currentIncrementStep += currentIncrementStep * increment_line + increment_line_plus;
            }else{
                currentHeightWindowLeft = maxHeightWindow;
                currentHeightWindowRight = minWindow;
                currentIncrementStep = initialIncrementStep;
                isOpen = false;
            }
        }else{

        }
    }

    void drawWindows()
    {
        drawWindowLeft();
        drawWindowRight();
    }

    void drawWindowLeft()
    {
        drawWindow(
            minWindow, minWindow,
            minWindow, currentHeightWindowLeft,
            maxWidthWindow, minWindow, windowColor);
    }

    void drawWindowRight()
    {
        drawWindow(
            maxWidthWindow, currentHeightWindowRight,
            minWindow, maxHeightWindow,
            maxWidthWindow, maxHeightWindow, windowColor);
    }

    void drawWindow(float a_x, float a_y, float b_x, float b_y, float c_x, float c_y, Color colorWindow)
    {
        DrawTriangle((Vector2){a_x, a_y},
                     (Vector2){b_x, b_y},
                     (Vector2){c_x, c_y}, colorWindow);
    }
};

#endif