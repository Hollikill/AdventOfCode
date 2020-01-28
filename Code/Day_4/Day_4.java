import java.util.*;
import java.io.*;

public class Day_4 {
    public static void main (String[] args) {
        try {
			Scanner file = new Scanner(new File("Data_4.txt"));
            file.useDelimiter("-");

            int low = file.nextInt();
            int high = file.nextInt();

            file.close();

            int possibleNums = 0;
            int possibleNums2 = 0;

            for (int i = low; i < high + 1; i++) {
                String num = "" + i;

                boolean property1 = false;

                boolean property2 = false;
                boolean property2_2 = false;
                boolean wasRepOf2 = false;
                boolean notInRep = true;

                boolean property3 = true;

                if (num.length() == 6) {
                    property1 = true;
                }
                
                char prevChar = ' ';
                for (int a = 0; a < num.length(); a++) {
                    if (num.charAt(a) == prevChar) {
                        property2 = true;
                        if (!wasRepOf2) {
                            if (notInRep) {
                                wasRepOf2 = true;
                            }
                        }
                        else {
                            wasRepOf2 = false;
                            notInRep = false;
                        }
                    }
                    else {
                        notInRep = true;
                        if (wasRepOf2) {
                            property2_2 = true;
                            wasRepOf2 = false;
                        }
                    }
                    prevChar = num.charAt(a);
                }
                if (wasRepOf2) {
                    property2_2 = true;
                }

                int prevNum = -1;
                for (int a = 0; a < num.length(); a++) {
                    if (!(Integer.parseInt(num.substring(a, a+1)) == prevNum) && !(Integer.parseInt(num.substring(a, a+1)) > prevNum)) {
                        property3 = false;
                    }
                    prevNum = Integer.parseInt(num.substring(a, a+1));
                }

                if (property1 && property2 && property3) {
                    possibleNums++;
                }
                if (property1 && property2_2 && property3) {
                    possibleNums2++;
                }
            }

            System.out.println("Possible Passwords: " + possibleNums);
            System.out.println("Possible Passwords (consistent w/ part 2): " + possibleNums2);
        }
        catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}