#include <Window.h>








namespace Engine
{
    str   Window::Title     () { return title;      } void Window::Title     (const str   _value)
    {
        title      = _value;
        glfwSetWindowTitle(handle, title.c_str());
    }
    ivec2 Window::Position  () { return position;   } void Window::Position  (const ivec2 _value)
    {
        position   = _value;
        glfwSetWindowPos(handle, position.x, position.y);
    }
    uvec2 Window::Size      () { return size;       } void Window::Size      (const uvec2 _value)
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
            glfwIconifyWindow(handle):
            glfwRestoreWindow(handle);
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
        maximized  =  _value;
        
        maximized ?
            glfwIconifyWindow(handle):
            glfwRestoreWindow(handle);
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
    
    Window::Window
    (
        const str   _title         ,
        const ivec2 _position      ,
        const uvec2 _size          ,
        const bool  _minimized     ,
        const bool  _maximized     ,
        const bool  _fullscreen    ,
        const bool  _focused       ,
        const bool  _visible       ,
        const u32   _vSync         ,
        const bool  _resizable     ,
        const bool  _decorated     ,
        const bool  _alwaysOnTop   ,
        const bool  _centerCursor  ,
        const bool  _transparent   ,
        const bool  _focusOnVisible,
        const bool  _ignoreCursor
    )
    {
        glfwInit(); // TODO: Only init/terminate if first/last usage, also make a glfw & opengl wrapper.
        
        
        glfwWindowHint(GLFW_VISIBLE                , GLFW_FALSE     );
        glfwWindowHint(GLFW_RESIZABLE              , _resizable     );
        glfwWindowHint(GLFW_DECORATED              , _decorated     );
        glfwWindowHint(GLFW_FLOATING               , _alwaysOnTop   );
        glfwWindowHint(GLFW_CENTER_CURSOR          , _centerCursor  );
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, _transparent   );
        glfwWindowHint(GLFW_FOCUS_ON_SHOW          , _focusOnVisible);
        glfwWindowHint(GLFW_MOUSE_PASSTHROUGH      , _ignoreCursor  );
        
        handle = glfwCreateWindow(1, 1, "", nullptr, nullptr);
        
        glfwSetWindowUserPointer(handle, this);
        glfwMakeContextCurrent  (handle      );
        
        Title     (_title     );
        Position  (_position  );
        Size      (_size      );
        Focused   (_focused   );
        Minimized (_minimized );
        Maximized (_maximized );
        Fullscreen(_fullscreen);
        Visible   (_visible   );
        VSync     (_vSync     );
        
        glfwSetWindowPosCallback     (handle, PositionCallback);
        glfwSetWindowSizeCallback    (handle, ResizeCallback  );
        glfwSetWindowCloseCallback   (handle, CloseCallback   );
        glfwSetWindowFocusCallback   (handle, FocusCallback   );
        glfwSetWindowIconifyCallback (handle, MinimizeCallback);
        glfwSetWindowMaximizeCallback(handle, MaximizeCallback);
        glfwSetKeyCallback           (handle, KeyCallback     );
        glfwSetCharModsCallback      (handle, CharCallback    );
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
        glfwMakeContextCurrent(handle);
        glfwSwapBuffers(handle);
        glfwPollEvents();
        
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
    void Window::CloseCallback   (GLFWwindow* _handle)
    {
        Window* _window = static_cast<Window*>(glfwGetWindowUserPointer(_handle));
        _window->closed = true;
    }
    void Window::FocusCallback   (GLFWwindow* _handle, i32 _focused)
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
    void Window::KeyCallback     (GLFWwindow*, i32, i32, i32, i32)
    {
        
    }
    void Window::CharCallback    (GLFWwindow*, u32, i32)
    {
        
    }
    void Window::ButtonCallback  (GLFWwindow*, i32, i32, i32)
    {
        
    }
    void Window::ScrollCallback  (GLFWwindow*, d64, d64)
    {
        
    }
    void Window::CursorCallback  (GLFWwindow*, d64, d64)
    {
        
    }
    void Window::DropFileCallback(GLFWwindow*, i32, const char*[])
    {
        
    }
}