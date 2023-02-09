#pragma once
#include <string>
#include <optional>
#include <vector>
#include <iostream>
#include "Plush.hpp"

class PlushStore
{
public:
    PlushStore(std::string const &name) : _name{name} {}

    const std::string &get_name() const
    {
        return _name;
    }

    int get_wealth_amount() const
    {
        return _wealth;
    }

    int get_stock_size() const
    {
        return _stock.size();
    }

    void loan(int nb)
    {
        _wealth += nb;
        _debt = _debt + nb + (nb / 10);
    }

    int get_debt_amount() const
    {
        return _debt;
    }

    int make_plush(int price)
    {

        if (_wealth >= price)
        {
            _xp += 1;
            _stock.emplace_back(price + (3 * _xp));
            _wealth -= price;
            return price + (3 * _xp);
        }
        if (_wealth != 0)
        {
            _xp += 1;
            _stock.emplace_back(price + _xp);
            _wealth = 0;
            return price + _xp;
        }
        return 0;
    }

    int get_experience() const
    {
        return _xp;
    }

    std::optional<Plush> buy(int val)
    {
        int min = (*_stock.begin()).get_cost();
        auto ref = _stock.begin();
        for (auto i = _stock.begin(); i < _stock.end(); i++)
        {
            if (min > (*i).get_cost())
            {
                min = (*i).get_cost();
                ref = i;
            }
        }
        if (val < min)
        {
            return {};
        }
        _wealth += min;
        auto copy = *ref;
        _stock.erase(ref);
        return copy;
    }

private:
    std::string _name;
    int _wealth = 0;
    std::vector<Plush> _stock;
    int _debt = 0;
    int _xp = 0;
};