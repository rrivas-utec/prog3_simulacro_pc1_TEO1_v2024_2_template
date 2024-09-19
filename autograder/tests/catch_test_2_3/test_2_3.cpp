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

static void test_2_3() {
  std::vector<int> vec = {1, 2, 3};
  std::list<int> lst;  // vacío
  std::vector<int> vec2;  // vacío
  
  auto result = union_containers(vec, lst, vec2);

  std::set<int> expected = {1, 2, 3};
  std::set<int> obtained{result.begin(), result.end()};
  std::cout << std::boolalpha;
  std::cout << (expected == obtained) << std::endl;
}

TEST_CASE("Question #2.3") {
    execute_test("test_2_3.in", test_2_3);
}