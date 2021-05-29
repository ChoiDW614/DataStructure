#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ListBaseQueue.h"

constexpr int CUS_COME_TERM = 15;

constexpr int CHE_BUR       = 0;
constexpr int BUL_BUR       = 1;
constexpr int DUB_BUR       = 2;

constexpr int CHE_TERM      = 12;
constexpr int BUL_TERM      = 15;
constexpr int DUB_TERM      = 24;

int main()
{
    int makeProc = 0;
    int cheOrder = 0, bulOrder = 0, dubOrder = 0;
    int sec;

    Queue que;

    QueueInit(&que);
    srand(time(nullptr));

    for(sec=0; sec<3600; sec++)
    {
        if(sec % CUS_COME_TERM == 0)
        {
            switch(rand() % 3)
            {
                case CHE_BUR:
                    Enqueue(&que, CHE_TERM);
                    cheOrder += 1;
                    break;

                case BUL_BUR:
                    Enqueue(&que, BUL_TERM);
                    bulOrder += 1;
                    break;

                case DUB_BUR:
                    Enqueue(&que, DUB_TERM);
                    dubOrder += 1;
                    break;
            }
        }
        if(makeProc <=0 && !QIsEmpty(&que))
            makeProc = Dequeue(&que);

        makeProc--;
    }

    std::cout << "Simulation Report" << std::endl;
    std::cout << " - Cheese burger: " << cheOrder << std::endl;
    std::cout << " - Bulgogi burger: " << bulOrder << std::endl;
    std::cout << " - Double burger: " << dubOrder << std::endl;
    std::cout << " - Waiting room size: " << QUE_LEN << std::endl;

    return 0;
}