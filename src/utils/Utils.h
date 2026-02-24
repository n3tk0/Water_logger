#pragma once
#include <Arduino.h>
#include <FS.h>
#include "../core/Config.h"

// getVersionString() is defined inline in Config.h – do NOT redeclare here.

// ---- String helpers ----
String formatFileSize(uint64_t bytes);

// ---- Path helpers ----
String buildPath(const String& dir, const String& name);
String sanitizePath(const String& path);
String sanitizeFilename(const String& filename);

// ---- FS helpers ----
bool deleteRecursive(fs::FS& fs, const String& path);