// Copyright (C) 2023 owoDra

#pragma once

#include "Logging/LogMacros.h"

GCEINTG_API DECLARE_LOG_CATEGORY_EXTERN(LogGCEI, Log, All);

#if !UE_BUILD_SHIPPING

#define GCEILOG(FormattedText, ...) UE_LOG(LogGCEI, Log, FormattedText, __VA_ARGS__)

#define GCEIENSURE(InExpression) ensure(InExpression)
#define GCEIENSURE_MSG(InExpression, InFormat, ...) ensureMsgf(InExpression, InFormat, __VA_ARGS__)
#define GCEIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) ensureAlwaysMsgf(InExpression, InFormat, __VA_ARGS__)

#define GCEICHECK(InExpression) check(InExpression)
#define GCEICHECK_MSG(InExpression, InFormat, ...) checkf(InExpression, InFormat, __VA_ARGS__)

#else

#define GCEILOG(FormattedText, ...)

#define GCEIENSURE(InExpression) InExpression
#define GCEIENSURE_MSG(InExpression, InFormat, ...) InExpression
#define GCEIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) InExpression

#define GCEICHECK(InExpression) InExpression
#define GCEICHECK_MSG(InExpression, InFormat, ...) InExpression

#endif