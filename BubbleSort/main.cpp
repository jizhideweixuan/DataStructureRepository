#include <iostream>

using namespace std;

//交换位置
void swap(int &a, int &b) {
    a = a + b - (b = a);
}

//输出
void output(int *p, int length) {
    for (int i = 0; i < length; i++) {
        cout << "" << p[i] << " ";
    }
}

void bubbleSort(int *p, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (p[j] > p[j + 1]) {
                swap(p[j], p[j + 1]);
            }
        }
    }
}

int main(int argc, char *args[]) {
    int buf[10] = {12, 4, 34, 6, 8, 65, 3, 2, 988, 45};
    cout << "排序前:" << endl;
    output(buf, sizeof(buf) / sizeof(int));
    bubbleSort(buf, sizeof(buf) / sizeof(int));
    cout << endl;
    cout << "排序后:" << endl;
    output(buf, sizeof(buf) / sizeof(int));
    return 0;
}