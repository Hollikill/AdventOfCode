import java.util.*;
import java.io.*;

public class Day_2_1 {
    
    /** 
     * @param args
     */
    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(new File("Data_2.txt"));
            scan.useDelimiter(",");

            ArrayList<Integer> intCode = new ArrayList<Integer>();

            while (scan.hasNext()) {
                
                int x = scan.nextInt();

                intCode.add(x);
            }

            scan.close();

            boolean codeRunning = true;
            int readerPos = 0;

            while (codeRunning) {
                int type = intCode.get(readerPos);

                if (type == 99) {
                    codeRunning = false;
                }
                else if (type == 1) {
                    intCode.set(intCode.get(readerPos + 3), (intCode.get(intCode.get(readerPos + 1)) + intCode.get(intCode.get(readerPos + 2))));
                    readerPos += 4;
                }
                else if (type == 2) {
                    intCode.set(intCode.get(readerPos + 3), (intCode.get(intCode.get(readerPos + 1)) * intCode.get(intCode.get(readerPos + 2))));
                    readerPos += 4;
                }
                else {
                    System.out.println("/// Error ///");
                }
            }

            for (int x = intCode.size() - 1; x > -1; x--) {
                System.out.println("Pos " + x + ": " + intCode.get(x));
            }
        }
        catch (Exception e) {
            System.out.println("Code Exception " + e);
        }
    }
}