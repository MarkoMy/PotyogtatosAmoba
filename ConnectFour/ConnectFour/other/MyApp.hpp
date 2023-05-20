#ifndef MYAPP_HPP
#define MYAPP_HPP

#include "application.hpp"
#include "Fields.hpp"
#include "jatekmester.hpp"
#include "statictext.hpp"

#include <vector>
#include <functional>

using namespace std;

class MyApp : public application{
public:
    MyApp():field(42){
        AllapotjelzoText = new StaticText(this,710,20,180,20,YELLOW,[=](){
            game.CheckText();
        });

        //táblafeltöltés
        int z = 0;
        for(int i = 0; i < 42; i++){
            if(i % 7 == 0 && i != 0){
                z++;
            }
            field[i] = new Fields(this,(i%7)*100,(z%7)*100,100,100,EMPTY,0,[=](){
                game.Move(i);
                updateboard();
            });
        }
    }

    void updateboard(){
            vector<int> board = game.TalbaGet();
            for( int i = 0; i < 42; i++ )
                field[i]->FieldSetter(board[i]);
        }

    void updatetext(){
        int ntext = game.CheckText();
    }

protected:
    JatekMester game;
    vector<Fields *> field;
    StaticText * AllapotjelzoText;
};

#endif // MYAPP_HPP
