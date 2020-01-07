#include "Ogre\ExampleApplication.h"


class Example43 : public ExampleApplication
{
private:
	
public:

	void createScene()
	{
		Ogre::Plane plane(Vector3::UNIT_Y, -10);
		Ogre::MeshManager::getSingleton().createPlane("plane",
			ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
			1500,1500,200,200,true,1,5,5,Vector3::UNIT_Z);


		Ogre::Entity* ent = mSceneMgr->createEntity("GrassPlane", "plane");
		mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ent);
		ent->setMaterialName("Examples/GrassFloor");

		Ogre::Light* light = mSceneMgr->createLight("Light1");
		light->setType(Ogre::Light::LT_DIRECTIONAL);
		light->setDirection(Ogre::Vector3(1,-1,0));


		Ogre::ManualObject*  manual = mSceneMgr->createManualObject("grass");
		manual->begin("Examples/GrassBlades", RenderOperation::OT_TRIANGLE_LIST);

		//First triangle
		manual->position(5.0, 0.0, 0.0);
		manual->textureCoord(0,1);
		manual->position(-5.0, 10.0, 0.0);
		manual->textureCoord(1,0);
		manual->position(-5.0, 0.0, 0.0);
		manual->textureCoord(1,1);

		//Second triangle
		manual->position(5.0, 0.0, 0.0);
		manual->textureCoord(0,1);
		manual->position(5.0, 10.0, 0.0);
		manual->textureCoord(0,0);
		manual->position(-5.0, 10.0, 0.0);
		manual->textureCoord(1,0);

		manual->end();

		Ogre::SceneNode* grassNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("GrassNode2");
		grassNode->attachObject(manual);


	}

	
};

int main (void)
{
	Example43 app;
	app.go();
	return 0;
}
