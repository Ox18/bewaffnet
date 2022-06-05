#include "Transition.h"

Transition::Transition()
{
    increment_line = .19f,
    increment_line_plus = .2f,
    initialIncrementStep = 0.1f;
    maxHeightWindow = 600.0f;
    maxWidthWindow = 800.0f;
    minWindow = 0.0f;
    initialHeightWindowLeft = 600.0f;
    initialHeightWindowRight = 0.0f;
    currentHeightWindowLeft = 600.0f;
    currentHeightWindowRight = 0.0f;
    currentIncrementStep = 0.1f;
};

Transition::~Transition(){

};

void Transition::open()
{
    if (isValidChangeOnOpening())
    {
        this->currentHeightWindowLeft -= this->currentIncrementStep;
        this->currentHeightWindowRight += this->currentIncrementStep;
        incrementStepOnChange();
    }
    else
    {
        this->currentHeightWindowLeft = 0.0f;
        this->currentHeightWindowRight = 600.0f;
        this->isOpen = true;
        this->currentIncrementStep = this->initialIncrementStep;
    }
};

void Transition::close()
{
    if (isValidChangeOnClosing())
    {
        currentHeightWindowLeft += currentIncrementStep;
        currentHeightWindowRight -= currentIncrementStep;
        incrementStepOnChange();
    }
    else
    {
        currentHeightWindowLeft = 600.0f;
        currentHeightWindowRight = 0.0f;
        this->isOpen = false;
        this->currentIncrementStep = this->initialIncrementStep;
    }
};

void Transition::drawWindows()
{
    drawWindowLeft();
    drawWindowRight();
};

void Transition::drawWindowLeft()
{
    drawWindow(minWindow, minWindow, minWindow, currentHeightWindowLeft, maxWidthWindow, minWindow, windowColor);
};

void Transition::drawWindowRight()
{
    drawWindow(maxWidthWindow, currentHeightWindowRight, minWindow, maxHeightWindow, maxWidthWindow, maxHeightWindow, windowColor);
};

void Transition::drawWindow(float a_x, float a_y, float b_x, float b_y, float c_x, float c_y, Color colorWindow)
{
    DrawTriangle((Vector2){a_x, a_y}, (Vector2){b_x, b_y}, (Vector2){c_x, c_y}, colorWindow);
};

void Transition::incrementStepOnChange()
{

    currentIncrementStep += currentIncrementStep * increment_line + increment_line_plus;
};

bool Transition::isValidChangeOnOpening()
{
    return currentHeightWindowLeft >= minWindow;
};

bool Transition::isValidChangeOnClosing()
{
    return currentHeightWindowLeft <= maxHeightWindow;
};