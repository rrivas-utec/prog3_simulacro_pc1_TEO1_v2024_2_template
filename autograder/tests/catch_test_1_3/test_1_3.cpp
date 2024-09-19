//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "mini_chess.h"
using namespace std;
using namespace chess;

static void test_1_3() {
  const int size = 6;
  board<Piece*, size> chessBoard;
  
  // Colocar un Rey en posición inicial
  chessBoard.add(0, 0, new King(1));

  // Intentar mover el Rey a una posición inválida
  auto result = chessBoard.move(0, 0, 3, 0);
  std::cout << std::boolalpha;
  std::cout << (result.first) << std::endl;
  std::cout << (result.second == nullptr) << std::endl;
  std::cout << (chessBoard(0, 0)->get_symbol() == 'K') << std::endl;
  std::cout << (chessBoard(3, 0) == nullptr) << std::endl;

  // Limpiar
  chessBoard.remove(0, 0);
  std::cout << (chessBoard(0, 0) == nullptr) << std::endl;
}

TEST_CASE("Question #1.3") {
    execute_test("test_1_3.in", test_1_3);
}