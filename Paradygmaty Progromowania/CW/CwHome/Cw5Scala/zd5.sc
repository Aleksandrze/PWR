object zd5 {
  println("Welcome to the Scala worksheet")       //> Welcome to the Scala worksheet
  

  
  // Zadanie 2 b
  
  val lfib = {
	def fibgen(a: Int, b: Int): Stream[Int] =
			a #:: fibgen(b, a + b)
			fibgen(1, 1)
}
  
}