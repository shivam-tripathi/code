/*
 * Using Java, one can write methods or classes or interfaces that can take more
 * than one data type as arguments.
 * Generics provide compile time safety against invalid data types.

 * Generic Methods :
 * All generic method declarations have a type parameter section delimited
 * by angle brackets (<>) the precedes method's return type like <E>.
 * Each type parameter contains one or more type parameters separated by commas.
 * A type parameter, also called type variable, is an identifier that specified a
 * generic type name.
 * The type parameters can be used to declare return type and act as placeholders
 * for the types of arguments passed to the generic method (actual parameters).
 * Type parameters can only represent only the reference data types and not the
 * primitive types like int, char, float etc.
 *
 */

/*
 * Bounded type parameters
 * To restrict the type of parameters to specific typeclass, bounded type
 * parameters are used.
 * This is done by using extends keyword after the generic name like
 * <T extends Comparable <T>>
 *
 */

/*
 * Generic classes
 * Class name is followed by a type parameter section. These are called
 * parametrized classes.
 */

import java.io.*;
public class GenericJava
{
    // <stuff> precedes the return type of the method
    public static <E> void printArray(E[] inputArray)
    {
        for(E element : inputArray){
            System.out.printf("%s",element); // C like.
        }
        System.out.println();
    }

    public static <T extends Comparable <T>> T maximum (T x, T y, T z)
    {
        T max = x;
        if (y.compareTo(max) > 0)
                max = y;
        if (z.compareTo(max) > 0)
            max =  z;
        return max;
    }

    public static void main(String[] args)throws IOException
    {
        Integer[] intArray = {1,2,3,4,5,6,7};
        Character[] charArray = {'a','c','f','h','s'};
        Double[] doubleArray = {1.2, 3.2, 4.3, 5.4, 6.5};

        System.out.println("intArray :");
        printArray(intArray);
        System.out.println("charArray :");
        printArray(charArray);
        System.out.println("doubleArray :");
        printArray(doubleArray);

        System.out.println('a' > 's');
        System.out.println(maximum(2,3,4));
        System.out.println(maximum('a','v','g'));

        GenericBox<Integer> integerBox = new GenericBox<Integer>();
        GenericBox<String> stringBox = new GenericBox<String>();
        integerBox.add(new Integer(10101));
        stringBox.add(new String("Hello!"));
        System.out.println(integerBox.get());
        System.out.println(stringBox.get());
    }
}


class GenericBox <T>
{
    private T t;

    public void add(T t){
        this.t = t;
    }

    public T get(){
        return t;
    }

}
