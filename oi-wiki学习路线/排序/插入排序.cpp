#include <bits/stdc++.h>
int a[607];
/*
插入排序的思想是将前i个位置做到最佳
所以他的长度从2-n
*/
int main(){
	int n, i, id, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	//插入排序
	for (i = 2; i <= n; ++i) {
        //把大于a[i]的数都往后挪
		for (j=i-1, k=a[i]; j && a[j]>k; --j)
            a[j+1] = a[j];
        //把a[i]放在他原有的位置上
        a[j+1] = k;
	}
	return 0;
}
