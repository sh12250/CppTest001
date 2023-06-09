using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// 일정한 주기로 코인이 랜덤한 위치에 떨어진다
// 플레이어 ( 0 )가 코인을 주으면 점수가 상승

// 플레이어와 컴퓨터가 각각 카드를 2장씩 뽑는다
// 두 카드의 합이 더 큰 쪽이 승리, 작은 쪽은 패배한다
// 동일한 숫자가 나올 경우 문양은
// 스페이드, 다이아몬드, 하트, 클로버 순으로 승리한다

namespace _23._06._09_JungProgram
{
    public class Program
    {
        static void Main(string[] args)
        {
            int[] cards = new int[13];
            string[] patterns = new string[4];
            Random random = new Random();

            for(int x = 0; x < 13; x++)
            {
                cards[x] = x + 1;
            }

            patterns[0] = "♣";
            patterns[1] = "◇";
            patterns[2] = "♡";
            patterns[3] = "♠";

            int myCardPatt1 = random.Next(1, patterns.GetLength(0));
            int myCardPatt2 = random.Next(1, patterns.GetLength(0));
            int myCardNum1 = random.Next(1, cards.GetLength(0));
            int myCardNum2 = random.Next(1, cards.GetLength(0));

            while (myCardNum1 == myCardNum2 && myCardPatt1 == myCardPatt2)
            {
                myCardNum1 = random.Next(1, cards.GetLength(0));
                myCardNum2 = random.Next(1, cards.GetLength(0));
            }

            int comCardPatt1 = random.Next(1, patterns.GetLength(0));
            int comCardPatt2 = random.Next(1, patterns.GetLength(0));
            int comCardNum1 = random.Next(1, cards.GetLength(0));
            int comCardNum2 = random.Next(1, cards.GetLength(0));

            while (comCardNum1 == comCardNum2 && comCardPatt1 == comCardPatt2)
            {
                comCardNum1 = random.Next(1, cards.GetLength(1));
                comCardNum2 = random.Next(1, cards.GetLength(1));
            }

            Console.WriteLine("내가 뽑은 카드 {0} {2} , {1} {3} \n\n", patterns[myCardPatt1], patterns[myCardPatt2], cards[myCardNum1], cards[myCardNum2]);

            Console.WriteLine("컴이 뽑은 카드 {0} {2} , {1} {3} \n\n", patterns[comCardPatt1], patterns[comCardPatt1], cards[comCardNum1], cards[comCardNum2]);

            Task.Delay(2000).Wait();

            if(myCardNum1 + myCardNum2 > comCardNum1 + comCardNum2)
            {
                Console.WriteLine("{0} : {1} \n", myCardNum1 + myCardNum2, comCardNum1 + comCardNum2);
                Console.WriteLine("내가 이겼다!!! \n");
            }
            else if(myCardNum1 + myCardNum2 == comCardNum1 + comCardNum2)
            {
                Console.WriteLine("카드 합이 같다... \n");

                if(myCardNum1 > myCardNum2)
                {
                    if (myCardPatt1 > comCardPatt1 && myCardPatt1 > comCardPatt2)
                    {
                        Console.WriteLine("{0} {1} : {2} {3} \n", myCardPatt1, myCardPatt2, comCardPatt1, comCardPatt2);
                        Console.WriteLine("내가 이겼다!!! \n");
                    }
                    else if(myCardPatt1 == comCardPatt1 || myCardPatt1 == comCardPatt2)
                    {
                        if (myCardPatt1 > comCardPatt2)
                        {
                            Console.WriteLine("{0} {1} : {2} {3} \n", myCardPatt1, myCardPatt2, comCardPatt1, comCardPatt2);
                            Console.WriteLine("내가 이겼다!!! \n");
                        }
                        else
                        {
                            Console.WriteLine("{0} {1} : {2} {3} \n", myCardPatt1, myCardPatt2, comCardPatt1, comCardPatt2);
                            Console.WriteLine("졌다... \n");
                        }
                    }
                    else
                    {
                        Console.WriteLine("{0} {1} : {2} {3} \n", myCardPatt1, myCardPatt2, comCardPatt1, comCardPatt2);
                        Console.WriteLine("졌다... \n");
                    }
                }
            }
        }           // main()

        static void MakeGameBoard()
        {

        }
    }
}
