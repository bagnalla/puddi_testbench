#define GLM_FORCE_RADIANS
#include "Puddi.h"
#include "LightSource.h"
#include "AnimatedObject.h"
#include "Texture.h"
#include "Skybox.h"
#include "Font.h"
#include "Shadow.h"
#include "Schematic.h"
#include "Camera.h"
#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace puddi;
using namespace std;

LightSource *lightSource;
Object *objectContainer;
//DrawableObject *cube;
//DrawableObject *rect;
//DrawableObject *wall;

void reset();

void init(void)
{
    engine::AddRenderGraph();
    engine::AddRenderGraph();
    engine::AddRenderGraph();

    GLuint texture = Texture::LoadTexture("grumpycat", "textures/grumpycat1.png", "bumpmaps/grumpycat1_medium.png");
    //GLuint texture = Texture::LoadTexture("grumpycat", "textures/grumpycat1_d.png");
    //GLuint texture = Texture::LoadTexture("rough", "textures/rough4.jpg", "bumpmaps/rough4_bumpmap_fine.jpg");
    Texture::LoadBumpMap("rough1", "bumpmaps/rough1_bumpmap_fine.jpg");
    Texture::LoadBumpMap("rough2", "bumpmaps/rough2_bumpmap_fine.jpg");
    Texture::LoadBumpMap("rough3", "bumpmaps/rough3_bumpmap_fine.jpg");
    Texture::LoadBumpMap("rough5", "bumpmaps/rough5_bumpmap_fine.jpg");
    GLuint bump = Texture::LoadBumpMap("rough4", "bumpmaps/rough4_bumpmap_fine.jpg");
    //GLuint bump = Texture::LoadBumpMap("rough", "bumpmaps/Shrek-and-Yoda_NRM.jpg");
    Texture::LoadCubeMap("skybox_2", "textures/skybox2.jpg");
    //GLuint texture = Texture::LoadTexture("shrek", "textures/Shrek-and-Yoda (copy).jpg");
    //GLuint texture = Texture::CreateTextureFromString("bakow", "bakow_string", "fonts/Bitstream/VeraMono-Bold.ttf", 24, vec3(1.0f, 0.0f, 0.0f));

//    Schematic::LoadSchematic("models/rounded.obj", "pill");
//    Schematic::LoadSchematic("models/cube rounded - 554 faces.obj", "rounded_cube");
//    Schematic::LoadSchematic("models/grumpycat.obj", "grumpycat");
//    Schematic::LoadSchematic("models/R2-D2.obj", "r2d2");
	Skeleton::LoadSkeleton("models/ninja.ms3d", "ninja");
	Schematic::LoadSchematic("models/ninja.ms3d", "ninja");

	//Skeleton::LoadSkeleton("models/game muscle guy.blend", "big_guy");
	//Schematic::LoadSchematic("models/game muscle guy.blend", "big_guy");

    engine::MainCamera->SetPosition(vec4(0.0f, -5.0f, 0.0f, 1.0f));
    engine::MainCamera->LookAt(vec4(0.0f, 0.0f, 0.0f, 1.0f));
    //engine::MainCamera->SetZoomOut(10.0f);

    lightSource = LightSource::ObtainLightSource();
    lightSource->ambient = vec4(1.0, 1.0, 1.0, 1.0);
    lightSource->diffuse = vec4(1.0, 1.0, 1.0, 1.0);
    lightSource->specular = vec4(1.0, 1.0, 1.0, 1.0);
    lightSource->position = vec4(-250.0f, -500.0f, 500.0f, 0.0f);
    lightSource->UpdateMatrix();
    LightSource::UpdateLightSourceMatricesInShaders();

    //wall = new Cube(engine::GetRootObject());
    //wall = new DrawableObject(engine::GetRootObject(), Schematic::GetSchematicByName("geodesic_weave"));
    //wall->RotateX(static_cast<float>(M_PI / 2.0f));
    //wall->SetScaleX(200.0f);
    //wall->SetScaleY(100.0f);
    //wall->SetScale(10.0f);
    //wall->SetPosition(vec4(0.0f, 10.f, 0.0f, 1.0f));
    //wall->SetMaterial(Material::Plastic(vec4(0.5f, 0.1f, 0.5f, 1.0f)));
    //wall->SetMaterial(Material::Vibrant(vec4(0.5f, 0.1f, 0.5f, 1.0f)));
    //wall->SetMaterial(Material::Medium(vec4(0.5f, 0.1f, 0.5f, 1.0f)));
    //wall->SetMaterial(Material::BlackRubber());
    //wall->SetBumpMap(bump);
    //wall->SetTexture(texture);

    //auto terrainMesh = new TerrainVertexMesh(HeightMapTerrain::CreateTerrainMeshFromFile("textures/ocaml_logo_2.png", 25.0f, 25.0f, 0.1f));
    ////auto terrainMesh = new TerrainVertexMesh(HeightMapTerrain::CreateTerrainMeshFromFile("textures/ou_logo_1.png", 25.0f, 25.0f, 0.1f));
    //Texture::LoadTexture("sand1", "textures/sand1.jpg", "bumpmaps/sand1_NRM.jpg");
    //Texture::LoadTexture("grass1", "textures/grass1.jpg", "bumpmaps/grass1_NRM.jpg");
    //Texture::LoadTexture("stone1", "textures/stone1.jpg", "bumpmaps/stone1_NRM.jpg");
    //Texture::LoadTexture("snow1", "textures/snow1.jpg", "bumpmaps/snow1_NRM.jpg");
    //terrainMesh->SetTexture1(Texture::GetTextureByName("sand1"));
    //terrainMesh->SetTexture2(Texture::GetTextureByName("grass1"));
    //terrainMesh->SetTexture3(Texture::GetTextureByName("stone1"));
    //terrainMesh->SetTexture4(Texture::GetTextureByName("snow1"));
    //terrainMesh->SetTextureHeights(vec4(0.0f, 0.3f, 0.5f, 0.9f));
    ////DrawableObject *terrainContainer = new DrawableObject(engine::GetRootObject(), terrainMesh);
    ////terrainContainer->Scale(0.01f);

    //if (Schematic::InitSchematic("models/cube rounded.obj", "cube") < 0)
    //if (Schematic::InitSchematic("models/cube rounded - 554 faces.obj", "cube") < 0)
    //if (Schematic::InitSchematic("models/alien_boss_spider.obj", "cube", "alien_boss_spider") < 0)
    //if (Schematic::InitSchematic("models/bb8.obj", "cube", "bb8") < 0)
    //    std::cerr << "error loading cube rounded model\n";

    //auto terrain = new DrawableObject(engine::GetRootObject());
    //terrain->AddVertexMesh(terrainMesh);
    //terrain->SetScale(0.1f);
    //terrain->SetScaleX(0.25f);
    //terrain->SetScaleY(0.25f);
    //terrain->RotateZ(M_PI / 2.0f);
    ////terrain->Translate(vec4(-1000.0f, -1000.0f, -1000.0f, 0.0f));
    ////terrain->Translate(vec4(-100.0f, -100.0f, -100.0f, 0.0f));
    ////terrain->Translate(vec4(-20.0f, -125.0f, -125.0f, 0.0f));
    //terrain->Translate(vec4(0.0f, 150.0f, -125.0f, 0.0f));

//    for (int i = 1; i < 1; ++i)
//    {
//        for (int j = 0; j < 1; ++j)
//        {
//            auto terrain = new DrawableObject(engine::GetRootObject());
//            terrain->AddVertexMesh(new TerrainVertexMesh(*terrainMesh));
//            terrain->SetScale(1.0f);
//            //terrain->Translate(vec4(-1000.0f, -1000.0f, -1000.0f, 0.0f));
//            terrain->Translate(vec4(-100.0f, -100.0f, -100.0f, 0.0f));
//            terrain->Translate(vec4(-254.0f * i, -254.0f * j, 0.0f, 0.0f));
//            //terrain->Translate(vec4(-1024.0f * i, -1024.0f * j, 0.0f, 0.0f));
//        }
//    }
//
//    terrain = new DrawableObject(engine::GetRootObject());
//    terrain->AddVertexMesh(new TerrainVertexMesh(*terrainMesh));
//    terrain->SetScale(1.0f);
//    //terrain->Translate(vec4(-1000.0f, -1000.0f, -1000.0f, 0.0f));
//    terrain->Translate(vec4(-100.0f, -100.0f, -100.0f, 0.0f));
//    terrain->Translate(vec4(0.0f, -254.0f, 0.0f, 0.0f));
//
//    terrain = new DrawableObject(engine::GetRootObject());
//    terrain->AddVertexMesh(new TerrainVertexMesh(*terrainMesh));
//    terrain->SetScale(1.0f);
//    //terrain->Translate(vec4(-1000.0f, -1000.0f, -1000.0f, 0.0f));
//    terrain->Translate(vec4(-100.0f, -100.0f, -100.0f, 0.0f));
//    terrain->Translate(vec4(-254.0f, 0.0f, 0.0f, 0.0f));

    // CONTAINERS
    objectContainer = new Object(engine::GetRootObject());

    Skybox *skybox = new Skybox(engine::MainCamera);
    skybox->SetCubeMap(Texture::GetCubeMapByName("skybox_2"));
    skybox->SetEmissive(true);
    skybox->SetScale(engine::ViewDistance);
    skybox->DisableShadowCasting();

//    DrawableObject *cat = new DrawableObject(engine::GetRootObject(), Schematic::GetSchematicByName("grumpycat"));
//    cat->SetScale(0.5f);
//    cat->Translate(vec4(0.0f, 0.0f, 5.0f, 0.0f));

    // OBJECTS
    //rect = new Rectangle(objectContainer);
    //rect->SetTexture(texture);
    //rect->RotateX(M_PI / 2.0f);

    // ninja
    auto ninja = new AnimatedObject(engine::GetRootObject(), Schematic::GetSchematicByName("ninja"), Skeleton::GetSkeletonByName("ninja"), Skeleton::GetAnimationsBySkeletonName("ninja"));
    //cube->SetTexture(texture);
    //cube->SetScale(100);
    //r2d2->Translate(vec4(-50.0f, 0.0f, 0.0f, 0.0f));
	ninja->RotateX(-M_PI / 2.0f);
	ninja->RotateZ(M_PI);
	ninja->Scale(1.0f);
    ninja->SetPosition(vec4(-2.0f, -2.0f, 0.0f, 1.0f));
	ninja->EnableAnimation();
	//ninja->SetActiveAnimation("");
	//ninja->SetAnimationTicksPerSecond("", 10.0f);
	ninja->SetActiveAnimation("<MS3DMasterAnim>");
	ninja->SetAnimationTicksPerSecond("<MS3DMasterAnim>", 10.0f);

    for (size_t i = 0; i < 50; ++i) {
        for (size_t j = 0; j < 25; ++j) {
            auto n = new AnimatedObject(engine::GetRootObject(), Schematic::GetSchematicByName("ninja"),
                                        Skeleton::GetSkeletonByName("ninja"),
                                        Skeleton::GetAnimationsBySkeletonName("ninja"));
            n->RotateX(-M_PI / 2.0f);
            n->RotateZ(M_PI);
            n->Scale(0.5f);
            n->SetPosition(vec4(i * 2.0f, j * 2.0f, 0.0f, 1.0f));
            n->EnableAnimation();
            n->SetActiveAnimation("<MS3DMasterAnim>");
            n->SetAnimationTicksPerSecond("<MS3DMasterAnim>", 10.0f);
            n->SetAnimationProgress(fmodf(i * j / 100.0f, 100.0f));
        }
    }

	//auto big_guy = new DrawableObject(engine::GetRootObject(), Schematic::GetSchematicByName("big_guy"));


    //DrawableObject *object = new DrawableObject(objectContainer, VertexMesh::GetVertexMeshPrototypeByName("a"));
    ////DrawableObject *object = new Rectangle(objectContainer);
    //object->SetTexture(Texture::GetTextureByName("myfont"));
    //object->SetBumpMapEnabled(false);
    //object->RotateX(M_PI / 2.0f);

    //int rows = 10;
    //int cols = 10;
    //for (int i = 0; i < rows; ++i)
    //{
        //for (int j = 0; j < cols; ++j)
        //{
            //DrawableObject *object = new DrawableObject(objectContainer, VertexMesh::GetVertexMeshPrototypeByName(std::string(1, i * cols + j + 32)));
            //object->SetTexture(Texture::GetTextureByName("myfont"));
            //object->RotateX(M_PI / 2.0f);
            //object->Translate(vec4(j, 0.0f, -i, 0.0f));
        //}
    //}

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
        engine::MainCamera->InputEvent(ev);

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
            engine::UpdateProjectionMatrixAndViewport();
        }
    }
//    if (cube != nullptr)
//        cube->RotateZ(1.0f / 2000.0f * GrumpyConfig::GetGameSpeedFactor());

    //rect->RotateZ(1.0f / 2000.0f * GrumpyConfig::GetGameSpeedFactor());

    return 0;
}

void enableShadows()
{
    engine::EnableShadows(SHADOW_MODE_UNI, SHADOW_RESOLUTION_EXTRA_HIGH);
    // overwrite z range to give better shadow precision
    Shadow::SetZRange(100.0f, engine::ViewDistance);

    engine::SetShadowLightPosition(vec3(lightSource->position));
}

int main(int argc, char **argv)
{
    if (int initStatus = engine::Init(1000.0f) != 0)
        return initStatus;

    init();

    engine::RegisterPostInitFunction(enableShadows);

    engine::RegisterUpdateFunction(update);

    return engine::Run();
}
