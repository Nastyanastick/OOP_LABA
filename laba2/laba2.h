#include <string>


class Money{
public:
    Money(const std::string& str); //объект из строки (конструктор)
    Money(const Money& other); //копируем (конструктор); other - параметр который указывает уже на существующий объект
    ~Money(); // когда больше объект не нужен (деструктор)
    Money();

    Money add(const Money& other) const;
    Money minus(const Money& other) const;
    Money copy() const;

    bool men(const Money& other) const;
    bool bol(const Money& other) const;
    bool ravno(const Money& other) const;

    std::string tostr() const;


private:
    size_t size;
    unsigned char* mon;
};