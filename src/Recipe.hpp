
#pragma once

class Recipe
{
private:
    const char *name;
    const uint8_t color_code;
    int quantities[6];
    bool haveIce;

    int getQuantitiesSum() const
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
            sum += quantities[i];
        return sum;
    }

    int getProportion(int index) const
    {
        return quantities[index] / getQuantitiesSum();
    }

public:
    Recipe(const char *name, uint8_t color_code, int quantities[6], bool haveIce)
        : name(name), color_code(color_code), haveIce(haveIce)
    {
        for (int i = 0; i < 6; i++)
            this->quantities[i] = quantities[i];
    }

    void serve(int volume)
    {
        // getProportion(0) * volume
    }

    const char *getName() const
    {
        return name;
    }

    int getQuantity(int index) const
    {
        if (index < 0 || index > 5) return -1;
        return quantities[index];
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
