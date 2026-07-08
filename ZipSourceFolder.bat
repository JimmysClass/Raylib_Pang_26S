rem replace "TypeYourStudentIDHere" with your student ID

powershell.exe -NoProfile -ExecutionPolicy Bypass -Command ^
"Compress-Archive -Path Source -DestinationPath source_TypeYourStudentIDHere.zip -Force"
