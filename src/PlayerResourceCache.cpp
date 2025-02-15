#include <PlayerResourceCache.h>
#include <ObjectManager.h>
#include <Game.h>
#include <list>
#include <ResourceComponent.h>

using namespace std;

void PlayerResourceCache::init ( int stone, int gold, int wood ) {
	this->stone = stone;
	this->gold = gold;
	this->wood = wood;
}

int PlayerResourceCache::getGold() {
	return gold;
}

int PlayerResourceCache::getStone() {
	return stone;
}

int PlayerResourceCache::getWood() {
	return wood;
}

void PlayerResourceCache::spend ( int stone, int gold, int wood ) {
	if (canAfford(stone, gold, wood)) {
		this->stone -= stone;
		this->gold -= gold;
		this->wood -= wood;
	}
}

bool PlayerResourceCache::canAfford ( int stone, int gold, int wood ) {
	return (getStone() >= stone && getGold() >= gold && getWood() >= wood);
}

void PlayerResourceCache::update() {
	
}

void PlayerResourceCache::gatherGold() {
	gold += gatherUnit;
}

void PlayerResourceCache::gatherStone() {
	stone += gatherUnit;
}

void PlayerResourceCache::gatherWood() {
	wood += gatherUnit;
}
