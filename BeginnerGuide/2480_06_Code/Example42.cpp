#include "Ogre\ExampleApplication.h"



class Example42 : public ExampleApplication
{
private:
	Ogre::SceneNode* _SinbadNode;
	Ogre::Entity* _SinbadEnt;
public:

	void createScene()
	{
		std::cout << mSceneMgr->getTypeName() << "::" << mSceneMgr->getName() << std::endl;
	}
	
};

int main (void)
{
	Example42 app;
	app.go();
	return 0;
}
