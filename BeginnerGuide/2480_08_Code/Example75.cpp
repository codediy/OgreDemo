#include "Ogre\ExampleApplication.h"


class Example75 : public ExampleApplication
{
private:
	
public:

	void createScene()
	{
		Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0,0,450));
		Ogre::Entity* ent = mSceneMgr->createEntity("Sinbad.mesh");
		node->attachObject(ent);

		Ogre::CompositorManager::getSingleton().addCompositor(mCamera->getViewport(), "Compositor6");
		Ogre::CompositorManager::getSingleton().setCompositorEnabled(mCamera->getViewport(), "Compositor6", true);


	}

	
};

int main (void)
{
	Example75 app;
	app.go();
	return 0;
}
