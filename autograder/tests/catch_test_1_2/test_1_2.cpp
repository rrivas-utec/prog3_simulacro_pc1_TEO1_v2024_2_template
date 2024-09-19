//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "mini_chess.h"
using namespace std;
using namespace chess;

static void test_1_2() {
  const int size = 6;
  board<Piece*, size, nullptr> chessBoard;
  
  // Colocar una pieza en el tablero
  Piece* king = new King(1);
  chessBoard.add(0, 0, king);

  std::cout << chessBoard(0, 0)->get_symbol() << std::endl;
  std::cout << chessBoard(0, 0)->get_player() << std::endl;

  // Verificar que otras celdas sigan vacías
  std::cout << boolalpha << (chessBoard(0, 1) == nullptr) << std::endl;

  // Limpiar
  chessBoard.remove(0, 0);
  std::cout << boolalpha << (chessBoard(0, 0) == nullptr) << std::endl;
}

TEST_CASE("Question #1.2") {
    execute_test("test_1_2.in", test_1_2);
}