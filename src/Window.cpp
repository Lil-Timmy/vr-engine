#include <Window.h>








namespace Engine
{
    const str&   Window::Title     () { return title;      } void Window::Title    (const str&  _value)
    {
        title      = _value;
        glfwSetWindowTitle(handle, title.c_str());
    }
    const ivec2 Window::Position  () { return position;   } void Window::Position  (const ivec2 _value)
    {
        position   = _value;
        glfwSetWindowPos(handle, position.x, position.y);
    }
    const uvec2 Window::Size      () { return size;       } void Window::Size      (const uvec2 _value)
    {
        size       = _value;
        glfwSetWindowSize(handle, i32(size.x), i32(size.y));
    }
          bool  Window::Minimized () { return minimized;  } void Window::Minimized (const bool  _value)
    {
        minimized  =  _value;
        
        minimized ?
            glfwIconifyWindow(handle):
            glfwRestoreWindow(handle);
    }
          bool  Window::Maximized () { return maximized;  } void Window::Maximized (const bool  _value)
    {
        maximized  =  _value;
        
        maximized ?
            glfwMaximizeWindow(handle):
            glfwRestoreWindow (handle);
    }
          bool  Window::Fullscreen() { return fullscreen; } void Window::Fullscreen(const bool  _value)
    {
        fullscreen = _value;
        
        if (fullscreen)
        {
            i32 _count;
            GLFWmonitor** _monitors = glfwGetMonitors(&_count);
            
                  i32          _bestOverlap   = i32MIN
                  GLFWmonitor* _bestMonitor   = nullptr;
            const GLFWvidmode* _bestVideoMode = nullptr;
            
            for (i32 _i = 0; _i < _count; _i++)
            {
                      GLFWmonitor* _monitor   = _monitors[_i];
                const GLFWvidmode* _videoMode = glfwGetVideoMode(_monitor);
                ivec2             _position   = ivec2(0                , 0                 );
                ivec2             _size       = ivec2(_videoMode->width, _videoMode->height);
                glfwGetMonitorPos(_monitor, &_position.x, &_position.y);
                
                i32 _overlap = 
                    (std::min(position.x + i32(size.x), _position.x + _size.x) - std::max(position.x, _position.x)) *
                    (std::min(position.y + i32(size.y), _position.y + _size.y) - std::max(position.y, _position.y));
                
                if (_overlap > _bestOverlap)
                {
                    _bestOverlap   = _overlap;
                    _bestMonitor   = _monitor;
                    _bestVideoMode = _videoMode;
                }
            }
            
            prevPosition = position;
            prevSize     = size;
            
            position = ivec2(0                         , 0                          );
            size     = uvec2(u32(_bestVideoMode->width), u32(_bestVideoMode->height));
            
            glfwSetWindowMonitor(handle, _bestMonitor, position    .x, position    .y, i32(size    .x), i32(size    .y), GLFW_DONT_CARE);
        }
        else
        {
            glfwSetWindowMonitor(handle, nullptr     , prevPosition.x, prevPosition.y, i32(prevSize.x), i32(prevSize.y), GLFW_DONT_CARE);
        }
    }
          bool  Window::Focused   () { return focused;    } void Window::Focused   (const bool  _value)
    {
        focused  =  _value;
        
        if (focused) glfwFocusWindow(handle);
    }
          bool  Window::Visible   () { return visible;    } void Window::Visible   (const bool  _value)
    {
        visible    = _value;
        
        visible ?
            glfwShowWindow(handle):
            glfwHideWindow(handle);
    }
          u32   Window::VSync     () { return vSync;      } void Window::VSync     (const u32   _value)
    {
        vSync     = _value;
        
        glfwSwapInterval(i32(vSync));
    }
          bool  Window::Closed    () { return closed;     } void Window::Closed    (const bool  _value)
    {
        closed    = _value;
        
        glfwSetWindowShouldClose(handle, closed);
    }
    
          bool                  Window::KeyPressed    (const int _key   ) { return pressedKeys    .find(_key   ) != pressedKeys    .end(); }
          bool                  Window::KeyHeld       (const int _key   ) { return heldKeys       .find(_key   ) != heldKeys       .end(); }
          bool                  Window::KeyReleased   (const int _key   ) { return releasedkeys   .find(_key   ) != releasedkeys   .end(); }
    const std::vector<ichar32>& Window::PressedChars  (                 ) { return pressedChars;                                           }
    
          bool                  Window::ButtonPressed (const int _button) { return pressedButtons .find(_button) != pressedButtons .end(); }
          bool                  Window::ButtonHeld    (const int _button) { return heldButtons    .find(_button) != heldButtons    .end(); }
          bool                  Window::ButtonReleased(const int _button) { return releasedButtons.find(_button) != releasedButtons.end(); }
          i32                   Window::ScrollWheel   (                 ) { return scrollWheel;                                            }
          ivec2                 Window::CursorPosition(                 ) { return cursorPosition;                                         }
    
    const std::vector<str    >& Window::DroppedFiles  (                 ) { return droppedFiles;                                           }
    
