class ProductOfNumbers {
public:
    vector<int> product;
    int lastZero;
    int i;

    ProductOfNumbers() {   
        lastZero = -1;
        i = -1;
    }
    
    void add(int num) {
        i++;
        if (num == 0) lastZero = i;
        if (i == 0 || product[i - 1] == 0) product.push_back(num);
        else product.push_back(product[i - 1] * num);
    }
    
    int getProduct(int k) {
        if (i - k < lastZero) return 0;
        if (i - k == lastZero) return product[i];
        
        return product[i] / product[i - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */