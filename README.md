# Systray Icon Launcher

This is a tiny launcher which shows an icon in system tray (systray)
and runs a command or application after user clicks the icon.
Requires GTK2 libraries. To build, you'll need libgtk2.0-dev package installed.

    Usage:
      systrayicon [OPTION...]

    Help Options:
      -h, --help                        Show help options

    Application Options:
      -i, --iconfile=image              Image file to use as icon.
      -c, --command="program -args"     Command to execute.
      -t, --tooltip                     Text to display when mouse is over the icon.
                                        (optional)

