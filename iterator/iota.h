// iota.h - input iterator 0, 1, 2, ...
#pragma once
#include "input.h"

namespace iterator {

	template<class T>
	class iota : public input_base<T*, T> {
		T t;
	public:
		iota(T t = 0)
			: t(t)
		{ }
		iota(const iota&) = default;
		iota& operator=(const iota&) = default;
		iota(iota&&) = default;
		iota& operator=(iota&&) = default;
		~iota()
		{ }

		T operator*() const
		{
			return t;
		}
		iota& operator++()
		{
			++t;

			return *this;
		}
		iota operator++(int)
		{
			iota i_(*this);

			operator++();

			return i_;
		}
	};

} // iterator

#ifdef _DEBUG
#include <cassert>

inline void test_iota()
{
	iota<int> i;

	assert (*i == 0);
	assert (*++i == 1);
	i++;
	assert (*i == 2);
}

#endif // _DEBUG