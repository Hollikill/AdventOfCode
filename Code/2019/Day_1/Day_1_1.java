import java.util.*;
import java.io.*;

public class Day_1_1 {
    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(new File("data_1.txt"));

            int i = 0;

            while (scan.hasNext()) {
                Scanner line = new Scanner(scan.nextLine());

                int x = line.nextInt();

                double y =  x / 3;

                y -= 2;

                i += y;
            }

            System.out.println("" + i);
        }
        catch (Exception e) {

        }
    }
}