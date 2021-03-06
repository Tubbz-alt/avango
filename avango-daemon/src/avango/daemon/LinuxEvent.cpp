// -*- Mode:C++ -*-

/************************************************************************\
*                                                                        *
* This file is part of Avango.                                           *
*                                                                        *
* Copyright 1997 - 2008 Fraunhofer-Gesellschaft zur Foerderung der       *
* angewandten Forschung (FhG), Munich, Germany.                          *
*                                                                        *
* Avango is free software: you can redistribute it and/or modify         *
* it under the terms of the GNU Lesser General Public License as         *
* published by the Free Software Foundation, version 3.                  *
*                                                                        *
* Avango is distributed in the hope that it will be useful,              *
* but WITHOUT ANY WARRANTY; without even the implied warranty of         *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
* GNU General Public License for more details.                           *
*                                                                        *
* You should have received a copy of the GNU Lesser General Public       *
* License along with Avango. If not, see <http://www.gnu.org/licenses/>. *
*                                                                        *
* Avango is a trademark owned by FhG.                                    *
*                                                                        *
\************************************************************************/

#include <avango/daemon/LinuxEvent.h>

namespace
{
static const av::daemon::LinuxEvent sEventMap;
}

av::daemon::LinuxEvent::LinuxEvent()
{
    // own definitions
    insert(std::make_pair("STATION_BUTTON", 0x00));
    insert(std::make_pair("STATION_VALUE", 0x01));
    insert(std::make_pair("STATION_LED", 0x02));

    // definitions from /usr/include/linux/input.h
    insert(std::make_pair("EV_SYN", 0x00));
    insert(std::make_pair("EV_KEY", 0x01));
    insert(std::make_pair("EV_REL", 0x02));
    insert(std::make_pair("EV_ABS", 0x03));
    insert(std::make_pair("EV_MSC", 0x04));
    insert(std::make_pair("EV_SW", 0x05));
    insert(std::make_pair("EV_LED", 0x11));
    insert(std::make_pair("EV_SND", 0x12));
    insert(std::make_pair("EV_REP", 0x14));
    insert(std::make_pair("EV_FF", 0x15));
    insert(std::make_pair("EV_PWR", 0x16));
    insert(std::make_pair("EV_FF_STATUS", 0x17));
    insert(std::make_pair("EV_MAX", 0x1f));
    insert(std::make_pair("SYN_REPORT", 0));
    insert(std::make_pair("SYN_CONFIG", 1));
    insert(std::make_pair("KEY_RESERVED", 0));
    insert(std::make_pair("KEY_ESC", 1));
    insert(std::make_pair("KEY_1", 2));
    insert(std::make_pair("KEY_2", 3));
    insert(std::make_pair("KEY_3", 4));
    insert(std::make_pair("KEY_4", 5));
    insert(std::make_pair("KEY_5", 6));
    insert(std::make_pair("KEY_6", 7));
    insert(std::make_pair("KEY_7", 8));
    insert(std::make_pair("KEY_8", 9));
    insert(std::make_pair("KEY_9", 10));
    insert(std::make_pair("KEY_0", 11));
    insert(std::make_pair("KEY_MINUS", 12));
    insert(std::make_pair("KEY_EQUAL", 13));
    insert(std::make_pair("KEY_BACKSPACE", 14));
    insert(std::make_pair("KEY_TAB", 15));
    insert(std::make_pair("KEY_Q", 16));
    insert(std::make_pair("KEY_W", 17));
    insert(std::make_pair("KEY_E", 18));
    insert(std::make_pair("KEY_R", 19));
    insert(std::make_pair("KEY_T", 20));
    insert(std::make_pair("KEY_Y", 21));
    insert(std::make_pair("KEY_U", 22));
    insert(std::make_pair("KEY_I", 23));
    insert(std::make_pair("KEY_O", 24));
    insert(std::make_pair("KEY_P", 25));
    insert(std::make_pair("KEY_LEFTBRACE", 26));
    insert(std::make_pair("KEY_RIGHTBRACE", 27));
    insert(std::make_pair("KEY_ENTER", 28));
    insert(std::make_pair("KEY_LEFTCTRL", 29));
    insert(std::make_pair("KEY_A", 30));
    insert(std::make_pair("KEY_S", 31));
    insert(std::make_pair("KEY_D", 32));
    insert(std::make_pair("KEY_F", 33));
    insert(std::make_pair("KEY_G", 34));
    insert(std::make_pair("KEY_H", 35));
    insert(std::make_pair("KEY_J", 36));
    insert(std::make_pair("KEY_K", 37));
    insert(std::make_pair("KEY_L", 38));
    insert(std::make_pair("KEY_SEMICOLON", 39));
    insert(std::make_pair("KEY_APOSTROPHE", 40));
    insert(std::make_pair("KEY_GRAVE", 41));
    insert(std::make_pair("KEY_LEFTSHIFT", 42));
    insert(std::make_pair("KEY_BACKSLASH", 43));
    insert(std::make_pair("KEY_Z", 44));
    insert(std::make_pair("KEY_X", 45));
    insert(std::make_pair("KEY_C", 46));
    insert(std::make_pair("KEY_V", 47));
    insert(std::make_pair("KEY_B", 48));
    insert(std::make_pair("KEY_N", 49));
    insert(std::make_pair("KEY_M", 50));
    insert(std::make_pair("KEY_COMMA", 51));
    insert(std::make_pair("KEY_DOT", 52));
    insert(std::make_pair("KEY_SLASH", 53));
    insert(std::make_pair("KEY_RIGHTSHIFT", 54));
    insert(std::make_pair("KEY_KPASTERISK", 55));
    insert(std::make_pair("KEY_LEFTALT", 56));
    insert(std::make_pair("KEY_SPACE", 57));
    insert(std::make_pair("KEY_CAPSLOCK", 58));
    insert(std::make_pair("KEY_F1", 59));
    insert(std::make_pair("KEY_F2", 60));
    insert(std::make_pair("KEY_F3", 61));
    insert(std::make_pair("KEY_F4", 62));
    insert(std::make_pair("KEY_F5", 63));
    insert(std::make_pair("KEY_F6", 64));
    insert(std::make_pair("KEY_F7", 65));
    insert(std::make_pair("KEY_F8", 66));
    insert(std::make_pair("KEY_F9", 67));
    insert(std::make_pair("KEY_F10", 68));
    insert(std::make_pair("KEY_NUMLOCK", 69));
    insert(std::make_pair("KEY_SCROLLLOCK", 70));
    insert(std::make_pair("KEY_KP7", 71));
    insert(std::make_pair("KEY_KP8", 72));
    insert(std::make_pair("KEY_KP9", 73));
    insert(std::make_pair("KEY_KPMINUS", 74));
    insert(std::make_pair("KEY_KP4", 75));
    insert(std::make_pair("KEY_KP5", 76));
    insert(std::make_pair("KEY_KP6", 77));
    insert(std::make_pair("KEY_KPPLUS", 78));
    insert(std::make_pair("KEY_KP1", 79));
    insert(std::make_pair("KEY_KP2", 80));
    insert(std::make_pair("KEY_KP3", 81));
    insert(std::make_pair("KEY_KP0", 82));
    insert(std::make_pair("KEY_KPDOT", 83));
    insert(std::make_pair("KEY_ZENKAKUHANKAKU", 85));
    insert(std::make_pair("KEY_102ND", 86));
    insert(std::make_pair("KEY_F11", 87));
    insert(std::make_pair("KEY_F12", 88));
    insert(std::make_pair("KEY_RO", 89));
    insert(std::make_pair("KEY_KATAKANA", 90));
    insert(std::make_pair("KEY_HIRAGANA", 91));
    insert(std::make_pair("KEY_HENKAN", 92));
    insert(std::make_pair("KEY_KATAKANAHIRAGANA", 93));
    insert(std::make_pair("KEY_MUHENKAN", 94));
    insert(std::make_pair("KEY_KPJPCOMMA", 95));
    insert(std::make_pair("KEY_KPENTER", 96));
    insert(std::make_pair("KEY_RIGHTCTRL", 97));
    insert(std::make_pair("KEY_KPSLASH", 98));
    insert(std::make_pair("KEY_SYSRQ", 99));
    insert(std::make_pair("KEY_RIGHTALT", 100));
    insert(std::make_pair("KEY_LINEFEED", 101));
    insert(std::make_pair("KEY_HOME", 102));
    insert(std::make_pair("KEY_UP", 103));
    insert(std::make_pair("KEY_PAGEUP", 104));
    insert(std::make_pair("KEY_LEFT", 105));
    insert(std::make_pair("KEY_RIGHT", 106));
    insert(std::make_pair("KEY_END", 107));
    insert(std::make_pair("KEY_DOWN", 108));
    insert(std::make_pair("KEY_PAGEDOWN", 109));
    insert(std::make_pair("KEY_INSERT", 110));
    insert(std::make_pair("KEY_DELETE", 111));
    insert(std::make_pair("KEY_MACRO", 112));
    insert(std::make_pair("KEY_MUTE", 113));
    insert(std::make_pair("KEY_VOLUMEDOWN", 114));
    insert(std::make_pair("KEY_VOLUMEUP", 115));
    insert(std::make_pair("KEY_POWER", 116));
    insert(std::make_pair("KEY_KPEQUAL", 117));
    insert(std::make_pair("KEY_KPPLUSMINUS", 118));
    insert(std::make_pair("KEY_PAUSE", 119));
    insert(std::make_pair("KEY_KPCOMMA", 121));
    insert(std::make_pair("KEY_HANGEUL", 122));
    // insert(std::make_pair("KEY_HANGUEL", KEY_HANGEUL));
    insert(std::make_pair("KEY_HANJA", 123));
    insert(std::make_pair("KEY_YEN", 124));
    insert(std::make_pair("KEY_LEFTMETA", 125));
    insert(std::make_pair("KEY_RIGHTMETA", 126));
    insert(std::make_pair("KEY_COMPOSE", 127));
    insert(std::make_pair("KEY_STOP", 128));
    insert(std::make_pair("KEY_AGAIN", 129));
    insert(std::make_pair("KEY_PROPS", 130));
    insert(std::make_pair("KEY_UNDO", 131));
    insert(std::make_pair("KEY_FRONT", 132));
    insert(std::make_pair("KEY_COPY", 133));
    insert(std::make_pair("KEY_OPEN", 134));
    insert(std::make_pair("KEY_PASTE", 135));
    insert(std::make_pair("KEY_FIND", 136));
    insert(std::make_pair("KEY_CUT", 137));
    insert(std::make_pair("KEY_HELP", 138));
    insert(std::make_pair("KEY_MENU", 139));
    insert(std::make_pair("KEY_CALC", 140));
    insert(std::make_pair("KEY_SETUP", 141));
    insert(std::make_pair("KEY_SLEEP", 142));
    insert(std::make_pair("KEY_WAKEUP", 143));
    insert(std::make_pair("KEY_FILE", 144));
    insert(std::make_pair("KEY_SENDFILE", 145));
    insert(std::make_pair("KEY_DELETEFILE", 146));
    insert(std::make_pair("KEY_XFER", 147));
    insert(std::make_pair("KEY_PROG1", 148));
    insert(std::make_pair("KEY_PROG2", 149));
    insert(std::make_pair("KEY_WWW", 150));
    insert(std::make_pair("KEY_MSDOS", 151));
    insert(std::make_pair("KEY_COFFEE", 152));
    insert(std::make_pair("KEY_DIRECTION", 153));
    insert(std::make_pair("KEY_CYCLEWINDOWS", 154));
    insert(std::make_pair("KEY_MAIL", 155));
    insert(std::make_pair("KEY_BOOKMARKS", 156));
    insert(std::make_pair("KEY_COMPUTER", 157));
    insert(std::make_pair("KEY_BACK", 158));
    insert(std::make_pair("KEY_FORWARD", 159));
    insert(std::make_pair("KEY_CLOSECD", 160));
    insert(std::make_pair("KEY_EJECTCD", 161));
    insert(std::make_pair("KEY_EJECTCLOSECD", 162));
    insert(std::make_pair("KEY_NEXTSONG", 163));
    insert(std::make_pair("KEY_PLAYPAUSE", 164));
    insert(std::make_pair("KEY_PREVIOUSSONG", 165));
    insert(std::make_pair("KEY_STOPCD", 166));
    insert(std::make_pair("KEY_RECORD", 167));
    insert(std::make_pair("KEY_REWIND", 168));
    insert(std::make_pair("KEY_PHONE", 169));
    insert(std::make_pair("KEY_ISO", 170));
    insert(std::make_pair("KEY_CONFIG", 171));
    insert(std::make_pair("KEY_HOMEPAGE", 172));
    insert(std::make_pair("KEY_REFRESH", 173));
    insert(std::make_pair("KEY_EXIT", 174));
    insert(std::make_pair("KEY_MOVE", 175));
    insert(std::make_pair("KEY_EDIT", 176));
    insert(std::make_pair("KEY_SCROLLUP", 177));
    insert(std::make_pair("KEY_SCROLLDOWN", 178));
    insert(std::make_pair("KEY_KPLEFTPAREN", 179));
    insert(std::make_pair("KEY_KPRIGHTPAREN", 180));
    insert(std::make_pair("KEY_NEW", 181));
    insert(std::make_pair("KEY_REDO", 182));
    insert(std::make_pair("KEY_F13", 183));
    insert(std::make_pair("KEY_F14", 184));
    insert(std::make_pair("KEY_F15", 185));
    insert(std::make_pair("KEY_F16", 186));
    insert(std::make_pair("KEY_F17", 187));
    insert(std::make_pair("KEY_F18", 188));
    insert(std::make_pair("KEY_F19", 189));
    insert(std::make_pair("KEY_F20", 190));
    insert(std::make_pair("KEY_F21", 191));
    insert(std::make_pair("KEY_F22", 192));
    insert(std::make_pair("KEY_F23", 193));
    insert(std::make_pair("KEY_F24", 194));
    insert(std::make_pair("KEY_PLAYCD", 200));
    insert(std::make_pair("KEY_PAUSECD", 201));
    insert(std::make_pair("KEY_PROG3", 202));
    insert(std::make_pair("KEY_PROG4", 203));
    insert(std::make_pair("KEY_SUSPEND", 205));
    insert(std::make_pair("KEY_CLOSE", 206));
    insert(std::make_pair("KEY_PLAY", 207));
    insert(std::make_pair("KEY_FASTFORWARD", 208));
    insert(std::make_pair("KEY_BASSBOOST", 209));
    insert(std::make_pair("KEY_PRINT", 210));
    insert(std::make_pair("KEY_HP", 211));
    insert(std::make_pair("KEY_CAMERA", 212));
    insert(std::make_pair("KEY_SOUND", 213));
    insert(std::make_pair("KEY_QUESTION", 214));
    insert(std::make_pair("KEY_EMAIL", 215));
    insert(std::make_pair("KEY_CHAT", 216));
    insert(std::make_pair("KEY_SEARCH", 217));
    insert(std::make_pair("KEY_CONNECT", 218));
    insert(std::make_pair("KEY_FINANCE", 219));
    insert(std::make_pair("KEY_SPORT", 220));
    insert(std::make_pair("KEY_SHOP", 221));
    insert(std::make_pair("KEY_ALTERASE", 222));
    insert(std::make_pair("KEY_CANCEL", 223));
    insert(std::make_pair("KEY_BRIGHTNESSDOWN", 224));
    insert(std::make_pair("KEY_BRIGHTNESSUP", 225));
    insert(std::make_pair("KEY_MEDIA", 226));
    insert(std::make_pair("KEY_SWITCHVIDEOMODE", 227));
    insert(std::make_pair("KEY_KBDILLUMTOGGLE", 228));
    insert(std::make_pair("KEY_KBDILLUMDOWN", 229));
    insert(std::make_pair("KEY_KBDILLUMUP", 230));
    insert(std::make_pair("KEY_SEND", 231));
    insert(std::make_pair("KEY_REPLY", 232));
    insert(std::make_pair("KEY_FORWARDMAIL", 233));
    insert(std::make_pair("KEY_SAVE", 234));
    insert(std::make_pair("KEY_DOCUMENTS", 235));
    insert(std::make_pair("KEY_BATTERY", 236));
    insert(std::make_pair("KEY_UNKNOWN", 240));
    insert(std::make_pair("BTN_MISC", 0x100));
    insert(std::make_pair("BTN_0", 0x100));
    insert(std::make_pair("BTN_1", 0x101));
    insert(std::make_pair("BTN_2", 0x102));
    insert(std::make_pair("BTN_3", 0x103));
    insert(std::make_pair("BTN_4", 0x104));
    insert(std::make_pair("BTN_5", 0x105));
    insert(std::make_pair("BTN_6", 0x106));
    insert(std::make_pair("BTN_7", 0x107));
    insert(std::make_pair("BTN_8", 0x108));
    insert(std::make_pair("BTN_9", 0x109));
    insert(std::make_pair("BTN_MOUSE", 0x110));
    insert(std::make_pair("BTN_LEFT", 0x110));
    insert(std::make_pair("BTN_RIGHT", 0x111));
    insert(std::make_pair("BTN_MIDDLE", 0x112));
    insert(std::make_pair("BTN_SIDE", 0x113));
    insert(std::make_pair("BTN_EXTRA", 0x114));
    insert(std::make_pair("BTN_FORWARD", 0x115));
    insert(std::make_pair("BTN_BACK", 0x116));
    insert(std::make_pair("BTN_TASK", 0x117));
    insert(std::make_pair("BTN_JOYSTICK", 0x120));
    insert(std::make_pair("BTN_TRIGGER", 0x120));
    insert(std::make_pair("BTN_THUMB", 0x121));
    insert(std::make_pair("BTN_THUMB2", 0x122));
    insert(std::make_pair("BTN_TOP", 0x123));
    insert(std::make_pair("BTN_TOP2", 0x124));
    insert(std::make_pair("BTN_PINKIE", 0x125));
    insert(std::make_pair("BTN_BASE", 0x126));
    insert(std::make_pair("BTN_BASE2", 0x127));
    insert(std::make_pair("BTN_BASE3", 0x128));
    insert(std::make_pair("BTN_BASE4", 0x129));
    insert(std::make_pair("BTN_BASE5", 0x12a));
    insert(std::make_pair("BTN_BASE6", 0x12b));
    insert(std::make_pair("BTN_DEAD", 0x12f));
    insert(std::make_pair("BTN_GAMEPAD", 0x130));
    insert(std::make_pair("BTN_A", 0x130));
    insert(std::make_pair("BTN_B", 0x131));
    insert(std::make_pair("BTN_C", 0x132));
    insert(std::make_pair("BTN_X", 0x133));
    insert(std::make_pair("BTN_Y", 0x134));
    insert(std::make_pair("BTN_Z", 0x135));
    insert(std::make_pair("BTN_TL", 0x136));
    insert(std::make_pair("BTN_TR", 0x137));
    insert(std::make_pair("BTN_TL2", 0x138));
    insert(std::make_pair("BTN_TR2", 0x139));
    insert(std::make_pair("BTN_SELECT", 0x13a));
    insert(std::make_pair("BTN_START", 0x13b));
    insert(std::make_pair("BTN_MODE", 0x13c));
    insert(std::make_pair("BTN_THUMBL", 0x13d));
    insert(std::make_pair("BTN_THUMBR", 0x13e));
    insert(std::make_pair("BTN_DIGI", 0x140));
    insert(std::make_pair("BTN_TOOL_PEN", 0x140));
    insert(std::make_pair("BTN_TOOL_RUBBER", 0x141));
    insert(std::make_pair("BTN_TOOL_BRUSH", 0x142));
    insert(std::make_pair("BTN_TOOL_PENCIL", 0x143));
    insert(std::make_pair("BTN_TOOL_AIRBRUSH", 0x144));
    insert(std::make_pair("BTN_TOOL_FINGER", 0x145));
    insert(std::make_pair("BTN_TOOL_MOUSE", 0x146));
    insert(std::make_pair("BTN_TOOL_LENS", 0x147));
    insert(std::make_pair("BTN_TOUCH", 0x14a));
    insert(std::make_pair("BTN_STYLUS", 0x14b));
    insert(std::make_pair("BTN_STYLUS2", 0x14c));
    insert(std::make_pair("BTN_TOOL_DOUBLETAP", 0x14d));
    insert(std::make_pair("BTN_TOOL_TRIPLETAP", 0x14e));
    insert(std::make_pair("BTN_WHEEL", 0x150));
    insert(std::make_pair("BTN_GEAR_DOWN", 0x150));
    insert(std::make_pair("BTN_GEAR_UP", 0x151));

    insert(std::make_pair("BTN_SOUTH", 0x130));
    insert(std::make_pair("BTN_EAST", 0x131));
    insert(std::make_pair("BTN_NORTH", 0x133));
    insert(std::make_pair("BTN_WEST", 0x134));
    insert(std::make_pair("BTN_TRIGGER_HAPPY", 0x2c0));
    insert(std::make_pair("BTN_TRIGGER_HAPPY1", 0x2c0));
    insert(std::make_pair("BTN_TRIGGER_HAPPY2", 0x2c1));
    insert(std::make_pair("BTN_TRIGGER_HAPPY3", 0x2c2));
    insert(std::make_pair("BTN_TRIGGER_HAPPY4", 0x2c3));
    insert(std::make_pair("BTN_TRIGGER_HAPPY5", 0x2c4));
    insert(std::make_pair("BTN_TRIGGER_HAPPY6", 0x2c5));
    insert(std::make_pair("BTN_TRIGGER_HAPPY7", 0x2c6));
    insert(std::make_pair("BTN_TRIGGER_HAPPY8", 0x2c7));
    insert(std::make_pair("BTN_TRIGGER_HAPPY9", 0x2c8));
    insert(std::make_pair("BTN_TRIGGER_HAPPY10", 0x2c9));
    insert(std::make_pair("BTN_TRIGGER_HAPPY11", 0x2ca));
    insert(std::make_pair("BTN_TRIGGER_HAPPY12", 0x2cb));
    insert(std::make_pair("BTN_TRIGGER_HAPPY13", 0x2cc));
    insert(std::make_pair("BTN_TRIGGER_HAPPY14", 0x2cd));
    insert(std::make_pair("BTN_TRIGGER_HAPPY15", 0x2ce));
    insert(std::make_pair("BTN_TRIGGER_HAPPY16", 0x2cf));

    insert(std::make_pair("KEY_OK", 0x160));
    insert(std::make_pair("KEY_SELECT", 0x161));
    insert(std::make_pair("KEY_GOTO", 0x162));
    insert(std::make_pair("KEY_CLEAR", 0x163));
    insert(std::make_pair("KEY_POWER2", 0x164));
    insert(std::make_pair("KEY_OPTION", 0x165));
    insert(std::make_pair("KEY_INFO", 0x166));
    insert(std::make_pair("KEY_TIME", 0x167));
    insert(std::make_pair("KEY_VENDOR", 0x168));
    insert(std::make_pair("KEY_ARCHIVE", 0x169));
    insert(std::make_pair("KEY_PROGRAM", 0x16a));
    insert(std::make_pair("KEY_CHANNEL", 0x16b));
    insert(std::make_pair("KEY_FAVORITES", 0x16c));
    insert(std::make_pair("KEY_EPG", 0x16d));
    insert(std::make_pair("KEY_PVR", 0x16e));
    insert(std::make_pair("KEY_MHP", 0x16f));
    insert(std::make_pair("KEY_LANGUAGE", 0x170));
    insert(std::make_pair("KEY_TITLE", 0x171));
    insert(std::make_pair("KEY_SUBTITLE", 0x172));
    insert(std::make_pair("KEY_ANGLE", 0x173));
    insert(std::make_pair("KEY_ZOOM", 0x174));
    insert(std::make_pair("KEY_MODE", 0x175));
    insert(std::make_pair("KEY_KEYBOARD", 0x176));
    insert(std::make_pair("KEY_SCREEN", 0x177));
    insert(std::make_pair("KEY_PC", 0x178));
    insert(std::make_pair("KEY_TV", 0x179));
    insert(std::make_pair("KEY_TV2", 0x17a));
    insert(std::make_pair("KEY_VCR", 0x17b));
    insert(std::make_pair("KEY_VCR2", 0x17c));
    insert(std::make_pair("KEY_SAT", 0x17d));
    insert(std::make_pair("KEY_SAT2", 0x17e));
    insert(std::make_pair("KEY_CD", 0x17f));
    insert(std::make_pair("KEY_TAPE", 0x180));
    insert(std::make_pair("KEY_RADIO", 0x181));
    insert(std::make_pair("KEY_TUNER", 0x182));
    insert(std::make_pair("KEY_PLAYER", 0x183));
    insert(std::make_pair("KEY_TEXT", 0x184));
    insert(std::make_pair("KEY_DVD", 0x185));
    insert(std::make_pair("KEY_AUX", 0x186));
    insert(std::make_pair("KEY_MP3", 0x187));
    insert(std::make_pair("KEY_AUDIO", 0x188));
    insert(std::make_pair("KEY_VIDEO", 0x189));
    insert(std::make_pair("KEY_DIRECTORY", 0x18a));
    insert(std::make_pair("KEY_LIST", 0x18b));
    insert(std::make_pair("KEY_MEMO", 0x18c));
    insert(std::make_pair("KEY_CALENDAR", 0x18d));
    insert(std::make_pair("KEY_RED", 0x18e));
    insert(std::make_pair("KEY_GREEN", 0x18f));
    insert(std::make_pair("KEY_YELLOW", 0x190));
    insert(std::make_pair("KEY_BLUE", 0x191));
    insert(std::make_pair("KEY_CHANNELUP", 0x192));
    insert(std::make_pair("KEY_CHANNELDOWN", 0x193));
    insert(std::make_pair("KEY_FIRST", 0x194));
    insert(std::make_pair("KEY_LAST", 0x195));
    insert(std::make_pair("KEY_AB", 0x196));
    insert(std::make_pair("KEY_NEXT", 0x197));
    insert(std::make_pair("KEY_RESTART", 0x198));
    insert(std::make_pair("KEY_SLOW", 0x199));
    insert(std::make_pair("KEY_SHUFFLE", 0x19a));
    insert(std::make_pair("KEY_BREAK", 0x19b));
    insert(std::make_pair("KEY_PREVIOUS", 0x19c));
    insert(std::make_pair("KEY_DIGITS", 0x19d));
    insert(std::make_pair("KEY_TEEN", 0x19e));
    insert(std::make_pair("KEY_TWEN", 0x19f));
    insert(std::make_pair("KEY_DEL_EOL", 0x1c0));
    insert(std::make_pair("KEY_DEL_EOS", 0x1c1));
    insert(std::make_pair("KEY_INS_LINE", 0x1c2));
    insert(std::make_pair("KEY_DEL_LINE", 0x1c3));
    insert(std::make_pair("KEY_FN", 0x1d0));
    insert(std::make_pair("KEY_FN_ESC", 0x1d1));
    insert(std::make_pair("KEY_FN_F1", 0x1d2));
    insert(std::make_pair("KEY_FN_F2", 0x1d3));
    insert(std::make_pair("KEY_FN_F3", 0x1d4));
    insert(std::make_pair("KEY_FN_F4", 0x1d5));
    insert(std::make_pair("KEY_FN_F5", 0x1d6));
    insert(std::make_pair("KEY_FN_F6", 0x1d7));
    insert(std::make_pair("KEY_FN_F7", 0x1d8));
    insert(std::make_pair("KEY_FN_F8", 0x1d9));
    insert(std::make_pair("KEY_FN_F9", 0x1da));
    insert(std::make_pair("KEY_FN_F10", 0x1db));
    insert(std::make_pair("KEY_FN_F11", 0x1dc));
    insert(std::make_pair("KEY_FN_F12", 0x1dd));
    insert(std::make_pair("KEY_FN_1", 0x1de));
    insert(std::make_pair("KEY_FN_2", 0x1df));
    insert(std::make_pair("KEY_FN_D", 0x1e0));
    insert(std::make_pair("KEY_FN_E", 0x1e1));
    insert(std::make_pair("KEY_FN_F", 0x1e2));
    insert(std::make_pair("KEY_FN_S", 0x1e3));
    insert(std::make_pair("KEY_FN_B", 0x1e4));
    insert(std::make_pair("KEY_BRL_DOT1", 0x1f1));
    insert(std::make_pair("KEY_BRL_DOT2", 0x1f2));
    insert(std::make_pair("KEY_BRL_DOT3", 0x1f3));
    insert(std::make_pair("KEY_BRL_DOT4", 0x1f4));
    insert(std::make_pair("KEY_BRL_DOT5", 0x1f5));
    insert(std::make_pair("KEY_BRL_DOT6", 0x1f6));
    insert(std::make_pair("KEY_BRL_DOT7", 0x1f7));
    insert(std::make_pair("KEY_BRL_DOT8", 0x1f8));
    // insert(std::make_pair("KEY_MIN_INTERESTING", KEY_MUTE));
    insert(std::make_pair("KEY_MAX", 0x1ff));
    insert(std::make_pair("REL_X", 0x00));
    insert(std::make_pair("REL_Y", 0x01));
    insert(std::make_pair("REL_Z", 0x02));
    insert(std::make_pair("REL_RX", 0x03));
    insert(std::make_pair("REL_RY", 0x04));
    insert(std::make_pair("REL_RZ", 0x05));
    insert(std::make_pair("REL_HWHEEL", 0x06));
    insert(std::make_pair("REL_DIAL", 0x07));
    insert(std::make_pair("REL_WHEEL", 0x08));
    insert(std::make_pair("REL_MISC", 0x09));
    insert(std::make_pair("REL_MAX", 0x0f));
    insert(std::make_pair("ABS_X", 0x00));
    insert(std::make_pair("ABS_Y", 0x01));
    insert(std::make_pair("ABS_Z", 0x02));
    insert(std::make_pair("ABS_RX", 0x03));
    insert(std::make_pair("ABS_RY", 0x04));
    insert(std::make_pair("ABS_RZ", 0x05));
    insert(std::make_pair("ABS_THROTTLE", 0x06));
    insert(std::make_pair("ABS_RUDDER", 0x07));
    insert(std::make_pair("ABS_WHEEL", 0x08));
    insert(std::make_pair("ABS_GAS", 0x09));
    insert(std::make_pair("ABS_BRAKE", 0x0a));
    insert(std::make_pair("ABS_HAT0X", 0x10));
    insert(std::make_pair("ABS_HAT0Y", 0x11));
    insert(std::make_pair("ABS_HAT1X", 0x12));
    insert(std::make_pair("ABS_HAT1Y", 0x13));
    insert(std::make_pair("ABS_HAT2X", 0x14));
    insert(std::make_pair("ABS_HAT2Y", 0x15));
    insert(std::make_pair("ABS_HAT3X", 0x16));
    insert(std::make_pair("ABS_HAT3Y", 0x17));
    insert(std::make_pair("ABS_PRESSURE", 0x18));
    insert(std::make_pair("ABS_DISTANCE", 0x19));
    insert(std::make_pair("ABS_TILT_X", 0x1a));
    insert(std::make_pair("ABS_TILT_Y", 0x1b));
    insert(std::make_pair("ABS_TOOL_WIDTH", 0x1c));
    insert(std::make_pair("ABS_VOLUME", 0x20));
    insert(std::make_pair("ABS_MISC", 0x28));
    insert(std::make_pair("ABS_MAX", 0x3f));
    insert(std::make_pair("SW_LID", 0x00));
    insert(std::make_pair("SW_TABLET_MODE", 0x01));
    insert(std::make_pair("SW_HEADPHONE_INSERT", 0x02));
    insert(std::make_pair("SW_MAX", 0x0f));
    insert(std::make_pair("MSC_SERIAL", 0x00));
    insert(std::make_pair("MSC_PULSELED", 0x01));
    insert(std::make_pair("MSC_GESTURE", 0x02));
    insert(std::make_pair("MSC_RAW", 0x03));
    insert(std::make_pair("MSC_SCAN", 0x04));
    insert(std::make_pair("MSC_MAX", 0x07));
    insert(std::make_pair("LED_NUML", 0x00));
    insert(std::make_pair("LED_CAPSL", 0x01));
    insert(std::make_pair("LED_SCROLLL", 0x02));
    insert(std::make_pair("LED_COMPOSE", 0x03));
    insert(std::make_pair("LED_KANA", 0x04));
    insert(std::make_pair("LED_SLEEP", 0x05));
    insert(std::make_pair("LED_SUSPEND", 0x06));
    insert(std::make_pair("LED_MUTE", 0x07));
    insert(std::make_pair("LED_MISC", 0x08));
    insert(std::make_pair("LED_MAIL", 0x09));
    insert(std::make_pair("LED_CHARGING", 0x0a));
    insert(std::make_pair("LED_MAX", 0x0f));
    // custom
    insert(std::make_pair("BTN_BUW1", 0x2af));
}

unsigned long av::daemon::LinuxEvent::getEventCode(const std::string& eventType)
{
    const_iterator return_value = sEventMap.find(eventType);
    return (return_value != sEventMap.end()) ? return_value->second : 0;
}
