/*!
 * \file   macros.h
 * \author Attila Krüpl dr.
 * \date   09/11/2020
 */

#pragma once

#if !defined(DRKR_THREADING_EXPORT)
#   ifdef DRKR_THREADING_EXPORTS
#       define DRKR_THREADING_EXPORT __declspec(dllexport)
#   else
#       define DRKR_THREADING_EXPORT __declspec(dllimport)
#   endif
#endif
