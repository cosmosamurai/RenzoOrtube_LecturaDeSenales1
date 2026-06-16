# TP Evaluativo 1-D – Lectura de Señales
Alumno: Renzo Ortube
Mecánica: Lectura de Señales

## Clases nuevas (TP3)
Carpeta: Source/EntregasPracticas/TP3_LecturaDeSenales/

- SignalInteractable.h — Interface + USTRUCT FSignalObjectData
- SignalTargetBase.h / .cpp — Actor base de los 5 objetos detectables
- SignalScannerComponent.h / .cpp — Componente principal (LineTrace, pulso, códice)

## Clases modificadas
- BP_ThirdPersonCharacter — se agregó SignalScannerComponent + IA_Escanear
