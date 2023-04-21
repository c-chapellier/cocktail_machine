
#pragma once

class Recipe
{
private:
    String name;
    int quantities[6];
    bool haveIce;

    int getQuantitiesSum()
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
            sum += quantities[i];
        return sum;
    }

    int getProportion(int index)
    {
        return quantities[index] / getQuantitiesSum();
    }

public:
    Recipe(String name, int quantities[6], bool haveIce)
        : name(name), haveIce(haveIce)
    {
        for (int i = 0; i < 6; i++)
            this->quantities[i] = quantities[i];
    }

    void serve(int volume)
    {
        // getProportion(0) * volume
    }

    String getName()
    {
        return name;
    }

    int getQuantity(int index)
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
};
