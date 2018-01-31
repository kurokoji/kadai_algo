#include <stdio.h>
#include <stdlib.h>
#include "chain_list.h"
#include "read_csv.h"

void make_list(void);

int main(void) {
  int select;
  make_list();
  printf("セ・リーグ投手データベース\n");

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
      break;
    }

  } while (select != 0);

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
  }
  for (i = 0; i < 6; i++) {
    Player* p = Header[i];
    while (p != NULL) {
      // printf("uniform: %d\n", p->uniform_number);
      p = p->node;
    }
  }
}
