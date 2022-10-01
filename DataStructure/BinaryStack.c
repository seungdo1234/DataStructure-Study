#include<stdio.h>

void binaryStack() {
	int num = 0, arrSize = 1;
	printf("2진수로 바꿀 10진수를 입력 :  ");
	scanf_s("%d", &num);
	int cnum = num;
	while (cnum > 1) { // 배열의 크기를 먼저 구함
		cnum /= 2;
		arrSize ++ ;
	}
	int* stack = (int*)malloc(sizeof(int) * arrSize ); // 동적할당
	for (int i = 0; i < arrSize; i++) {  // 푸시
		stack[i]= num % 2;
		num /= 2;
	}
	printf("2진수 = ");
	for (int i = arrSize - 1; i >= 0; i--) { // 팝
		printf("%d", stack[i]);
		stack[i] = NULL; 
	}
	free(stack);
}
void main() {
	binaryStack();	
}