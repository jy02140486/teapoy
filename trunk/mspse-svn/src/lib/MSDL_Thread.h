#ifndef _MSDL_THREAD_H_
    #define _MSDL_THREAD_H_
/** 为了修正新建线程是函数指针的传递错误而存在。
    使用了代理的方式来避免指针转换的冲突问题。
    详见：http://goo.gl/kM1n
 */

//========================================================================
template <typename T>
struct SDL_ThreadProxy
{
    typedef int (T::*TFunction)();
    SDL_ThreadProxy(T * instance, TFunction function)
        : _instance(instance)
        , _function(function)
    {}
    static int run(SDL_ThreadProxy<T> * _this)
    {
        return ((_this->_instance)->*(_this->_function))();
    }

private:
    T * _instance;
    TFunction _function;
};

template <typename T>
SDL_Thread * SDL_CreateMemberThread(T * instance, int (T::*function)())
{
    SDL_ThreadProxy<T> proxy(instance, function);
    typedef int (*SDL_ThreadFunction)(void *);
    return SDL_CreateThread(reinterpret_cast<SDL_ThreadFunction>(SDL_ThreadProxy<T>::run), &proxy); 
}

#endif