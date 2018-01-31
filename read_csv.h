#ifndef INCLUDE_READ_CSV_H
#define INCLUDE_READ_CSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baseball_struct.h"

#define LINE_LENGTH 128

Player read_csv(char line[], char team_name[]) {
  Player ret;
  sscanf(line, "%d,%s,%d,%d,%d,%d,%s,%s", &ret.uniform_number, ret.player_name
      , &ret.years, &ret.age, &ret.height, &ret.weight, ret.hand, ret.team_name);
  strcpy(ret.team_name, team_name);

  return ret;
}

int main(void) {
  char filename[] = "./data/carp.csv";
  char readline[LINE_LENGTH];
  Player player;
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("error: Can not file open");
    return EXIT_FAILURE;
  }
  while (fgets(readline, LINE_LENGTH, fp) != NULL) {
    printf("%s\n", readline);
    player = read_csv(readline, "hoge");
    printf("1: %d\n", player.uniform_number);
  }

  return (0);
}

#endif

