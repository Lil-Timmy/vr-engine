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

cmake -B ./build
Error "Project failed to build."

cmake --build ./build --config $config
Error "Project failed to link."

& "./build/$config/vr-engine"
Error "Project failed to run."