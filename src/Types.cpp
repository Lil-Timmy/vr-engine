#include <Types.h>








#pragma region fvec2
    fvec2::fvec2(                           ) : x(0  ), y(0  ) { }
    fvec2::fvec2(const f32 _xy              ) : x(_xy), y(_xy) { }
    fvec2::fvec2(const f32 _x , const f32 _y) : x(_x ), y(_y ) { }
    
    fvec2  fvec2::operator+ (const fvec2& _other) const { return fvec2(x +  _other.x, y +  _other.y);              }
    fvec2& fvec2::operator+=(const fvec2& _other)       {              x += _other.x; y += _other.y; return *this; }
    fvec2  fvec2::operator+ (const f32&   _other) const { return fvec2(x +  _other,   y +  _other);                }
    fvec2& fvec2::operator+=(const f32&   _other)       {              x += _other;   y += _other;   return *this; }
    
    fvec2  fvec2::operator- (const fvec2& _other) const { return fvec2(x -  _other.x, y -  _other.y);              }
    fvec2& fvec2::operator-=(const fvec2& _other)       {              x -= _other.x; y -= _other.y; return *this; }
    fvec2  fvec2::operator- (const f32&   _other) const { return fvec2(x -  _other,   y -  _other);                }
    fvec2& fvec2::operator-=(const f32&   _other)       {              x -= _other;   y -= _other;   return *this; }
    
    fvec2  fvec2::operator* (const fvec2& _other) const { return fvec2(x *  _other.x, y *  _other.y);              }
    fvec2& fvec2::operator*=(const fvec2& _other)       {              x *= _other.x; y *= _other.y; return *this; }
    fvec2  fvec2::operator* (const f32&   _other) const { return fvec2(x *  _other,   y *  _other);                }
    fvec2& fvec2::operator*=(const f32&   _other)       {              x *= _other;   y *= _other;   return *this; }
    
    fvec2  fvec2::operator/ (const fvec2& _other) const { return fvec2(x /  _other.x, y /  _other.y);              }
    fvec2& fvec2::operator/=(const fvec2& _other)       {              x /= _other.x; y /= _other.y; return *this; }
    fvec2  fvec2::operator/ (const f32&   _other) const { return fvec2(x /  _other,   y /  _other);                }
    fvec2& fvec2::operator/=(const f32&   _other)       {              x /= _other;   y /= _other;   return *this; }
#pragma endregion fvec2

#pragma region fvec3
    fvec3::fvec3(                                               ) : x(0    ), y(0    ), z(0    ) { }
    fvec3::fvec3(const f32   _xyz                               ) : x(_xyz ), y(_xyz ), z(_xyz ) { }
    fvec3::fvec3(const fvec2 _xy , const f32   _z               ) : x(_xy.x), y(_xy.y), z(_z   ) { }
    fvec3::fvec3(const f32   _x  , const fvec2 _yz              ) : x(_x   ), y(_yz.x), z(_yz.y) { }
    fvec3::fvec3(const f32   _x  , const f32   _y , const f32 _z) : x(_x   ), y(_y   ), z(_z   ) { }
    
    fvec3 fvec3::operator+ (const fvec3& _other) const { return fvec3(x + _other.x, y + _other.y, z + _other.z); }
    fvec3 fvec3::operator+=(const fvec3& _other) const { return fvec3(x + _other.x, y + _other.y, z + _other.z); }
    fvec3 fvec3::operator+ (const f32&   _other) const { return fvec3(x + _other  , y + _other  , z + _other  ); }
    fvec3 fvec3::operator+=(const f32&   _other) const { return fvec3(x + _other  , y + _other  , z + _other  ); }
    
    fvec3 fvec3::operator- (const fvec3& _other) const { return fvec3(x - _other.x, y - _other.y, z - _other.z); }
    fvec3 fvec3::operator-=(const fvec3& _other) const { return fvec3(x - _other.x, y - _other.y, z - _other.z); }
    fvec3 fvec3::operator- (const f32&   _other) const { return fvec3(x - _other  , y - _other  , z - _other  ); }
    fvec3 fvec3::operator-=(const f32&   _other) const { return fvec3(x - _other  , y - _other  , z - _other  ); }
    
    fvec3 fvec3::operator* (const fvec3& _other) const { return fvec3(x * _other.x, y * _other.y, z * _other.z); }
    fvec3 fvec3::operator*=(const fvec3& _other) const { return fvec3(x * _other.x, y * _other.y, z * _other.z); }
    fvec3 fvec3::operator* (const f32&   _other) const { return fvec3(x * _other  , y * _other  , z * _other  ); }
    fvec3 fvec3::operator*=(const f32&   _other) const { return fvec3(x * _other  , y * _other  , z * _other  ); }
    
    fvec3 fvec3::operator/ (const fvec3& _other) const { return fvec3(x / _other.x, y / _other.y, z / _other.z); }
    fvec3 fvec3::operator/=(const fvec3& _other) const { return fvec3(x / _other.x, y / _other.y, z / _other.z); }
    fvec3 fvec3::operator/ (const f32&   _other) const { return fvec3(x / _other  , y / _other  , z / _other  ); }
    fvec3 fvec3::operator/=(const f32&   _other) const { return fvec3(x / _other  , y / _other  , z / _other  ); }
