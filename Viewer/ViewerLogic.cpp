#include "ViewerLogic.hpp"

#include "BaseApplication.hpp"
#include "SceneManager.hpp"
#include "geommath.hpp"

using namespace My;
using namespace std;

int ViewerLogic::Initialize() {
    int result;

    auto pSceneManager = dynamic_cast<BaseApplication*>(m_pApp)->GetSceneManager();

    cout << "[ViewerLogic] Viewer Logic Initialize" << endl;

    if (m_pApp->GetCommandLineArgumentsCount() > 1) {
        auto scene_filename = m_pApp->GetCommandLineArgument(1);
        cout << "[ViewerLogic] Loading Scene: " << scene_filename << endl;
        result = pSceneManager->LoadScene(scene_filename);
    } else {
        cout << "[ViewerLogic] Loading Splash Scene" << endl;
        result = pSceneManager->LoadScene("Scene/splash.ogex");
    }

    return result;
}

void ViewerLogic::Finalize() { cout << "[ViewerLogic] Finalize" << endl; }

void ViewerLogic::Tick() {}

void ViewerLogic::OnLeftKeyDown() {
    auto pSceneManager = dynamic_cast<BaseApplication*>(m_pApp)->GetSceneManager();

    auto& scene = pSceneManager->GetSceneForRendering();
    if (scene) {
        auto pCameraNode = scene->GetFirstCameraNode();
        if (pCameraNode) {
            auto local_axis = pCameraNode->GetLocalAxis();
            Vector3f camera_x_axis = local_axis[0];

            // pan camera along its local axis -x direction
            pCameraNode->MoveBy(camera_x_axis * -1.0f);
            auto target = pCameraNode->GetTarget();
            target -= camera_x_axis;
            pCameraNode->SetTarget(target);
        }
    }
}

void ViewerLogic::OnRightKeyDown() {
    auto pSceneManager = dynamic_cast<BaseApplication*>(m_pApp)->GetSceneManager();

    auto& scene = pSceneManager->GetSceneForRendering();
    if (scene) {
        auto pCameraNode = scene->GetFirstCameraNode();
        if (pCameraNode) {
            auto local_axis = pCameraNode->GetLocalAxis();
            Vector3f camera_x_axis = local_axis[0];

            // pan along camera local axis x direction
            pCameraNode->MoveBy(camera_x_axis);
            auto target = pCameraNode->GetTarget();
            target += camera_x_axis;
            pCameraNode->SetTarget(target);
        }
    }
}

void ViewerLogic::OnUpKeyDown() {
    auto pSceneManager = dynamic_cast<BaseApplication*>(m_pApp)->GetSceneManager();

    auto& scene = pSceneManager->GetSceneForRendering();
    if (scene) {
        auto pCameraNode = scene->GetFirstCameraNode();
        if (pCameraNode) {
            auto local_axis = pCameraNode->GetLocalAxis();
            Vector3f camera_y_axis = local_axis[1];

            // lifting camera along its local axis y direction
            pCameraNode->MoveBy(camera_y_axis);
            auto target = pCameraNode->GetTarget();
            target += camera_y_axis;
            pCameraNode->SetTarget(target);
        }
    }
}

void ViewerLogic::OnDownKeyDown() {
    auto pSceneManager = dynamic_cast<BaseApplication*>(m_pApp)->GetSceneManager();

    auto& scene = pSceneManager->GetSceneForRendering();
    if (scene) {
        auto pCameraNode = scene->GetFirstCameraNode();
        if (pCameraNode) {
            auto local_axis = pCameraNode->GetLocalAxis();
            Vector3f camera_y_axis = local_axis[1];

            // lifting camera along its local axis -y direction
            pCameraNode->MoveBy(camera_y_axis * -1.0f);
            auto target = pCameraNode->GetTarget();
            target -= camera_y_axis;
            pCameraNode->SetTarget(target);
        }
    }
}

void ViewerLogic::OnAnalogStick(int id, float deltaX, float deltaY) {
    auto pSceneManager = dynamic_cast<BaseApplication*>(m_pApp)->GetSceneManager();

    if (id == 1) {
        auto& scene = pSceneManager->GetSceneForRendering();
        if (scene) {
            auto pCameraNode = scene->GetFirstCameraNode();
            if (pCameraNode) {
                // pCameraNode->RotateBy(deltaY / (2.0 * PI), 0.0f, 0.0f);
                pCameraNode->RotateBy(0.0f, 0.0f, deltaX / (2.0 * PI));
            }
        }
    }
}
