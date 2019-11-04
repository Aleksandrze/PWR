def index[A](xs:List[A], index:A):List[Int]={
def indexHelp[A](i:Int, xs:List[A], ys:List[Int]): List[Int]={
xs match {
	case Nil => ys
	case h::t =>
	if(h==index) indexHelp(i+1, t, i::ys) else
		indexHelp(i+1,t,ys)
	}
	}
	indexHelp(0,xs, List()).reverse

	index(List(1,2,3,4,2,4,5,8,2), 2) 