#include "core/config.h"
#include "core/json.h"
#include "core/update.h"
#include "engine/clicker.h"
#include "engine/engine.h"
#include "lang/lang.h"
#include "ui/gfx.h"
#include "ui/msgbox.h"
#include "ui/statusbar.h"
#include <commctrl.h>
#include <commdlg.h>
#include <shellapi.h>
#include <shlobj.h>
#include <string>
#include <uxtheme.h>
#include <vector>
#include <windows.h>
#include <windowsx.h>

#ifndef CSIDL_PROGRAMS
#define CSIDL_PROGRAMS 0x0002
#endif
#ifndef CSIDL_DESKTOPDIRECTORY
#define CSIDL_DESKTOPDIRECTORY 0x0010
#endif
#ifndef CSIDL_LOCALAPPDATA
#define CSIDL_LOCALAPPDATA 0x001c
#endif

#define WM_APP_TRAY (WM_APP + 1)
#define WM_APP_UPDATE (WM_APP + 2)
#define WM_APP_PLAYDONE (WM_APP + 3)
#define WM_APP_QUIT (WM_APP + 7)
#define WM_IN_OK (WM_APP + 20)
#define WM_IN_CANCEL (WM_APP + 21)

enum { HK_ID_REC = 1, HK_ID_PLAY = 2 };

enum {
  IDM_REC = 100,
  IDM_PLAY,
  IDM_OPEN,
  IDM_SAVE,
  IDM_SP025 = 107,
  IDM_SP05 = 108,
  IDM_SP075 = 109,
  IDM_SP1 = 110,
  IDM_SP125 = 111,
  IDM_SP15 = 112,
  IDM_SP2 = 113,
  IDM_SP3 = 114,
  IDM_SP4 = 115,
  IDM_SP5 = 116,
  IDM_SP8 = 117,
  IDM_SP10 = 118,
  IDM_SP50 = 119,
  IDM_SPTURBO = 120,
  IDM_SPMAX = 121,
  IDM_SPCUSTOM = 122,
  IDM_LP1 = 125,
  IDM_LP2,
  IDM_LP3,
  IDM_LP5,
  IDM_LP10,
  IDM_LP20,
  IDM_LP50,
  IDM_LP100,
  IDM_LP500,
  IDM_LP1000,
  IDM_LPCONT,
  IDM_LPCUSTOM,
  IDM_LPDELAY = 137,
  IDM_TH0 = 140,
  IDM_TH1,
  IDM_TH2,
  IDM_TRI0 = 143,
  IDM_TRI1,
  IDM_TRI2,
  IDM_UI0 = 146,
  IDM_UI1,
  IDM_UI2,
  IDM_LENG = 150,
  IDM_LENRU,
  IDM_LENZH,
  IDM_LENIMP,
  IDM_LENTR,
  IDM_HKR0 = 160,
  IDM_HKP0,
  IDM_PANIC_PAUSE = 165,
  IDM_PANIC_SCROLL,
  IDM_PANIC_ESC,
  IDM_PANIC_MOUSE,
  IDM_SB_SHOW = 175,
  IDM_SB_TOP,
  IDM_SB_BOTTOM,
  IDM_SB_FOLLOW,
  IDM_SB_PROGRESS,
  IDM_SB_ETA,
  IDM_SB_LEFT,
  IDM_SB_CENTER,
  IDM_SB_RIGHT,
  IDM_ASSOC_ONTY = 185,
  IDM_TOPMOST = 190,
  IDM_AUTOMINIMIZE = 191,
  IDM_BACKGROUND = 198,
  IDM_COPY_CLIPBOARD = 192,
  IDM_PASTE_CLIPBOARD = 193,
  IDM_CREATE_SHORTCUT = 194,
  IDM_INSTALL = 195,
  IDM_UNINSTALL = 196,
  IDM_UPDATE = 197,
  IDM_ABOUT,
  IDM_DONATE,
  IDM_EXIT,
  IDM_SAVE_CURRENT = 201,
  IDM_CLICK_START,
  IDM_CLICK_STOP,
  IDM_CLICK_INTERVAL,
  IDM_CLICK_TARGET_MOUSE,
  IDM_CLICK_TARGET_KEY,