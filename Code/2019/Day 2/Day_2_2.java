import java.util.*;
import java.io.*;

public class Day_2_2 {
    
    /** 
     * @param args
     */
    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(new File("Data_2.txt"));
            scan.useDelimiter(",");

            ArrayList<Integer> intCodeOg = new ArrayList<Integer>();

            while (scan.hasNext()) {
                
                int x = scan.nextInt();

                intCodeOg.add(x);
            }

            scan.close();

            boolean findingParams = true;
            int param1 = 0;
            int param2 = 0;
            //ArrayList<Integer> param1L = new ArrayList<Integer>();
            //ArrayList<Integer> param2L = new ArrayList<Integer>();

            int timesRan = 0;

            while  (findingParams) {
                System.out.println("Run: " + (timesRan + 1));
                
                ArrayList<Integer> intCode = copy(intCodeOg);

                param1 = (int)(Math.random()*101);
                param2 = (int)(Math.random()*101);

                intCode.set(1, param1);
                intCode.set(2, param2);

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

                if (intCode.get(0) == 19690720) {
                    findingParams = false;
                }

                timesRan += 1;
            }

            System.out.println((100 * param1 + param2));
        }
        catch (Exception e) {
            System.out.println("Code Exception " + e);
        }
    }

    public static ArrayList<Integer> copy(ArrayList<Integer> ar) {
        ArrayList<Integer> i = new ArrayList<Integer>();

        for (Integer x : ar) {
            i.add(x);
        }

        return i;
    }

    /*
    public static boolean has(ArrayList<Integer> ar, int value) {
        boolean bool = false;

        for (int x : ar) {
            if (x == value) {
                bool = true;
            }
        }

        return bool;
    }
    */
}