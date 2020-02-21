#ifndef SYSTEMERRORS_H
#define SYSTEMERRORS_H

typedef enum { ERR_INIT_CHD, ERR_INIT_CNA, ERR_INIT_CLD } error_t;
typedef unsigned char systemErrors_t;

int setSystemError(error_t err);
int getSystemError(error_t err);
systemErrors_t getSystemErrors(void);
const char* getSystemErrorsString(void);

#endif