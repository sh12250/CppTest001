
#include <iostream>
#include <stdio.h>


void MyNewPrint(int number) 
{
    printf("입력 값은 %d 입니다. \n", number);
}

int PlusTwoNumbers(int number1, int number2) 
{
    printf("입력 값은 %d, %d 입니다. ", number1, number2);

    return number1 + number2;
}

int MultiplyThreeNumbers(int number1, int number2, int number3) 
{
    printf("입력 값은 %d %d %d 입니다. ", number1, number2, number3);

    return number1 * number2 * number3;
}



int main()
{
    int number = 10;

    std :: cout << "Hello World!\n";
    printf("Hello World! \" \n");

    printf("Hello World!!\n");
    printf("Hello World!!\n");
    printf("Hello World!! %d \n\n\n", number - 2);


    MyNewPrint(100);
    printf("두 수의 합은 %d 입니다. \n\n", PlusTwoNumbers(5, 7));
    printf("세 수의 곱은 %d 입니다. \n\n", MultiplyThreeNumbers(12, 2, 5));





    
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
        %d : printf함수에서 숫자를 입력받을 때 사용하는 문자

        변수 : 컴퓨터 메모리에 값을 저장하기 위한 공간
        변수의 종류 : 구조체, 클래스, 대리자 등등
        
        함수 : 컴퓨터가 작업을 수행하도록 하는 기능
        함수의 종류 : 메서드(클래스가 가진 멤버), 프로시저, 이벤트 등등

        #include는 '전처리기 지시문(preprocessor directive)'이다.
        <>안에 적어주는 것이 헤더파일이다. (iostream, stdio.h가 헤더파일 header file)
        헤더파일에 커서를 두고 F12를 누르면 열어볼 수 있다.
        ctrl + - : 뒤로 가기

        코드를 기계어로 바꿔주는 것이 컴파일
        컴파일compile을 해주는 프로그램이 컴파일러compiler(VisualStudio)

        함수에는 입력과 출력이 있다.
        입력(input) -> 함수(Do Something) -> 출력(output)
        int main()는 함수다(메인 함수)

        함수의 구성
        int, main, (void)
        출력 형태를 결정한다
            이 부분이 void일 경우 출력값이 없다
            void가 아닐 경우 출력값이 생긴다
            출력값은 하나다.
        함수 이름
        입력 형태를 결정한다

        프로그램은 정해진 순서에 의해서 진행되는 함수의 호출이다.
        1. 함수의 정의 : 함수를 코드로 적는다.
        2. 함수의 호출 : 함수의 실행을 명령한다.
            실제로 함수를 사용하는 줄(ln22)에서 함수를 부른다(call)한다.
        3. 인자의 전달 : 함수의 실행을 명령할 때, 입력값을 전달한다.

        입력값의 종류 : 매개변수, 인자, 인수 등등

        함수에는 몸통(내용)이 있다
        함수의 내용은 중괄호({, }) 안에 적어준다

        int main(void)
        {
            //함수의 내용이 위치하는 곳
        }
        return을 만나는 순간 함수가 종료된다.

        return 0; <- return문

        return은 
            1. 함수의 종료와 
            2. 값의 전달(반환)이라는 
            두 가지 의미를 지닌다.

        void는 비어있다는 뜻이다.
    */

    return 0;
}
