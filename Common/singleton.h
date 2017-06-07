#ifndef SINGLETON_H
#define SINGLETON_H
#include "Common/SocketManager.h"
template <class T>
class Singleton
{
public:
    static T* Instance()
    {
        static QMutex mutex;
        static QScopedPointer<T> inst;
        if (Q_UNLIKELY(!inst)) {
            mutex.lock();
            if (!inst) {
                inst.reset(new T);
            }
            mutex.unlock();
        }
        return inst.data();
    }
};
//SocketManager* inst = Singleton<SocketManager>::Instance();
#endif // SINGLETON_H
