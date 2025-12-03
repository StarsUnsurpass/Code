#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DoublyLinkedList.h"

int main(void) {
	printf("==== Doubly Linked List Test ====\n\n");

	// 1.创建一个空的播放列表
	printf(">> Initializing playlist...\n");
	DoublyLinkedList* playlist = createList();
	if (!playlist) {
		return 1;
	}
	printListForward(playlist);
	printf("\n");

	// 2.添加初始歌单
	printf(">> Adding initial songs to the playlist using append()...\n");
	append(playlist, (Song) { "Hear my hope", "Amily", 317 });
	append(playlist, (Song) { "Loser, baby", "Husk", 198 });
	append(playlist, (Song) { "Gravity", "Rute", 178 });
	printListForward(playlist);
	printf("\n");

	// 3.演示先前遍历和向后遍历
	printf(">> Verfying backward traversal...\n");
	printListBackward(playlist);
	printf("\n");

	// 4.演示插入操作
	printf(">> Action: Inserting 'More than anything' after 'Hear my hope'.\n");
	printf("	This is an O(1) operation once the target node is found.\n");
	Node* HearMyHopeNode = findByTitle(playlist, "Hear my hope");
	if (HearMyHopeNode) {
		insertAfter(playlist, HearMyHopeNode, (Song) { "More than anything", "Lucifer", 136 });
		printListForward(playlist);
	}
	else {
		printf("	Could not fing 'Hear my hope'.\n");
	}
	printf("\n");

	// 5.演示在头部插入
	printf(">> Action: Inserting 'First Class' at the very beginning.\n");
	printf("	This is an O(1) operation.\n");
	prepend(playlist, (Song) { "First Class", "Jack Harlow", 174 });
	printListForward(playlist);
	printf("\n");

	// 6.演示删除操作
	printf(">> Action: Deleting 'Gravity' from the palylist.\n");
	printf("	This is an O(1) operation once the rarget node is found.\n");
	Node* GravityNode = findByTitle(playlist, "Gravity");
	if (GravityNode) {
		deleteNode(playlist, GravityNode);
		printListForward(playlist);
	}
	else {
		printf("	Could not found 'Gravity'.\n");
	}
	printf("\n");

	// 7.演示删除头节点
	printf(">> Action: Deleting the head node ('First Class').\n");
	Node* headNode = playlist->head;
	if (headNode) {
		deleteNode(playlist, headNode);
		printListForward(playlist);
	}
	printf("\n");

	// 8.演示删除尾节点
	printf(">> Action: Deleting the tail node ('Loser, baby').\n");
	Node* tailNode = playlist->tail;
	if (tailNode) {
		deleteNode(playlist, tailNode);
		printListForward(playlist);
	}
	printf("\n");

	// 9.清理工作
	printf(">> Demo finished. Freeing all allocated memory...\n");
	freeList(playlist);
	printf("	Memory has been successfully freed.\n");

	return 0;
}