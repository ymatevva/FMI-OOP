#pragma once
#include"SetExpression.h"
#include"StringVieww.h"
#include"Addition.h"
#include"Difference.h"
#include"Intersection.h"
#include"Union.h"
#include"XOR.h"
#include"Singleton.h"

SetExpression* setFactory(StringView str);
