void Insert(MaxHeap H,ElementType item)
{
	int i;
	if(IfFull(H))
	{
		printf("FUll");
		return ;
	}
	i = ++H->Size;//H->Size表示最后一个的下表 
	for(;(H->Element[i/2]<item)&&i!=1;i=i/2)
	{
		H->Element[i]=H->Element[i/2];
	}
	H->Element[i]=item;
}
ElementType DeleteMax(MaxHeap H)
{
	int Parent,Child;
	ELementType MaxItem,temp;
	if(IsEmpty(H))
	{
		printf("Empty")
		return;
	}
	MaxItem=H->Element[1];
	temp=H->Elements[H->Size--]
	for(Parent=1;Parent*2<=H->Size;Parent=Child)
	{
		Child=Parent*2;
		if((Child!=H->Size)&&H->Elments[Child]<H->Elments[Child+1])
			child=child+1;//找到左右儿子最大的
		if(temp>=H->Elements[Child])
			break;
		else
			H->Elements[Parents]=H->Elments[Child]; 
	}
	H->Elments[Parent]=temp;
	return MaxItem;
}
