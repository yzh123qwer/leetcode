/* 
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

说明：所有供暖器都遵循你的半径标准，加热的半径也一样。

 

示例 1:

输入: houses = [1,2,3], heaters = [2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
示例 2:

输入: houses = [1,2,3,4], heaters = [1,4]
输出: 1
解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
示例 3：

输入：houses = [1,5], heaters = [2]
输出：3
*/
void InsertSort(int Element[], int N)
{
	int j, p,i;
	int tmp;
	for (p = 1; p < N; p++)
	{
		tmp = Element[p];
		for (j = p; j > 0 && Element[j - 1] > tmp; j--)
			Element[j] = Element[j - 1];
		Element[j] = tmp;
	}
}
void ShellSort(int Element[], int N)
{
	int i, j, increment, tmp;
	for (increment = N / 2; increment != 0; increment /= 2)
	{
		for (i = increment; i < N; i++)
		{
			tmp = Element[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (tmp < Element[j - increment])
					Element[j] = Element[j - increment];
				else
					break;
			}
			Element[j] = tmp;
		}
	}
}
int findRadius(int* houses, int housesSize, int* heaters, int heatersSize)
{
    ShellSort(heaters, heatersSize);
    int house_num, heater_num;
    int R_min = 0, R;
    for (house_num = 0; house_num < housesSize; house_num++)
    {
        if (houses[house_num] <= heaters[0])
            R = heaters[0] - houses[house_num];
        else if (houses[house_num] >= heaters[heatersSize - 1])
            R = houses[house_num] - heaters[heatersSize - 1];
        else
        {
            for (heater_num = 1; houses[house_num] >= heaters[heater_num]; heater_num++);
            if (houses[house_num] - heaters[heater_num - 1] >= heaters[heater_num] - houses[house_num])
                R = heaters[heater_num] - houses[house_num];
            else
                R = houses[house_num] - heaters[heater_num - 1];
        }
        if (R > R_min)
            R_min = R;
    }
    return R_min;
}
