#include "Ogre\ExampleApplication.h"


class Example14 : public ExampleApplication
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
		light->setType(Ogre::Light::LT_SPOTLIGHT);
		light->setDirection(Ogre::Vector3(1,-1,0));
		light->setSpotlightInnerAngle(Ogre::Degree(5.0f));
		light->setSpotlightOuterAngle(Ogre::Degree(45.0f));
		light->setSpotlightFalloff(0.0f);
		light->setDiffuseColour(Ogre::ColourValue(0.0f,1.0f,0.0f));
		node2->attachObject(light);

		Ogre::Entity* lightEnt = mSceneMgr->createEntity("MyEntity","sphere.mesh");
		Ogre::SceneNode* node3 = node2->createChildSceneNode("node3");
		node3->setScale(0.1f,0.1f,0.1f);
		node3->attachObject(lightEnt);

		
	}
};

int main (void)
{
	Example14 app;
	app.go();
	return 0;
}