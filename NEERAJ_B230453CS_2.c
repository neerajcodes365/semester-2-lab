#include <stdio.h>
int top = -1;

struct job
{
    int job_id;
    int priority;
};
typedef struct job job;

void swap(job *x, job *y)
{
    job temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(job arr[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l].priority < arr[largest].priority)
        largest = l;

    if (r < size && arr[r].priority < arr[largest].priority)
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapsort(job arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void add(job arr[], int id, int p)
{
    top = top + 1;
    arr[top].job_id = id;
    arr[top].priority = p;
    heapsort(arr, top + 1);
}

void schedule(job arr[])
{
    if (top == -1)
    {
        printf("-1");
    }
    else
    {
        swap(&arr[0], &arr[top]);
        printf("%d\n",arr[top].job_id);
        top--;
        heapsort(arr, top + 1);
    }
}

void next_job(job arr[])
{
    if (top == -1)
    {
        printf("-1");
    }
    else
    {
        printf("%d\n", arr[0].job_id);
    }
}
void replace_priority(job arr[], int id, int np)
{
     int c = 0;
    for (int i = 0; i < top + 1; i++)
    {
       
        if (arr[i].job_id == id)
        {
            c++;
            arr[i].priority = np;
        }
    }
    if (c == 0)
        printf("-1");
     heapsort(arr, top + 1);
}

void display(job arr[])
{
    if (top == -1)
    {
        printf("-1");
    }
    else
    {
        for (int i = 0; i < top + 1; i++)
        {
            printf("%d ", arr[i].job_id);
            printf("%d", arr[i].priority);
            printf("\n");
        }
    }
}
int main()
{
    job jobs[20];
    int id, p, np;
    char choice;
    do
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            scanf("%d", &id);
            scanf("%d", &p);
            add(jobs, id, p);
            break;
        case 's':
            schedule(jobs);
            break;
        case 'n':
            next_job(jobs);
            break;
        case 'r':
            scanf("%d", &id);
            scanf("%d", &np);
            replace_priority(jobs, id, np);
            break;
        case 'd':
            display(jobs);
            break;
        case 'e':
            break;
        default:
            printf("invalid input\n");
        }
    } while (choice != 'e');
    return 0;
}