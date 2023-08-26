# Description:

Automatically switches the camera to Third/First person in combat/when weapons are drawn and returns to the previous view afterwards

### Requirements

- [CMake](https://cmake.org/)
- [Vcpkg](https://github.com/microsoft/vcpkg)
- [Visual Studio Community Preview 2022](https://visualstudio.microsoft.com/): Install desktop development with C++ extension
- [CommonLibSSE](https://github.com/powerof3/CommonLibSSE): This is already included as git submodle
- **Environmental Variables**:
  - Add the cmake executable to your `PATH` environmental variable
  - Add the environment variable `VCPKG_ROOT` with the value as the path to the folder containing vcpkg

### Register Visual Studio as a Generator

- Open `x64 Native Tools Command Prompt`
- Run `cmake`
- Close the cmd window


### Build Instructions
```
git clone --recursive https://github.com/Styyx1/SwitchView-SKSE
```
then open the folder with Visual Studio, select the preset and build it

for the release config, you can simply run the build.bat file afterwards

### Compatibility 
works with Skyrim 1.5.97 and 
with Skyrim 1.6.629+

Does NOT work with VR or any 1.6 version below 1.6.629

### Credits:
dann1c - for helping me with the Clib setup  
nightfallstorm - for the 1.6 offset 
Loki - for the hook in RegenAdjuster  
suncalluntojethr0 - for the actual idea for the mod  
po3 - for lots of references  
SKSE team and everyone involved in CommonLib  
