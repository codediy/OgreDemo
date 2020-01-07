#include "Ogre\ExampleApplication.h"


class Example28FrameListener : public Ogre::FrameListener
{
private:
	Ogre::SceneNode* _node;
	OIS::InputManager* _man;
	OIS::Keyboard* _key;
public:

	Example28FrameListener(Ogre::SceneNode* node,RenderWindow* win)
	{
		_node = node;

		size_t windowHnd = 0;
		std::stringstream windowHndStr;

		win->getCustomAttribute("WINDOW", &windowHnd);
		windowHndStr << windowHnd;
		
		OIS::ParamList pl;
		pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

		_man = OIS::InputManager::createInputSystem( pl );
		_key = static_cast<OIS::Keyboard*>(_man->createInputObject( OIS::OISKeyboard, false ));
	}
	
	bool frameStarted(const Ogre::FrameEvent  &evt)
	{
		Ogre::Vector3 translate(0,0,0);
		
		_key->capture();
		if(_key->isKeyDown(OIS::KC_ESCAPE))
		{
			return false;
		}
		if(_key->isKeyDown(OIS::KC_W))
		{
			translate += Ogre::Vector3(0,0,-10);
		}
		if(_key->isKeyDown(OIS::KC_S))
		{
			translate += Ogre::Vector3(0,0,10);
		}
		if(_key->isKeyDown(OIS::KC_A))
		{
			translate += Ogre::Vector3(-10,0,0);
		}
		if(_key->isKeyDown(OIS::KC_D))
		{
			translate += Ogre::Vector3(10,0,0);
		}
		_node->translate(translate*evt.timeSinceLastFrame);

		return true;
	}
};


class Example28 : public ExampleApplication
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
		Ogre::FrameListener* FrameListener = new Example28FrameListener(_SinbadNode,mWindow);
		mRoot->addFrameListener(FrameListener);
	}
};

int main (void)
{
	Example28 app;
	app.go();
	return 0;
}