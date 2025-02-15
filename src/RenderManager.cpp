#include <iostream>

#include <RenderManager.h>
#include <EventReceiver.h>
#include <DebugValues.h>

using namespace std;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

std::string const RenderManager::resPath = "./res";

RenderManager::RenderManager() {

}

RenderManager::~RenderManager() {
	if (device != nullptr)
		device->drop();
}

/**
 * Initialise the Render Manager and get pointers to the various systmes
 * used by Irrlicht
 */
void RenderManager::init ( const wchar_t* caption ) {
	
	device = createDevice(video::EDT_OPENGL, dimension2d<u32>(800, 600), 16, false, DebugValues::STENCIL_ENABLED, false);
	
	if (!device) {
		cerr << "An error occurred when creating the display device :(" << endl; 
		return;
	}
	
	device->setWindowCaption(caption);
	
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guienv = device->getGUIEnvironment();
}

/**
 * Returns a pointer to the manager's IrrlichtDevice
 */
IrrlichtDevice* RenderManager::getDevice() {
	return device;
}

/**
 * Returns a pointer to the manager's IVideoDriver
 */
IVideoDriver* RenderManager::getDriver() {
	return driver;
}

/**
 * Returns a pointer to the manager's IGUIEnvironment
 */
IGUIEnvironment* RenderManager::getGUIEnvironment() {
	return guienv;
}

/**
 * Returns a pointer to the manager's ISceneManager
 */
ISceneManager* RenderManager::getSceneManager() {
	return smgr;
}

