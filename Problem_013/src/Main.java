import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

import static java.lang.Integer.parseInt;

public class Main {

    public static void main(String[] args) {

        String fileName = "src/zin.txt";

        String line;

        BigInteger a[] = new BigInteger[100];

        try {
            FileReader fileReader = new FileReader(fileName);
 
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            int i = 0;
            while ((line = bufferedReader.readLine()) != null) {
                a[i] = new BigInteger(line);
                ++i;
            }
        }
        catch (FileNotFoundException ex){
            System.out.println(
                    "Unable to open file '" +
                            fileName + "'");
        }
        catch (IOException ex) {
            ex.printStackTrace();
        }
/*
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < t; ++i) a[i] = parseInt(scanner.next());
        scanner.close();
*/
        BigInteger sum = BigInteger.valueOf(0);

        for (int i = 0; i < 100; ++i) {
            sum = sum.add(a[i]);
        }
        System.out.print(sum);
    }
}
 