#pragma once

#include <iostream>
#include <assert.h>

#include "TErrorHandler.h"

template<typename T>
class TList {
private:

	struct TNode {
		T data;
		TNode* prev;
		TNode* next;
	};

	TNode* _headPtr;
	TNode* _tailPtr;
	size_t _size;

	void initialize() {
		_size = 0;
		_headPtr = new TNode;
		assert(_headPtr != nullptr && "Failed to allocate memory.");
		_tailPtr = new TNode;
		assert(_tailPtr != nullptr && "Failed to allocate memory.");
		_headPtr->next = _tailPtr;
		_tailPtr->prev = _headPtr;
	}

public:
	class TIterator {
	public:

		TIterator() : _iteratorPtr{ nullptr } {}

		TIterator(const TIterator& other) : _iteratorPtr{ other._iteratorPtr } {}

		TIterator(TNode* node) : _iteratorPtr{ node } {}

		TIterator& operator=(const TIterator& other) {
			_iteratorPtr = other._iteratorPtr;
			return *this;
		}

		bool operator!=(const TIterator& other) const {
			return _iteratorPtr != other._iteratorPtr;
		}

		bool operator==(const TIterator& other) const {
			return _iteratorPtr == other._iteratorPtr;
		}

		T& operator*() {
			return _iteratorPtr->data;
		}

		T* operator->() {
			return &(_iteratorPtr->data);
		}

		TIterator& operator++() {
			_iteratorPtr = _iteratorPtr->next;
			return *this;
		}

		TIterator operator++(int) {
			TIterator ptrBeforeIncrementing{ *this };
			_iteratorPtr = _iteratorPtr->next;
			return ptrBeforeIncrementing;
		}

		TIterator& operator--() {
			_iteratorPtr = _iteratorPtr->prev;
			return *this;
		}

		TIterator operator--(int) {
			TIterator ptrBeforeDecrementing{ *this };
			_iteratorPtr = _iteratorPtr->prev;
			return ptrBeforeDecrementing;
		}

		TIterator operator+(const size_t shift) {
			TIterator itr{ _iteratorPtr };
			for (size_t idx{ 0 }; idx < shift; ++idx) {
				++itr;
			}
			return itr;
		}

		TIterator operator-(const size_t shift) {
			TIterator itr{ _iteratorPtr };
			for (size_t idx{ 0 }; idx < shift; ++idx) {
				--itr;
			}
			return itr;
		}

	protected:

		TNode* _iteratorPtr;
		friend class TList<T>;

	};


	class TConstIterator {
	public:

		TConstIterator() : _constIteratorPtr{ nullptr } {}

		TConstIterator(const TConstIterator& other) : _constIteratorPtr{ other._constIteratorPtr } {}

		TConstIterator(TNode* node) : _constIteratorPtr{ node } {}

		TConstIterator& operator=(const TConstIterator& other) {
			_constIteratorPtr = other._constIteratorPtr;
			return *this;
		}

		bool operator!=(const TConstIterator& other) const {
			return _constIteratorPtr != other._constIteratorPtr;
		}

		bool operator==(const TConstIterator& other) const {
			return _constIteratorPtr == other._constIteratorPtr;
		}

		const T& operator*() const {
			return _constIteratorPtr->data;
		}

		const T* operator->() const {
			return &(_constIteratorPtr->data);
		}

		TConstIterator& operator++() {
			_constIteratorPtr = _constIteratorPtr->next;
			return *this;
		}

		TConstIterator operator++(int) {
			TConstIterator ptrBeforeIncrementing{ *this };
			_constIteratorPtr = _constIteratorPtr->next;
			return ptrBeforeIncrementing;
		}

		TConstIterator& operator--() {
			_constIteratorPtr = _constIteratorPtr->prev;
			return *this;
		}

		TConstIterator operator--(int) {
			TConstIterator ptrBeforeDecrementing{ *this };
			_constIteratorPtr = _constIteratorPtr->prev;
			return ptrBeforeDecrementing;
		}

		TConstIterator operator+(const size_t shift) {
			TConstIterator itr{ _constIteratorPtr };
			for (size_t idx{ 0 }; idx < shift; ++idx) {
				++itr;
			}
			return itr;
		}

		TConstIterator operator-(const size_t shift) {
			TConstIterator itr{ _constIteratorPtr };
			for (size_t idx{ 0 }; idx < shift; ++idx) {
				--itr;
			}
			return itr;
		}

	protected:

		TNode* _constIteratorPtr;
		friend class TList<T>;

	};

