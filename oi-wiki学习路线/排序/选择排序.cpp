#include <bits/stdc++.h>
int a[607];
/*
选择排序的思想
每次都安抚好当前位置的数字到底排在哪里
因为当前位置之前的都被选择好了，所以每次在后面的点找即可
*/
int main(){
	int n, i, id, j, t;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	//选择排序
	for (i = 1; i < n; ++i) {
		id = i;
		for (j = i + 1; j <= n; ++j)
			if (a[j] < a[id]) id = j;
        //找到属于当前位置的数
		//交换a[id] 和 a[i] 
		if (id != i) 
			t = a[id], a[id] = a[i], a[i] = t;
	}
	return 0;
}
