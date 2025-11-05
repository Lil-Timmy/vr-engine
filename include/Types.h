#pragma once

#include <cstdint>
#include <string>




using i08 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u08 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using f32 = float;
using d64 = double;

using ichar08 = char;
using ichar16 = char16_t;
using ichar32 = char32_t;

using uchar08 = unsigned char;

#pragma clang diagnostic ignored "-Wunused-macros"
#define i08MIN INT8_MIN;
#define i16MIN INT16_MIN;
#define i32MIN INT32_MIN;
#define i64MIN INT64_MIN;

#define i08MAX INT8_MAX;
#define i16MAX INT16_MAX;
#define i32MAX INT32_MAX;
#define i64MAX INT64_MAX;

#define u08MAX UINT8_MAX;
#define u16MAX UINT16_MAX;
#define u32MAX UINT32_MAX;
#define u64MAX UINT64_MAX;
#pragma clang diagnostic push

using str = std::string;



struct fvec2
{
    public: f32 x;
    public: f32 y;
    
    fvec2(                           );
    fvec2(const f32 _xy              );
    fvec2(const f32 _x , const f32 _y);
    
    fvec2  operator+ (const fvec2& _other) const;
    fvec2& operator+=(const fvec2& _other);
    fvec2  operator+ (const f32&   _other) const;
    fvec2& operator+=(const f32&   _other);
    
    fvec2  operator- (const fvec2& _other) const;
    fvec2& operator-=(const fvec2& _other);
    fvec2  operator- (const f32&   _other) const;
    fvec2& operator-=(const f32&   _other);
    
    fvec2  operator* (const fvec2& _other) const;
    fvec2& operator*=(const fvec2& _other);
    fvec2  operator* (const f32&   _other) const;
    fvec2& operator*=(const f32&   _other);
    
    fvec2  operator/ (const fvec2& _other) const;
    fvec2& operator/=(const fvec2& _other);
    fvec2  operator/ (const f32&   _other) const;
    fvec2& operator/=(const f32&   _other);
};
struct fvec3
{
    public: f32 x;
    public: f32 y;
    public: f32 z;
    
    fvec3(                                               );
    fvec3(const f32   _xyz                               );
    fvec3(const fvec2 _xy , const f32   _z               );
    fvec3(const f32   _x  , const fvec2 _yz              );
    fvec3(const f32   _x  , const f32   _y , const f32 _z);
    
    fvec3 operator+ (const fvec3& _other) const;
    fvec3 operator+=(const fvec3& _other) const;
    fvec3 operator+ (const f32&   _other) const;
    fvec3 operator+=(const f32&   _other) const;
    
    fvec3 operator- (const fvec3& _other) const;
    fvec3 operator-=(const fvec3& _other) const;
    fvec3 operator- (const f32&   _other) const;
    fvec3 operator-=(const f32&   _other) const;
    
    fvec3 operator* (const fvec3& _other) const;
    fvec3 operator*=(const fvec3& _other) const;
    fvec3 operator* (const f32&   _other) const;
    fvec3 operator*=(const f32&   _other) const;
    
    fvec3 operator/ (const fvec3& _other) const;
    fvec3 operator/=(const fvec3& _other) const;
    fvec3 operator/ (const f32&   _other) const;
    fvec3 operator/=(const f32&   _other) const;
};
struct fvec4
{
    public: f32 x;
    public: f32 y;
    public: f32 z;
    public: f32 w;
    
    fvec4(                                                                  );
    fvec4(const f32   _xyzw                                                 );
    fvec4(const fvec3 _xyz , const f32   _w                                 );
    fvec4(const f32   _x   , const fvec3 _yzw                               );
    fvec4(const fvec2 _xy  , const fvec2 _zw                                );
    fvec4(const fvec2 _xy  , const f32   _z  , const f32   _w               );
    fvec4(const f32   _x   , const fvec2 _yz , const f32   _w               );
    fvec4(const f32   _x   , const f32   _y  , const fvec2 _zw              );
    fvec4(const f32   _x   , const f32   _y  , const f32   _z , const f32 _w);
    
    fvec4 operator+ (const fvec4& _other) const;
    fvec4 operator+=(const fvec4& _other) const;
    fvec4 operator+ (const f32&   _other) const;
    fvec4 operator+=(const f32&   _other) const;
    
