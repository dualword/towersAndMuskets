#include <iostream>
#include <string>
#include <irrlicht.h>
#include <SFML/Window.hpp>

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <chrono>
#include <ctime>

#include <TowerDefenseEngine.h>
#include <random>
#include <SFML/Main.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace chrono;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace sf;

void runGame() {
	Game::game.init();
	Game::game.run();
	Game::game.dispose();
	
	cout << "Game Exited" << endl;
}

int main() {
	
	runGame();
	
	return 0;
}







