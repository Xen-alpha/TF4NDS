typedef struct LinkedList_Trie {
  char index[16];
  int value;
  struct LinkedList_Trie *next;
  struct LinkedList_Trie *children;
} LinkedTrie;

void insertGLID(LinkedTrie *node, const char *keyword, int glID, int level); // level must be positive integer
int findGLID(LinkedTrie *node, const char *keyword, int level); // level must be positive integer
