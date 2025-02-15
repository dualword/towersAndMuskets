#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include <irrlicht.h>
#include <Quadtree.h>

/**
 * Stores the grid representation of the world with methods for checking if
 * sections of the grid are passable, or if an object is colliding with it
 */
class WorldManager {
private:
	// Pointer to the grid
	short *grid;
	
	// Rectangle boundary of the edges of the world
	irr::core::recti worldBounds;
	
	/**
	 * Sets the value of the grid at an x and y location
	 */
	void setGridXY(int x, int y, short val);
	
	/**
	 * Gets the value of the grid at an x and y location
	 */
	int getGridXY(int x, int y);
	
	/**
	 * Gets the height of the terrain at a given location
	 */
	float terrainHeight(float x, float y);
	
	/**
	 * Used by other objects for querying distances to each other
	 */
	Quadtree* positionTree;
public:
	
	// The width of the grid
	int gridWidth;
	
	// The height of the grid
	int gridHeight;
	
	// The size of each grid square
	float gridSize;
	
	/**
	 * Initialises the grid
	 */
	WorldManager(float gridSize);
	
	/**
	 * Sets a rectangle area of the grid as either passable or impassable
	 */
	void setPassable(irr::core::rectf bounds, bool passable);
	
	/**
	 * Checks if a position in the world is passable on the grid
	 */
	bool checkPassable(irr::core::vector3df worldPosition);
	
	/**
	 * Checks if a position in the world is passable on the grid using
	 * actual grid coordinates
	 */
	bool checkPassableGridCoords(int x, int y);
	
	/**
	 * Checks if a rectangle area is colliding with the world
	 */
	bool checkColliding(irr::core::rectf bounds);
	
	/**
	 * Checks if a circular area is colliding with the world
	 */
	bool checkColliding(irr::core::vector3df worldPosition, float rad);
	
	/**
	 * Draws the world grid for debugging
	 */
	void draw(float timestep);
	
	void dropWorld(); // Delete grid
	
	/**
	 * Clears all grid squares
	 */
	void clear();
	
	void setTerrainData(irr::scene::ITerrainSceneNode* terrain);
	
	/**
	 * Update the object position quadtree
	 */
	void update();
	
	/**
	 * Returns the nearest object with a different team to the one specified
	 */
	int getNearestNotOnTeam(int id);
	
	/**
	 * Use as a comparison for ensuring an object is on a different team
	 */
	static bool onDifferentTeam(int queryID, int otherID);
	
	irr::core::recti getWorldBounds();
	irr::core::rectf getWorldBoundsF();
};

#endif

