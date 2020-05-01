# microsoft

https://leetcode.com/discuss/interview-question/568395/microsoft-online-assessment-max-sum-in-an-array-from-more-than-one-pair

Given an array of N positive integers in random order (duplicates are possible), find a maximum sum that can be generated with more than one pair of array elements. If such sum doesn't exist, return -1.

Function signature (example in C++) is:

int FindMaxSum(std::vector<int>& numbers);

Examples:

{ 25, 4, 28, 1, 5, 1, 17, 2 }

Max sum is 30, from pairs (25, 5) and (28, 2).

{ 25, 15, 28, 1, 6, 17, 2 }

Sum doesn't exist, result is -1.

Elements in an array aren't greater than 1,000,001.
