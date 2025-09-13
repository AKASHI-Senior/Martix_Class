#include <iostream>
#include <time.h>
#include <ctime>

template<class T>
class Matrix {
private:
    T* arr;
    size_t size;
public:
    //Constructor
    Matrix(size_t s = 5) : arr(new T[s]), size(s) {}

    //Keyboard input
    void keaboard()
    {
        for (size_t i = 0; i < this->size; i++)
            std::cin >> this->arr[i];
    }

    //Random element for matrix
    void rand_Element_matrix()
    {
        for (size_t i = 0; i < this->size; i++)
        {
            arr[i] = rand() % (20 - 5 + 1) + 5;
        }
    }

    //Overload
    Matrix operator+(const Matrix& other)
    {
        if (size != other.size)
            throw std::runtime_error("Размеры матриц разные !");

        Matrix res(size);

        for (size_t i = 0; i < size; i++)
        {
            res.arr[i] = this->arr[i] + other.arr[i];
        }
        return res;
    }

    Matrix operator-(const Matrix& other)
    {
        if (size != other.size)
            throw std::runtime_error("Размеры матриц разные !");

        Matrix res(size);

        for (size_t i = 0; i < size; i++)
        {
            res.arr[i] = this->arr[i] - other.arr[i];
        }
        return res;
    }

    Matrix operator*(const Matrix& other)
    {
        if (size != other.size)
            throw std::runtime_error("Размеры матриц разные !");

        Matrix res(size);
        for (size_t i = 0; i < size; i++)
        {
            res.arr[i] = this->arr[i] * other.arr[i];
        }
        return res;
    }

    Matrix operator/(const Matrix& other)
    {
        if (size != other.size)
            throw std::runtime_error("Размеры матриц разные !");

        Matrix res(size);
        for (size_t i = 0; i < size; i++)
        {
            if (other.arr[i] == 0)
                throw std::runtime_error("Ошибка: деление на ноль!");
            res.arr[i] = this->arr[i] / other.arr[i];
        }
        return res;
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;
        delete[] arr;
        size = other.size;
        arr = new T[size];
        for (size_t i = 0; i < size; i++)
            arr[i] = other.arr[i];
        return *this;
    }

    //Search Max and Min Value
    void max_Matrix()
    {
        T max = arr[0];
        for (size_t i = 1; i < this->size; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        std::cout << "\nМаксимальное значение: " << max << std::endl;
    }

    void min_Matrix()
    {
        T min = arr[0];
        for (size_t i = 1; i < this->size; i++)
        {
            if (arr[i] < min)
                min = arr[i];
        }
        std::cout << "Минимальное значение: " << min << std::endl;
    }

    //Matrix display
    void Display()
    {
        for (size_t i = 0; i < this->size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Matrix()
    {
        delete[] this->arr;
    }
};



int main() {
    setlocale(0, "ru");
    srand(time(NULL));
    Matrix<int> a, b, c, w, e, g;

    std::cout << "Вручную заполните: \n";
    a.keaboard();

    std::cout << "Авто заполнение: \n";
    b.rand_Element_matrix();
    b.Display();

    std::cout << "\nСумма: " << std::endl;
    c = a + b;
    c.Display();

    std::cout << "\nРазность: " << std::endl;
    w = a - b;
    w.Display();

    std::cout << "\nДеление: " << std::endl;
    e = a / b;
    e.Display();

    std::cout << "\nУмножение: " << std::endl;
    g = a * b;
    g.Display();

    std::cout << "\nПоиск max/min в A: " << std::endl;
    a.max_Matrix();
    a.min_Matrix();

    return 0;
}