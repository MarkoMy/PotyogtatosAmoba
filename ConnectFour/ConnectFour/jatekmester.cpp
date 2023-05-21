#include "jatekmester.hpp"

#include <vector>

std::vector<int> JatekMester::TalbaGet() {
    return tabla;
}

int JatekMester::GetText() {
    return AllText;
}

void JatekMester::Move(int x) {
    if (_gameRun && tabla[x] == EMPTY) {
        int oszlop = x % 7;
        for (int i = oszlop; i < oszlop + 5 * 7; i += 7) {
            if (tabla[i] == EMPTY && tabla[oszlop + 5 * 7] == EMPTY) {
                tabla[oszlop + 5 * 7] = _player;
                _player = !_player;
                lastPlace = oszlop + 5 * 7;
                break;
            } else if (tabla[i] == EMPTY && tabla[i + 7] != EMPTY) {
                tabla[i] = _player;
                _player = !_player;
                lastPlace = i;
                break;
            }
        }
    }
}

void JatekMester::CheckText() {
    if (!_player) {
        AllText = Y;
    } else {
        AllText = R;
    }

    if (!_gameRun && _player) {
        AllText = YW;
    } else if (!_gameRun && !_player) {
        AllText = RW;
    }

    if (CheckTie()) {
        AllText = D;
        _gameRun = false;
    }
}

void JatekMester::checkWin() {
    int index = lastPlace;
    int sor = index / 7;
    int oszlop = index % 7;

    // Sor
    int szamlalo = 0;
    for (int i = sor * 7; i < sor * 7 + 7; i++) {
        if (tabla[i] != EMPTY) {
            if (tabla[i] == tabla[i + 1]) {
                szamlalo++;
            } else {
                szamlalo = 0;
            }
            if (szamlalo == 3) {
                _gameRun = false;
                break;
            }
        }
    }

    // Oszlop
    szamlalo = 0;
    for (int i = oszlop; i < oszlop + 5 * 7; i += 7) {
        if (tabla[i] != EMPTY) {
            if (tabla[i] == tabla[i + 7]) {
                szamlalo++;
            } else {
                szamlalo = 0;
            }
            if (szamlalo == 3) {
                _gameRun = false;
                break;
            }
        }
    }

    // Átló le-jobb
    szamlalo = 0;
    int r = sor;
    int c = oszlop;

    while (r > 0 && c > 0) {
        r--;
        c--;
    }
    while (r <= 5 && c <= 6) {
        int currentIndex = r * 7 + c;
        if (tabla[currentIndex] == tabla[index] && tabla[index] != EMPTY) {
            szamlalo++;
            if (szamlalo >= 4) {
                _gameRun = false;
                break;
            }
        } else {
            szamlalo = 0;
        }
        r++;
        c++;
    }

    // Átló le-bal
    szamlalo = 0;
    r = sor;
    c = oszlop;

    while (r > 0 && c < 6) {
        r--;
        c++;
    }
    while (r <= 5 && c >= 0) {
        int currentIndex = r * 7 + c;
        if (tabla[currentIndex] == tabla[index] && tabla[index] != EMPTY) {
            szamlalo++;
            if (szamlalo >= 4) {
                _gameRun = false;
                break;
            }
        } else {
            szamlalo = 0;
        }
        r++;
        c--;
    }
}

bool JatekMester::CheckTie() {
    for (int i = 0; i < 42; ++i) {
        if (tabla[i] == EMPTY) {
            return false;
        }
    }
    return true;
}

void JatekMester::gameReseter() {
    tabla.assign(42, EMPTY);
    _player = false;
    _gameRun = true;
    CheckText();
}
