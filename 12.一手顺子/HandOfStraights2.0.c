void InsertSort(int* a, int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0 && a[j] > tmp; j--)
            a[j + 1] = a[j];
        a[j + 1] = tmp;
    }
}
bool isNStraightHand(int* hand, int handSize, int groupSize)
{
    if (handSize % groupSize != 0)
        return false;
    else if (groupSize == 1)
        return true;
    else
    {
        int group_nums = handSize / groupSize;
        InsertSort(hand, handSize);
        int** TheGroup = (int**)malloc(sizeof(int*) * group_nums);
        int* group_pointer = (int*)malloc(sizeof(int) * group_nums);
        int i, j;
        for (i = 0; i < group_nums; i++)
        {
            group_pointer[i] = 0;
            TheGroup[i] = (int*)malloc(sizeof(int) * groupSize);
            TheGroup[i][0] = -1;
        }
        for (i = 0; i < handSize; i++)
        {
            for (j = 0; j < group_nums; j++)
            {
                if (TheGroup[j][group_pointer[j]] == -1)
                {
                    TheGroup[j][group_pointer[j]] = hand[i];
                    group_pointer[j] += 1;
                    break;
                }
                else
                {
                    if (hand[i] == TheGroup[j][group_pointer[j] - 1] + 1)
                    {
                        TheGroup[j][group_pointer[j]] = hand[i];
                        group_pointer[j] += 1;
                        break;
                    }
                    else
                    {
                        if (j == group_nums - 1)
                            return false;
                        else
                            continue;
                    }
                }
            }
        }
        return true;
    }
}
