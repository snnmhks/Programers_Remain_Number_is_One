#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

/*
소수를 찾는 문제와 거의 같다. 나머지가 1이 되게 하려면 그 수에서 1을 뺀 수의 최소 공약수를 찾으면 된다.
어떤 수가 소수가 아니면은 나누어 떨어지는 수는 항상 짝을 이룬다.
ex) 10은 2와 5의 곱이며 5와 2의 곱이다. -> 즉 2만 확인해도 5는 확인할 필요가 없다. 따라서 제곱근 수까지만 
확인하면 짝을 이루는 모든 수를 살펴보는 것이다.
*/

int solution(int n) {
    int answer = 0;

    int LastNum = (n - 1) % 10;
    // 끝자리수
    if (LastNum % 2 == 0)
        // 끝자리수로 짝홀 판단
    {
        answer = 2;
    }

    else
    {
        int Rootn = sqrt(n - 1);
        // 제곱근수
        for (int i = 3; i <= Rootn; i += 2)
        {
            if ((n - 1) % i == 0)
                // 나누어 떨어지면 그게 답이다.
            {
                answer = i;
                break;
            }
        }

        if (answer == 0)
            // 아무것도 안 나누어 떨어지면 그 수가 소수이므로 그게 답이다.
        {
            answer = n - 1;
        }
    }
    return answer;
}