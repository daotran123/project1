#include <bits/stdc++.h>
using namespace std;

struct T {
    int t1;    // Số nước trong bình a
    int t2;    // Số nước trong bình b
    int step;  // Số bước đã thực hiện

    T(int _t1, int _t2, int _step) {
        t1 = _t1;
        t2 = _t2;
        step = _step;
    }
};

int solution(int a, int b, int c) {
    queue<T> q;
    set<pair<int, int>> visited; // Để lưu các trạng thái đã thăm
    q.push(T(0, 0, 0));
    visited.insert({0, 0});

    while (!q.empty()) {
        T tmp = q.front();
        q.pop();

        // Nếu một trong hai thùng có đúng c lít nước, trả về số bước
        if (tmp.t1 == c || tmp.t2 == c) {
            return tmp.step;
        }

        vector<T> vt;
        // Đổ đầy thùng a
        vt.push_back(T(a, tmp.t2, tmp.step + 1));
        // Đổ đầy thùng b
        vt.push_back(T(tmp.t1, b, tmp.step + 1));
        // Đổ rỗng thùng a
        vt.push_back(T(0, tmp.t2, tmp.step + 1));
        // Đổ rỗng thùng b
        vt.push_back(T(tmp.t1, 0, tmp.step + 1));
        // Đổ từ thùng a sang thùng b
        int pourAtoB = min(tmp.t1, b - tmp.t2);
        vt.push_back(T(tmp.t1 - pourAtoB, tmp.t2 + pourAtoB, tmp.step + 1));
        // Đổ từ thùng b sang thùng a
        int pourBtoA = min(tmp.t2, a - tmp.t1);
        vt.push_back(T(tmp.t1 + pourBtoA, tmp.t2 - pourBtoA, tmp.step + 1));

        // Kiểm tra và thêm các trạng thái mới vào hàng đợi
        for (auto x : vt) {
            if (visited.find({x.t1, x.t2}) == visited.end()) {
                visited.insert({x.t1, x.t2});
                q.push(x);
            }
        }
    }

    return -1; // Nếu không tìm được cách
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solution(a, b, c) << endl;
    return 0;
}
