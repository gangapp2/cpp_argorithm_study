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
		// 현재 capacity 크기가 유지된 채로 clear됨
		if (_buffer)
		{
			delete[] _buffer; // 전체 데이터를 삭제
			_size = 0;
		}

		_buffer = new T[_capacity]; // 같은 capacity로 생성
	}

	void push_back(const T& data)
	{
		if (_size == _capacity) // 용량이 꽉 찼을 경우
		{
			int newCapacity = static_cast<int>(_capacity * 1.5);
			// _capacity의 초기값이 0,1일 경우 예외처리
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity); // 메모리 증설 후 이동
		}
		_buffer[_size] = data;
		_size++;
	}

	void pop_back()
	{
		// 가장 최근 데이터 삭제
		_size--;
	}

	T& back() // 가장 최근 데이터
	{
		return _buffer[_size - 1];
	}

	void reserve(int capacity)
	{
		// 현재 용량이 새 용량보다 더 큰경우 예외처리
		if (_capacity >= capacity)
			return;

		T* newBuffer = new T[capacity];

		for (int i = 0; i < size(); i++)
			newBuffer[i] = _buffer[i];
		
		if(_buffer)
			delete[] _buffer; // 기존 메모리 해제

		_buffer = newBuffer; // 포인터를 증설된 메모리로 이동
	}
	T& operator[](int index)
	{
		assert(index < _size && index >= 0); // 조건 만족하지 않으면 크래시
		return _buffer[index];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }
private:
	T* _buffer = nullptr;
	int _size = 0; // 현재 사용중인 배열 크기
	int _capacity = 0; // 할당받은 배열의 전체 크기
};