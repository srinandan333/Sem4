//NAME: SRINANDAN A
//SRN: PES1UG20CS596
//SEC: J

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ANY STATIC FUNCTIONS ARE UP HERE

static void table(const char *p, int n, int *t) 
{
    int a=0;
	int i=0;
    int j;
	while(p[i]!='\0')
    {
        a++;
        i++;
    }
    i=0;
	while(i<26)
    {
	    t[i]=a;
        i++;
    }
    j=0;
	while(j<a-1)
    {
	    t[p[j]%26]=a-1-j;
        j++;
    }
    t[p[a-1]%26]=a;
}

static void insert(int *q, int *top, int n)
{
    (*top)++;
    q[*top]=n;
}

static int permutations(const char *src, const char *p, int *t) 
{
    int a=0; 
    int b=0;
	int i=0;
    int k; 
    while(src[i]!='\0')
    {
        b++;
        i++;
    }
    i=0;
    while(p[i]!='\0')
    {
        a++;
        i++;
    }
	i=a-1;
	while(i<b) 
    {
		k=0;
		while((k<a)&&(p[a-1-k]==src[i-k]))
        {
		    k++;
        }
		if(k==a)
        {
		    return 1; 
        }
        else
        {
		    i=i+t[src[i]%26];
        }
	}
	return 0;
}


static int findpath(int n, int dist[][n], const connection_t connections[n][n], int s, int d)
{
    int a;
    int min;
    int time[n];
    int arr[n]; 
    int src;
    int dest;
    int prev[n];
    int visited[n];
    int i=0;
    while(i<n)
    {
        visited[i]=0;
        i++;
    }
    i=1;
    while(i<n)
    {
        time[i]=INT_MAX;
        prev[i]=-1;
        i++;
    }
    prev[0]=-1;
    src=s;
    visited[src]=1;
    time[src]=0;
    while(visited[d]==0)
    {   
        min=INT_MAX;
        a=0;
        i=0;
        while(i<n)
        {
            dest=time[src]+connections[src][i].time;
            if(dest<time[i] && visited[i]==0)
            {
                time[i]=dest;
                prev[i]=src;
            }
            if(min>time[i] && visited[i]==0)
            {
                min=time[i];
                a=i;
            }
            i++;
        }
        src=a;
        visited[src]=1;
    }
    i=0;
    while(i<n)
    {
        arr[i]=time[i];
        i++;
    }
    return arr[d];
}

static int delete(int *q, int *top)
{
    int n=q[0];
    int i=1;
    while(i<(*top)+1)
    {
        q[i-1]=q[i];
        i++;
    }
    (*top)--;
    return n;
}

static void traversal(int *q, int *top, int n, int visited[][n], const connection_t connections[][n], int i)
{
    if((*top)==-1)
    {
        return;
    }
    else
    {
        int k=delete(q, top);
        for(int j=0; j<n; j++)
        {
            if(connections[k][j].distance!=INT_MAX && connections[k][j].distance!=0 && visited[i][j]==0)
            {
                insert(q, top, j);
                visited[i][j]=1;
                traversal(q, top, n, visited, connections, i);
            }
        }
    }
}

