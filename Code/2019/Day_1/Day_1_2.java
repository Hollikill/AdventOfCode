import java.util.*;
import java.io.*;

public class Day_1_2 {
    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(new File("data_1.txt"));

            int fuel = 0;
            int tempFuel = 0;
            int tempTempFuel = 0;

            while (scan.hasNext()) {
                Scanner line = new Scanner(scan.nextLine());

                int x = line.nextInt();

                int y = getFuel(x);

                tempFuel = y;
                tempTempFuel = y;

                while (getFuel(tempTempFuel) > 0) {
                    int z = getFuel(tempTempFuel);

                    tempTempFuel = z;

                    tempFuel += tempTempFuel;
                }

                fuel += tempFuel;
            }

            /*while (getFuel(tempFuel) > 0) {
                int x = getFuel(tempFuel);

                tempFuel = x;

                fuel += tempFuel;
            }*/

            System.out.println("fuel: " + fuel);
        }
        catch (Exception e) {

        }
    }

    public static int getFuel(int mass) {
        double massDouble = mass;

        massDouble = ((int)(massDouble / 3)) - 2;

        int fuel = (int) massDouble;

        return fuel;
    }
}