#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct
{
    char data[MAX][255];
    int top;
} stack;

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} queue;

void iniStack(stack *s)
{
    s-> top = -1;
}

void iniqueue(queue *q)
{
    q->front = q->rear = -1;
}

int fullstack(stack *s)
{
    return s->top == MAX - 1;
}

int emptystack(stack *s)
{
    return s->top == -1;
}

int fullqueue(queue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

int emptyqueue(queue *q)
{
    return q->front == -1;
}

void push(stack *s, char str[])
{
    if (fullstack(s))
    {
        printf("Stack penuh!\n");
        return;
    }

    strcpy(s->data[++s->top], str);
    printf("%s MASUK!!!\n", str);
}

char *pop(stack *s)
{
    if (emptystack(s))
    {
        printf("Stack kosong!\n");
        return "";
    }

    return s->data[s->top--];
}

void printstack(stack *s)
{
    if (emptystack(s))
    {
        printf("Stack kosong!\n");
        return;
    }

    for (int i = s->top; i >= 0; i--)
        printf("Data Stack ke %d : %s\n", i + 1, s->data[i]);
}

void deletestack(stack *s)
{
    iniStack(s);
    printf("Data stack berhasil dihapus\n");
}

void enqueue(queue *q, int x)
{
    if (fullqueue(q))
    {
        printf("Antrian penuh!\n");
        return;
    }
    else if (emptyqueue(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }

    q->data[q->rear] = x;
    printf("%d MASUK!!!\n", x);
}

int dequeue(queue *q)
{
    int x;

    if (emptyqueue(q))
    {
        printf("Antrian kosong!\n");
        exit(0);
    }
    else
    {
        x = q->data[q->front];

        if (q->front == q->rear)
        {
            iniqueue(q);
        }
        else
        {
            q->front = (q->front + 1) % MAX;
        }

        return x;
    }
}

void printqueue(queue *q)
{
    int i = q->front;
    int j = 0;

    while (i != q->rear)
    {
        printf("Data ke %d = %d\n", j++, q->data[i]);
        i = (i + 1) % MAX;
    }

    printf("Data ke %d = %d\n", j++, q->data[q->rear]);

    return 0;
}

void deletequeue(queue *q)
{
    iniqueue(q);
    printf("Data queue berhasil dihapus\n");
}
int penjelasanstack()
{
    printf("stack adalah tipe data abstrak yang berfungsi sebagai kumpulan elemen, dengan dua operasi utama: \npush, yang menambahkan elemen ke kumpulan, \ndan pop, yang menghapus elemen yang paling baru ditambahkan yang belum dihapus.\n Urutan di mana elemen ditambahkan atau dihapus dari stack disebut sebagai \nlast in, first out (LIFO) atau first in, last out (FILO).\nStack mirip dengan tumpukan piring di restoran prasmanan atau kantin. \nPiring yang berada di atas adalah yang pertama kali diambil, \nsedangkan piring yang diletakkan di posisi paling bawah tetap berada di dalam stack untuk waktu yang paling lama.");
    getch();
    system("cls");
}

int penjelasanqueue()
{
    printf("Queue adalah jenis struktur data yang menerapkan konsep FIFO (First In First Out), yaitu elemen yang dimasukkan pertama kali akan diproses terlebih dahulu\n");
    printf("Queue memiliki dua operasi dasar, yaitu Enqueue untuk menambahkan elemen di posisi belakang dan Dequeue untuk mengambil elemen di posisi depan\n");
    getchar();
    system("cls");
}

int main()
{
    stack s;
    queue q;

    iniStack(&s);
    iniqueue(&q);

    int menuutama;
    int submenu;

    char str[255];
    int x;

    do
    {
        printf("===========================\n");
        printf("Tugas Quiz Stack and Queue\n");
        printf("===========================\n");
        printf("1. Stack String\n");
        printf("2. Queue Integer\n");
        printf("3. Penjelasan Stack\n");
        printf("4. Penjelasan Queue\n");
        printf("5. Exit Program\n");
        printf("===========================\n");

        do
        {
            printf("Pilihan anda: ");
            scanf("%d", &menuutama);
            getchar();
            system("cls");
        } while (menuutama < 1 || menuutama > 5);

        switch (menuutama)
        {
        case 1:
            do
            {
                printf("1. Push Stack\n");
                printf("2. Pop Stack\n");
                printf("3. Print Stack\n");
                printf("4. Delete Stack\n");
                printf("5. Kembali\n");
                printf("==========================");

                do
                {
                    printf("\nPilihan anda: ");
                    scanf("%d", &submenu);
                    getchar();
                    system("cls");
                } while (submenu < 1 || submenu > 5);

                switch (submenu)
                {
                case 1:
                    if (!fullstack(&s))
                    {
                        printf("\nMasukkan string: ");
                        scanf("%[^\n]", str);
                        getchar();

                        push(&s, str);
                    }
                    else
                        printf("\nStack penuh!\n");

                    break;
                case 2:
                    if (!emptystack(&s))
                        printf("\nPop stack: %s\n", pop(&s));
                    else
                        printf("\nStack kosong!\n");

                    break;
                case 3:
                    printstack(&s);

                    break;
                case 4:
                    deletestack(&s);

                    break;
                default:
                    break;
                }
            } while (submenu != 5);

            break;
        case 2:
            do
            {
                printf("1. Enqueue Int\n");
                printf("2. Dequeue Int\n");
                printf("3. Print Queue\n");
                printf("4. Delete Queue\n");
                printf("5. Kembali\n");
                printf("=======================");

                do
                {
                    printf("\nPilihan anda: ");
                    scanf("%d", &submenu);
                    getchar();
                    system("cls");
                } while (submenu < 1 || submenu > 5);

                switch (submenu)
                {
                case 1:
                    if (!fullqueue(&q))
                    {
                        printf("\nMasukkan integer: ");
                        scanf("%d", &x);
                        getchar();

                        enqueue(&q, x);
                    }
                    else
                        printf("\nQueue penuh!\n");

                    break;
                case 2:
                    if (!emptyqueue(&q))
                        printf("\nDequeue queue: %d\n", dequeue(&q));
                    else
                        printf("\nQueue kosong!\n");

                    break;
                case 3:
                    printqueue(&q);

                    break;
                case 4:
                    deletequeue(&q);

                    break;
                default:
                    break;
                }
            } while (submenu != 5);

            break;
        case 3:
            penjelasanstack();
            break;
        case 4:
            penjelasanqueue();
            break;

        default:
            printf("\n\n\t\t\t\t\tTERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI :)\n\n\n\n\n\n\n\n");
            exit(0);
        }
    } while (1);

    return 0;
}
