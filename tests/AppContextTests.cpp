#include <catch2/catch_all.hpp>

#include <v3d.hpp>

TEST_CASE("App lifecycle")
{
    V3D::Settings settings = {};
    settings.backend = V3D::Backend_Vulkan;
    settings.platform = V3D::Platform_GLFW;

    auto ctx = std::make_unique<V3D::Context>(settings);

    REQUIRE(ctx->settings() == settings);
    REQUIRE(ctx->windowManager() == nullptr);
    REQUIRE(ctx->scene() == nullptr);

    ctx->init();

    REQUIRE(ctx->settings() == settings);
    REQUIRE(ctx->windowManager() != nullptr);
    REQUIRE(ctx->scene() != nullptr);
}