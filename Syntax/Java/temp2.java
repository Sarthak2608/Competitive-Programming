/*
https://www.youtube.com/watch?v=QvygMnR6sHM&feature=youtu.be


Questions:

1.) What happen if we remove static from main function:
It will compile,but when JVM call main function by the class name then it will generate error.


2.) JAVA compiler converts source code into byte code (It is same for all platforms means for window ,ios,linux) 
	JVM generate machine code from the byte code .JVM is machine dependent.

	JRE=JVM + extra librares use in java( ex : util ,Array etc)
	JDK=JRE + compiler
3.) Why Java?
	It is platform independent because it creates the bytes code

4.) Why java is not a 100% Object oriented?
	It contains primitive data types (int ,double etc) which are not objects

5.) what is Wrapper class?
	This classes provides the extra features to primitive data types like paresInt in Integer class

6.) can we execute java program without main method?
	till java 1.7 vesion ,we can execute it without main function.
	We can execute program in static initialization area of class.
	But in above version ,If we have not main function then static initialization will not call.
	
	https://www.tutorialspoint.com/can-we-execute-a-java-program-without-a-main-method

7.) Polymorphism or overloading?
	It is done on the basis of number of parameters or type of argument .
	Overloading cannot be done on the basis acess modifier (means public ,private etc) and static or non static

8.) which class is parent class of every class
	Object class

9.) super keyword?
	In inheritance , to call the function of parent class from child class ,super is used.

10.)Is Multiple inheritance supported using class in java?
	No ,If it is suppoted the there is chance of ambiguity
	Ex: A->C
		B->C
	if A,B both have same name function then if we call this same function from object of 
	C ,then there is a ambiguity.

	Note: we can acheive multiple inheritance using interface.

11.) Final keyword?
	in variable: cannot reinitialize
	in function: cannot override
	in class : cannotn  extends (or inherit)
	

12.) Interface ?
	These are the classes in which all functions have declaration but no body.
	we implements all the function in child body.

13.) Abstract class?
	In these class some function have not body so these are implemented in child class
	
	we can say in Interface all methods are abstract.	

14.) Threads in java
	It is a lightweight process ,Example ,we scroll something as well as download

15.) Synchronization
	If we have multiple process , all of them want to use same resource then to ensure that at each time only one process use
	the resource ,we use synchronize keyword
16.) Why java string are immutable?
	
	String s="hello" //line 1
	s="world"		 //line 2

	In intern pool memory:
	in line 1 ,in heap memory JVM check the if there exist "hello" string then it
	will return address a,otherwise allocate memory to the string "hello"
	let address be x

	in line 2 ,another address return by the JVM and value at the x remains same till garbage collector 
	frees it 		
	
Note: If we use String s=new String("hello") then it always allocates the new memory in heap memory 



17.) why Stringbuilder?
	we can change the value of string at the same address

18.) String builder vs string buffer
	
	string builder is not synchronised (means at same time all thread use the same function)
	so it is fast

	but string buffer is synchronised so it slow.

19.) Arraylist vs vector
	arraylist is not synchronized but vector is synchronized

20.) which will call first -costructor,instance initializer ,static initializer
	
	first static initializer then instance initializer and then constructor

21.) static binding vs dynamic binding
	
	static binding -> compiler already knows which function will call on runtime 
		ex- if method is static ,private or final then it cannot override so compiler knows.

	dynamic binding ->compiler would know which function will calls at runtime ,overriding is the example of it	

*/


import java.util.*;
import java.lang.Math.*;


//use of this
class Test
{
	public int a=10;
	public static int b;
	static{
		b=5;
	}

	Test()
	{
	
	}
	public void show(Test obj)
	{
		int a=b;
		obj.a=3;
		System.out.println(a);
		System.out.println(this.a);
		System.out.println(obj.a);
	}
}


class A
{
	public int x;

	//instance initializer block
	{
		for(int i=1;i<=5;i++)
			x+=i;
	}

	public A()
	{
	 	this(11);
		x=1;	
	}
	public A(int y)
	{
		x=y;
		this.show();
	}
	
	public void show()
	{
		System.out.println("x="+x);
	}
}

public class Temp2
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);



		int i=10;
		System.out.println(i);
		Integer ii=i;  //auto boxing
		System.out.println(ii);
		int j=ii; //unboxing
		System.out.println(j);
		


		//this operator
		Test obj=new Test();
		Test obj2=new Test();
		obj.show(obj2);




		//static import
		int a=7,b=5;
		System.out.println("Without static import "+Math.max(a,b));
	//	System.out.println("Static import "+max(a,b));


		//constructor
		A obja=new A();
		obja.show();

	}
}