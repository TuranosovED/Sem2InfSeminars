#include "ShellSort.h"
#include "lines.h"
int main()
{
    arrayConfig array = DataRead();
    ShellSort(&array);
    print(&array);
    printf("%s",ReadStr());
    return 0;
}