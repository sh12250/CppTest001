using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// C#에서 함수는 메서드다
// 클래스 안의 함수를 멤버 함수라고 한다
// 그게 메서드다

namespace Gustation
{
    public class Program    // internal
    {
        // main함수는 변수를 밖( 명령 프롬프트 같은 것 )에서 매개변수로 받을 수 있다
        static void Main(string[] args) // static 메서드는 함수 안에서만 부를 수 있다
        {
            // Descript1();
            
            // 기본적으로 0으로 초기화 되어있다
            int[] numbers1 = new int[5];
            int[,] numbers2 = new int[5, 5];

            int valueCount = 0;
            for(int i = 0; i < 5; i++)
            {
                for(int j=0; j < 5; j++)
                {
                    valueCount++;
                    numbers2[i, j] = valueCount;
                    // Console.WriteLine("numbers[{0}][{2}] 의 값 : {1} \n", i, numbers2[i,j], j);
                }
                // Console.WriteLine("numbers[{0}] 의 값 : {1} \n", i, numbers1[i]);
            }
            A myClassA = new A();

            myClassA.PrintMyArr(numbers2);

            string[,] board = new string[5, 5];

            for(int y = 0; y < 5; y++)
            {
                for(int x = 0;x < 5; x++)
                {
                    board[y, x] = "*";
                }
            }
        }           // main()


    }       // class program

    public class A
    {

        public void PrintMyArr(int[,] array_)
        {
            for (int y = 0; y < 5; y++)
            {
                for (int x = 0; x < 5; x++)
                {
                    // 줄넘김이 없다
                    Console.Write("{0} ", array_[y, x]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }       // PrintMyArr();

        public void Descript1()
        {
            Console.WriteLine("Hello world! \n");

            string userInput1 = default;
            string userInput2 = default;
            int number = default;
            float floatNum = default;

            int userNumber1 = default;
            int userNumber2 = default;

            // 여기서 입력받는다
            userInput1 = Console.ReadLine(); // _getch()함수 같이 작동한다
            userInput2 = Console.ReadLine();

            //userNumber1 = System.Convert.ToInt32(userInput1);
            //userNumber2 = System.Convert.ToInt32(userInput2);

            //userNumber1 = int.Parse(userInput1);
            //userNumber2 = int.Parse(userInput2);

            int.TryParse(userInput1, out userNumber1); // 숫자면 리턴?
            int.TryParse(userInput2, out userNumber2); // 아니면 안한다?


            Console.WriteLine("{0} + {1} = {2} \n", userNumber1, userNumber2, userNumber1 + userNumber2);


            // Console.WriteLine("입력 받은 내용 출력 >> {1} {0} \n\n", userInput1, userInput2);
            // {0}은 자리 표시자
            // 배열에서의 순서와 같다
        }

    }



}
