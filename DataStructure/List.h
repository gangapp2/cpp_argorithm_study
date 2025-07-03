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
	List() // dummy 노드를 head, tail에 추가, 서로 가리키도록 함 [dummy]<->[dummy]
	{
		_head = new Node<int>(0); // dummy
		_tail = new Node<int>(0); // dummy
		_head->_next = _tail;
		_tail->_prev = _head;
	}
	~List() // list의 모든 노드를 delete
	{
		Node<T>* node = _head;

		while (node) // node != nullptr, 즉 _head노드부터 끝까지 탐색하면서 delete한다
		{
			Node<T>* deleteNode = node; // 현재 node를 바구니에 담아둠
			node = node->_next; // 다음 node로 이동시킴
			delete deleteNode; // 바구니에 담아둔 현재 node를 delete
		}
	}
public:	

	void Print()
	{
		// head, tail은 dummy node이므로 그 사이의 값들을 모두 출력해준다
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
		// list에 처음으로 node를 삽입하는 경우 node는 head이자 tail이 된다
		if (_head == nullptr)
		{
			_head = node;
			_tail = node;
		}
		// 기존 head 값을 nextNode라고 하고 node와 nextNode를 서로 연결시켜준 뒤 node를 head로 바꿔준다
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

		if (node == _tail) // list에 값이 없는 경우 예외처리
			return nullptr;

		for (int i = 0; i < index; i++)
		{
			if (node == _tail->prev) // index를 넘어서는 경우 예외처리
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
		// posNode의 앞부분에 newNode를 삽입시켜줄 것임
		// 삽입 위치의 앞 노드를 prevNode로 지정
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
		// 삭제 대상 노드의 prev, next node를 서로 연결시켜준후 node를 삭제한다
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;
		
		// 연결
		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		// 삭제 대상
		delete node;

		return nextNode;
	}
public:
	Node<T>* _tail = nullptr;
	Node<T>* _head = nullptr;

};