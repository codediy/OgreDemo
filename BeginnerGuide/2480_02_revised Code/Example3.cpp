#include "Ogre\ExampleApplication.h"


class Example1 : public ExampleApplication
{
public:

	void createScene()
	{
		Ogre::Entity* ent = mSceneMgr->createEntity("MyEntity","Sinbad.mesh");
		Ogre::SceneNode* node = mSceneMgr->createSceneNode("Node1");
		node->setPosition(10,10,0);
		mSceneMgr->getRootSceneNode()->addChild(node);
		node->attachObject(ent);

		Ogre::Entity* ent2 = mSceneMgr->createEntity("MyEntity2","Sinbad.mesh");
		Ogre::SceneNode* node2 = mSceneMgr->createSceneNode("Node2");
		node->addChild(node2);
		node2->setPosition(0,10,20);
		node2->attachObject(ent2);
		
	}
};

int main (void)
{
	Example1 app;
	app.go();
	return 0;
}