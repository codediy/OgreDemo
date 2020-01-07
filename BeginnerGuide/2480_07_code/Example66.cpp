#include "Ogre\ExampleApplication.h"


class Example66 : public ExampleApplication
{
private:
	
public:

	void createScene()
	{
		Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Node1");
		Ogre::Entity* ent = mSceneMgr->createEntity("Entity1","Sinbad.mesh");
		ent->setMaterial(Ogre::MaterialManager::getSingleton().getByName("MyMaterial14"));
		node->attachObject(ent);
	
	}

	
};

int main (void)
{
	Example66 app;
	app.go();
	return 0;
}
