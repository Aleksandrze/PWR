object Zadanie {

   
 def zad2BezFL(list: List[Int=> Int]):(Int=> Int)={
 	list match {
 		case (head :: Nil) => list.head
 		case (f1::f2::tail) => zad2BezFL((f1 compose f2)::tail)
 	}
 }
 
 def zad2FL(list: List[Int =>Int]):(Int=>Int)= {
 	list.tail.foldLeft(list.head){(first, second) => second compose  first }
 }
	
def f1 = (n: Int) => n + n
def f2 = (n: Int) => 2 * n

def list = List(f1, f2, f1)

zad2BezFL(list)(3)
zad2FL(list)(3)

	
	
	def fl=((10-0.3)/(1.0/3.0))


	
	def za1(x:Int): Double ={
		def temp(i:Double, yy:Double, zz:Double):Double={
			if(1/i< zz) yy+zz
			else temp(i-1, yy+1,zz+1)
		}
		temp(i, yy-1, zz-1)
	}
	
}