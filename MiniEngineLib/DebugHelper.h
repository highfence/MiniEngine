#pragma once

namespace MiniEngineLib
{
	using namespace std;

#define AppDebugBreak(message) \
{ \
	ZeroMemory(gDebugBuffer, sizeof(gDebugBuffer)); \
\
	if (mainWindowHandler->GetWinHandle() != NULL && mainWindowHandler->GetWinHandle() != INVALID_HANDLE_VALUE) \
	{ \
		auto title = (wsprintf(gDebugBuffer, TEXT("[File : %s, Func : %s, Line : %d]"), __FILE__, __FUNCTION__, __LINE__)); \
		MessageBox(mainWindowHandler->GetWinHandle(), (LPCTSTR)message, (LPCTSTR)title, NULL); \
	} \
\
	DebugBreak(); \
} \

}
