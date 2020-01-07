#include "Ogre\ExampleApplication.h"


class Example69 : public ExampleApplication
{
private:
	
public:

	void createScene()
	{
		Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Node1",Ogre::Vector3(0,0,450));
		Ogre::Entity* ent = mSceneMgr->createEntity("Entity1","Sinbad.mesh");
		node->attachObject(ent);

		Ogre::CompositorManager::getSingleton().addCompositor(mCamera->getViewport(), "Compositor1");
		Ogre::CompositorManager::getSingleton().setCompositorEnabled(mCamera->getViewport(), "Compositor1", true);


	
	}

	
};

int main (void)
{
	Example69 app;
	app.go();
	return 0;
}
