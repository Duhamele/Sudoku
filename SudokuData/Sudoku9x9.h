//
// Created by duhamel on 01/11/24.
//

#ifndef SUDOKU9X9_H
#define SUDOKU9X9_H
#include "InterfaceSudoku.h"


class Sudoku9x9:public InterfaceSudoku{
        protected:
        int sudoku[81];

        public:
        Sudoku9x9();
        ~Sudoku9x9() override =default;

        _taille_ NombreCase() override;

        _nombre_ getCase(_numero_ numeroCase) override;

        _nombre_ MaxNombre() override;

        bool IsPossible(_numero_ numeroCase, _nombre_ nombre) override;

        bool IsWin() override;
        static void GetColonneLigne(_nombre_ numeroCase,int* colonne,int* ligne);
};



#endif //SUDOKU9X9_H
