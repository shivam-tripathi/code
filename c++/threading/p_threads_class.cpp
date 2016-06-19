/*******************************************************************************
*                            p_threads_class.cpp                               *
*                       C++ wrapper over p_threads library                     *
*******************************************************************************/

//#define nullptr NULL
#include "p_threads_class.h"
#include <pthread.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ThreadData{
    pthread_t m_thread;
    pthread_attr_t m_attr;
};

namespace{
    void *thread_function(void* data) {
        PThreadsClass *thread = static_cast<PThreadsClass*>(data);
        thread->run();
        return nullptr;
    }
}

PThreadsClass::PThreadsClass() : m_data(new ThreadData), m_joinable(false){
    pthread_attr_init(&m_data->m_attr);
}

PThreadsClass::~PThreadsClass(){
    if(m_data){
        delete m_data;
    }
}

void PThreadsClass::startThread() {
    // arguments : &pthread_t, &pthread_attr_t, worker_function, arguments
    pthread_create(&m_data->m_thread, &m_data->m_attr, thread_function, this);
}

void PThreadsClass::endThread(){
    pthread_exit(nullptr);
}

void PThreadsClass::setJoinable(bool set){
    pthread_attr_setdetachstate(&m_data->m_attr, set ? PTHREAD_CREATE_JOINABLE : PTHREAD_CREATE_DETACHED);
    m_joinable = set;
}

void PThreadsClass::run(){
    cout << "Nothing to run" << endl;
}

void PThreadsClass::join(){
    if(!m_joinable){
        cout << "Cannot be joined" << endl;
    }
    else{
        void *result;
        pthread_join(m_data->m_thread, &result);
    }
};
