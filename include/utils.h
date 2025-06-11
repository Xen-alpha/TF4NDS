typedef struct LinkedList_Trie {
  unsigned char indexChar;
  int value;
  struct LinkedList_Trie *next;
  struct LinkedList_Trie *children;
} LinkedTrie;

