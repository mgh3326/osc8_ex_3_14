/**
* Simple program demonstrating Win32 anonymous pipes.
*
* Figure 3.27
*
* @author Gagne, Galvin, Silberschatz
* Operating System Concepts  - Eighth Edition
* Copyright John Wiley & Sons - 2008.
*/

#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 25
int memo[50];			   //이걸 크게 해야 좋은걸까?
long long fibonacci(int n) //메모이제이션
{						   //메모이제이션을 추가한 방법의 시간 복잡도는 O(N)입니다.
	if (n <= 1)
	{
		return n;
	}
	else if (memo[n] != 0)
	{
		return memo[n];
	}
	else
	{
		return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	/*if (n == 0)//
	이 방법은 재귀 호출을 이용한 방법입니다. 시간 복잡도는 대략 O(2N) 정도가 나오게 됩니다.
	return 0;
	else if (n == 1)
	return 1;
	else
	{
	long long a = fibonacci(n - 1) + fibonacci(n - 2);
	return a;
	}*/
}
int main(VOID)
{
	HANDLE ReadHandle, WriteHandle;
	CHAR buffer[BUFFER_SIZE];
	DWORD read;

	ReadHandle = GetStdHandle(STD_INPUT_HANDLE);
	WriteHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	/* have the child read from the pipe */
	if (ReadFile(ReadHandle, buffer, BUFFER_SIZE, &read, NULL))
	{
		//printf("child: >%s<", buffer);
		printf("fibonacci(%d) : (%lld)\n", atoi(buffer), fibonacci(atoi(buffer)));

	}
	else
		fprintf(stderr, "Child: Error reading from pipe\n");

	return 0;
}
