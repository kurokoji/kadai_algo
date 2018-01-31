#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int select;
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
