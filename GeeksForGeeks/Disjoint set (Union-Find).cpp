//link
//https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1

/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if(x == par[x]){
        return x;
    }
    return par[x] = find(par, par[x]);
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int ux = find(par, x);
    int uz = find(par, z);
    
    par[ux] = uz;
}