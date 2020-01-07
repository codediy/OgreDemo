#include "Ogre\ExampleApplication.h"


class Example70 : public ExampleApplication
{
private:
	
public:

	void createScene()
	{
		Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Node1",Ogre::Vector3(0,0,450));
		Ogre::Entity* ent = mSceneMgr->createEntity("Entity1","Sinbad.mesh");
		node->attachObject(ent);

		Ogre::CompositorManager::getSingleton().addCompositor(mCamera->getViewport(), "Compositor2");
		Ogre::CompositorManager::getSingleton().setCompositorEnabled(mCamera->getViewport(), "Compositor2", true);


	
	}

	
};

int main (void)
{
	Example70 app;
	app.go();
	return 0;
}
