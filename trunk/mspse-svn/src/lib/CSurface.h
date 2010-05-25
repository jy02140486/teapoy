#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL.h>

/** 进一步封装好的图片加载类 */
class CSurface
{
public:
    CSurface();

public:
    /** 根据图片路径 fileURI 加载图片到指针 */
    static SDL_Surface* OnLoad(char* fileURI);

    /** 将源表面绘制到目标表面的x，y处 */
    static bool OnDraw(SDL_Surface* surDest, SDL_Surface* surSrc,
        int dest_x, int dest_y);

    /** 将源表面的x，y，w，h区域，绘制到目标表面的x，y处 */
    static bool OnDraw(SDL_Surface* surDest, SDL_Surface* surSrc,
        int dest_x, int dest_y,
        int src_x, int src_y, int src_w, int src_h);

    /** 设置目标表面透明颜色 */
    static bool Transparent(SDL_Surface* surDest, int R, int G, int B);
};

#endif