/*
declare the class with name outer_calculator
declar inner class with name inner_calculator -> do four functions
1.addition 2.substraction 3.multiplication 4.divison
write the main method inside outer_calculator
user operator symbol to take input from the user and 
if user enter wrong operator then it display messsage("invalid operator")
*/

import java.util.Scanner;

class OuterInnerClass {
	
	//int a=10,b=20;
	int a,b;
	OuterInnerClass(int a, int b) {
		this.a=a; this.b=b;
	}
	
	class inner_calculator {
		
		void addition() {
			
			System.out.println("A+B:"+(a+b));
			
		}
		
		void substraction() {
			
			System.out.println("A-B:"+(a-b));
			
		}
		
		void multiplication() {
			
			System.out.println("A*B:"+(a*b));
			
		}
		
		void divison() {
			
			System.out.println("A/B:"+(a/b));
			
		}
	}
	
	public static void main(String[] args) {
		
		Scanner scan=new Scanner(System.in);
		
		System.out.print("Enter 2 values for A & B: ");
		
		int a=scan.nextInt();
		int b=scan.nextInt();
		
		OuterInnerClass.inner_calculator obj = new OuterInnerClass(a,b).new inner_calculator();

		
		System.out.println("Enter the character + - * /:");
		
		char c=scan.next().charAt(0);
				
		switch(c) {
			
			case '+':
				obj.addition();
				break;
			
			case '-':
				obj.substraction();
				break;
			
			case '*':
				obj.multiplication();
				break;
			
			case '/':
				obj.divison();
				break;
			
			default:
				System.out.println("Invalid operator");
		}
	}
}