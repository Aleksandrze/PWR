object qwerty {

def dwa(x: List[Int]): Int={
val b = x.head
val a = (x.tail).head
	if(b <= a) b
	else
	dwa(x.tail)
	}                                         //> dwa: (x: List[Int])Int
	
	
	dwa(List(6,5,1,2,3))                      //> res0: Int = 1


def mnejLixzba(x: List[Int]): Int={
val b = x.head
val a = (x.tail).head
val c =0
	if(b < a){
		c==(x.tail).head
		if(b < c){
		b
		}else{
				throw new RuntimeException ("Error")
	}
	}else
	mnejLixzba(x.tail)
}                                                 //> mnejLixzba: (x: List[Int])Int
}