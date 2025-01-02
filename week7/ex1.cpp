#include<bits/stdc++.h>

using namespace std;

struct Order {
    string customerID;
    string productID;
    int price;
    string shopID;
    int timePoint;
};

typedef struct Order Order;

vector<Order> orders;
unordered_map<string, int> shops;
unordered_map<string, map<string, int> > c_shops;

bool cmp(Order a, Order b){
    return a.timePoint < b.timePoint;
}

int parseTime(string time1) {
    int hours = stoi(time1.substr(0, 2));
    int minutes = stoi(time1.substr(3, 2));
    int seconds = stoi(time1.substr(6, 2));
    return hours * 3600 + minutes * 60 + seconds;
}

int binarySearch(int time1) {
    int left = 0;
    int right = orders.size();  // Right bắt đầu từ orders.size()

    while (left < right) {
        int mid = (right + left) / 2;

        if (orders[mid].timePoint < time1) {
            left = mid + 1;
        } else if (orders[mid].timePoint > time1){
            right = mid;
        }else{
            left = mid;
            break;
        }
    }

    return left;  // Left sẽ là vị trí đầu tiên có timePoint >= time1
}


int main(){
    string s;
    int total_orders = 0;
    int total_revenue = 0;

    while(getline(cin, s) && s != "#"){
        istringstream ss(s);
        string timePoint;
        Order order;
        ss >> order.customerID >> order.productID >> order.price >> order.shopID >> timePoint;

        int time1 = parseTime(timePoint);

        order.timePoint = time1;

        orders.push_back(order);
        shops[order.shopID] += order.price;
        c_shops[order.customerID][order.shopID] += order.price;

        total_orders++;
        total_revenue += order.price;
    }

    sort(orders.begin(), orders.end(), cmp);

    vector<int> prefix_sum;

    prefix_sum.resize(orders.size());
    prefix_sum[0] = orders[0].price;
    for (size_t i = 1; i < orders.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + orders[i].price;
    }

    while(getline(cin, s) && s != "#"){
        istringstream ss(s);
        string word = "";
        ss >> word;
        if (word == "?total_number_orders"){
            cout << total_orders << endl;
        }else if (word == "?total_revenue"){
            cout << total_revenue << endl;
        }else if (word == "?revenue_of_shop"){
            string shop;
            ss >> shop;
            cout << shops[shop] << endl;
        }else if (word == "?total_consume_of_customer_shop"){
            string customer, shop;
            ss >> customer >> shop;
            cout << c_shops[customer][shop] << endl;
        }else{
            string from_time, to_time;
            ss >> from_time >> to_time;
            int f_time = parseTime(from_time);
            int t_time = parseTime(to_time);
            int total = 0;

            int start = binarySearch(f_time);
            int end1 = binarySearch(t_time);
            if (start >= orders.size()) { // Kiểm tra nếu start vượt quá orders
                cout << 0 << endl;
            } else {
                if (end1 >= orders.size() || orders[end1].timePoint > t_time) {
                    end1--; // Lùi lại để end1 nằm trong giới hạn <= t_time
                }

                if (start > end1) { // Kiểm tra nếu khoảng không hợp lệ
                    cout << 0 << endl;
                } else if (start > 0) {
                    cout << prefix_sum[end1] - prefix_sum[start - 1] << endl;
                } else {
                    cout << prefix_sum[end1] << endl;
                }
            }

        }
    }

}
