/*
Copyright ou © ou Copr. Elie Duhamel , (01/11/24)

elie.duhamel@grenoble-inp.org

Ce logiciel est régi par la licence CeCILL soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe à
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL, et que vous en avez accepté les
termes.
*/

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

        std::vector<_numero_> getLigneCase(_numero_ numeroCase) override;

        std::vector<_numero_> getColonneCase(_numero_ numeroCase) override;

        std::vector<_numero_> getBoxCase(_numero_ numeroCase) override;

        bool IsWin() override;
        static void GetColonneLigne(_nombre_ numeroCase,int* colonne,int* ligne);
        int GetBoxCase(_numero_ numeroCase);
};



#endif //SUDOKU9X9_H
