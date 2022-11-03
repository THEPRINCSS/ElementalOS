#include <kstdint.h>
#include <kstring.h>

size_t kstrcmp(const char * first, const char * second)
{
    if(kstrlen(first) == kstrlen(second))
    {
        for(size_t i = 0; i < kstrlen(first); i++)
        {
            if(first[i] == second[i])
                continue;
            else
                return first[i] - second[i];
        }
    }
    else
        return kstrlen(first) - kstrlen(second);
}
