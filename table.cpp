#include "table.hpp"
void clear(int ** t,size_t m){
  for (size_t i=0; i<m;++i){
    delete[] t[i];
  }
  delete[] t;
}
int ** alloc(size_t m, size_t n){
  int ** t = new int*[m];
  size_t created = 0;
  try
  {
    for (created<n;++created){
      t[created] = new int[n];
    }
  }
  catch(const std::bad_alloc & e)
  {
    clear(t,created);
    throw;
  }
  return t; 
}
void input(std::istream & in,int ** t, size_t m, size_t n)
{
  for (size_t i = 0; i < m;++i)
  {
    for (size_t j = 0;j < n;++j )
    {
      in >> t[i][j];
      if (in.eof())
      {
        throw std::logic_error("Not enough arguments");
      }
      if (in.fail())
      {
        throw std::invalid_argument("Invalid argument");
      }
    }
  }
}
void print(std::ostream & out, const int * const * t, size_t m, size_t n){
  for (size_t i =0;i<m;++i)
  {
    out << t[i][0];
    for (size_t j=1;j<m;++j)
    {
      out << " " << t[i][j];
    }
    out << "\n";
  }
}

int Matrix::rows() const
{
  return  m_;
}

int Matrix::columns() const
{
  return  n_;
}

int ** copy(const int * const * t, size_t m, size_t n )
{
  int ** newt = new int[m];
  size_t created = 0;
  try
  {
    for (created < n; ++created){
      newt[created]=new int[n];
    }
  }
  catch(const std::bad_alloc & e)
  {
    clear(newt, created);
    throw;
  }
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      newt[i][j]=t[i][j];
    }
  }
  return newt;
}