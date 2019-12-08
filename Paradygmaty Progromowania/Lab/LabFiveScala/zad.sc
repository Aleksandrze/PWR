object zad {
  println("Welcome to the Scala worksheet")       //> Welcome to the Scala worksheet

def zad3(xs: List[Double], predOne: (Double)=>Boolean, predTwo: (Double)=>Boolean) = {
    def zad3_temp(predO: Boolean, tl: List[Double], minimum: Double):  Boolean = {
      tl match {
        case Nil => (predO && predTwo(minimum))
        case h::t =>
          if (h < minimum) {
            if (!predOne(h)) zad3_temp(false, t, h)
            else zad3_temp(predO, t, h)
          }else {
            if (!predOne(h)) zad3_temp(false, t, minimum)
            else zad3_temp(predO, t, minimum)
          }
      }
    }
    zad3_temp(true,xs,xs.head)
  }                                               //> zad3: (xs: List[Double], predOne: Double => Boolean, predTwo: Double => Bool
                                                  //| ean)Boolean
  
zad3(List(8,1,1,0,6,4), (x: Double)=>x>3,(min:Double)=>min==0)
                                                  //> res0: Boolean = false


}