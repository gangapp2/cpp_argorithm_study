#pragma once
#include<assert.h>

template <typename T>
class Vector
{
public:
	explicit Vector()
	{
		
	}
	~Vector()
	{
		if (_buffer)
			delete[]_buffer;
	}

	void clear()
	{
		// ���� capacity ũ�Ⱑ ������ ä�� clear��
		if (_buffer)
		{
			delete[] _buffer; // ��ü �����͸� ����
			_size = 0;
		}

		_buffer = new T[_capacity]; // ���� capacity�� ����
	}

	void push_back(const T& data)
	{
		if (_size == _capacity) // �뷮�� �� á�� ���
		{
			int newCapacity = static_cast<int>(_capacity * 1.5);
			// _capacity�� �ʱⰪ�� 0,1�� ��� ����ó��
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity); // �޸� ���� �� �̵�
		}
		_buffer[_size] = data;
		_size++;
	}

	void pop_back()
	{
		// ���� �ֱ� ������ ����
		_size--;
	}

	T& back() // ���� �ֱ� ������
	{
		return _buffer[_size - 1];
	}

	void reserve(int capacity)
	{
		// ���� �뷮�� �� �뷮���� �� ū��� ����ó��
		if (_capacity >= capacity)
			return;

		T* newBuffer = new T[capacity];

		for (int i = 0; i < size(); i++)
			newBuffer[i] = _buffer[i];
		
		if(_buffer)
			delete[] _buffer; // ���� �޸� ����

		_buffer = newBuffer; // �����͸� ������ �޸𸮷� �̵�
	}
	T& operator[](int index)
	{
		assert(index < _size && index >= 0); // ���� �������� ������ ũ����
		return _buffer[index];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }
private:
	T* _buffer = nullptr;
	int _size = 0; // ���� ������� �迭 ũ��
	int _capacity = 0; // �Ҵ���� �迭�� ��ü ũ��
};