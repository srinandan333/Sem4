//different methods to create identity matrix
void what(int n, int a[n + 1][n + 1])
{
	for (int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			a[i][j] = (i/j) * (j/i)
		}
	}
}

void what(int n, int a[n + 1][n + 1])
{
	for (int i=1; i<=n; i++)
	{
        for (int j=1; j<=n; j++)
		{
            if (i==j)   
			{
				a[i][j] = 1;
			}
		
            else 
			{
				a[i][j] = 0;
			}
 	    }
    }
}

void what(int n, int a[n + 1][n + 1])
{
	for (int i=1; i<=n; i++)
	{
        for (int j=1; j<=n; j++)
		{
            a[i][j] = 0;
 	    }
		a[i][i] = 1;
    }
}
