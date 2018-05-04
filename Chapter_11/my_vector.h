#include <iostream>
#include <memory>
#include <algorithm>

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

	iterator end() {return avail;}
	const_iterator end() const {return avail;}

	MyVector(const MyVector &init){ create(init.begin(), init.end()); }
	MyVector& operator=(const MyVector &rhs);

	~MyVector() {uncreate();}

	void push_back(const T &new_element);

  private:
	iterator data;	//First element
	iterator avail;	//One past the last created element.
	iterator limit;	//One past the last allocated space.

	std::allocator<T> alloc;

	void create();
	void create(size_type n, const MyVector &init = T());
	void create(const_iterator i, const_iterator j);

	void uncreate();
	
	void grow();
	void unchecked_append(const T &new_val);
};

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector &rhs){
	
  if (this != &rhs){
	uncreate();
  	create(rhs.begin(), rhs.end());
  }

  return *this;

}

template <class T>
void MyVector<T>::push_back(const T &new_element){
	if (avail == limit)
			grow();

	unchecked_append(new_element);
}

template <class T>
void MyVector<T>::create(){
	data = avail = limit = nullptr;
}

template <class T>
void MyVector<T>::create(MyVector::size_type n, const MyVector &init){
	data = alloc.allocate(n);
	avail = limit = data + n;
	std::uninitialized_fill(data, avail, init);
}

template <class T>
void MyVector<T>::create(MyVector::const_iterator i, MyVector::const_iterator j){
	data = alloc.allocate(j - i);
	avail = limit = std::uninitialized_copy(i, j, data);
}

template <class T>
void MyVector<T>::uncreate(){

		if (data){
			auto it = avail;
			while (it != data)
					alloc.destroy(--it);

			alloc.deallocate(data, limit-data);
		
		}
		data = avail = limit = 0;

}

template <class T>
void MyVector<T>::grow(){
	
		size_type new_size = std::max(2*(limit - data), ptrdiff_t(1));

		auto new_data = alloc.allocate(new_size);
		auto new_avail = std::uninitialized_copy(data, avail, new_data);

		uncreate();

		data = new_data;
		avail = new_avail;
		limit = data + new_size;
}

template <class T>
void MyVector<T>::unchecked_append(const T &new_val){
	alloc.construct(avail++, new_val);
}
