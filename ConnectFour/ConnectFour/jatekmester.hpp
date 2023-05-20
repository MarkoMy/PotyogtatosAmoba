#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

#include <vector>
#include "other/Fields.hpp"

class JatekMester
{
protected:
    bool _player = 1;
    int _phaseText = 0;
    std::vector<int> tabla;

public:
    JatekMester():tabla(42,EMPTY){};
    virtual std::vector<int> TalbaGet();
    virtual void Move(int x);
    virtual bool CheckWin(int x);
    virtual void CheckText();
    virtual bool CheckTie();

};

#endif // JATEKMESTER_HPP
