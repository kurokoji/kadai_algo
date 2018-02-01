#include <stdio.h>
#include <stdlib.h>
#include "chain_list.h"
#include "read_csv.h"
#include "baseball_struct.h"

Player* player_height;
Player* player_weight;
int player_height_sort(void);
int player_weight_sort(void);
void disp_ar(Player ar[], int num, int N);
void disp_player(Player *player);
void disp_team(int team_number);
void make_list(void);

int main(void) {
  int select;
  int player_num;
  make_list();
  printf("セ・リーグ投手データベース\n");
  player_num = player_height_sort();
  player_weight_sort();

  do {
    printf("何をしますか?\n");
    printf("0: 終了\n");
    printf("1: チームの検索\n");
    printf("2: ランキング(身長と体重)\n");

    printf(">> ");
    scanf("%d", &select);
    printf("\n");

    switch (select) {
      int n, kind;
    case 0:
      break;
    case 1:
      printf("0: CARP\n");
      printf("1: DENA\n");
      printf("2: DRAGONS\n");
      printf("3: GIANTS\n");
      printf("4: SWALLOWS\n");
      printf("5: TIGERS\n");
      scanf("%d", &n);
      disp_team(n);
      break;
    case 2:
      printf("0: 身長\n");
      printf("1: 体重\n");
      printf(">> ");
      scanf("%d", &kind);
      printf("表示人数は?\n");
      printf(">> ");
      scanf("%d", &n);
      switch (kind) {
      case 0:
        disp_ar(player_height, n, player_num);
        break;
      case 1:
        disp_ar(player_weight, n, player_num);
        break;
      }
      break;
    }
    printf("\n");

  } while (select != 0);

  free(player_height);
  free(player_weight);
  Init();
  return 0;
}

void make_list(void) {
  char filename[6][32] = {
    "./data/carp.csv",
    "./data/dena.csv",
    "./data/dragons.csv",
    "./data/giants.csv",
    "./data/swallows.csv",
    "./data/tigers.csv"
  };
  int i = 0;
  
  Init(); // 連結リストの初期化
  for (i = 0; i < 6; i++) {
    char readline[LINE_LENGTH];
    Player player;
    FILE *fp;
    if ((fp = fopen(filename[i], "r")) == NULL) {
      printf("error: Can not file open");
      exit(EXIT_FAILURE);
    }
    while (fgets(readline, LINE_LENGTH, fp) != NULL) {
      player = read_csv(readline, i);
      Add(i, &player);
    }
    fclose(fp);
  }

  for (i = 0; i < 6; i++) {
    Player* p = Header[i];
    while (p != NULL) {
      // printf("uniform: %d\n", p->uniform_number);
      p = p->node;
    }
  }
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

// 挿入ソート
int player_weight_sort(void) {
  int cnt = 0;
  int i, j;
  for (i = 0; i < 6; ++i) {
    Player* p;
    for (p = Header[i]; p->node != NULL; p = p->node) {
      cnt++;
    }
  }

  player_weight = (Player*)malloc(sizeof(Player) * cnt);
  int idx = 0;
  for (i = 0; i < 6; ++i) {
    Player* p;
    for (p = Header[i]; p->node != NULL; p = p->node) {
      player_weight[idx++] = *p;
    }
  }

  for (i = 1; i < cnt; ++i) {
    for (j = i; j > 0 && player_weight[j].weight > player_weight[j - 1].weight; --j) {
      swap(player_weight + j, player_weight + j - 1);
    }
  }
  return cnt;
}

void disp_ar(Player ar[], int num, int N) {
  int i;
  for (i = 0; i < num && i < N; ++i) {
    disp_player(&ar[i]);
  }
}

void disp_player(Player *player) {
  printf("-------------------------\n");
  printf("[チーム名]%s [背番号]%d [名前]%s\n", player->team_name, player->uniform_number, player->player_name);
  printf("[年数]%d\n", player->years);
  printf("[年齢]%d\n", player->age);
  printf("[身長]%dcm\n", player->height);
  printf("[体重]%dkg\n", player->weight);
  printf("[投打]%s\n", player->hand);
  printf("[出身校]%s\n", player->school_name);
  printf("-------------------------\n");
}

void disp_team(int team_number) {
  Player *p;
  for (p = Header[team_number]; p != NULL; p = p->node) {
    disp_player(p);
  }
}
