#include<iostream>
#include<array>



template<typename Type,int _size>
class MyClass {


public:
	
	Type& operator[](int i) {
		return data_[i];
	}
	const Type& operator[](int i)const {
		return data_[i];
	}
	// верхние и нижние две функции одинаковые, разное написание
	auto at(int i) -> Type& {
		return data_[i];
	}
	auto at(int i)const ->const Type& {
		return data_[i];
	}

	int size()const {
		return size_;
	}

	class iterator {
	public:
		iterator() = delete;
		iterator(Type*data):data_(data){}

		iterator& operator++() {
			data_++;
			return *this;
		}
		iterator& operator++(int) {
			iterator tmp(*this);
			data_++;
			return tmp;
		}

		bool operator==(const iterator&obj)const {
			return this->data_ == obj.data_;
		}
		bool operator!=(const iterator& obj)const {
			return !this->operator==(obj);
		}

		Type& operator*() {
			return *data_;
		}

	private:
		Type* data_;
	};

	iterator begin() {
		return iterator(data_);
	}
	iterator end() {
		return iterator(data_ + size_);
	}

private:
	Type data_[_size] ;
	const int size_{_size};


};

void f01(MyClass<int,10> a) {
	for (size_t i = 0; i < a.size(); i++) {
		std::cout << a[i] << ' ';
	}
}


int main() {
	MyClass<int,10> a;
	for (size_t i = 0; i < a.size(); i++) {
		a[i] =i+1;
	}
	int arr[10];
	for (size_t i = 0; i < std::size(arr); i++) {
		arr[i] = i + 1;
	}


	std::cout << '\n';
	for (int &e1 : arr) {
		std::cout << e1 << ' ';
	}




	
	std::array<int,10> arrObj;
	for (size_t i = 0; i < std::size(arrObj); i++) {
		arrObj[i] = i + 1;
	}
	std::cout << '\n';

	for (const auto& e1 : arrObj) {
		std::cout << e1 << ' ';
	}
	std::cout << '\n';

	for (const auto& e1 : a) {
		std::cout << e1 << ' ';
	}


	return 0;
}