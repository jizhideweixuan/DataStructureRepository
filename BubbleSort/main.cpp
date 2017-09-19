#include <iostream>

using namespace std;

//����λ��
void swap(int &a, int &b) {
    a = a + b - (b = a);
}

//���
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
    cout << "����ǰ:" << endl;
    output(buf, sizeof(buf) / sizeof(int));
    bubbleSort(buf, sizeof(buf) / sizeof(int));
    cout << endl;
    cout << "�����:" << endl;
    output(buf, sizeof(buf) / sizeof(int));
    return 0;
}