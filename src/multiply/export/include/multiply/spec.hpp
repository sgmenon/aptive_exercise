/* Copyright 2017 The MathWorks, Inc. */
#ifndef LIBMULTIPLY_SPEC_HPP
#define LIBMULTIPLY_SPEC_HPP

#include "package.hpp"

#ifdef BUILDING_MULTIPLY

/* This header is being included by files inside this module */
# define MULTIPLY_EXPORT          DLL_EXPORT_SYM

#else

/* This file is being include by other internal modules */

# define MULTIPLY_EXPORT          DLL_IMPORT_SYM

#endif

#endif // LIBMULTIPLY_SPEC_HPP
