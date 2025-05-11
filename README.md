Quy hoạch động trên cây

Quy hoạch động trên cây (Dynamic Programming on Trees) là một kỹ thuật phổ biến trong thuật toán để giải các bài toán tối ưu có cấu trúc cây (tree). Đây là một dạng đặc biệt của quy hoạch động, nơi mà cây là cấu trúc dữ liệu cơ bản thay vì mảng, chuỗi hoặc đồ thị thông thường.

*Cây:
Theo định lý Daisy Chain. Cụ thể:

Cho T=(V,E) là đồ thị vô hướng có n đỉnh, thì các mệnh đề sau là tương đương:

•	T là cây.

•	T không chứa chu trình và có đúng n - 1 cạnh.

•	T liên thông và mỗi cạnh của nó đều là cầu (bridge).

•	Giữa hai đỉnh bất kỳ của T tồn tại đúng một đường đi đơn.

•	T không chứa chu trình, nhưng mỗi khi thêm một cạnh vào thì sẽ tạo thành một chu trình.

•	T liên thông và có n - 1 cạnh.

Từ đây, ta có thể gọi cây gốc là T[u] với u là đỉnh gốc.

1. Cốt lõi của quy hoạch động trên cây

Trong cây, không có chu trình, nên ta có thể duyệt từ gốc xuống (hoặc ngược lại) và tính toán kết quả tại mỗi nút dựa trên các con của nó (hoặc cha của nó).

Thông thường, ta sẽ sử dụng:

•	DFS để duyệt cây.

•	Mỗi nút lưu trữ một trạng thái phụ thuộc vào các trạng thái của các nút con (trong cây con gốc tại nút đó).

•	Quy hoạch động được dùng để tránh tính toán lại các trạng thái con.

2. Cách tiếp cận tổng quát

vector<int> adj[MAXN];

int dp[MAXN];

void dfs(int u, int parent) {
    
    dp[u] = ... // khởi tạo
    
    for (int v : adj[u]) {
        
        if (v == parent) continue;
        
        dfs(v, u);
        
        dp[u] = combine(dp[u], dp[v]); // cập nhật dp[u] dựa trên dp[v]
    
    }

}

3. Các kiểu bài toán phổ biến

a. Tối đa/tối thiểu gì đó trong cây con

VD: Tổng lớn nhất trong cây con, số lượng nút nhất định, số cách chọn...

b. Tree-DP dạng "Include/Exclude"

Ví dụ: Chọn tập đỉnh độc lập (Maximum Independent Set)

→ Không chọn đỉnh kề nhau:

int dp[MAXN][2];

void dfs(int u, int p) {
    
    dp[u][0] = 0; // không chọn u
    
    dp[u][1] = 1; // chọn u
   
    for (int v : adj[u]) {
        
        if (v == p) continue;
        
        dfs(v, u);
       
        dp[u][0] += max(dp[v][0], dp[v][1]); // nếu không chọn u, có thể chọn hoặc không chọn v
        
        dp[u][1] += dp[v][0];               // nếu chọn u, không được chọn v
    
    }

}

