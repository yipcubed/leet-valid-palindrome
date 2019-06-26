#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <climits>
#include <ctype.h>

using namespace std;

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    // Time: O(n) n is size of size
    // Space: O(1)
    bool isPalindrome(string s) {
        int start = 0;
        int fin = s.size() - 1;
        // cout << "Begin start: " << start << ", fin: " << fin << endl;
        while (start < fin) {
          while (start < s.size() && ! isalnum(s[start])) ++start ;
          while (fin >= 0 && ! isalnum(s[fin])) --fin;
          if (start >= fin) return true;
          // matches with case
          char c = s[start];
          char d = s[fin];
          // cout << "start: " << start << ", fin: " << fin << endl;
          // cout << "c: " << c << ", d:" << d << endl;
          if (! ( (isdigit(c) && (c == d)) ||
                  (isalpha(c) && toupper(c) == toupper(d))))
                  return false;
          start++;
          fin--;
        }
        return true;
    }
};

void test1() {
  Solution S;
  string s = "A man, a plan, a canal: Panama";
  cout << boolalpha;
  cout << "true? " << S.isPalindrome(s) << endl;
  s = "race a car";
  cout << "false? " << S.isPalindrome(s) << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}



