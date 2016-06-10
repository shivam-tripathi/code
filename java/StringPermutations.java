// All permutations of a strings

import java.io.*;
import java.util.*;

class StringPermutations
{
    // Correct function
    public static void main(String[] args)throws IOException
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader obj=new BufferedReader(isr);
        String str = obj.readLine();
        int l = str.length();
        int lim = (int)Math.pow(2,l);
        System.out.println(lim);
        String[] subsequences = new String[lim];
        subsequences[0] = "";
        int index = 1;
        for(char c : str.toCharArray())
        {
            int temp = index;
            for(int i = 0; i < index; i++)
            {
                subsequences[temp++] = subsequences[i] + c;
            }
            index = temp;
        }
        for (int i = 1; i < lim; i ++)
        {
            if ((i & (i-1)) == 0)
                System.out.println();
            System.out.print(""+subsequences[i]+"  ");
        }
    }


    // Initial wrong pattern
    public static void wrongPattern(String str, int l)
    {
        str = ">" + str;
        for (int presentPos = 1; presentPos <= l; presentPos ++)
        {
            char c = str.charAt(presentPos);
            System.out.print(c+"\n");

            for (int i = 1; i < presentPos; i++)
            {
                for (int j = 1; j <= presentPos - i; j ++)
                {
                    for (int k = j+i-1; k >= j; k-- ){
                        c = str.charAt(presentPos-k);
                        System.out.print(c+" ");
                    }
                    System.out.print(str.charAt(presentPos) + " ");
                    System.out.print("\t");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}

/*
--------------------------------------------------------------------------------
First I made a mistake in generating the pattern. I started to print the pattern
1   2   3   4 ...
  12  23  34 ...
   123  234 ...
     1234 ...
Even in this I learnt some use of loops.
1 Separation of variables in analysing looping techniques.
2 When dealing with string based patterns, think in terms of indexes. Try to
  generate the pattern of indexes.
3 For any pattern to be analysed, it can have only three variables for proper
  pictorial representation. Start with innermost three loops, i.e. breaking the
  looping pattern into subloops. It will increase analysis efficiency, like
  below.

  j ------->
i
| Printed pattern depends on k.
| k is directly dependedant on values of i and k.
V

--------------------------------------------------------------------------------

It was later that I realised the every element if coupled with the permutations
of elements before it, gives the correct pattern. The major source of
inspiration was haskell's Data.List's subsequences function.
For example, lets take "hello".
h * [[]]
e * [[],h]
l * [[],[h],[e],[he]]
l * [[],[h],[e],[he],[l],[hl],[el],[hel]]
o ...

The increase is in geometric progression. We already know, total number of terms
would be:
(nC1)+(nC2)+(nC3)+....(nCn) = 2^n - 1

--------------------------------------------------------------------------------

Char to String:
    String stringValueOf = String.valueOf('c'); // Most efficient

    String characterToString = Character.toString('c');

    String characterObjectToString = new Character('c').toString();

    String concatBlankString = 'c' + "";

    String fromCharArray = new String(new char[]{x});

--------------------------------------------------------------------------------

Char array to String:
    String s = new String (<[char]>);
    String s = String.valueOf(<[char]>);
--------------------------------------------------------------------------------
How to check if a number is power of 2?
 The number be x. & bitwise operator calculates the binary AND of the two
 arguments.
 x & (x-1) == 0 means that the number is a power of two.
--------------------------------------------------------------------------------
*/
