void dialogoIngresarDados(GtkWidget *window){

    GtkWidget *dialog;
    GtkWidget *vbox, *button;
    GtkWidget *hBoxDado1, *hBoxDado2, *label1, *label2;

    struct textEntries dados;

    dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width(GTK_CONTAINER(dialog),5);
    gtk_widget_set_size_request(dialog ,200, 100);
    gtk_window_set_title(GTK_WINDOW(dialog), "Dados");
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);

    vbox = gtk_vbox_new(FALSE, 0);

    label1 = gtk_label_new("Dado1");
    label2 = gtk_label_new("Dado2");
    button = gtk_button_new_from_stock(GTK_STOCK_APPLY);

    dados.entryDado1 = gtk_entry_new_with_max_length(10);
    dados.entryDado2 = gtk_entry_new_with_max_length(10);

    hBoxDado1 = gtk_hbox_new(TRUE,0);
    hBoxDado2 = gtk_hbox_new(TRUE,0);

    gtk_box_pack_start_defaults (GTK_BOX (vbox), hBoxDado1);
    gtk_box_pack_start_defaults (GTK_BOX (vbox), hBoxDado2);
    gtk_box_pack_start_defaults (GTK_BOX (vbox), button);

    gtk_box_pack_start_defaults (GTK_BOX (hBoxDado1), label1);
    gtk_box_pack_start_defaults (GTK_BOX (hBoxDado1), dados.entryDado1);

    gtk_box_pack_start_defaults (GTK_BOX (hBoxDado2), label2);
    gtk_box_pack_start_defaults (GTK_BOX (hBoxDado2), dados.entryDado2);

    gtk_container_add (GTK_CONTAINER(dialog), vbox);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(applyIngresarDados), &dados);
    g_signal_connect(G_OBJECT(dialog), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all (dialog);
}
