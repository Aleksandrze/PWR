object zadanie2 {
  println("Welcome to the Scala worksheet")       //> Welcome to the Scala worksheet
  
sealed trait Marka
case object Opel extends Marka
case object Renault extends Marka
case object Nissan extends Marka

sealed trait Model
case object astra extends Model
case object megane extends Model
case object corsa extends Model
case object micra extends Model

type Samochod = (Marka,Model,Int)
type Samochody = List[Samochod]


val allCars = List((Opel, astra, 1999),(Renault, megane, 2004), (Opel, corsa, 2009),  (Nissan, micra, 2004), (Opel, corsa, 2009),  (Nissan, micra, 2004))
                                                  //> allCars  : List[(Product with Serializable with zadanie2.Marka, Product with
                                                  //|  Serializable with zadanie2.Model, Int)] = List((Opel,astra,1999), (Renault,
                                                  //| megane,2004), (Opel,corsa,2009), (Nissan,micra,2004), (Opel,corsa,2009), (Ni
                                                  //| ssan,micra,2004))
    
  
 def zad2 (list:Samochody,rocznik:Int) = {
 val cars = list filter ((c => c._3==rocznik))
  def zad2(flist:Samochody,acc:List[(Marka,Model,Int)]):List[(Marka,Model,Int)] = {
    flist match {
     case Nil => acc.reverse
     case x::xs => val k = (x._1,x._2, (flist filter (car => (car._1==x._1 && car._2==x._2))).length)
       zad2 ((flist filter (car => (car._1!=x._1 && car._2!=x._2))), k::acc )
    }
     
  }
      zad2 (cars,Nil)
  }                                               //> zad2: (list: zadanie2.Samochody, rocznik: Int)List[(zadanie2.Marka, zadanie
                                                  //| 2.Model, Int)]




zad2 (allCars,2004)                               //> res0: List[(zadanie2.Marka, zadanie2.Model, Int)] = List((Renault,megane,1)
                                                  //| , (Nissan,micra,2))
zad2 (allCars,2009)                               //> res1: List[(zadanie2.Marka, zadanie2.Model, Int)] = List((Opel,corsa,2))
 

  
}