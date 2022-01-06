/*
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true
*/
bool isValid(char * s){
    struct stack{
        char prenthese;
        struct stack* last;
        struct stack* next;
    };
    struct stack *stacks = (struct stack*)malloc(sizeof(struct stack));
    struct stack *stacks_void = (struct stack*)malloc(sizeof(struct stack));//第一个栈不存储信息
    stacks->last = stacks_void;
    stacks_void->next = stacks;
    stacks->prenthese = s[0];
    struct stack *tmp;
    int i_s;
    for (i_s = 1; s[i_s] != '\0'; i_s++){
        if (s[i_s] == '(' || s[i_s] == '[' || s[i_s] == '{'){
            stacks->next = (struct stack*)malloc(sizeof(struct stack));
            stacks->next->last = stacks;
            stacks = stacks->next;
            stacks->prenthese = s[i_s];
        }
        else if (s[i_s] == ')'){
            if (stacks->prenthese == '('){
                stacks = stacks->last;
                free(stacks->next);
                continue;
            }
            else{
                return false;
            }
        }
        else if (s[i_s] == ']'){
            if (stacks->prenthese == '['){
                stacks = stacks->last;
                free(stacks->next);
                continue;
            }
            else{
                return false;
            }
        }
        else{
            if (stacks->prenthese == '{'){
                stacks = stacks->last;
                free(stacks->next);
                continue;
            }
            else{
                return false;
            }
        }
    }
    if (stacks == stacks_void)
        return true;
    else
        return false;
}
