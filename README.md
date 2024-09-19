# Task #PC3: Simulacro Practica Calificada 1  
**course:** Programación III  
**unit:** 6  
**cmake project:** prog3_simulacro_pc1_TEO1_v2024_2
## Instructions
- El tiempo límite para la evaluación es 100 minutos.
- Cada pregunta deberá ser respondida en un archivo cabecera (`.h`):
    - `mini_chess.h`
    - `union_containers.h`
- Adicionalmente, la **pregunta #3** debía de ser entregada como un PDF, MS Word o PNG
- Deberás subir estos archivos directamente a [www.gradescope.com](https://www.gradescope.com) o se puede crear un `.zip` que contenga todos ellos y subirlo.


## Question #1 - {Clases y Template de Clases} (13 points)

El "Ajedrez Simplificado" es una versión reducida del ajedrez tradicional, jugado en un tablero de `6x6` casillas. Cada jugador tiene un conjunto limitado de piezas: 1 Rey, 1 Reina y 4 Peones. El objetivo es capturar el Rey del oponente o posicionar el propio Rey en la fila inicial del oponente.

Diseña e implementa la clase template `board` que representa el tablero dentro del namespace `chess` que permita almacenar de forma genérica diferentes tipos `T` (por ejemplo, punteros a objetos de una clase base `Piece` u otro tipo si el tablero en el futuro quisiera usarse en otro juego), que permita definir el tablero de diferentes tamaños usando un parámetro de template no-tipo `sz` que representa el tamaño del lado, y adicionalmente debe contar con un parámetro no-tipo que defina el valor vacío (`empty_value`) de las celdas en el tablero que no tienen pieza y que sea del tipo `T` (por ejemplo, nullptr para punteros a `Piece`).

La clase debe almacenarse en memoria dinámica. Implementa los constructores adecuados para inicializar y copiar tableros, así como un destructor para liberar la memoria correctamente.

Para facilitar la impresión del tablero, sobrecargar el operador `<<`. Asimismo, implementa las sobrecargas del operador `()` para acceder contenido de celdas individuales, y un método `size_t size()` que retorne el tamaño del tablero (`sz`) descrito en el primer párrafo.

La clase `board` debera incluir el método `add(size_t row, size_t col, T piece)` para agregar una pieza en la fila y columna de la tabla. y el método `remove(size_t row, size_t col)` para remover una pieza de la fila y columna seleccionada.

Proporciona el método `std::pair<bool, T> move(int i1, int j1, int i2, int j2)` donde:
- `i1` y `j1` son las coordenadas de la pieza a mover.
- `i2` y `j2` son las coordenadas de destino.

Adicionalmente, implementa una jerarquía de clases para las piezas:

Clase base abstracta `Piece`: Representa una pieza genérica del juego.

Atributos:
- `char symbol`: Representación gráfica de la pieza (`K` para `King`, `Q` para `Queen` y `P` para `Pawn`). 
- `int player`: Identificador del jugador al que pertenece la pieza.
Métodos:
- `virtual bool is_valid_move(int fromX, int fromY, int toX, int toY) = 0;`
- `get_symbol()` retorna el valor del atributo  `symbol`
- `get_player()` retorna el valor del atributo `player`
- Otros métodos que considere necesarios.
Clases derivadas de Piece:
- `King`, `Queen`, `Pawn`
Cada una implementa el método is_valid_move según las reglas simplificadas del ajedrez.

## **Nota:**
Considerar las siguientes reglas simplificadas de validación de movimiento:

`King`
```cpp
    bool is_valid_move(int fromX, int fromY, int toX, int toY) override {
      return (fromX == toX + 1 || fromX == toX - 1) &&
             (fromY == toY + 1 || fromY == toY - 1);
    }
```

`Queen`
```cpp
    bool is_valid_move(int fromX, int fromY, int toX, int toY) override {
      return ((fromX - toX) == 0 || (fromY - toY) == 0) || ((fromX - toX)/(fromY - toY) == 1);
    }

```

`Pawn`
```cpp
    bool is_valid_move(int fromX, int fromY, int toX, int toY) override {
      return (fromX == toX + 1 || fromX == toX - 1) && (fromY - toY  == 0);
    }
```

**Use Case 1:**

```cpp
  // Incluirlo en una función 
  const int size = 6;
  board<Piece*, size, nullptr> chessBoard; 

  bool result = true;
  for (int i = 0; i < chessBoard.size(); ++i) {
    for (int j = 0; j < chessBoard.size(); ++j) {
      if (chessBoard(i, j) != nullptr) {
        result = false;
      }
    }
  }
  if (result) 
    std::cout << "correcto";
  else
    std::cout << "incorrecto";
  }
```

**Use Case 2:**
```cpp
    using namespace chess;
    const int size = 6;
    board<Piece*, size, nullptr> chessBoard;

    // Colocar una pieza en el tablero
    Piece* king = new King(1);
    chessBoard.add(0, 0, king);

    assert(chessBoard(0, 0)->get_symbol() == 'K');
    assert(chessBoard(0, 0)->get_player() == 1);

    // Verificar que otras celdas sigan vacías
    assert(chessBoard(0, 1) == nullptr);

    // Limpiar
    chessBoard.remove(0, 0);
    assert(chessBoard(0, 0) == nullptr);
```

**Use Case 3:**
```cpp
    const int size = 6;
    board<Piece*, size, nullptr> chessBoard;

    // Colocar un Rey en posición inicial
    chessBoard.add(0, 0, new King(1));

    // Intentar mover el Rey a una posición inválida
    auto result = chessBoard.move(0, 0, 3, 0);
    assert(result.first == false);
    assert(result.second == nullptr);
    assert(chessBoard(0, 0)->get_symbol() == 'K');
    assert(chessBoard(3, 0) == nullptr);

    // Limpiar
    chessBoard.remove(0, 0);
    assert(chessBoard(0, 0) == nullptr);
```

```cpp
    const int size = 6;
    board<Piece*, size, nullptr> chessBoard;

    // Colocar una Reina del jugador 1
    chessBoard.add(0, 1, new Queen(1));
    // Colocar una pieza enemiga en una posición a la que la Reina puede moverse
    chessBoard.add(3, 1, new Pawn(2));

    // Mover la Reina para capturar el Peón
    auto result = chessBoard.move(0, 1, 3, 1);
    assert(result.first == true);
    assert(result.second->get_symbol() == 'Q');
    assert(chessBoard(3, 1)->get_symbol() == 'Q');
    assert(chessBoard(0, 1) == nullptr);

    // Limpiar
    chessBoard.remove(3, 1);
    assert(chessBoard(3, 1) == nullptr);
```

## Question #2 - {Template de funciones} (7 points)

Diseña e implementa una función template `union_containers` que tome un número variable de contenedores y realice las siguientes operaciones:

Combinar todos los elementos de los contenedores proporcionados en un solo contenedor.
Omitir los elementos duplicados de modo que cada elemento sea único y aparezca solo una vez en el contenedor resultante.

La función debe ser capaz de recibir contenedores de distintos tipos (por ejemplo, `std::vector`, `std::list`, etc.) y combinar elementos de cualquier tipo que sea comparable utilizando el operador `==`.

Además, la función debe permitir al usuario especificar el tipo de contenedor resultante mediante un parámetro de template de template `ContainerResult`, este parámetro tendrá por default `std::vector`.

**Use Case 1:**

```cpp
#include <vector>
#include <list>
#include <deque>
```
```cpp
    std::vector<int> vec = {1, 2, 3};
    std::list<int> lst = {3, 4, 5};
    std::vector<int> vec2 = {5, 6, 7};

    auto result = union_containers<std::vector>(vec, lst, vec2);

    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < expected.size(); ++i) assert(result[i] == expected[i]);
```
**Use Case 2:**

```cpp
    std::vector<int> vec;
    std::list<int> lst;
    std::vector<int> vec2;

    auto result = union_containers<std::vector>(vec, lst, vec2);

    assert(result.empty());
```

**Use Case 3:**

```cpp
    std::vector<int> vec = {1, 2, 3};
    std::list<int> lst;  // vacío
    std::vector<int> vec2;  // vacío

    auto result = union_containers(vec, lst, vec2);

    std::vector<int> expected = {1, 2, 3};
    for (int i = 0; i < expected.size(); ++i) assert(result[i] == expected[i]);
```
**Use Case 4:**

```cpp
    std::vector<int> vec = {1, 2, 3};
    std::list<double> lst = {2.0, 3.0, 4.0};
    std::vector<float> vec2 = {4.0f, 5.0f, 6.0f};

    auto result = union_containers<std::vector>(vec, lst, vec2);

    std::vector<double> expected = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    for (int i = 0; i < expected.size(); ++i) assert(result[i] == expected[i]);
```
