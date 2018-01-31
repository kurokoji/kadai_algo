typedef struct Player {
  struct Player* node;
  int uniform_number; // 背番号
  char player_name[64]; // 選手名
  int years; // 年数
  int age; // 年齢
  float height; // 身長
  float weight; // 体重
  char hand[4]; // 投打の利き手
  char school_name[64]; // 出身校
  char team_name[64]; // 所属チーム
} Player;
