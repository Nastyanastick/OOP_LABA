#include "laba1.h" //подключаем заголовочный файл

int choco(int n, int m) {
    if ((n <= 0) || (m <= 0)){
        return 0;
    }
    return n * m -1;

}