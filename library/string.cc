#include <iostream>

/* Rule of 3/5/0
 https://en.cppreference.com/w/cpp/language/rule_of_three
 https://www.codementor.io/@sandesh87/the-rule-of-five-in-c-1pdgpzb04f
*/

/* Idioms in C++
 https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms
*/
class String {
public:
  const size_t &length() const noexcept;

  explicit String(const char *) noexcept; // default constructor
  String(const String &) noexcept;        // copy constructor
  String(String &&) noexcept;             // move constructor
  ~String() noexcept;                     // destructor

  String &operator=(String) noexcept; // copy assignment operator

  // making friend as, we are defining this function for cin, cout which do not
  // have access to private members
  friend std::istream &operator>>(std::istream &, const String &);
  friend std::ostream &operator<<(std::ostream &, const String &);
  friend void swap(String &, String &) noexcept;

private:
  size_t m_size = 0;
  char *m_str = nullptr;
};

const size_t &String::length() const noexcept { return m_size; }

String::String(const char *str = "") noexcept {
  size_t len = 0;
  while (str[len] != '\0') {
    ++len;
  }

  m_size = len;
  m_str = new char[len];

  while (len--) {
    m_str[len] = str[len];
  }
}

String::String(const String &str) noexcept {
  m_size = str.m_size;
  m_str = new char[m_size];

  size_t len = m_size;
  while (len--) {
    m_str[len] = str.m_str[len];
  }
}

String::~String() noexcept {
  m_size = 0;
  delete[] m_str;
  m_str = nullptr;
}

// String &String::operator=(const String &str) noexcept {
//   if (this == &str) {
//     return *this;
//   }
//
//   delete[] m_str;
//
//   m_size = str.m_size;
//   m_str = new char[m_size]; // suppose memory allocation here fails, we lose
//   m_str data
//
//   size_t len = m_size;
//   while (len--) {
//     m_str[len] = str.m_str[len];
//   }
//
//   return *this;
// }

// copy assignment using copy and swap idiom
String &String::operator=(String str) noexcept {
  swap(*this, str);
  return *this;
}

// taking a rvalue reference
String::String(String &&str) noexcept {
  swap(*this, str);

  // if we don't do this, str becomes nullptr and throws error when printed
  str = String("");
}

std::istream &operator>>(std::istream &iss, String &str) {
  // taking the input in a temporary buffer
  char temp[100];
  iss >> temp;

  str = String(temp);
  return iss;
}

std::ostream &operator<<(std::ostream &oss, const String &str) {
  oss << str.m_str;
  return oss;
}

void swap(String &str1, String &str2) noexcept {
  std::swap(str1.m_str, str2.m_str);
  std::swap(str1.m_size, str2.m_size);
}

int main() {
  String s1 = String("Hello"); // String s1 = "Hello" will also call the
                               // constructor but implicitly change to String

  std::cin >> s1;
  std::cout << s1 << '\n';

  String s2 = s1; // copy constructor
  std::cout << s2 << '\n';

  String s3 = String("Wow");
  s3 = s1; // copy assignment operator
  std::cout << s3 << '\n';

  swap(s1, s3);
  std::cout << s3 << '\n';

  String s4 = std::move(s1); // move constructor
  std::cout << s1 << '\n';
  std::cout << s4 << '\n';

  String s5;
  s5 = std::move(s2); // move assignment operator

  std::cout << s2 << '\n';
  std::cout << s5 << '\n';

  auto len = s5.length();
  std::cout << len << '\n';
}
