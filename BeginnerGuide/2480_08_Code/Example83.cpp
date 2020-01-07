#include "Ogre\ExampleApplication.h"


class CompositorListener2 : public Ogre::CompositorInstance::Listener
{
public:

	void notifyMaterialSetup (uint32 pass_id, MaterialPtr &mat)
	{
		mat->getBestTechnique()->getPass(pass_id)->getFragmentProgramParameters()->setNamedConstant("factors",Ogre::Vector3(1,0,0));
	}
};

class CompositorListener3 : public Ogre::CompositorInstance::Listener
{
public:

	void notifyMaterialSetup (uint32 pass_id, MaterialPtr &mat)
	{
		mat->getBestTechnique()->getPass(pass_id)->getFragmentProgramParameters()->setNamedConstant("factors",Ogre::Vector3(0,1,0));
	}
};

class CompositorListener4 : public Ogre::CompositorInstance::Listener
{
public:

	void notifyMaterialSetup (uint32 pass_id, MaterialPtr &mat)
	{
		mat->getBestTechnique()->getPass(pass_id)->getFragmentProgramParameters()->setNamedConstant("factors",Ogre::Vector3(0,0,1));
	}
};


class Example83 : public ExampleApplication
{
private:

	Ogre::Viewport* vp;
	Ogre::Viewport* vp2;
	Ogre::Viewport* vp3;
	Ogre::Viewport* vp4;

public:

	void createScene()
	{
		Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		Ogre::Entity* ent = mSceneMgr->createEntity("Sinbad.mesh");
		node->attachObject(ent);

		Ogre::CompositorManager::getSingleton().addCompositor(vp, "Compositor9");
		Ogre::CompositorManager::getSingleton().setCompositorEnabled(vp, "Compositor9", true);

		Ogre::CompositorInstance* comp =  Ogre::CompositorManager::getSingleton().getCompositorChain(vp)->getCompositor("Compositor9");
		CompositorListener2* compListener = new CompositorListener2();
		comp->addListener(compListener);

		Ogre::CompositorManager::getSingleton().addCompositor(vp2, "Compositor9");
		Ogre::CompositorManager::getSingleton().setCompositorEnabled(vp2, "Compositor9", true);

		Ogre::CompositorInstance* comp2 =  Ogre::CompositorManager::getSingleton().getCompositorChain(vp2)->getCompositor("Compositor9");
		CompositorListener3* compListener2 = new CompositorListener3();
		comp2->addListener(compListener2);

		Ogre::CompositorManager::getSingleton().addCompositor(vp3, "Compositor9");
		Ogre::CompositorManager::getSingleton().setCompositorEnabled(vp3, "Compositor9", true);

		Ogre::CompositorInstance* comp3 =  Ogre::CompositorManager::getSingleton().getCompositorChain(vp3)->getCompositor("Compositor9");
		CompositorListener4* compListener3 = new CompositorListener4();
		comp3->addListener(compListener3);



	}

	void createCamera()
	{
		mCamera = mSceneMgr->createCamera("MyCamera1");
		mCamera->setPosition(0,10,20);
		mCamera->lookAt(0,0,0);
		mCamera->setNearClipDistance(5);
	}

	void createViewports()
	{
		vp = mWindow->addViewport(mCamera,0,0.0,0.0,0.5,0.5);
		vp->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));

		vp2 = mWindow->addViewport(mCamera,1,0.5,0.0,0.5,0.5);
		vp2->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));

		vp3 = mWindow->addViewport(mCamera,2,0.0,0.5,0.5,0.5);
		vp3->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));

		vp4 = mWindow->addViewport(mCamera,3,0.5,0.5,0.5,0.5);
		vp4->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));

		mCamera->setAspectRatio(Real(vp->getActualWidth()) / Real(vp->getActualHeight()));    
	}


};

int main (void)
{
	Example83 app;
	app.go();
	return 0;
}
