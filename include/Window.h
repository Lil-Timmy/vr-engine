#pragma once

#include <GLFW/glfw3.h>
#include <Types.h>





namespace Engine
{
    class Window
    {
        private : str         title;      public : str   Title     (); public : void Title     (const str   _value);
        private : ivec2       position;   public : ivec2 Position  (); public : void Position  (const ivec2 _value); private : ivec2 prevPosition;
        private : uvec2       size;       public : uvec2 Size      (); public : void Size      (const uvec2 _value); private : uvec2 prevSize;
        private : bool        minimized;  public : bool  Minimized (); public : void Minimized (const bool  _value);
        private : bool        maximized;  public : bool  Maximized (); public : void Maximized (const bool  _value);
        private : bool        fullscreen; public : bool  Fullscreen(); public : void Fullscreen(const bool  _value);
        private : bool        focused;    public : bool  Focused   (); public : void Focused   (const bool  _value);
        private : bool        visible;    public : bool  Visible   (); public : void Visible   (const bool  _value);
        private : u32         vSync;      public : u32   VSync     (); public : void VSync     (const u32   _value);
        private : bool        closed;     public : bool  Closed    (); public : void Closed    (const bool  _value);
        private : GLFWwindow* handle;
        
        public: Window
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
        );
        public: ~Window();
        
        Window(const   Window&) = delete;
        Window(Window&& _other) = delete;
        
        public: bool Update();
        
        
        private: static void PositionCallback         (GLFWwindow* _handle, i32 _x, i32 _y);
        private: static void ResizeCallback           (GLFWwindow* _handle, i32 _x, i32 _y);
        private: static void CloseCallback            (GLFWwindow* _handle                );
        private: static void FocusCallback            (GLFWwindow* _handle, i32 _focused  );
        private: static void MinimizeCallback         (GLFWwindow* _handle, i32 _minimized);
        private: static void MaximizeCallback         (GLFWwindow* _handle, i32 _maximized);
        private: static void KeyCallback              (GLFWwindow* _handle, i32 _key      , i32 _scanCode, i32 _action, i32 _modifiers);
        private: static void CharCallback             (GLFWwindow* _handle, u32 _character,                             i32 _modifiers);
        private: static void ButtonCallback           (GLFWwindow* _handle, i32 _button   ,                i32 _action, i32 _modifiers);
        private: static void ScrollCallback           (GLFWwindow* _handle, d64  _x, d64 _y);
        private: static void CursorCallback           (GLFWwindow* _handle, d64  _x, d64 _y);
        private: static void DropFileCallback         (GLFWwindow* _handle, i32 _pathCount, const char* _paths[]);
    };
}