/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:47:18 by mpernia-          #+#    #+#             */
/*   Updated: 2020/01/31 00:25:50 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tresde.h"

int main()
{
	mlx_t tresde;
	void *nokia_ptr;
	int nokia_h;
	int nokia_w;

	tresde.mlx_ptr = mlx_init(); //Inicia interfaz gráfica
	tresde.win_ptr = mlx_new_window(tresde.mlx_ptr,
									1500, 1500, "HolaMundo"); //Crea puntero ventana
									//2560, 1440 Fullscreen

	/*
	Escribo strings
	*/

	mlx_string_put(tresde.mlx_ptr, tresde.win_ptr, 50, 50,
				   0xFFFFFF, "Hola, Myung");
	mlx_string_put(tresde.mlx_ptr, tresde.win_ptr, 50, 70,
				   0xD33D3D, "Eres marico.");

	/*
	Seteo de datos de imagen y pixel por espacios en array
	*/

	set_square(&tresde);

	/*
	Seteo de imagen xpm
	*/

	nokia_ptr = mlx_xpm_file_to_image(tresde.mlx_ptr,
									  "images/nokia.xpm", &nokia_h, &nokia_w);
	mlx_put_image_to_window(tresde.mlx_ptr, tresde.win_ptr,
							nokia_ptr, 600, 300); //Put xpm en ventana

	mlx_do_key_autorepeatoff(tresde.mlx_ptr); // Apaga la repetición de teclas en KeyPressed event
	mlx_hook(tresde.win_ptr, 2, 1, key_pressed, &tresde);
	mlx_hook(tresde.win_ptr, 3, 1, key_release, &tresde);
	mlx_loop_hook(tresde.mlx_ptr, test_key, &tresde); //Regulación de acciones por segundo
	mlx_hook(tresde.win_ptr, 17, 1, exit_game, 0); // Llamado de cerrar app cuando X sea presionada

	/*
	2 = KeyPress
	3 = KeyRelease
	4 = MouseButtonPress
	5 = MouseButtonRelease
	*/

	mlx_loop(tresde.mlx_ptr); //Loop infinito para mantener la ventana
}

/*
Man de MiniLIBX:		man /usr/share/man/man3/mlx.1
					man /usr/share/man/man3/mlx_new_window.1
					man /usr/share/man/man3/mlx_pixel_put.1
					man /usr/share/man/man3/mlx_loop.1

gcc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
*/
