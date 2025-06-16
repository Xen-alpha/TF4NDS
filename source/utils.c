#include <utils.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// trie with linked list
// assumed that inserted textures are ordered by alphabet sequences
void insertGLID(LinkedTrie *node, const char *keyword, int glID, int level) {
  if (keyword == NULL || level <= 0 ) return; // 예외 처리?
  if (node == NULL) { // 이건 바로 삽입
    LinkedTrie *newNode = (LinkedTrie *) malloc(sizeof(LinkedTrie));
    newNode->next = NULL;
    strncpy(newNode->index, keyword, 16);
    newNode->value = glID;
    newNode->children = NULL;
    node = newNode;
    return;
  }
  if (strlen(keyword) > 16 || level > 16) return; // 16 이상의 길이의 문자열은 삽입 불가
  LinkedTrie *cur = node;
  do {
    int compare = strncmp(keyword, cur->index, level);
    if (compare == 0) { // 일부 일치
      int keywordSize = strlen(keyword);
      int indexSize = strlen(cur->index);
      if (keywordSize == level) { // 완전 일치(이미 있는 경우)
        return; 
      }
      else if (cur->children) { // child가 있는 경우 -> 더 긴 길이를 비교해야 한다.
        if (indexSize == level) return insertGLID(cur->children, keyword, glID, level+1);
        return insertGLID(cur, keyword, glID, level + 1);
      }
      else { // 일부만 일치하고 child 없음 -> 이전에 삽입된 키워드를 접두사로 하는 새로운 키워드이므로 child로 삽입
        LinkedTrie *newNode = (LinkedTrie *) malloc(sizeof(LinkedTrie));
        newNode->next = NULL;
        strncpy(newNode->index, keyword, 16);
        newNode->value = glID;
        newNode->children = NULL;
        cur->children = newNode;
        return;
      }
    }
    // 일부 일치는 안 되는데 next가 있다면 일단 그리로 간다
    if (cur-> next != NULL ) cur = cur->next;
  } while (cur->next != NULL);
  // 일부 일치도 안 되는데 여기까지 왔다면 next로 삽입
  LinkedTrie *newNode = (LinkedTrie *) malloc(sizeof(LinkedTrie));
  newNode->next = NULL;
  strncpy(newNode->index, keyword, 16);
  newNode->value = glID;
  newNode->children = NULL;
  cur->next = newNode;
  return;
}

int findGLID(LinkedTrie *node, const char *keyword, int level) {
  if (node == NULL || keyword == NULL || level <= 0) return -1;
  if (strlen(keyword) > 16 || level > 16) return -1; // 16 이상의 길이의 문자열은 삽입 불가
  LinkedTrie *cur = node;
  do {
    int compare = strncmp(keyword, cur->index, level);
    if (compare == 0) { // 일부 일치
      int keywordSize = strlen(keyword);
      int indexSize = strlen(cur->index);
      if (keywordSize == level) { // 완전 일치(이미 있는 경우) -> GLID 반환
        return cur->value; 
      }
      else if (cur->children) { // child가 있는 경우 -> 더 긴 길이를 비교해야 한다.
        if (indexSize == level) return findGLID(cur->children, keyword, level + 1);
        return findGLID(cur, keyword, level + 1);
      }
      else { // 일부만 일치하고 child 없음 -> 못 찾음
        return -1;
      }
    }
    // 일부 일치가 안 되는데 여기까지 왔다면 next로 가야 한다.   
    if (cur->next != NULL) cur = cur->next;
  } while (cur->next != NULL);
  return -1; // 못 찾음
}