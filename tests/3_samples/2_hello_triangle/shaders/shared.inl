#pragma once

#include <daxa/daxa.inl>

struct DrawVertex
{
    daxa_f32vec4 pos, col;
};

DAXA_DECL_BUFFER_STRUCT(
    DrawVertexBuffer,
    {
        DrawVertex verts[3];
    }
)

struct DrawPush
{
#if DAXA_SHADERLANG == DAXA_SHADERLANG_GLSL
    daxa_RWBuffer(DrawVertexBuffer) face_buffer;
#elif DAXA_SHADERLANG == DAXA_SHADERLANG_HLSL
    daxa_BufferId vertex_buffer_id;
#endif
    // u32vec2 frame_dim;
};
