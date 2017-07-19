#pragma once
#include <string>
#include <vector>
#include <algorithm>    
#include <climits>

using namespace std;



class Solution {
public:
   /**
   Given a string and an integer k, you need to reverse the first k characters for every 2k
   characters counting from the start of the string. If there are less than k characters
   left, reverse all of them. If there are less than 2k but greater than or equal to k
   characters, then reverse the first k characters and left the other as original.

   Example:
   Input: s = "abcdefg", k = 2
   Output: "bacdfeg"

   Restrictions:
   The string consists of lower English letters only.
   Length of the given string and k will in the range [1, 10000]

   */
   string reverseStr(string s, int k) {
      string result;
      int k2 = 2 * k;
      int rle = 0; // reversal lower end
      auto len = s.length();
      int rue = std::min((size_t)k, len) - 1; // reversal upper end
      int bue = std::min((size_t)k2, len) - 1; // block upper end
      int i = rue;
      do
      {
         result += s[i];
         if (i == rle) {
            i = rue + 1;
         }
         else if (i > rle && i <= rue) {
            i--;
         }
         else if (i == bue && bue < len - 1) {
            rle = bue + 1;
            rue = std::min((size_t)rle + k, len) - 1;
            bue = std::min((size_t)rle + k2, len) - 1;
            i = rue;
         }
         else {
            i++;
         }
      } while (i < len);
      return result;
   }


   /**
   Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

   Example 1:
   Input: "Let's take LeetCode contest"
   Output: "s'teL ekat edoCteeL tsetnoc"
   Note: In the string, each word is separated by single space and there will not be any extra space in the string.
   */
   string reverseWords(string s) {
      string result;
      string seg;
      for (int i = 0; i < s.length(); i++)
      {
         if (s[i] == ' ') {
            for (auto it = seg.rbegin(); it != seg.rend(); it++) result += *it;
            seg.clear();
            result += s[i];
         }
         else
            seg += s[i];
      }
      for (auto it = seg.rbegin(); it != seg.rend(); it++) result += *it;
      return result;
   }

   /**
   There are two sorted arrays nums1 and nums2 of size m and n respectively.

   Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

   Example 1:
      nums1 = [1, 3]
      nums2 = [2]

      The median is 2.0
   Example 2:
      nums1 = [1, 2]
      nums2 = [3, 4]

      The median is (2 + 3)/2 = 2.5

  Example 3:
      nums1 = [1, 3, 5, 14]
      med1=4
      nums2 = [2, 3, 4, 15]
      med2=3.5
      The median is (3 + 4)/2 = 3.5

 Example 4:
      nums1 = [1, 1, 1, 1]
      nums2 = [2, 2, 2, 2]
      The median is (1 + 2)/2 = 1.5

 Example 5:
      nums1 = [1, 1, 1, 1, 1]
      nums2 = [2, 2, 2, 2]
      The median is 1.0
   */
   double median(vector<int>& sorted) {
      auto n = sorted.size();
      auto mid = n / 2;
      return n % 2 == 0 ? (sorted[mid] + sorted[mid + 1]) / 2.0 : sorted[mid];
   }

   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      auto med1 = median(nums1);
      auto med2 = median(nums2);
      if (med1 == med2) return med1;
      // I got stumped with how to constrain this to O(log(m+n)) time. Moved on to another challenge
      // the simple brute force approach is to merge the two vectors into one then select the median.
      // that is O(m+n)
      // will come back later. I'm sure I can find a precanned solution online. But that's no fun.
   }


   /**
   You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

   You may assume the two numbers do not contain any leading zero, except the number 0 itself.

   Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
   Output: 7 -> 0 -> 8
   */
   struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
   };
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* res = NULL;
      ListNode* cd = NULL;
      int carry = 0;
      do
      {
         auto v = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
         auto d = new ListNode(v % 10);
         if (res == NULL) res = d;
         if (cd != NULL) cd->next = d;
         else cd = d;

         carry = v / 10;

         // move next digit
         if (l1) l1 = l1->next;
         if (l2) l2 = l2->next;
         if (cd->next) cd = cd->next;

      } while (l1 != NULL || l2 != NULL);

      if (carry) cd->next = new ListNode(1);

      return res;
   }

   /**
   Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
   Find all unique triplets in the array which gives the sum of zero.

   Note: The solution set must not contain duplicate triplets.

   For example, given array S = [-1, 0, 1, 2, -1, -4],

   A solution set is:
   [[-1, 0, 1],[-1, -1, 2]]

   [-1, 0, 1, 2, -1, -4] -> [[-1, 0, 1],[-1, -1, 2]]

   [ -2, 0, 1, 1, 2 ]   ->  []

   [ 1, 2, -2, -1 ]     ->  []

   [3, 0, -2, -1, 1, 2] ->  [???]
   Step 1. Sort it [-2, -1, 0, 1, 2, 3]
   Step 2.
     l = 0, r=n-1=5
     vl=-2, vr=3, t=-1
     find t -> [-2, -1, 3]


   */
   vector<vector<int>> threeSum(vector<int>& nums) {
      // this is ugly code. It works. But it's brute force. There's likely a more elegant solution.
      // but it was time to eat lunch, hunger was distracting me. Yeah. I know that'll never fly in a job interview
      // muchless on the job. Of course on the job you have more time.
      vector<vector<int>> results;
      vector<int> tzs({ 0,0,0 });

      // first sort the input vector O(n*log(n))
      std::sort(nums.begin(), nums.end());
      auto len = nums.size();
      size_t l = 0;

      for (int l = 0; l < len - l - 1; l++) {
         for (int r = len - l - 1; r > l; r--) {
            tzs[0] = nums[l];
            tzs[1] = nums[r];
            tzs[2] = 0 - (nums[l] + nums[r]);
            if (binary_search(nums.begin() + l + 1, nums.begin() + r, tzs[2]))
            {
               std::sort(tzs.begin(), tzs.end());
               results.push_back(tzs);
            }
         }
      }
      std::sort(results.begin(), results.end());
      // remove duplicates
      for (int i = 1; i < results.size(); ) {
         if (results[i - 1] == results[i]) {
            results.erase(results.begin() + i);
         }
         else {
            i++;
         }
      }
      return results;
   }

   vector<vector<int>> threeSum2(vector<int>& num) {
      /* This is a more efficient method posted in the discussion area. originally coded in Java.
      I had to add a total size check, because APPARENTLY they pass in a vector with < 3 items.
      They fail to state this in the problem statement. In fact it implies you will only have >=3. Bad form guys!
      As a result, < 3 items causes a runtime binding issue on their server (exception in VC++).

      After examining this code, it's a similar approach to what I initially abandoned. I wish i'd stuck with it.
      It would have taken me more than 45 minutes tho. I've been trying to constrain my solutions to that
      as a matter of practicing for an up coming interview with Amazon.
      */
      vector<vector<int>> res;
      if (num.size() < 3) return res;
      std::sort(num.begin(), num.end());
      // scan all items, take the negative of this item as the target sum. (yes, this is the TARGET value.)
      for (int i = 0; i < num.size() - 2; i++) {
         // so long as we aren't on a duplicate number, or are on the first. (we can't compare back one to check for duplicate...)
         // examine for a match.
         if (i == 0 || (i > 0 && num[i] != num[i - 1])) {
            // initially look ahead by one, and at the last item.
            int lo = i + 1, hi = num.size() - 1, sum = 0 - num[i];
            // keep scanning from front to back. As with the target skipping duplicates as they occur.
            while (lo < hi) {
               // if the sum of the hi+lo indicies is the sum, then we know that num[i]+num[lo]+num[hi]==0
               // this is because we negated the target. Simple, right? Yes. And very clever!
               if (num[lo] + num[hi] == sum) {
                  vector<int> triple({ num[i], num[lo], num[hi] });
                  // push the result.
                  res.push_back(triple);
                  // skip the hi and lo duplicates.
                  while (lo < hi && num[lo] == num[lo + 1]) lo++;
                  while (lo < hi && num[hi] == num[hi - 1]) hi--;
                  // move next for hi and lo.
                  lo++; hi--;
               }
               // otherwise, if it's not a match and is less than the sum we know just the lo needs to advance.
               else if (num[lo] + num[hi] < sum) lo++;
               // otherwise just the hi needs to advance.
               else hi--;
            }
            /*EDITORIAL: In my abandoned solution, I wasn't a) skipping duplicates *derp* and b) I was advancing BOTH. Big big mistake.
                         But. I was on the right track. This is basically an N^2 solution in worst case.
                         My brute force, above, was... N^2*log(N) at best... not so good.
            */
         }
      }
      return res;
   }
   /*
   Given a linked list, swap every two adjacent nodes and return its head.

   For example,
   Given 1->2->3->4, you should return the list as 2->1->4->3.

   Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
   */
   ListNode* swapPairs(ListNode* head) {
      if (head == NULL) return NULL;
      ListNode dummyHead(-1);
      ListNode *c = NULL, *p = NULL;
      dummyHead.next = head;
      p = &dummyHead;
      c = head;
      do
      {
         // swap
         auto n = c->next;
         if (n) {
            c->next = n->next;
            p->next = n;
            n->next = c;
         }
         p = c;
         c = c->next;
      } while (c != NULL);
      return dummyHead.next;
   }


   long divide(long dividend, long divisor) {
      // rejected, too slow. examined an accepted solution for C++. 
      // it's bit fiddling craziness. I will study it.

      if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
      if (dividend == divisor) return 1;
      if (divisor == 1) return dividend;
      if (divisor == -1) return ~((int64_t)dividend) + 1;

      int i = 0;
      bool nr = (divisor > 0 && dividend < 0) || (divisor < 0 && dividend>0);
      auto a(abs(dividend)), b(abs(divisor));
      while (a >= b) a -= b, i++;

      return nr ? 0 - i : i;
   }

   // i borrowed this code so that I could see other peoples implementations. I knew my brute force method would 
   // be too slow.
   ///http://bisqwit.iki.fi/story/howto/bitmath/#DivAndModDivisionAndModulo
   /// had to fix a bug in it, and added my own guard, instant knowledge short circuit results.
   /// I'm actually still trying to understand WHY this one works. I'll add code comments explaining it
   /// as I better understand it.
   int divide2(int dividend, int divisor) {
      // some shortcircuit logic where we know the results up front
      if (divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
      if (divisor == 1) return dividend; //
      if (divisor == -1) return ~((int64_t)dividend) + 1; // toggle the signed bit
      if (dividend == divisor) return 1;
      if (dividend == -divisor) return -1;

      bool nr = (divisor > 0 && dividend < 0) || (divisor < 0 && dividend>0);
      divisor = abs(divisor);
      dividend = abs(dividend);
      uint32_t scaled_divisor = divisor;  // The right-hand side of division
      uint32_t remain = dividend;         // The left-hand side of division, i.e. what is being divided
      uint32_t result = 0;
      uint32_t multiple = 1;

      while (scaled_divisor < dividend)
      {
         scaled_divisor <<= 1; // Multiply by two.
         multiple <<= 1;       // Multiply by two.                                                
      }
      do {
         if (remain >= scaled_divisor)
         {
            remain = remain - scaled_divisor;
            result = result + multiple;
         }
         scaled_divisor = scaled_divisor >> 1; // Divide by two.
         multiple = multiple >> 1;
      } while (multiple != 0);
      return nr ? 0 - result : result;
   }

};
