#include <stdio.h>
#include <Windows.h>

#define SIZE 5
#define QUEQU 10

int x;
int MAX = 1000;
int count = 1;
int map[SIZE][SIZE] = { {MAX,0,0,0,-1},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{1,0,MAX,MAX,0} };
void update();
void print();
bool save();

int main() {
	printf("횟수를 입력하세요 : ");
	scanf_s("%d", &x);
	bool start = true;

	while (1) {
		if (start == true) {
			for (int k = 0; k < x+1; k++) {
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						if (map[i][j] == count) {
							bool cri = save();
							if (cri == true) { printf("you are saved!\n"); Sleep(10000); return 0; }
							if (i < SIZE - 1 && map[i + 1][j] != count && map[i + 1][j] < 1000) { map[i + 1][j] = count + 1; }
							if (j < SIZE - 1 && map[i][j + 1] != count && map[i][j+1] < 1000) { map[i][j + 1] = count + 1; }
							if (i >= 1 && map[i - 1][j] != count && map[i - 1][j] < 1000) { map[i - 1][j] = count + 1; }
							if (j >= 1 && map[i][j - 1] != count && map[i][j-1] < 1000) { map[i][j - 1] = count + 1; }
						}
					}
				}
				count += 1;
				if (k == x) { update(); }
				print(); Sleep(5000);
			}
			start = false;
		}
		else {
			for (int k = 0; k < x; k++) {
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						if (map[i][j] == count) {
							bool cri = save();
							if (cri == true) { printf("you are saved!\n"); Sleep(10000); return 0; }
							if (i < SIZE - 1 && map[i + 1][j] != count && map[i + 1][j] < 1000) { map[i + 1][j] = count + 1; }
							if (j < SIZE - 1 && map[i][j + 1] != count && map[i][j + 1] < 1000) { map[i][j + 1] = count + 1; }
							if (i >= 1 && map[i - 1][j] != count && map[i - 1][j] < 1000) { map[i - 1][j] = count + 1; }
							if (j >= 1 && map[i][j - 1] != count && map[i][j - 1] < 1000) { map[i][j - 1] = count + 1; }
						}
					}
				}
				count += 1;
				if (k == x - 1) { update(); }
				print(); Sleep(5000);
			}
		}
	}
	
}

void update() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (map[i][j] == MAX) {
				if (i<SIZE-1 && map[i+1][j]!=MAX) { map[i + 1][j] = MAX+1; }
				if (j<SIZE-1 && map[i][j+1] != MAX) { map[i][j+1] = MAX+1; }
				if (i>=1 && map[i-1][j] != MAX) { map[i-1][j] = MAX+1; }
				if (j>=1 && map[i][j-1] != MAX) { map[i][j-1] = MAX+1; }
			}
		}
	}
	MAX += 1;
}

void print() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%8d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool save() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (map[i][j] == count) {
				if (i < SIZE - 1 && map[i + 1][j] == -1) { return true; }
				if (j < SIZE - 1 && map[i][j + 1] == -1) { return true; }
				if (i >= 1 && map[i - 1][j] == -1) { return true; }
				if (j >= 1 && map[i][j - 1] == -1) { return true; }
			}
		}
	}
	return false;
}

