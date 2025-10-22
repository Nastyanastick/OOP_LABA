#include <iostream> //библиотека для ввода и вывода в С++
#include "laba1.h" //подключаем наш заголовочный файл

int main() {
    int n, m;
    std::cout << "Enter the size of the chocolate:";
    std::cin >> n >> m;

    if ((n < 0) || (m < 0)) {
        std::cout << "Error: incorrect size" << std::endl; //(перевод на новую строку)
        return 1;
    }
    int result = choco(n,m);

    std::cout << "Minimum number of partitions" << result << std::endl;
    return 0;

}