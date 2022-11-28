#include <iostream>
#include "xceptB.h"
using namespace std;

template <class T>
class DinamisBalita
{

    template <class U>
    friend ostream &operator<<(ostream &, const DinamisBalita<U> &);

public:
    DinamisBalita(int size = 0);
    DinamisBalita(const DinamisBalita<T> &v);
    ~DinamisBalita() { delete[] element; }
    T &operator[](int i) const;
    int Size() { return size; }
    DinamisBalita<T> &operator=(const DinamisBalita<T> &v);
    DinamisBalita<T> operator+() const;
    DinamisBalita<T> operator+(const DinamisBalita<T> &v) const;
    DinamisBalita<T> operator-() const;
    DinamisBalita<T> operator-(const DinamisBalita<T> &v) const;
    DinamisBalita<T> operator*(const DinamisBalita<T> &v) const;
    DinamisBalita<T> &operator+=(const T &x);
    DinamisBalita<T> &ReSize(int sz);
    DinamisBalita<T> tambahAKhir(const DinamisBalita<T> &v);

private:
    int size;
    T *element;
};

template <class T>
DinamisBalita<T> DinamisBalita<T>::tambahAKhir(const DinamisBalita<T> &v)
{
    if (this != &v)
    {
        delete[] element;
        element = new T[size];
        for (int i = 0; i < v.size; i++)
            element[i] = v.element[i];
    }
    return *this;
}

template <class T>
DinamisBalita<T>::DinamisBalita(int sz)
{
    if (sz < 0)
        throw BadInitializers();
    size = sz;
    element = new T[sz];
}

template <class T>
DinamisBalita<T>::DinamisBalita(const DinamisBalita<T> &v)
{
    size = v.size;
    element = new T[size];         // get space
    for (int i = 0; i < size; i++) // copy elements
        element[i] = v.element[i];
}

template <class T>
T &DinamisBalita<T>::operator[](int i) const
{
    if (i < 0 || i >= size)
        throw OutOfBounds();
    return element[i];
}
template <class T>
DinamisBalita<T> &DinamisBalita<T>::operator=(const DinamisBalita<T> &v)
{
    if (this != &v)
    {
        size = v.size;
        delete[] element;
        element = new T[size];
        for (int i = 0; i < size; i++)
            element[i] = v.element[i];
    }
    return *this;
}
template <class T>
DinamisBalita<T> DinamisBalita<T>::operator+(const DinamisBalita<T> &v) const
{
    if (size != v.size)
        throw SizeMismatch();
    DinamisBalita<T> w(size);
    for (int i = 0; i < size; i++)
        w.element[i] = element[i] + v.element[i];
    return w;
}
template <class T>
DinamisBalita<T> DinamisBalita<T>::operator-(const DinamisBalita<T> &v) const
{
    if (size != v.size)
        throw SizeMismatch();
    DinamisBalita<T> w(size);
    for (int i = 0; i < size; i++)
        w.element[i] = element[i] - v.element[i];
    return w;
}
template <class T>
DinamisBalita<T> DinamisBalita<T>::operator-() const
{
    DinamisBalita<T> w(size);
    for (int i = 0; i < size; i++)
        w.element[i] = -element[i];
    return w;
}
template <class T>
DinamisBalita<T> DinamisBalita<T>::operator*(const DinamisBalita<T> &v) const
{
    if (size != v.size)
        throw SizeMismatch();
    DinamisBalita<T> w(size);
    for (int i = 0; i < size; i++)
        w.element[i] = element[i] * v.element[i];
    return w;
}
template <class T>
DinamisBalita<T> &DinamisBalita<T>::operator+=(const T &x)
{
    for (int i = 0; i < size; i++)
        element[i] += x;
    return *this;
}

template <class T>
ostream &operator<<(ostream &out, const DinamisBalita<T> &x)
{
    out <<endl;
    // out <<"DATA BALITA POSYANDU BAHAGIA "<<endl;
    for (int i = 0; i < x.size; i++)
    {
        // out << "Data barang ke-" <<  i + 1 << endl;
        out<<"----------------------------------------------"<<endl;
        out << "NAMA      : " << x.element[i].namaBalita << endl;
        out << "IBU       : " << x.element[i].ibu << endl;
        out << "Tinggi    : " << x.element[i].tinggi << endl;
        out << "Berat     : " << x.element[i].berat << endl;
        out<<"----------------------------------------------"<<endl;
    }
    return out;
}
template <class T>
DinamisBalita<T> &DinamisBalita<T>::ReSize(int sz)
{
    if (sz < 0)
        throw BadInitializers();
    delete[] element;
    size = sz;
    element = new T[size];
    return *this;
}   