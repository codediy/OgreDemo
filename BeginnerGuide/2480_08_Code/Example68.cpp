#include "Ogre\ExampleApplication.h"


class Example68 : public ExampleApplication
{
private:
	
public:

	void createScene()
	{
		Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Node1",Ogre::Vector3(0,0,450));
		Ogre::Entity* ent = mSceneMgr->createEntity("Entity1","Sinbad.mesh");
		node->attachObject(ent);
	}
};

int main (void)
{
	Example68 app;
	app.go();
	return 0;
}
