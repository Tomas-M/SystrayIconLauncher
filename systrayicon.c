#include <stdlib.h>
#include <gtk/gtk.h>

static gchar *option_iconfile = NULL;
static gchar *option_command = NULL;
static gchar *option_tooltip = NULL;

static const GOptionEntry option_entries[] = {
	{ "iconfile", 'i', 0, G_OPTION_ARG_STRING, &option_iconfile,
		"Image file to use as icon.", "image" },
	{ "command", 'c', 0, G_OPTION_ARG_STRING, &option_command,
		"Command to execute.", "\"program -args\"" },
	{ "tooltip", 't', 0, G_OPTION_ARG_STRING, &option_tooltip,
		"Text to display when mouse is over the icon.", NULL },
	{ NULL }
};

static void run_command_callback(GtkStatusIcon *icon, gpointer data)
{
	GError *error = NULL;

	if (!g_spawn_command_line_async(option_command, &error))
		g_printerr("ERROR: %s\n", error->message);
}

int main(int argc, char *argv[])
{
	GtkStatusIcon *icon;
	GOptionContext *context;
	GError *error = NULL;

	gtk_init(&argc, &argv);

	context = g_option_context_new(NULL);
	g_option_context_add_main_entries(context, option_entries, NULL);
	if (!g_option_context_parse(context, &argc, &argv, &error)) {
		g_printerr("ERROR when parsing options: %s\n", error->message);
		exit(1);
	}

	if (!option_iconfile || !option_command) {
		g_print("%s", g_option_context_get_help(context, TRUE, NULL));
		exit(1);
	}

	if (option_iconfile) {
		icon = gtk_status_icon_new_from_file(option_iconfile);
		g_signal_connect(icon, "activate",
					G_CALLBACK(run_command_callback), NULL);
		if (option_tooltip)
			gtk_status_icon_set_tooltip_text(icon, option_tooltip);
	}
	
	gtk_main();
	
	return 0;
}
