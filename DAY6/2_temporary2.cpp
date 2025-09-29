struct Point
{
	int x, y;
	Point(int a, int b) : x{a}, y{b} { }	
};
void set_pixel(int x1, int y1) {}

void draw_line(const Point& from, const Point& to) {}

int main()
{
	// 1, 2 에 점을 그리고 싶다 => 변수를 만들기 보다는, literal 로 전달하는 것이 좋다.

	// 방법 #1. 변수를 생성해서 함수 인자로 사용
	int x = 0,  y = 0;
	set_pixel(x, y);

	// 방법 #2. literal 을 인자로 사용
	set_pixel(1, 2);


	// #2. draw_line을 사용해서 (1,1) ~ (5, 5)에 선을 그리고 싶다.
	Point from{1, 1};
	Point to{5, 5};
	draw_line(from, to ); // 방법 #1. 객체를 생성해서 전달
						  // 이렇게 하면 from, to 객체를 {}을 벗어날때 까지 파괴 안됨. 
		
	// 핵심 : 함수 인자로만 사용할 객체가 필요 하다면 "temporary" 가 훨씬 좋습니다.
	draw_line(Point{1,1}, Point{5, 5});					  
}