#ifndef SHARED_PTR_H
#define SHARED_PTR_h

template <typename T>
class SharedPtr {
private:
	size_t* m_count;
	T* m_ptr;

public:
	//构造函数
	SharedPtr(): m_count(new size_t), m_ptr(nullptr) {}
	SharedPtr(T* ptr) : m_count(new size_t), m_ptr(ptr) { m_count = 1; }
	//拷贝构造
	SharedPtr(const SharedPtr& other) {
		m_count = other.m_count;
		m_ptr = other.m_ptr;
		++(*m_count);
	}
	//拷贝赋值运算
	SharedPtr& operator=(const SharedPtr& other) {
		return SharedPtr(std::move(other));
	}
	//移动构造
	SharedPtr(SharedPtr&& other) {
		m_count = other.m_count;
		m_ptr = other.m_ptr;
		++(*m_count);
	}
	//移动赋值运算
	SharedPtr& operator=(SharedPtr&& other) {
		return SharedPtr(std::move(other));
	}

	//解引用
	T& operator*() {
		return *m_ptr;
	}
	//箭头运算
	T* operator->() {
		return m_ptr;
	}
	//重载bool操作符
	operator bool() {
		return m_ptr == nullptr;
	}

	//析构函数
	~SharedPtr() {
		--(*m_count);
		if (*m_count == 0) {
			delete m_count;
			delete m_ptr;
			m_count = nullptr;
			m_ptr = nullptr;
		}
	}

	T* get() {
		return m_ptr;
	}
	size_t use_count() {
		return *m_count;
	}
	bool unique() {
		return *(m_count) == 1;
	}
	void swap(SharedPtr& other) {
		std::swap(this, other);
	}
};



#endif
