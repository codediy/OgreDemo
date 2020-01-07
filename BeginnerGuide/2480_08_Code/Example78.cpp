#include "Ogre\ExampleApplication.h"



class CompositorListener1 : public Ogre::CompositorInstance::Listener
{
public:

	void notifyMaterialSetup (uint32 pass_id, MaterialPtr &mat)
	{
		mat->getBestTechnique()->getPass(pass_id)->getFragmentProgramParameters()->setNamedConstant("numpixels",125.0f);
	}
};


class Example78 : public ExampleApplication
{
private:
	CompositorListener1* compListener;
public:

	~Example78()
	{
		delete compListener;
	}

	void createScene()
	{
		Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0,0,450));
		Ogre::Entity* ent = mSceneMgr->createEntity("Sinbad.mesh");
		node->attachObject(ent);

		Ogre::CompositorManager::getSingleton().addCompositor(mCamera->getViewport(), "Compositor8");
		Ogre::CompositorManager::getSingleton().setCompositorEnabled(mCamera->getViewport(), "Compositor8", true);

		Ogre::CompositorInstance* comp =  Ogre::CompositorManager::getSingleton().getCompositorChain(mCamera->getViewport())->getCompositor("Compositor8");
		compListener = new CompositorListener1();
		comp->addListener(compListener);


	}

	
};

int main (void)
{
	Example78 app;
	app.go();
	return 0;
}
