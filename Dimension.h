#ifndef DIMENSION_H
#define DIMENSION_H

#endif // DIMENSION_H

class Dimension
{
public:
    Dimension(){};
    int getSize();
    void setSize(int);
    int getEIndex(int);
    int position;
private:
    int size;
};

int Dimension::getSize()
{
    return size;
}

int Dimension::getEIndex(int coordinate)
{
    return coordinate - 1;
}

void Dimension::setSize(int size)
{
    this->size = size;
}
