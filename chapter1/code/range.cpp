#include <iostream>
#include <vector>

using namespace std;

namespace detail_range
{
    template <typename T>
    class iterator
    {
    public:
        using value_type = T;
        using size_type = size_t;

    private:
        size_type cursor_;
        const value_type step_;
        value_type value_;

    public:
        iterator(size_type cur_start, value_type begin_val, value_type step_val)
            : cursor_(cur_start), value_(begin_val), step_(step_val)
        {
            value_ += (step_ + cursor_);
        }
        value_type operator*() const { return value_; }
        bool operator!=(const iterator &rhs) const
        {
            return (cursor_ != rhs.cursor_);
        }

        iterator &operator++(void)
        {
            value_ += step_;
            ++cursor_;
            return (*this);
        }
    };

    template <typename T>
    class impl
    {
    public:
        using value_type = T;
        using reference = const value_type;
        using const_reference = const value_type;
        using iterator = const detail_range::iterator<value_type>;
        using const_iterator = const detail_range::iterator<value_type>;
        using size_type = size_t;

    private:
        const value_type begin_;
        const value_type end_;
        const value_type step_;
        const size_type max_count_;

        size_type get_adjusted_count(void) const
        {
            if (step_ > 0 && begin_ >= end_)
            {
                throw logic_error("End value must be greater than begin value.");
            }
            else
            {
                if (step_ < 0 && begin_ <= end_)
                {
                    throw logic_error("End value must be less than begin value.");
                }
            }

            size_type x = static_cast<size_type>((end_ - begin_) / stap_);
        }
    };
}
