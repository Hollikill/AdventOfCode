import java.util.*;
import java.io.File;
 
public class ProgramAlarm {
 
    public static void main(String[] args) throws Exception {
        File file = new File("Data_2.txt"); // changed read file -Hollister
        Scanner sc = new Scanner(file);
        String data = "";
 
 
        // Copy data from text file to single string
        while (sc.hasNext()) {
            data += sc.next();
        }

        // added close -Hollister
        sc.close();
 
        //Split string into String array
        String[] codesString = data.split(",");
        int[] codes = new int[codesString.length];
 
        //Convert string array to int array
        for (int i = 0, n = codesString.length; i < n; i++) {
            codes[i] = Integer.parseInt(codesString[i]);
        }
 
       
        // get code, perform aritmetic
        for (int i = 0, n = codes.length - 4; i < n; i += 4) {
            int opcode = codes[i];
            int pos1 = codes[i+1];
            int pos2 = codes[i+2];
            int dest = codes[i+3];
            if (opcode == 99) {
                break;
            } else if (opcode == 1) {
                codes[dest] = codes[pos1] + codes[pos2];
            } else if (opcode == 2) {
                codes[dest] = codes[pos1] * codes[pos2];
            }
        }
 
        System.out.println(codes[0]);
 
    }
}