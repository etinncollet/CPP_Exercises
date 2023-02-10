#pragma once

#include <string>
#include <memory>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon() : _name{"Pikachu"}
    {
    }

    Pokemon(const std::string &name) : _name{name}, _id{next_id++}
    {
    }

    Pokemon(const Pokemon &other)
        : Pokemon(other._name)
    {
    }

    const std::string &name() const
    {
        return _name;
    }

    int id() const
    {
        return _id;
    }

    Pokemon &operator=(const Pokemon &other)
    {
        if (this != &other)
        {
            _name = other._name;
        }
        return *this;
    }

    const std::unique_ptr<Trainer> &trainer() const
    {
        return _dress;
    }

private:
    std::string _name;
    int _id;
    static inline int next_id = 0;
    std::unique_ptr<Trainer> _dress;
};

typedef std::unique_ptr<Pokemon> PokemonPtr;