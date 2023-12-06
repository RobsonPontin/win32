## COM Project using ATL libs

A simple sample project where a WinUI 3 C++/WinRT Application consumes COM objects from 2 types of COM servers:

1. ATLComProject - it is a `InProceServer32` which represents a dynamic link library (DLL) implementation
2. ATLComProjectExe - it is a `LocalServer32` which represents an executable implementation which accepts command-line arguments

## References
- https://learn.microsoft.com/en-us/cpp/atl/active-template-library-atl-concepts?view=msvc-170
- https://learn.microsoft.com/en-us/windows/win32/com/inprocserver32
- https://learn.microsoft.com/en-us/windows/win32/com/localserver32
