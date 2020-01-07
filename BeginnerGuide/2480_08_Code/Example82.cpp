#include "Ogre\ExampleApplication.h"



class Example82 : public ExampleApplication
{
private:
	Ogre::Camera* mCamera2;
	Ogre::Camera* mCamera3;
	Ogre::Camera* mCamera4;

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
		mCamera2->setPosition(0,10,-20);
		mCamera2->lookAt(0,0,0);
		mCamera2->setNearClipDistance(5);

		mCamera3 = mSceneMgr->createCamera("MyCamera3");
		mCamera3->setPosition(-20,10,0);
		mCamera3->lookAt(0,0,0);
		mCamera3->setNearClipDistance(5);

		mCamera4 = mSceneMgr->createCamera("MyCamera4");
		mCamera4->setPosition(20,10,0);
		mCamera4->lookAt(0,0,0);
		mCamera4->setNearClipDistance(5);
	}

	void createViewports()
	{
		Ogre::Viewport* vp = mWindow->addViewport(mCamera,0,0.0,0.0,0.5,0.5);
		vp->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));

		Ogre::Viewport* vp2 = mWindow->addViewport(mCamera2,1,0.5,0.0,0.5,0.5);
		vp2->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));

		Ogre::Viewport* vp3 = mWindow->addViewport(mCamera3,2,0.0,0.5,0.5,0.5);
		vp3->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));

		Ogre::Viewport* vp4 = mWindow->addViewport(mCamera4,3,0.5,0.5,0.5,0.5);
		vp4->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));
		
		mCamera->setAspectRatio(Real(vp->getActualWidth()) / Real(vp->getActualHeight()));    
		mCamera2->setAspectRatio(Real(vp2->getActualWidth()) / Real(vp2->getActualHeight()));   
		mCamera3->setAspectRatio(Real(vp2->getActualWidth()) / Real(vp3->getActualHeight()));
		mCamera4->setAspectRatio(Real(vp2->getActualWidth()) / Real(vp4->getActualHeight()));



	}

	
};

int main (void)
{
	Example82 app;
	app.go();
	return 0;
}
