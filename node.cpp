#include "node.h"

node::node() { }

int node::getWeight() const
{
    return weight;
}

string node::getDestiny() const
{
    return destiny;
}

void node::setWeight(const int &w)
{
    weight = w;
}

void node::setDestiny(const string &d)
{
    destiny = d;
}
