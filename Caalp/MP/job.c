public class job
{
    static int i,j,temp;
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number of jobs:");
        int n=sc.nextInt();

        int p[]=new int[n+1];
        int d[]=new int[n+1];
        int slot[]=new int[n+1];

        //enter profit and deadline first
        for(i=0;i<n;i++)
        {
            p[i]=sc.nextInt();
            d[i]=sc.nextInt();
        }

        //descending order
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(p[i]<p[j])
                {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                    temp=d[i];
                    d[i]=d[j];
                    d[j]=temp;
                }
            }
        }
            

        //reverse loop
        int profit=0;
        for(i=0;i<n;i++)
        {
            for(j=d[i];j>0;j--)
            {
                if(slot[j]==0)
                {
                    slot[j]=1;
                    profit+=p[i];   
                    break;
                }
            }
        }

        System.out.println("Job Scheduling:");
        System.out.println("JOB No   PROFIT  DEADLINE  SLOT ALLOTTED");
        for (int i = 1; i <= n; i++) {
            if (slot[i] > 0)
                System.out.printf("\n   %d       %d        %d        [%d - %d]", slot[i], p[slot[i]], d[slot[i]], i - 1, i);
        }

        System.out.println("\nTotal Profit=" + profit);
        
    }
}