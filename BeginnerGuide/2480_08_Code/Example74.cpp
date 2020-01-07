#include "Ogre\ExampleApplication.h"


class Example74 : public ExampleApplication
{
private:
	
public:

	void createScene()
	{
		Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0,0,450));
		Ogre::Entity* ent = mSceneMgr->createEntity("Sinbad.mesh");
		node->attachObject(ent);

		Ogre::CompositorManager::getSingleton().addCompositor(mCamera->getViewport(), "Compositor3");
		Ogre::CompositorManager::getSingleton().setCompositorEnabled(mCamera->getViewport(), "Compositor3", true);

		Ogre::CompositorManager::getSingleton().addCompositor(mCamera->getViewport(), "Compositor2");
		Ogre::CompositorManager::getSingleton().setCompositorEnabled(mCamera->getViewport(), "Compositor2", true);




	
	}

	
};

int main (void)
{
	Example74 app;
	app.go();
	return 0;
}
