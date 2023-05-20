#include "jatekmester.hpp"

#include <vector>

std::vector<int> JatekMester::TalbaGet(){
    return tabla;
}


void JatekMester::Move(int x){
    if(tabla[x] < 36 && tabla[x+7] != EMPTY && tabla[x] == EMPTY){
        tabla[x] = _player;
        _player = !_player;
    }
}

bool JatekMester::CheckWin(int x){

}

bool JatekMester::CheckTie() {
    for (int i = 0; i < 42; ++i) {
        if (tabla[i] == EMPTY)
            return false;
    }
    return true;
}

void JatekMester::CheckText(){
    if(_player && CheckTie()){
        _phaseText = 0;
    } else if(!_player && CheckTie()){
        _phaseText = 1;
    }
}

/*
 * KÉNE:
 * winchecks
 *
 * ha az összes mező tele, akkor TIE
 *
 * checkelni azt, hogy 4 ugyanolyan van
 *
 * Kiírni, hogy melyik ember jön
 *
 * PIPA:
 * csak azokat a kattintásokat engedni, ami EMPTY, és alatta nem EMPTY
 */
