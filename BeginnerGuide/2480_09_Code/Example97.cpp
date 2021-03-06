#include "Ogre\Ogre.h"
#include "OIS\OIS.h"

class MyFrameListener : public Ogre::FrameListener
{
private:
	
	OIS::InputManager* _InputManager;
	OIS::Keyboard* _Keyboard;
	OIS::Mouse* _Mouse;
	Ogre::Camera* _Cam;
	Ogre::Viewport* _viewport;
	float _movementspeed;

	bool comp1,comp2,comp3;
	bool down1,down2,down3;
public:

	MyFrameListener(Ogre::RenderWindow* win,Ogre::Camera* cam,Ogre::Viewport* viewport)
	{
	
		_Cam = cam;
		_movementspeed = 50.0f;
		_viewport = viewport;

		comp1 = false;
		comp2 = false;
		comp3 = false;

		down1 = false;
		down2 = false;
		down3 = false;


		OIS::ParamList parameters;
		unsigned int windowHandle = 0;
		std::ostringstream windowHandleString;

		win->getCustomAttribute("WINDOW", &windowHandle);
		windowHandleString << windowHandle;
		parameters.insert(std::make_pair("WINDOW", windowHandleString.str()));

		_InputManager = OIS::InputManager::createInputSystem(parameters);
		_Keyboard = static_cast<OIS::Keyboard*>(_InputManager->createInputObject( OIS::OISKeyboard, false ));
		_Mouse = static_cast<OIS::Mouse*>(_InputManager->createInputObject( OIS::OISMouse, false ));
	}

	~MyFrameListener()
	{
		_InputManager->destroyInputObject(_Keyboard);
		_InputManager->destroyInputObject(_Mouse);
		OIS::InputManager::destroyInputSystem(_InputManager);
	}

	bool frameStarted(const Ogre::FrameEvent& evt)
	{
		_Keyboard->capture();
		if(_Keyboard->isKeyDown(OIS::KC_ESCAPE))
		{
			return false;
		}

		Ogre::Vector3 translate(0,0,0);
		if(_Keyboard->isKeyDown(OIS::KC_W))
		{
			translate += Ogre::Vector3(0,0,-1);
		}
		if(_Keyboard->isKeyDown(OIS::KC_S))
		{
			translate += Ogre::Vector3(0,0,1);
		}
		if(_Keyboard->isKeyDown(OIS::KC_A))
		{
			translate += Ogre::Vector3(-1,0,0);
		}
		if(_Keyboard->isKeyDown(OIS::KC_D))
		{
			translate += Ogre::Vector3(1,0,0);
		}
		
		if(_Keyboard->isKeyDown(OIS::KC_1) && !down1)
		{
			down1 = true;
			comp1 = !comp1;
			Ogre::CompositorManager::getSingleton().setCompositorEnabled(_viewport, "Compositor2", comp1);
		}
		if(_Keyboard->isKeyDown(OIS::KC_2) && !down2)
		{
			down2 = true;
			comp2 = !comp2;
			Ogre::CompositorManager::getSingleton().setCompositorEnabled(_viewport, "Compositor3", comp2);
		}
		if(_Keyboard->isKeyDown(OIS::KC_3) && !down3)
		{
			down3 = true;
			comp3 = !comp3;
			Ogre::CompositorManager::getSingleton().setCompositorEnabled(_viewport, "Compositor7", comp3);
		}

		if(!_Keyboard->isKeyDown(OIS::KC_1))
		{
			down1 = false;
		}
		if(!_Keyboard->isKeyDown(OIS::KC_2))
		{
			down2 = false;
		}
		if(!_Keyboard->isKeyDown(OIS::KC_3))
		{
			down3 = false;
		}
	
		

		_Cam->moveRelative(translate*evt.timeSinceLastFrame * _movementspeed);

		_Mouse->capture();
		float rotX = _Mouse->getMouseState().X.rel * evt.timeSinceLastFrame* -1;
		float rotY = _Mouse->getMouseState().Y.rel * evt.timeSinceLastFrame * -1;


		_Cam->yaw(Ogre::Radian(rotX));
		_Cam->pitch(Ogre::Radian(rotY));


		return true;
	}
};

class MyApplication
{
private:

	Ogre::SceneManager* _sceneManager;
	Ogre::Root* _root;

	MyFrameListener* _listener;

	bool _keepRunning;
public:

	MyApplication()
	{
		_sceneManager = NULL;
		_listener = NULL;
		_keepRunning = true;
	}
	
	~MyApplication()
	{
		if(_root)
		{
			delete _root;
		}
		if(_listener)
		{
			delete _listener;
		}
	}
	
	void loadResources()
	{
		Ogre::ConfigFile cf;
		cf.load("resources_d.cfg");


		Ogre::ConfigFile::SectionIterator sectionIter = cf.getSectionIterator();
		Ogre::String sectionName, typeName, dataname;
		while (sectionIter.hasMoreElements())
		{
			sectionName = sectionIter.peekNextKey();
			Ogre::ConfigFile::SettingsMultiMap *settings = sectionIter.getNext();
			Ogre::ConfigFile::SettingsMultiMap::iterator i;
			for (i = settings->begin(); i != settings->end(); ++i)
			{
				typeName = i->first;
				dataname = i->second;

				Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
					dataname, typeName, sectionName);

			}
		}


		Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	}

	int startup()
	{
		_root = new Ogre::Root("plugins_d.cfg");


		if(!_root->showConfigDialog())
		{
			return -1;
		}

		Ogre::RenderWindow* window = _root->initialise(true,"Ogre3D Beginners Guide");

		_sceneManager = _root->createSceneManager(Ogre::ST_GENERIC);

		Ogre::Camera* camera = _sceneManager->createCamera("Camera");
		camera->setPosition(Ogre::Vector3(0,0,50));
		camera->lookAt(Ogre::Vector3(0,0,0));
		camera->setNearClipDistance(5);


		Ogre::Viewport* viewport = window->addViewport(camera);
		viewport->setBackgroundColour(Ogre::ColourValue(0.0,0.0,0.0));
		camera->setAspectRatio(Ogre::Real(viewport->getActualWidth())/ Ogre::Real(viewport->getActualHeight()));


		loadResources();
		createScene();

		_listener = new MyFrameListener(window,camera,viewport);
		_root->addFrameListener(_listener);

		
		Ogre::CompositorManager::getSingleton().addCompositor(viewport, "Compositor2");
		Ogre::CompositorManager::getSingleton().addCompositor(viewport, "Compositor3");
		Ogre::CompositorManager::getSingleton().addCompositor(viewport, "Compositor7");

		return 0;

	}

	void createScene()
	{
		Ogre::Entity* ent = _sceneManager->createEntity("Sinbad.mesh");

		_sceneManager->getRootSceneNode()->attachObject(ent);

	}

	void renderOneFrame()
	{
		Ogre::WindowEventUtilities::messagePump();
		_keepRunning = _root->renderOneFrame();
	}

	bool keepRunning()
	{
		return _keepRunning;
	}
};


int main (void)
{
	MyApplication app;
	app.startup();
	
	while(app.keepRunning())
	{
		app.renderOneFrame();
	}

	return 0;
}
