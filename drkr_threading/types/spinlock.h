/*!
 * \file   spinlock.h
 * \author Attila Kr�pl dr.
 * \date   08/11/2020
 */

#pragma once

namespace nDrkrThreading
{
    class DRKR_THREADING_EXPORT SpinLock
    {
    private:
        std::atomic_flag mFlag;

    public:
        SpinLock();

    public:
        void Lock();
        void Unlock();
    };
}
