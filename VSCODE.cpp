void Dijkstra(Graph C,int D,)
{
	for(int i=0;i<n;i++)
	{
		D[i] = C[0][i];
		if(C[0][i]!=INF)
			Path[i] = 0;
		else
			Path =-1;
	}
	for(int i=0;i<n-1;i++)
	{
		int min_j = MINCOST(D,S);
		S[min_j] =  true;
		for(int j=0;j<n;j++)
		{
			if(!S[j]&&D[min_j]+C[min_j][j]<D[min_j])
				D[min_j]=D[min_j]+C[min_j][j];
				Path[j] = min_j;
		}
	}
}