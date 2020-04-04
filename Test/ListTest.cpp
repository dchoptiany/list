#include "List.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(ListTest, IntListSizeShouldEqual0)
{
    List<int> emptyList;
    ASSERT_EQ(0, emptyList.size());
}

TEST(ListTest, FloatListSizeShouldEqual1)
{
    List<float> floatList;
    floatList.push_back(2.5);
    ASSERT_EQ(1, floatList.size());
}

TEST(ListTest, StringListSizeShouldEqual2)
{
    List<std::string> stringList;
    stringList.push_back("one");
    stringList.push_back("two");
    ASSERT_EQ(2, stringList.size());
}

TEST(ListTest, UnsignedListSizeShouldEqual3)
{
    List<unsigned> unsignedList;
    unsignedList.push_back(1);
    unsignedList.push_back(2);
    unsignedList.push_back(3);
    ASSERT_EQ(3, unsignedList.size());
}