#include <iostream>

using namespace std;

//Êä³ö
void output(int *p, int length) {
    for (int i = 0; i < length; i++) {
        cout << "" << p[i] << " ";
    }
}

void insertSort(int *p, int length) {
    int key, j;
    for (int i = 1; i < length; i++) {
        key = p[i];
        j = i - 1;
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = key;
    }
}

int main(int argc, char *args[]) {
    int buf[10] = {12, 4, 34, 6, 8, 65, 3, 2, 988, 45};
    cout << "ÅÅÐòÇ°:" << endl;
    output(buf, sizeof(buf) / sizeof(int));
    insertSort(buf, sizeof(buf) / sizeof(int));
    cout << endl;
    cout << "ÅÅÐòºó:" << endl;
    output(buf, sizeof(buf) / sizeof(int));
    return 0;
}