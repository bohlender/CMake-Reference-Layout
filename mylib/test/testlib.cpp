#include <mylib/MyLib.h>
#include <gtest/gtest.h>

TEST(MyLibTest, DummyTest){
    ASSERT_EQ("0.1", MyLib::getVersionString());
}