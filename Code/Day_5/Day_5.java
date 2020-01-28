import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Day_5 {
    public static void main(String[] args) {
        try {
            // load file
            Scanner scan = new Scanner(new File("Data_5.txt"));
            scan.useDelimiter(",");
            
            // open empty intCode
            ArrayList<BigInteger> intCode = new ArrayList<BigInteger>();
            
            // get data from file
            while (scan.hasNext()) {
                String x = scan.next();
                
                intCode.add(new BigInteger(x));
            }
            scan.close();

            while (intCode.size() < 100000) {
                intCode.add(new BigInteger("0"));
            }
            
            // initialize code
            boolean codeRunning = true;
            int readerPos = 0;
            int relativePos = 0;
            
            // open a scanner for code input
            Scanner input = new Scanner(System.in);
            
            // compute intCode
            while (codeRunning) {
                // take the operator
                String operation = intCode.get(readerPos).toString();
                
                int operator = 0;
                StringBuilder valueTypes = new StringBuilder("");

                // check if operator is less than 2 length (ie 1)
                if (operation.length() < 2) {
                    // split operator type
                    operator = Integer.valueOf(operation.substring(operation.length() - 1));
                }
                else {
                    // split operator type
                    operator = Integer.valueOf(operation.substring(operation.length() - 2));
                    // split and order parameter types
                    valueTypes = new StringBuilder(operation.substring(0, operation.length() - 2));
                    valueTypes.reverse();
                }

                // execute operation (where the magic happens)
                switch (operator) {
                    case 1 : {
                        // get parameter 1
                        BigInteger x = new BigInteger("0");
                        int a = getValueType(valueTypes, 1);
                        switch (a) {
                            case 0 : {
                                x = intCode.get(Integer.valueOf(intCode.get(readerPos + 1).toString()));
                                break;
                            }
                            case 1 : {
                                x = intCode.get(readerPos + 1);
                                break;
                            }
                        }
                        // get paramerter 2
                        BigInteger y = new BigInteger("0");
                        int b = getValueType(valueTypes, 2);
                        switch (b) {
                            case 0 : {
                                y = intCode.get(Integer.valueOf(intCode.get(readerPos + 2).toString()));
                                break;
                            }
                            case 1 : {
                                y = intCode.get(readerPos + 2);
                                break;
                            }
                        }
                        // get parameter 3 (can only referance a position)
                        BigInteger z = new BigInteger("0");
                        int c = getValueType(valueTypes, 3);
                        switch (c) {
                            case 0 : {
                                z = intCode.get(Integer.valueOf(intCode.get(readerPos + 3).toString()));
                                break;
                            }
                        }
                        
                        // actually do the operation
                        BigInteger op = x.add(y);
                        intCode.set(Integer.valueOf(z.toString()), op);
                        
                        // incerment the reader
                        readerPos += 4;
                        
                        // proceed to next point
                        break;
                    }
                    case 2 : {
                        // get parameter 1
                        BigInteger x = new BigInteger("0");
                        int a = getValueType(valueTypes, 1);
                        switch (a) {
                            case 0 : {
                                x = intCode.get(Integer.valueOf(intCode.get(readerPos + 1).toString()));
                                break;
                            }
                            case 1 : {
                                x = intCode.get(readerPos + 1);
                                break;
                            }
                        }
                        // get paramerter 2
                        BigInteger y = new BigInteger("0");
                        int b = getValueType(valueTypes, 2);
                        switch (b) {
                            case 0 : {
                                y = intCode.get(Integer.valueOf(intCode.get(readerPos + 2).toString()));
                                break;
                            }
                            case 1 : {
                                y = intCode.get(readerPos + 2);
                                break;
                            }
                        }
                        // get parameter 3 (can only referance a position)
                        BigInteger z = new BigInteger("0");
                        int c = getValueType(valueTypes, 3);
                        switch (c) {
                            case 0 : {
                                z = intCode.get(Integer.valueOf(intCode.get(readerPos + 3).toString()));
                                break;
                            }
                        }
                        
                        // actually do the operation
                        BigInteger op = x.multiply(y);
                        intCode.set(Integer.valueOf(z.toString()), op);
                        
                        // incerment the reader
                        readerPos += 4;
                        
                        // proceed to next point
                        break;
                    }
                    case 3 : {
                        // get parameter 1
                        BigInteger x = new BigInteger("0");
                        int a = getValueType(valueTypes, 1);
                        switch (a) {
                            case 0 : {
                                x = intCode.get(Integer.valueOf(intCode.get(readerPos + 1).toString()));
                                break;
                            }
                            case 1 : {
                                x = intCode.get(readerPos + 1);
                                break;
                            }
                        }
                        // get parameter 2 (from input)
                        System.out.print("input required to proceed: ");
                        BigInteger y = new BigInteger(input.next());
                        
                        // actually do operation
                        intCode.set(Integer.valueOf(x.toString()), y);
                        
                        // incremt the reader
                        readerPos += 2;
                        
                        // proceed to next point
                        break;
                    }
                    case 4 : {
                        // get parameter 1
                        BigInteger x = new BigInteger("0");
                        int a = getValueType(valueTypes, 1);
                        switch (a) {
                            case 0 : {
                                x = intCode.get(Integer.valueOf(intCode.get(readerPos + 1).toString()));
                                break;
                            }
                            case 1 : {
                                x = intCode.get(readerPos + 1);
                                break;
                            }
                        }
                        
                        // do operation
                        System.out.println("Parameter 4 output: " + x.toString());
                        
                        // increment the reader
                        readerPos += 2;
                        
                        // proceed to next point
                        break;
                    }
                    case 99 : {
                        // stop code loop
                        codeRunning = false;
                        
                        // exit current loop iteration
                        break;
                    }
                    default : {
                        // print error message
                        System.out.println("/// Error: Invalid Operand: " + operation +" ///");
                        
                        // stop code loop
                        codeRunning = false;
                        
                        // exit current loop iteration
                        break;
                    }
                }
            }
        }
        // catch errors
        catch (Exception e) {
            System.out.println("Code Exception " + e);
        }
    }
    
    // for determining what type of parameter you need to get after operand
    public static int getValueType(StringBuilder str, int index) {
        // fix index to apply to StringBuilder indexes
        index--;
        // create return type
        int returnValue;
        
        // if index does not exist, put 0 in returnValue
        if (index > str.length() - 1) {
            returnValue = 0;
        }
        // if exists, get the type and put in returnValue
        else {
            returnValue = Integer.valueOf(str.substring(index, index + 1));
        }
        
        // return correct parameter type
        return returnValue;
    }
}