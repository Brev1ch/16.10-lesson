#ifndef TABLE_HPP
#define TABLE_HPP
#include <iostream>
int ** alloc(size_t n, size_t m);
int ** copy(const int * const * t, size_t m, size_t n);
void clear(int ** t, size_t m);
int input(std::istream & in, int ** t, size_t m, size_t n);
void print(std::ostream & out, const int * const * t, size_t m , size_t n);
class Matrix
{
  public:
	~Matrix() {
		::clear(t_, m_);
	}
	Matrix(const Matrix &e)
	{
		::copy(e.t_, e.m_, e.n_);
	}
	Matrix(size_t m, size_t n):
	t_(::alloc(m, n)), m_(m), n_(n)
	{}
	void input(std::istream & in)
	{
		::input(in, t_, m_, n_);
	}
  void print(std::ostream & out)
  {
    ::print(out, t_, m_, n_);
  }
	int rows() const;
	int columns() const;
  private:
	int ** t_;
	size_t m_, n_;  
};
#endif

