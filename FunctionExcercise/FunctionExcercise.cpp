#include<iostream>
#include<stdio.h>
#include<time.h>

// 이게 함수의 정의
void SocialSecurityNumber(int age) 
{
    printf("제 이름은 정석환입니다. 나이는 %d살이고, 전화번호는 010-2486-4240입니다. \n\n", age);
}

float CriticalHit(float damage) 
{
    srand((unsigned int) time(NULL));
    int rate = rand() * 2;
    int criticalrate = rate - ((rate / 100) * 100);
    float criticaldamagerate = 1.5;

    printf("70을 초과하면 크리티컬! : %d \n\n", criticalrate);

    if (criticalrate > 70)
    {
        return damage * criticaldamagerate;
    }
    else 
    {
        return damage;
    }
}

void PlusFunction(int number1, int number2) 
{
    printf("%d + %d = %d \n", number1, number2, number1 + number2);
}
void MinusFunction(int number1, int number2) 
{
    printf("%d - %d = %d \n", number1, number2, number1 - number2);
}
void MultiplyFunction(int number1, int number2) 
{
    printf("%d * %d = %d \n", number1, number2, number1 * number2);
}
void DivideFunction(float number1, float number2) 
{
    printf("%.0f / %.0f = %.2f \n", number1, number2, number1 / number2);
}
void ModCalcFunction(int number1, int number2) 
{
    printf("%d %% %d = %d \n\n", number1, number2, number1 % number2);
}

void HealingFunction(int healingpower) 
{
    int FullHealthPoint = 50;
    int HealthPoint = 20;

    printf("전체 체력 : %d, 현재 체력 : %d, 힐량 : %d \n\n", FullHealthPoint, HealthPoint, healingpower);

    HealthPoint = (HealthPoint + healingpower) > FullHealthPoint ? FullHealthPoint : HealthPoint + healingpower;

    printf("힐받은 체력 : %d \n\n", HealthPoint);
}

int main()
{
    int number = 10; // int는 정수Intezer의 약자다
    float number2 = 1.66666; // 정수부분만 입력되고 소수점 아래는 입력되지 않는다

    printf("이게 먼저 호출 된다. \n\n");

    SocialSecurityNumber(30); // 함수의 호출

    printf("순서대로 실행되기 때문이다. \n\n"); // 함수를 main위에 정의하는 이유

    int anynumber = -100;
    printf("%d \n\n", anynumber);

    printf("평타 : %f, 크리티컬 : %f \n\n", number2, CriticalHit(number2));

    int someNumber = 0;
    someNumber = someNumber++;

    printf("someNumber안에는 무슨 값이 들어 있을까? %d \n", someNumber);

    //int num1 = 10;
    //int num2 = 12;
    //int result1, result2, result3;

    //result1 = num1 != num2;
    //result2 = num1 <= num2;
    //result3 = num1 >= num2;

    //printf("Result1 결과는 %d \n", result1); // 0
    //printf("Result2 결과는 %d \n", result2); // 1
    //printf("Result3 결과는 %d \n", result3); // 0

    //int num1 = 10;
    //int num2 = 12;
    //int result1, result2, result3;

    //result1 = (num1 == 10 && num2 == 12); // 양쪽을 먼저 연산하고 &&(논리곱)을 연산한다
    //result2 = (num1 < 12 || num2 > 12);
    //result3 = (!num1); // C++에서 0이 아닌 다른 모든 숫자는 '참'이다.

    //printf("result1 : %d \n", result1);
    //printf("result2 : %d \n", result2);
    //printf("result3 : %d \n", result3);

    int age = 20;
    bool boolresult;

    boolresult = (age < 20) ? true : false;


    printf("Bool Result는 어떤 값? %d \n\n", (age < 20) ? false : true);

    /*
    printf("%d + %d = %d \n", num1, num2, result); // 더하기
    printf("%d - %d = %d \n", num1, num2, num1 - num2); // 빼기
    printf("%d * %d = %d \n", num1, num2, num1 * num2); // 곱하기
    printf("%d / %d = %d \n", num1, num2, num1 / num2); // 나누기
    printf("%d %% %d = %d \n", num1, num2, num1 % num2); // mod 연산

    PlusFunction(num1, num2);
    MinusFunction(num1, num2);
    MultiplyFunction(num1, num2);
    DivideFunction(num1, num2);
    ModCalcFunction(num1, num2);
    */
    // 전체 체력 50 현재 체력 20 힐받는 양은 입력받는다, 전체 체력을 초과할 수 없다.
    HealingFunction(31);


}

/*
    main함수는 무조건 있어야 한다
    프로그램은 main함수에서부터 시작한다


    ctrl + k + c : 주석처리
    ctrl + K + u : 주석처리 해제
*/