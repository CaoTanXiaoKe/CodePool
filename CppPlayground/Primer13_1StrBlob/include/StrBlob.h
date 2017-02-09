#ifndef STRBLOB_H
#define STRBLOB_H
#include <memory>
#include <vector>
#include <string>

// ���� StrBlob �е���Ԫ������˵�� ���ǰ�������Ǳ�Ҫ��
class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
    public:
        typedef std::vector<std::string>::size_type size_type;
        StrBlob():data(std::make_shared<std::vector<std::string>>()) { }
        StrBlob(std::initializer_list<std::string>il):data(std::make_shared<std::vector<std::string>>(il)) { }
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        // ��Ӻ�ɾ��Ԫ��
        void push_back(const std::string &t) { data->push_back(t); }
        void pop_back();

        std::string& front();
        std::string& back();
        const std::string& front() const;
        const std::string& back() const;

        // ����ָ����Ԫ�غ�βԪ�ص� StrBlobPtr
        StrBlobPtr begin();
        StrBlobPtr end();
    private:
        std::shared_ptr<std::vector<std::string>> data;
        void check(size_type i, const std::string &msg) const;
};

// ���ڷ���һ��������Ԫ�صĳ��ԣ� StrBlobPtr�׳�һ���쳣
class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();     // ǰ׺����
private:
    // �����ɹ��� check����һ��ָ�� vector �� shared_ptr
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t i, const std::string& msg) const;
    // ����һ�� waak_ptr�� ��ζ�ŵײ� vector ���ܱ�����
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;       // �������еĵ�ǰλ��
};
#endif // STRBLOB_H
