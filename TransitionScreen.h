#ifndef TRANSITIONSCREEN_H__
#define TRANSITIONSCREEN_H__

#include "raylib.h"
#include "rlgl.h"

class TransitionScreen
{
private:
    float increment_line = .03f,
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

        if (isOpened())
        {
            close();
        }
        else
        {
            open();
        }
    }

    void close()
    {
        if (currentHeightWindowLeft < maxHeightWindow && currentHeightWindowRight > minWindow)
        {
            changeWindows();
        }
        else
        {
            currentHeightWindowLeft = maxHeightWindow;
            currentHeightWindowRight = minWindow;
            currentIncrementStep = initialIncrementStep;
            isOpen = false;
        }
    }

    void open()
    {
        if (currentHeightWindowLeft > minWindow && currentHeightWindowRight < maxHeightWindow)
        {
            changeWindows();
        }
        else
        {
            currentHeightWindowLeft = minWindow;
            currentHeightWindowRight = maxHeightWindow;
            currentIncrementStep = initialIncrementStep;
            isOpen = true;
        }
    }

    void changeWindows()
    {
        currentHeightWindowLeft = isOpened() ? currentHeightWindowLeft + currentIncrementStep : currentHeightWindowLeft - currentIncrementStep;
        currentHeightWindowRight = isOpened() ? currentHeightWindowRight - currentIncrementStep : currentHeightWindowRight + currentIncrementStep;
        incrementStepOnChange();
    }

    void incrementStepOnChange()
    {
        currentIncrementStep += currentIncrementStep * increment_line + increment_line_plus;
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