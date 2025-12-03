import java.util.Scanner;

public class Test01{
    public static void main(String[] args){
        long number = 0;
        Scanner input = new Scanner(System.in);

        System.out.println("Please input your number(larger than 0):");
        number = input.nextLong();

        long number1 = 0;
        long number2 = 1;
        long result = 0;

        long startTime = System.currentTimeMillis();
        for(int i = 0; i < number; i++){
            result = number1 + number2;
            number1 = number2;
            number2 = result;
        }
        long endTime = System.currentTimeMillis();

        System.out.println("The result is " + result);

        long duration = endTime - startTime;
        System.out.println("time spending of the function: " + duration + " ms");

        input.close();
    }
}