    fvec4 operator- (const fvec4& _other) const;
    fvec4 operator-=(const fvec4& _other) const;
    fvec4 operator- (const f32&   _other) const;
    fvec4 operator-=(const f32&   _other) const;
    
    fvec4 operator* (const fvec4& _other) const;
    fvec4 operator*=(const fvec4& _other) const;
    fvec4 operator* (const f32&   _other) const;
    fvec4 operator*=(const f32&   _other) const;
    
    fvec4 operator/ (const fvec4& _other) const;
    fvec4 operator/=(const fvec4& _other) const;
    fvec4 operator/ (const f32&   _other) const;
    fvec4 operator/=(const f32&   _other) const;
};

struct ivec2
{
    public: i32 x;
    public: i32 y;
    
    ivec2(                           );
    ivec2(const i32 _xy              );
    ivec2(const i32 _x , const i32 _y);
    
    ivec2 operator+ (const ivec2& _other) const;
    ivec2 operator+=(const ivec2& _other) const;
    ivec2 operator+ (const i32&   _other) const;
    ivec2 operator+=(const i32&   _other) const;
    
    ivec2 operator- (const ivec2& _other) const;
    ivec2 operator-=(const ivec2& _other) const;
    ivec2 operator- (const i32&   _other) const;
    ivec2 operator-=(const i32&   _other) const;
    
    ivec2 operator* (const ivec2& _other) const;
    ivec2 operator*=(const ivec2& _other) const;
    ivec2 operator* (const i32&   _other) const;
    ivec2 operator*=(const i32&   _other) const;
    
    ivec2 operator/ (const ivec2& _other) const;
    ivec2 operator/=(const ivec2& _other) const;
    ivec2 operator/ (const i32&   _other) const;
    ivec2 operator/=(const i32&   _other) const;
};
struct ivec3
{
    public: i32 x;
    public: i32 y;
    public: i32 z;
    
    ivec3(                                               );
    ivec3(const i32   _xyz                               );
    ivec3(const ivec2 _xy , const i32   _z               );
    ivec3(const i32   _x  , const ivec2 _yz              );
    ivec3(const i32   _x  , const i32   _y , const i32 _z);
    
    ivec3 operator+ (const ivec3& _other) const;
    ivec3 operator+=(const ivec3& _other) const;
    ivec3 operator+ (const i32&   _other) const;
    ivec3 operator+=(const i32&   _other) const;
    
    ivec3 operator- (const ivec3& _other) const;
    ivec3 operator-=(const ivec3& _other) const;
    ivec3 operator- (const i32&   _other) const;
    ivec3 operator-=(const i32&   _other) const;
    
    ivec3 operator* (const ivec3& _other) const;
    ivec3 operator*=(const ivec3& _other) const;
    ivec3 operator* (const i32&   _other) const;
    ivec3 operator*=(const i32&   _other) const;
    
    ivec3 operator/ (const ivec3& _other) const;
    ivec3 operator/=(const ivec3& _other) const;
    ivec3 operator/ (const i32&   _other) const;
    ivec3 operator/=(const i32&   _other) const;
};
struct ivec4
{
    public: i32 x;
    public: i32 y;
    public: i32 z;
    public: i32 w;
    
    ivec4(                                                                  );
    ivec4(const i32   _xyzw                                                 );
    ivec4(const ivec3 _xyz , const i32   _w                                 );
    ivec4(const i32   _x   , const ivec3 _yzw                               );
    ivec4(const ivec2 _xy  , const ivec2 _zw                                );
    ivec4(const ivec2 _xy  , const i32   _z  , const i32   _w               );
    ivec4(const i32   _x   , const ivec2 _yz , const i32   _w               );
    ivec4(const i32   _x   , const i32   _y  , const ivec2 _zw              );
    ivec4(const i32   _x   , const i32   _y  , const i32   _z , const i32 _w);
    
    ivec4 operator+ (const ivec4& _other) const;
    ivec4 operator+=(const ivec4& _other) const;
    ivec4 operator+ (const i32&   _other) const;
    ivec4 operator+=(const i32&   _other) const;
    
    ivec4 operator- (const ivec4& _other) const;
    ivec4 operator-=(const ivec4& _other) const;
    ivec4 operator- (const i32&   _other) const;
    ivec4 operator-=(const i32&   _other) const;
    
    ivec4 operator* (const ivec4& _other) const;
    ivec4 operator*=(const ivec4& _other) const;
    ivec4 operator* (const i32&   _other) const;
    ivec4 operator*=(const i32&   _other) const;
    
