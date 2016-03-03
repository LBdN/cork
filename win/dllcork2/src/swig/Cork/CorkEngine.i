%module corkengine
%include "arrays_csharp.i"



%apply double INPUT[]  {double vertices[]}
%apply int INPUT[] {int faces[]}

%{
#include "../booleanEngine.h"
#include "CorkEngine.h"
%}

%include "../booleanEngine.h"
%include "CorkEngine.h"