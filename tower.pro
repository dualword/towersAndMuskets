
TEMPLATE = app
TARGET = game
DEPENDPATH += . include src
INCLUDEPATH += . include

Qt -= qt
DEPENDPATH += .
INCLUDEPATH += .

LIBS += -lsfml-system -lsfml-audio -lsfml-window -lIrrlicht

HEADERS += include/AnimatedMeshComponent.h \
           include/AnimatorComponent.h \
           include/CameraComponent.h \
           include/CameraSystem.h \
           include/ComponentSystem.h \
           include/DebugValues.h \
           include/Enums.h \
           include/EventReceiver.h \
           include/FaceDirectionComponent.h \
           include/FaceDirectionSystem.h \
           include/Game.h \
           include/GameComponent.h \
           include/GameResources.h \
           include/GameState.h \
           include/GroupPathMover.h \
           include/GuiElement.h \
           include/GuiElementPurchase.h \
           include/GuiObserver.h \
           include/GuiSubject.h \
           include/HealthComponent.h \
           include/InteractionMenu.h \
           include/MapGenerator.h \
           include/NodePath.h \
           include/NoiseGenerator.h \
           include/NotificationMessage.h \
           include/ObjectFactory.h \
           include/ObjectManager.h \
           include/ObjectPlacer.h \
           include/ParticleManager.h \
           include/PathFinder.h \
           include/PathMovementComponent.h \
           include/PathMovementSystem.h \
           include/PlayerResourceCache.h \
           include/Quadtree.h \
           include/RenderComponent.h \
           include/RenderManager.h \
           include/RenderSystem.h \
           include/ResourceComponent.h \
           include/RTSAIComponent.h \
           include/RTSAISystem.h \
           include/RTSCamera.h \
           include/RTSLogicComponent.h \
           include/RTSLogicSystem.h \
           include/RTSVillagerLogicComponent.h \
           include/RTSVillagerLogicSystem.h \
           include/SelectableComponent.h \
           include/SelectionSystem.h \
           include/SpawnLocationComponent.h \
           include/StateMainMenu.h \
           include/StatePauseMenu.h \
           include/StatePlaying.h \
           include/StateWinLose.h \
           include/StaticMeshComponent.h \
           include/SteeringComponent.h \
           include/SteeringSystem.h \
           include/TeamComponent.h \
           include/TowerComponent.h \
           include/TowerDefenseEngine.h \
           include/TownhallComponent.h \
           include/TransformComponent.h \
           include/TransparentMaterialShader.h \
           include/WaveController.h \
           include/WorldManager.h

SOURCES += src/CameraSystem.cpp \
           src/DebugValues.cpp \
           src/EventReceiver.cpp \
           src/FaceDirectionSystem.cpp \
           src/Game.cpp \
           src/GameResources.cpp \
           src/GroupPathMover.cpp \
           src/GuiElement.cpp \
           src/GuiElementPurchase.cpp \
           src/InteractionMenu.cpp \
           src/Main.cpp \
           src/MapGenerator.cpp \
           src/NodePath.cpp \
           src/NoiseGenerator.cpp \
           src/NotificationMessage.cpp \
           src/ObjectManager.cpp \
           src/ObjectPlacer.cpp \
           src/ParticleManager.cpp \
           src/PathFinder.cpp \
           src/PathMovementSystem.cpp \
           src/PlayerResourceCache.cpp \
           src/Quadtree.cpp \
           src/RenderManager.cpp \
           src/RenderSystem.cpp \
           src/RTSAISystem.cpp \
           src/RTSCamera.cpp \
           src/RTSLogicSystem.cpp \
           src/RTSVillagerLogicSystem.cpp \
           src/SelectionSystem.cpp \
           src/StateMainMenu.cpp \
           src/StatePauseMenu.cpp \
           src/StatePlaying.cpp \
           src/StateWinLose.cpp \
           src/SteeringSystem.cpp \
           src/TeamComponent.cpp \
           src/TransparentMaterialShader.cpp \
           src/WaveController.cpp \
           src/WorldManager.cpp

OBJECTS_DIR = .build/obj
MOC_DIR     = .build/moc
RCC_DIR     = .build/rcc
UI_DIR      = .build/ui
