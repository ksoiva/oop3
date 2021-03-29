#include <iostream>
#include <string.h>
#define N 20
using namespace std;


class UkrString {
private:

    char* str;
    char substr[N] = {};
    int num = 10, subnum = 0;
    int copnum = 0;

public:

    UkrString(int valuenum) {
        num = valuenum;
        str = nullptr;
    }

    UkrString() {
        num = 20;
        str = {};
    }

    bool operator >= (const UkrString& copstr) {
        for (int i = 0; i < this->num || i < copstr.num; i++) {
            double id1 = (int)this->str[i] + 256.0;
            double id2 = (int)copstr.str[i] + 256.0;
            switch ((int)id1) {
            case 179:
                id1 = 232.2; break;
            case 180:
                id1 = 227.5; break;
            case 186:
                id1 = 229.5; break;
            case 191:
                id1 = 232.6; break;
            case 256:
                id1 = 0.0;
            }
            switch ((int)id2) {
            case 179:
                id2 = 232.2; break;
            case 180:
                id2 = 227.5; break;
            case 186:
                id2 = 229.5; break;
            case 191:
                id2 = 232.6; break;
            case 256:
                id2 = 0.0;
            }
            if (id1 > id2)
                return false;
            if (this->str[i] == '\0' && copstr.str[i] == '\0')
                return false;
            if (id1 < id2)
                return true;
        }
    }

    bool operator * (const UkrString& copstr) {
        if (strstr(this->str, copstr.str) != NULL) {
            return true;
        }
        else return false;
    }

    UkrString& operator = (const UkrString& copstr) {
        if (this->str != nullptr) {
            delete[] str;
        }
        this->num = copstr.num + 1;
        this->str = new char[copstr.num+1];
        int i;
        for (i = 0; i < copstr.num; i++) {
            this->str[i] = copstr.str[i];
        }
        this->str[i] = '\0';
        return *this;
    }

    int SetStr() {
        str = new char[num];
        cout << "Введіть рядок: ";
        gets_s(str, num);
        num = strlen(str);
        return num;
    }

    void Output() {
        puts(str);
    }

    ~UkrString() {
        delete[] str;
    }
};

void Sort(UkrString* coparr, int length) {
    UkrString temp(25);
    temp = coparr[0];

    for (int k = 0; k < length; k++){

        for (int i = k + 1; i < length; i++){

            if (coparr[k] >= coparr[i]){
                temp = coparr[k];
                coparr[k] = coparr[i];
                coparr[i] = temp;
            }
        }
    }
}

int main() {
    system("chcp 1251");
    cout << endl;
    int size = 10;
    UkrString* array;
    array = new UkrString[size];
    int i;

    for (i = 0;; i++) {
       if (array[i].SetStr() == 0) break;
    }
    size = i; 

    Sort(array, size);
    cout << endl;
    for (i = 0; i < size; i++) {
        cout << i + 1 << ". ";
        array[i].Output();
    }
    cout << endl;

    for (int k = 0; k < size - 1; k++) {
        for (i = k + 1; i < size; i++) {
            if (array[k] * array[i] == true)
                cout << "Рядок " << i+1 << " входить у рядок " << k+1 << endl;
            if (array[i] * array[k] == true)
                cout << "Рядок " << k+1 << " входить у рядок " << i+1 << endl;
        }
    }

    delete[] array;
     return 0;
}