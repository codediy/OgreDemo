#include "Ogre\ExampleApplication.h"


class Example61 : public ExampleApplication
{
private:
	
public:

	void createScene()
	{
		

		Ogre::ManualObject*  manual = mSceneMgr->createManualObject("Quad");
		manual->begin("MyMaterial11", RenderOperation::OT_TRIANGLE_LIST);

	
		manual->position(5.0, 0.0, 0.0);
		manual->textureCoord(0.0,1.0);
		manual->position(-5.0, 10.0, 0.0);
		manual->textureCoord(1.0,0.0);
		manual->position(-5.0, 0.0, 0.0);
		manual->textureCoord(1.0,1.0);
		manual->position(5.0, 10.0, 0.0);
		manual->textureCoord(0.0,0.0);

		manual->index(0);
		manual->index(1);
		manual->index(2);

		manual->index(0);
		manual->index(3);
		manual->index(1);



		manual->end();

		manual->convertToMesh("Quad");

	
		Ogre::Entity * ent = mSceneMgr->createEntity("Quad");
		Ogre::SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Node1");
		node->attachObject(ent);

		
		ent = mSceneMgr->createEntity("Quad");
		ent->setMaterial(Ogre::MaterialManager::getSingleton().getByName("MyMaterial12"));
		node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Node2",Ogre::Vector3(15,0,0));
		node->attachObject(ent);
	
	}

	
};

int main (void)
{
	Example61 app;
	app.go();
	return 0;
}
