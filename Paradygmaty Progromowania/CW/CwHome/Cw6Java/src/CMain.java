
public class CMain {

	static boolean isEqual1(int m, int n){return m == n;}
	static boolean isEqual2(Integer m, Integer n){
		return m == n;
		}
	public static void main(String[] args){
	System.out.println(isEqual1(500,500));
	System.out.println(isEqual2(500,500)); 
	
	System.out.println("*-*-*-*-*-*-*-*-*-*-*-*-*-");
	
	String s1 = "foo";
	String s2 = "foo";
	System.out.println(s1 == s2);
	System.out.println(s1.equals(s2));
	String s3 = new String("foo");
	System.out.println(s1 == s3);
	System.out.println(s1.equals(s3)); 
	}

}
