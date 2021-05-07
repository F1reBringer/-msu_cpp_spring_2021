#include "BigInt.h"





bool BigInt::AbsGreater(const BigInt &other) const
{
    if(size_ != other.size_)
    {
        return size_ > other.size_;
    }

    for(size_t i = 0; i < size_; i++)
    {
        if(num_[i] > other.num_[i])
            return true;
        else
            if(num_[i] < other.num_[i])
                return false;
    }

    return true;
}

void BigInt::MakeZeros(size_t size)
{
    delete []num_;
    num_ = new unsigned char[size];
    size_ = size;
    for(size_t i = 0; i < size; i++)
        num_[i] = '0';
}


void BigInt::DeleteZeros()
{
    size_t cnt = 0;
    for(size_t i = 0; i < size_; i++)
    {
        if(num_[i] != 0 + '0')
            break;
        cnt++;
    }
    if(cnt == size_)
    {
        cnt--;
        sign_ = 0;
    }
    unsigned char *buf = new unsigned char[size_ - cnt];
    std::copy(num_ + cnt, num_ + size_, buf);
    delete []num_;
    num_ = buf;
    size_ -= cnt;
}



BigInt::BigInt() : num_(nullptr), sign_(0), size_(0){}

BigInt::BigInt(const std::string & str){
    if(str[0] == '-')
    {
        sign_ = 1;
    }
    else
    {
        sign_ = 0;
    }
    size_t start;
    if(sign_ == 1)
    {
        start = 1;
    }
    else{
        start = 0;
    }
    if(sign_ == 1)
    {
        size_ = str.size() - 1;
    }
    else{
        size_ = str.size();
    }
    num_ = new unsigned char[size_];
    for(size_t i = start; i < size_ + start; i++)
    {
        num_[i - start] = str[i];
        if(str[i] > '9' or str[i] < '0')
        {
            delete []num_;
            throw std::invalid_argument("wrong symbol");
        }
    }
    this->DeleteZeros();
}

BigInt::BigInt(int val){
    if(val < 0)
    {
        sign_ = 1;
    }
    else
    {
        sign_ = 0;
    }
    int tmp;
    if(val < 0)
    {
        tmp = -val;
    }
    else
    {
        tmp = val;
    }
    size_= 0;
    if(tmp == 0)
        size_ = 1;
    while(tmp != 0)
    {
        tmp /= BASE;
        size_ += 1;
    }
    num_ = new unsigned char[size_];
    unsigned char* buf = &num_[size_ - 1];
    if(val < 0)
    {
        tmp = -val;
    }
    else
    {
        tmp = val;
    }
    if(tmp == 0)
        *buf = '0';
    while(tmp != 0)
    {
        *buf = tmp % BASE + '0';
        tmp /= BASE;
        buf--;
    }
}



std::string BigInt::ToString()
{
    std::string result;
    if (sign_ == 1)
        result += '-';
    for (size_t i=0; i < size_; i++)
    result += num_[i];
    return result;
}



BigInt::BigInt(const BigInt& other): sign_(other.sign_), size_(other.size_){
    num_ = new unsigned char[other.size_];
    std::copy(other.num_, other.num_ + size_, num_);
}

BigInt::BigInt(BigInt &&other): sign_(std::move(other.sign_)), size_(std::move(other.size_)){
    num_ = other.num_;
    other.num_ = nullptr;
    other.sign_ = 0;
    other.size_ = 0;
}

BigInt& BigInt::operator=(const BigInt &other)
{
    if(this == &other)
        return *this;
    if(size_ != other.size_)
    {
        delete []num_;
        size_= other.size_;
        num_ = new unsigned char[size_];
    }
    sign_ = other.sign_;
    std::copy(other.num_, other.num_ + size_, num_);
    return *this;
}

BigInt& BigInt::operator=(BigInt &&other)
{
    if(this == &other)
        return *this;
    delete []num_;
    size_ = std::move(other.size_);
    sign_ = std::move(other.sign_);
    num_ = other.num_;
    other.num_ = nullptr;
    other.sign_ = 0;
    other.size_ = 0;
    return *this;
}

BigInt::~BigInt()
{
    delete []num_;
}

