// pair.h - pair of iterators
#pragma once
#include <utility>
#include "enumerator.h"

namespace iter {

	template<class I, class J,
		class T = typename std::iterator_traits<I>::value_type,
		class U = typename std::iterator_traits<J>::value_type
	>
	class pair_ : public enumerator_<std::pair<I,J>,std::pair<T,U>> {
	public:
		using enumerator_<std::pair<I,J>,std::pair<T,U>>::i;

		pair_()
		{ }
		pair_(I i, J j)
			: enumerator_<std::pair<I,J>,std::pair<T,U>>(std::make_pair(i,j))
		{ }

		explicit operator bool() const
		{
			return i.first && i.second;
		}
		std::pair<T,U> operator*() const
		{
			return std::make_pair(*i.first, *i.second);
		}
		pair_& operator++()
		{
			++i.first;
			++i.second;

			return *this;
		}
		pair_ operator++(int)
		{
			pair_ i_(*this);

			operator++();

			return i_;
		}
	};
	template<class I, class J,
		class T = typename std::iterator_traits<I>::value_type,
		class U = typename std::iterator_traits<J>::value_type
	>
	inline auto pair(I i, J j)
	{
		return pair_<I,J,T,U>(i, j);
	}

} // iter

#ifdef _DEBUG
#include "include/ensure.h"

inline void test_pair()
{
	int a[] = {0,1,2};
	int b[] = {2,4,5};

using namespace iter;


	auto c = pair(std::begin(a),std::begin(b));
	auto f(c);
	c = f;
	ensure (*c == std::make_pair(0,2));
	c = pair(a,b);
	ensure (*c == std::make_pair(0,2));
	c = pair(a,&b[0]);
	ensure (*c == std::make_pair(0,2));

	ensure (*++c == std::make_pair(1,4));
	c++;
	ensure (*c == std::make_pair(2,5));

	c = pair(a,b);
	pair_<int*,int*> d(a,b);
	ensure (c == d);
	++c;
	ensure (c != d);
	d = c;
	ensure (c == d);
}

#endif // _DEBUG