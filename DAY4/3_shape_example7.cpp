#include <iostream>
#include <vector>

// 핵심 #6

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() const { return 0;}
	virtual void draw() { std::cout << "draw shape\n"; }

};




class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }
};


int main()
{
	std::vector<Shape*> v; 

	while( 1 )
	{
		int cmd;
		std::cin >> cmd;

		if 		( cmd == 1 ) v.push_back(new Rect);
		else if ( cmd == 2 ) v.push_back(new Circle);
		else if ( cmd == 9 )
		{
			for ( auto s : v)
				s->draw();
		}
		
		// 이번 소스의 핵심
		else if ( cmd == 8 )
		{
			std::cout << "몇번째 만들었던 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			// k 번째 만들었던 도형과 완전히 동일한 도형을 만들어서 v에 추가합니다.
			// 어떻게 해야 할까요 ?
			// k 번째 도형은 어떤 도형일까요 ? 

			// 해결책 #1. dynamic_cast 로 k 번째 도형이 어떤 도형인지 조사한다.
			// => 단점 : 새로운 도형이 추가되면 아래 코드는 수정되어야 합니다.
			//			 OCP 위반
			
			if( dynamic_cast<Rect*>(v[k]) != nullptr )
			{
				v.push_back(new Rect()); // 정확히 하려면 v[k] 의 속성을 동일하게 설정해야 합니다.
			}
			else if ( dynamic_cast<Circle*>(v[k]) != nullptr )
			{
				v.push_back(new Circle()); 
			}
			

		}
	}
}
