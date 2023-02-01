# fafqarr
支持快速单点修改，区间加，区间求和的数组

------

fafqarr，即 ``fast_add_fast_query_array`` （原谅我小学英语水平），支持在 $O(\log n)$ 的时间复杂度上单点修改，区间加，区间求和的数组

内部由“超级树状数组”实现

用法：

```cpp
fafqarr<long long,5e5> a;
//定义一个元素种类为long long，元素个数为5e5的fafqarr
a[3]=1;
//将a[3]赋值为1
a[4]+=3;
//将a[4]加上3
a[4]-=3;
//将a[4]减去3
a(2,5)=1;
//错误，不支持区间赋值
a(2,5)+=2;
//将区间[2,5]加上2
a(2,5)-=2;
//将区间[2,5]减去2
int tmp=a[3];
//查询a[3]的值
cout<<a[3];
//可以直接输出
int tmp=a(2,5);
cout<<a(2,5);
//查询区间的和同理

a[{x,y}]、a(x)分别与a(x,y)、a[x]用法相同，可根据自己习惯取用
```

**注：若定义``fafqarr<T,maxn>``，则有效下标为1~maxn；即使求和时没爆int，但有可能实现时爆掉，所以最好定义long long**

实例：（[线段树1](https://www.luogu.com.cn/problem/P3372)）

```cpp
fafqarr<long long,(int)5e5+5> q;
int n,m,x,y,k,op;
int main(){
    cin>>n>>m;
    F(i,1,n) cin>>x,q[i]=x;
    F(i,1,m) {
        cin>>op>>x>>y;
        if(op==1) cin>>k,q(x,y)+=k;
        else cout<<q(x,y)<<endl;
    }
    return 0;
}
```

注：

- 运算时可能会溢出

- 若 ``a`` 为 ``fafqarr`` ，``x`` 和 ``y`` 为整数，则调用 ``a[{x,y}]`` 或 ``a(x,y)`` 时必须保证 $1\leq x\leq y\leq \text{maxn}$，调用 ``a[x]`` 或 ``a(x)`` 时必须保证 $1\leq x\leq maxn$
[在luogu blog中查看](https://konyakest.blog.luogu.org/fafqarr)