#pragma endregion fvec3
    
#pragma region fvec4
    fvec4::fvec4(                                                                  ) : x(0     ), y(0     ), z(0     ), w(0     ) { }
    fvec4::fvec4(const f32   _xyzw                                                 ) : x(_xyzw ), y(_xyzw ), z(_xyzw ), w(_xyzw ) { }
    fvec4::fvec4(const fvec3 _xyz , const f32   _w                                 ) : x(_xyz.x), y(_xyz.y), z(_xyz.z), w(_w    ) { }
    fvec4::fvec4(const f32   _x   , const fvec3 _yzw                               ) : x(_x    ), y(_yzw.x), z(_yzw.y), w(_yzw.z) { }
    fvec4::fvec4(const fvec2 _xy  , const fvec2 _zw                                ) : x(_xy.x ), y(_xy.y ), z(_zw.x ), w(_zw.y ) { }
    fvec4::fvec4(const fvec2 _xy  , const f32   _z  , const f32   _w               ) : x(_xy.x ), y(_xy.y ), z(_z    ), w(_w    ) { }
    fvec4::fvec4(const f32   _x   , const fvec2 _yz , const f32   _w               ) : x(_x    ), y(_yz.x ), z(_yz.y ), w(_w    ) { }
    fvec4::fvec4(const f32   _x   , const f32   _y  , const fvec2 _zw              ) : x(_x    ), y(_y    ), z(_zw.x ), w(_zw.y ) { }
    fvec4::fvec4(const f32   _x   , const f32   _y  , const f32   _z , const f32 _w) : x(_x    ), y(_y    ), z(_z    ), w(_w    ) { }
    
    fvec4 fvec4::operator+ (const fvec4& _other) const { return fvec4(x + _other.x, y + _other.y, z + _other.z, w + _other.w); }
    fvec4 fvec4::operator+=(const fvec4& _other) const { return fvec4(x + _other.x, y + _other.y, z + _other.z, w + _other.w); }
    fvec4 fvec4::operator+ (const f32&   _other) const { return fvec4(x + _other  , y + _other  , z + _other  , w + _other  ); }
    fvec4 fvec4::operator+=(const f32&   _other) const { return fvec4(x + _other  , y + _other  , z + _other  , w + _other  ); }
    
    fvec4 fvec4::operator- (const fvec4& _other) const { return fvec4(x - _other.x, y - _other.y, z - _other.z, w - _other.w); }
    fvec4 fvec4::operator-=(const fvec4& _other) const { return fvec4(x - _other.x, y - _other.y, z - _other.z, w - _other.w); }
    fvec4 fvec4::operator- (const f32&   _other) const { return fvec4(x - _other  , y - _other  , z - _other  , w - _other  ); }
    fvec4 fvec4::operator-=(const f32&   _other) const { return fvec4(x - _other  , y - _other  , z - _other  , w - _other  ); }
    
    fvec4 fvec4::operator* (const fvec4& _other) const { return fvec4(x * _other.x, y * _other.y, z * _other.z, w * _other.w); }
    fvec4 fvec4::operator*=(const fvec4& _other) const { return fvec4(x * _other.x, y * _other.y, z * _other.z, w * _other.w); }
    fvec4 fvec4::operator* (const f32&   _other) const { return fvec4(x * _other  , y * _other  , z * _other  , w * _other  ); }
    fvec4 fvec4::operator*=(const f32&   _other) const { return fvec4(x * _other  , y * _other  , z * _other  , w * _other  ); }
    
    fvec4 fvec4::operator/ (const fvec4& _other) const { return fvec4(x / _other.x, y / _other.y, z / _other.z, w / _other.w); }
    fvec4 fvec4::operator/=(const fvec4& _other) const { return fvec4(x / _other.x, y / _other.y, z / _other.z, w / _other.w); }
    fvec4 fvec4::operator/ (const f32&   _other) const { return fvec4(x / _other  , y / _other  , z / _other  , w / _other  ); }
    fvec4 fvec4::operator/=(const f32&   _other) const { return fvec4(x / _other  , y / _other  , z / _other  , w / _other  ); }
