
#pragma once

class Box
{
private:
    const int x, y, w, h, hSpacing, vSpacing, hNbCases, vNbCases;
    const int caseWidth, caseHeight;

public:
    Box(int x, int y, int w, int h, int hSpacing, int vSpacing, int hNbCases, int vNbCases)
        :
            x(x), y(y), w(w), h(h),
            hSpacing(hSpacing), vSpacing(vSpacing), hNbCases(hNbCases), vNbCases(vNbCases),
            caseWidth((this->w - (this->hSpacing * (this->hNbCases + 1))) / this->hNbCases),
            caseHeight((this->h - (this->vSpacing * (this->vNbCases + 1))) / this->vNbCases)
    {}

    int getCenterX() const
    {
        return this->x;
    }

    int getCenterY() const
    {
        return this->y;
    }

    int getW() const
    {
        return this->w;
    }

    int getH() const
    {
        return this->h;
    }

    int getHSpacing() const
    {
        return this->hSpacing;
    }

    int getVSpacing() const
    {
        return this->vSpacing;
    }

    int getCaseWidth() const
    {
        return this->caseWidth;
    }

    int getCaseHeight() const
    {
        return this->caseHeight;
    }

    int getCaseCenterX(int n) const
    {
        return this->x - this->w/2 + (n%this->hNbCases + 1) * (this->caseWidth + this->hSpacing) - this->caseWidth/2;
    }

    int getCaseCenterY(int n) const
    {
        return this->y - this->h/2 + (n/this->hNbCases + 1) * (this->caseHeight + this->vSpacing) - this->caseHeight/2;
    }

    int getCaseX(int n) const
    {
        return this->getCaseCenterX(n) - this->caseWidth/2;
    }

    int getCaseY(int n) const
    {
        return this->getCaseCenterY(n) - this->caseHeight/2;
    }
};
