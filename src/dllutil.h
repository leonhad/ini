/*
 * This file is part of INI.
 * Copyright (C) 2012 Leonardo Alves da Costa
 * mailto:leonhad AT gmail DOT com
 *
 * PDF Tools is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * PDF Tools is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#pragma once

#ifdef _WINDOWS

#include <SDKDDKVer.h>

#pragma warning( disable: 4251 )

#ifdef INI_EXPORTS
#define EXPORT_INI __declspec(dllexport)
#else
#define EXPORT_INI __declspec(dllimport) void HelloWorld();
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#else

#define EXPORT_INI

#endif
