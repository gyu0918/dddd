package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;

public class Main {
    private static int length;
    private static char[][] strArr;

    private static int count;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        length = sc.nextInt();
        strArr = new char[8][8];
        for(int i = 0; i < strArr.length; i++){
            String str = sc.next();
            for (int j = 0; j < strArr[i].length; j++){
                strArr[i][j] = str.charAt(j);
            }
        }
    }
}