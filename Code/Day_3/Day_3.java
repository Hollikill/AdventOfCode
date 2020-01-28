import java.util.*;
import java.io.*;

public class Day_3 {
    public static void main (String[] args) {
		System.out.println("Day 3 parts 1 and 2 started");
        try {
			Scanner file = new Scanner(new File("Data_3.txt"));
			System.out.println("File Loaded");

            ArrayList<int[]> wire1 = new ArrayList<int[]>();
			ArrayList<int[]> wire2 = new ArrayList<int[]>();

			for (int i = 0; i < 2; i++) {
				int[] lastPoint = new int[2];
				lastPoint[0] = 0;
				lastPoint[1] = 0;
				
				Scanner line = new Scanner(file.nextLine());
				
				line.useDelimiter(",");
				
				while (line.hasNext()) {
					int dirX = 0;
					int dirY = 0;
					int distance = 0;
					String word = line.next();
					
					String dirString = word.substring(0,1);
					switch (dirString) {
						case "U" : {
							dirX = 0;
							dirY = 1;
							break;
						}
						case "R" : {
							dirX = 1;
							dirY = 0;
							break;
						}
						case "D" : {
							dirX = 0;
							dirY = -1;
							break;
						}
						case "L" : {
							dirX = -1;
							dirY = 0;
							break;
						}
					}
					
					Scanner numScan = new Scanner(word.substring(1));
					distance = numScan.nextInt();
					numScan.close();
					
					for (int a = 0; a < distance; a++) {
						int[] pos = new int[2];
						
						pos[0] = lastPoint[0];
						pos[1] = lastPoint[1];
						
						pos[0] += dirX;
						pos[1] += dirY;
						
						lastPoint[0] = pos[0];
						lastPoint[1] = pos[1];
						
						if (i == 0) {
							wire1.add(pos);
						}
						if (i == 1) {
							wire2.add(pos);
						}
					}
				}
				line.close();
			}

			System.out.println("Points Plotted Successfully");
			
			int z = 1;
			int closestDistance = 2147483647;
			int leastSteps = 2147483647;

			int xi = 1;

			for (int[] x : wire1) {
				int yi = 1;
				for (int[] y : wire2) {
					if (x[0] == y[0] && x[1] == y[1]) {
						if ((Math.abs(x[0]) + Math.abs(x[1])) < closestDistance) {
							closestDistance = (Math.abs(x[0]) + Math.abs(x[1]));
						}
						if ((yi + xi) < leastSteps) {
							leastSteps = (yi + xi);
						}
					}
					yi++;
				}
				if (z % 5000 == 0) {
					System.out.println("compared point " + z + " of total " + wire1.size());
				}

				z++;
				xi++;
			}
			
			System.out.println("\n\n\n\tClosest Cross (Manhattan Distance): " + closestDistance + "\n\n\tLeast signal time (combined least movements on wire to reach intersection): " + leastSteps + "\n\n\n");

			file.close();
        }
        catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}