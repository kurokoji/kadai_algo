#ifndef INCLUDE_CHAIN_LIST_H
#define INCLUDE_CHAIN_LIST_H

#include "baseball_struct.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  CARP, DENA, DRAGONS, GIANTS, SWALLOWS, TIGERS
} team;

Player* Header[6];

void Delete(int team, Player* p) {
  if (p == NULL) return;
  if (p == Header[team]) {
    Player* t = Header[team];
    Header[team] = Header[team]->node;
    free(t);
  } else {
    Player* t, * s;
    for (t = Header[team]; t->node != p; t = t->node);
    if (t == NULL) return;
    s = t->node;
    t->node = s->node;
    free(s);
  }
}

void Init(void) {
  int i;
  for (i = 0; i < 6; ++i) {
    while (Header[i]) {
      Player* d = Header[i];
      Header[i] = Header[i]->node;
      free(d);
    }
  }
}

void Add(int team, Player* new_node) {
  if (Header[team] == NULL) {
    Header[team] = (Player*)malloc(sizeof(Player));
    if (Header[team] == NULL) {
      fprintf(stderr, "error\n");
      exit(1);
    }
    *Header[team] = *new_node;
    Header[team]->node = NULL;
  } else {
    Player* p, * t;
    for (p = Header[team]; p->node != NULL; p = p->node);
    t = (Player*)malloc(sizeof(Player));
    *t = *new_node;
    t->node = NULL;
    p->node = t;
  }
}


#endif
