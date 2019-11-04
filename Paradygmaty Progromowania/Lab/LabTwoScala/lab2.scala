//Zadanie 1
def one[A](x:A,y:A,z: Float)={
	(List(x,y),z*z)
}                                                

def two (x:(List[List[Float]]),y:(List[List[Float]]))={
		x.head==y.head
}   

def three[A](x:List[A], y: List[A] ,z:A)={
  ((y.head::x),(x.head,y.head))
}                                            



//Zadanie 2
def zad2[A](list:List[A]): List[A]= {
if(list==Nil)Nil
else List(list.head,list.last)
}   

 zad2(List(2,25,4,5,9,8))                      
 zad2( List('a','a','v','v','5','e','c'))
 
 