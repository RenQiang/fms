# iter - input iterator for numerics

This project solves a much simpler problem than current C++ proposals for ranges.
It provides a limited set of algorithms designed to be easily optimized by modern compilers
to make one pass over constant data that model input iterators.

Enumerators are a input iterators that provide an `operator bool() const` that returns `true` when
it is valid to dereference the iterator. This is similar to `MoveNext` in the `IEnumerator`
C# interface, but fits in better with C++ notions of iteration.

The basic idea is that `enumerator<I,T>` is an input iterator that uses `I` for iteration and returns value_type `T`,
perhaps different from `I::value_type`.
The canonical example is applying a function from T -> U on an input iterator.
The resulting iterator should be of type `enumerator<T,U>`, but we still need the original iterator
in order to do lazy evaluation.
This requires bundling up everything needed for just in time delivery.
The implementation is drastically simplified by passing everything by value.

All classes deriving from `enumerator_base` are quite simple: save the iterator and implement
`operator bool() const`, `operator*`, and `operator++` pre and post increment. That's all!

But this requires some assumptions. I assume that the initial iterator can be dereferenced
to give a meaningful value. It is your job to arrange that. The first time `operator++` is
called is responsible for getting the next dereference in order.

A good example of that is `factorial`. It provides the sequence 1,1,2,6,... It is not just
accumulating the products of iota 0,1,2,...

Most algorithms are O(n), but a few are O(n log n). Anything worse is not acceptable.


operator, => concatenate
operator^ => cycle