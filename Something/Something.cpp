#include <iostream>
#include <initializer_list>
#include <string>

using namespace std;

void print() {
}
template<class First, class... Other>
void print(const First& first, const Other&... other)
{
    cout << first;
    cout << endl;
    print(other...);
}

class Chisla
{
private:
    int* arr;
    size_t size;

public:
    Chisla(const initializer_list<int>& array)
    {
        for (char el : array)if (el % 2 == 0)size++;
        arr = new int[size];

        int i = 0;
        for (char el : array)
        {
            if (el % 2 == 0)
            {
                arr[i] = el;
                i++;
            }
        }
    }

    friend ostream& operator<< (ostream& ost, const Chisla& chisla)
    {
        for (int i = 0; i < chisla.size; i++)
        {
            ost << chisla.arr[i];
            if (i < chisla.size - 1)ost << ", ";
        }
        return ost;
    }


    ~Chisla()
    {
        delete[] arr;
        arr = nullptr;
    }
};

int main()
{
    Chisla new1{ 5, 6, 7, 8, 9 };
    Chisla new2{ 15, 22, 56, 45, 12 };
    print(new1, new2);
}