#pragma once

#include <GLFW/glfw3.h>
#include <Types.h>
#include <vector>
#include <set>



namespace Engine
{
    struct WindowSettings
    {
        public : const str   title          = "Window";
        public : const ivec2 position       = ivec2(0  , 0  );
        public : const uvec2 size           = uvec2(960, 540);
        public : const bool  minimized      = false;
        public : const bool  maximized      = false;
        public : const bool  fullscreen     = false;
        public : const bool  focused        = false;
        public : const bool  visible        = true;
        public : const u32   vSync          = false;
        
        public : const bool  resizable      = true;
        public : const bool  decorated      = true;
        public : const bool  alwaysOnTop    = false;
        public : const bool  centerCursor   = false;
        public : const bool  transparent    = false;
        public : const bool  focusOnVisible = false;
        public : const bool  ignoreCursor   = false;
    };
    
    class Window
    {
        private : str         title;      public : const str&  Title     (); public : void Title     (const str&  _value);
        private : ivec2       position;   public : const ivec2 Position  (); public : void Position  (const ivec2 _value); private : ivec2 prevPosition;
        private : uvec2       size;       public : const uvec2 Size      (); public : void Size      (const uvec2 _value); private : uvec2 prevSize;
        private : bool        minimized;  public :       bool  Minimized (); public : void Minimized (const bool  _value);
        private : bool        maximized;  public :       bool  Maximized (); public : void Maximized (const bool  _value);
        private : bool        fullscreen; public :       bool  Fullscreen(); public : void Fullscreen(const bool  _value);
        private : bool        focused;    public :       bool  Focused   (); public : void Focused   (const bool  _value);
        private : bool        visible;    public :       bool  Visible   (); public : void Visible   (const bool  _value);
        private : u32         vSync;      public :       u32   VSync     (); public : void VSync     (const u32   _value);
        private : bool        closed;     public :       bool  Closed    (); public : void Closed    (const bool  _value);
        
        private : std::set   <int    > pressedKeys     = { }; public :       bool                  KeyPressed    (const int _key   );
        private : std::set   <int    > heldKeys        = { }; public :       bool                  KeyHeld       (const int _key   );
        private : std::set   <int    > releasedkeys    = { }; public :       bool                  KeyReleased   (const int _key   );
        private : std::vector<ichar32> pressedChars    = { }; public : const std::vector<ichar32>& PressedChars  (                 );
        
        private : std::set   <int    > pressedButtons  = { }; public :       bool                  ButtonPressed (const int _button);
        private : std::set   <int    > heldButtons     = { }; public :       bool                  ButtonHeld    (const int _button);
        private : std::set   <int    > releasedButtons = { }; public :       bool                  ButtonReleased(const int _button);
        private : i32                  scrollWheel     = { }; public :       i32                   ScrollWheel   (                 );
        private : ivec2                cursorPosition  = { }; public :       ivec2                 CursorPosition(                 );
        
        private : std::vector<str    > droppedFiles    = { }; public : const std::vector<str    >& DroppedFiles  (                 );
        
        private : GLFWwindow* handle;
        
        public:  Window(const WindowSettings);
        public: ~Window();
        public:  Window(const   Window&) = delete;
        public:  Window(Window&& _other) = delete;
        
        public: bool Update();
        
        
        private: static void PositionCallback         (GLFWwindow* _handle, i32 _x, i32 _y);
        private: static void ResizeCallback           (GLFWwindow* _handle, i32 _x, i32 _y);
        private: static void CloseCallback            (GLFWwindow* _handle                );
        private: static void FocusCallback            (GLFWwindow* _handle, i32 _focused  );
        private: static void MinimizeCallback         (GLFWwindow* _handle, i32 _minimized);
        private: static void MaximizeCallback         (GLFWwindow* _handle, i32 _maximized);
        private: static void KeyCallback              (GLFWwindow* _handle, i32 _key      , i32 _scanCode, i32 _action, i32 _modifiers);
        private: static void CharCallback             (GLFWwindow* _handle, u32 _character                                            );
        private: static void ButtonCallback           (GLFWwindow* _handle, i32 _button   ,                i32 _action, i32 _modifiers);
        private: static void ScrollCallback           (GLFWwindow* _handle, d64  _x, d64 _y);
        private: static void CursorCallback           (GLFWwindow* _handle, d64  _x, d64 _y);
        private: static void DropFileCallback         (GLFWwindow* _handle, i32 _pathCount, const char* _paths[]);
    };
}