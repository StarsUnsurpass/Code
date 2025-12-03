import java.util.Scanner;
public class array03{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        int num = scan.nextInt();
        String[] name = new String[50];
        int[] score = new int[50];

        for(int i = 0; i < num; i ++){
            name[i] = scan.nextLine();
            score[i] = scan.nextInt();
        }

        int temp = 0;
        String tem;

        for(int i = 0; i < num; i ++){
            for(int j = 0; j < i; j ++){
                if(score[i] < score[i + 1]){
                    temp = score[i + 1];
                    score[i + 1] = score[i];
                    score[i] = temp;

                    tem = name[i + 1];
                    name[i + 1] = name[i];
                    name[i] = tem;
                }
            }
        }

        for(int i = 0; i < num; i ++){
            System.out.println(name[i] + score[i]);
        }

    }
}