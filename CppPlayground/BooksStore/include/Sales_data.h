#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>

class Sales_data
{
public:
// �����Ĺ��캯��
//Sales_data() = default; // Ĭ�Ϲ��캯��
//    Sales_data(std::string &s = "") : bookNo(s) { }
//    Sales_data(const std::string &s, unsigned n, double p):
//            bookNo(s), units_sold(n), revenue(p*n) { }
//    Sales_data(std::istream&);

// ί�й��캯��
// ��ί�й��캯��ʹ�ö�Ӧ��ʵ�γ�ʼ����Ա
Sales_data(std::string s, unsigned cnt, double price):
    bookNo(s), units_sold(cnt), revenue(price * cnt) { }
// ���๹�캯��ȫ��ί�и���һ�����캯��
Sales_data() : Sales_data("", 0, 0){ }
Sales_data(std::string s) : Sales_data(s, 0, 0) { }
Sales_data(std::istream &is);// ί�и��ڶ������캯��
// �ͺϳɵĿ������캯���ȼ۵Ŀ������캯��������
Sales_data(const Sales_data&);

    // �³�Ա������ Sales_data ����Ĳ���
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // ���ݳ�Ա
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

// Sales_data �ķǳ�Ա�ӿں���
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

#endif // SALES_DATA_H