#pragma endregion fvec4
    
#pragma region ivec2
    ivec2::ivec2(                           ) : x(0  ), y(0  ) { }
    ivec2::ivec2(const i32 _xy              ) : x(_xy), y(_xy) { }
    ivec2::ivec2(const i32 _x , const i32 _y) : x(_x ), y(_y ) { }
    
    ivec2 ivec2::operator+ (const ivec2& _other) const { return ivec2(x + _other.x, y + _other.y); }
    ivec2 ivec2::operator+=(const ivec2& _other) const { return ivec2(x + _other.x, y + _other.y); }
    ivec2 ivec2::operator+ (const i32&   _other) const { return ivec2(x + _other  , y + _other  ); }
    ivec2 ivec2::operator+=(const i32&   _other) const { return ivec2(x + _other  , y + _other  ); }
    
    ivec2 ivec2::operator- (const ivec2& _other) const { return ivec2(x - _other.x, y - _other.y); }
    ivec2 ivec2::operator-=(const ivec2& _other) const { return ivec2(x - _other.x, y - _other.y); }
    ivec2 ivec2::operator- (const i32&   _other) const { return ivec2(x - _other  , y - _other  ); }
    ivec2 ivec2::operator-=(const i32&   _other) const { return ivec2(x - _other  , y - _other  ); }
    
    ivec2 ivec2::operator* (const ivec2& _other) const { return ivec2(x * _other.x, y * _other.y); }
    ivec2 ivec2::operator*=(const ivec2& _other) const { return ivec2(x * _other.x, y * _other.y); }
    ivec2 ivec2::operator* (const i32&   _other) const { return ivec2(x * _other  , y * _other  ); }
    ivec2 ivec2::operator*=(const i32&   _other) const { return ivec2(x * _other  , y * _other  ); }
    
    ivec2 ivec2::operator/ (const ivec2& _other) const { return ivec2(x / _other.x, y / _other.y); }
    ivec2 ivec2::operator/=(const ivec2& _other) const { return ivec2(x / _other.x, y / _other.y); }
    ivec2 ivec2::operator/ (const i32&   _other) const { return ivec2(x / _other  , y / _other  ); }
    ivec2 ivec2::operator/=(const i32&   _other) const { return ivec2(x / _other  , y / _other  ); }
#pragma endregion ivec2
    
