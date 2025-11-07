param
(
    [string]$config
)


function Error($message)
{
    if ($LASTEXITCODE -ne 0)
    {
        Write-Host "$message" -ForegroundColor Red
        exit $LASTEXITCODE
    }
}


if (-not $config)
{
    Write-Host "No config was specified. (Debug, Release)" -ForegroundColor Red
    exit 1
}
elseif ($config -ne "Debug" -and $config -ne "Release")
{
    Write-Host "$config config not supported. (Debug, Release)" -ForegroundColor Red
    exit 1
}

Write-Host "Building..." -ForegroundColor Green
cmake -B ./build -G "Ninja" -DCMAKE_CXX_COMPILER=clang++ "-DCMAKE_BUILD_TYPE=$config" -DCMAKE_CXX_FLAGS="-target x86_64-w64-mingw32"
Error "Project failed to build."

Write-Host "Linking..." -ForegroundColor Green
ninja -C ./build
Error "Project failed to link."

Write-Host "Running..." -ForegroundColor Green
& "./bin/$config/vr-engine.exe"
Error "Project failed to run."