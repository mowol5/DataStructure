#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct ListNode* link;
} ListNode;

// �� �տ� ��� ���� 
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

// �� ���� ��带 ����
ListNode* remove_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* remove(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode* search_list(ListNode* head, element x) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == x) return p;
	}
	return NULL; //Ž�� ����
}

ListNode* reverse(ListNode* head) {
	//��ȸ �����ͷ� p,q,r�� ���
	ListNode* p, * q, * r;

	p = head;//�������� ���� ����Ʈ
	q = NULL; //�������� ���� ���
	while (p != NULL) {
		r = q; //r�� �������� �� ����Ʈ
		//r�� q, q�� p�� ���ʷ� ���󰣴�
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	for (int i = 4; i >= 1; i--) {
		head1 = insert_first(head1, i * 10);
	}
	print_list(head1);
	print_list(head2);
	return 0;
}
