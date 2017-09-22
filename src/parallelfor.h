//
// Created by Wojciech Jarosz on 9/13/17.
//
#pragma once

#include <functional>

/*!
 * @brief 		Executes the body of a for loop in parallel
 * @param begin	The starting index of the for loop
 * @param end 	One past the ending index of the for loop
 * @param step 	How much to increment at each iteration when moving from begin to end
 * @param body 	The body of the for loop as a lambda, taking two parameters: the iterator index in [begin,end), and the CPU number
 */
void parallel_for(int begin, int end, int step, std::function<void(int, size_t)> body);

/*!
 * @brief	A version of the parallel_for accepting a body lambda that only takes the iterator index as a parameter
 */
void parallel_for(int begin, int end, int step, std::function<void(int)> body);



// adapted from http://www.andythomason.com/2016/08/21/c-multithreading-an-effective-parallel-for-loop/
// license unknown, presumed public domain
inline void parallel_for(int begin, int end, std::function<void(int, size_t)> body)
{
	parallel_for(begin, end, 1, body);
}

inline void parallel_for(int begin, int end, std::function<void(int)> body)
{
	parallel_for(begin, end, 1, body);
}