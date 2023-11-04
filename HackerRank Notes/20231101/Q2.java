/*
Write a program to check whether two strings are ANAGRAM or not. Strings will be anagram if they have same set of characters same number of times. Your program should take the input of two strings of length greater than 2. If the length of the any string is less than equal 2 then display the message “Invalid Input” without taking any more input

Input Format

Your program should take the input of two strings.

Constraints

Length of strings should be greater than 2.

Output Format

Your program should display the “ANAGRAM” or “NOT ANAGRAM” depending on the input strings.

Sample Input 0

silent
listen
Sample Output 0

ANAGRAM
Sample Input 1

ssilent
listenn
Sample Output 1

NOT ANAGRAM
*/

import java.util.Arrays;
import java.util.Scanner;

public class AnagramChecker {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading the input strings
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();

        // Closing the scanner to avoid memory leaks
        scanner.close();

        // Checking if the length of the strings is greater than 2
        if(str1.length() <= 2 || str2.length() <= 2) {
            System.out.println("Invalid Input");
            return;
        }

        // Converting the strings to character arrays
        char[] charArray1 = str1.toCharArray();
        char[] charArray2 = str2.toCharArray();

        // Sorting the character arrays
        Arrays.sort(charArray1);
        Arrays.sort(charArray2);

        // Comparing the sorted character arrays
        if(Arrays.equals(charArray1, charArray2)) {
            System.out.println("ANAGRAM");
        } else {
            System.out.println("NOT ANAGRAM");
        }
    }
}
