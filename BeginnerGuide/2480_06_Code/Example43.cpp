#include "Ogre\ExampleApplication.h"



class Example43 : public ExampleApplication
{
private:
	Ogre::SceneNode* _SinbadNode;
	Ogre::Entity* _SinbadEnt;
public:

	void createScene()
	{
		
	}

	virtual void chooseSceneManager(void)
	{
		ResourceGroupManager::getSingleton().addResourceLocation("../../media/packs/chiropteraDM.pk3", "Zip",
		ResourceGroupManager::getSingleton().getWorldResourceGroupName(), true);
		ResourceGroupManager::getSingleton().initialiseResourceGroup(ResourceGroupManager::getSingleton().getWorldResourceGroupName());

		mSceneMgr = mRoot->createSceneManager("BspSceneManager");
		mSceneMgr->setWorldGeometry("maps/chiropteradm.bsp");

	}


	
};

int main (void)
{
	Example43 app;
	app.go();
	return 0;
}
