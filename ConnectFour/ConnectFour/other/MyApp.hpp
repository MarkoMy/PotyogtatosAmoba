#ifndef MYAPP_HPP
#define MYAPP_HPP

#include "application.hpp"
#include "Fields.hpp"
#include "jatekmester.hpp"
#include "statictext.hpp"
#include "button.hpp"

#include <vector>
#include <functional>

using namespace std;

class MyApp : public application{
public:
    MyApp():field(42){
        AllapotjelzoText = new StaticText(this,710,20,180,40,Y);

        resetBTN = new Button(this,710,280,180,40,"Reset",[=](){
            game.gameReseter();
            updateboard();
            updateText();
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
                game.checkWin(i);
                game.CheckText();
                updateText();

            });
        }
    }

    void updateboard(){
            vector<int> board = game.TalbaGet();
            for( int i = 0; i < 42; i++ )
                field[i]->FieldSetter(board[i]);
        }

    void updateText(){
        AllapotjelzoText ->TextSetter(game.GetText());
    }

protected:
    JatekMester game;
    vector<Fields *> field;
    StaticText * AllapotjelzoText;
    Button *resetBTN;
};

#endif // MYAPP_HPP