    Window::Window(const WindowSettings _settings)
    {
        glfwInit(); // TODO: Only init/terminate if first/last usage, also make a glfw & opengl wrapper.
        
        glfwWindowHint(GLFW_VISIBLE                , GLFW_FALSE              );
        glfwWindowHint(GLFW_POSITION_X             , _settings.position.x    );
        glfwWindowHint(GLFW_POSITION_Y             , _settings.position.y    );
        glfwWindowHint(GLFW_RESIZABLE              , _settings.resizable     );
        glfwWindowHint(GLFW_DECORATED              , _settings.decorated     );
        glfwWindowHint(GLFW_FLOATING               , _settings.alwaysOnTop   );
        glfwWindowHint(GLFW_CENTER_CURSOR          , _settings.centerCursor  );
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, _settings.transparent   );
        glfwWindowHint(GLFW_FOCUS_ON_SHOW          , _settings.focusOnVisible);
        glfwWindowHint(GLFW_MOUSE_PASSTHROUGH      , _settings.ignoreCursor  );
        
        handle = glfwCreateWindow(i32(_settings.size.x), i32(_settings.size.y), "", nullptr, nullptr);
        
        glfwSetWindowUserPointer(handle, this);
        glfwMakeContextCurrent  (handle      );
        
        Title     (_settings.title     );
        Position  (_settings.position  );
        Size      (_settings.size      );
        Focused   (_settings.focused   );
        Minimized (_settings.minimized );
        Maximized (_settings.maximized );
        Fullscreen(_settings.fullscreen);
        Visible   (_settings.visible   );
        VSync     (_settings.vSync     );
        
        glfwSetWindowPosCallback     (handle, PositionCallback);
        glfwSetWindowSizeCallback    (handle, ResizeCallback  );
        glfwSetWindowCloseCallback   (handle, CloseCallback   );
        glfwSetWindowFocusCallback   (handle, FocusCallback   );
        glfwSetWindowIconifyCallback (handle, MinimizeCallback);
        glfwSetWindowMaximizeCallback(handle, MaximizeCallback);
        glfwSetKeyCallback           (handle, KeyCallback     );
        glfwSetCharCallback          (handle, CharCallback    );
        glfwSetMouseButtonCallback   (handle, ButtonCallback  );
        glfwSetScrollCallback        (handle, ScrollCallback  );
        glfwSetCursorPosCallback     (handle, CursorCallback  );
        glfwSetDropCallback          (handle, DropFileCallback);
    }
    Window::~Window()
    {
        glfwDestroyWindow(handle);
        handle = nullptr;
        
        
        glfwTerminate();
    }
    
    bool Window::Update()
    {
        pressedKeys    .clear();
        releasedkeys   .clear();
        pressedChars   .clear();
        
        pressedButtons .clear();
        releasedButtons.clear();
        scrollWheel = 0;
        
        droppedFiles.clear();
        
        glfwMakeContextCurrent(handle);
        glfwSwapBuffers       (handle);
        glfwPollEvents        (      );
        
        return !glfwWindowShouldClose(handle);
    }
    
    
    void Window::PositionCallback(GLFWwindow* _handle, i32 _x, i32 _y)
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        _window->position = ivec2(i32(_x), i32(_y));
    }
    void Window::ResizeCallback  (GLFWwindow* _handle, i32 _x, i32 _y)
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        _window->size = uvec2(u32(_x), u32(_y));
    }
    void Window::CloseCallback   (GLFWwindow* _handle                )
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        _window->closed = true;
    }
    void Window::FocusCallback   (GLFWwindow* _handle, i32 _focused  )
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        _window->focused = _focused;
    }
    void Window::MinimizeCallback(GLFWwindow* _handle, i32 _minimized)
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        _window->minimized = _minimized;
    }
    void Window::MaximizeCallback(GLFWwindow* _handle, i32 _maximized)
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        _window->maximized = _maximized;
    }
    void Window::KeyCallback     (GLFWwindow* _handle, i32 _key      , i32, i32 _action, i32)
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        if      (_action == GLFW_PRESS  )
        {
            _window->pressedKeys .insert(_key);
            _window->heldKeys    .insert(_key);
        }
        else if (_action == GLFW_RELEASE)
        {
            _window->heldKeys    .erase (_key);
            _window->releasedkeys.insert(_key);
        }
    }
    void Window::CharCallback    (GLFWwindow* _handle, u32 _character                       )
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        _window->pressedChars.push_back(char32_t(_character));
    }
    void Window::ButtonCallback  (GLFWwindow* _handle, i32 _button   ,      i32 _action, i32)
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        if      (_action == GLFW_PRESS  )
        {
            _window->pressedButtons .insert(_button);
            _window->heldButtons    .insert(_button);
        }
        else if (_action == GLFW_RELEASE)
        {
            _window->heldButtons    .erase (_button);
            _window->releasedButtons.insert(_button);
        }
    }
    void Window::ScrollCallback  (GLFWwindow* _handle, d64    , d64 _y)
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        _window->scrollWheel = (_y > 0) - (_y < 0);
    }
    void Window::CursorCallback  (GLFWwindow* _handle, d64  _x, d64 _y)
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        _window->cursorPosition = ivec2(i32(_x), i32(_y));
    }
    void Window::DropFileCallback(GLFWwindow* _handle, i32 _pathCount, const char* _paths[])
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        for (int _i = 0; _i < _pathCount; _i++)
        {
            _window->droppedFiles.push_back(str(_paths[_i]));
        }
    }
}