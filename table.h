#ifndef TABLE_H
#define TABLE_H
#include <vector>

using namespace std;

class Table
{
public:
    Table(int x, int y, int w, int h, int px, int py)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->px = px;
        this->py = py;
    }

    int x;
    int y;
    int w;
    int h;
    int px;
    int py;
};

#endif // TABLE_H
