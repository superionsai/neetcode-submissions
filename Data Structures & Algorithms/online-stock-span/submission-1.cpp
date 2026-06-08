class StockSpanner {
private:
    vector <pair<int, int>> Spanner;

public:
    StockSpanner() { 
        Spanner.push_back({INT_MAX, 0});
    }
    
    int next(int price) {
        int iter = Spanner[0].second; 
        int counter = 1;
        int span = 1;
        while (iter > 0 && Spanner[iter].first <= price) { counter++; iter--; }
        span = max(span, counter);
        Spanner.push_back({price, span});
        Spanner[0].second++;
        cout << span << " : span of number";
        cout << " || " << Spanner[0].second << " : size" << endl;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */