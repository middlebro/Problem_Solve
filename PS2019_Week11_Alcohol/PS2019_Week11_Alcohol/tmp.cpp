//#include<iostream>
//#include<vector>
//using namespace std;
//
//long long int Layer(long long int L) {// L층의 끝번호(잔 개수) 반환
//    long long int sum = 0;
//    for (int i = 1; i <= L; i++) {
//        for (int j = 1; j <= i; j++) {
//            sum += 1;
//        }
//    }
//    return sum;
//}
//
//class Node {
//public:
//    long long int amount = 0;
//    int floor;
//    int num;
//    int line;   //그 층에서 몇번째 줄에 있는건지
//    Node(int f, int n, int li) {
//        floor = f;
//        num = n;
//        line = li;
//    }
//};
//
//class Tree {
//public:
//    Node*root;
//    long double full = 1;
//    vector<Node*> nodelist;
//    Tree(int f) {   //몇층인지 입력받음 -> 해당 층까지만 벡터로 만들고 그 다음층부터는 버림
//        
//        for (int i = 1; i <= f; i++) {//층
//            full *= 3;
//            int s = 1;
//            for (int j = 1; j <= i; j++) {//라인
//                for (int k = 1; k <= j; k++) {//번호
//                    nodelist.push_back(new Node(i, s, j));
//                    s++;
//                }
//            }
//        }
//        root = nodelist[0];
//        //찾고자 하는 층까지 소주 잔 벡터 만들어놓음
//        //접근인덱스 : L층, N번 접근하려면 L-1층 까지 Layer값 다 더하고, N더하고 1빼면 됨
//    }
//    
//    int Index(int f, int n) {   //소주잔 위치에 해당하는 nodelist 인덱스값 반환
//        int sum = 0;
//        for (int i = 1; i <= f - 1; i++) {
//            sum += Layer(i);
//        }
//        return sum + n - 1;
//    }
//    
//    void Insert(Node * start, long long int rem) {   //한잔을 부음
//        //시작 노드, 남은 양(처음에 root, full로 들어올거)
//        if (start->amount + rem <= full) {//남은거 다 붓고 안넘친 상태
//            start->amount += rem;
//            return;   //종료
//        }
//        else { //남은거 다 못부어서 넘치는 상태(애초에 꽉차있던 상황 포함)
//            start->amount = full;
//            rem -= full - start->amount;   //남은양 계산 완료
//            
//            if (Index(start->floor + 1, 1) > nodelist.size() - 1) {//인덱스 만들어놓은것보다 크게 잡혔을때(start의 다음 층이 기준임)
//                return;   //굳이 찾고자하는 층의 다음층을 계산할 필요 없음
//            }
//            else {   //인덱스로 접근가능
//                Insert(nodelist[Index(start->floor + 1, start->num)], rem / 3);
//                Insert(nodelist[Index(start->floor + 1, start->num + start->line)], rem / 3);
//                Insert(nodelist[Index(start->floor + 1, start->num + start->line + 1)], rem / 3);
//            }
//        }
//    }
//    
//    void printAnswer(int f, int n) {   //f, n노드 답 출력
//        if (nodelist[Index(f, n)]->amount == 0)cout << 0 << endl;
//        else if (nodelist[Index(f, n)]->amount == full)cout << 1 << endl;
//        else cout << 2 << endl;
//    }
//};
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    int T;
//    cin >> T;
//    while (T--) {//testcase
//        long long int B, L, N;
//        cin >> B >> L >> N;   //소주병, 잔의 층, 위치
//        long long int jan = 7 * B;   //소주잔 양
//        Tree naksu(L);   //층 입력
//        for (int i = 0; i < jan; i++) {   //잔 붓기(7*B잔)
//            naksu.Insert(naksu.root, naksu.full);
//        }
//        naksu.printAnswer(L, N);
//    }//testcase
//    return 0;
//}
