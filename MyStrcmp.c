#include <stdio.h>
#include <assert.h>

int MyStrcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);//确保str1和str2不为空指针
	while (*str1 == *str2)//检测第一对字符是否相等
	{                    //如果相等就判断是不是遇到了'\0'
		if (*str1 == 0)  //为'\0'证明两个字符串相等
			return 0;    //相等返回0
		str1++;          //比较下一对字符
		str2++;
	}
	//程序走到这里，一定是出现了一对不相等的字符
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