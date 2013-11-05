#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> ret;
        string tmp_str;
        int num_dot = 0;
        int i = 0;
        restore_ip(s, i, num_dot, tmp_str, ret);
        return ret;
    }
    bool restore_ip(string& s, int i, int num_dot, string& tmp_str, vector<string>& ret) {
        if (s.empty() || i < 0 || num_dot < 0 || num_dot > 3 || s.size() == i) return false;
        cout << tmp_str << '\t' << i << '\t' << num_dot << endl;
        if (num_dot == 3) {
            int tmp_num = 0;
            for (int j = i; j < s.size(); j++) {
                tmp_num *= 10;
                tmp_num += s[j] - '0';
            }
            if (tmp_num > 255 || tmp_num < 0) return false;
            ret.push_back(tmp_str + s.substr(i));
            return true;
        }

        tmp_str.push_back(s[i]);
        tmp_str.push_back('.');
        restore_ip(s, i+1, num_dot + 1, tmp_str, ret);
        tmp_str.erase(tmp_str.size()-2);
        if (i < s.size()-1) {
          tmp_str.push_back(s[i]);
          tmp_str.push_back(s[i+1]);
          tmp_str.push_back('.');
          restore_ip(s, i+2, num_dot + 1, tmp_str, ret);
          tmp_str.erase(tmp_str.size()-3);
          if (i < s.size()-2) {
            int tmp_num = (s[i] - '0')*100 + (s[i+1] - '0')*10 + s[i+2] - '0';
            tmp_str.push_back(s[i]);
            tmp_str.push_back(s[i+1]);
            tmp_str.push_back(s[i+2]);
            tmp_str.push_back('.');
            if (tmp_num <= 255 && tmp_num >=0)  restore_ip(s, i+3, num_dot + 1, tmp_str, ret);
            tmp_str.erase(tmp_str.size()-4);
          }
        }
        return false;
    }
};

int main(void)
{
  string s("0000");
  Solution test;
  test.restoreIpAddresses(s);
  return 0;
}

