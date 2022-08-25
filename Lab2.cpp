#include <iostream>
#include <vector>

class Cylinder {
public:
    float H;
    virtual float square() = 0;
    float volume() {
        return H * square();
    }
};

class RoundCylinder : public Cylinder {
public:
    RoundCylinder(int R, int H) : R(R) {
        this->H = H;
    }
    int R;
    virtual float square() {
        return 3.14 * R * R;
    }
};

class RectanglePrizm : public Cylinder {
public:
    RectanglePrizm(int A, int B, int H): A(A), B(B) {
        this->H = H;
    }
    int A, B;
    virtual float square() {
        return A * B;
    }
};

template <typename T>
void printInfo(T& object) {
    std::cout << object.volume() << std::endl;
}

int main() {
    //создание объектов-наследников класса
    RoundCylinder C1(3, 6);
    printInfo(C1);
    RectanglePrizm C2(3, 6, 2);
    printInfo(C2);
    std::cout << "------------" << std::endl;
    // объединение разных видов объектов-наследников класса в один массив
    int N = 10;
    std::vector<Cylinder*> figure_array(N);
    for (int i = 0; i < N; i++)
    {
        if (rand() % 2 == 1)
            figure_array[i] = new RoundCylinder(i + 5, rand() % 5 + 2);
        else
            figure_array[i] = new RectanglePrizm(i + 5, rand() % 5 + 2,
                rand() % 3 + 1);
    }
    for (auto f : figure_array)
        printInfo(*f);
    for (auto& f : figure_array)
        delete f;

    return 0;
}