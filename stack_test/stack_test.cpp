#include <gtest.h>
#include "stack.h"



TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> stack(4);
	ASSERT_NO_THROW(stack = stack);
}

TEST(TStack, can_get_top_element_of_stack)
{
	TStack<int> stack(4);
	stack.Push(10);
	ASSERT_EQ(10, stack.TopView());
}

TEST(TStack, can_assign_stacks_with_different_sizes)
{
	TStack<int> stack(4), stack_1(5);
	ASSERT_NO_THROW(stack = stack_1);
}

TEST(TStack, can_get_size_of_stack)
{
	TStack<int> stack(5);
	ASSERT_EQ(5, stack.GetSize());
}

TEST(TStack, can_get_top_of_stack)
{
	TStack<int> stack(6);
	stack.Push(4);
	ASSERT_EQ(4, stack.GetTop());
}

TEST(TStack, can_use_copy_constructor)
{
	TStack<int> stack(12);
	stack.Push(2);
	TStack<int> stack_1(stack);
	ASSERT_EQ(stack.GetTop(), stack_1.GetTop());
}

TEST(TStack, cant_create_with_zero_size)
{
	ASSERT_ANY_THROW(TStack<int> s1(0));
}

TEST(TStack, can_create_a_simple_stack)
{
	ASSERT_NO_THROW(TStack<int> s1(10));
}

TEST(TStack, can_push_element_of_stack)
{
	TStack<int> stack(1);
	ASSERT_NO_THROW(stack.Push(10));
}

TEST(TStack, can_check_stack_is_empty)
{
	TStack<int> s1(2);
	ASSERT_EQ(true, s1.IsEmpty());
	s1.Push(1);
	ASSERT_EQ(false, s1.IsEmpty());
}

TEST(TStack, can_check_is_full)
{
	TStack<int> stack(2);
	ASSERT_EQ(false, stack.IsFull());
	stack.Push(1);
	stack.Push(1);
	ASSERT_EQ(true, stack.IsFull());
}

TEST(TStack, cant_push_element_when_he_is_full)
{
	TStack<int> stack(1);
	stack.Push(10);
	ASSERT_ANY_THROW(stack.Push(10));
}

TEST(TStack, cant_get_top_element_when_stack_is_empty)
{
	TStack<int> stack(1);
	ASSERT_ANY_THROW(stack.TopView());
}






