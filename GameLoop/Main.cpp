#include "GameLoop.h"
#include "InputManager.h"
#include "IImageLoader.h"
#include "GLFW\glfw3.h"

int main() {

	int width = 200;
	int height = 200;
	int channels = 3;
	int req_comp = 0;

	IImageLoader* loader = new IImageLoader();
	loader->LoadImage("C:\\git\\Images\\LokiAssets\\LokiTeleport\\Loki_Teleport00.png", &width, &height, &channels, req_comp);
	GameLoop gameLoop(600, 400, "Test");
	gameLoop.run();
}