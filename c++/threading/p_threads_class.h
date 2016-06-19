/*******************************************************************************
*                              p_threads_class.h                               *
*                       C++ wrapper over p_threads library                     *
*******************************************************************************/

#ifndef _P_THREADS_CLASS_H_
#define _P_THREADS_CLASS_H_

struct ThreadData;

class PThreadsClass{
public:
    PThreadsClass();
    virtual ~PThreadsClass();
private:
    PThreadsClass(const PThreadsClass &p); // Can't be copied, copy constructor is private
    PThreadsClass &operator=(const PThreadsClass &p); // Can't be copied, = operator is private
public:
    virtual void run() = 0;
    void startThread();
    void endThread();
    void setJoinable(bool yes);
    void join();
private:
    ThreadData *m_data;
    bool m_joinable;
};

#endif /* _P_THREADS_CLASS_H_ */
