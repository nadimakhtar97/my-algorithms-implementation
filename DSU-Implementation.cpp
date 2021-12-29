class DisjointSet {
    public:

    vector<int> parent;
    vector<int> rank;

    DisjointSet(int maxSize) {

        parent.resize(maxSize);
        size.resize(maxSize);

        for (int i = 0; i < maxSize; i++) {
            parent[i] = -1;
            size[i] = 1;
        }
    }

    int find_set(int v) {

        if (parent[v] == -1)
            return v;

        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) {

        int s1 = find_set(a);
        int s2 = find_set(b);

        if (s1 != s2) {
            
            if(rank[s1] > rank[s2]){
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
            else{
                parent[s1] = s2;
                rank[s2] = rank[s1];
            }
        }
    }
};