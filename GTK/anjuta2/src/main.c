/* Descrizione: GUI Client FTP sviluppato come progetto per il corso di Reti di Calcolatori (laurea SSRI presso DTI Crema)
 * Sviluppatori: Paolo Stivanin, Filippo Roncari, Stefano Agostini.
 * Anno: 2012
 * Licenza: GNU AGPL v3 <http://www.gnu.org/licenses/agpl-3.0.html>
 * Sito web: <https://github.com/polslinux/FTPUtils> */

#include <gtk/gtk.h>
  
typedef struct {
int i;
GtkWidget *target;
} Data;

/* When "connect" button is clicked a message will appear */

static void my_func(GtkButton*, GtkWindow*); 
static void my_func2(); 
void change( GtkWidget *widget,
             Data      *data );

static void button_callback(GtkWidget* w ,gpointer data);
   
 
static void print_hello (GtkWidget *widget, gpointer data)
{
  g_print ("Connect button clicked\n");
};




int main (int argc, char *argv[]){

/* Declare widgets */
GtkWidget *window;
GtkWidget *grid;
GtkWidget *button;
GtkWidget *mybutton;
	
GtkWidget *u_name;
GtkWidget *h_name;
GtkWidget *pass;
GtkWidget *label_user;
GtkWidget *label_host;
GtkWidget *label_pass;
GtkWidget *label_my;

Data data;
data.i = 0;
    
		



	/*This is called in all GTK applications. Arguments are parsed from the command line and are returned to the application.*/
gtk_init (&argc, &argv);

/* create a new window, set its title and put it on center */
window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW (window), "FTP Client");
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
	
	
g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
gtk_container_set_border_width (GTK_CONTAINER (window), 10);
gtk_window_set_resizable(GTK_WINDOW(window), FALSE); /* window is NOT resizable */

/* Here we construct the container that is going pack our buttons */
grid = gtk_grid_new ();
gtk_grid_set_row_spacing (GTK_GRID (grid), 10);
gtk_grid_set_column_spacing (GTK_GRID (grid), 10);

/* Pack the container in the window */
gtk_container_add (GTK_CONTAINER (window), grid);

/* Add labels */
label_user = gtk_label_new("Username  ");
	label_host = gtk_label_new("Hostname  ");
		label_pass = gtk_label_new("Password  ");
			label_my = gtk_label_new("for change");
	



	/* Add hostname entry and label */
h_name = gtk_entry_new();
gtk_entry_set_placeholder_text (GTK_ENTRY (h_name), "Hostname"); /* imposto il testo trasparente che scompare quando clicco o scrivo */
gtk_grid_attach (GTK_GRID (grid), label_host, 0, 0, 1, 1);
gtk_grid_attach (GTK_GRID (grid), h_name, 1, 0, 1, 1);

/* Add username entry and label */
u_name = gtk_entry_new();
gtk_entry_set_placeholder_text (GTK_ENTRY (u_name), "Username");
gtk_grid_attach (GTK_GRID (grid), label_user, 0, 1, 1, 1);
gtk_grid_attach (GTK_GRID (grid), u_name, 1, 1, 2, 1);

/* Add password entry and label (visibility set to 0 = not visible */
pass = gtk_entry_new();
gtk_entry_set_placeholder_text (GTK_ENTRY (pass), "Password");
gtk_grid_attach (GTK_GRID (grid), label_pass, 0, 2, 1, 1);
gtk_entry_set_visibility (GTK_ENTRY (pass), 0);
gtk_grid_attach (GTK_GRID (grid), pass, 1, 2, 1, 1);

	

/* Add connect button */
button = gtk_button_new_with_label ("Connect");
g_signal_connect (button, "clicked", G_CALLBACK (my_func), NULL);
gtk_grid_attach (GTK_GRID (grid), button, 0, 3, 2, 1);

/* Add quit button */
button = gtk_button_new_with_label ("Quit");
g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

gtk_grid_attach (GTK_GRID (grid), button, 0, 4, 2, 1);


	
/* Add my Label */
gtk_grid_attach (GTK_GRID (grid), label_my, 0, 5, 2, 1);

/* Add MY button */
mybutton = gtk_button_new_with_label ("MyButton");
g_signal_connect (mybutton, "clicked", G_CALLBACK (change), &data);
data.target = label_my;

	
gtk_grid_attach (GTK_GRID (grid), mybutton, 3, 5, 1, 1);
	

/* Now that we are done packing our widgets, we show them all in one go, by calling gtk_widget_show_all() on the window.*/
gtk_widget_show_all (window);

/* All GTK applications must have a gtk_main(). Control ends here and waits for an event to occur (like a key press or a mouse event),
 * until gtk_main_quit() is called. */
gtk_main ();

return 0;
}



/* Create a new message dialog that tells the user that the button was clicked. */
static void
my_func (GtkButton *button, GtkWindow *parent)
{
GtkWidget *dialog;
dialog = gtk_message_dialog_new (parent, GTK_DIALOG_MODAL,
GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
"The button was clicked!");
gtk_window_set_title (GTK_WINDOW (dialog), "Information");
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
}



static void button_callback(GtkWidget* w ,gpointer data)
 {
   g_print ("Hello World\n");
 }


  
void change( GtkWidget *widget,
             Data      *data )
{
    gtk_label_set_text(GTK_LABEL(data->target), "it did!");
	data->i=5;
}  
