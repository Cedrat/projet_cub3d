/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 00:54:14 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/16 02:40:08 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int quit(t_img *img)
{
	free(img->dda);
	free(img->draw_sp->sp_x);
	free(img->draw_sp->sp_y);
	free(img->draw_sp->dist_to_p);
	free(img->draw_sp);
	if (img->secu->tex_e == 1)
		ft_free_textures(img->skin->E);
    if (img->secu->tex_n == 1)
    	ft_free_textures(img->skin->N);
    if (img->secu->tex_s == 1)
    	ft_free_textures(img->skin->S);
    if (img->secu->tex_w == 1)
        ft_free_textures(img->skin->W);
    if (img->secu->tex_sp == 1)
    	ft_free_textures(img->skin->Sp);
    ft_free_map(img);
    free(img->z_buffer);
    if (img->save == 0)
    {
        mlx_clear_window(img->mlx_ptr, img->mlx_wd);
        mlx_destroy_window(img->mlx_ptr, img->mlx_wd);
    }
	exit(0);
}

void ft_free_textures(t_wall *skin)
{
    size_t i;

    i = 0;
    while (i < skin->height)
    {
        free(skin->color_tab[i]);
        i++;
    }
    // mlx_destroy_image(skin->mlx_ptr, skin->img_addr);
}

void ft_free_map(t_img *img)
{
    size_t i;

    i = 0;
    while (i < img->map_heigth)
    {
        free(img->map[i]);
        i++;
    }
    free(img->map);
}
