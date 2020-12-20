#include <iostream>

using namespace std;

template <typename T>
class List
{
	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node<T>* head;

public:
	List();
	~List();

	void push_back(T data);
	int GetSize() { return size; }
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();
	void isClear();
	void findEl(T data);
	void showList();

	T& operator[](const int index);
};

template <typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}
template <typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;

}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}

template<typename T>
void List<T>::isClear()
{
	if (GetSize())
	{
		cout << "List is not clear!" << endl;
	}
	else
	{
		cout << "List is clear!" << endl;
	}
}

template<typename T>
void List<T>::findEl(T data)
{
	int counter = 0;
	Node<T>* current = this->head;
	for (int i = 0; i < size; i++)
	{
		if (current->data == data)
			counter++;
		current = current->pNext;
	}
	cout << "This item is listed " << counter << " times" << endl;
}

template<typename T>
void List<T>::showList()
{
	Node<T>* current = this->head;
	for (int i = 0; i < size; i++)
	{
		cout << current->data << endl;
		current = current->pNext;
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}

int main()
{
	List<int> lst1;

	lst1.isClear();

	lst1.push_front(2);
	lst1.push_back(3);
	lst1.push_front(1);

	lst1.showList();
	cout << endl;

	lst1.isClear();

	lst1.push_back(5);

	lst1.showList();
	cout << endl;

	lst1.insert(4, 3);

	lst1.showList();
	cout << endl;

	lst1.push_back(6);
	lst1.push_back(6);
	lst1.push_back(6);

	lst1.showList();
	cout << endl;

	lst1.findEl(6);

	lst1.pop_back();
	lst1.pop_back();

	lst1.showList();
	/*List<const char*> lst;
	lst.push_front("abc");
	lst.push_front("abcd");
	lst.push_front("abcde");

	lst.showList();
	cout << endl;

	lst.push_back("abcde");

	lst.showList();
	cout << endl;

	lst.findEl("abcde");*/
}
