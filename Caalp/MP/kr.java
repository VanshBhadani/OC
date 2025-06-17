import java.util.*;

public class kr
{
     //start main program
    public static void main(String args[])
    {
    int u,v,i,j,a,b,ne=1;
    int min,mincost=0;
    
        //initialize n
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number of vertices:");
        int n= sc.nextInt();

         int cost[][]=new int[n+1][n+1];
         int vis[]=new int[n+1];

        //enter adjacency matrix
        System.out.println("Enter adjacency matrix:");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cost[i][j]=sc.nextInt();
                if(cost[i][j]==0)
                {
                    cost[i][j]=999;
                }
            }
        }

        //initialize visited vertex
        for(i=0;i<n;i++)
        {
            vis[i]=0;
        }
        vis[1]=1;

        //prim algorithm
        while(ne<n)
        {
            min=999;
            a=b=u=v=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(cost[i][j]<min)
                    {
                        if(vis[i]!=0)
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
            if(vis[u]==0 || vis[v]==0)
            {
                mincost+=min;
                ne++;
                System.out.println("Edge " + ne + ": (" + a + ", " + b + ") Cost: " + min);
                vis[b]=1;
            }
             cost[a][b]=cost[b][a]=999;
        }
        System.out.println("Minimim cost:"+mincost);
    }
}
