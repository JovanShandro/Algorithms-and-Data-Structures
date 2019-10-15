#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>

std::string fill_string(const std::string& str, unsigned long long count, char ch, int type = 1);
bool is_zero(const std::string& str) ;
std::string sum_strings(const std::string& str1, const std::string& str2);
std::string remove_left_zeros(const std::string& value);
std::string sub_strings(const std::string& str1, const std::string& str2);
std::string mult_string_char(const std::string& str1, const char ch); 
std::string mult_brute_force(const std::string& str1, const std::string& str2); 
std::string multiply(const std::string& string1, const std::string& string2); 

#endif