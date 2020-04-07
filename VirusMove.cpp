 #include "DxLib.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <time.h>
#include <math.h>

/*
random_device rnd;     //
mt19937 rand_mt(rnd());            //
uniform_int_distribution<> rand640(0, 640);
uniform_int_distribution<> rand480(0, 480);
*/
class _Axis{
public:
    int Axis[2];
   _Axis& operator=(const int EnteredAxis[2]){
     Axis[0]=EnteredAxis[0];
     Axis[1]=EnteredAxis[1];
     return *this;
   };
};
std::map<int,_Axis> InfectedAxis;
float Distance(int first_Axis[2],int second_Axis[2]);

float Distance(int first_Axis[2],int second_Axis[2]){
  return sqrt((float)(pow(first_Axis[0]-second_Axis[0],2)+pow(first_Axis[1]-second_Axis[1],2)));
}
class class_human{
public:
  int element;
  int Axis[2];
  int speed[2];
  int Acell[2];
  int InfectedFlag;
  int AlreadyInfectedFlag;
public:
  void setspeed(){if(speed[0]+Acell[0]>=-5&&speed[0]+Acell[0]<=5)speed[0]+=Acell[0];if(speed[1]+Acell[1]>=-5&&speed[1]+Acell[1]<=5)speed[1]+=Acell[1];};
  void setAcell(){if(Axis[0]<=0)Acell[0]=rand()%3;else if(Axis[0]>=630)Acell[0]=rand()%3-2;else Acell[0]=rand()%3-1;if(Axis[1]<=0)Acell[1]=rand()%3; else if(Axis[1]>=470)Acell[1]=rand()%3-2;else Acell[1]=rand()%3-1;};
  void setAxis(){Axis[0]+=speed[0];Axis[1]+=speed[1];};
  void givevirus(){if(AlreadyInfectedFlag!=1)InfectedFlag=-255;AlreadyInfectedFlag=1;}
  void virusupdate();
  void setAll(){setAcell();setspeed();setAxis();}
  class_human(int PullElemet);
};
using namespace std;
class_human::class_human(int PullElemet){
  element=PullElemet;
  speed[0]=rand()%6-3;
  speed[1]=rand()%6-3;
  Axis[0]=rand()%640;
  Axis[1]=rand()%480;
  //cout << "X:" << this->Axis[0] <<"Y:" << this->Axis[1];
  this->InfectedFlag=-256;
  this->AlreadyInfectedFlag=0;
}


int main() {
srand((unsigned int)time(NULL));
  int PeopleNum,PeopleElement;
  SetGraphMode( 640 , 480 , 16 );
  cout << "Set number of people\n";
  cin >> PeopleNum ;
  cout << "Set Human to watch\n";
  cin >>  PeopleElement;
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
      for(int i=0;i<PeopleNum;i++){
       human.push_back(class_human(i-1/*rand()%640,rand()%480)*/));
        //Y_Axis.push_back(rand480(rand_mt));
        //X_Axis.push_back(rand640(rand_mt));
      }
      human[PeopleElement].givevirus();
      setupflag=1;

    }else{
      cout <<"SpeedX:" <<human[PeopleElement].speed[0] <<" SpeedY:" <<human[PeopleElement].speed[1] <<"\n AxisX" <<human[PeopleElement].Axis[0]<<" AxisY:" <<human[PeopleElement].Axis[1] <<"\n";

      ClearDrawScreen();
      for(int i=0;i<=PeopleNum-20;i++){


        human[i].setAll();
        human[i].virusupdate();



        //DrawGraph(human[i].Axis[0] ,human[i].Axis[1],humanhandle, FALSE ) ;
if(human[i].InfectedFlag<=-256||human[i].InfectedFlag>=256){
      DrawPixel(human[i].Axis[0] ,human[i].Axis[1],GetColor(0,255,0));
      if(i==PeopleElement)
      DrawBox(0,0,20,20,GetColor(0,255,0),true) ;
}else{

        DrawPixel(human[i].Axis[0] ,human[i].Axis[1],GetColor(-1*abs(human[i].InfectedFlag)+255,abs(human[i].InfectedFlag),0));
        if(i==PeopleElement)
        DrawBox(0,0,20,20,GetColor(-1*abs(human[i].InfectedFlag)+255,abs(human[i].InfectedFlag),0),true) ;
      }

      }
      ScreenFlip();
    }
  }
}

void class_human::virusupdate(){
  if(InfectedFlag>=-255&&InfectedFlag<=255){
    InfectedFlag++;
    //InfectedAxis[element][0]=Axis[0];
    //InfectedAxis[element][1]=Axis[1];
    InfectedAxis[element]=Axis;

  }
  else{

    for(map<int,_Axis>::iterator itr = InfectedAxis.begin();itr!=InfectedAxis.end();++itr){
    int LocalInfectedAxis[2]={itr->second.Axis[0],itr->second.Axis[1]};
      if(Distance(Axis,LocalInfectedAxis)<3)givevirus();
    }
  }
}
