@echo off
set /p "timer=The device will shut down. How long until it should restart: "
shutdown /s /t %timer% /d p:4:1 /c "El dispositivo tiene una actualizacion pendiente"
@echo off
timeout /t 2
shutdown /a