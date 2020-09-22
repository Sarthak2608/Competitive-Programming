/*
Can we overload main method ?
Yes

*/

public class Overload_main
{
	public static void main(String[] args) {
		main(10);
	}
	public static void main(int x)
	{
		System.out.println(x);
		try{
			System.out.println("Hello try");
			// return ;
		}
		catch(Exception e)
		{

		}
		finally{
			System.out.println("Hello finally");
		}	



		System.gc(); //two ways to call garbage collector
		Runtime.getRuntime().gc();  




		String s1="hello";
		String s2="hello";
		String s3=new String("hello");
		if(s1==s3)
		{
			System.out.println("Address are equal of 1 and 3");
		}
		else if(s1==s2)
		{
			System.out.println("Address are equal of 1 and 2");
		}
		else
		{
			System.out.println("Address are Not equal");
		}
		if(s1.equals(s3))
		{
			System.out.println("value is equal of 1 and 3");
		}
	}
}
