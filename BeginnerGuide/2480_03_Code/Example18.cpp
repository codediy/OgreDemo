#include "Ogre\ExampleApplication.h"


class Example18 : public ExampleApplication
{
public:

	void createScene()
	{
		Ogre::Plane plane(Vector3::UNIT_Y, -10);
		Ogre::MeshManager::getSingleton().createPlane("plane",
			ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
			1500,1500,200,200,true,1,5,5,Vector3::UNIT_Z);


		Ogre::Entity* ent = mSceneMgr->createEntity("LightPlaneEntity", "plane");
		mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent);
		ent->setMaterialName("Examples/BeachStones");


		Ogre::SceneNode* node = mSceneMgr->createSceneNode("Node1");
		mSceneMgr->getRootSceneNode()->addChild(node);

		Ogre::SceneNode* node2 = node->createChildSceneNode("node2");
		node2->setPosition(0,100,0);

		Ogre::Light* light = mSceneMgr->createLight("Light1");
		light->setType(Ogre::Light::LT_DIRECTIONAL);
		light->setDirection(Ogre::Vector3(1,-1,0));
	

		Ogre::Entity* Sinbad = mSceneMgr->createEntity("Sinbad", "Sinbad.mesh");
		Ogre::SceneNode* SinbadNode = node->createChildSceneNode("SinbadNode");
		SinbadNode->setScale(3.0f,3.0f,3.0f);
		SinbadNode->setPosition(Ogre::Vector3(0.0f,4.0f,0.0f));
		SinbadNode->attachObject(Sinbad);


		
	}
};

int main (void)
{
	Example18 app;
	app.go();
	return 0;
}