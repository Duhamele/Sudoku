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
        if(this->sudoku[numeroCase] != 0) {
                return false;
        }
        for(_numero_ n:this->getBoxCase(numeroCase)) {
                if(this->sudoku[n] == nombre) {
                        return false;
                }
        }
        for(_numero_ n:this->getLigneCase(numeroCase)) {
                if(this->sudoku[n] == nombre) {
                        return false;
                }
        }
        for(_numero_ n:this->getColonneCase(numeroCase)) {
                if(this->sudoku[n] == nombre) {
                        return false;
                }
        }
        return true;

}

std::vector<_numero_> Sudoku9x9::getLigneCase(_numero_ numeroCase) {
        std::vector<_numero_> Ligne(9,0);
        int ligne;
        int colonne;
        GetColonneLigne(numeroCase, &colonne, &ligne);
        for (int i = 0; i < 9; i++) {
                Ligne[i]=ligne+colonne*9;
        }
        return Ligne;
}

std::vector<_numero_> Sudoku9x9::getBoxCase(_numero_ numeroCase) {
        int box =GetBoxCase(numeroCase);
        switch (box) {
                case 0:
                        return std::vector<_numero_>{0,1,2,9,10,11,18,19,20};
                case 1:
                        return std::vector<_numero_>{3,4,5,12,13,14,21,22,23};
                case 2:
                        return std::vector<_numero_> {6,7,8,15,16,17,24,25,26};
                case 3:
                        return std::vector<_numero_> {27,28,29,36,37,38,45,46,47};
                case 4:
                        return std::vector<_numero_> {30,31,32,39,40,41,48,49,50};
                case 5:
                        return std::vector<_numero_> {33,34,35,42,43,44,51,52,53};
                case 6:
                        return std::vector<_numero_> {54,55,56,63,64,65,72,73,74};
                case 7:
                        return std::vector<_numero_> {57,58,59,66,67,68,75,76,77};
                case 8:
                        return std::vector<_numero_>{60,61,62,69,70,71,78,79,80};
                default:
                        return std::vector<_numero_>{-1};
        }
}

bool Sudoku9x9::IsWin() {
        for (int i = 0; i < 81; i++) {
                if(sudoku[i] == 0) {
                        return false;
                }
                for(_numero_ n:this->getBoxCase(i)) {
                        if(this->sudoku[n] == this->sudoku[i]&&i!=n) {
                                return false;
                        }
                }
                for(_numero_ n:this->getLigneCase(i)) {
                        if(this->sudoku[n] == this->sudoku[i]&&i!=n) {
                                return false;
                        }
                }
                for(_numero_ n:this->getColonneCase(i)) {
                        if(this->sudoku[n] == this->sudoku[i]&&i!=n) {
                                return false;
                        }
                }

        }
        return true;
}

void Sudoku9x9::GetColonneLigne(_nombre_ numeroCase, int *colonne, int *ligne) {
        *colonne=numeroCase/9;
        *ligne=numeroCase%9;
}

_nombre_ Sudoku9x9::MaxNombre() {
        return 9;
}
std::vector<_numero_> Sudoku9x9::getColonneCase(_numero_ numeroCase) {
        std::vector<_numero_> Colonne(9,0);
        int ligne;
        int colonne;
        GetColonneLigne(numeroCase, &colonne, &ligne);
        for (int i = 0; i < 9; i++) {
                Colonne[i]=colonne*9+i;
        }
        return Colonne;
}
int Sudoku9x9::GetBoxCase(_numero_ numeroCase) {
        int ligne;
        int colonne;
        GetColonneLigne(numeroCase, &colonne, &ligne);
        colonne/=3;
        ligne/=3;
        return ligne+colonne*3;
}

void Sudoku9x9::setCase(_numero_ numeroCase, _nombre_ nombre) {
        if(sudoku[numeroCase]==0) {
                if(this->IsPossible(numeroCase,nombre)) {
                        sudoku[numeroCase]=nombre;
                }
        }
}




