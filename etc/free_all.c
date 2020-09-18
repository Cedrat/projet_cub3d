/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 00:54:14 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/18 12:35:32 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/cub3d.h"

int		quit(t_img *img)
{
	free(img->dda);
	free(img->draw_sp->sp_x);
	free(img->draw_sp->sp_y);
	free(img->draw_sp->dist_to_p);
	free(img->draw_sp);
	ft_free_tex(img);
	free(img->secu);
	free(img->skin);
	ft_free_map(img);
	free(img->z_buffer);
	mlx_destroy_image(img->mlx_ptr, img->img);
	if (img->save == 0)
	{
		mlx_clear_window(img->mlx_ptr, img->mlx_wd);
		mlx_destroy_window(img->mlx_ptr, img->mlx_wd);
	}
	free(img->mlx_ptr);
	free(img);
	exit(0);
}

void	ft_free_textures(t_img *img, t_wall *skin)
{
	int i;

	i = 0;
	while (i < skin->height)
	{
		free(skin->color_tab[i]);
		i++;
	}
	free(skin->color_tab);
	mlx_destroy_image(img->mlx_ptr, skin->img);
}

void	ft_free_map(t_img *img)
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

void	ft_free_tex(t_img *img)
{
	if (img->secu->tex_e == 1)
		ft_free_textures(img, img->skin->e);
	if (img->secu->tex_n == 1)
		ft_free_textures(img, img->skin->n);
	if (img->secu->tex_s == 1)
		ft_free_textures(img, img->skin->s);
	if (img->secu->tex_w == 1)
		ft_free_textures(img, img->skin->w);
	if (img->secu->tex_sp == 1)
		ft_free_textures(img, img->skin->sp);
	free(img->skin->n);
	free(img->skin->s);
	free(img->skin->w);
	free(img->skin->e);
	free(img->skin->sp);
}

void	quick_quit(t_img *img)
{
	free(img->dda);
	free(img->draw_sp);
	ft_free_tex(img);
	free(img->skin);
	if (img->secu->map == 1)
		ft_free_map(img);
	free(img->secu);
	free(img->mlx_ptr);
	free(img);
	exit(0);
}
