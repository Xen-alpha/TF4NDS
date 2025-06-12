typedef struct LinkedList_Trie {
  char index[16];
  int value;
  struct LinkedList_Trie *next;
  struct LinkedList_Trie *children;
} LinkedTrie;

