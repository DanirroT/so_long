#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

/*
 Initialize MLX space.
 Creates the connection between the program and the OS (X11 server).
 Must be called before any other mlx function.
 Return NULL if failed.
*/
void	*mlx_init(void);



/*
 Creates a new window of size_x by size_y with given title.
 Return NULL if failed.
*/
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);



/*
 Clears the window contents (fills it with black).
 Does NOT destroy images.
*/
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);


/*
 Draws a single pixel directly to the window.
 This is slow and should only be used for testing.
*/
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

/*
** Origin (0,0) is top-left corner.
** Positive y goes downward.
** Color format: 0x00RRGGBB
*/



/*
** Image stuff
*/


/*
 Allocates an image buffer of width by height.
 Image is stored in memory, not displayed.
 Return NULL if failed.
*/
void	*mlx_new_image(void *mlx_ptr, int width, int height);
/*
**  obsolete : image2 data is stored using bit planes
**  void	*mlx_new_image2(void *mlx_ptr,int width,int height);
*/

/*
 Get memory location of the first pixel of the image, using the set parameters
*/
/*
 Returns a pointer to the first byte of the image memory.
 Also fills metadata needed to interpret the image data.
*/
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
/*
** bits_per_pixel : usually 32 (4 bytes per pixel)
** size_line      : number of bytes per image row
** endian         : 0 = little endian, 1 = big endian

**  for mlx_new_image2, 2nd arg of mlx_get_data_addr is number_of_planes
*/

/*
 Displays an image to a window at position (x, y).
*/
int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

/*
 Converts a color to the correct format for the display.
 Rarely needed on Linux.
*/
int mlx_get_color_value(void *mlx_ptr, int color);


/*
** dealing with Events
*/

/*
 sets Mouse Button Hooks
 Triggered when a mouse button is pressed.
 funct mutst be: int funct(int button, int x, int y, void *param);
 	where:
		button is mouse button
		x and y are the position of the mouse
		param is a pointer to the parameters used for the function to work
*/
int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);

/*
 sets keyboard Hooks
 Triggered on key release.
 funct mutst be: int funct(int keycode, void *param);
 	where:
		keycode is mouse keycode of the key pressed
		param is a pointer to the parameters used for the function to work
*/
int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);

/*
 sets expose Hooks, aka window size changes (full screen, minimize, etc)
 funct mutst be: int funct(void *param);
 	where:
		param is a pointer to the parameters used for the function to work
*/
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);

/*
 sets a Loop Hook, a function that will execute every loop/frame
 Used for animations and continuous rendering.
 funct mutst be: int funct(void *param);
 	where:
		param is a pointer to the parameters used for the function to work
	?????
*/
int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);

/*
 Starts Function loop set by what is above
 This function blocks and does not return until program exit.
*/
int	mlx_loop (void *mlx_ptr);
/*
 Stops Function loop
*/
int mlx_loop_end (void *mlx_ptr);



/*
**  Usually asked...
*/

/*
 Writes a string to the window at position (x, y) in a set collor.
 Defoult Font is ???
 Text is drawn directly to the window, not to an image.
 Useful for debugging or HUD elements.
*/
int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

/*
 Sets the font used by mlx_string_put.
 Font name must be available to the X server.
 Rarely used in 42 projects.
*/
void mlx_set_font(void *mlx_ptr, void *win_ptr, char *name);

/*
 Creates an image from XPM data stored in memory.
 xpm_data is a NULL-terminated array of strings.
 Width and height are set by the function.
*/
void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);

/*
 Loads an XPM file and creates an image from it.
 Width and height are set by the function.
 Transparent colors defined as "None" are supported.
*/
void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

/*
 Destroys a window.
 The window must not be used after this call.
*/
int mlx_destroy_window(void *mlx_ptr, void *win_ptr);

/*
 Frees an image and its associated memory.
 The image pointer becomes invalid after this call.
*/
int mlx_destroy_image(void *mlx_ptr, void *img_ptr);

/*
 Destroys the display connection.
 Usually called before freeing mlx_ptr.
*/
int mlx_destroy_display(void *mlx_ptr);


/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/


/*
 Generic hook for any X11 event.
 Allows handling events not covered by mlx_*_hook functions.
 Requires X11 event and mask definitions.
*/
int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

/*
 Disables key auto-repeat.
 Useful when handling continuous movement manually.
*/
int	mlx_do_key_autorepeatoff(void *mlx_ptr);
/*
 Enables key auto-repeat.
 Restores default keyboard behavior.
*/
int	mlx_do_key_autorepeaton(void *mlx_ptr);
/*
 Forces synchronization with the X server.
 Rarely needed; mostly for debugging.
*/
int	mlx_do_sync(void *mlx_ptr);



/*
 Retrieves current mouse position relative to the window.
*/
int	mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);

/*
 Moves the mouse cursor to position (x, y) in the window.
*/
int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);

/*
 Hides the mouse cursor inside the window.
*/
int	mlx_mouse_hide(void *mlx_ptr, void *win_ptr);

/*
 Shows the mouse cursor inside the window.
*/
int	mlx_mouse_show(void *mlx_ptr, void *win_ptr);

/*
 Retrieves the maximum screen resolution.
 Useful to limit window size.
*/
int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);