#include "Sales_data.h"

// ������ⲿ�����Ա����
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

// �� Sales_data �ĺϳɵĿ������캯���ȼ�
Sales_data::Sales_data(const Sales_data &orig):
    bookNo(orig.bookNo),        // ʹ�� string �Ŀ������캯��
    units_sold(orig.units_sold),    // ���� orig.units_sold
    revenue(orig.revenue)          // ���� orig.revenue
    { }                             // �պ�����

// �� Sales_data �ĺϳɵĿ�����ֵ������ȼ�
Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;        // ���� string::operator=
    units_sold = rhs.units_sold;    // ʹ�����õ� int ��ֵ
    revenue = rhs.revenue;          // ʹ�����õ� double ��ֵ
    return *this;                   // ����һ���Դ˶��������
}

double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// ������ⲿ���� �� Sales_data �ķǳ�Ա�ӿں���
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;       // �� lhs �����ݳ�Ա������ sum
    sum.combine(rhs);           // �� rhs �����ݳ�Ա�ӵ� sum ����
    return sum;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}



