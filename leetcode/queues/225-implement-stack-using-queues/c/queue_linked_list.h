#if !defined(queue_linked_list)
#define queue_linked_list

void *queueCreate();
void queueDelete(void *queue);

void queueEnqueue(void *queue, int item);
int queueDequeue(void *queue);
int queuePeek(void *queue);

int queueSize(void *queue);
int isQueueEmpty(void *queue);

#endif // queue_linked_list
