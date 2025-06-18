typedef struct LinkedList_Trie {
  char index;
  int value;
  struct LinkedList_Trie *next;
  struct LinkedList_Trie *children;
} LinkedTrie;

// node must be a valid pointer to a LinkedTrie node
void insertGLID(LinkedTrie *node, const char *keyword, int glID);
int findGLID(LinkedTrie *node, const char *keyword); 
int deleteGLID(LinkedTrie *node, const char *keyword); 