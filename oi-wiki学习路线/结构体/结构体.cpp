struct point 
{
    int sum;
    int cnt;
    bool operator <(const point &b) const{
        if(sum==b.sum)return cnt<b.cnt;
        else return sum<b.sum;
        //这是按照你的要求进行排序
        //当sum一致，返回cnt小的，否则返回sum小的
    }
}
// 当我们想进行结构体排序或者运用在堆的时候，需要对他进行内置作用
