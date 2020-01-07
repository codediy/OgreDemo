#include "Ogre\ExampleApplication.h"


class Example17 : public ExampleApplication
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

		Ogre::Light* light = mSceneMgr->createLight("Light1");
		light->setType(Ogre::Light::LT_DIRECTIONAL);
		light->setDiffuseColour(Ogre::ColourValue(1.0f,1.0f,1.0f));
		light->setDirection(Ogre::Vector3(1,-1,0));
	
		
		
	}
};

int main (void)
{
	Example17 app;
	app.go();
	return 0;
}