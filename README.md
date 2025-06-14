<h2>Custom Game Engine</h2> <br/>

This is a game engine written using OpenGL 3.3 and C++17.<br/><br/>
It contains a plethora of structures, classes, and functions that enable the user to;<br/>
- Render various shapes, sprites, decals, and meshes with different materials, using either the CPU or GPU. Although the software rendering method, which utilizes the CPU to draw what the user desires pixel by pixel, is relatively fast, it is better to opt for GPU utilization for rendering in performance-sensitive applications, which combines the power of parallel computing and batch rendering.
- Have control over the underlying structures a graphical application is comprised of, such as buffers and shaders, which creates opportunities for further optimizations.
- Save and load data using the custom save system of the engine, which resembles XML.
- Use the math library provided with the engine for graphics development, which contains vectors, matrices, quaternions, conversion functions, vector swizzling, intersection tests, and various utilities.
- Use the input modules to check for key & mouse button states.
- Enable post-processing and choose the desired post-processing mode.
- Use the "gui.h" & "menu.h" class for better user interaction.
- Experiment with different lighting to find which combination suits the application best.