///�������Ȱ�����Ӧ��������������ǾͿ���֪�������п�ȱ�ˣ�Ȼ������뵽����ѵļ���ǰN��͵��ۼ�ֵ�İ취�ͻ��뵽���㵽�ⲽҪ��0
///ֻ������������һ��������ģ�ͣ��������뵽��������Ϊ�����������ı���������һ�Σ�������˵㣬�����Ҷ˵㡣
#include<stdio.h>
#include<string.h>
int a[110100],b[110100];
int erfen(int l,int r,int zero){
    int k=b[l-1];
    while(l<r){
        int mid=(l+r)>>1;
        if(b[mid]>k+zero){///�����Ҫ�ҵ�ֵ��Ļ������Ҿ�������
            r=mid;
        }
        else{///������Ȼ�С����������һ����������¸���Ŀ�����ҵĲ����ĵ���ģ��������Ǿͻ��ҵ���һ�������ҵ��ģ����Ǽ�һ��
            l=mid+1;///�����е�ʱ����ҵ�ĩβû���꣬�������ǱȽ��Ƿ���ڣ�����ڼ�һ��������ȫ����
        }
    }
    if(b[l]-k>zero)
    l--;
    return l;
}
int main()
{
    int t,n,m,temp,zero;
    scanf("%d",&t);
    while(t--){
        zero=0;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            if(temp==0) zero++;
            else a[temp]=1;
        }
        memset(b,0,sizeof(b));
        for(int i=1;i<=m;i++){
            b[i]=b[i-1]+(!a[i]);
        }
        int maxn=0;
        for(int i=1;i<=m;i++){
            if(erfen(i,m,zero)-i+1>maxn)
                maxn=erfen(i,m,zero)-i+1;
        }
        printf("%d\n",maxn);
    }
}
