//Zadanie 1
def poleTrojkata(a: Double, b: Double, c: Double): Double = {
  if (a <= 0 || b <= 0 || c <= 0) throw new RuntimeException("Bledne dane")
  else if (math.abs(b - c) < a && b + c > a) {
    val p = (a + b + c) / 2
     math.sqrt(p*(p-a)*(p-b)*(p-c))
  } else throw new RuntimeException("Taki trojkat nie jest mozliwy")
}


println(poleTrojkata(1,1,1))
//println(poleTrojkata(1,1,-1))


//Zadanie 4
def mnejLixzba(x: List[Int]): Int={
val b = x.head
val a = (x.tail).head
val c =0
	if(b < a){
		c==(x.tail).head
		if(b < c){
		b
		}else{
				c
	}
	}else
	mnejLixzba(x.tail)
}                                                 //> mnejLixzba: (x: List[Int])Int
                                            //> mnejLixzba: (x: List[Int])Int

mnejLixzba(List(6,5,4,2,2,3,1,0,9)) 