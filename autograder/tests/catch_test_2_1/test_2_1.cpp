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

static void test_2_1() {
  std::vector<int> vec = {1, 2, 3};
  std::list<int> lst = {3, 4, 5};
  std::vector<int> vec2 = {5, 6, 7};
  
  auto result = union_containers<std::vector>(vec, lst, vec2);

  std::set<int> expected = {1, 2, 3, 4, 5, 6, 7};
  std::set<int> obtained{result.begin(), result.end()};
  std::cout << (expected == obtained) << std::endl;
}

TEST_CASE("Question #2.1") {
    execute_test("test_2_1.in", test_2_1);
}