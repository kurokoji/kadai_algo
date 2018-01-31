#include <stdio.h>
#include <stdlib.h>
#include "baseball_struct.h"
#include "chain_list.h"


Player* player_height;
int player_height_sort(void);
void disp_ar(Player ar[], int num, int N);

int main(void) {
  int select;
  int player_num;
  printf("セ・リーグ投手データベース\n");
  player_num = player_height_sort();

  do {
    printf("何をしますか?\n");
    printf("0: 終了\n");
    printf("1: チームの検索\n");
    printf("2: ランキング(身長と体重)\n");

    scanf("%d", &select);

    switch (select) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      disp_ar(player_height, 10, player_num);
      break;
    }

  } while (select != 0);

  return 0;
}

void swap(Player* a, Player* b) {
  Player t = *a;
  *a = *b;
  *b = t;
}

// 挿入ソート
int player_height_sort(void) {
  int cnt = 0;
  int i, j;
  for (i = 0; i < 6; ++i) {
    Player* p;
    for (p = Header[i]; p->node != NULL; p = p->node) {
      cnt++;
    }
  }

  player_height = (Player*)malloc(sizeof(Player) * cnt);
  int idx = 0;
  for (i = 0; i < 6; ++i) {
    Player* p;
    for (p = Header[i]; p->node != NULL; p = p->node) {
      player_height[idx++] = *p;
    }
  }

  for (i = 1; i < cnt; ++i) {
    for (j = i; j > 0 && player_height[j].height > player_height[j - 1].height; --j) {
      swap(player_height + j, player_height + j - 1);
    }
  }
  return cnt;
}

void disp_ar(Player ar[], int num, int N) {
  int i;
  for (i = 0; i < num && i < N; ++i) {
    printf("%d,%s,%d,%d,%d,%d,%s,%s,%s\n", ar[i].uniform_number, ar[i].player_name, ar[i].years, ar[i].age, ar[i].height, ar[i].weight, ar[i].hand, ar[i].school_name, ar[i].team_name);
  }
}
