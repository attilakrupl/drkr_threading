/*!
 * \file   spinlocktest.cpp
 * \author Attila Kr�pl dr.
 * \date   09/11/2020
 */

#include "stdafx.h"

namespace
{
    const std::string kReferenceString = "01234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950515253545556575859606162636465666768697071727374757677787980818283848586878889909192939495969798990123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899";

    nDrkrThreading::SpinLock lSpin;
    std::mutex               lMutex;
    std::string              lString;

    void WorkOnResource()
    {
        lSpin.Lock();
        for ( int i = 0; i < 100; ++i )
        {
            lString.append( std::to_string( i ) );
        }
        lSpin.Unlock();
    }

    void WaitCheckCPUWithLock()
    {
        lSpin.Lock();
        std::this_thread::sleep_for( std::chrono::milliseconds( 5000 ) );
        lSpin.Unlock();
    }

    void WaitCheckCPUWithMutex()
    {
        lMutex.lock();
        std::this_thread::sleep_for( std::chrono::milliseconds( 5000 ) );
        lMutex.unlock();
    }
}

TEST( ThreadingTest, SpinLockOne )
{
    std::thread lThread1( WorkOnResource );
    std::thread lThread2( WorkOnResource );

    lThread1.join();
    lThread2.join();

    EXPECT_EQ( kReferenceString, lString );
}

TEST( ThreadingTest, SpinLockCPUUsage )
{
    std::thread lThread1( WaitCheckCPUWithLock );
    std::thread lThread2( WaitCheckCPUWithLock );

    lThread1.join();
    lThread2.join();

    EXPECT_EQ( true, true );
}

TEST( ThreadingTest, MutexCPUUsage )
{
    std::thread lThread1( WaitCheckCPUWithMutex );
    std::thread lThread2( WaitCheckCPUWithMutex );

    lThread1.join();
    lThread2.join();

    EXPECT_EQ( true, true );
}
