#include <gtest/gtest.h>
#include <string>
#include <ostream>
#include <fstream>

void print(const std::string& text, std::ostream& out) {
    // Записываем текст в указанный поток
    out << text;
}

TEST(Print, InFileStream)
{
  std::string filepath = "file.txt";
  std::string text = "hello";
  std::ofstream out{filepath};

  print(text, out);
  out.close();

  std::string result;
  std::ifstream in{filepath};
  in >> result;

  EXPECT_EQ(result, text);
}
