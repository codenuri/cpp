struct Point
{
	int x, y;
	Point(int a, int b) : x{a}, y{b} { }	
};

// const 없이 & 로 받을때
// => 임시객체를 받을수 없다.
void reset(Point& pt) { pt.x = 0; pt.y = 0;}

// const &
// => 인자값을 읽기만 하겠다.
// => 임시객체를 받을수 있다.
void draw_line(const Point& from, const Point& to) {}


int main()
{
	// 임시객체를 인자로 전달 
	draw_line(Point {0, 0}, Point {30, 30} ); // ok

	reset( Point {30, 30} ); 	// error
}