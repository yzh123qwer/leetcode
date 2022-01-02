/*
Alice 手中有一把牌，她想要重新排列这些牌，分成若干组，使每一组的牌数都是 groupSize ，并且由 groupSize 张连续的牌组成。

给你一个整数数组 hand 其中 hand[i] 是写在第 i 张牌，和一个整数 groupSize 。如果她可能重新排列这些牌，返回 true ；否则，返回 false 。

 

示例 1：

输入：hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
输出：true
解释：Alice 手中的牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
示例 2：

输入：hand = [1,2,3,4,5], groupSize = 4
输出：false
解释：Alice 手中的牌无法被重新排列成几个大小为 4 的组。
 

提示：

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length
*/
int min_hand(int* hand, int handSize)
{
    int i, min, min_i;
    for (i = 0; hand[i] == -1; i++);
    min = hand[i];
    min_i = i;
    for (; i < handSize; i++)
    {
        if (hand[i] != -1 && hand[i] < min)
        {
            min = hand[i];
            min_i = i;
        }
    }
    hand[min_i] = -1;
    return min;
}//选走hand中最小的数(>=0)，并将其值改变为-1（表示被选走）
bool isNStraightHand(int* hand, int handSize, int groupSize)
{
    if (handSize % groupSize != 0)
        return false;
    else if (groupSize == 1)
        return true;
    else
    {
        int group_nums = handSize / groupSize;//group_nums是一共有几个数组
        int min1, min2;
        int i, j;
        for (i = 0; i < group_nums; i++)
        {
            min1 = min2 = min_hand(hand, handSize);
            for (j = 0; j < handSize; j++)
            {
                if (hand[j] != -1 && hand[j] == min2 + 1)
                {
                    hand[j] = -1;
                    min2 = min2 + 1;
                    if (min2 == min1 + groupSize - 1)
                        break;
                    else
                        j = -1;
                }
            }
            if (min2 == min1 + groupSize - 1)
                continue;
            else
                return false;
        }
        return true;
    }
}
