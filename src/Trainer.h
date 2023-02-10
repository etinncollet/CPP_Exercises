#pragma once

#include <string>
#include <array>

#include "PC.h"
#include "Pokeball.h"

// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(const std::string &name, PC &pc) : _name{name}, _pc{pc}
    {
    }

    const std::string &name() const
    {
        return _name;
    }

    const std::array<Pokeball, 6> &pokeballs() const
    {
        return _team;
    }

    void capture(PokemonPtr poke)
    {
        if (_number < 6)
        {
            _team[_number].store(std::move(poke));
            _number += 1;
        }
        else
        {
            _pc.transfer(std::move(poke));
        }
    }

    void store_in_pc(unsigned int index)
    {
        if (index <= _number)
        {
            _pc.transfer(std::move(_team[index].out()));
        }
    }

private:
    std::string _name;
    PC &_pc;
    std::array<Pokeball, 6> _team;
    unsigned int _number = 0;
};
