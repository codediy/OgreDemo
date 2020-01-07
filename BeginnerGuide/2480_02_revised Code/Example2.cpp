#include "Ogre\ExampleApplication.h"


class Example2 : public ExampleApplication
{
public:

	void createScene()
	{
		Ogre::Entity* ent = mSceneMgr->createEntity("MyEntity","Sinbad.mesh");
		Ogre::SceneNode* node = mSceneMgr->createSceneNode("Node1");
		mSceneMgr->getRootSceneNode()->addChild(node);
		node->attachObject(ent);

		
	}
};

int main (void)
{
	Example2 app;
	app.go();
	return 0;
}