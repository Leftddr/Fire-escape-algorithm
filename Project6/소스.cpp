/*#include <stdio.h>
#include <Windows.h>

int main() {
	int test;
	int memory[2];
	int num;
	int app[100][2];
	int result = 0;
	int count;
	int count2;
	int cri;
	scanf_s("%d", &test);

	while (test>0) {
		scanf_s("%d %d", &memory[0], &memory[1]);
		cri = memory[1] - memory[0];
		scanf_s("%d", &num);
		for (int i = 0; i < num; i++) {
			scanf_s("%d %d", &app[i][0],&app[i][1]);
		}
		for (int i = 0; i < num - 1; i++) {
			for (int j = i + 1; j < num; j++) {
				if (app[i][0] >= app[j][0]) {
					int temp1, temp2;
					temp1 = app[i][0]; temp2 = app[i][1];
					app[i][0] = app[j][0]; app[i][1] = app[j][1];
					app[j][0] = temp1; app[j][1] = temp2;
				}
			}
		}
		count = app[0][1];
		count2 = app[0][0];
		int num1;
		for (int i = 1; i < num; i++) {
			num1 = count + app[i][1];
			if (num1 <= cri) {
				count += app[i][1];
				result += (count2 + app[i][0]);
				count2 += app[i][0];
			}
			else {
				num1 -= app[i][1];
			}
		}
		test--;
	}
	printf("result=%d\n", result);
	Sleep(100000);
}
*/