#include <stdio.h>
#include <stdlib.h>

struct Node {
  int coef; //  coefficient
  int exp;  //  exponent
  struct Node *next;
};
typedef struct Node PolyNode;
typedef PolyNode *PolyList;

void print_all_links(PolyList head);
PolyList sum_polymonial(PolyList a, PolyList b);
PolyList create_node(int coef, int exp);
PolyList create_polymonial(int data[]);

int main() {
  PolyList a, b, c;
  int data1[4] = {3, 0, 4, 2};
  int data2[4] = {6, 8, 6, 9};
  a = create_polymonial(data1);
  b = create_polymonial(data2);
  printf("原始多項式：\nA=\t");
  print_all_links(a);
  printf("\n原始多項式：\nB=\t");
  print_all_links(b);
  printf("\n多項式相加結果：\nC=\t");
  c = sum_polymonial(a, b);
  print_all_links(c);
}

void print_all_links(PolyList head) {
  while (head != NULL) {
    if (head->coef == 0) {
      head = head->next;
      continue;
    }
    switch (head->exp) {
    case 0:
      printf("%d", head->coef);
      break;
    case 1:
      printf("%dX", head->coef);
      break;
    default:
      printf("%dX^%d", head->coef, head->exp);
      break;
    }
    if (head->next != NULL) {
      printf(" + ");
    }
    head = head->next;
  }
}

PolyList sum_polymonial(PolyList a, PolyList b) {
  int sum[4], i = 0;
  PolyList ptr = b;
  while (a != NULL) {
    b = ptr;
    while (b != NULL) {
      if (a->exp == b->exp) {
        sum[i] = a->coef + b->coef;
        a = a->next;
        b = b->next;
      } else if (a->exp > b->exp) {
        sum[i] = a->coef;
        a = a->next;
      } else if (a->exp < b->exp) {
        sum[i] = b->coef;
        b = b->next;
      }
      i++;
    }
  }
  return create_polymonial(sum);
}

PolyList create_node(int coef, int exp) {
  PolyList newNode = (PolyList)malloc(sizeof(PolyNode));
  if (!newNode) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(1);
  }
  newNode->coef = coef;
  newNode->exp = exp;
  newNode->next = NULL;
  return newNode;
}

PolyList create_polymonial(int data[]) {
  PolyList head, newnode, ptr;
  int i;
  for (i = 0; i < 4; i++) {
    newnode = create_node(data[i], 3 - i);
    if (i == 0) {
      head = newnode;
      ptr = head;
      continue;
    }
    ptr->next = newnode;
    ptr = newnode;
  }
  return head;
}
