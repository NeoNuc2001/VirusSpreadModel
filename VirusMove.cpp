#include "DxLib.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <random>
#include <time.h>

/*
random_device rnd;     //
mt19937 rand_mt(rnd());            //
uniform_int_distribution<> rand640(0, 640);
uniform_int_distribution<> rand480(0, 480);
*/
class class_human{
public:
  int Axis[2];
  int InfectedFlag;
  int AlreadyInfectedFlag;
public:
  class_human();
};
using namespace std;
class_human::class_human(){

  Axis[0]=rand()%640;
  Axis[1]=rand()%480;
  cout << "X:" << this->Axis[0] <<"Y:" << this->Axis[1];
  this->InfectedFlag=0;
  this->AlreadyInfectedFlag=0;
}


int main() {
srand((unsigned int)time(NULL));
  int PeopleNum;
  SetGraphMode( 640 , 480 , 16 );
  cout << "Set number of people\n";
  cin >> PeopleNum ;
  ChangeWindowMode(TRUE);
  	if( DxLib_Init() == -1 )		//
  	{
  		return -1 ;			//
  	}
SetDrawScreen( DX_SCREEN_BACK );
    std::vector<class_human>human;
  int humanhandle = LoadGraph("People.png");
  int setupflag=0;
  while( CheckHitKey( KEY_INPUT_ESCAPE ) == 0&&!ScreenFlip()&&!ProcessMessage()&&!ClearDrawScreen()){
    if(setupflag==0){
      for(int i=0;i<=PeopleNum;i++){
       human.push_back(class_human(/*rand()%640,rand()%480)*/));
        //Y_Axis.push_back(rand480(rand_mt));
        //X_Axis.push_back(rand640(rand_mt));
      }
      setupflag=1;

    }else{
      #line 1
      ClearDrawScreen();
      for(int i=0;i<=PeopleNum-20;i++){



        DrawGraph(human[i].Axis[0] ,human[i].Axis[1],humanhandle, FALSE ) ;
      //DrawPixel(human[i].Axis[0] ,human[i].Axis[1],GetColor(0,255,0));


      }
      ScreenFlip();
    }
  }
}
