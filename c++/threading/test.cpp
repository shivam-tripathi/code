// Compile as g++ test.cpp p_threads_class.cpp -std=c++11 -lpthreads -o3

#include "p_threads_class.h"
#include <bits/stdc++.h>
using namespace std;

class TestThread : public PThreadsClass{
public:
    void run(){
        cout << " Test thread Running " << endl;
    }
};

int main(){
    PThreadsClass *thread = new TestThread;
    thread->setJoinable(true);
    thread->startThread();
    thread->join();
    thread->endThread();
    return 0;
}
