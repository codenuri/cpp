// edit 예제 정리

// edit3.cpp
// => 변하는 것을 가상함수로 분리 한것
// => 의도 : 파생 클래스를 만들어서 변하는 것(가상함수)를 override
// => template method



// 특징 
// #1. NumEdit 는 "Edit 기능 + Validation 알고리즘"을 모두 가지고 있다
// => 다른 입력도구(MultiEdit)같은 곳에서는 NumEdit 가진 알고리즘 사용못함
// => Validation 알고리즘은 NumEdit 가 소유, 다른 곳에서 사용못함.






// edit4.cpp
// => 변하는 것(알고리즘)을 다른 클래스로 분리 한것
// => strategy 패턴

// 특징 : Edit 본연의 기능과 Validation 알고리즘이 완벽히 분리되어 있다
// => 다른 입력도구에서도 언제라도 Validation 알고리즘을 사용가능하다.
// => Validation 알고리즘의 재사용가능

// 중요한 특징 : 실행시간에 validation 알고리즘 교체 가능. 
