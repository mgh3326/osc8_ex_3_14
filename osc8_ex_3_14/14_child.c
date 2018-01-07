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
int memo[50];			   //�̰� ũ�� �ؾ� �����ɱ�?
long long fibonacci(int n) //�޸������̼�
{						   //�޸������̼��� �߰��� ����� �ð� ���⵵�� O(N)�Դϴ�.
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
	�� ����� ��� ȣ���� �̿��� ����Դϴ�. �ð� ���⵵�� �뷫 O(2N) ������ ������ �˴ϴ�.
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
