#include "App.h"




int main() {

	App* app = new App("rpn-log.txt");
	app->startUp();
	delete app;
	return 0;
}