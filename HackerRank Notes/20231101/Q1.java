/*
In a class, the teacher while teaching word formation to students thaught of an activity where two participants are choosen from the class. Participant 1 is asked to speak any english word, the participant 2 is again asked the same. After 2 words are choosen, it is checked by the class whether the starting 3 characters of word match the ending three characters in reverse order. WRITE A PROGRAM code for the teacher to perform the activity and return the appropriate message.

Input Format

Line 1 of input takes a String spoken by participant 1 of the game. Line 2 of input takes a String spoken by participant 2 of the game.

Constraints

The words choosen by the participants should be of minimum 3 length, otherwise display "ERROR".

Output Format

The mismatch should display "TRY NEXT TIME" and the match should display "GREAT"

Sample Input 0

HI<br>
IH
Sample Output 0

ERROR
Sample Input 1

HELLO<br>
TABBOULEH
Sample Output 1

GREAT
*/

import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading the words spoken by the participants
        String word1 = scanner.nextLine().toUpperCase();
        String word2 = scanner.nextLine().toUpperCase();

        // Closing the scanner to avoid memory leaks
        scanner.close();

        // Checking if the words have a minimum length of 3
        if(word1.length() < 3 || word2.length() < 3) {
            System.out.println("ERROR");
            return;
        }

        // Extracting the first 3 characters of word1 and the last 3 characters of word2
        String part1 = word1.substring(0, 3);
        String part2 = new StringBuilder(word2.substring(word2.length() - 3)).reverse().toString();

        // Comparing the extracted parts and printing the result
        if(part1.equals(part2)) {
            System.out.println("GREAT");
        } else {
            System.out.println("TRY NEXT TIME");
        }
    }
}
