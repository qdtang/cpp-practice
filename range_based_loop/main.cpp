#include <iostream>
#include <cassert>

template <typename T = long long>
class IntegralRange
{
private:
    T m_begin = 0;
    T m_end = 0;
    T m_span = 1;

public:
    explicit IntegralRange(T end) : m_end{end}
    {
        if (m_begin > m_end)
        {
            m_span = -1;
        }
    }

    IntegralRange(T begin, T end) : m_begin{begin}, m_end{end}
    {
        if (m_begin > m_end)
        {
            m_span = -1;
        }
    }

    IntegralRange(T begin, T end, T span) : m_begin{begin}, m_end{end}, m_span{span}
    {
        if (m_begin < m_end)
        {
            assert(span > 0);
        }
        else
        {
            assert(span <= 0);
        }
    }

    T getSpan() const
    {
        return m_span;
    }

    class iterator
    {
    private:
        const IntegralRange &m_range;
        T m_current;

    public:
        iterator(const IntegralRange &range, T current) : m_range{range}, m_current{current} {}
        T operator*() const
        {
            return m_current;
        }
        bool operator!=(iterator rhs) const
        {
            return m_range.getSpan() > 0 ? m_current < rhs.m_current : m_current > rhs.m_current;
        }
        iterator &operator++()
        {
            m_current += m_range.getSpan();
            return *this;
        }
    };

    iterator begin() const
    {
        return iterator{*this, m_begin};
    }

    iterator end() const
    {
        return iterator{*this, m_end};
    }
};

template <typename Range>
void printRange(const Range& range)
{
    for (const auto& m : range) {
        std::cout << m << " ";
    }
    std::cout << "\n";
}

int main()
{
    printRange(IntegralRange{10});
    printRange(IntegralRange{10, 20});
    printRange(IntegralRange{10, 0});
    printRange(IntegralRange{10, 20, 3});
    printRange(IntegralRange{10, 0, -3});
    return 0;
}