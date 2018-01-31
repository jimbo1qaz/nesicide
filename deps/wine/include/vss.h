/*** Autogenerated by WIDL 3.0 from vss.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __vss_h__
#define __vss_h__

/* Forward declarations */

/* Headers for imported files */

#include <oaidl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef GUID VSS_ID;
typedef enum _VSS_APPLICATION_LEVEL {
    VSS_APP_AUTO = -1,
    VSS_APP_UNKNOWN = 0,
    VSS_APP_SYSTEM = 1,
    VSS_APP_BACK_END = 2,
    VSS_APP_FRONT_END = 3,
    VSS_APP_SYSTEM_RM = 4
} VSS_APPLICATION_LEVEL;
/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __vss_h__ */