static int partition(airport_t *a, int low, int high, int (*predicate_func)(const airport_t *, const airport_t *)) 
{
    int i=low+1;
    int j=high;
    airport_t pivot=a[low];
    while(i<=j) 
    {
        while(i<=high && predicate_func(a+i,&pivot)>0) 
        {
            i++;
        }
        while(j>low && predicate_func(a+j,&pivot)==0) 
        {
            j--;
        }
        if(i<j) 
        {
            airport_t temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    if(j!=low) 
    {
        a[low]=a[j];
        a[j]=pivot;
    }
    return j;
}

static int maximum(const airport_t *a, const airport_t *b)
{
    int i=0;
    while(i!='\0')
    {
        if(a->airport_name[i]>b->airport_name[i])
        {
            return 0;
        }
        else if(a->airport_name[i]<b->airport_name[i])
        {
            return 1;
        }
        i++;
    }
    return 1;
}

static void quicksort(airport_t *a, int low, int high, int (*predicate_func)(const airport_t *, const airport_t *)) 
{
    int j;
    if (low<high) 
    {
        j=partition(a, low, high, predicate_func);
        quicksort(a, low, j-1, predicate_func);
        quicksort(a, j+1, high, predicate_func);
    }
}

static void swap(int a, int b, int arr[])
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

static void jt(int *a, int *p, int m, int n, int *minlen, const connection_t connections[m+2][m+2], int *route)
{
    int temp;
    int i;
    int len=0;
    int routes[m+1];
    routes[0]=route[0];
    if(n==2)
    {
        int flag=0;
        for(int i=0; i<m; i++)
        {
            if(flag==0)
            {
                if(connections[routes[i]][a[i]].distance==INT_MAX)
                {
                    flag=1;
                }
                else
                {
                    len=len+connections[routes[i]][a[i]].distance;
                    routes[i+1]=a[i];
                }
            }
        }
        if(flag==0 && connections[a[m-1]][routes[0]].distance!=INT_MAX)
        {
            len=len+connections[a[m-1]][routes[0]].distance;
        }
        else
        {
            flag=1;
        }
        if(flag==0)
        {
            *minlen=len;
            int i=0;
            while(i<m+1)
            {
                route[i]=routes[i];
                i++;
            }
        }
        swap(0, 1, p);
        flag=0;
        len=0;
        for(int i=0; i<m; i++)
        {
            if(flag==0)
            {
                if(connections[routes[i]][a[i]].distance==INT_MAX)
                {
                    flag=1;
                }
                else
                {
                    len=len+connections[routes[i]][a[i]].distance;
                    routes[i+1]=a[i];
                }
            }
        }
        if(flag==0 && connections[a[m-1]][routes[0]].distance!=INT_MAX)
        {
            len=len+connections[a[m-1]][routes[0]].distance;
        }
        else
        {
            flag=1;
        }
        if(flag==0)
        {
            *minlen=len;
            int i=0;
            while(i<m+1)
            {
                route[i]=routes[i];
                i++;
            }
        }
        swap(0, 1, p);
    }
    else
    {
        i=0;
        while(i<n)
        {
            int temp=p[i];
            int j=i-1;
            while(j>=0)
            {
                p[j+1]=p[j];
                j--;
            }
            p[0]=temp;
            jt(a, p+1, m, n-1, minlen, connections, route);
            temp=p[0];
            j=1;
            while(j<=i)
            {
                p[j-1]=p[j];
                j++;
            }
            p[i]=temp;
            i++;
        }
    }
}

// YOUR SOLUTIONS BELOW

int q1(int n, const connection_t connections[n][n])
{
    int list[n];
    int top=-1;
    int visited[n][n];
    for(int i=0; i<n; i++)
    { 
        for(int j=0; j<n; j++)
        {
            visited[i][j]=0;
        }
        visited[i][i]=1;
    }
    int i=0;
    for(int i=0; i<n; i++)
    {
        top=-1;
        insert(list, &top, i);
        traversal(list, &top, n, visited, connections, i);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(visited[i][j]==0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k, const connection_t connections[n][n])
{
    int visited[n];
    int prev[n];
    int l=0;
    int o=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(connections[i][j].distance!=INT_MAX && visited[j]!=0)
            {
                prev[j]=i;
            }
        }
    }
    if(visited[dest->num_id]==1)
    {
        int q=dest->num_id;
        while(q!=src->num_id)
        {
            q=prev[q];
            l++;
        }
    }
    if(l<=k)
    {
        o=1;
    }
    return o;
}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    int list[n];
    int top=-1;
    int visited[n][n]; 
    for(int i=0; i<n; i++)
    { 
        for(int j=0;j<n;j++)
        {
            visited[i][j]=0;
        }
        visited[i][i]=1;
    }
    for(int i=0; i<n; i++)
    {
        top=-1;
        insert(list, &top, i);
        traversal(list, &top, n, visited, connections, i);
    }
    for(int i=0; i<n; i++)
    {
        if(visited[src->num_id][i]==1 && src->num_id!=i)
        {
            if(visited[i][src->num_id]==1)
            {
                return 1;
            }
        }
    }
    return 0;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *), airport_t airport_list[n])
{
    quicksort(airport_list, 0, n-1, predicate_func);
}

