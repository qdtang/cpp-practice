#include <iostream>
#include <cassert>

template <typename T = long long>
class IntegralRange
{
private:
    T m_begin = 0;
    T m_end = 0;
    T m_step = 1;

public:
    explicit IntegralRange(T end) : m_end{end}
    {
        if (m_begin > m_end)
        {
            m_step = -1;
        }
    }

    IntegralRange(T begin, T end) : m_begin{begin}, m_end{end}
    {
        if (m_begin > m_end)
        {
            m_step = -1;
        }
    }

    IntegralRange(T begin, T end, T step) : m_begin{begin}, m_end{end}, m_step{step}
    {
        if (m_begin < m_end)
        {
            assert(step > 0);
        }
        else
        {
            assert(step <= 0);
        }
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
            return m_range.m_step > 0 ? m_current < rhs.m_current : m_current > rhs.m_current;
        }
        iterator &operator++()
        {
            m_current += m_range.m_step;
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
