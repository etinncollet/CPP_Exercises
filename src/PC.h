#pragma once

#include "Pokemon.h"
#include <vector>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    const std::vector<PokemonPtr> &pokemons() const
    {
        return _save;
    }

    void transfer(PokemonPtr poke)
    {
        _save.emplace_back(std::move(poke));
    }

private:
    std::vector<PokemonPtr> _save;
};
