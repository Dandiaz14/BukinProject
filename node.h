#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class node
{
public:
    node();

    int getWeight() const;
    string getDestiny() const;

    void setWeight(const int &w);
    void setDestiny(const string &d);

private:
    string destiny;
    int weight;
};

#endif // NODE_H
