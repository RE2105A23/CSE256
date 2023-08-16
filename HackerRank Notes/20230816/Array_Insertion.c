//
// Created by SRI VISHNU JSB on 8/16/2023.
//
/*
 * A task is assigned to some surveyors to store temparature in an array daily for 8 days.

An array for storing temperature is used by the surveyor but they forget to insert one element at some positions. Index 0 1 2 3 4 5 6 7 Temp. 30 40 35 25 20 10 23

If they insert 15 at index 4 then the array looks like:

Index 0 1 2 3 4 5 6 7
Temparature 30 40 35 25 15 20 10 23

So, you decided to create a function to insert the temperature at any given position in an array so, that if insertion is required then they can insert it.

Input Format

You have to take three line inputs where
first line contains an array of temperature separated by space
second line input contains the position index where we want to insert element(where index position starts from 0)
Third line input contains the element you want to insert.

Constraints

Temparature values must be an integer values. Capacity of an array to store is according to 8 days temparature data only.

Output Format

Prints all the temperatures given in an array after inserting the temparature at given index position. Output is comma separated values where there is no comma after last element. If the position given is not in the array index range then display an error message "Invalid Position".
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void insertTemperature(int array[], int *size, int position, int temperature) {

    if (position < 0 || position > *size) {
        printf("Invalid Position\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        array[i] = array[i - 1];
    }

    array[position] = temperature;
    (*size)++;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int temperatures[8];
    int size = 0;

    // Input temperatures separated by space
    for (int i = 0; i < 7; i++) {
        scanf("%d", &temperatures[i]);
        size++;
    }

    int position, temperature;

    // Input position index
    scanf("%d", &position);

    // Input element to insert
    scanf("%d", &temperature);

    insertTemperature(temperatures, &size, position, temperature);

    // Print the updated temperatures with comma separation
    if (position >= 0 && position < size) {
        for (int i = 0; i < size; i++) {
            printf("%d", temperatures[i]);
            if (i != size - 1) {
                printf(",");
            }
        }
    }

    return 0;
}
