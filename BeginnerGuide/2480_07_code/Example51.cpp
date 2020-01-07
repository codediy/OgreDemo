#include "Ogre\ExampleApplication.h"


class Example51 : public ExampleApplication
{
private:
	
public:

	void createScene()
	{
		

		Ogre::ManualObject*  manual = mSceneMgr->createManualObject("Quad");
		manual->begin("MyMaterial2", RenderOperation::OT_TRIANGLE_LIST);

	
		manual->position(5.0, 0.0, 0.0);
		manual->textureCoord(0,1);
		manual->position(-5.0, 10.0, 0.0);
		manual->textureCoord(1,0);
		manual->position(-5.0, 0.0, 0.0);
		manual->textureCoord(1,1);
		manual->position(5.0, 10.0, 0.0);
		manual->textureCoord(0,0);

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
	
	}

	
};

int main (void)
{
	Example51 app;
	app.go();
	return 0;
}
