#include <cub3d.h>

static void mlx_put_pixel_(t_game *game, int x, int y, int color)
{
    if (x < 0)
        return ;
    else if (x >= WIN_WIDTH)
        return ;
    else if (y < 0)
        return ;
    else if (y >= WIN_HEIGHT)
        return ;
    pixel_put(game, x, y, color);
}

static int  get_color(t_game *game, t_ray *ray)
{
    (void)game;
    ray->angle = normalize_angle(ray->angle);
    if (ray->side == 0)
    {
        if (ray->angle > M_PI / 2 && ray->angle < 3 * (M_PI / 2))
            return (0);
        else
            return (1);
    }
    else
    {
        if (ray->angle > 0 && ray->angle < M_PI)
            return (2);
        else
            return (3);
    }
}
void    my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int get_pixel_image(t_img *img, int x, int y)
{
    char *dst;

    dst = (img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8)));

    return(*(unsigned int*)dst);
}
static void draw_wall(t_game *game, t_ray *ray, int s_pix, int e_pix, double w_height)
{
    int color;
    int x;
    int y;
    // t_img img;
    
    // img.img = game->img;
    // img.addr = game->addr;
    // img.bits_per_pixel = game->bpp;
    // img.size_line = game->line_len;
    // img.endian = game->endian;
    // printf("x: %f, y: %f\n", ray->wall_hit_x, ray->wall_hit_y);
    if(ray->side)
    {
        x = (int)ray->wall_hit_x % 64;
    }
    else
        x = (int)ray->wall_hit_y % 64;
    while (s_pix < e_pix)
    {
        y = (s_pix -((WIN_HEIGHT - w_height) / 2)) * (64 / w_height);
        // printf("x: %i, y: %i\n", x, y);
        color = get_pixel_image(game->texture_buffer[get_color(game, ray)],x,y);
        mlx_put_pixel_(game, ray->index, s_pix, color);
        s_pix++;
    }
}

static void draw_floor_ceiling(t_game *game, t_ray *ray, int s_pix, int e_pix)
{
    int i;

    i = e_pix;
    while (i < WIN_HEIGHT)
        mlx_put_pixel_(
            game,
            ray->index,
            i++,
            COLOR_FLOOR
        );
    i = 0;
    while (i < s_pix)
        mlx_put_pixel_(
            game,
            ray->index,
            i++,
            COLOR_CEILING
        );
}

void    render_wall(t_game *game, t_ray *ray)
{
    double  wall_height;
    double  e_pix;
    double  s_pix;

    ray->wall_dist *= cos(normalize_angle(ray->angle - game->player->angle_dir)); // fix the fisheye
    wall_height = (TILE_SIZE / ray->wall_dist) * ((WIN_WIDTH / 2) / tan(FOV_RD / 2)); // get the wall height
    e_pix = (WIN_HEIGHT / 2) + (wall_height / 2); // get the bottom pixel
    s_pix = (WIN_HEIGHT / 2) - (wall_height / 2); // get the top pixel
    if (e_pix > WIN_HEIGHT) // check the bottom pixel
        e_pix = WIN_HEIGHT;
    if (s_pix < 0) // check the top pixel
        s_pix = 0;
    draw_wall(game, ray, s_pix, e_pix , wall_height); // draw the wall
    draw_floor_ceiling(game, ray, s_pix, e_pix); // draw the floor and the ceiling
}
