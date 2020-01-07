#include "Ogre\ExampleApplication.h"


class Example11 : public ExampleApplication
{
public:

	void createScene()
	{
		Ogre::Plane plane(Vector3::UNIT_Y, -10);
		Ogre::MeshManager::getSingleton().createPlane("plane",
			ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
			1500,1500,20,20,true,1,5,5,Vector3::UNIT_Z);


		Ogre::Entity* ent = mSceneMgr->createEntity("LightPlaneEntity", "plane");
		mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent);
		ent->setMaterialName("Examples/BeachStones");


		Ogre::SceneNode* node = mSceneMgr->createSceneNode("Node1");
		mSceneMgr->getRootSceneNode()->addChild(node);

		Ogre::Light* light1 = mSceneMgr->createLight("Light1");
		light1->setType(Ogre::Light::LT_POINT);
		light1->setPosition(0,20,0);
		light1->setDiffuseColour(1.0f,1.0f,1.0f);
		
		
		Ogre::Entity* LightEnt = mSceneMgr->createEntity("MyEntity","sphere.mesh");
		Ogre::SceneNode* node3 = node->createChildSceneNode("node3");
		node3->setScale(0.1f,0.1f,0.1f);
		node3->setPosition(0,20,0);
		node3->attachObject(LightEnt);



		
	}
};

int main (void)
{
	Example11 app;
	try {
		app.go();
	}
	catch(Exception &e) {
		std::cout << e.getFile();
	}
		
	return 0;
}