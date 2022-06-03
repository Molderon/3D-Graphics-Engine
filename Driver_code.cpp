#include "Resources.h"

/*
	There's still a lot to be done.
	1. Camera Movement
	2. Optimization
	3. Optimization...
	4. More Colors?
*/

void to_load(to_render& object) {
	string query;
	cout << "What would you like to Render?\n\n";
	cout << "	1. Space Craft\n	2.Cube\n";
	cout << "Enter Object->";

	cin >> query;
	if (query == "Space Craft" || query == "space craft" || query == "1") { object = Space_Craft; }
	else if (query == "Cube" || query == "cube" || query == "2") { object = Cube; }
	cin.clear();
}


int main()
{
	to_load(object);
	
	olcEngine3D Graphic;
	if (Graphic.ConstructConsole(256, 240, 4, 4)) {
		Graphic.Start();
	}

	return 0;
}