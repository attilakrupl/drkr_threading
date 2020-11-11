/*!
 * \file   spinlock.cpp
 * \author Attila Krüpl dr.
 * \date   08/11/2020
 */

#include "stdafx.h"

using namespace nDrkrThreading;

SpinLock::SpinLock()
    : mFlag()
{
    mFlag.clear();
}

void SpinLock::Lock()
{
    while ( mFlag.test_and_set() );
}

void SpinLock::Unlock()
{
    mFlag.clear();
}
