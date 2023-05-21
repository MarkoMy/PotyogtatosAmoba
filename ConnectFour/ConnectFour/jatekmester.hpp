#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

#include <vector>
#include "other/Fields.hpp"
#include "other/statictext.hpp"

class JatekMester
{
protected:
    bool _player = 0;
    int _phaseText = 0;
    std::vector<int> tabla;
    int AllText;
    bool _gameRun = 1;

public:
    JatekMester():tabla(42,EMPTY){};
    virtual std::vector<int> TalbaGet();
    virtual void Move(int x);
    virtual bool CheckWin(int x);
    virtual void CheckText();
    virtual bool CheckTie();

    virtual int GetText();

    virtual void gameReseter();

};

#endif // JATEKMESTER_HPP
