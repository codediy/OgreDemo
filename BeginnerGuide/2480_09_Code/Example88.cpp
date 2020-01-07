#include "Ogre\Ogre.h"

class MyApplication
{
private:

	Ogre::SceneManager* _sceneManager;
	Ogre::Root* _root;
public:
	
	MyApplication()
	{
		_sceneManager = NULL;
	}

	~MyApplication()
	{	
		delete _root;
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
