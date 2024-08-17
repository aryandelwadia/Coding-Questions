//link
//https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
public:
vector<int> ans;
    ProductOfNumbers() {
        ans.push_back(1);  
    }
    
    void add(int num) 
    {
        if(num!=0)
        {
            ans.push_back(ans.back()*num);
        }
        else
        {
            ans.clear();
            ans.push_back(1);
        }
    }
    
    int getProduct(int k) 
    {
        if(k>=ans.size()){
            return 0;    
        }
        else {
            return ans.back() / ans[ans.size()-k-1];
        }
    }
};