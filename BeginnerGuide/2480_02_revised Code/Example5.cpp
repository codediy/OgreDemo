#include "Ogre\ExampleApplication.h"


class Example5 : public ExampleApplication
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
		Ogre::SceneNode* node2 = node->createChildSceneNode("node2");
		node2->setPosition(10,0,0);
		node2->scale(2.0f,2.0f,2.0f);
		node2->attachObject(ent2);

		Ogre::Entity* ent3 = mSceneMgr->createEntity("MyEntity3","Sinbad.mesh");
		Ogre::SceneNode* node3 = node->createChildSceneNode("node3",Ogre::Vector3(20,0,0));
		node3->scale(0.2f,0.2f,0.2f);
		node3->attachObject(ent3);

	
		
	}
};

int main (void)
{
	Example5 app;
	app.go();
	return 0;
}