typedef char String[256];

typedef struct{
    int run;
    int wait;
    int end;
} Status;

typedef struct process{
    String processName;
    int processTime;
    Status processStatus;
    int priority;
    struct process *next;
} Process;

typedef struct{
    Process *front;
    int length;
} Scheduler;

Scheduler* create();
typedef int compareFunc(void* , void*);
int insertProcess(Scheduler *queue,Process *process,compareFunc* compare);        
int removeProcess(Scheduler *queue);