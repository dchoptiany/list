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

TEST(ListTest, IntListEmptyShouldEqualTrue)
{
    List<int> intList;
    ASSERT_TRUE(intList.empty());
}

TEST(ListTest, IntListEmptyShouldEqualFalse)
{
    List<int> intList;
    intList.push_back(0);
    ASSERT_FALSE(intList.empty());
}

TEST(ListTest, IntListMinShouldEqual0)
{
    List<int> intList;
    intList.push_back(0);
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    ASSERT_EQ(0, intList.min());
}

TEST(ListTest, DoubleListMinShouldEqualNegative5)
{
    List<double> doubleList;
    doubleList.push_back(2.5);
    doubleList.push_back(1.75);
    doubleList.push_back(-5.0);
    doubleList.push_back(12.32);
    ASSERT_EQ(-5.0, doubleList.min());
}

TEST(ListTest, IntListMaxShouldEqual3)
{
    List<int> intList;
    intList.push_back(0);
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    ASSERT_EQ(3, intList.max());
}

TEST(ListTest, DoubleListMinShouldEqualNegative10)
{
    List<double> doubleList;
    doubleList.push_back(-10.0);
    doubleList.push_back(-17.5);
    doubleList.push_back(-50.0);
    doubleList.push_back(-123.2);
    ASSERT_EQ(-10.0, doubleList.max());
}

TEST(ListTest, IntClearList1Value)
{
    List<int> intList;
    intList.push_back(10);
    intList.clear();
    ASSERT_TRUE(intList.empty());
}

TEST(ListTest, IntClearList2Value)
{
    List<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.clear();
    ASSERT_TRUE(intList.empty());
}

TEST(ListTest, IntClearList10Value)
{
    List<int> intList;
    intList.push_back(10);
    intList.push_back(10);
    intList.push_back(10);
    intList.push_back(10);
    intList.push_back(10);
    intList.push_back(10);
    intList.push_back(10);
    intList.push_back(10);
    intList.push_back(10);
    intList.push_back(10);
    intList.clear();
    ASSERT_TRUE(intList.empty());
}
