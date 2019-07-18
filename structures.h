#include <iostream>
using namespace std;

int main() {
  std::cout << "Hello World!\n";
}

template <class T>
struct OpNewCreator
{
  static T* Create()
  {
    return new T;
  }
};

template <class T>
struct MallocCreator
{
  static T* Create()
  {
    void* buf = std::malloc(sizeof(T));
    if (!buf) return 0;
    return new(buf) t;
  }
};

template <class T>
struct PrototypeCreator
{
  PrototypeCreator (T* pObj = 0)
    :pPrototype_(pOjb)
  {}
  T* Create()
  {
    return pPrototype_ ? pPrototype_->Clone() : 0;
  }
  T* GetPrototype() { return pPrototype_; }
  void setPrototype (T* pOjb) { pPrototype_= pOjb; }
private:
  T pPrototype_;
};