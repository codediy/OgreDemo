#include "Ogre\ExampleApplication.h"


class Example35FrameListener : public Ogre::FrameListener
{
private:
	Ogre::SceneNode* _node;

	Ogre::Camera* _Cam;
	Ogre::PolygonMode _PolyMode;
	OIS::InputManager* _man;
	OIS::Keyboard* _key;
	OIS::Mouse* _mouse;
	bool _pressedBefore;
	float _movementspeed;

	Ogre::Entity* _ent;
	Ogre::AnimationState* _aniState;

	Ogre::Entity* _ent2;
	Ogre::AnimationState* _aniState2;

public:

	Example35FrameListener(Ogre::SceneNode* node,Ogre::Entity* ent,Ogre::Entity* ent2,RenderWindow* win,Ogre::Camera* cam)
	{
		_node = node;
		
		_Cam = cam;

		_pressedBefore = false;

		_movementspeed = 200.0f;
		_PolyMode = Ogre::PolygonMode::PM_SOLID;

		size_t windowHnd = 0;
		std::stringstream windowHndStr;

		win->getCustomAttribute("WINDOW", &windowHnd);
		windowHndStr << windowHnd;
		
		OIS::ParamList pl;
		pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

		_man = OIS::InputManager::createInputSystem( pl );
		_key = static_cast<OIS::Keyboard*>(_man->createInputObject( OIS::OISKeyboard, false ));
		_mouse = static_cast<OIS::Mouse*>(_man->createInputObject( OIS::OISMouse, false ));

		_ent = ent;
		_aniState = _ent->getAnimationState("Dance");
		_aniState->setEnabled(true);
		_aniState->setLoop(true);

		_ent2 = ent2;
		_aniState2 = _ent2->getAnimationState("Dance");
		_aniState2->setEnabled(true);
		_aniState2->setLoop(true);


		

		
	}
	
	bool frameStarted(const Ogre::FrameEvent  &evt)
	{
		Ogre::Vector3 translate(0,0,0);
		
		_key->capture();
		_mouse->capture();
		if(_key->isKeyDown(OIS::KC_ESCAPE))
		{
			return false;
		}
		if(_key->isKeyDown(OIS::KC_W))
		{
			translate += Ogre::Vector3(0,0,-1);
		}
		if(_key->isKeyDown(OIS::KC_S))
		{
			translate += Ogre::Vector3(0,0,1);
		}
		if(_key->isKeyDown(OIS::KC_A))
		{
			translate += Ogre::Vector3(-1,0,0);
		}
		if(_key->isKeyDown(OIS::KC_D))
		{
			translate += Ogre::Vector3(1,0,0);
		}

		if(_key->isKeyDown(OIS::KC_R) && !_pressedBefore)
		{
			_pressedBefore = true;
			if(_PolyMode == PM_SOLID) 
			{
				_PolyMode = Ogre::PolygonMode::PM_WIREFRAME;
			} 
			else if(_PolyMode == PM_WIREFRAME) 
			{
				_PolyMode = Ogre::PolygonMode::PM_POINTS;
			} 
			else if(_PolyMode == PM_POINTS) 
			{
				_PolyMode = Ogre::PolygonMode::PM_SOLID;
			} 
			_Cam->setPolygonMode(_PolyMode);
		}
		if(!_key->isKeyDown(OIS::KC_R))
		{
			_pressedBefore = false;
		}
		
		float rotX = _mouse->getMouseState().X.rel * evt.timeSinceLastFrame* -1;
		float rotY = _mouse->getMouseState().Y.rel * evt.timeSinceLastFrame * -1;
		

		_Cam->yaw(Ogre::Radian(rotX));
		_Cam->pitch(Ogre::Radian(rotY));
		_Cam->moveRelative(translate*evt.timeSinceLastFrame * _movementspeed);

		_aniState->addTime(evt.timeSinceLastFrame);
		_aniState2->addTime(evt.timeSinceLastFrame * 0.25);
		return true;
	}
};


class Example35 : public ExampleApplication
{
private:
	Ogre::SceneNode* _SinbadNode;
	Ogre::SceneNode* _SinbadNode2;
	Ogre::Entity* _SinbadEnt;
	Ogre::Entity* _SinbadEnt2;
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


		_SinbadEnt = mSceneMgr->createEntity("Sinbad", "Sinbad.mesh");
		_SinbadNode = node->createChildSceneNode("SinbadNode");
		_SinbadNode->setScale(3.0f,3.0f,3.0f);
		_SinbadNode->setPosition(Ogre::Vector3(0.0f,4.0f,0.0f));
		_SinbadNode->attachObject(_SinbadEnt);

		_SinbadEnt2 = mSceneMgr->createEntity("Sinbad2", "Sinbad.mesh");
		_SinbadNode2 = node->createChildSceneNode("SinbadNode2");
		_SinbadNode2->setScale(3.0f,3.0f,3.0f);
		_SinbadNode2->setPosition(Ogre::Vector3(20.0f,4.0f,0.0f));
		_SinbadNode2->attachObject(_SinbadEnt2);

		mSceneMgr->setShadowTechnique(SHADOWTYPE_STENCIL_ADDITIVE);	

	}

	void createCamera()
	{
	
		mCamera = mSceneMgr->createCamera("MyCamera1");
		mCamera->setNearClipDistance(5);
		mCamera->setPosition(0,100,200);
		


	}

	void createFrameListener()
	{
		Ogre::FrameListener* FrameListener = new Example35FrameListener(_SinbadNode,_SinbadEnt,_SinbadEnt2,mWindow,mCamera);
		mRoot->addFrameListener(FrameListener);
	}
};

int main (void)
{
	Example35 app;
	app.go();
	return 0;
}