bool BigInt::operator < (const BigInt & other) const
{
    if(sign_ == 1 && other.sign_ == 0)
    {
        return true;
    }
    else if(sign_ == 0 && other.sign_ == 1)
    {
            return false;
    }
    else if(sign_ == 1)
    {
        if(size_ != other.size_)
        {
            if(size_ > other.size_)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        for(size_t i = 0; i < size_; i++)
        {
            if(num_[i] > other.num_[i])
                return true;
        }
        return false;
    }
    else
    {
        if(size_ != other.size_)
        {
            if(size_ < other.size_)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        for(size_t i = 0; i < size_; i++)
        {
            if(num_[i] < other.num_[i])
                return true;
        }
        return false;
    }
}

bool BigInt::operator == (const BigInt &other) const
{
    if(size_ != other.size_ || sign_ != other.sign_)
    {
        return false;
    }
    for(size_t i = 0; i < size_; i++)
    {
        if(num_[i] != other.num_[i])
            return false;
    }
    return true;
}


bool BigInt::operator <= (const BigInt &other) const
{
    return ((*this < other) || (*this == other));
}

bool BigInt::operator != (const BigInt &other) const
{
    return !(*this == other);
}

bool BigInt::operator > (const BigInt &other) const
{
    return (!(*this < other) && !(*this == other));
}

bool BigInt::operator >= (const BigInt &other) const
{
    return !(*this < other);
}

BigInt BigInt::operator - () const
{
    BigInt res = *this;
    if(res != 0)
        res.sign_ = !res.sign_;
    return res;
}

BigInt BigInt::operator + (const BigInt &other) const
{
    if(sign_ != other.sign_)
    {
        if(!sign_)
        {
            return (*this - (-other));
        }
        else
        {
            return (other - (-(*this)));
        }
    }
    unsigned char mem = 0;
    size_t i, j;
    BigInt res;
    if(size_ >= other.size_)
    {
        res = *this;
    }
    else
    {
        res = other;
    }
    BigInt small;
    if(size_ >= other.size_)
    {
        small = other;
    }
    else
    {
        small = *this;
    }
    for(i = res.size_ - 1, j = small.size_ - 1; j < small.size_; i--, j--)
    {
        res.num_[i] += mem + small.num_[j] - '0';
        mem = (res.num_[i] > BASE - 1 + '0');
        if(mem)
            res.num_[i] -= BASE;
    }
    for(; i < res.size_ && mem; i--)
    {
        res.num_[i] += 1;
        mem = (res.num_[i] > BASE - 1 + '0');
        if(mem)
            res.num_[i] -= BASE;
    }
    if(mem)
    {
        res.size_ += 1;
        unsigned char *buf = new unsigned char[res.size_];
        std::copy(res.num_, res.num_ + res.size_ - 1, &buf[1]);
        buf[0] = 1 + '0';
        delete []res.num_;
        res.num_ = buf;
    }
    return res;
}

BigInt BigInt::operator - (const BigInt &other) const
{
    if(sign_ != other.sign_)
        return *this + (-other);
    unsigned char mem = 0;
    size_t i, j;
    BigInt res = (this->AbsGreater(other)) ? *this : other;
    res.sign_ = (this->AbsGreater(other)) ? this->sign_ : !other.sign_;
    BigInt small = (this->AbsGreater(other)) ? other : *this;
    for(i = res.size_ - 1, j = small.size_ - 1; j < small.size_; j--, i--)
    {
        res.num_[i] -= (mem + small.num_[j] - '0');
        mem = (res.num_[i] < 0 + '0');
        if(mem)
            res.num_[i] += BASE;
    }
    for(; i < res.size_ && mem; i--)
    {
        res.num_[i] -= 1;
        mem = (res.num_[i] < 0 + '0');
        if(mem)
            res.num_[i] += BASE;
    }
    res.DeleteZeros();
    return res;
}

BigInt BigInt::operator * (const BigInt &other) const
{
    BigInt res;
    if(sign_ != other.sign_)
    {
        res.sign_ = 1;
    }
    else
    {
        res.sign_ = 0;
    }
    res.MakeZeros(size_ + other.size_);
    for(size_t i = size_ - 1; i < size_; i--)
    {
        int mem = 0;
        size_t j = other.size_ - 1;
        for(; j < other.size_; j--)
        {
            size_t cur = res.num_[i + j + 1] + (num_[i] - '0') * (other.num_[j] - '0') + mem - '0';
            res.num_[i + j + 1] = cur % BASE + '0';
            mem = cur / BASE;
        }
        for(long int k = -1; mem; k--)
        {
            size_t cur = res.num_[i + k + 1] + mem - '0';
            res.num_[i + k + 1] = static_cast<unsigned char>(cur % BASE) + '0';
            mem = cur / BASE;
        }
    }
    res.DeleteZeros();
    return res;
}

BigInt BigInt:: operator + (int other) const
{
    return *this + BigInt(other);
}

BigInt BigInt:: operator - (int other) const
{
    return *this - BigInt(other);
}

BigInt BigInt:: operator * (int other) const
{
    return *this * BigInt(other);
}

std::ostream& operator<<(std::ostream& out, const BigInt& n)
{
    if(n.sign_)
        out << '-';
    for(size_t i = 0; i < n.size_; i++)
        out << n.num_[i];
    return out;
}
