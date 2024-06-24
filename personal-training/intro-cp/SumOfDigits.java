import java.util.Scanner;
public class SumOfDigits{
  public static int count = 0;
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String num = sc.nextLine();
    sumOfDigitsUntil1(num);
    System.out.println(count);
  }
  public static void sumOfDigitsUntil1(String num){
    if(num.length() == 1){
      return;
    }
    int sum = 0;
    for(int i = 0; i < num.length(); i++){
      sum += Integer.parseInt(num.charAt(i) + "");
    }
    count++;
    sumOfDigitsUntil1(sum + "");
  }
}