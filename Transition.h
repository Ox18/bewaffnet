#ifndef TRANSITION_H_
#define TRANSITION_H_

#include "raylib.h"
#include "rlgl.h"

class Transition
{

public:
    // increment step and line
    float increment_line,
        increment_line_plus,
        initialIncrementStep;
    bool isOpen = false;
    // COLORS
    Color windowColor = BLACK;
    // sizes
    float
        maxHeightWindow,
        maxWidthWindow,
        minWindow,
        initialHeightWindowLeft,
        initialHeightWindowRight,
        currentHeightWindowLeft,
        currentHeightWindowRight,
        currentIncrementStep;
    Transition();
    ~Transition();
    void open();
    void close();
    void drawWindows();
    void drawWindowLeft();
    void drawWindowRight();
    void drawWindow(float a_x, float a_y, float b_x, float b_y, float c_x, float c_y, Color colorWindow);
    void incrementStepOnChange();
    bool isValidChangeOnOpening();
    bool isValidChangeOnClosing();
};

#endif