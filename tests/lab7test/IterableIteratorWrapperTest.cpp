//
// Created by mwypych on 10.04.17.
//

#include <gtest/gtest.h>
#include <memory>
#include <MemLeakTest.h>
#include <Iterable.h>

using ::utility::IterableIterator;
using ::utility::IterableIteratorWrapper;
using ::std::vector;
using ::std::string;
using ::std::make_unique;
using ::std::make_pair;
using ::std::pair;

class IterableIteratorWrapperTests : public ::testing::Test, MemLeakTest {
 public:
};

bool dereference_called = false;
bool next_called = false;
bool not_equals_called = false;

class IteratorMock : public IterableIterator {
 public:
  using ReturnType = pair<int, string>;
  ReturnType Dereference() const override {
    dereference_called = true;
    return make_pair(0,"");
  }
  IterableIterator &Next() override {
    next_called = true;
    return *this;
  }
  bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override {
    not_equals_called = true;
    return false;
  }
  IteratorMock() {
    not_equals_called = false;
    next_called = false;
    dereference_called = false;
  }
};

TEST_F(IterableIteratorWrapperTests,
       ThereIsIterableIteratorWrapperThatTakesUniquePointerToIterableIteratorClassAsItsField) {
  std::unique_ptr<IterableIterator> test_it = std::make_unique<IteratorMock>();
  IterableIteratorWrapper wrapper{move(test_it)};
}

TEST_F(IterableIteratorWrapperTests, IterableIteratorWrapperOverloadsOperatorStarByDereferencingItsField) {
  std::unique_ptr<IterableIterator> test_it = std::make_unique<IteratorMock>();
  IterableIteratorWrapper wrapper{move(test_it)};
  EXPECT_EQ((make_pair<int,string>(0,"")),*wrapper);
  EXPECT_TRUE(dereference_called);
  EXPECT_FALSE(next_called);
  EXPECT_FALSE(not_equals_called);
}

TEST_F(IterableIteratorWrapperTests, IterableIteratorWrapperOverloadsOperatorPreIncrementByCallingNextOfItsField) {
  std::unique_ptr<IterableIterator> test_it = std::make_unique<IteratorMock>();
  IterableIteratorWrapper wrapper{move(test_it)};
  ++wrapper;
  EXPECT_FALSE(dereference_called);
  EXPECT_TRUE(next_called);
  EXPECT_FALSE(not_equals_called);
}


TEST_F(IterableIteratorWrapperTests, IterableIteratorWrapperOverloadsOperatorNotEqualByCallingNotEqualsOfItsField) {
  std::unique_ptr<IterableIterator> test_it = std::make_unique<IteratorMock>();
  IterableIteratorWrapper wrapper{move(test_it)};
  std::unique_ptr<IterableIterator> test_other = std::make_unique<IteratorMock>();
  IterableIteratorWrapper wrapper_other{move(test_other)};
  wrapper != wrapper_other;
  EXPECT_FALSE(dereference_called);
  EXPECT_FALSE(next_called);
  EXPECT_TRUE(not_equals_called);
}


