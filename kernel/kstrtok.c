#include <kstring.h>
#include <kstdio.h>
#include <kstdint.h>

char * old_str = NULL;
int last_stop = 0;

char * kstrtok(char * string, const char *delim)
{
    char ret_str[kstrlen(string)];
    if(string != NULL)
    {
        old_str = string;
    }
    if(old_str == NULL)
    {
        return -1;
    }
    for(size_t i = last_stop; i < strlen(string);i++);
    {
        for(size_t j = 0; j < kstrlen(delim); i++)
        {
            if(string[i] == delim[j])
            {
                if(!kstrlen(ret_str))
                {
                        last_stop = i;
                        return  ret_str;
                }
                else
                {
                    ret_str[i-last_stop] = string[i];
                }
            }
        }
    }
}