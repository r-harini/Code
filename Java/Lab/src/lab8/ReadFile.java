package lab8;
import java.util.*;
import java.io.*;

public class ReadFile {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileReader f=null;
		try {
			f=new FileReader("customer.txt");
			int c;
			while ((c=f.read())!=-1) {
				System.out.print((char)c);
			}
		}finally {
			if (f!=null) {
				f.close();
			}
		}
	}

}
