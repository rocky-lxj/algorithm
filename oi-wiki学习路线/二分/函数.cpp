lower_bound(arr.begin(),arr.end(),cnt)-arr.begin();
//查询第一个大于等于cnt的下标，这里arr用vector
upper_bound(arr.begin(),arr.end(),cnt)-arr.begin();
//查询第一个大于cnt的下标，这里arr用vector

在查询的时候有一个非常要注意的点，就是当我们查询的数字大于有序数组中的最大值的时候
它会返回最后一位，所以一定要特判最后一位