
class A
{
	int x=10;
	@Override
	public void finalize() throws Throwable{
		System.out.println("Now memory of this object is cleared");
	}
}

public class Finalize_example
{
	public static void main(String[] args) {
		A obj;
		obj=null;
		System.out.println("Hello");

		//using these command garbage collector may or not call
		System.gc();
		Runtime.getRuntime().gc();  
	}
}