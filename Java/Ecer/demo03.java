import java.util.Scanner;
public class demo03{
    public static void main(String[] args){

        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();

        int num_a = number % 10;
        number /= 10;

        int num_b = number % 10;
        number /= 10;

        int num_c = number % 10;
        number /= 10;

        int num_d = number % 10;
        number /= 10;

        int num1 = (num_a + 5) % 10;

        int num2 = (num_b + 5) % 10;

        int num3 = (num_c + 5) % 10;

        int num4 = (num_d + 5) % 10;

        int Num = num1 * 1000 + num2 * 100 + num3 * 10 + num4;

        System.out.println(Num);
    }
}