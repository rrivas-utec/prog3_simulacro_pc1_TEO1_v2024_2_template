//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "mini_chess.h"
using namespace std;
using namespace chess;

static void test_1_1() {
  // Incluirlo en una función
  const int size = 6;
  board<Piece*, size, nullptr> chessBoard;
  
  // Verificar que todas las celdas estén inicializadas con empty_value
  bool result = true;
  for (int i = 0; i < chessBoard.size(); ++i) {
    for (int j = 0; j < chessBoard.size(); ++j) {
      if (chessBoard(i, j) != nullptr) {
        result = false;
      }
    }
  }
  if (result) std::cout << "correcto";
}

TEST_CASE("Question #1.1") {
    execute_test("test_1_1.in", test_1_1);
}