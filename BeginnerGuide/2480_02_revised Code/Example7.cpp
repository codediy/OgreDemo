#include "Ogre\ExampleApplication.h"


class Example7 : public ExampleApplication
{
public:

	void createScene()
	{
		Ogre::Entity* ent = mSceneMgr->createEntity("MyEntity","Sinbad.mesh");
		Ogre::SceneNode* node = mSceneMgr->createSceneNode("Node1");
		node->setPosition(0,0,400);
		node->yaw(Ogre::Degree(180.0f));
		mSceneMgr->getRootSceneNode()->addChild(node);
		node->attachObject(ent);

		Ogre::Entity* ent2 = mSceneMgr->createEntity("MyEntity2","Sinbad.mesh");
		Ogre::SceneNode* node2 = node->createChildSceneNode("node2");
		node2->setPosition(10,0,0);
		node2->translate(0,0,10);
		node2->attachObject(ent2);

		Ogre::Entity* ent3 = mSceneMgr->createEntity("MyEntity3","Sinbad.mesh");
		Ogre::SceneNode* node3 = node->createChildSceneNode("node3");
		node3->setPosition(20,0,0);
		node3->translate(0,0,10,Ogre::Node::TS_WORLD);
		node3->attachObject(ent3);



		

	
	}
};

int main (void)
{
	Example7 app;
	app.go();
	return 0;
}