#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>

// 바둑 게임에서 "다음수를 예측"하는 알고리즘은 아주 다양합니다.
// => 최선의 다음수를 예측하는 것이 항상 좋은 것은 아닙니다.
// => 10급을 두는 사람에는 10급에 맞는 알고리즘을 제공하고,
//    사용자가 점점 잘 두게되면 알고리즘도 그에 맞도록 변경되어야 합니다.

// 바둑 게임에서 "다음수 예측 알고리즘은 교체" 가능해야 합니다.


// 사용자가 생각한 3개의 숫자를 컴퓨터가 맞추는 게임입니다

class BaseBallGame
{
	typedef std::tuple<int, int, int> INPUT;	// 컴퓨터가 예측한 3개의 숫자
	typedef std::tuple<int, int> RESULT;		// 위 3개의 숫자에 대한 결과 (ex 1strike 2ball)
	std::vector<std::pair<INPUT, RESULT> > v;
public:
	BaseBallGame() { srand((unsigned)time(0)); }

	void run()
	{
		while (1)
		{
			//-----------------------------------------------
			// 이전의 결과가 담긴 vector v를 참고 해서
			// 사용자가 생각한 숫자를 예측해 냅니다.
			// 현재 구현은 무조건 랜덤 입니다.
			int x = 0, y = 0, z = 0;
			do {
				x = rand() % 9 + 1;
				y = rand() % 9 + 1;
				z = rand() % 9 + 1;
			} while (x == y || y == z || x == z);
			//--------------------------------------
			std::cout << "당신이 생각한 숫자는 " << x
				<< ", " << y << ", " << z << " 입니까 ?\n";
			int strike = 0, ball = 0;
			std::cout << "strike 갯수 : ";
			std::cin >> strike;
			if (strike == 3)
			{
				std::cout << "성공 !\n";
				break;
			}
			std::cout << "ball 갯수 : ";
			std::cin >> ball;
			//--------------------------------------
			// 입력된 결과(strike, ball)을 기록해 두었다가
			// 다음수를 예측할때 사용합니다.
			v.push_back(std::make_pair(INPUT(x, y, z), RESULT(strike, ball)));
			dump();
		}
	}
	// 필요하신 분을 위해 참고용으로 만든 함수입니다. 
	void dump()
	{
		printf("-------------------------------\n");
		printf("입력값   s b\n");
		for (auto& p  : v) // p는 pair<INPUT, RESULT> 입니다.
		{
			printf(" %d %d %d : %d %d\n", 
				std::get<0>(p.first), std::get<1>(p.first), std::get<2>(p.first),
				std::get<0>(p.second), std::get<1>(p.second));
		}
		printf("-------------------------------\n");
	}
};
int main(void)
{
	BaseBallGame bbg;
	bbg.run();
}

/*
사용자가 생각한 숫자를 맞추는 알고리즘은 다양하게 변경 할 수 있습니다. 또는, 초급용/중급용/고급용 알고리즘을 교체하면서 사용할 수도 있습니다. 하지만, 위 코드는 하나의 함수안에서 모든 것을 처리하고 있기 때문에 알고리즘을 교체 하려면 BaseBallGame 클래스 자체를 수정해야 합니다.
과제는 다음과 같습니다.

과제 내용
위 코드에서 변하는 것에 해당 하는 “이전 결과를 바탕으로 사용자가 생각한 숫자를 예측하는 부분”을 교체 가능한 설계로 변경해 보세요. 즉, BaseBallGame 클래스가 변하지 않고도 알고리즘을 교체 할 수 있도록 설계 구조를 변경하세요
아래의 3가지 형태로 전부 작성해 주세요
1. 변하는 부분을 가상함수로(template method) 해서 구현해 보세요
2. 변하는 것을 다른 클래스로 분리한 후, 인터페이스 기반으로 교체 가능한 설계(strategy)로 만들어 보세요
3. 변하는 것을 다른 클래스로 분리한 후, 템플릿의 인자로 교체 가능한 설계(PolicyBase)로 만들어 보세요.

이 예제의 경우 최선의 디자인은 어떤 디자인 일까요 ?

알고리즘을 2개 만들고 
처음알고리즘은 나쁜 알고리즘을 사용하고
5번 이상 틀리면 좋은 알고리즘으로 교체 하는 코드도 만들어 보세요
=> 즉, 실행시간에 알고리즘이 교체되게 해보세요
=> 외 코드에서 몇번을 사용해야 하는지 생각해 보세요. 
*/