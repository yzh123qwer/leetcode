/*
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。

请注意，返回的 规范路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。

 

示例 1：

输入：path = "/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。 
示例 2：

输入：path = "/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根目录是你可以到达的最高级。
示例 3：

输入：path = "/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：

输入：path = "/a/./b/../../c/"
输出："/c"
*/
char* simplifyPath(char* path) {
    struct path_name {
        char file_name[100];
        int file_nums;//文件名称的长度
    };
    struct path_name path_names[100];//路径中包含最多100个文件名称
    int i_path, i_path_name, i, j;
    i_path_name = 0;
    for (i_path = 0; path[i_path] != '\0'; i_path++) {
        if (path[i_path + 1] == '/')
            continue;
        else if (path[i_path + 1] == '.') {
            if (path[i_path + 2] == '.') {
                if (path[i_path + 3] == '.') {
                    for (i = 0, i_path++; path[i_path] != '/' && path[i_path] != '\0'; i++, i_path++)
                    path_names[i_path_name].file_name[i] = path[i_path];
                    path_names[i_path_name].file_name[i] = '\0';
                    path_names[i_path_name].file_nums = i;
                    i_path_name++;
                    i_path--;
                    continue;
                }
                else if (path[i_path + 3] == '/') {
                    if (i_path_name == 0) {
                        i_path = i_path + 2;
                        continue;
                    }
                    else {
                        i_path_name--;
                        continue;
                    }
                }
                else if (path[i_path + 3] == '\0') {
                    if (i_path_name == 0)
                        break;
                    else {
                        i_path_name--;
                        break;
                    }
                }
                else {
                    for (i = 0, i_path++; path[i_path] != '/' && path[i_path] != '\0'; i++, i_path++)
                        path_names[i_path_name].file_name[i] = path[i_path];
                    path_names[i_path_name].file_name[i] = '\0';
                    path_names[i_path_name].file_nums = i;
                    i_path_name++;
                    i_path--;
                    continue;
                }
            }
            else if (path[i_path + 2] == '/') {
                i_path = i_path + 1;
                continue;
            }
            else if (path[i_path + 2] == '\0')
                break;
            else {
                for (i = 0, i_path++; path[i_path] != '/' && path[i_path] != '\0'; i++, i_path++)
                    path_names[i_path_name].file_name[i] = path[i_path];
                path_names[i_path_name].file_name[i] = '\0';
                path_names[i_path_name].file_nums = i;
                i_path_name++;
                i_path--;
                continue;
            }
        }
        else if (path[i_path + 1] == '\0')
            break;
        else {
            for (i = 0, i_path++; path[i_path] != '/' && path[i_path] != '\0'; i++, i_path++)
                path_names[i_path_name].file_name[i] = path[i_path];
            path_names[i_path_name].file_name[i] = '\0';
            path_names[i_path_name].file_nums = i;
            i_path_name++;
            i_path--;
            continue;
        }
    }
    if (i_path_name == 0) {
        char* char_return = "/";
        return char_return;
    }
    else {
        int return_size = 0;
        for (i = 0; i < i_path_name; i++)
            return_size = return_size + path_names[i].file_nums + 1;
        char* return_char = (char*)malloc(sizeof(char) * (return_size + 1));
        int i_return_char = 0;
        for (i = 0; i < i_path_name; i++) {
            return_char[i_return_char++] = '/';
            for (j = 0; j < path_names[i].file_nums; j++, i_return_char++)
                return_char[i_return_char] = path_names[i].file_name[j];
        }
        return_char[return_size] = '\0';
        return return_char;
    }
}
