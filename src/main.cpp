// This file is distributed under the BSD License.
// See "license.txt" for details.
// Copyright 2014, Jason Turner (jason@emptycrate.com)

template<typename T>
void function(const T& t)
{
}

class MyClass
{
  public:
    MyClass(int i)
      : m_i(2)
    {
    }

  private:
    int m_i;
    int m_i2;

};

int somefunc()
{
  return 1;
}

int main(int argc, char *argv[])
{
  function(1);
  function(6.3);
  
  
  {
    // shadow a variable in a new scope to cause a new warning
    double argc = 0.9;
  }

  return 0;
}
