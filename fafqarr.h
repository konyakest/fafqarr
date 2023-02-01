#ifndef FAFQARR_H
#define FAFQARR_H	

#define F(i,j,k) for (signed i=signed(j);i<=signed(k);i++)
#define lowbit(x) ((x)&-(x))
#define inline __attribute((always_inline))

template<typename T,int maxn>
class fafqarr;

template<typename T,int maxn>
class fafqarr_node1{
    friend fafqarr<T,maxn>;
public:
    inline void operator +=(T k){
        que->change(x,x,k);
    }
    inline void operator -=(T k){
        (*this)+=(-k);
    }
    inline void operator =(T k){
        int adder=k-(*que)(x);
        (*this)+=adder;
    }
    inline operator T(){
        return que->query(x,x);
    }
private:
    int x;
    fafqarr<T,maxn>* que;
    inline void init(int _x,fafqarr<T,maxn>* _que){
        x=_x;
        que=_que;
    } 
};

template<typename T,int maxn>
class fafqarr_node2{
    friend fafqarr<T,maxn>;
public:
    inline void operator +=(T k){
        que->change(x,y,k);
    }
    inline void operator -=(T k){
        (*this)+=(-k);
    }
    inline operator T(){
        return que->query(x,y);
    }
private:
    int x,y;
    fafqarr<T,maxn>* que;
    inline void init(int _x,int _y,fafqarr<T,maxn>* _que){
        x=_x,y=_y;
        que=_que;
    } 
};

template<typename T,int maxn>
class fafqarr{
    friend fafqarr_node1<T,maxn>;
    friend fafqarr_node2<T,maxn>;
public:
    inline fafqarr_node1<T,maxn> operator[](int x){
        fafqarr_node1<T,maxn> tmp;
        tmp.init(x,this);
        return tmp;
    }
    inline fafqarr_node1<T,maxn> operator()(int x){
        return (*this)[x];
    }
    inline fafqarr_node2<T,maxn> operator[](pair<int,int> x){
        fafqarr_node2<T,maxn> tmp;
        tmp.init(x.first,x.second,this);
        return tmp;
    }
    inline fafqarr_node2<T,maxn> operator()(int x,int y){
        return (*this)[{x,y}];
    }
private:
    T t1[maxn+5],t2[maxn+5];
    inline void add(int x,T y){
        int tmp=x;
        for(;x<=maxn;x+=lowbit(x)) t1[x]+=y;
        x=tmp;
        for(;x<=maxn;x+=lowbit(x)) t2[x]+=y*tmp;
    }
    inline T query(int x){
        int tmp=x;
        T ans1=0,ans2=0;
        for(;x;x-=lowbit(x)) ans1+=t1[x];
        x=tmp;
        for(;x;x-=lowbit(x)) ans2+=t2[x];
        return (tmp+1)*ans1-ans2;
    }
    inline T query(int x,int y){
        return query(y)-query(x-1);
    }
    inline void change(int x,int y,int k){
        add(x,k);add(y+1,-k);
    }
};

#undef inline
#undef lowbit
#undef F(i,j,k)

#endif
