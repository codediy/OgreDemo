#include "Ogre\ExampleApplication.h"



class Example81 : public ExampleApplication
{
private:
	Ogre::Camera* mCamera2;

public:

	void createScene()
	{
		Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		Ogre::Entity* ent = mSceneMgr->createEntity("Sinbad.mesh");
		node->attachObject(ent);
	}

	void createCamera()
	{
		mCamera = mSceneMgr->createCamera("MyCamera1");
		mCamera->setPosition(0,10,20);
		mCamera->lookAt(0,0,0);
		mCamera->setNearClipDistance(5);

		mCamera2 = mSceneMgr->createCamera("MyCamera2");
		mCamera2->setPosition(20,10,0);
		mCamera2->lookAt(0,0,0);
		mCamera2->setNearClipDistance(5);
	}

	void createViewports()
	{
		Ogre::Viewport* vp = mWindow->addViewport(mCamera,0,0.0,0.0,0.5,1.0);
		vp->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));

		Ogre::Viewport* vp2 = mWindow->addViewport(mCamera2,1,0.5,0.0,0.5,1.0);
		vp2->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));
		
		mCamera->setAspectRatio(Real(vp->getActualWidth()) / Real(vp->getActualHeight()));    
		mCamera2->setAspectRatio(Real(vp2->getActualWidth()) / Real(vp2->getActualHeight()));   



	}

	
};

int main (void)
{
	Example81 app;
	app.go();
	return 0;
}
