#include "Ogre\ExampleApplication.h"


class Example6 : public ExampleApplication
{
public:

	void createScene()
	{
		Ogre::Entity* ent = mSceneMgr->createEntity("MyEntity","Sinbad.mesh");
		Ogre::SceneNode* node = mSceneMgr->createSceneNode("Node1");
		node->setPosition(40,10,0);
		node->yaw(Ogre::Degree(180.0f));
		mSceneMgr->getRootSceneNode()->addChild(node);
		node->attachObject(ent);

		Ogre::Entity* ent2 = mSceneMgr->createEntity("MyEntitysNinja","ninja.mesh");
		Ogre::SceneNode* node2 = node->createChildSceneNode("node2");
		node2->setPosition(10,0,0);
		node2->setScale(0.02f,0.02f,0.02f);
		node2->attachObject(ent2);
		

	
	}
};

int main (void)
{
	Example6 app;
	app.go();
	return 0;
}