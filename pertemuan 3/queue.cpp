#include <iostream>
using namespace std;

#define MAX 6
int queue[MAX];            // sama kaya int queue[6]
int front = -1, rear = -1; // diawalnya kosong

// Operasi Enqueue (Menambahkan elemen ke dalam antrean)
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        cout << "Queue sudah penuh!\n";
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        cout << value << " masuk kedalam queue\n";
    }
}

// Operasi Dequeue (Menghapus elemen terdepan dari antrean)
void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue kosong!\n";
    }
    else
    {
        cout << queue[front] << " keluar dari queue\n";
        front++;
    }
} // <-- Kurung tutup ini sebelumnya kurang, sehingga fungsi lain ikut masuk ke dalam dequeue

// Nampilin isi queue
void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue kosong\n";
    }
    else
    {
        cout << "Isi dari queue: ";
        // Diperbaiki: loop harus sampai i <= rear (sebelumnya i < rear)
        for (int i = front; i <= rear; i++) 
        {
            cout << queue[i] << " ";
        }
        cout << endl; // Tambahkan enter agar rapi
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();
    cout << "----------------------\n";

    enqueue(6);
    display();
    cout << "----------------------\n";

    dequeue();
    display();
    cout << "----------------------\n";

    return 0;
}