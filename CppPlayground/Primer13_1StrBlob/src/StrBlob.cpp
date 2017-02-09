#include "StrBlob.h"
#include <iostream>
// �� StrBlob ��ʵ��
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string & StrBlob::front()
{
    // ��� vector Ϊ�գ� check ���׳�һ���쳣
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back()
{
    // ��� vector Ϊ�գ� check ���׳�һ���쳣
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(size_type i, const std::string& msg) const
{
    if (i >= data->size());
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// �� StrBlobPtr ��ʵ��
std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "derefernmce past end");
    return (*p)[curr];
}

StrBlobPtr & StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();         // ��� vector �Ƿ����
    if (!ret)
        ; //throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        ; //throw std::out_of_range(msg);

    return ret;
}
