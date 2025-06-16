typedef struct LinkedList_Trie {
  char index;
  int value;
  struct LinkedList_Trie *next;
  struct LinkedList_Trie *children;
} LinkedTrie;

void insertGLID(LinkedTrie *node, const char *keyword, int glID); // level must be positive integer
int findGLID(LinkedTrie *node, const char *keyword); // level must be positive integer
