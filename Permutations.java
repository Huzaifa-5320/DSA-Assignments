import java.util.Scanner;

public class Permutations {

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        printPermutations(s,"");
        sc.close();
    }


    public static void printPermutations(String ques,String asf)
    {
        if(ques.length()==0)
        {
            System.out.println(asf);
            return;
        }
        for(int i=0;i<ques.length();i++)
        {
            char ch = ques.charAt(i);
            String qlpart = ques.substring(0, i);
            String qrpart = ques.substring(i+1);
            String roq = qlpart + qrpart;
            printPermutations(roq, asf+ch);
        }
    }
}
