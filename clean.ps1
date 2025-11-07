if (Test-Path "./.cache") { Remove-Item -Path "./.cache" -Recurse }
if (Test-Path "./build") { Remove-Item -Path "./build" -Recurse }
if (Test-Path "./bin") { Remove-Item -Path "./bin" -Recurse }