#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

// ��ü �� - �� ���� �� = 100, �ƴ� ���� -1�� ������
int find(int v[],int sum)
{
    int num = sum;
    int output = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (num - (v[i] + v[j]) == 100)
            {
                v[i] = -1;
                v[j] = -1;
                return 0;
            }
        }
    }
}

int main()
{
    int v[9] = { 0, };
    int sum = 0;

    // �����̸� �Է¹ް� �����ϱ� 
    for (int i = 0; i < 9; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v, v + 9);

    // ã��
    find(v, sum);

    // ����ϱ�
    for (int i = 0; i < 9; i++) {
        if (v[i] != -1) cout << v[i] << "\n";
    }
    return 0;
}