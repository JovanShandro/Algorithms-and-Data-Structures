#include <cstdlib>
#include <list> 
#include <string>
#include <iostream>
#include <algorithm>
#include "functions.h"

using namespace std;
/*
   Add a certain char n times to the left or the right of the string 
   1 is for the right side , -1 for the left
*/
string fill_string(const string& str, unsigned long long count, char ch, int type ) 
{ 
    string s(count, ch);
    return type == -1 ? s + str : str + s;
}

// returns true if the string has only '0's 

bool is_zero(const string& str) 
{
    for (unsigned long long  i = 0, l = str.size(); i < l; i++) 
        if (str[i] != '0') 
            return false;
    return true;
}
 
// returns the sum of two strings representing numbers
string sum_strings(const string& str1, const string& str2) 
{
    if (str2 == "") return str1;
    if (str1 == "") return str2;
    string total = "";
    unsigned long long  str1Size =str1.size();
    unsigned long long  str2Size =str2.size();
    unsigned long long  m = max(str1Size, str2Size);
    unsigned int  carry = 0;
    for (int i = 0; i < static_cast<int>(m); i++) {
        unsigned int  c0 = i < str1Size ? str1[str1Size - 1 - i] - '0' : 0;
        unsigned int  c1 = i < str2Size ? str2[str2Size - 1 - i] - '0' : 0;
        unsigned int  c = c0 + c1 + carry;
        carry = c / 2;
        total += (c % 2) + '0';
    }
    if (carry) total += carry + '0';
    reverse(total.begin(), total.end());
    return total;
}

// gets rid of the zeros on the left 
string remove_left_zeros(const string& value) 
{
    // Delete '0's from the left
    if (value.size() > 1 && value[0] == '0') 
    {
        for (unsigned long long  i = 0, l = value.size(); i < l; i++) 
        {
            if (value[i] == '0')
                continue;
            return value.substr(i, l - i);
        }
    } 
    return value;
}

/// substracts 2 strings assuming the first is greater than the second 
string sub_strings(const string& str1, const string& str2) 
{
    if (str2 == "") return str1;
    string total = "";
    unsigned long long str1Size = str1.size();
    unsigned long long str2Size = str2.size();
    unsigned int  carry = 0;
    for (int i = 0; i < str1Size; i++) 
    {
        int c0 = str1[str1Size - 1 - i] - '0' - carry;
        int c1 = i < str2Size ? str2[str2Size - 1 - i] - '0' : 0;
        carry = 0;
        if (c0 < c1) {
            carry = 1;
            c0 += 2;
        }
        total += (c0 - c1) + '0';
    }
    reverse(total.begin(), total.end());
    return is_zero(total) ? "0" : remove_left_zeros(total);
}

/* 
    returns the result of the product of first parameter by the 
    digit that second parameter represents 
*/
string mult_string_char(const string& str1, const char ch) 
{
    if (ch == '0') return "0";
    if (ch == '1') return str1;

    int carry = 0;
    int d0 = ch - '0';
    string r = "";
    for (int j = str1.size() - 1; j >= 0; j--) 
    {
        int d1 = str1[j] - '0';
        int d = (d0 * d1) + carry;
        carry = d / 2;
        d %= 2;
        r += d + '0';
    }
    if (carry) r += carry + '0';
    reverse(r.begin(), r.end());
    return r;
}

//brute force approach implementation
string mult_brute_force(const string& str1, const string& str2) 
{
    list<string> res;
    unsigned int  padding = 0;
    for (int i = str2.size() - 1; i >= 0; i--) {
        res.push_back(fill_string(mult_string_char(str1, str2[i]), padding, '0', 1));
        padding++;
    }
    string total = "";
    for (string line : res)
        total = sum_strings(total, line);
    return total;
}

//recursive implementation
string multiply(const string& string1, const string& string2) 
{ 
    if (is_zero(string1) || is_zero(string2)) {
        return "0";
    }
    string str1 = remove_left_zeros(string1);
    string str2 = remove_left_zeros(string2);
    unsigned long long l1 = str1.size();
    unsigned long long  l2 = str2.size();

    if (l1 == 1 || l2 == 1)
        return mult_string_char(l1 == 1 ? str2 : str1, l1 == 1 ? str1[0] : str2[0]);

    // make th division
    unsigned long long  n = max(l1, l2);
    n += (n & 1);

    str1 = fill_string(str1, n - l1, '0', -1);
    str2 = fill_string(str2, n - l2, '0', -1);
    unsigned long long  n2 = n / 2;

    string a = str1.substr(0, n2);
    string b = str1.substr(n2, n2);
    string c = str2.substr(0, n2);
    string d = str2.substr(n2, n2);

    // first 2 recursive calls
    string ac = multiply(a, c);
    string bd = multiply(b, d);
        
    string _ab = sum_strings(a, b);
    string _cd = sum_strings(c, d);

    // third call
    string abcd = multiply(_ab, _cd);

    abcd = sub_strings(abcd, ac);
    abcd = sub_strings(abcd, bd);

    ac = fill_string(ac, n, '0', 1);
    abcd = fill_string(abcd, n2, '0', 1);
    string res = sum_strings(ac, abcd);
    res = sum_strings(res, bd);
    return remove_left_zeros(res);
}