    ivec4 operator/ (const ivec4& _other) const;
    ivec4 operator/=(const ivec4& _other) const;
    ivec4 operator/ (const i32&   _other) const;
    ivec4 operator/=(const i32&   _other) const;
};

struct uvec2
{
    public: u32 x;
    public: u32 y;
    
    uvec2(                           );
    uvec2(const u32 _xy              );
    uvec2(const u32 _x , const u32 _y);
    
    uvec2 operator+ (const uvec2& _other) const;
    uvec2 operator+=(const uvec2& _other) const;
    uvec2 operator+ (const u32&   _other) const;
    uvec2 operator+=(const u32&   _other) const;
    
    uvec2 operator- (const uvec2& _other) const;
    uvec2 operator-=(const uvec2& _other) const;
    uvec2 operator- (const u32&   _other) const;
    uvec2 operator-=(const u32&   _other) const;
    
    uvec2 operator* (const uvec2& _other) const;
    uvec2 operator*=(const uvec2& _other) const;
    uvec2 operator* (const u32&   _other) const;
    uvec2 operator*=(const u32&   _other) const;
    
    uvec2 operator/ (const uvec2& _other) const;
    uvec2 operator/=(const uvec2& _other) const;
    uvec2 operator/ (const u32&   _other) const;
    uvec2 operator/=(const u32&   _other) const;
};
struct uvec3
{
    public: u32 x;
    public: u32 y;
    public: u32 z;
    
    uvec3(                                               );
    uvec3(const u32   _xyz                               );
    uvec3(const uvec2 _xy , const u32   _z               );
    uvec3(const u32   _x  , const uvec2 _yz              );
    uvec3(const u32   _x  , const u32   _y , const u32 _z);
    
    uvec3 operator+ (const uvec3& _other) const;
    uvec3 operator+=(const uvec3& _other) const;
    uvec3 operator+ (const u32&   _other) const;
    uvec3 operator+=(const u32&   _other) const;
    
    uvec3 operator- (const uvec3& _other) const;
    uvec3 operator-=(const uvec3& _other) const;
    uvec3 operator- (const u32&   _other) const;
    uvec3 operator-=(const u32&   _other) const;
    
    uvec3 operator* (const uvec3& _other) const;
    uvec3 operator*=(const uvec3& _other) const;
    uvec3 operator* (const u32&   _other) const;
    uvec3 operator*=(const u32&   _other) const;
    
    uvec3 operator/ (const uvec3& _other) const;
    uvec3 operator/=(const uvec3& _other) const;
    uvec3 operator/ (const u32&   _other) const;
    uvec3 operator/=(const u32&   _other) const;
};
struct uvec4
{
    public: u32 x;
    public: u32 y;
    public: u32 z;
    public: u32 w;
    
    uvec4(                                                                  );
    uvec4(const u32   _xyzw                                                 );
    uvec4(const uvec3 _xyz , const u32   _w                                 );
    uvec4(const u32   _x   , const uvec3 _yzw                               );
    uvec4(const uvec2 _xy  , const uvec2 _zw                                );
    uvec4(const uvec2 _xy  , const u32   _z  , const u32   _w               );
    uvec4(const u32   _x   , const uvec2 _yz , const u32   _w               );
    uvec4(const u32   _x   , const u32   _y  , const uvec2 _zw              );
    uvec4(const u32   _x   , const u32   _y  , const u32   _z , const u32 _w);
    
    uvec4 operator+ (const uvec4& _other) const;
    uvec4 operator+=(const uvec4& _other) const;
    uvec4 operator+ (const u32&   _other) const;
    uvec4 operator+=(const u32&   _other) const;
    
    uvec4 operator- (const uvec4& _other) const;
    uvec4 operator-=(const uvec4& _other) const;
    uvec4 operator- (const u32&   _other) const;
    uvec4 operator-=(const u32&   _other) const;
    
    uvec4 operator* (const uvec4& _other) const;
    uvec4 operator*=(const uvec4& _other) const;
    uvec4 operator* (const u32&   _other) const;
    uvec4 operator*=(const u32&   _other) const;
    
    uvec4 operator/ (const uvec4& _other) const;
    uvec4 operator/=(const uvec4& _other) const;
    uvec4 operator/ (const u32&   _other) const;
    uvec4 operator/=(const u32&   _other) const;
};