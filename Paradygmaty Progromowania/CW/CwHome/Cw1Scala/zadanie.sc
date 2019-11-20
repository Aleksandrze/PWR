object zadanie {
  
  //zad 1 sciska zagniezdzine struktury
def flatten[A](x:List[List[A]]):List[A] ={
if (x == Nil) Nil
else x.head ++ flatten(x.tail)
  }                                               //> flatten: [A](x: List[List[A]])List[A]
	val lol = List(List(1,2), List(3,4))      //> lol  : List[List[Int]] = List(List(1, 2), List(3, 4))
	lol.flatten                               //> res0: List[Int] = List(1, 2, 3, 4)

	
  
  //zad 2
    def count [A](x: A, list: List[A]): Int={
  	if(list == Nil) 0
  	else (if (x==list.head) 1 else 0) + count(x, list.tail)
  }                                               //> count: [A](x: A, list: List[A])Int
  count ('a', List('a','a','v','v','5','e','a'))  //> res1: Int = 3
  count ('2', List('2','f','f','2','z','2','5','4'))
                                                  //> res2: Int = 3
                                                  
	//zad 3
  
  def coping[A](element: A, ileRaz: Int ) : List[A]= {
  if(ileRaz<0) throw new Exception("Negative reps")
  else if(ileRaz == 0) Nil
  else element :: coping(element, ileRaz-1)
  }                                               //> coping: [A](element: A, ileRaz: Int)List[A]
  coping("lala", 5)                               //> res3: List[String] = List(lala, lala, lala, lala, lala)
  // coping ("tt", -5)
  coping( "s",3)                                  //> res4: List[String] = List(s, s, s)
  coping(5, 2)                                    //> res5: List[Int] = List(5, 5)
  
  //zad 4
	def sqrList(list:List[Int]): List[Int]={
	if(list == Nil) Nil
	else list.head * list.head :: sqrList(list.tail)
	}                                         //> sqrList: (list: List[Int])List[Int]
	sqrList(List(1,2,3,4))                    //> res6: List[Int] = List(1, 4, 9, 16)
	
	//zad 5
	//I don't know how this using
	
	//zad 6
	def lingth[A](list: List[A]): Int= {
		if(list == Nil) 0
		else 1 + lingth(list.tail)
	}                                         //> lingth: [A](list: List[A])Int
lingth(List(1,2,5,4,8,6,47,6,48,4,11))            //> res7: Int = 11

    def count1 [A](x: A, list: List[A]): Int={
  	if(list == Nil) 0
  	else (if (x==list.head) 1 else 0) + count1(x, list.tail)
  }                                               //> count1: [A](x: A, list: List[A])Int
  count1 ('a', List('a','a','v','v','5','e','a')) //> res8: Int = 3
  
  
}