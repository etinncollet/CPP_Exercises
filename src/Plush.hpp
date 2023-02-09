#pragma once

class Plush
{
public:
    Plush(int val)
        : _cost{val} {}

    Plush()
        : _cost{10} {}

    int get_cost() const
    {
        return _cost;
    }

    void set_cost(int val)
    {
        _cost = val;
    }

private:
    int _cost = 10;
};