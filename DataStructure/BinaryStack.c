#include<stdio.h>

void binaryStack() {
	int num = 0, arrSize = 1;
	printf("2������ �ٲ� 10������ �Է� :  ");
	scanf_s("%d", &num);
	int cnum = num;
	while (cnum > 1) { // �迭�� ũ�⸦ ���� ����
		cnum /= 2;
		arrSize ++ ;
	}
	int* stack = (int*)malloc(sizeof(int) * arrSize ); // �����Ҵ�
	for (int i = 0; i < arrSize; i++) {  // Ǫ��
		stack[i]= num % 2;
		num /= 2;
	}
	printf("2���� = ");
	for (int i = arrSize - 1; i >= 0; i--) { // ��
		printf("%d", stack[i]);
		stack[i] = NULL; 
	}
	free(stack);
}
void main() {
	binaryStack();	
}