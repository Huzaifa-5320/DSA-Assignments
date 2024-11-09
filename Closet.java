import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Closet {
    private File file;


    public Closet() throws Exception {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the name of input file: ");
        String s = sc.next();
        this.file = new File(s+".txt");

    }

    List<String> bla_shelf = new ArrayList<>();
    List<String> blu_shelf = new ArrayList<>();
    List<String> g_shelf = new ArrayList<>();
    List<String> w_shelf = new ArrayList<>();

    // method to simply print array.
    public void printArray(String[] arr){

        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();

    }


    // counts the number of lines our input file have in order to initialize array of that length.
    public String[] count(File file)  throws Exception{

        if (!file.exists()) {
            throw new FileNotFoundException("File not found.");
        }

        Scanner sc = new Scanner(file);
        int count = 1;

        while(sc.hasNextLine()){
            sc.nextLine();
            count++;
        }
        sc.close();
        String[] arr = new String[count-1];

        return arr;

    }

    // once the array is initialized we start adding data to our arrray line by line.
    public String[] populateArray(String[] arr,File file) throws FileNotFoundException {

        if (!file.exists()) {
            throw new FileNotFoundException("File not found.");
        }

        Scanner input = new Scanner(file);
        for (int i=0;i<arr.length;i++){
            arr[i]=input.nextLine();
        }
        return arr;

    }



    // once the array is initialized we then sort our array on the basis of color.
    public void sortArray(String[] arr){

        // Assuming the input file has only black,blue,green and white colors respectively
        for(String e:arr){
            if (e.charAt(2)=='a'){
                bla_shelf.add(e);
            }else if (e.charAt(2) == 'u') {
                blu_shelf.add(e);
            }else if(e.charAt(0) == 'G' || e.charAt(0) == 'g'){
                g_shelf.add(e);
            }else if(e.charAt(0) == 'W' || e.charAt(0) == 'w'){
                w_shelf.add(e);
            }
        }

    }

    public File writeData() throws Exception {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the name of the file in which you want output: ");
        String s = sc.next();
        File obj = new File(s+".txt");

        if (obj.exists()){
            System.out.println("File already exists");
            System.exit(1);
        }
        PrintWriter output = new PrintWriter(obj);
        output.println("Shelf 1: ");
        for (String e : bla_shelf) {
            output.println(e);
        }
        output.println();
        output.println("Shelf 2: ");
        for (String e : blu_shelf){
            output.println(e);
        }
        output.println();
        output.println("Shelf 3:");
        for (String e : g_shelf){
            output.println(e);
        }
        output.println();
        output.println("Shelf 4:");
        for (String e : w_shelf){
            output.println(e);
        }
        output.println();
        output.close();
        return obj;

    }


    public static void main(String[] args) throws Exception {

        Closet c = new Closet();
        String[] elements = c.count(c.file);
        c.populateArray(elements,c.file);
        c.sortArray(elements);
        c.writeData();

    }
}