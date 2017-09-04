//stack_gtest.c
#include<iostream>
#include<gtest/gtest.h>
#include<stack>
using namespace std;

class GlobalStackTest : public testing :: Environment
{
	public:
		virtual void SetUp(){
		cout<<"GlobalSetUp"<<endl;
		}
		
		virtual void TearDown(){
			cout<<"GlobalTearDown"<<endl;
		}

};

TEST(StackTestPush,TestPush)  
{
	stack<int> s1;
	for(int i =0;i<5;i++)
	{
		s1.push(i);
		EXPECT_EQ(s1.top(),i);
	}
}
class StackTest:public testing::Test{
	public:
	virtual void SetUp()
	{
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		s.push(5);
		cout<<"StackTestSetUp"<<endl;
	}
	virtual void TearDown()
	{
		while(s.empty() == false)
		{
			s.pop();
		}
		cout<<"StackTestTearDown"<<endl;
	}
	public:
	stack<int> s;
};

TEST_F(StackTest,TestPop)
{
	for(int i = s.size();i>0;i--)
	{
		EXPECT_EQ(s.top(),i);
		EXPECT_FALSE(s.top() != i);
		s.pop();
	}
}

TEST_F(StackTest,TestSize)
{
	for(int i=5;i>0;i--)
	{
		EXPECT_EQ(s.size(),i);
	    EXPECT_FALSE(s.size() != i);
		s.pop();
	}
}

TEST_F(StackTest,TestTop)
{
	for(int i=s.size();i>0;i--)
	{
		EXPECT_EQ(s.top(),i);
		EXPECT_FALSE(s.top() != i);
		s.pop();
	}
}

TEST_F(StackTest,TestEmpty)
{
	EXPECT_TRUE(s.empty() == false);
	for(int i = s.size();i>0;i--)
	{
		s.pop();
	}
	EXPECT_TRUE(s.empty() == true);
}

int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc,argv);
	testing::Environment* env = new GlobalStackTest();
	testing::AddGlobalTestEnvironment(env);
	return RUN_ALL_TESTS();
}

