#include "Ogre\Ogre.h"
#include "OIS\OIS.h"

class MyFrameListener : public Ogre::FrameListener
{
private:
	
	OIS::InputManager* _InputManager;
	OIS::Keyboard* _Keyboard;
public:

	MyFrameListener(Ogre::RenderWindow* win)
	{
		OIS::ParamList parameters;
		unsigned int windowHandle = 0;
		std::ostringstream windowHandleString;

		win->getCustomAttribute("WINDOW", &windowHandle);
		windowHandleString << windowHandle;
		parameters.insert(std::make_pair("WINDOW", windowHandleString.str()));

		_InputManager = OIS::InputManager::createInputSystem(parameters);
		_Keyboard = static_cast<OIS::Keyboard*>(_InputManager->createInputObject( OIS::OISKeyboard, false ));
	}

	~MyFrameListener()
	{
		_InputManager->destroyInputObject(_Keyboard);
		OIS::InputManager::destroyInputSystem(_InputManager);
	}

	bool frameStarted(const Ogre::FrameEvent& evt)
	{
		_Keyboard->capture();
		if(_Keyboard->isKeyDown(OIS::KC_ESCAPE))
		{
			return false;
		}
		return true;
	}
};

class MyApplication
{
private:

	Ogre::SceneManager* _sceneManager;
	Ogre::Root* _root;

	MyFrameListener* _listener;
public:

	MyApplication()
	{
		_sceneManager = NULL;
		_listener = NULL;
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

		_listener = new MyFrameListener(window);
		_root->addFrameListener(_listener);

		_root->startRendering();

		return 0;

	}

	void createScene()
	{
		Ogre::Entity* ent = _sceneManager->createEntity("Sinbad.mesh");

		_sceneManager->getRootSceneNode()->attachObject(ent);

	}
};


int main (void)
{
	MyApplication app;
	app.startup();
	return 0;
}
