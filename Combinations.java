import java.util.Scanner;

public class Combinations {
    public static void combinations(int currentBox, String n, int selectedItems, int totalItems, String asf) {
        if (currentBox > n.length()) {
            if (selectedItems == totalItems) {
                System.out.println(asf);;
            }
            return;
        }
        // Choose the current character as part of the combination
        combinations(currentBox + 1, n, selectedItems + 1, totalItems, asf + n.charAt(currentBox - 1));
        
        // Do not choose the current character
        combinations(currentBox + 1, n, selectedItems, totalItems, asf);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String n = sc.next();

        System.out.println("Enter the number of items to select: ");
        int ritems = sc.nextInt();

        combinations(1, n, 0, ritems, "");
        sc.close();
    }
}