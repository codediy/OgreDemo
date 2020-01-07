#include "Ogre\ExampleApplication.h"



class CompositorListener1 : public Ogre::CompositorInstance::Listener
{
private:
	float number;

public:

	CompositorListener1()
	{
		number = 125.0f;
	}

	void notifyMaterialRender(uint32 pass_id, MaterialPtr &mat)
	{
		mat->getBestTechnique()->getPass(pass_id)->getFragmentProgramParameters()->setNamedConstant("numpixels",number);
	}

	void setNumber(float num)
	{
		number = num;
	}

	float getNumber()
	{
		return number;
	}
};

class Example79FrameListener : public Ogre::FrameListener
{
private:
	
	OIS::InputManager* _man;
	OIS::Keyboard* _key;
	CompositorListener1* _listener;
public:

	Example79FrameListener(RenderWindow* win,CompositorListener1* listener)
	{
	
		_listener = listener;

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
		_key->capture();
		
		if(_key->isKeyDown(OIS::KC_ESCAPE))
		{
			return false;
		}

		if(_key->isKeyDown(OIS::KC_UP))
		{
			float num = _listener->getNumber();
			num++;
			_listener->setNumber(num);

			std::cout << num << std::endl;
		}

		if(_key->isKeyDown(OIS::KC_DOWN))
		{
			float num = _listener->getNumber();
			num--;
			_listener->setNumber(num);

			std::cout << num << std::endl;
		}

		
		return true;
	}

};

class Example79 : public ExampleApplication
{
private:
	CompositorListener1* compListener;
public:

	~Example79()
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

	void createFrameListener()
	{
		Ogre::FrameListener* FrameListener = new Example79FrameListener(mWindow,compListener);
		mRoot->addFrameListener(FrameListener);
	}

	
};

int main (void)
{
	Example79 app;
	app.go();
	return 0;
}
