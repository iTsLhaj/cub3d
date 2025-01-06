#include <cub3d.h>

int check_rest(char *str, int i)
{
    int len;
    int count;

    count = 0;
    len  = ft_strlen(str) - strlen(&str[i]) + 1;
    while(str[i])
    {
        if(str[i] ==  ' ')
            count++;
        i--;
    }
    if(count == len)
        return (1);
    return (0);
}
int check_pos(char **map ,int i, int j)
{
    if(map[i + 1])
    {
        while(map[i][j])
        {
            if(map[i][j] != '1')
            {
                if((map[i][j] == '0' || map[i][j] == 'N'|| map[i][j] == 'S')
                    || map[i][j] == 'E' || map[i][j] == 'W')
                {
                    if(map[i - 1][j] == ' ')
                    {
                        return (1);
                    }
                    if(map[i + 1][j] == ' ')
                    {
                        return (1);
                    }
                    if(map[i][j + 1] ==  ' ')
                    {
                        return (1);
                    }
                    if(map[i][j - 1] == ' ')
                        return (1);
                }
            }
            j++;
        }
    }
    return (0);
}

int check_wall_len(char **map)
{
    int i;
    int j;

    i = 1;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == '1')
                j++;
            else
            {
                if(check_pos(map ,i,j))
                    return (0);
                else
                    break;
            }
        }
        i++;
    }
    return (1);
}
