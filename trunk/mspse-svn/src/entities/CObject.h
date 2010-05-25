#ifndef _COBJECT_H_
    #define _COBJECT_H_

#include <SDL.h>


class CObject
{
private:
    /** 当前画面帧序列 */
    int     CurrentFrame;
    /** 画面步进值+1或-1 */
    int     FrameInc;
private:
    /** 画面切换速度，毫秒计 */
    int     FrameRate;

    /** 记录步进前时间 */
    long    OldTime;
public:
    /** 最大渲染序列值，依据贴图而定 */
    int     MaxFrames;

    /** 能否振荡标志 */
    bool    Oscillate;
public:
    CObject();

    /**  */
    void    OnObject();

    /** 设置画面序列切换速度 */
    void    SetFrameRate(int Rate);

    /** 设置当前画面序列值 */
    void    SetCurrentFrame(int Frame);

    /** 获取当前画面序列值 */
    int     GetCurrentFrame();
};

#endif