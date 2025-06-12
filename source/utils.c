#include <utils.h>
#include <stdio.h>
#include <string.h>

// trie with linked list
// assumed that inserted textures are ordered by alphabet sequences
void insertGLID(LinkedTrie *node, char *keyword, int keylength) {
  for (LinkedTrie *parent = node; parent != NULL;parent = parent->children){
    for (LinkedTrie *cur = parent; cur != NULL; cur = parent->next) {
      if (strcmp(keyword, cur->index) == 0) {
        return;
      } 
    }
  }
}

int findGLID(LinkedTrie *node, char *keyword) {
  return 0;
}