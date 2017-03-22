#include"gtest\gtest.h"
#include"MyStack.h"

TEST(teststack,simpletest)
{
	MyStack st;
	st.push(4);
	EXPECT_EQ(4,st.pop());
}