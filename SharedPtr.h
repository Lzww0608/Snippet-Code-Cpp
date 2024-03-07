#ifndef SHARED_PTR_H
#define SHARED_PTR_h

template <typename T>
class SharedPtr {
private:
	size_t* m_count;
	T* m_ptr;

public:
	//���캯��
	SharedPtr(): m_count(new size_t), m_ptr(nullptr) {}
	SharedPtr(T* ptr) : m_count(new size_t), m_ptr(ptr) { m_count = 1; }
	//��������
	SharedPtr(const SharedPtr& other) {
		m_count = other.m_count;
		m_ptr = other.m_ptr;
		++(*m_count);
	}
	//������ֵ����
	SharedPtr& operator=(const SharedPtr& other) {
		return SharedPtr(std::move(other));
	}
	//�ƶ�����
	SharedPtr(SharedPtr&& other) {
		m_count = other.m_count;
		m_ptr = other.m_ptr;
		++(*m_count);
	}
	//�ƶ���ֵ����
	SharedPtr& operator=(SharedPtr&& other) {
		return SharedPtr(std::move(other));
	}

	//������
	T& operator*() {
		return *m_ptr;
	}
	//��ͷ����
	T* operator->() {
		return m_ptr;
	}
	//����bool������
	operator bool() {
		return m_ptr == nullptr;
	}

	//��������
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
