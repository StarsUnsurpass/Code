import java.util.Scanner;

public class Test03 {
    
    /**
     * 尾递归求解斐波那契数列
     * @param n 要计算的斐波那契数位置
     * @return 第n个斐波那契数
     */
    public static long fibonacci(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("输入必须大于等于0");
        }
        // 调用尾递归辅助函数
        return fibonacciTailRec(n, 0, 1);
    }
    
    /**
     * 尾递归辅助函数
     * @param n 剩余递归次数
     * @param a F(k-2) 的值
     * @param b F(k-1) 的值
     * @return 斐波那契数结果
     */
    private static long fibonacciTailRec(int n, long a, long b) {
        // 基础情况
        if (n == 0) {
            return a;  // 返回 F(0)
        }
        if (n == 1) {
            return b;  // 返回 F(1)
        }
        
        // 尾递归调用：所有计算都在参数中完成
        // n-1: 减少递归深度
        // b: 原来的 F(n-1) 变成新的 F(n-2)
        // a+b: 计算新的 F(n-1)
        return fibonacciTailRec(n - 1, b, a + b);
    }
    
    public static void main(String[] args) {
        int number = 0;
        long result = 0;

        System.out.println("Please input your number:");
        Scanner input = new Scanner(System.in);
        number = input.nextInt();

        long startTime = System.currentTimeMillis();
        result = fibonacci(number);
        long endTime = System.currentTimeMillis();

        System.out.println("The result is: " + result);
        
        long duration = endTime - startTime;
        System.out.println("time spending of the function: " + duration + " ms");

        input.close();
    }
}