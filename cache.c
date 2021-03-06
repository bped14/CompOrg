//Direct Mapped Cache

//Structs (Cache and Block)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Block_ {
  int valid;
  int tag;
  int dirty;
}

struct Cache_ {
  int hits;
  int misses;
  int reads;
  int writes;
  int cache_size;
  int block_size;
  int lines;
  int write_policy;
  Block* blocks;
};
