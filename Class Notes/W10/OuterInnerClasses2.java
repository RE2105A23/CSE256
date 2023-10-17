/*
Outer-inner class concept in Java
*/

class Outer {
	
	//Outer class variables
	//private int a=10; final int b=20; static int c=50;
	
	static void Input() {
		System.out.println("This is outer class");
	}

    static class Inner {
        static void show() {
            System.out.println("This is inner class");
			//System.out.println("A is="+a);
			//System.out.println("B is="+b);
			//System.out.println("C is="+c);
        }
    }
	
	//Inner obj=new Inner(); obj.show();
}

class OuterInnerClasses2 {
	
	public static void main(String[] args) {
		//outer.inner object = new outer().new inner()
		//Outer.Inner obj=new Outer().new Inner();
		//obj.show();
		//Outer obj1=new Outer(); obj1.Input();
		//Outer obj1=new Outer(); obj1.Input();
		
		Outer.Input(); Outer.Inner.show();
	}
}

