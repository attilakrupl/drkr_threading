/*!
 * \file   spinlock.cpp
 * \author Attila Kr�pl dr.
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
}

void SpinLock::Unlock()
{
}
