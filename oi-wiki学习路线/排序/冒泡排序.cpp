#include <bits/stdc++.h>
int a[607];
/*
冒泡排序，每次保证i-n的序列有序
*/
int main(){
	int n, i, j, t;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	//冒泡排序
    //保证由后向前的稳定性
	for (i = n-1; i; --i) {
        for (j = 1; j <= i; ++j)
            if (a[j] > a[j+1])
                t = a[j], a[j] = a[j+1], a[j+1] = t;
	}
	return 0;
}