#pragma region ivec3
    ivec3::ivec3(                                               ) : x(0    ), y(0    ), z(0    ) { }
    ivec3::ivec3(const i32   _xyz                               ) : x(_xyz ), y(_xyz ), z(_xyz ) { }
    ivec3::ivec3(const ivec2 _xy , const i32   _z               ) : x(_xy.x), y(_xy.y), z(_z   ) { }
    ivec3::ivec3(const i32   _x  , const ivec2 _yz              ) : x(_x   ), y(_yz.x), z(_yz.y) { }
    ivec3::ivec3(const i32   _x  , const i32   _y , const i32 _z) : x(_x   ), y(_y   ), z(_z   ) { }
    
    ivec3 ivec3::operator+ (const ivec3& _other) const { return ivec3(x + _other.x, y + _other.y, z + _other.z); }
    ivec3 ivec3::operator+=(const ivec3& _other) const { return ivec3(x + _other.x, y + _other.y, z + _other.z); }
    ivec3 ivec3::operator+ (const i32&   _other) const { return ivec3(x + _other  , y + _other  , z + _other  ); }
    ivec3 ivec3::operator+=(const i32&   _other) const { return ivec3(x + _other  , y + _other  , z + _other  ); }
    
    ivec3 ivec3::operator- (const ivec3& _other) const { return ivec3(x - _other.x, y - _other.y, z - _other.z); }
    ivec3 ivec3::operator-=(const ivec3& _other) const { return ivec3(x - _other.x, y - _other.y, z - _other.z); }
    ivec3 ivec3::operator- (const i32&   _other) const { return ivec3(x - _other  , y - _other  , z - _other  ); }
    ivec3 ivec3::operator-=(const i32&   _other) const { return ivec3(x - _other  , y - _other  , z - _other  ); }
    
    ivec3 ivec3::operator* (const ivec3& _other) const { return ivec3(x * _other.x, y * _other.y, z * _other.z); }
    ivec3 ivec3::operator*=(const ivec3& _other) const { return ivec3(x * _other.x, y * _other.y, z * _other.z); }
    ivec3 ivec3::operator* (const i32&   _other) const { return ivec3(x * _other  , y * _other  , z * _other  ); }
    ivec3 ivec3::operator*=(const i32&   _other) const { return ivec3(x * _other  , y * _other  , z * _other  ); }
    
    ivec3 ivec3::operator/ (const ivec3& _other) const { return ivec3(x / _other.x, y / _other.y, z / _other.z); }
    ivec3 ivec3::operator/=(const ivec3& _other) const { return ivec3(x / _other.x, y / _other.y, z / _other.z); }
    ivec3 ivec3::operator/ (const i32&   _other) const { return ivec3(x / _other  , y / _other  , z / _other  ); }
    ivec3 ivec3::operator/=(const i32&   _other) const { return ivec3(x / _other  , y / _other  , z / _other  ); }
#pragma endregion ivec3
    
