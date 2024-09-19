//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "mini_chess.h"
using namespace std;
using namespace chess;

static void test_1_4() {
  const int size = 6;
  board<Piece*, size> chessBoard;
  
  // Colocar una Reina del jugador 1
  chessBoard.add(0, 1, new Queen(1));
  // Colocar una pieza enemiga en una posición a la que la Reina puede moverse
  chessBoard.add(3, 1, new Pawn(2));

  // Mover la Reina para capturar el Peón
  auto result = chessBoard.move(0, 1, 3, 1);
  std::cout << std::boolalpha;
  std::cout << (result.first) << std::endl;
  std::cout << (result.second->get_symbol() == 'Q') << std::endl;
  std::cout << (chessBoard(3, 1)->get_symbol() == 'Q') << std::endl;
  std::cout << (chessBoard(0, 1) == nullptr) << std::endl;

    // Limpiar
    chessBoard.remove(3, 1);
    assert(chessBoard(3, 1) == nullptr);
}

TEST_CASE("Question #1.4") {
    execute_test("test_1_4.in", test_1_4);
}