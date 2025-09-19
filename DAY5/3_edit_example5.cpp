// edit 예제 정리

// edit3.cpp
// => 변하는 것을 가상함수로 분리 한것
// => 의도 : 파생 클래스를 만들어서 변하는 것(가상함수)를 override
// => template method



// 특징 
// #1. NumEdit 는 "Edit 기능 + Validation 알고리즘"을 모두 가지고 있다
// => 다른 입력도구(MultiEdit)같은 곳에서는 NumEdit 가진 알고리즘 사용못함
// => Validation 알고리즘은 NumEdit 가 소유, 다른 곳에서 사용못함.

// 중요한 특징 : 실행시간에 validation 알고리즘 교체 할수 없다.
// => 코드 작성시(파생 클래스 만들때) 알고리즘이 결정 
//----------------------------------------------------------

// edit4.cpp
// => 변하는 것(알고리즘)을 다른 클래스로 분리 한것
// => strategy 패턴

// 특징 : Edit 본연의 기능과 Validation 알고리즘이 완벽히 분리되어 있다
// => 다른 입력도구에서도 언제라도 Validation 알고리즘을 사용가능하다.
// => Validation 알고리즘의 재사용가능

// 중요한 특징 : 실행시간에 validation 알고리즘 교체 가능. 

// 결론 : Edit 의 Validation 교체 코드는
// => template method(edit3.cpp) 보다는 strategy(edit4.cpp) 가 좋습니다

// 그런데,
// Rect 의 draw()/draw_imp() 관계 - template method! 에서

// 1. Rect 를 "어떻게 그리는지" 는 실행시간에 변경될 이유 없습니다
// 2. Rect 를 "어떻게 그리는지" 는 다른 클래스에서 사용할 이유 없습니다
// 3. 사각형을 그리려면 멤버 데이타 접근 필요 합니다
//    => template method 는 가상함수 기반이므로 private 멤버 접근 가능
//    => strategy 는 다른 클래스이므로 private 멤버 접근 안됨. 

// 따라서
// Edit 예제는 "strategy" 가 좋고
// Shape 예제는 "template method" 가 좋습니다

// => 복습할때 위 2개의 장단점을 명확히 정리해 놓으세요
// => 그래야, 실전에서 어떤 패턴을 적용할지 판단할수 있습니다