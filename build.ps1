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

cmake -B ./build -G "Ninja" -DCMAKE_CXX_COMPILER=g++ "-DCMAKE_BUILD_TYPE=$config"
Error "Project failed to build."

ninja -C ./build
Error "Project failed to link."

& "./bin/$config/vr-engine.exe"
Error "Project failed to run."
