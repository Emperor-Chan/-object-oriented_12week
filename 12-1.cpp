/*   
*      HW#10: 템플릿과 STL
*   작성자 : 황재찬          날짜: 2023년 6월 5일
* 
*   문제정의 : 다음 함수는 매개변수로 주어진 int 배열 src에서 배열 minus에 들어있는
*              같은 정수를 모두 삭제한 새로운 int 배열을 동적으로 할당받아 리턴한
*              다. retSize는 remove() 함수의 실행결과를 리턴하는 배열의 크기를 전달
*              받는다.
*              템플릿을 이용하여 remove()를 일반화시키고, double로 구체화하는 경우
*              어떻게 remove() 함수를 호출해야 하는지 뒷장의 main() 함수에 추가해
*              보시오
*/
#include <iostream>

using namespace std;

template<class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	T* arr = new T[sizeSrc]; /* 최대 sizeSrc의 크기만큼 배열을 저장할 수 있어야 하므로 그 크기만큼 동적할당
	해주어야 합니다. 
	*/
	retSize = 0; //retSize를 0으로 초기화해줍니다. 
	for (int i = 0; i < sizeSrc; i++) {
		bool flag = 0;
		for (int j = 0; j < sizeMinus; j++) { // minus를 모두 탐색하고 만약 src[i]가 존재하면 flag=1을해줍니다.
			if (src[i] == minus[j]) {
				flag = 1;
				break;
			}
		}
		if (flag)continue;//flag가 1이라는것은 minus에 존재하는 원소이므로 continue해줍니다. 
		arr[retSize++] = src[i];//flag가 0이므로 제거된 배열에 추가해줍니다. 
	}
	return arr;//minus와 겹치지 않은 원소만 담긴 배열인 arr를 반환합니다. 
}

int main() {
	// remove() 함수를 int로 구체화하는 경우
	cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2,3}을 뺍니다" << endl;
	int x[] = { 1,2,3,4 };
	int y[] = { -3,5,10,1,2,3 };
	int retSize;
	int* p = remove(x, 4, y, 6, retSize);
	if (retSize == 0) {
		cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
		return 0;
	}
	else {
		for (int i = 0; i < retSize; i++) // 배열의 모든 원소 출력
			cout << p[i] << ' ';
		cout << endl;
		delete[] p; // 할당받은 배열 반환
	}
	// remove() 함수를 double로 구체화하는 경우
	// 이곳에 작성
	cout << "실수 배열 { 1.1,2.2,3.3,4.4 }에서 정수 배열{ -3.3,5.5,10.1,1.1,2.2,3.3 }을 뺍니다" << endl;
	double xx[] = { 1.1,2.2,3.3,4.4 };//double형 배열들을 선언해줍니다.
	double yy[] = { -3.3,5.5,10.1,1.1,2.2,3.3 };
	double* pp = remove(xx, 4, yy, 6, retSize);//double형 배열을 반환받으므로
	//pp를 double*형으로 선언해줍니다. 
	if (retSize == 0) {
		cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
		return 0;
	}
	else {
		for (int i = 0; i < retSize; i++) // 배열의 모든 원소 출력
			cout << pp[i] << ' ';
		cout << endl;
		delete[] pp; // 할당받은 배열 반환
	}
}
