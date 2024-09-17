
/**
 * ReadDouble CP4 1.3.4.1
 */
import java.util.Scanner;

public class ReadDouble {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String[] num = ("       " + sc.nextLine() + "   ")
        .split("\\.");
    String integer = num[0].substring(num[0].length() - 7);
    String decim = num[1].substring(0, 3);
    System.out.println(integer + "." + decim);
  }
}