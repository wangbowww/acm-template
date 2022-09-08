const int maxlen=1e2+3;
const int maxn = 4e4+3;
class Trie {
public:
    int root,L;
    int f[maxn*maxlen][26],end[maxn*maxlen];
    int fail[maxn*maxlen];
    int newnode(){
        for(int i=0;i<26;++i){
            f[L][i] = -1;
        }
        end[L++] = 0;
        return L-1;
    }
    Trie() {
        L = 0;
        root = newnode();
    }
    void insert(string word) {
        int now = root;
        int len = word.size();
        for(int i=0;i<len;++i){
            if(f[now][word[i]-'a']==-1){
                f[now][word[i]-'a'] = newnode();
            }
            now = f[now][word[i]-'a'];
        }
        end[now]++;
    }
    bool search(string word) {
        int len = word.size();
        int now = root;
        for(int i=0;i<len;++i){
            if(f[now][word[i]-'a']==-1){
                return false;
            }
            now = f[now][word[i]-'a'];
        }
        if(end[now]) return true;
        else return false;
    }
    bool startsWith(string prefix) {
        int len = prefix.size();
        int now = root;
        for(int i=0;i<len;++i){
            if(f[now][prefix[i]-'a']==-1){
                return false;
            }
            now = f[now][prefix[i]-'a'];
        }
        return true;
    }
    void build(){
        queue<int>Q;
        fail[root] = root;
        for(int i=0;i<26;++i){
            if(f[root][i]==-1){
                f[root][i] = root;
            }else{
                fail[f[root][i]] = root;
                Q.push(f[root][i]);
            }
        }
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            for(int i=0;i<26;++i){
                if(f[now][i]==-1){
                    f[now][i] = f[fail[now]][i];
                }else{
                    fail[f[now][i]] = f[fail[now]][i];
                    Q.push(f[now][i]);
                }
            }
        }
    }
    int ask(string word){
        int len = word.size();
        int now = root;
        int res=0;
        for(int i=0;i<len;++i){
            now = f[now][word[i]-'a'];
            int temp = now;
            while(temp!=root){
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
};
