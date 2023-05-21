#include "jatekmester.hpp"

#include <vector>

std::vector<int> JatekMester::TalbaGet(){
    return tabla;
}


void JatekMester::Move(int x){
    if(tabla[x] < 36 && tabla[x+7] != EMPTY && tabla[x] == EMPTY && _gameRun && !CheckTie()){
        tabla[x] = _player;
        _player = !_player;
    }
}

void JatekMester::CheckText(){
    if(!_player){
        AllText = Y;
    } else if(_player){
        AllText = R;
    } else if(!_gameRun && !_player && !CheckTie()){
        AllText = YW;
    } else if(!_gameRun && _player && !CheckTie()){
        AllText = RW;
    }

    if(CheckTie()){
        AllText = D; _gameRun = !_gameRun;
    }
}

int JatekMester::GetText(){
    return AllText;
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

void JatekMester::gameReseter(){
    for (int i = 0; i < 42; ++i) {
        tabla[i] = EMPTY;
    }
    _player = 0;
    _gameRun = 1;
    CheckText();
}


/*
 * KÉNE:
 * winchecks
 *
 * ha az összes mező tele, akkor TIE
 *
 * checkelni azt, hogy 4 ugyanolyan van
 *
 * PIPA:
 * csak azokat a kattintásokat engedni, ami EMPTY, és alatta nem EMPTY
 * Csak akkor rak le, ha _gameRun true, ez kell majd a játék végéhez
 *
 * Reset gomb
 * Kiírni, hogy melyik ember jön
 */
