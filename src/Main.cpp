#include <Window.h>








int main()
{
    Engine::Window _window
    (
        "VR-ENGINE"    ,
        ivec2(540, 270),
        uvec2(960, 540),
        true           ,
        false          ,
        false          ,
        false          ,
        true           ,
        true           ,
        true           ,
        true           ,
        false          ,
        false          ,
        false          ,
        false          ,
        false
    );
    while (_window.Update())
    {
        continue;
    }
    
    return 0;
}