/*
Understanding multithreading in java.
    A multithreaded program contains two or more parts that can concurrently and
each part can handle different task at the same time, making optimal use of
available resources, especially when the system has multiple cpu s.
    Multithreading is when multiple processes share common processing resources
like cpu. Multithreading extends the idea of multi tasking into single
application where one can decide the division of specific operations in a single
application into multiple individual threads.

Life cycle of a thread :
New <runnable : start()>
    Runnable {<waiting : await, lock> <time-waiting : await, sleep>
    < terminated : thread completes>}
        Waiting < unlock, signal, signalAll>
        Time-waiting <interval expires>
        Terminated

New :
    A new thread begins it's life in new state. It remains in this state until
    the program starts the thread.
Runnable :
    After a newly born thread is started, the thread becomes runnable. A thread
    in this state is said to be executing it's task.
Waiting :
    Sometimes a thread transitions to waiting state as it has to wait for result
    from another thread. It transitions back to running state only when the
    other thread signals the waiting thread to continue executing.
Time-waiting :
    A thread can go to waiting state for a specified interval of time, and it
    transitions back to original state when the specified time interval expires
    or when some even it is waiting for occurs.
Terminated :
    When a thread completes it's task or otherwise is terminated, it ends
    execution, and is said to be terminated.

Thread Priority :
    Every thread has priority which tells the operating system in which order to
    run them. These range from MIN_PRIORITY = 1 to MAX_PRIORITY = 10. By default
    all the properties have NORM_PRIORITY = 5.
    Threads with higher priority time are those which are more important to the
    to the program and should be alloted processor time before others. However
    these priorities cannot guarantee order of execution of threads.
*/


/*
There are 2 methods to create threads in java:
1. Using Runnable interface.
2. By extending Thread class.


Using Runnable interface:
1. Implement run() function provided by runnable interface. This provides entry
point of the thread. It contains the complete logic inside this.
public void run()

2. Instantiate the Thread object using object that imlements Runnable interface
and String thread name.
Thread (Runnable theadObj, String objectName)

3. After the creation of thread, call it using start method, which executes a
call to the run() method.
start()

*/
import java.io.*;
class RunnableThreads implements Runnable
{
    // Data member is threadName.
    private Thread t;
    private String threadName;

    // Initialise the threadName, and prints the name.
    RunnableThreads( String name)
    {
        threadName = name;
        System.out.println("Creating "+ threadName);
    }

    // Implementing run()
    public void run()
    {
        System.out.println("Running thread : "+ threadName);
        try
        {
            for(int i = 4; i > 0; i--)
            {
                System.out.println("Thread : " + threadName + ", " + i);
                // Using sleep method of Thread
                Thread.sleep(50);
            }
        }
        catch (InterruptedException e)
        {
            System.out.println("Thread " + threadName + " interrupted.");
        }
        System.out.println("Thread "+ threadName +" exiting.");
    }

    // Instantiate the Thread object, using the object that called this
    // function and the threadName, the data member of this class.
    public void start()
    {
        System.out.println("Starting thread : " + threadName);
        if (t == null)
        {
            t = new Thread(this, threadName);
            t.start();
        }
    // start() method of Thread class will call run implemented in this class.
    }
}

class Threads
{
    public static void main(String[] args)
    {
        RunnableThreads t1 = new RunnableThreads("Thread-1");
        t1.start();
        RunnableThreads t2 = new RunnableThreads("Thread-2");
        t2.start();
    }
}
