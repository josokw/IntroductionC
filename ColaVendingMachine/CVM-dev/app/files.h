#ifndef FILES_H
#define FILES_H

/// Get current directory.
const char* getCurrentDir(void);

/// Adds relativePath and fname current directory path.
const char *getFullFilePath(const char *relativePath, const char *fname);

#endif