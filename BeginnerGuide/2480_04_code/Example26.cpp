#include "Ogre\ExampleApplication.h"


class Example26FrameListener : public Ogre::FrameListener
{
private:
	Ogre::SceneNode* _node;
public:

	Example26FrameListener(Ogre::SceneNode* node)
	{
		_node = node;
	}
	
	bool frameStarted(const Ogre::FrameEvent  &evt)
	{
		_node->translate(Ogre::Vector3(10,0,0) * evt.timeSinceLastFrame);
		return true;
	}
};


class Example26 : public ExampleApplication
{
private:
	Ogre::SceneNode* _SinbadNode;
public:

	void createScene()
	{
		Ogre::Plane plane(Vector3::UNIT_Y, -10);
		Ogre::MeshManager::getSingleton().createPlane("plane",
			ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
			1500,1500,200,200,true,1,5,5,Vector3::UNIT_Z);


		Ogre::Entity* ent = mSceneMgr->createEntity("LightPlaneEntity", "plane");
		mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent);
		ent->setMaterialName("Examples/BeachStones");


		Ogre::SceneNode* node = mSceneMgr->createSceneNode("Node1");
		mSceneMgr->getRootSceneNode()->addChild(node);



		Ogre::Light* light = mSceneMgr->createLight("Light1");
		light->setType(Ogre::Light::LT_DIRECTIONAL);
		light->setDirection(Ogre::Vector3(1,-1,0));


		Ogre::Entity* Sinbad = mSceneMgr->createEntity("Sinbad", "Sinbad.mesh");
		_SinbadNode = node->createChildSceneNode("SinbadNode");
		_SinbadNode->setScale(3.0f,3.0f,3.0f);
		_SinbadNode->setPosition(Ogre::Vector3(0.0f,4.0f,0.0f));
		_SinbadNode->attachObject(Sinbad);

		mSceneMgr->setShadowTechnique(SHADOWTYPE_STENCIL_ADDITIVE);	
	}

	void createCamera()
	{
		mCamera = mSceneMgr->createCamera("MyCamera1");
		mCamera->setPosition(0,100,200);
		mCamera->lookAt(0,0,0);
		mCamera->setNearClipDistance(5);


	}

	void createFrameListener()
	{
		Ogre::FrameListener* FrameListener = new Example26FrameListener(_SinbadNode);
		mRoot->addFrameListener(FrameListener);
	}
};

int main (void)
{
	Example26 app;
	app.go();
	return 0;
}