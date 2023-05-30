
#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
    int number = 10;

    cout << "Hello World!\n";
    printf("Hello World!\n");

    printf("Hello World!!\n");
    printf("Hello World!!\n");
    printf("Hello World!! %d \n", number - 2);

    


    
    // 주석(comment) 이 라인은 프로그램에 영향을 주지 않는다.
    // 내가 필요한 글자를 마음대로 적으면 된다.
    // 이게 한줄 주석이라고 한다.

    /*
        이걸 여러줄 주석이라고 한다.
        이 라인들은 프로그램에 영향을 주지 않는다.

        ctrl + s : 저장
        ctrl + l : 한줄 지우기
        ctrl + d : 한줄 복사 생성
        ctrl + 방향키 : 단어 건너뛰기
        shift + alt + 위아래 방향키 : 여러줄 타이핑

        특수문자 (\) 와 조합해서 쓰는 특수문자를 ★이스케이프 시퀸스라고 한다.
        \n : 줄바꿈 문자(개행 문자)

        변수 : 컴퓨터 메모리에 값을 저장하기 위한 공간
        변수의 종류 : 구조체, 클래스, 대리자 등등
        
        함수 : 컴퓨터가 작업을 수행하도록 하는 기능
        함수의 종류 : 메서드(클래스가 가진 멤버), 프로시저, 이벤트 등등

        #include는 '전처리기 지시문(preprocessor directive)'이다.
        <>안에 적어주는 것이 헤더파일이다. (stdio.h가 헤더파일 header file)
        헤더파일에 커서를 두고 F12를 누르면 열어볼 수 있다.
        ctrl + -를 누르면 반대로 간다.
        코드를 기계어로 바꿔주는 것이 컴파일
        컴파일을 해주는 프로그램이 컴파일러(VisualStudio)
        int main()는 함수다(메인 함수)
        void는 비어있다는 뜻이다.

        
    */

    return 0;
}
