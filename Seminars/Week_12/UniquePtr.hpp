#include<iostream>

template<typename T>

class UniquePtr {
	T* ptr;

public:
	UniquePtr(T* ptr);
	UniquePtr(const UniquePtr& other) = delete;
	UniquePtr& operator=(const UniquePtr& other) = delete;
	UniquePtr(UniquePtr&& other)noexcept;
	UniquePtr& operator=(UniquePtr&& other)noexcept;
	~UniquePtr();

	T& operator*();
	const T& operator*() const;
};

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr)
{
	ptr(ptr);
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) noexcept
{
	ptr = other.ptr;
	other.ptr = nullptr;
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept
{
	if (this != &other) {
		delete ptr;
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	return *this;
}

template<typename T>
UniquePtr<T>::~UniquePtr()
{
	delete ptr;
}

template<typename T>
T& UniquePtr<T>::operator*()
{
	return *ptr;
}

template<typename T>
const T& UniquePtr<T>::operator*() const
{
	return *ptr;
}
