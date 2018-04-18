#pragma once

#ifdef __cplusplus
extern "C" {
#endif

    // Time units
    typedef enum {
        US = 0,
        MS = 1,
        S = 2,
    } TimeUnits;

    #define	PAGE_SIZE		(4*1024)
    #define	BLOCK_SIZE		(4*1024)

#ifdef __cplusplus
}
#endif
