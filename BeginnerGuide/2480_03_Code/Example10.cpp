#include "Ogre\ExampleApplication.h"


class Example10 : public ExampleApplication
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

		
	}
};

int main (void)
{
	Example10 app;
	try {
		app.go();
	}
	catch(Exception &e) {
		std::cout << e.getFile();
	}
		
	return 0;
}