#pragma region ivec4
    ivec4::ivec4(                                                                  ) : x(0     ), y(0     ), z(0     ), w(0     ) { }
    ivec4::ivec4(const i32   _xyzw                                                 ) : x(_xyzw ), y(_xyzw ), z(_xyzw ), w(_xyzw ) { }
    ivec4::ivec4(const ivec3 _xyz , const i32   _w                                 ) : x(_xyz.x), y(_xyz.y), z(_xyz.z), w(_w    ) { }
    ivec4::ivec4(const i32   _x   , const ivec3 _yzw                               ) : x(_x    ), y(_yzw.x), z(_yzw.y), w(_yzw.z) { }
    ivec4::ivec4(const ivec2 _xy  , const ivec2 _zw                                ) : x(_xy.x ), y(_xy.y ), z(_zw.x ), w(_zw.y ) { }
    ivec4::ivec4(const ivec2 _xy  , const i32   _z  , const i32   _w               ) : x(_xy.x ), y(_xy.y ), z(_z    ), w(_w    ) { }
    ivec4::ivec4(const i32   _x   , const ivec2 _yz , const i32   _w               ) : x(_x    ), y(_yz.x ), z(_yz.y ), w(_w    ) { }
    ivec4::ivec4(const i32   _x   , const i32   _y  , const ivec2 _zw              ) : x(_x    ), y(_y    ), z(_zw.x ), w(_zw.y ) { }
    ivec4::ivec4(const i32   _x   , const i32   _y  , const i32   _z , const i32 _w) : x(_x    ), y(_y    ), z(_z    ), w(_w    ) { }
    
    ivec4 ivec4::operator+ (const ivec4& _other) const { return ivec4(x + _other.x, y + _other.y, z + _other.z, w + _other.w); }
    ivec4 ivec4::operator+=(const ivec4& _other) const { return ivec4(x + _other.x, y + _other.y, z + _other.z, w + _other.w); }
    ivec4 ivec4::operator+ (const i32&   _other) const { return ivec4(x + _other  , y + _other  , z + _other  , w + _other  ); }
    ivec4 ivec4::operator+=(const i32&   _other) const { return ivec4(x + _other  , y + _other  , z + _other  , w + _other  ); }
    
    ivec4 ivec4::operator- (const ivec4& _other) const { return ivec4(x - _other.x, y - _other.y, z - _other.z, w - _other.w); }
    ivec4 ivec4::operator-=(const ivec4& _other) const { return ivec4(x - _other.x, y - _other.y, z - _other.z, w - _other.w); }
    ivec4 ivec4::operator- (const i32&   _other) const { return ivec4(x - _other  , y - _other  , z - _other  , w - _other  ); }
    ivec4 ivec4::operator-=(const i32&   _other) const { return ivec4(x - _other  , y - _other  , z - _other  , w - _other  ); }
    
    ivec4 ivec4::operator* (const ivec4& _other) const { return ivec4(x * _other.x, y * _other.y, z * _other.z, w * _other.w); }
    ivec4 ivec4::operator*=(const ivec4& _other) const { return ivec4(x * _other.x, y * _other.y, z * _other.z, w * _other.w); }
    ivec4 ivec4::operator* (const i32&   _other) const { return ivec4(x * _other  , y * _other  , z * _other  , w * _other  ); }
    ivec4 ivec4::operator*=(const i32&   _other) const { return ivec4(x * _other  , y * _other  , z * _other  , w * _other  ); }
    
    ivec4 ivec4::operator/ (const ivec4& _other) const { return ivec4(x / _other.x, y / _other.y, z / _other.z, w / _other.w); }
    ivec4 ivec4::operator/=(const ivec4& _other) const { return ivec4(x / _other.x, y / _other.y, z / _other.z, w / _other.w); }
    ivec4 ivec4::operator/ (const i32&   _other) const { return ivec4(x / _other  , y / _other  , z / _other  , w / _other  ); }
    ivec4 ivec4::operator/=(const i32&   _other) const { return ivec4(x / _other  , y / _other  , z / _other  , w / _other  ); }
#pragma endregion ivec4
    
#pragma region uvec2
    uvec2::uvec2(                           ) : x(0  ), y(0  ) { }
    uvec2::uvec2(const u32 _xy              ) : x(_xy), y(_xy) { }
    uvec2::uvec2(const u32 _x , const u32 _y) : x(_x ), y(_y ) { }
    
    uvec2 uvec2::operator+ (const uvec2& _other) const { return uvec2(x + _other.x, y + _other.y); }
    uvec2 uvec2::operator+=(const uvec2& _other) const { return uvec2(x + _other.x, y + _other.y); }
    uvec2 uvec2::operator+ (const u32&   _other) const { return uvec2(x + _other  , y + _other  ); }
    uvec2 uvec2::operator+=(const u32&   _other) const { return uvec2(x + _other  , y + _other  ); }
    
    uvec2 uvec2::operator- (const uvec2& _other) const { return uvec2(x - _other.x, y - _other.y); }
    uvec2 uvec2::operator-=(const uvec2& _other) const { return uvec2(x - _other.x, y - _other.y); }
    uvec2 uvec2::operator- (const u32&   _other) const { return uvec2(x - _other  , y - _other  ); }
    uvec2 uvec2::operator-=(const u32&   _other) const { return uvec2(x - _other  , y - _other  ); }
    
    uvec2 uvec2::operator* (const uvec2& _other) const { return uvec2(x * _other.x, y * _other.y); }
    uvec2 uvec2::operator*=(const uvec2& _other) const { return uvec2(x * _other.x, y * _other.y); }
    uvec2 uvec2::operator* (const u32&   _other) const { return uvec2(x * _other  , y * _other  ); }
    uvec2 uvec2::operator*=(const u32&   _other) const { return uvec2(x * _other  , y * _other  ); }
    
    uvec2 uvec2::operator/ (const uvec2& _other) const { return uvec2(x / _other.x, y / _other.y); }
    uvec2 uvec2::operator/=(const uvec2& _other) const { return uvec2(x / _other.x, y / _other.y); }
    uvec2 uvec2::operator/ (const u32&   _other) const { return uvec2(x / _other  , y / _other  ); }
    uvec2 uvec2::operator/=(const u32&   _other) const { return uvec2(x / _other  , y / _other  ); }
