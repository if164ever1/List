// List01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


template <typename T> class Node
{
public:
    Node* pNext;
    T m_data;
    Node(T data=T(), Node* pNext = nullptr) {
        this->m_data = data;
        this->pNext = pNext;
    }
};



template <typename T> class CList 
{
public:
    CList();
    ~CList();

	void pop_front();
	void clear();
	void push_back(const T& m_data);
	int getSize() const { return m_size; }
	void push_front(const T& m_data);
	void insert(const T& m_value, const int m_index);
	void removeAT(int m_index);
	void pop_back();

	 T& operator [](const int idx) const {
		int m_counter = 0;
		Node<T>* pcurrent = this->m_phead;
		while (pcurrent != nullptr)
		{
			if (m_counter == idx)
			{
				return pcurrent->m_data;
			}
			pcurrent = pcurrent->pNext;
			m_counter++;
		}
	}
private:
    Node<T>* m_phead;
    size_t m_size;
};



int main()
{
	CList<int> m_lst;
	int m_countList = 5;

	for (size_t i = 0; i < m_countList; i++)
		m_lst.push_back(rand() % 100);

	for (size_t i = 0; i < m_countList; i++)
		std::cout << m_lst[i] << " ";

	m_lst.pop_back();
	std::cout << "\nAfter delete\n";
	for (size_t i = 0; i < m_lst.getSize(); i++)
	{
		std::cout << m_lst[i] << " ";
	}

	std::cout << "\n";
	std::cout << m_lst[2];
	m_lst[2] = 555;
	std::cout << m_lst[2];
}

template<typename T>
CList<T>::CList()
{
	m_size = 0;
	m_phead = nullptr;
}

template<typename T>
CList<T>::~CList()
{
	std::cout << "\nWorked destructor\n";
	clear();
}

template<typename T>
void CList<T>::pop_front()
{
	if (m_size) {
		Node<T>* ptemp = m_phead;
		m_phead = m_phead->pNext;
		delete ptemp;
		m_size--;
	}
}

template<typename T>
void CList<T>::clear()
{
	while (m_size)
	{
		pop_front();
	}
}

template<typename T>
void CList<T>::push_back(const T& m_data)
{
	if (m_phead == nullptr)
		m_phead = new Node<T>(m_data);

	else {
		Node<T>* pcurrent = this->m_phead;
		while (pcurrent->pNext != nullptr)
		{
			pcurrent = pcurrent->pNext;
		}
		pcurrent->pNext = new Node<T>(m_data);
	}
	m_size++;
}

template<typename T>
void CList<T>::push_front(const T& m_data)
{
	m_phead = new Node<T>(m_data, m_phead);
	m_size++;
}

template<typename T>
void CList<T>::insert(const T& m_value, const int m_index)
{
	if (!m_index)
		push_front(m_value);
	else {
		Node<T>* pprevius = this->m_phead;
		for (size_t i = 0; i < m_index-1; i++)
		{
			pprevius = pprevius->pNext;
		}
		Node<T>* pnewNode = new Node<T>(m_value, pprevius->pNext);
		pprevius->pNext = pnewNode;
		m_size++;
	}
}

template<typename T>
void CList<T>::removeAT(int m_index)
{
	if (!m_index)
		pop_front();
	else {
		Node<T>* pprevius = this->m_phead;
		for (size_t i = 0; i < m_index-1; i++)
			pprevius = pprevius->pNext;

		Node<T>* ptoDelete = pprevius->pNext;
		pprevius->pNext = ptoDelete->pNext;

		delete ptoDelete;
		m_size--;
	}
}

template<typename T>
void CList<T>::pop_back()
{
	removeAT(m_size - 1);
}
