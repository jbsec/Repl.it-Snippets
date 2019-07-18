// #include <boost/variant.hpp>
#include <vector>
#include <string>
#include <iostream>
// using namespace std;

int main() {
  typedef boost::variant<int, const char*, std::string> my_var_t; std::vector<my_var_t> some_values;
  some_values.push_back(10);
  some_values.push_back("Hello there!");
  some_values.push_back(std::string("Wow!"));
  std::string& s = boost::get<std::string>(some_values.back());
  s += " That is great!z\n";
  std::cout << s;
  return 0;
}