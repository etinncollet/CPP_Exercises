#pragma once

#include "Pokemon.h"
#include <memory>
#include <iostream>

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    bool empty() const
    {
        return !_contains;
    }

    void store(PokemonPtr poke)
    {
        _prisonier = std::move(poke);
        _contains = true;
    }

    const Pokemon &pokemon() const
    {
        return *_prisonier;
    }

    PokemonPtr out()
    {
        return std::move(_prisonier);
    }

private:
    PokemonPtr _prisonier;
    bool _contains = false;
};
