#pragma once

#include <Windows.h>
#include <string>
#include <memory>
#include <functional>

#include <stdio.h>
#include <io.h>
#include <fcntl.h>

// WindowClasses Headers
#include "IChildWindowHandleable.h"
#include "MiniTimer.h"
#include "MainWindow.h"
#include "RenderWindow.h"
#include "EditWindow.h"
#include "TextWindow.h"

// Math Headers
#include "Vector.h"

// Debug Headers
#include "DebugHelper.h"
static TCHAR gDebugBuffer[2048];