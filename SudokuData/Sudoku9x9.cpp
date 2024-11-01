//
// Created by duhamel on 01/11/24.
//

#include "Sudoku9x9.h"
Sudoku9x9::Sudoku9x9() {
        for (int i = 0; i < 81; i++) {
                sudoku[i] = 0;
        }
}
_taille_ Sudoku9x9::NombreCase() {
        return 81;
}

_nombre_ Sudoku9x9::getCase(_numero_ numeroCase) {
        return sudoku[numeroCase];

}

bool Sudoku9x9::IsPossible(_numero_ numeroCase, _nombre_ nombre) {

}

bool Sudoku9x9::IsWin() {
}

void Sudoku9x9::GetColonneLigne(_nombre_ numeroCase, int *colonne, int *ligne) {
        *colonne=numeroCase/9;
        *ligne=numeroCase%9;
}

_nombre_ Sudoku9x9::MaxNombre() {
        return 9;
}