#pragma endregion uvec2
    
#pragma region uvec3
    uvec3::uvec3(                                               ) : x(0    ), y(0    ), z(0    ) { }
    uvec3::uvec3(const u32   _xyz                               ) : x(_xyz ), y(_xyz ), z(_xyz ) { }
    uvec3::uvec3(const uvec2 _xy , const u32   _z               ) : x(_xy.x), y(_xy.y), z(_z   ) { }
    uvec3::uvec3(const u32   _x  , const uvec2 _yz              ) : x(_x   ), y(_yz.x), z(_yz.y) { }
    uvec3::uvec3(const u32   _x  , const u32   _y , const u32 _z) : x(_x   ), y(_y   ), z(_z   ) { }
    
    uvec3 uvec3::operator+ (const uvec3& _other) const { return uvec3(x + _other.x, y + _other.y, z + _other.z); }
    uvec3 uvec3::operator+=(const uvec3& _other) const { return uvec3(x + _other.x, y + _other.y, z + _other.z); }
    uvec3 uvec3::operator+ (const u32&   _other) const { return uvec3(x + _other  , y + _other  , z + _other  ); }
    uvec3 uvec3::operator+=(const u32&   _other) const { return uvec3(x + _other  , y + _other  , z + _other  ); }
    
    uvec3 uvec3::operator- (const uvec3& _other) const { return uvec3(x - _other.x, y - _other.y, z - _other.z); }
    uvec3 uvec3::operator-=(const uvec3& _other) const { return uvec3(x - _other.x, y - _other.y, z - _other.z); }
    uvec3 uvec3::operator- (const u32&   _other) const { return uvec3(x - _other  , y - _other  , z - _other  ); }
    uvec3 uvec3::operator-=(const u32&   _other) const { return uvec3(x - _other  , y - _other  , z - _other  ); }
    
    uvec3 uvec3::operator* (const uvec3& _other) const { return uvec3(x * _other.x, y * _other.y, z * _other.z); }
    uvec3 uvec3::operator*=(const uvec3& _other) const { return uvec3(x * _other.x, y * _other.y, z * _other.z); }
    uvec3 uvec3::operator* (const u32&   _other) const { return uvec3(x * _other  , y * _other  , z * _other  ); }
    uvec3 uvec3::operator*=(const u32&   _other) const { return uvec3(x * _other  , y * _other  , z * _other  ); }
    
    uvec3 uvec3::operator/ (const uvec3& _other) const { return uvec3(x / _other.x, y / _other.y, z / _other.z); }
    uvec3 uvec3::operator/=(const uvec3& _other) const { return uvec3(x / _other.x, y / _other.y, z / _other.z); }
    uvec3 uvec3::operator/ (const u32&   _other) const { return uvec3(x / _other  , y / _other  , z / _other  ); }
    uvec3 uvec3::operator/=(const u32&   _other) const { return uvec3(x / _other  , y / _other  , z / _other  ); }
#pragma endregion uvec3
    
