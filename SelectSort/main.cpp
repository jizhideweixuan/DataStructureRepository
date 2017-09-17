#include <iostream>

using namespace std;

//½»»»Î»ÖÃ
void swap(int &a, int &b) {
    a = a + b - (b = a);
}

//Êä³ö
void output(int *p, int length) {
    for (int i = 0; i < length; i++) {
        cout << "" << p[i] << " ";
    }
}

void selectSort(int *p, int length) {
    int tmp;
    for (int i = 0; i < length; i++) {
        tmp = i;
        for (int j = i + 1; j < length; j++) {
            if (p[tmp] > p[j]) {
                tmp = j;
            }
        }
        if (i != tmp) {
            swap(p[i], p[tmp]);
        }
    }
}

int main(int argc, char *args[]) {
    int buf[10] = {12, 4, 34, 6, 8, 65, 3, 2, 988, 45};
    cout << "BeforeSort:" << endl;
    output(buf, sizeof(buf) / sizeof(int));
    selectSort(buf, sizeof(buf) / sizeof(int));
    cout << endl;
    cout << "AfterSort:" << endl;
    output(buf, sizeof(buf) / sizeof(int));
}