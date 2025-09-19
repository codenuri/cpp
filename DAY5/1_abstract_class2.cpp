#include <iostream>
#include <vector>

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}
	
	void draw() 
	{ 
		std::cout << "mutex.lock\n";
		draw_imp();		
		std::cout << "mutex.unlock\n"; 
	}

protected:
	virtual void draw_imp() 
	{
		std::cout << "draw shape\n";
	}

public:
	virtual Shape* clone() const {	return new Shape(*this); }
};



class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect\n"; }

	Shape* clone() const override {	return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw circle\n"; }

	Shape* clone() const override {	return new Circle(*this); }
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
	}
}
