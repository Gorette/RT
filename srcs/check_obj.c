/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:26:28 by axbal             #+#    #+#             */
/*   Updated: 2019/03/21 14:26:30 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		assign_func(t_obj *o)
{
	if (o->type == PLANE)
		o->norm = NULL;
	if (o->type == SPHERE)
		o->norm = &sphere_norm;
	if (o->type == CYLINDER)
		o->norm = &cylinder_norm;
	if (o->type == CONE)
		o->norm = &cone_norm;
	return (1);
}

int		expected_result2(t_obj *obj)
{
	if (obj->type == CUBE)
	{
		if (obj->pos_c == 1 && obj->size_c == 1)
			return (1);
	}
	if (obj->type == SQUARE)
	{
		if (obj->pos_c == 1 && obj->size_c == 1 && obj->rotation_c == 1)
			return (1);
	}
	return (-2);
}

int		expected_result(t_obj *obj)
{
	if (obj->type_c == 0)
		return (0);
	if (obj->type == SPHERE)
	{
		if (obj->pos_c == 1 && obj->radius_c == 1)
			return (assign_func(obj));
	}
	if (obj->type == CYLINDER)
	{
		if (obj->pos_c == 1 && obj->radius_c == 1 && obj->rotation_c == 1)
			return (assign_func(obj));
	}
	if (obj->type == CONE)
	{
		if (obj->pos_c == 1 && obj->angle_c == 1 && obj->rotation_c == 1)
			return (assign_func(obj));
	}
	if (obj->type == PLANE)
	{
		if (obj->pos_c == 1 && obj->rotation_c == 1)
			return (assign_func(obj));
	}
	return (expected_result2(obj));
}

int		compare_string_to_values2(char *f, int s, t_obj *new)
{
	if (ft_strncmp(f + s, "rlim_z(", 7) == 0)
		return (get_object_rlim_z(f, s, new));
	if (ft_strncmp(f + s, "size(", 5) == 0)
		return (get_object_size(f, s, new));
	if (ft_strncmp(f + s, "shiny", 5) == 0)
		new->shiny = 1;
	if (ft_strncmp(f + s, "neg", 3) == 0)
		new->neg = 1;
	else if (ft_strncmp(f + s, "sinus", 5) == 0)
		new->d1 = 1;
	else if (ft_strncmp(f + s, "squared", 7) == 0)
		new->d2 = 1;
	else if (ft_strncmp(f + s, "checkered", 9) == 0)
		new->d3 = 1;
	else if (ft_strncmp(f + s, "transparent", 11) == 0)
		return (get_object_refraction(f, s, new));
	return (-1);
}

int		compare_string_to_values(char *f, int s, t_obj *new)
{
	if (ft_strncmp(f + s, "type(", 5) == 0)
		return (get_object_type(f, s, new));
	else if (ft_strncmp(f + s, "mirror(", 7) == 0)
		return (get_object_mirror(f, s, new));
	else if (ft_strncmp(f + s, "pos(", 4) == 0)
		return (get_object_pos(f, s, new));
	else if (ft_strncmp(f + s, "radius(", 7) == 0)
		return (get_object_rad(f, s, new));
	else if (ft_strncmp(f + s, "angle(", 6) == 0)
		return (get_object_angle(f, s, new));
	else if (ft_strncmp(f + s, "rotation(", 9) == 0)
		return (get_object_rot(f, s, new));
	else if (ft_strncmp(f + s, "color(", 6) == 0)
		return (get_object_color(f, s, new));
	else if (ft_strncmp(f + s, "plim_x(", 7) == 0)
		return (get_object_lim_x(f, s, new));
	else if (ft_strncmp(f + s, "plim_y(", 7) == 0)
		return (get_object_lim_y(f, s, new));
	else if (ft_strncmp(f + s, "plim_z(", 7) == 0)
		return (get_object_lim_z(f, s, new));
	else if (ft_strncmp(f + s, "rlim_x(", 7) == 0)
		return (get_object_rlim_x(f, s, new));
	else if (ft_strncmp(f + s, "rlim_y(", 7) == 0)
		return (get_object_rlim_y(f, s, new));
	return (compare_string_to_values2(f, s, new));
}
