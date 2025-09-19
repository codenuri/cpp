// QA : validation 알고리즘을 함수 포인터나 람다식으로 전달하는 방식도 
//      가능할거 같은데 이런 방식은 잘 사용하지 않나요?

// 함수   : 1개의 동작만을 정의 한것, 상태도 없습니다.
// 클래스 : 여러개의 동작이 있고, 상태도 있습니다.(멤버 데이타가 있다는 것)

class Edit 
{
	IValidator* val; // val 에 LimitDigitValidator 를 연결하면
					 // 1. validation 정책
					 // 2. is_complete 정책 
					 // 3. validation 정책을 위한 데이타(value) 
					 // 가 한번에 연결됩니다.

	bool(*validte)(const std::string& s);  // 함수 포인터
					// validation 정책만 연결됩니다.
					// is_complete 는 별도의 함수 포인터 필요
					// 또한 함수는 멤버데이타도 없습니다.

}

