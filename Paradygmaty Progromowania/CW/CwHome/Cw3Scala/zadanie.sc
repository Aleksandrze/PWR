object zadanie {

// Zadanie 2a
def curry3[A,B,C,D](f:(A,B,C)=>D)=
	(x:A)=>(y:B)=>(z:C)=>f(x,y,z)             //> curry3: [A#81605, B#81606, C#81607, D#81608](f#81634: (A#81605, B#81606, C#81
                                                  //| 607) => D#81608)A#81605 => (B#81606 => (C#81607 => D#81608))
	
// Zadanie 2b

def uncurry3[A,B,C,D](f:A=>B=>C=>D)=
(x:A,y:B,z:C)=>f(x)(y)(z)                         //> uncurry3: [A#81614, B#81615, C#81616, D#81617](f#81643: A#81614 => (B#81615 
                                                  //| => (C#81616 => D#81617)))(A#81614, B#81615, C#81616) => D#81617



//Zadanie 3
def sumProd(xs:List[Int]) =
(xs foldLeft (0,1)) ((acc, h) => (acc._1 + h, acc._2 * h))
                                                  //> sumProd: (xs#81644: List#2139[Int#892])(Int#892, Int#892)

}