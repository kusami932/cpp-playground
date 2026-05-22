#include <Windows.h>
#include <process.h>
#include <mutex>

#include <iostream>

static std::mutex coutMutex;

typedef struct MyData {
    int a1;
    int a2;
} MyData, *PMyData;

unsigned _stdcall myThreadFunc(void *lpParam) {
    MyData* param = (MyData*) lpParam;

    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << param->a1 << " + " << param->a2 << " = " << param->a1 + param->a2 << std::endl;
    }

    return 0;
}

int main() {
    const size_t MAX_THREADS = 6;

    PMyData paramArray[MAX_THREADS];
    HANDLE myThreadArray[MAX_THREADS];
    unsigned int myThreadIDArray[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        paramArray[i] = new MyData();
        paramArray[i]->a1 = i;
        paramArray[i]->a2 = i * i + 3 * i;

        myThreadArray[i] = (HANDLE) _beginthreadex(
            NULL,
            0,
            myThreadFunc,
            paramArray[i],
            0
            &myThreadIDArray[i]
        );
    }

    WaitForMultipleObjects(MAX_THREADS, myThreadArray, TRUE, INFINITE);

    for (int i = 0; i < MAX_THREADS; i++) {
        std::cout << myThreadsIDArray[i] << std::endl;
        CloseHandle(myThreadArray[i]);
        delete(paramArray[i]);
    }

    getchar();
    return 0;
}