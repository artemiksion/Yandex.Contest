#include <iostream>
//#include <vector>
using namespace std;

class vector
{
public:
    vector(int size)
    {
        Capacity = 200 * size;
        Size = 0;
        array = new short int[Capacity];
    }
    ~vector()
    {
        delete[] array;
    }
    void push_back(const short int a)
    {
        if (Size >= Capacity)
            increase_capacity();
        array[Size++] = a;
    }
    int size()
    {
        return Size;
    }
    void set_size(const int a)
    {
        Size = a;
    }
    int capacity()
    {
        return Capacity;
    }
    short int& operator[](int i)
    {
        return array[i];
    }
    void increase_capacity()
    {
        Capacity *= 2;
        short int* p = new short int[Capacity];
        for (int i = 0; i < Size; ++i)
            p[i] = array[i];
        delete[] array;
        array = p;
    }
private:
    int Capacity;
    int Size;
    short int* array;
};

inline void AddArray(vector& v, short int*& P, const int& SizeOfP)
{
    int k = v.size() - 1, l = SizeOfP - 1;
    if (v.capacity() < (v.size() + SizeOfP))
        v.increase_capacity();
    if (v[v.size() - 1] <= P[0])
    {
        for (int i = (v.size() + SizeOfP - 1); i >= v.size(); --i)
            v[i] = P[i - v.size()];
        v.set_size(v.size() + SizeOfP);
        return;
    }
    if (v[0] >= P[SizeOfP - 1])
    {
        for (int i = (v.size() + SizeOfP - 1); i >= SizeOfP; --i)
            v[i] = v[i - SizeOfP];
        for (int i = 0; i < SizeOfP; ++i)
            v[i] = P[i];
        v.set_size(v.size() + SizeOfP);
        return;
    }
    for (int i = (v.size() + SizeOfP - 1); i >= 0; --i)
    {
        if ((v[k] >= P[l]) && (k >= 0) || (l < 0))
            v[i] = v[k--];
        else
            v[i] = P[l--];
    }
    v.set_size(v.size() + SizeOfP);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short int NumberOfArrays;
    short int SizeOfCurrentArray;
    cin >> NumberOfArrays;
    if (NumberOfArrays <= 0)
        return 0;
    cin >> SizeOfCurrentArray;
    vector v(SizeOfCurrentArray);// (100 * SizeOfCurrentArray);
    for (short int i = 0; i < SizeOfCurrentArray; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (short int i = 1; i < NumberOfArrays; i++)
    {
        cin >> SizeOfCurrentArray;
        if (SizeOfCurrentArray == 0)
            continue;
        short int* p2 = new short int[SizeOfCurrentArray];
        for (short int j = 0; j < SizeOfCurrentArray; j++)
            cin >> p2[j];
        AddArray(v, p2, SizeOfCurrentArray);
        delete[] p2;
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}