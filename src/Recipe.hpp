
#pragma once

class Recipe
{
private:
    const char *name;
    const uint8_t color_code;
    const bool haveIce;
    int quantities[6];

    int getQuantitiesSum() const
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
            sum += quantities[i];
        return sum;
    }

public:
    Recipe(const char *name, uint8_t color_code, int quantities[6], bool haveIce)
        : name(name), color_code(color_code), haveIce(haveIce)
    {
        for (int i = 0; i < 6; i++)
            this->quantities[i] = quantities[i];
    }

    const char *getName() const
    {
        return name;
    }

    bool isIced() const
    {
        return this->haveIce;
    }

    double getQuantity(int index) const
    {
        if (index < 0 || index > 5) return -1;
        
        return quantities[index];
    }

    double getProportion(int index) const
    {
        if (index < 0 || index > 5) return -1;
        
        return ((double)quantities[index]) / getQuantitiesSum();
    }

    int setQuantity(int index, int value)
    {
        if (index < 0 || index > 5 || value < 0 || value > 100) return -1;

        quantities[index] = value;
        return 0;
    }

    uint32_t getColorCode() const 
    {
        return this->color_code;
    }
};
