/*
*      HW#10: 템플릿과 STL
*   작성자 : 황재찬          날짜: 2023년 6월 5일
*
*   문제정의 : map 컨테이너를 이용하여 (영어, 한글) 단어를 쌍으로 저장하고, 영어로
*			   한글을 검색하는 사전을 작성하는 아래 프로그램을 완성하시오
*/
#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string,string> dic; // 맵 컨테이너 생성. 키는 영어 단어, 값은 한글 단어
	//모두 단어이므로 string으로 지정하고 map을 선언해줍니다. 
	// 단어 3개를 map에 저장
	dic.insert(make_pair("love", "사랑")); // ("love", "사랑") 저장
	dic.insert(make_pair("apple", "사과")); // ("apple", "사과") 저장
	dic["cherry"] = "체리"; // ("cherry", "체리") 저장
	cout << "저장된 단어 개수 " << dic.size() << endl;
	string eng;
	while (true) {
		cout << "찾고 싶은 단어>> ";
		cin >> eng;// 사용자로부터 키 입력
		if (eng == "exit")
			break; // "exit"이 입력되면 종료
		if (dic.find(eng)==dic.end()) // eng '키'를 끝까지 찾았는데 없음
			cout << "없음" << endl;
		else
			cout << dic[eng] << endl; // dic에서 eng의 값을 찾아 출력
	}
	cout << "종료합니다..." << endl;
}
