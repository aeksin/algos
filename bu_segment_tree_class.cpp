template<typename T>
class segment_tree{
private:
    std::vector<T> tree;
    T size;
    void make_tree(T sz){
        int c=1;
        while (c<sz){
            c<<=1;
        }
        segment_tree::size=c;
        tree.assign(segment_tree::size*2,0);
    }
public:
    segment_tree(T sz){
        make_tree(sz);

    }
    segment_tree(std::vector<T> &d){
        make_tree(d.size());
        for (T pos=0;pos<d.size();pos++){
            segment_tree::update(pos,d[pos]);
        }
    }
    void update(T pos,T elem){
        pos+=segment_tree::size;
        segment_tree::tree[pos]=elem;
        for (pos>>=1;pos>=1;pos>>=1){
            segment_tree::tree[pos]=tree[2*pos]+tree[(2*pos)^1];
        }
    }
    void update(T l,T r,T elem){
        l+=segment_tree::size;
        r+=segment_tree::size;
        if (r<l)[[unlikely]] swap(r,l);
        while(l<=r){
            if (l%2==1){
                tree[l]+=elem;
                l++;
            }
            if (r%2==0){
                tree[r]+=elem;
                r--;
            }
            l>>=1;
            r>>=1;
        }
    }
    T get(T pos){
        pos+=segment_tree::size;
        T sum=0;
        while (pos>=1){
            sum+=segment_tree::tree[pos];
            pos>>=1;
        }
        return sum;
    }
    T get(T l,T r){
        l+=segment_tree::size;
        r+=segment_tree::size;
        T sum=0;
        if (r<l)[[unlikely]] swap(r,l);
        while(l<=r){
            sum+=l%2==1?tree[l++]:0;
            sum+=r%2==0?tree[r--]:0;
            l>>=1;
            r>>=1;
        }
        return sum;
    }
};
