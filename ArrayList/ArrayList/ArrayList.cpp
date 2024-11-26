#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 // 리스트의 최대 크기

typedef int element; // 항목의 정의
typedef struct {
    element array[MAX_LIST_SIZE]; // 배열 정의
    int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리 함수
void error(const char* message)  // const char*로 수정
{
    fprintf(stderr, "%s\n", message); // 오류 메시지 출력
    exit(1);
}

// 리스트 초기화 함수
void init(ArrayListType* L)
{
    L->size = 0;
}

// 리스트가 비어 있으면 1을 반환, 그렇지 않으면 0을 반환
int is_empty(ArrayListType* L)
{
    return L->size == 0;
}

// 리스트가 가득 차 있으면 1을 반환, 그렇지 않으면 0을 반환
int is_full(ArrayListType* L)
{
    return L->size == MAX_LIST_SIZE;
}

// 리스트의 특정 위치에 있는 항목 반환
element get_entry(ArrayListType* L, int pos)
{
    if (pos < 0 || pos >= L->size)
        error("위치 오류");
    return L->array[pos];
}

// 리스트 출력
void print_list(ArrayListType* L)
{
    int i;
    for (i = 0; i < L->size; i++)
        printf("%d -> ", L->array[i]);
    printf("\n");
}

// 리스트의 끝에 항목 추가
void insert_last(ArrayListType* L, element item)
{
    if (L->size >= MAX_LIST_SIZE) {
        error("리스트 오버플로우");
    }
    L->array[L->size++] = item;
}

// 리스트의 특정 위치에 항목 삽입
void insert(ArrayListType* L, int pos, element item)
{
    if (pos < 0 || pos > L->size || is_full(L)) { // 수정된 조건문
        error("위치 오류 또는 리스트 오버플로우");
    }
    for (int i = L->size - 1; i >= pos; i--) {
        L->array[i + 1] = L->array[i];
    }
    L->array[pos] = item;
    L->size++;
}

// 리스트에서 특정 위치의 항목 삭제
element delete_element(ArrayListType* L, int pos)
{
    if (pos < 0 || pos >= L->size)
        error("위치 오류");
    element item = L->array[pos];
    for (int i = pos; i < L->size - 1; i++) {
        L->array[i] = L->array[i + 1];
    }
    L->size--;
    return item; // 삭제된 항목 반환
}

int main(void)
{
    ArrayListType list;

    init(&list);
    insert(&list, 0, 10); print_list(&list);
    insert(&list, 0, 20); print_list(&list);
    insert(&list, 0, 30); print_list(&list);
    insert_last(&list, 40); print_list(&list);
    delete_element(&list, 0); print_list(&list);

    return 0;
}