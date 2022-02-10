
u8 arr[]={ a,a,a,b,b,c,d,e,f,b,s };

u8* fun(u8* arr,u8 arr_size)
{
	int i,flag=0;
	u8* ptr= m;
	for(i=0; i<arr_size ;i++)
	{
		
			if (arr[i]==arr[i+1])
			{
				if(flag==0)
				{
					arr2[i]=arr[i];
				}
				else
				{
					contanue;
				}
				flag++;
				
			}
			else
			{
				arr2[i]= arr[i];
				flag=0;
			}
	}
	
	return arr2;
}
