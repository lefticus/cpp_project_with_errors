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

int main(int argc, char *argv[])
{
  function(1);
  function(6.3);
  return 0;
}
