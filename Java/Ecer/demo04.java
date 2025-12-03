import java.util.Scanner;
public class demo04{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
            int year = sc.nextInt();
            int month = sc.nextInt();
            int day = sc.nextInt();

            int days = 0;

            if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
                if(month == 1){

                days = day;

                }else if(month == 2){

                days = day + 31;

                }else if(month == 3){

                days = day + 60;

                }else if(month == 4){

                days = day + 91;

                }else if(month == 5){

                days = day + 121;
                
                }else if(month == 6){

                days = day + 152;
                
                }else if(month == 7){

                days = day + 182;
                
                }else if(month == 8){

                days = day + 213;
                
                }else if(month == 9){

                days = day + 244;
                
                }else if(month == 10){

                days = day + 274;
                
                }else if(month == 11){

                days = day + 305;
                
                }else if(month == 12){

                days = day + 335;
                
                }
            }else{
                if(month == 1){

                days = day;

                }else if(month == 2){

                days = day + 31;

                }else if(month == 3){

                days = day + 59;

                }else if(month == 4){

                days = day + 90;

                }else if(month == 5){

                days = day + 120;
                
                }else if(month == 6){

                days = day + 151;
                
                }else if(month == 7){

                days = day + 181;
                
                }else if(month == 8){

                days = day + 212;
                
                }else if(month == 9){

                days = day + 243;
                
                }else if(month == 10){

                days = day + 273;
                
                }else if(month == 11){

                days = day + 304;
                
                }else if(month == 12){

                days = day + 334;
                
                }
            }

            System.out.println(days);
        }
    
}