pair_t q5(int n, airport_t airports[n])
{
    int a=1;
    pair_t ans={-1, -1};
    quicksort(airports, 0, n-1, maximum);
    int prefix[n-1];
    for(int i=0; i<n-1; i++)
    {
        int k=0;
        int l=0;
        int flag=0;
        while(airports[i].airport_name[k]!='\0' && airports[i+1].airport_name[k]!='\0' && flag==0)
        {
            if(airports[i].airport_name[k]!=airports[i+1].airport_name[k])
            {
                flag=1;
            }
            else
            {
                l++;
            }
            k++;
        }
        prefix[i]=l;
    }
    int maxl=prefix[0];
    ans.first=airports[0].num_id;
    ans.second=airports[1].num_id;
    int i=1;
    while(i<n-1)
    {
        if(prefix[i]>maxl)
        {
            maxl=prefix[i];
            ans.first=airports[i].num_id;
            ans.second=airports[i+1].num_id;
        }
        i++;
    }
    if(maxl==0)
    {
        ans.first=-1;
        ans.second=-1;
    }
    return ans;
}

int q6(int n, int amount, const int entry_fee[n])
{
    int m=0;
    int beg=0;
    int end=n-1;
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(entry_fee[mid]>amount)
        {
            end=mid-1;
        }
        else if(entry_fee[mid]<amount)
        {   
            beg=mid+1;
            m=mid+1;
        }
        else
        {
            m=mid+1;
            beg=end+1;
        }
    }
    return m;
}

void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{
    int t[26];
    table(pat, n, t);
    int i=0;
    while(i<n)
    {
        contains[i]=permutations(airports[i].airport_name, pat, t);
        i++;
    }
}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    int route[n-1];
    int minlen=INT_MAX;
    int trip_num[n][n-1];
    int len=INT_MAX;
    int a[n-2];
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j!=i)
            {
                if(j>=i)
                {
                    trip_num[i][j-1]=j;
                }
                else
                {
                    trip_num[i][j]=j;
                }
            }
        }
    }
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n-2; i++)
        {
            a[i]=trip_num[j][i+1];
        }
        route[0]=trip_num[j][0];
        jt(a, a, n-2, n-2, &len, connections, route);
        if(len<minlen)
        {
            minlen=len;
            int l=0;
            while(l<n-1)
            {
                trip_order[l]=route[l];
                l++;
            }
        }
    }
    if(minlen==INT_MAX)
    {
        minlen=-1;
    }
    return minlen;
}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    int edge=0;
    int visited[n];
    int i=0;
    int r;
    int c;
    while(i<n)
    {
        visited[i]=0;
        i++;
    }
    visited[0]=1;
    int time=0;
    while(edge<n-1)
    {
        int min=INT_MAX;
        r=0;
        c=0;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==1)
            {
                for(int j=0; j<n; j++)
                {
                    if(visited[j]==0 && connections[i][j].time!=INT_MAX)
                    {
                        if(min>connections[i][j].time)
                        {min=connections[i][j].time;
                        r=i;
                        c=j;
                        }
                    }
                }
            }
        }
        time=time+min;
        visited[c]=1;
        edges[edge].first=r;
        edges[edge].second=c;
        edge++;
    }
    return time;
}

void q10(int n, int k, const airport_t *src, const connection_t connections[n][n], const int destinations[k], int costs[k])
{
    int dist[n][n];
    int i=0;
    while(i<k)
    {       
        costs[i]=findpath(n,dist,connections,src->num_id, destinations[i]);
        i++;
    }
}

// END