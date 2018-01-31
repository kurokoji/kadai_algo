#ifndef INCLUDE_BASEBALL_STRUCT_H
#define INCLUDE_BASEBALL_STRUCT_H

typedef struct Player {
  struct Player* node;
  int uniform_number; // 背番号
  char player_name[64]; // 選手名
  int years; // 年数
  int age; // 年齢
  int height; // 身長
  int weight; // 体重
  char hand[16]; // 投打の利き手
  char school_name[64]; // 出身校
  char team_name[64]; // 所属チーム
} Player;

#endif
