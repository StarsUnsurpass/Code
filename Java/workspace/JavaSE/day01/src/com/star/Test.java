package com.star;

import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int i1 = scan.nextInt();
        int i2 = scan.nextInt();
        int i3 = scan.nextInt();
        int i4 = scan.nextInt();
        int i5 = scan.nextInt();
    }
}

//class Point{
//    int x = 0;
//    int y = 0;
//
//    public double distace(){
//        x *= x;
//        y *= y;
//
//        double l = Math.sqrt(x + y);
//
//        return l;
//    }
//
//    public double distance(int x, int y){
//        int x1 = this.x - x;
//        int y1 = this.y - y;
//
//        x1 *= x1;
//        y1 *= y1;
//
//        double l = Math.sqrt(x1 + y1);
//
//        return l;
//    }
//
//    public double distance(Point other){
//        int x1 = x - other.x;
//        int y1 = y - other.y;
//
//        x1 *= x1;
//        y1 *= y1;
//
//        double l = Math.sqrt(x1 + y1);
//
//        return l;
//    }
//}