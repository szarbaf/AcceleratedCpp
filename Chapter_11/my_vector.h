#include <iostream>

template <class T>
class MyVector{
  public:

	typedef T* iterator;
	typedef const T* const_iterator;
	typedef std::size_t size_type;
	typedef T value_type;

	MyVector() {create();}
	explicit MyVector(size_type n, const T &init_val = T()) {create(n, init_val);}

	size_type size() const {return limit - data;}
	T& operator[](size_type i) {return data[i];}

	iterator begin() {return data;}
	const_iterator begin() const{return data;}

	iterator end() {return limit;}
	const_iterator end() const {return limit;}

	MyVector(const T &init){ create(init.begin(), init.end()); }
	MyVector& operator=(const MyVector &rhs);

  private:
	T* data;	//First element
	T* limit;	//One past the last element
};

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector &rhs){
	
  if (this != &rhs){
	uncreate();
  	create(rhs.begin(), rhs.end());
  }

  return *this;

}
