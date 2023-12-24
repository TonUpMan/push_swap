#include "push_swap.h"

static char *ft_addspace(char *argv)
{
    char *spaced;

    spaced = ft_strjoin(argv, " ");
    return(spaced);
}
static char *ft_join(char *result, char *tmp)
{
    char    *joined;

    joined = ft_strjoin(result, tmp);
    free (result);
    free (tmp);
    return (joined);
}


char *ft_makeone(int argc, char **argv)
{
    char    *result;
    char    *tmp;
    int     i;

    i = 1;
    result = ft_calloc(1, sizeof (char));
    while (i <= (argc - 1))
    {
        tmp = ft_addspace(argv[i]);
        result = ft_join(result, tmp);
        i++;
    }
    return (result);
}