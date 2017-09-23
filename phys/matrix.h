#pragma once

#include <vector>
#include <sstream>
#include <iostream>
typedef unsigned int uint;

void Throw(const std::string &msg) {
  std::cout << "Error: " << msg;
  throw "";
}
class Matrix
{
  uint m_width;
  uint m_height;
  std::vector<std::vector<double> > m_mem;
  public:
  Matrix(uint height,uint width):m_width(width),m_height(height),m_mem(height,std::vector<double>(height,0.0)) {}
  Matrix(const Matrix &other):m_width(other.m_width),m_height(other.m_height),m_mem(other.m_mem) {};
  Matrix(const std::vector<std::vector<double>> &v):m_width(v.size() ? v[0].size():0),m_height(v.size()),m_mem(v) {for (uint i=0;i<m_height;i++) if (m_mem[i].size()!=m_width) Throw("DimensionsMismatch");}
  Matrix operator*(const Matrix &rhs) const
  {
    if(m_width!=rhs.m_height)
      Throw("DimensionsMismatch");
    Matrix ret(m_height,rhs.m_width);
    for (uint i=0;i<ret.m_height;i++)
    {
      for (uint j=0;j<ret.m_width;j++)
      {
        double v=0;
        for (uint k=0;k<m_width;k++)
          v+=m_mem[i][k]*rhs.m_mem[k][j];
        ret.m_mem[i][j]=v;
      }
    }
    return ret;
  }
  Matrix operator+(const Matrix &rhs) const
  {
    if (m_width!=rhs.m_width  ||
        m_height !=rhs.m_height)
      Throw("DimensionsMismatch");
    Matrix ret(m_height,m_width);
    for (uint i=0;i<ret.m_height;i++)
      for (uint j=0;j<ret.m_width;j++)
        ret.m_mem[i][j]=m_mem[i][j]+rhs.m_mem[i][j];
    return ret;
  }
  const double &at(uint i,uint j) const
  {
    if (i>m_height || j>m_width)
      Throw("DimensionsMismatch");
    return m_mem[i][j];
  }
  double &at(uint i,uint j)
  {
    if (i>m_height || j>m_width)
      Throw("DimensionsMismatch");
    return m_mem[i][j];
  }
  Matrix operator+(const double &rhs) const
  {
    Matrix ret(m_height,m_width);
    for (uint i=0;i<ret.m_height;i++)
      for (uint j=0;j<ret.m_width;j++)
        ret.m_mem[i][j]=m_mem[i][j]+rhs;
    return ret;
  }
  std::string toString() const
  {
    std::stringstream ret;
    for (uint i=0;i<m_height;i++)
    {
      for (uint j=0;j<m_width;j++)
      {
        if (j!=0)
        {
          ret << '\t';
        }
        ret << m_mem[i][j];
      }
      ret << '\n';
    }
    return ret.str();
  }
  Matrix t() const // transpose
  {
    Matrix ret(m_width,m_height);
    for (uint i=0;i<ret.m_height;i++)
      for (uint j=0;j<ret.m_width;j++)
        ret.m_mem[i][j]=m_mem[j][i];
    return ret;
  }
  Matrix dot(const Matrix &rhs) const 
  {
    if ( ( m_height!=1 && m_width!=1 ) || m_height!=rhs.m_height || m_width!=rhs.m_width)
      Throw("DimensionsMismatch");
    if (m_height==1)
      return ((*this)*(rhs.t()));
    else
      return (t()*rhs);
  }
};

Matrix Vector(const std::vector<double> &v) {return Matrix(std::vector<std::vector<double>>(1,v));}
std::ostream &operator<<(std::ostream &os, Matrix const &m) { 
    return os << m.toString();
}
