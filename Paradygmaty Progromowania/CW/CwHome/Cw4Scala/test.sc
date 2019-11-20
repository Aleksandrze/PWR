object test {
  println("Welcome to the Scala worksheet")       //> Welcome to the Scala worksheet
  
  // Zadanie 3
  
 sealed trait BT[+A]
case object Empty extends BT[Nothing]
case class Node[+A](elem:A, left:BT[A], right:BT[A]) extends BT[A]

// start
	def breadthBT[A](tree: BT[A]) = {
		def helper[A](queue: List[BT[A]]): List[A] = queue
		 match {
			case Nil => Nil
			case Empty :: tail => helper(tail)
			case Node(v, l, r) :: tail => v :: helper(tail ++List(l, r)) // v value
		}
			helper (List(tree))
	}                                         //> breadthBT: [A](tree: test.BT[A])List[A]

	
	
	
 breadthBT(Node(1, Node(2, Node(4, Empty, Empty),Empty),Node(3,Node(5,Empty,Node(6,Empty,Empty)),Empty)));
                                                  //> res0: List[Int] = List(1, 2, 3, 4, 5, 6)
	
}