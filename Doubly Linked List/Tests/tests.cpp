#include <iostream>
#include <assert.h>

#include "pch.h"
#include "../Doubly Linked List/TErrorHandler.h"
#include "../Doubly Linked List/TList.h"

class TListFixture : public ::testing::Test {
protected:

    const size_t FILLED_LIST_SIZE{ 10 };
    TList<int>* _filledList;
    TList<int>* _emptyList;

    void SetUp() override {
        _emptyList = new TList<int>;
        assert(_emptyList != nullptr && "Failed to allocate memory.");
        _filledList = new TList<int>;
        assert(_filledList != nullptr && "Failed to allocate memory.");
        fillList(*_filledList);
    }

    void TearDown() override {
        delete _emptyList;
        delete _filledList;
    }

public:

    static void fillList(TList<int>& list) {
        // list < 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 >
        list.pushBack(5);
        list.pushFront(4);
        list.pushBack(6);
        list.pushFront(3);
        list.pushBack(7);
        list.pushFront(2);
        list.pushBack(8);
        list.pushFront(1);
        list.pushBack(9);
        list.pushFront(0);
    }

};

TEST_F(TListFixture, IsEmptyMethodCheck) {
    ASSERT_EQ(_emptyList->isEmpty(), true);
    ASSERT_EQ(_filledList->isEmpty(), false);
}

TEST_F(TListFixture, GetSizeMethodCheck) {
    ASSERT_EQ(_emptyList->getSize(), 0);
    ASSERT_EQ(_filledList->getSize(), FILLED_LIST_SIZE);
}

TEST_F(TListFixture, FrontMethodsThrowCheck) {
    ASSERT_THROW(_emptyList->getFront(), TErrorHandler);
    ASSERT_THROW(_emptyList->popFront(), TErrorHandler);
    ASSERT_NO_THROW(_filledList->getFront(), TErrorHandler);
    ASSERT_NO_THROW(_filledList->popFront(), TErrorHandler);
}

TEST_F(TListFixture, FrontMethodsCheck) {
    ASSERT_EQ(_filledList->getFront(), 0);
    _filledList->popFront();
    ASSERT_EQ(_filledList->getFront(), 1);
    _filledList->pushFront(0);
    ASSERT_EQ(_filledList->getFront(), 0);
}

TEST_F(TListFixture, BackMethodsThrowCheck) {
    ASSERT_THROW(_emptyList->getBack(), TErrorHandler);
    ASSERT_THROW(_emptyList->popBack(), TErrorHandler);
    ASSERT_NO_THROW(_filledList->getBack(), TErrorHandler);
    ASSERT_NO_THROW(_filledList->popBack(), TErrorHandler);
}

TEST_F(TListFixture, BackMethodsCheck) {
    ASSERT_EQ(_filledList->getBack(), 9);
    _filledList->popBack();
    ASSERT_EQ(_filledList->getBack(), 8);
    _filledList->pushBack(9);
    ASSERT_EQ(_filledList->getBack(), 9);
}

TEST_F(TListFixture, ClearMethodCheck) {
    _emptyList->clear();
    ASSERT_EQ(_emptyList->isEmpty(), true);
    _filledList->clear();
    ASSERT_EQ(_filledList->isEmpty(), true);
}

TEST_F(TListFixture, InsertMethodCheck) {
    _filledList->insert(_filledList->end() - 2, 10);
    _filledList->popBack();
    _filledList->popBack();
    ASSERT_EQ(_filledList->getBack(), 10);
    _filledList->insert(_filledList->begin() + 1, -1);
    _filledList->popFront();
    ASSERT_EQ(_filledList->getFront(), -1);
}

TEST_F(TListFixture, EraseMethodCheck) {
    _filledList->erase(_filledList->end() - 2);
    _filledList->popBack();
    _filledList->popBack();
    ASSERT_EQ(_filledList->getBack(), 6);
    _filledList->erase(_filledList->begin() + 1);
    _filledList->popFront();
    ASSERT_EQ(_filledList->getFront(), 2);
}

TEST_F(TListFixture, EraseMethodThrowCheck) {
    ASSERT_THROW(_filledList->erase(_filledList->end()), TErrorHandler);
}

TEST_F(TListFixture, RemoveMethodCheck) {
    _filledList->pushBack(2);
    _filledList->pushBack(2);
    _filledList->pushBack(2);
    ASSERT_EQ(_filledList->remove(2), 4);
    ASSERT_EQ(_emptyList->remove(0), 0);
}

TEST_F(TListFixture, AreEqualCheck) {
    TList<int>* newList{ new TList<int> };
    assert(newList != nullptr && "Failed to allocate memory.");
    fillList(*newList);
    ASSERT_EQ(*newList == *_filledList, true);
    delete newList;
}

