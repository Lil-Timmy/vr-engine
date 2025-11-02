# Compile the c++ files into object files.
foreach ($file in Get-ChildItem src/ -Filter *.cpp)
{
    g++ -c $file.FullName -Iinclude -O3 -flto -o ("build/objects/" + $file.BaseName + ".o")
    
    if ($LASTEXITCODE -ne 0)
    {
        Write-Host "Binary compilation for $($file.Name) failed."
        exit $LASTEXITCODE
    }
}

# Link the c++ objects and libraries and build the executable.
g++ build/objects/*.o -Llib -lglfw3 -lopengl32 -lgdi32 -s -o build/build.exe

if ($LASTEXITCODE -ne 0)
{
    Write-Host "Failed to link libraries"
    exit $LASTEXITCODE
}

# If all compiled, run the project.
./build/build.exe