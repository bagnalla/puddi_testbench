#define GLM_FORCE_RADIANS
#include "Puddi.h"
#include "LightSource.h"
#include "Texture.h"
// #include "Skybox.h"
// #include "Font.h"
// #include "Shadow.h"
// #include "Schematic.h"
#include "Camera.h"
#include "Geometry.h"
#include "Sphere.h"
#include "Line.h"
#include "Cube.h"
#include "RenderGraph.h"

#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace puddi;
using namespace std;

LightSource *lightSource;
Object *objectContainer;
Scene *world_scene;
Camera *world_camera;

void reset();

// vec4 make_normal(const vec4 &a, const vec4 &b, const vec4 &c)
vec3 make_normal(const vec3 &a, const vec3 &b, const vec3 &c)
{
  return normalize(cross(b-a, c-a));
}

struct Vec3Cmp {
  bool operator()(const vec3& a, const vec3& b) const { 
    return true;
  }
};

void init(void)
{
  world_scene = engine::GetWorldScene();
  world_camera = engine::GetWorldCamera();

  world_camera->SetPosition(vec4(0.0f, -5.0f, 0.0f, 1.0f));
  world_camera->LookAt(vec4(0.0f, 0.0f, 0.0f, 1.0f));
  //engine::MainCamera->SetZoomOut(10.0f);

  lightSource = LightSource::ObtainLightSource();
  lightSource->ambient = vec4(1.0, 1.0, 1.0, 1.0);
  lightSource->diffuse = vec4(1.0, 1.0, 1.0, 1.0);
  lightSource->specular = vec4(1.0, 1.0, 1.0, 1.0);
  lightSource->position = vec4(-250.0f, -500.0f, 500.0f, 0.0f);
  lightSource->UpdateMatrix();
  LightSource::UpdateLightSourceMatricesInShaders();

  // CONTAINERS
  // objectContainer = new Object(engine::GetRootObject());

  // Skybox *skybox = new Skybox(engine::MainCamera);
  // skybox->SetCubeMap(Texture::GetCubeMapByName("skybox_2"));
  // skybox->SetEmissive(true);
  // skybox->SetScale(engine::ViewDistance);
  // skybox->DisableShadowCasting();

  // cout << "making sphere" << endl;
  // auto sphere = new Sphere(world_scene->GetRootObject());
  // cout << "adding sphere to world scene" << endl;
  // // auto sphere = new Cube(world_scene->GetRootObject());
  // world_scene->AddObject(sphere);
  // cout << "setting emissive" << endl;
  // sphere->SetEmissive(true);
  // sphere->SetEmissive(true);
  // cout << "setting emission color" << endl;
  // sphere->SetEmissionColor(vec4(0.0f, 0.5f, 1.0f, 1.0f));

  // auto sphere_vertices = Sphere::GetSphereVertices();
  // auto sphere_vertices = Cube::GetCubeVertices();
  // auto sphere_normals = Sphere::GetSphereNormals();

  // // Map vertices to triangles they are a part of.
  // // map<vec3, vector<tuple<vec3, vec3, vec3>>>
  //   // vert_tri_map([](const vec3 &v1, const vec3 &v2) { return true; });
  // map<vec3, vector<tuple<vec3, vec3, vec3>>, Vec3Cmp> vert_tri_map;

  // // for (auto it = sphere_vertices.begin();
  // //      it != sphere_vertices.end(); ++it) {
  // // auto v = *it;
  // for (size_t i = 0; i < sphere_vertices.size(); i += 3) {
  //   auto v1 = vec3(sphere_vertices[i]);
  //   auto v2 = vec3(sphere_vertices[i+1]);
  //   auto v3 = vec3(sphere_vertices[i+2]);
  //   // cout << v1.x << " " << v1.y << " " << v1.z << endl;
    
  //   vert_tri_map.emplace(v1, vector<tuple<vec3, vec3, vec3>>());
  //   vert_tri_map.emplace(v2, vector<tuple<vec3, vec3, vec3>>());
  //   vert_tri_map.emplace(v3, vector<tuple<vec3, vec3, vec3>>());

  //   vert_tri_map[v1].push_back(make_tuple(v1, v2, v3));
  //   vert_tri_map[v2].push_back(make_tuple(v1, v2, v3));
  //   vert_tri_map[v3].push_back(make_tuple(v1, v2, v3));
  // }


  engine::SetLineWidth(5);
  // engine::SetLineWidth(10);

  Line *l = new Line(world_scene->GetRootObject());
  l->SetEmissive(true);
  l->SetEmissionColor(vec4(0.0f, 0.0f, 0.0f, 1.0f));
  l->SetWorldPoints(vec4(-10, 0, 0, 1), vec4(10, 0, 0, 1));
  // world_scene->AddObject(l);
  l->AddMeshesToScene(world_scene);
  
  // sphere->DisableRender();

  auto square_verts = Geometry::CreateRectangleTriangles();

  auto linesContainer = new Object(world_scene->GetRootObject());
  // world_scene->AddObject(linesContainer);

  // // for (size_t i = 0; i < sphere_vertices.size(); i += 2) {
  // for (size_t i = 0; i < square_verts.size(); ++i) {
  //   if (i == square_verts.size() - 1) break;
  //   auto l = new Line(linesContainer);
  //   l->AddMeshesToScene(world_scene);
  //   // l->SetWorldPoints(sphere_vertices[i], sphere_vertices[i+1]);
  //   l->SetWorldPoints(square_verts[i], square_verts[i+1]);
  //   l->AddMeshesToScene(world_scene);
  //   // cout << world_scene->GetRenderGraph()->Size() << endl;
  // }

  // drawableobject *cat =
  //   new DrawableObject(engine::GetRootObject(),
  // 		       Schematic::GetSchematicByName("grumpycat"));

  reset();
}

