#include <gtk/gtk.h>

static void pass_char_array (GtkWidget *widget, gpointer data)
{
  g_print ("Value passed to callback: [%s]\n", (char *) data);
}

static void pass_int (GtkWidget *widget, gpointer data)
{
  g_print ("Value passed to callback: [%d]\n",  (int) data);
}

static void pass_int_array (GtkWidget *widget, int *array)
{
  g_print ("Values passed to callback: [%d][%d]\n", array[0], array[1]);
}


int main (int argc, char **argv)
{
  GtkWidget *window, *button, *box;

  gtk_init (&argc, &argv);

  // Create window
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  g_signal_connect (G_OBJECT (window), "destroy",G_CALLBACK (gtk_main_quit), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  box = gtk_vbox_new (FALSE, 5);
  gtk_container_add (GTK_CONTAINER (window), box);

  // First button
  button = gtk_button_new_with_label ("char array button");
  g_signal_connect (G_OBJECT(button), "clicked",
                    G_CALLBACK(pass_char_array), "test data");
  gtk_box_pack_start (GTK_BOX (box), button, TRUE, TRUE, 5);

  // now let's work on an integer array:
  int a[3] = {362,45,1789};

  // Create 2d button, then pass him only the first integer
  button = gtk_button_new_with_label ("int button");
  g_signal_connect (G_OBJECT(button), "clicked",
                    G_CALLBACK(pass_int), (gpointer)a[0]);
  gtk_box_pack_start (GTK_BOX(box), button, TRUE, TRUE, 5);

  // 3d button: pass him whole array. See callback prototype
  button = gtk_button_new_with_label ("int array button");
  g_signal_connect (G_OBJECT(button), "clicked",
                    G_CALLBACK(pass_int_array), (int*)a);
  gtk_box_pack_start (GTK_BOX (box), button, TRUE, TRUE, 5);


  gtk_widget_show_all (window);

  gtk_main ();
  return 0;
}
