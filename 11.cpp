#include <iostream>
#include <vector>

using namespace std;

// تعریف یک نقطه در جدول
struct Point {
    int x, y;
};

// تعریف جدول
struct Table {
    int rows, cols;
};

// تابع برای چک کردن اینکه یک نقطه در محدوده جدول قرار دارد یا خیر
bool isValid(Point p, Table table) {
    return (p.x >= 0) && (p.x < table.rows) && (p.y >= 0) && (p.y < table.cols);
}

// تابع بازگشتی برای یافتن تمام مسیرهای ممکن با طول n
void findPaths(Point current, Point destination, Table table, vector<Point> path, vector<vector<bool>>& visited, int n, vector<vector<Point>>& allPaths) {
    // اگر نقطه فعلی برابر با نقطه مقصد باشد، یک مسیر یافت شده است
    if (current.x == destination.x && current.y == destination.y) {
        // اگر طول مسیر برابر با n باشد، آن را به لیست مسیرها اضافه کن
        if (path.size() == n) {
            allPaths.push_back(path);
        }
        return;
    }

    // افزودن نقطه فعلی به مسیر
    path.push_back(current);
    visited[current.x][current.y] = true;

    // تعریف حرکات ممکن (بالا، پایین، چپ، راست)
    int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // انجام حرکات ممکن
    for (int i = 0; i < 4; i++) {
        Point next = {current.x + moves[i][0], current.y + moves[i][1]};
        
        // اگر نقطه بعدی معتبر بود و تا کنون به آنجا رفته نشده بود
        if (isValid(next, table) && !visited[next.x][next.y]) {
            findPaths(next, destination, table, path, visited, n, allPaths);
        }
    }

    // حذف نقطه فعلی از مسیر (بازگشت به حالت قبلی)
    path.pop_back();
    visited[current.x][current.y] = false;
}

int main() {
    // ورودی ابعاد جدول و مختصات نقاط شروع و مقصد
    Table table;
    Point start, end;

    cout << "Enter the number of rows: ";
    cin >> table.rows;

    cout << "Enter the number of columns: ";
    cin >> table.cols;

    cout << "Enter the starting point (x, y): ";
    cin >> start.x >> start.y;

    cout << "Enter the destination point (x, y): ";
    cin >> end.x >> end.y;

    // مشخص کردن طول مسیر
    int pathLength;
    cout << "Enter the desired path length: ";
    cin >> pathLength;

    // تعریف ماتریس بازدید
    vector<vector<bool>> visited(table.rows, vector<bool>(table.cols, false));

    // تعریف لیست مسیرها
    vector<vector<Point>> allPaths;

    // تعریف مسیر
    vector<Point> path;

    // یافتن تمام مسیرهای ممکن با طول مشخص
    findPaths(start, end, table, path, visited, pathLength, allPaths);

    // چاپ تمام مسیرها
    cout << "All Paths Found:" << endl;
    for (const auto& singlePath : allPaths) {
        for (const auto& point : singlePath) {
            cout << "(" << point.x << "," << point.y << ") ";
        }
        cout << endl;
    }

    return 0;
}
