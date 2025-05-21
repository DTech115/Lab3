#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

int main()
{
	ALLEGRO_DISPLAY* Screen = NULL;
	if (!al_init())
	{
		al_show_native_message_box(NULL, "Error!", "Allegro has failed to initialize.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
			return -1;
	}
	int width = 800, height = 600;
	Screen = al_create_display(width, height);
	if (Screen == NULL)
	{
		al_show_native_message_box(Screen, "Error!", "Failed to create the display.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
			return -1;
	}

	bool draw = false;
	bool done = false;

	int xCord = width;
	int yCord = height;

	ALLEGRO_EVENT_QUEUE* eventQueue = NULL;

	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();


	al_destroy_display(Screen);
	return 0;
}