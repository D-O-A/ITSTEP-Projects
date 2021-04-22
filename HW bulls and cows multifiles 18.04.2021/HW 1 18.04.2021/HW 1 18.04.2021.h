#ifndef _bnc.h_
#define _bnc.h_

extern const int SIZE = 4;

void RiddleMeThis(int arr[], int SIZE);
int GetUserNum();
void ConvertUserInput(int brr[], int SIZE, int userNum);
int GetCows(int arr[], int brr[], int SIZE);
int GetBulls(int arr[], int brr[], int SIZE);
void PrintResult(int cows, int bulls);

#endif 