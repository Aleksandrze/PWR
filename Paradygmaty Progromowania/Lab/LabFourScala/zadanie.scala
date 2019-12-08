//Rekurencja zwykław

 // Zadanie 1
  
//Rekurencja zwykław
def zad1a[A](list:List[A],pred:(A=>Boolean)): List[A] = {
  list match {
    case Nil => Nil
    case head::teal => if (pred (head)) head::(zad1a(teal,pred))
                  else zad1a(teal,pred)
  }
}                                                 //> zad1a: [A](list: List[A], pred: A => Boolean)List[A]


// Rekurencja ogónowa

def zad1b[A](list:List[A],pred:(A=>Boolean)): List[A] = {
   def help(xs:List[A],xy:List[A]): List[A] =
     xs match {
     case Nil => xy.reverse
     case head::teal => if (pred (head)) help(teal,head::xy)
                   else help(teal,xy)
   }

   help(list,Nil)
}                                                 //> zad1b: [A](list: List[A], pred: A => Boolean)List[A]


def predykant(x:Int):Boolean ={
  if (x % 2 == 0) true
  else false
  }                                               //> predykant: (x: Int)Boolean
  
  
zad1a (List(3,2,323,4,88,99,100),predykant)       //> res0: List[Int] = List(2, 4, 88, 100)

zad1b (List(3,2,323,4,88,99,100),predykant)       //> res1: List[Int] = List(2, 4, 88, 100)

 // Zadanie 2 //dx =1.0E-15 dokładnosc
 
def zad2(fun:(Double=>Double),dx:Double,list:List[Double]):List[Double] = {
  def helpZ2(x:Double): Double = (fun(x+dx)-fun(x))/dx
  def temp (xlist:List[Double], ylist:List[Double]):List[Double] ={
    xlist match {
      case Nil => ylist.reverse
      case head::teil => temp(teil,helpZ2(head)::ylist)
    }
  }
  temp(list,Nil)
}                                                

zad2(math.sin,1.0E-15,List(1,2,3,4))             
zad2(((x:Double) => x*x),1.0E-15,List(1,2,3,4))   