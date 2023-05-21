#include "jatekmester.hpp"

#include <vector>

std::vector<int> JatekMester::TalbaGet(){
    return tabla;
}


void JatekMester::Move(int x){

    if(_gameRun && tabla[x] == EMPTY){
                int oszlop = x % 7;
                for(int i=oszlop; i < oszlop+5*7; i+=7){
                    if(tabla[i] == EMPTY && tabla[oszlop+5*7] == EMPTY){
                        tabla[oszlop+5*7] = _player;
                        _player = !_player;
                        lastPlace = oszlop+5*7;
                        break;
                    }else if(tabla[i] == EMPTY && tabla[i+7] != EMPTY){
                        tabla[i] = _player;
                        _player = !_player;
                        lastPlace = i;
                    }
                }

    }

}

void JatekMester::CheckText(){
    if(!_player){
        AllText = Y;
    } else if(_player){
        AllText = R;
    }

    if(!_gameRun && _player){
        AllText = YW;
    } else if(!_gameRun && !_player){
        AllText = RW;
    }

    if(CheckTie()){
        AllText = D; _gameRun = !_gameRun;
    }
}

int JatekMester::GetText(){
    return AllText;
}

void JatekMester::checkWin() {
    int index = lastPlace;
    int sor = index / 7;
    int oszlop = index % 7;

    //sor
    int szamlalo = 0;
    for(int i=sor*7; i < sor*7+7; i++){
        if(tabla[i] != EMPTY){
        if(tabla[i] == tabla[i+1] ){
            szamlalo++;
        }
        if(tabla[i] != tabla[i+1])
            szamlalo = 0;
        if(szamlalo == 3)
        _gameRun = 0;
        }
    }

    //oszlop
    szamlalo = 0;
    for(int i=oszlop; i < oszlop+5*7; i+=7){
        if(tabla[i] != EMPTY){
        if(tabla[i] == tabla[i+7] ){
            szamlalo++;
        }
        if(tabla[i] != tabla[i+7])
            szamlalo = 0;
        if(szamlalo == 3)
        _gameRun = 0;
        }
    }

    //átló le-jobb
    szamlalo = 0;
    int r = sor;
    int c = oszlop;

    while (r > 0 && c > 0) {
        r--;
        c--;
    }
    while (r <= 5 && c <= 6) {
            int currentIndex = r * 7 + c;
            if (tabla[currentIndex] == tabla[index]&& tabla[index] != EMPTY) {
                szamlalo++;
                if (szamlalo >= 4)
                   _gameRun = 0;
            } else {
                szamlalo = 0;
            }
            r++;
            c++;
        }

    //átló le-bal

    szamlalo = 0;
    r = sor;
    c = oszlop;

    while (r > 0 && c < 0) {
        r--;
        c++;
    }
    while (r <= 5 && c >= 0) {
            int currentIndex = r * 7 + c;
            if (tabla[currentIndex] == tabla[index] && tabla[index] != EMPTY) {
                szamlalo++;
                if (szamlalo >= 4)
                   _gameRun = 0;
            } else {
                szamlalo = 0;
            }
            r++;
            c--;
        }
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
