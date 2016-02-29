#include <StatePlaying.h>
#include <irrlicht/irrlicht.h>
#include <Game.h>
#include <sfml/SFML/Audio.hpp>
#include <sfml/SFML/Window.hpp>

using namespace irr;
using namespace core;
using namespace gui;
using namespace scene;
using namespace video;
using namespace sf;


StatePlaying::StatePlaying(std::string mapname) {
	transparentDraw = false;
	transparentUpdate = false;
	ISceneManager* smgr = Game::game.getRendMgr()->getSceneManager();
	
	objectPlacer.init();
	interactionMenu.init(128, this);
	messageDisplay.init(RenderManager::resPath + "/materials/textures/SerifFont.xml");

	loadMap(mapname);
	
	if (!bufGunshot1.loadFromFile("res/sounds/musketshot.ogg"))
		std::cout << "Sound not loaded" << std::endl;

	sndGunshot1.setBuffer(bufGunshot1);
	sndGunshot1.setRelativeToListener(false);
	sndGunshot1.setAttenuation(0.1f);
	sndGunshot1.setPosition(128, 0, 128);
	
	ObjectManager* objmgr = Game::game.getObjMgr();
}

void StatePlaying::loadMap ( std::string mapname ) {
	ISceneManager* smgr = Game::game.getRendMgr()->getSceneManager();
	
	Game::game.getObjMgr()->clearObjects();
	Game::game.getObjMgr()->worldManager->clear();
	smgr->clear();
	
	mapGenerator.generateMap(mapname);
	
	smgr->setShadowColor(video::SColor(80,0,0,0));
	smgr->setAmbientLight(SColorf(0.8f, 0.8f, 0.8f));
	vector3df lightdir = vector3df( 0.8f, -1, 0.8f ).normalize();
	ILightSceneNode* light = smgr->addLightSceneNode(0, -lightdir * 10000, SColorf(1,1,1), 100000);
	light->setLightType(video::ELT_DIRECTIONAL);
	light->getLightData().Direction = lightdir;
	
	camera.addToScene();
}

void StatePlaying::update() {
    GameState::update();
	
	camera.update();
	interactionMenu.update();
	messageDisplay.update();
	objectPlacer.update();
	Game::game.getObjMgr()->updateSystems(0);
}

void StatePlaying::render ( irr::video::IVideoDriver* driver ) {
    GameState::render ( driver );

	Game::game.getObjMgr()->drawSystems(0);
	interactionMenu.render(driver);
	messageDisplay.render(driver);
}

void StatePlaying::transitionIn() {
    GameState::transitionIn();
}

void StatePlaying::transitionOut() {
    GameState::transitionOut();
}

void StatePlaying::message ( int messageNum, std::string message ) {
	switch (messageNum) {
	case SET_PLACE_OBJECT_TOWER:
		objectPlacer.setObjectType(Tower);
		break;
	case SET_PLACE_OBJECT_TREE:
		objectPlacer.setObjectType(Tree);
		break;
	case SET_PLACE_OBJECT_ROCK:
		objectPlacer.setObjectType(Rock);
		break;
	case SET_PLACE_OBJECT_ENEMY_UNIT:
		objectPlacer.setObjectType(EnemyUnit);
		break;
	case SET_PLACE_OBJECT_PLAYER_UNIT:
		objectPlacer.setObjectType(PlayerUnit);
		break;
	case SET_PLACE_OBJECT_PLAYER_CANNON:
		objectPlacer.setObjectType(PlayerCannon);
		break;
	case SHOW_MESSAGE_GOOD:
		messageDisplay.showMessage(message, SColor(255,0,255,0));
		Game::game.resources.loadSound("goodsound.ogg")->play();
		break;
	case SHOW_MESSAGE_BAD:
		messageDisplay.showMessage(message, SColor(255,255,0,0));
		Game::game.resources.loadSound("badsound.ogg")->play();
		break;
	}
}
