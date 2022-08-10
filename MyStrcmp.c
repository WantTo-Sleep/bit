#include <stdio.h>
#include <assert.h>

int MyStrcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);//ȷ��str1��str2��Ϊ��ָ��
	while (*str1 == *str2)//����һ���ַ��Ƿ����
	{                    //�����Ⱦ��ж��ǲ���������'\0'
		if (*str1 == 0)  //Ϊ'\0'֤�������ַ������
			return 0;    //��ȷ���0
		str1++;          //�Ƚ���һ���ַ�
		str2++;
	}
	//�����ߵ����һ���ǳ�����һ�Բ���ȵ��ַ�
	return *str1 - *str2;
}

int main()
{
	char* arr1[] = { "zhangsan","lisi","wangwu" };
	char* arr2[] = { "zhangsan","liwu","wang" };
	int i = 0;
	while (i < 3)
	{
		int ret = MyStrcmp(arr1[i], arr2[i]);
		if (ret > 0)
			printf(">\n");
		else if (ret < 0)
			printf("<\n");
		else
			printf("=\n");
		i++;
	}

	return 0;
}