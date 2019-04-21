/* Copyright 2017 The MathWorks, Inc. */
#ifndef LIBDIVIDE_SPEC_HPP
#define LIBDIVIDE_SPEC_HPP

#include "package.hpp"

#ifdef BUILDING_DIVIDE

/* This header is being included by files inside this module */
# define DIVIDE_EXPORT          DLL_EXPORT_SYM

#else

/* This file is being include by other internal modules */

# define DIVIDE_EXPORT          DLL_IMPORT_SYM

#endif

#endif // LIBDIVIDE_SPEC_HPP
