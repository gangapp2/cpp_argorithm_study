#include<iostream>
using namespace std;

template <typename T>
class Node
{
public:
	Node(T data) : _data(data){}
public:
	T _data;
	Node* _prev = nullptr;
	Node* _next = nullptr;
};

// [dummy][nextNode]<->[2]<->[3][dummy]
// [head]						 [tail]
template <typename T>
class List
{
public:
	List() // dummy ��带 head, tail�� �߰�, ���� ����Ű���� �� [dummy]<->[dummy]
	{
		_head = new Node<int>(0); // dummy
		_tail = new Node<int>(0); // dummy
		_head->_next = _tail;
		_tail->_prev = _head;
	}
	~List() // list�� ��� ��带 delete
	{
		Node<T>* node = _head;

		while (node) // node != nullptr, �� _head������ ������ Ž���ϸ鼭 delete�Ѵ�
		{
			Node<T>* deleteNode = node; // ���� node�� �ٱ��Ͽ� ��Ƶ�
			node = node->_next; // ���� node�� �̵���Ŵ
			delete deleteNode; // �ٱ��Ͽ� ��Ƶ� ���� node�� delete
		}
	}
public:	

	void Print()
	{
		// head, tail�� dummy node�̹Ƿ� �� ������ ������ ��� ������ش�
		Node<T>* node = _head->_next;
		while (node != _tail)
		{
			cout << node->_data << endl;
			node = node->_next;
		}
		cout << endl;
	}
	//		[node]
	// [dummy]<->[nextNode]<->[dummy]
	// [head]				   [tail]
	Node<T>* AddAtHead(T data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* nextNode = _head->_next;

		// [head]<->[node]
		node->_prev = _head;
		_head->_next = node;

		// [node]<->[next]
		node->_next = nextNode;
		nextNode->_prev = node;
		/*
		// list�� ó������ node�� �����ϴ� ��� node�� head���� tail�� �ȴ�
		if (_head == nullptr)
		{
			_head = node;
			_tail = node;
		}
		// ���� head ���� nextNode��� �ϰ� node�� nextNode�� ���� ��������� �� node�� head�� �ٲ��ش�
		else
		{
			Node<T>* nextNode = _head;
			node->_next = nextNode;
			nextNode->_prev = node;
			_head = node;
		}
		*/
		return node;
	}

	//					  [node]
	// [dummy]<->[prevNode]<->[dummy]
	// [head]				   [tail]
	Node<T>* AddatTail(T data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = _tail->_prev;

		// [node]<->[tail]
		node->_next = _tail;
		_tail->_prev = node;

		// [prev]<->[node]
		node->_prev = prevNode;
		prevNode->_next = node;

		return node;
	}

	Node<T>* GetNode(int index)
	{
		Node<T>* node = _head->_next;

		if (node == _tail) // list�� ���� ���� ��� ����ó��
			return nullptr;

		for (int i = 0; i < index; i++)
		{
			if (node == _tail->prev) // index�� �Ѿ�� ��� ����ó��
				return nullptr;
			node = node->_next;
		}

		return node;
	}
	
	//					[newNode]
	// [dummy]<->[prevNode]<->[posNode]<->[dummy]
	// [head]	
	Node<T>* Insert(Node<T>* posNode, T data)
	{
		// posNode�� �պκп� newNode�� ���Խ����� ����
		// ���� ��ġ�� �� ��带 prevNode�� ����
		Node<T>* newNode = new Node<T>(data);
		Node<T>* prevNode = posNode->_prev;

		// [prev]<->[newNode]
		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		//[newNode]<->[posNode]
		newNode->_next = posNode;
		posNode->_prev = newNode;

		return newNode;
	}

	//						[remove]
	// [dummy]<->[prevNode]<-[node]->[nextNode]<->[dummy]
	// [head]									   [tail]
	Node<T>* Remove(Node<T>* node)
	{
		// ���� ��� ����� prev, next node�� ���� ����������� node�� �����Ѵ�
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;
		
		// ����
		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		// ���� ���
		delete node;

		return nextNode;
	}
public:
	Node<T>* _tail = nullptr;
	Node<T>* _head = nullptr;

};