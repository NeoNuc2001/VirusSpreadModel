##include "Lib/DxLib.h"
##include "vector"
##include "random"
using namespace std;
class human{
  int Axis[2];
  int InfectedFlag;
  int AlreadyInfectedFlag;
}
int main(int argc, char const *argv[]) {
  int PeopleNum;
  SetGraphMode( 640 , 480 , 16 );
  printf("Set number of people\n", );
  scanf("%d\n",PeopleNum );
  vector<int> Y_Axis;
  vector<int> X_Axis;
  	if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
  	{
  		return -1 ;			// エラーが起きたら直ちに終了
  	}
    std::random_device rnd;     // 非決定的な乱数生成器
    std::mt19937 rand_mt(rnd());            // メルセンヌ・ツイスタの32ビット版、引数は初期シード
    uniform_int_distribution<> rand640(0, 640);
    uniform_int_distribution<> rand480(0, 480);
  ChangeWindowMode(TRUE),  SetDrawScreen( DX_SCREEN_BACK );
  int setupflag=0;
  while(true){
    if(setupflag==0){
      for(int i=0;i<=PeopleNum;i++){
        Y_Axis.push_back(rand480(rand_mt));
        X_Axis.push_back(rand640(rand_mt));
      }

    }else{

    }
  }
}