#pragma region uvec4
    uvec4::uvec4(                                                                  ) : x(0     ), y(0     ), z(0     ), w(0     ) { }
    uvec4::uvec4(const u32   _xyzw                                                 ) : x(_xyzw ), y(_xyzw ), z(_xyzw ), w(_xyzw ) { }
    uvec4::uvec4(const uvec3 _xyz , const u32   _w                                 ) : x(_xyz.x), y(_xyz.y), z(_xyz.z), w(_w    ) { }
    uvec4::uvec4(const u32   _x   , const uvec3 _yzw                               ) : x(_x    ), y(_yzw.x), z(_yzw.y), w(_yzw.z) { }
    uvec4::uvec4(const uvec2 _xy  , const uvec2 _zw                                ) : x(_xy.x ), y(_xy.y ), z(_zw.x ), w(_zw.y ) { }
    uvec4::uvec4(const uvec2 _xy  , const u32   _z  , const u32   _w               ) : x(_xy.x ), y(_xy.y ), z(_z    ), w(_w    ) { }
    uvec4::uvec4(const u32   _x   , const uvec2 _yz , const u32   _w               ) : x(_x    ), y(_yz.x ), z(_yz.y ), w(_w    ) { }
    uvec4::uvec4(const u32   _x   , const u32   _y  , const uvec2 _zw              ) : x(_x    ), y(_y    ), z(_zw.x ), w(_zw.y ) { }
    uvec4::uvec4(const u32   _x   , const u32   _y  , const u32   _z , const u32 _w) : x(_x    ), y(_y    ), z(_z    ), w(_w    ) { }
    
    uvec4 uvec4::operator+ (const uvec4& _other) const { return uvec4(x + _other.x, y + _other.y, z + _other.z, w + _other.w); }
    uvec4 uvec4::operator+=(const uvec4& _other) const { return uvec4(x + _other.x, y + _other.y, z + _other.z, w + _other.w); }
    uvec4 uvec4::operator+ (const u32&   _other) const { return uvec4(x + _other  , y + _other  , z + _other  , w + _other  ); }
    uvec4 uvec4::operator+=(const u32&   _other) const { return uvec4(x + _other  , y + _other  , z + _other  , w + _other  ); }
    
    uvec4 uvec4::operator- (const uvec4& _other) const { return uvec4(x - _other.x, y - _other.y, z - _other.z, w - _other.w); }
    uvec4 uvec4::operator-=(const uvec4& _other) const { return uvec4(x - _other.x, y - _other.y, z - _other.z, w - _other.w); }
    uvec4 uvec4::operator- (const u32&   _other) const { return uvec4(x - _other  , y - _other  , z - _other  , w - _other  ); }
    uvec4 uvec4::operator-=(const u32&   _other) const { return uvec4(x - _other  , y - _other  , z - _other  , w - _other  ); }
    
    uvec4 uvec4::operator* (const uvec4& _other) const { return uvec4(x * _other.x, y * _other.y, z * _other.z, w * _other.w); }
    uvec4 uvec4::operator*=(const uvec4& _other) const { return uvec4(x * _other.x, y * _other.y, z * _other.z, w * _other.w); }
    uvec4 uvec4::operator* (const u32&   _other) const { return uvec4(x * _other  , y * _other  , z * _other  , w * _other  ); }
    uvec4 uvec4::operator*=(const u32&   _other) const { return uvec4(x * _other  , y * _other  , z * _other  , w * _other  ); }
    
    uvec4 uvec4::operator/ (const uvec4& _other) const { return uvec4(x / _other.x, y / _other.y, z / _other.z, w / _other.w); }
    uvec4 uvec4::operator/=(const uvec4& _other) const { return uvec4(x / _other.x, y / _other.y, z / _other.z, w / _other.w); }
    uvec4 uvec4::operator/ (const u32&   _other) const { return uvec4(x / _other  , y / _other  , z / _other  , w / _other  ); }
    uvec4 uvec4::operator/=(const u32&   _other) const { return uvec4(x / _other  , y / _other  , z / _other  , w / _other  ); }
#pragma endregion uvec4