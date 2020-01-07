#include "Ogre\ExampleApplication.h"


class Example8 : public ExampleApplication
{
public:

	void createScene()
	{
		Ogre::Entity* ent = mSceneMgr->createEntity("MyEntity","sinbad.mesh");
		Ogre::SceneNode* node = mSceneMgr->createSceneNode("Node1");
		mSceneMgr->getRootSceneNode()->addChild(node);
		node->attachObject(ent);

		Ogre::Entity* ent2 = mSceneMgr->createEntity("MyEntity2","sinbad.mesh");
		Ogre::SceneNode* node2 = mSceneMgr->getRootSceneNode()->createChildSceneNode("Node2");
		node2->setPosition(10,0,0);
		node2->yaw(Ogre::Degree(90));
		node2->roll(Ogre::Degree(90));
		node2->attachObject(ent2);

		Ogre::Entity* ent3 = mSceneMgr->createEntity("MyEntity3","Sinbad.mesh");
		Ogre::SceneNode* node3 = node->createChildSceneNode("node3");
		node3->setPosition(20,0,0);
		node3->yaw(Ogre::Degree(90),Ogre::Node::TS_WORLD);
		node3->roll(Ogre::Degree(90),Ogre::Node::TS_WORLD);
		node3->attachObject(ent3);



		

	
	}
};

int main (void)
{
	Example8 app;
	app.go();
	return 0;
}