#include "Ogre\Ogre.h"



int main (void)
{
	Ogre::Root* root = new Ogre::Root("plugins_d.cfg");

	if(!root->showConfigDialog())
	{
		return -1;
	}

	Ogre::RenderWindow* window = root->initialise(true,"Ogre3D Beginners Guide");

	Ogre::SceneManager* sceneManager = root->createSceneManager(Ogre::ST_GENERIC);

	Ogre::Camera* camera = sceneManager->createCamera("Camera");
	camera->setPosition(Ogre::Vector3(0,0,50));
	camera->lookAt(Ogre::Vector3(0,0,0));
	camera->setNearClipDistance(5);

	Ogre::Viewport* viewport = window->addViewport(camera);
	viewport->setBackgroundColour(Ogre::ColourValue(0.0,0.0,0.0));

	camera->setAspectRatio(Ogre::Real(viewport->getActualWidth())/ Ogre::Real(viewport->getActualHeight()));

	root->startRendering();



	return 0;
}
