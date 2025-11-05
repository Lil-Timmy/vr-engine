#include "GLFW/glfw3.h"
#include "Types.h"
#include <Window.h>




int main()
{
    Engine::Window _window
    (
        Engine::WindowSettings
        {
            .title          = "Test Window"  ,
            .position       = ivec2(540, 270),
            .size           = uvec2(960, 540),
            .minimized      = false          ,
            .maximized      = false          ,
            .fullscreen     = false          ,
            .focused        = false          ,
            .visible        = true           ,
            .vSync          = false          ,
            .resizable      = true           ,
            .decorated      = true           ,
            .alwaysOnTop    = false          ,
            .centerCursor   = false          ,
            .transparent    = false          ,
            .focusOnVisible = false          ,
            .ignoreCursor   = false          ,
        }
    );
    
    fvec2 _position = fvec2(0, 270);
    fvec2 _velocity = fvec2(0, 0);
    while (_window.Update())
    {
        if (_window.KeyPressed(GLFW_KEY_F11)) _window.Fullscreen(!_window.Fullscreen());
        
        continue;
    }
    
    return 0;
}