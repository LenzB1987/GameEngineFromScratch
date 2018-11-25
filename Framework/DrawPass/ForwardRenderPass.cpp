#include "ForwardRenderPass.hpp"
#include "GraphicsManager.hpp"
#include "IShaderManager.hpp"

using namespace My;
using namespace std;

void ForwardRenderPass::Draw(Frame& frame)
{
    auto shaderProgram = g_pShaderManager->GetDefaultShaderProgram(DefaultShaderIndex::Pbr);

    // Set the color shader as the current shader program and set the matrices that it will use for rendering.
    g_pGraphicsManager->UseShaderProgram(shaderProgram);
    g_pGraphicsManager->SetPerFrameConstants(frame.frameContext);
    g_pGraphicsManager->SetLightInfo(frame.lightInfo);
    g_pGraphicsManager->SetShadowMaps(frame);
    g_pGraphicsManager->SetSkyBox(frame.frameContext);
    g_pGraphicsManager->SetPerBatchConstants(frame.batchContexts);
    g_pGraphicsManager->DrawBatch(frame.batchContexts);
}