#include <stdio.h>
#include <math.h>

#define NUM 7368792// NUM以下の素数を求める

int main(void){
  unsigned i, j;
  unsigned sq_num = (int)sqrt((double)NUM);
  unsigned prime[NUM];
  unsigned m=0;
  int num_1,num_2;
  int count=0;
  scanf("%d %d",&num_1,&num_2);

  // 1が立っているものが素数
  // 0が立っているものが合成数（素数ではない）

  for (i = 0; i < NUM; i++){
    prime[i] = 1;  // 全ての数に1を立てる
  }
  prime[0] = 0;    // 1は素数ではない

  for (i = num_1 - 1; i < sq_num; i++) {
	  if (prime[i] == 1) {          // prime[i]が素数なら
		  for (j = (i + 1); (i + 1) * j <= NUM; j++)
			  prime[(i + 1) * j - 1] = 0;  // 素数の倍数は素数ではない
		  if (m < (i * 1)*j - 1) {
			  m = (i + 1)*j - 1;
		  }
		  count++;
		  if (count == num_2) {
				  break;
		  }
	  }
    }

  // 1が立っているものが素数
    printf("%d",m-1 );
    return (0);
}