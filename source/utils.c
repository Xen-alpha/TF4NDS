#include <utils.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// trie with linked list
// assumed that inserted textures are ordered by alphabet sequences
void insertGLID(LinkedTrie *node, const char *keyword, int glID) {
  if (keyword == NULL ) return; // 예외 처리?
  if (strlen(keyword) > 16 ) return; // 16 이상의 길이의 문자열은 삽입 불가
  LinkedTrie *cur = node; // 루트 노드(공백 노드)의 자식 노드로 시작
  int i = 0, len = strlen(keyword);
  for (i = 0; i < len; i++) {
    char c = keyword[i];
    if (cur->index == c) { // 인덱스와 현재 글자가 같다
      if (cur->children == NULL) { // 그런데 자식 노드가 없다?
        if (i == len - 1) {
          cur->value = glID; // 마지막 문자면 현 노드 값으로 GL ID 저장
        } else {
          cur->children = (LinkedTrie *) malloc(sizeof(LinkedTrie));
          cur->children->next = NULL;
          cur->children->children = NULL;
          cur->children->index = keyword[i+1]; // 다음 글자를 인덱스로 설정
          cur->children->value = -1; // 중간 노드므로 -1로 설정
        }
      } 
      cur = cur->children; // 자식 노드로 이동
    } else { // 인덱스와 현재 글자가 다르다
      while (cur->next != NULL) {
        if (cur->next->index == c) { // 다음 노드의 인덱스가 현재 문자와 같으면
          cur = cur->next; // 다음 노드로 이동
          break; // while 루프 탈출!
        } else { // 다음 노드의 인덱스가 현재 문자와 다르다
          cur = cur->next; // 다음 노드로 이동
        }
      }
      // 이제 현 위치가 마지막 노드므로 비교를 한다.
      if (cur->index == c) {
        if (cur->children == NULL) { // 그런데 자식 노드가 없다?
          if (i == len - 1) {
            cur->value = glID; // 마지막 문자면 현 노드 값으로 GL ID 저장
          } else {
            cur->children = (LinkedTrie *) malloc(sizeof(LinkedTrie));
            cur->children->next = NULL;
            cur->children->children = NULL;
            cur->children->index = keyword[i+1]; // 다음 글자를 인덱스로 설정
            cur->children->value = -1; // 중간 노드므로 -1로 설정
          }
        } 
        cur = cur->children; // 자식 노드로 이동
      } else {
        // next에 새 노드를 끼워 만든다.
        cur->next = (LinkedTrie *) malloc(sizeof(LinkedTrie));
        cur->next->next = NULL;
        cur->next->children = NULL;
        cur->next->index = c; // 현 글자를 인덱스로 설정
        if (i == len - 1) {
          cur->next->value = glID; // 마지막 문자면 현 노드 값으로 GL ID 저장
          return;
        } else {
          cur->next->value = -1; // 중간 노드므로 -1로 설정
        }
        cur = cur->next; // 다음 노드로 이동
        // 다음 글자를 자식 노드로 설정
        if (i < len - 1) {
          cur->children = (LinkedTrie *) malloc(sizeof(LinkedTrie));
          cur->children->next = NULL;
          cur->children->children = NULL;
          cur->children->index = keyword[i+1]; // 다음 글자를 인덱스로 설정
          cur->children->value = -1; // 중간 노드이므로 -1로 설정
          cur = cur->children; // 자식 노드로 이동
        } else {
          cur->children = NULL; // 마지막 문자이므로 자식 노드는 없음
          cur->value = glID; // 마지막 문자면 현 노드 값으로 GL ID 저장
        }
      }
    }
  }
  //printf("Inserted '%s' with GL ID %d\n", keyword, glID);
  return; // 삽입 완료
}

int findGLID(LinkedTrie *node, const char *keyword) {
  if (node == NULL || keyword == NULL ) return -1;
  if (strlen(keyword) > 16 ) return -1; // 16 이상의 길이의 문자열은 삽입 불가
  LinkedTrie *cur = node;
  int len = strlen(keyword);
  for (int i = 0; i < len; i++) {
    char c = keyword[i];
    if (c == cur->index) {
      if (i == len - 1) { //마지막 문자면
        //printf("Found '%s' with GL ID %d\n", keyword, cur->value);
        return cur->value; // GL ID 반환
      }
      if (cur->children == NULL) {
        // 더 못 내려가므로 못 찾음
        //printf("Cannot find '%s' in trie(child)\n", keyword);
        return -1; // 못 찾음
      }
      cur = cur->children; // 자식 노드로 이동
    } else { // 인덱스와 현재 글자가 다르다 -> next 노드로 이동
      // 현재 노드의 다음 노드로 이동
      while (cur->next != NULL) {
        if (cur->next->index == c) { // 다음 노드의 인덱스가 현재 문자와 같으면
          cur = cur->next; 
          break; // 다음 노드로 이동하고 바로 멈춰서 while 이후를 실행
        }
        cur = cur->next; // 다음 노드로 이동
        //printf("Moving to next node: %c\n", cur->index);
      }
      if (cur->index != c) { // 현재 인덱스가 c가 아니면...
        //printf("Cannot find '%s' in trie(next)\n", keyword);
        return -1; // 못 찾음
      } else {
        if (i == len - 1) { // 마지막 문자면
          return cur->value; // GL ID 반환
        }
        if (cur->children == NULL) {
          // 더 못 내려가므로 못 찾음
          //printf("Cannot find '%s' in trie(child)\n", keyword);
          return -1; // 못 찾음
        }
        cur = cur->children; // 자식 노드로 이동
      }
    }
  }
  //printf("Cannot find '%s' in trie\n", keyword);
  return -1; // 못 찾음
}