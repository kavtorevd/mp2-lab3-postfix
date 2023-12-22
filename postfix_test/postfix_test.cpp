#include <gtest.h>
#include "stack.h"
#include "postfix.h"

TEST(TPostfix, can_ToPostfix_string_with_equal_brackets)
{
	TPostfix postfix;
	postfix.SetInfix("((4+((2-1)+3)))");
	ASSERT_NO_THROW(postfix.ToPostfix());
}

TEST(TPostfix, right_Calculation)
{
	TPostfix postfix;
	postfix.SetInfix("10+2");
	postfix.ToPostfix();
	ASSERT_EQ(postfix.Calculate(), 12);
}

TEST(TPostfix, right_to_postfix_SetInfix)
{
	TPostfix postfix;
	postfix.SetInfix("1+2");
	postfix.ToPostfix();
	string tmp;
	tmp = ("1 2+");
	ASSERT_EQ(postfix.GetPostfix(), tmp);
}

TEST(TPostfix, can_SetInfix_with_non_equal_count_brakets)
{
	TPostfix postfix;
	ASSERT_ANY_THROW(postfix.SetInfix(")))((1+2))"));
}

TEST(TPostfix, can_SetInfix_with_equal_count_brakets)
{
	TPostfix postfix;
	ASSERT_NO_THROW(postfix.SetInfix("((4+((2-1)+3)))"));
}

TEST(TPostfix, can_create_postfix)
{
	ASSERT_NO_THROW(TPostfix postfix);
}


TEST(TPostfix, can_SetInfix_void_TPostfix)
{
	TPostfix postfix;
	ASSERT_NO_THROW(postfix.SetInfix(""));
}

TEST(TPostfix, can_ToPostfix_empty_string)
{
	TPostfix postfix;
	postfix.SetInfix("");
	ASSERT_NO_THROW(postfix.ToPostfix());
}

