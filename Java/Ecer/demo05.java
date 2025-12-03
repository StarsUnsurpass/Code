import java.util.Scanner;
public class demo05{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        char operater = sc.next().charAt(0);
        double num1 = sc.nextDouble();
        double num2 = sc.nextDouble();

        double out_num = 0;

        if(operater == '+'){
            out_num = num1 + num2;
            System.out.println(num1 + '+' + num2 + '=' + out_num);
        }else if(operater == '-'){
            out_num = num1 - num2;
            System.out.println(num1 + '-' + num2 + '=' + out_num);
        }else if(operater == '*'){
            out_num = num1 * num2;
            System.out.println(num1 + '-' + num2 + '=' + out_num);
        }else if(operater == '/'){
            out_num = num1 / num2;
            System.out.println(num1 + '-' + num2 + '=' + out_num);
        }else{
            System.out.println("error");
        }
    }
}