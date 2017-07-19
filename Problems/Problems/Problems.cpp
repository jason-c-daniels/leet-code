// Problems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solution.h"
#include <iostream>

int main()
{
   Solution sol;
   string input = "abcdefg";
   std::cout << "Reverse String II" << std::endl;
   std::cout << input << std::endl;
   std::cout << sol.reverseStr(input, 2) << std::endl;

   input = "Let's take LeetCode contest";
   std::cout << "Reverse Words" << std::endl;
   std::cout << input << std::endl;
   std::cout << sol.reverseWords(input) << std::endl;

   auto result = sol.threeSum2(vector<int>({ -2, 0, 1, 1, 2 }));
   result = sol.threeSum2(vector<int>({ -1, 0, 1, 2, -1, -4 }));   
   result = sol.threeSum2(vector<int>({ 1, 2, -2, -1 }));
   result = sol.threeSum2(vector<int>({3, 0, -2, -1, 1, 2}));
   result = sol.threeSum2(vector<int>({ 3, 0, -2, -1, -1, -1, -1, -1, -1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 }));

   auto b = -5 / -1 == sol.divide2(-5, -1);
   b = (long long(-2147483648) / long long(-1)) == sol.divide2(-2147483648, -1);
   b = 1 / -1 == sol.divide2(1, -1);
   b = -1 / -1 == sol.divide2(-1, -1);
   b = 5 / -1 == sol.divide2(5, -1);
   b = 5 / 2 == sol.divide2(5, 2);
   b = 5 / -2 == sol.divide2(5, -2);
   b = 4 / 2 == sol.divide2(4, 2);
   b = 4 / -2 == sol.divide2(4, -2);
   b = -4 / -2 == sol.divide2(-4, -2);
   
   b = INT_MAX == sol.divide(5, 0);
   return 0;
}

