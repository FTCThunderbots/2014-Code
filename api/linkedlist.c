// linkedlist.c
// Contains code for a linked list structure

typedef struct Timer {
   float seconds;
	long miliseconds;
	bool running;
	long start;
	long previousTime;
} Timer_t;

typedef struct ListNode {
   struct ListNode *next;
   void *this;
} ListNode_t;

typedef struct LinkedList {
   ListNode_t head;
   byte length;
} LinkedList_t;

listAppend(LinkedList_t list, ListNode item) {
   list.length++;
   
   
ListNode_t listGet(LinkedList_t list, byte index) {
   ListNode item = list.head;
   for (int i = 0; i < index; i++)
      item = item.next;
   return item;
}