#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return a < b ? a : b; } // get the minimum
int max(int a, int b) { return a > b ? a : b; } // get the maximum

int *calculateWhole(int width, int height) {
  int *ratio = (int *)malloc(sizeof(int) * 2); // make an array of two integers by allocating memory for each element
  int minval = min(width, height);
  for (int i = minval; i >= 1; i--) {
    if (((float)width / i - width / i) == 0 &&
        ((float)height / i - height / i) == 0) {
      if (ratio[1] == 0 && ratio[0] == 0) {
        ratio[0] = width / i;
        ratio[1] = height / i;
      } else {
	if(!((float)width/i <= 0 || (float)height/i <= 0)) {
        ratio[0] = min(ratio[0], width / i);
        ratio[1] = min(ratio[1], height / i);	}
      }
    }
  }
  return ratio;
}
float *calculateDecimal(int width, int height) {
  float *ratio = (float *)malloc(sizeof(float) * 2);
  int maxVal = min(width, height);
  ratio[0]= (float)width/maxVal;
  ratio[1]= (float)height/maxVal;
  return ratio;
}

int main() {
  int *w = (int *)malloc(1);
  int *h = (int *)malloc(1);
  int width = *w;
  int height = *h;

  printf("w : ");
  scanf("%10i", &width);
  printf("h : ");
  scanf("%10i", &height);
  printf("w: %d, h: %d\n", *w, *h);

  int *ratio = calculateWhole(width, height);

  printf("ratio : %d:%d\n", ratio[0], ratio[1]);

  float *ratioF = calculateDecimal(width, height);

  printf("ratio : %.3f:%.3f\n", ratioF[0], ratioF[1]);

  free(w);
  free(h);
  free(ratio);
  free(ratioF);
  return 0;
}
