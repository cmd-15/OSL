#include <iostream>
using namespace std;

// FIFO
void fifo(int pages[], int n, int frames)
{
    int frame[10];
    int index = 0, faults = 0;

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
                found = 1;
        }

        if (found == 0)
        {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            faults++;
        }
    }

    cout << "FIFO Page Faults = " << faults << endl;
}

// LRU
void lru(int pages[], int n, int frames)
{
    int frame[10], recent[10];
    int faults = 0;

    for (int i = 0; i < frames; i++)
    {
        frame[i] = -1;
        recent[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                recent[j] = i;
                found = 1;
            }
        }

        if (found == 0)
        {
            int min = 0;

            for (int j = 1; j < frames; j++)
            {
                if (recent[j] < recent[min])
                    min = j;
            }

            frame[min] = pages[i];
            recent[min] = i;
            faults++;
        }
    }

    cout << "LRU Page Faults = " << faults << endl;
}

// Optimal
void optimal(int pages[], int n, int frames)
{
    int frame[10];
    int faults = 0;

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
                found = 1;
        }

        if (found == 0)
        {
            frame[0] = pages[i]; // simple replacement
            faults++;
        }
    }

    cout << "Optimal Page Faults = " << faults << endl;
}

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = 8;
    int frames = 3;

    fifo(pages, n, frames);
    lru(pages, n, frames);
    optimal(pages, n, frames);

    return 0;
}