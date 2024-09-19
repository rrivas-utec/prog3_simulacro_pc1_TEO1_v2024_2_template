//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "union_containers.h"
#include <vector>
#include <list>
#include <deque>
using namespace std;

static void test_2_2() {
  std::vector<int> vec;
  std::list<int> lst;
  std::vector<int> vec2;
  
  auto result = union_containers<std::vector>(vec, lst, vec2);
  std::cout << (result.empty()) << std::endl;
}

TEST_CASE("Question #2.2") {
    execute_test("test_2_2.in", test_2_2);
}