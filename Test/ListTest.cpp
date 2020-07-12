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
    List<float> floatList {2.5};
    ASSERT_EQ(1, floatList.size());
}

TEST(ListTest, StringListSizeShouldEqual2)
{
    List<std::string> stringList {"one", "two"};
    ASSERT_EQ(2, stringList.size());
}

TEST(ListTest, UnsignedListSizeShouldEqual3)
{
    List<unsigned> unsignedList {1, 2, 3};
    ASSERT_EQ(3, unsignedList.size());
}

TEST(ListTest, BeginShouldReturn0)
{
    List<int> intList {0, 1, 2};
    ASSERT_EQ(0, intList.begin());
}

TEST(ListTest, BeginShouldThrowInvalidArgument)
{
    List<int> intList;
    ASSERT_THROW(intList.begin(), std::invalid_argument);
}

TEST(ListTest, IntListEmptyShouldEqualTrue)
{
    List<int> intList;
    ASSERT_TRUE(intList.empty());
}

TEST(ListTest, IntListEmptyShouldEqualFalse)
{
    List<int> intList {0};
    ASSERT_FALSE(intList.empty());
}

TEST(ListTest, IntListMinShouldEqual0)
{
    List<int> intList {0, 1, 2, 3};
    ASSERT_EQ(0, intList.min());
}

TEST(ListTest, DoubleListMinShouldEqualNegative5)
{
    List<double> doubleList {2.5, 1.75, -5.0, 12.32};
    ASSERT_EQ(-5.0, doubleList.min());
}

TEST(ListTest, IntListMaxShouldEqual3)
{
    List<int> intList {0, 1, 2, 3};
    ASSERT_EQ(3, intList.max());
}

TEST(ListTest, DoubleListMinShouldEqualNegative10)
{
    List<double> doubleList {-10.0, -17.5, -50.0, -123.2};
    ASSERT_EQ(-10.0, doubleList.max());
}

TEST(ListTest, IntClearList1Value)
{
    List<int> intList {0};
    intList.clear();
    ASSERT_TRUE(intList.empty());
}

TEST(ListTest, IntClearList2Value)
{
    List<int> intList {1, 2};
    intList.clear();
    ASSERT_TRUE(intList.empty());
}

TEST(ListTest, IntClearList10Value)
{
    List<int> intList {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    intList.clear();
    ASSERT_TRUE(intList.empty());
}

TEST(ListTest, AtShouldReturn0)
{
    List<int> intList {0, 1, 2, 3};
    ASSERT_EQ(0, intList.at(0));
}

TEST(ListTest, AtShouldReturn3)
{
    List<int> intList {0, 1, 2, 3};
    ASSERT_EQ(3, intList.at(3));
}

TEST(ListTest, AtShouldThrowOutOfRange)
{
    List<int> intList {0, 1, 2, 3};
    ASSERT_THROW(intList.at(4), std::out_of_range);
}

TEST(ListTest, AtShouldThrowOutOfRangeEmptyList)
{
    List<int> intList;
    ASSERT_THROW(intList.at(0), std::out_of_range);
}

TEST(ListTest, AtShouldReturnSecond)
{
    List<std::string> stringList {"First", "Second", "Third"};
    ASSERT_EQ("Second", stringList.at(1));
}

TEST(ListTest, InsertShouldThrowOutOfRange)
{
    List<int> intList {0, 1, 2, 3};
    ASSERT_THROW(intList.insert(5, 0), std::out_of_range);
}

TEST(ListTest, EraseShouldThrowOutOfRange)
{
    List<int> intList {0, 1, 2, 3};
    ASSERT_THROW(intList.erase(4), std::out_of_range);
}
