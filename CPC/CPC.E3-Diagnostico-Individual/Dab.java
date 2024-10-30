import java.util.Scanner;

public class D {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int len = sc.nextInt();
    sc.nextLine();
    String s = sc.nextLine();
    System.out.println(((s.indexOf("ab") != -1)||(s.indexOf("ba") != -1)) ? "Yes" : "No");

  }
}