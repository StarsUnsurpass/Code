import java.util.Scanner;

public class Test{
    public static void main(String[] args){
        long number = 0;
        Scanner input = new Scanner(System.in);
        
        System.out.println("Please input a number(lager than 1): ");
        number = input.nextLong();

        long startTime = System.currentTimeMillis();
        long result = fabonacci(number);
        long endTime = System.currentTimeMillis();

        System.out.println("The result is: " + result);
        
        long duration = endTime - startTime;
        System.out.println("time spending of the function: " + duration + " ms");

        input.close();
    }

    public static long fabonacci(long number){
        if(number < 1){
            System.out.println("Please input the corrent number!");
            return 0;
        }
        else if(number < 3){
            return 1;
        }
        else{
            return fabonacci(number - 1) + fabonacci(number - 2);
        }
    }
}