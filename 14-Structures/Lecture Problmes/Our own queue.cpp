#include <iostream>
using namespace std;


#define size 5

struct queue {
    int add;
    int number[size];

    queue(){add = 0;}

    void add_end(int value) {
        if (add < size)
            number[add] = value, add++;

    }
    void add_front(int value) {
        if (add < size)
            for (int i = add - 1; i >= 0; --i)
                number[i + 1] = number[i];
        number[0] = value, add++;
    }
    int remove_front() {
        int value{ number[0] };

        for (int i = 0; i < add - 1; ++i)
            number[i] = number[i + 1];
        add--;
        return value;
    }
    void print() {
        for (int i = 0; i < add; ++i)
            cout << number[i] << " ";
        cout << endl;
    }
};


int main() {
    queue q1;
    q1.add_end(10);
    q1.add_end(20);
    q1.add_end(30);
    q1.print();

    q1.add_front(1);
    q1.add_front(4);
    q1.print();

    cout << q1.remove_front() << endl;
    return 0;
}
