# build_glfw.ps1

# Paths
$GLFW_SRC = "build/deps/GLFW/glfw-3.4"
$BUILD_DIR = "$GLFW_SRC\build"

# Create build directory if it doesn't exist
if (-Not (Test-Path $BUILD_DIR)) { New-Item -ItemType Directory -Path $BUILD_DIR | Out-Null }

# Navigate to build folder
Set-Location $BUILD_DIR

# Configure with CMake (minimal build, static library)
cmake .. `
    -G "MinGW Makefiles" `
    -DBUILD_SHARED_LIBS=OFF `
    -DGLFW_BUILD_EXAMPLES=OFF `
    -DGLFW_BUILD_TESTS=OFF `
    -DGLFW_BUILD_DOCS=OFF `
    -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build . --config Release