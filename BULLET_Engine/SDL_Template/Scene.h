#ifndef Scene0_H
#define Scene0_H
#include "Scene.h"
#include "Vec3.h"

class GameObject;
class Mesh;


class Scene0 : public Scene
{
private:
	//Camera* camera;
	GameObject* gameObject;
	Mesh* meshPtr;
public:
	Scene0();
	~Scene0();
	bool OnCreate(const char* title, int xPos, int yPos, int width, int height, bool fullScreen)override;
	void HandleEvents()override;
	void Update()override;
	void Render()const override;
	void OnDestroy()override;
	
};

#endi
