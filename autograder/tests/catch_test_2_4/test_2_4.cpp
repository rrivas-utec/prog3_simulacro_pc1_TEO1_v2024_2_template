//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "union_containers.h"
#include <vector>
#include <list>
#include <deque>
#include <set>

using namespace std;

static void test_2_4() {
  std::vector<int> vec = {1, 2, 3};
  std::list<double> lst = {2.0, 3.0, 4.0};
  std::vector<float> vec2 = {4.0f, 5.0f, 6.0f};
  
  auto result = union_containers<std::vector>(vec, lst, vec2);

  std::set<double> expected = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  std::set<double> obtained{result.begin(), result.end()};
  std::cout << std::boolalpha;
  std::cout << (expected == obtained) << std::endl;
}

TEST_CASE("Question #2.4") {
    execute_test("test_2_4.in", test_2_4);
}