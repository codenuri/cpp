// 4_접근지정자 - 76page~
#include <iostream>


// struct : 접근지정자 생략시 기본이 public
// class  : 접근지정자 생략시 기본이 private

// C++에서 struct 와 class 키워드 차이는 오직 한가지 밖에 없습니다.
// => 위 내용..
// => 나머지는 완전히 동일  

// => 단, C#, Java 에서는 struct 와 class 차이가 아주 많습니다. - 해당분야 학습해 보세요
// => Rust 에는 struct 문법만 있습니다. class 없음. 


// 객체지향의 철학에는 struct 보다는 class 가 좋습니다.!!!


//struct Car
class  Car
{
//private:		
	int speed;	
				

public:			
	void set_speed(int s)
	{
		if ( s >= 0 && s < 200 )
			speed = s;
	}
};

int main()
{
	Car c;

	c.set_speed(-10);	
}
