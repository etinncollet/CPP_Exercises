#pragma once
#include <string>
#include "PlushStore.hpp"
#include <iostream>

class Kid
{
public:
    Kid(std::string const &name, int money)
        : _money{money}, _name{name}
    {
    }

    std::string const &get_name() const
    {
        return _name;
    }

    int get_money() const
    {
        return _money;
    }

    void buy_plush(PlushStore &val)
    {
        auto plush = val.buy(_money);
        if (plush.has_value())
        {
            _money -= plush.value().get_cost();
        }
    }

private:
    int _money = 0;
    std::string _name;
};

std::ostream &operator<<(std::ostream &out, const Kid &val)
{
    return out << val.get_name() << " has " << val.get_money() << " euros.";
};