SYSTRAYICON_CFLAGS	:= `pkg-config --cflags gtk+-2.0`
SYSTRAYICON_LDFLAGS	:= `pkg-config --libs gtk+-2.0`
SYSTRAYICON_OBJECTS	:= systrayicon.o
CFLAGS	:= -Wall $(SYSTRAYICON_CFLAGS)

all: $(SYSTRAYICON_OBJECTS)
	$(CC) -o systrayicon $(SYSTRAYICON_OBJECTS) $(SYSTRAYICON_LDFLAGS)

clean:
	rm $(SYSTRAYICON_OBJECTS)

