object zadanie {

	//Zadanie 1  Jest tylko 4 + obrazek
 def evenR(n:Int): Boolean=
 if(n==0) true else addR(n-1)                     //> evenR: (n: Int)Boolean
 def addR(n:Int): Boolean =
 	if(n==0)false else evenR(n-1)             //> addR: (n: Int)Boolean
	 
 	evenR(2)                                  //> res0: Boolean = true
 	
  //Zadanie 2 a
  def fib(n: Int): Int={
  if(n<0) throw new RuntimeException("Bledne dane")
  else{
	n match {
		case 0 => 0
		case 1 => 1
	  case _ => fib(n-2) + fib(n-1)
	}
	}
 }                                                //> fib: (n: Int)Int

  
  //Zadanie 2 b
  
	def fibTail(n:Int) = {
	if(n<0) throw new RuntimeException("Bledne dane")
	else {
  	def fHelper(n:Int, f1:Int, f2:Int):Int =
    	n match {
      	case 0 => f1
      	case 1 => f2
      	case _ => fHelper(n - 1, f2, f1 + f2)
  	}
  	fHelper(n, 0, 1)
 		}
	}                                         //> fibTail: (n: Int)Int

//Zadanie 3

def root3 (a:Double) = {
  def root3Helper(x:Double):Double =
    if (math.abs(math.pow(x, 3) - a) <= 1.0e-55 * Math.abs(a)) x // sprawdzamy bezwzglednosc
    else root3Helper(x + (a / math.pow(x, 2) - x) / 3)
  root3Helper(if (a > 1) a/3 else a)
}                                                 //> root3: (a: Double)Double


//Zadnie 5

def initSegment[A](xs:List[A], ys:List[A]):Boolean =
  (xs, ys) match {
    case (Nil, _) => true
    case (_, Nil) => false
    case _ =>
      if (xs.head == ys.head) initSegment(xs.tail, ys.tail)
      else false
  }                                               //> initSegment: [A](xs: List[A], ys: List[A])Boolean


//Zadanie 6

def replaceNth[A](xs:List[A], n:Int, x:A):List[A] =
  (xs, n) match {
    case (Nil, _) => Nil
    case (list, 0) => x :: xs.tail
    case (list, _) => xs.head :: replaceNth(xs.tail, n-1, x)
}                                                 //> replaceNth: [A](xs: List[A], n: Int, x: A)List[A]


}
