#include <stdio.h>
#include <assert.h>
const char* MyStrstr(const char* str1, const char* str2)
{
	assert(str1 && str2);

	//���str1�ҵ���ĩβ���ͽ���ѭ��
	while (*str1)
	{   //�ҵ���һ��ƥ����ַ�
		while (*str1 != *str2 && *str1 != '\0')
			str1++;
		
		int i = 0;
		//��ʱ������˵�һ����ȵ��ַ�����������ƥ��
		while (*(str1 + i))
		{
			//��Ϊ��һ���ַ��Ѿ�ƥ�����ȣ�����i������++
			i++;
			//ƥ����������str2������'\0'��֤��str1����str2������
			if (*(str2 + i) == '\0')
				return str1;
			//�����'\0'֮ǰƥ�䵽����ȵģ��ͽ�����һ�ε�ƥ��
			if (*(str1 + i) != *(str2 + i))
				break;
		}
		//���str1 + i ��'\0'����ζ��str1���Ѿ������ܰ���str2��
		if (*(str1 + i))
			str1++;
		else
			return NULL;
	}
	if (*str2 == '\0')
		return str1;
	else
		return NULL;
}
int main()
{
	char* arr1[] = { "zhangsan","lisssiaaa","\0","wang","wangwu" };
	char* arr2[] = { "gsa","si","\0","wang","www" };
	int i = 0;
	while (i < 5)
	{
		char* ret = MyStrstr(arr1[i], arr2[i]);
		if (ret == NULL)
			printf("%s ���Ҳ��� %s\n", arr1[i], arr2[i]);
		else
			printf("%s\n", ret);
		i++;
	}
	return 0;
}