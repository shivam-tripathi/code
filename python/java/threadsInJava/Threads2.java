/*
Use of threads extending the Thread class.
Create a new class the extends the Thread class. Using the available methods in
the Thread class, handling of the threads becomes more flexible.

1. Override the run() method in the Thread class. As while implementing the
Runnable class, here also the run() method acts as the entry point of the thread
and contains all the logic which is to be implementing.

2. Run the start() method.

*/

class ThreadExtending extends Thread
{
    private Thread t;
    private String threadName;

    ThreadExtending(String name)
    {
        threadName = name;
        System.out.println("Creating a thread :" + threadName);
    }

    public void run()
    {
        System.out.println(" Running thread :" + threadName);
        try
        {
            for(int i = 20; i >= 0; i--)
            {
                System.out.println("Thread : "+ threadName + ", " + i);
                Thread.sleep(50);
            }
        }
        catch (InterruptedException e)
        {
            System.out.println("Thread " + threadName + " interrupted.");
        }
        System.out.println("Thread " + threadName + " terminated.");
    }

    public void start()
    {
        System.out.println("Starting thread " + threadName);
        if (t == null)
        {
            t = new Thread(this, threadName);
            t.start();
        }
    }
}

class Threads2
{
    public static void main(String[] args)
    {
        ThreadExtending t1 = new ThreadExtending("T1");
        t1.start();
        ThreadExtending t2 = new ThreadExtending("T2");
        t2.start();
        ThreadExtending t3 = new ThreadExtending("T3");
        t3.start();
    }
}

/*
Important methods in the Thread class :

1. public void start()
    Start the thread in separate path of execution, then invoke the run() method
    in this Thread object.
2. public void run()
    If this Thread object was instantiated using a separate Runnable target, the
    run() method is invoked on that Runnable object.
3. public final void setName(String name)
    Changes the name of the Thread object. There is also a getName() method for
    retrieving the name.

4. public final void setPriority(int priority)
    Sets the priority of this Thread object. The possible values are between 1
    and 10.

5. public final void setDaemon(boolean on)
    A parameter of true denotes this Thread as a daemon thread.

6. public final void join(long millisec)
    The current thread invokes this method on a second thread, causing the
    current thread to block until the second thread terminates or the specified
    number of milliseconds passes.

7. public void interrupt()
    Interrupts this thread, causing it to continue execution if it was blocked
    for any reason.

8. public final boolean isAlive()
    Returns true if the thread is alive, which is any time after the thread has
    been started but before it runs to completion.


The previous methods are invoked on a particular Thread object.
The following methods in the Thread class are static. Invoking one of the static
methods performs the operation on the currently running thread.

1. public static void yield()
    Causes the currently running thread to yield to any other threads of the
    same priority that are waiting to be scheduled.

2. public static void sleep(long millisec)
    Causes the currently running thread to block for at least the specified
    number of milliseconds.

3. public static boolean holdsLock(Object x)
    Returns true if the current thread holds the lock on the given Object.

4. public static Thread currentThread()
    Returns a reference to the currently running thread, which is the thread
    that invokes this method.

5. public static void dumpStack()
    Prints the stack trace for the currently running thread, which is useful
    when debugging a multithreaded application.


// File Name : DisplayMessage.java
// Create a thread to implement Runnable
public class DisplayMessage implements Runnable
{
   private String message;
   public DisplayMessage(String message)
   {
      this.message = message;
   }
   public void run()
   {
      while(true)
      {
         System.out.println(message);
      }
   }
}

// File Name : GuessANumber.java
// Create a thread to extentd Thread
public class GuessANumber extends Thread
{
   private int number;
   public GuessANumber(int number)
   {
      this.number = number;
   }
   public void run()
   {
      int counter = 0;
      int guess = 0;
      do
      {
          guess = (int) (Math.random() * 100 + 1);
          System.out.println(this.getName()
                       + " guesses " + guess);
          counter++;
      }while(guess != number);
      System.out.println("** Correct! " + this.getName()
                       + " in " + counter + " guesses.**");
   }
}

// File Name : ThreadClassDemo.java
public class ThreadClassDemo
{
   public static void main(String [] args)
   {
      Runnable hello = new DisplayMessage("Hello");
      Thread thread1 = new Thread(hello);
      thread1.setDaemon(true);
      thread1.setName("hello");
      System.out.println("Starting hello thread...");
      thread1.start();

      Runnable bye = new DisplayMessage("Goodbye");
      Thread thread2 = new Thread(bye);
      thread2.setPriority(Thread.MIN_PRIORITY);
      thread2.setDaemon(true);
      System.out.println("Starting goodbye thread...");
      thread2.start();

      System.out.println("Starting thread3...");
      Thread thread3 = new GuessANumber(27);
      thread3.start();
      try
      {
         thread3.join();
      }catch(InterruptedException e)
      {
         System.out.println("Thread interrupted.");
      }
      System.out.println("Starting thread4...");
      Thread thread4 = new GuessANumber(75);

      thread4.start();
      System.out.println("main() is ending...");
   }
}

Output :
Starting hello thread...
Starting goodbye thread...
Hello
Hello
Hello
Hello
Hello
Hello
Goodbye
Goodbye
Goodbye
Goodbye
Goodbye
.......

Other topics on same concept :
    http://www.tutorialspoint.com/java/java_thread_synchronization.htm
    http://www.tutorialspoint.com/java/java_thread_communication.htm
    http://www.tutorialspoint.com/java/java_thread_deadlock.htm
    http://www.tutorialspoint.com/java/java_thread_control.htm

Other topics on interest :
    http://www.tutorialspoint.com/java/java_applet_basics.htm
    http://www.tutorialspoint.com/java/java_sending_email.htm
    http://www.tutorialspoint.com/java/java_networking.htm
    http://www.tutorialspoint.com/java/java_serialization.htm
    http://www.tutorialspoint.com/java/java_generics.htm
    http://www.tutorialspoint.com/java/java_collections.htm
    http://www.tutorialspoint.com/java/java_data_structures.htm
    http://www.tutorialspoint.com/java/java_documentation.htm
*/