void reset()
{
}

//----------------------------------------------------------------------------

bool holdingMouseClick = false;
int update()
{
  SDL_Event ev;
  while (SDL_PollEvent(&ev))
  {
    // send event to camera
    world_camera->InputEvent(ev);

    // quit
    if (ev.type == SDL_QUIT)
    {
      return 1;
    }
    // key press
    else if (ev.type == SDL_KEYDOWN)
    {
      switch (ev.key.keysym.sym)
      {
	// EXIT PROGRAM
      case SDLK_ESCAPE:
	return 1;
	break;
	// ENABLE FULLSCREEN
      case SDLK_f:
	engine::ToggleFullScreen();
	break;
	/*case SDLK_1:
	  parser->AddTokenToQueue(new Token(engine::GetRootObject(), LexToken()));
	  break;*/
      case SDLK_r:
	reset();
	break;
      case SDLK_MINUS:
      case SDLK_UNDERSCORE:
	//                GrumpyConfig::SetGameSpeed(std::max(0.0f, GrumpyConfig::GetGameSpeed() - 0.1f));
	break;
      case SDLK_PLUS:
      case SDLK_EQUALS:
	//                GrumpyConfig::SetGameSpeed(GrumpyConfig::GetGameSpeed() + 0.1f);
	break;
      }
    }
    // mouse click
    else if (ev.type == SDL_MOUSEBUTTONDOWN)
    {
      holdingMouseClick = true;
    }
    // mouse release
    else if (ev.type == SDL_MOUSEBUTTONUP)
    {
      holdingMouseClick = false;
    }
    // mouse motion
    else if (ev.type == SDL_MOUSEMOTION)
    {
      //
    }
    // window event
    else if (ev.type == SDL_WINDOWEVENT)
    {
      engine::ViewportChange();
    }
  }
  //    if (cube != nullptr)
  //        cube->RotateZ(1.0f / 2000.0f * GrumpyConfig::GetGameSpeedFactor());

  //rect->RotateZ(1.0f / 2000.0f * GrumpyConfig::GetGameSpeedFactor());

  return 0;
}

int main(int argc, char **argv)
{
  if (int initStatus = engine::Init(1000.0f) != 0)
    return initStatus;

  init();

  engine::RegisterUpdateFunction(update);

  return engine::Run();
}