	TList() {
		initialize();
	}

	TList(const TList& other) {
		initialize();
		for (auto itr{ other.begin() }; itr != other.end(); ++itr) {
			pushBack(*itr);
		}
	}

	TList(TList&& other) {
		_size = other._size;
		_headPtr = other._headPtr;
		_tailPtr = other._tailPtr;
		other._size = 0;
		other._headPtr = nullptr;
		other._tailPtr = nullptr;
	}

	~TList() {
		clear();
		delete _headPtr;
		delete _tailPtr;
	}

	TList& operator=(const TList& other) {
		if (&other == this) {
			return *this;
		}
		clear();
		return *this += other;
	}

	TList& operator=(TList&& other) {
		if (&other == this) {
			return *this;
		}
		clear();
		delete _headPtr; 
		delete _tailPtr; 
		_size = other._size;
		_headPtr = other._headPtr;
		_tailPtr = other._tailPtr;
		other._size = 0;
		other._headPtr = nullptr;
		other._tailPtr = nullptr;
		return *this;
	}

	TIterator begin() {
		return TIterator{ _headPtr->next };
	}

	TConstIterator begin() const {
		return TConstIterator{ _headPtr->next };
	}

	TConstIterator cbegin() const {
		return TConstIterator{ _headPtr->next };
	}

	TIterator end() {
		return TIterator{ _tailPtr };
	}

	TConstIterator end() const {
		return TConstIterator{ _tailPtr };
	}

	TConstIterator cend() const {
		return TConstIterator{ _tailPtr };
	}

	size_t getSize() const {
		return _size;
	}

	bool isEmpty() const {
		return _size == 0;
	}

	T& getFront() {
		if (isEmpty()) {
			throw TListIsEmpty();
		}
		return *begin();
	}

	const T& getFront() const {
		if (isEmpty()) {
			throw TListIsEmpty();
		}
		return *begin();
	}

	T& getBack() {
		if (isEmpty()) {
			throw TListIsEmpty();
		}
		return *(--end());
	}

	const T& getBack() const {
		if (isEmpty()) {
			throw TListIsEmpty();
		}
		return *(--end());
	}

	TIterator erase(TIterator position) {
		if (isEmpty()) {
			throw TListIsEmpty();
		}
		if (position == end() || position == begin() - 1) {
			throw TIncorrectPosition();
		}
		TNode* node{ position._iteratorPtr };
		TIterator nextItr{ node->next };
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
		--_size;
		return nextItr;
	}

	TIterator erase(TIterator begin, TIterator end) {
		TIterator itr{ begin };
		while (itr != end) {
			itr = erase(itr);
		}
		return end;
	}

	size_t remove(const T& value) {
		size_t amount{ 0 };
		auto itr{ begin() };
		while (itr != end()) {
			if (*itr == value) {
				itr = erase(itr);
				++amount;
			} else {
				++itr;
			}
		}
		return amount;
	}

	void clear() {
		while (!isEmpty()) {
			popBack();
		}
	}

	void popBack() {
		erase(--end());
	}

	void popFront() {
		erase(begin());
	}

	void pushBack(const T& value) {
		insert(end(), value);
	}

	void pushFront(const T& value) {
		insert(begin(), value);
	}

	TIterator insert(TIterator before, const T& value) {
		TNode* newNode{ new TNode };
		assert(newNode != nullptr && "Failed to allocate memory.");
		newNode->data = value;
		TNode* prevNode{ before._iteratorPtr->prev };
		prevNode->next = newNode;
		newNode->prev = prevNode;
		newNode->next = before._iteratorPtr;
		before._iteratorPtr->prev = newNode;
		++_size;
		return TIterator(newNode);
	}

	TList& operator+=(const TList& other) {
		for (auto itr{ other.begin() }; itr != other.end(); ++itr) {
			pushBack(*itr);
		}
		return *this;
	}

};

template<typename T>
bool operator!=(const TList<T>& left, const TList<T>& right) {
	return !(left == right);
}

template<typename T>
bool operator==(const TList<T>& left, const TList<T>& right) {
	if (&left == &right) {
		return true;
	}
	if (left.getSize() != right.getSize()) {
		return false;
	}
	for (auto first{ left.begin() }, second{ right.begin() }; first != left.end(); ++first, ++second) {
		if (*first != *second) {
			return false;
		}
	}
	return true;
}

template<typename T>
TList<T> operator+(const TList<T>& left, const TList<T>& right) {
	TList<T> list{ left };
	list += right;
	return list;
}
