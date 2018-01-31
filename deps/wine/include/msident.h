/*** Autogenerated by WIDL 3.0 from msident.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __msident_h__
#define __msident_h__

/* Forward declarations */

#ifndef __IUserIdentity_FWD_DEFINED__
#define __IUserIdentity_FWD_DEFINED__
typedef interface IUserIdentity IUserIdentity;
#ifdef __cplusplus
interface IUserIdentity;
#endif /* __cplusplus */
#endif

#ifndef __IEnumUserIdentity_FWD_DEFINED__
#define __IEnumUserIdentity_FWD_DEFINED__
typedef interface IEnumUserIdentity IEnumUserIdentity;
#ifdef __cplusplus
interface IEnumUserIdentity;
#endif /* __cplusplus */
#endif

#ifndef __IUserIdentityManager_FWD_DEFINED__
#define __IUserIdentityManager_FWD_DEFINED__
typedef interface IUserIdentityManager IUserIdentityManager;
#ifdef __cplusplus
interface IUserIdentityManager;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <unknwn.h>
#include <ocidl.h>
#include <oleidl.h>
#include <oaidl.h>

#ifdef __cplusplus
extern "C" {
#endif

#define E_IDENTITIES_DISABLED       _HRESULT_TYPEDEF_(0x80007110)
#define S_IDENTITIES_DISABLED       _HRESULT_TYPEDEF_(0x00007110)
#define E_NO_CURRENT_IDENTITY       _HRESULT_TYPEDEF_(0x80007111)
#define E_USER_CANCELLED            _HRESULT_TYPEDEF_(0x80007112)
#define E_PROCESS_CANCELLED_SWITCH  _HRESULT_TYPEDEF_(0x80007113)
#define E_IDENTITY_NOT_FOUND        _HRESULT_TYPEDEF_(0x80007114)
#define E_IDENTITY_EXISTS           _HRESULT_TYPEDEF_(0x80007115)
#define E_IDENTITY_CHANGING         _HRESULT_TYPEDEF_(0x80007116)
/*****************************************************************************
 * IUserIdentity interface
 */
#ifndef __IUserIdentity_INTERFACE_DEFINED__
#define __IUserIdentity_INTERFACE_DEFINED__

#define GIF_ROAMING_FOLDER     0x0001
#define GIF_NON_ROAMING_FOLDER 0x0002
DEFINE_GUID(IID_IUserIdentity, 0xa9ae6c8e, 0x1d1b, 0x11d2, 0xb2,0x1a, 0x00,0xc0,0x4f,0xa3,0x57,0xfa);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("a9ae6c8e-1d1b-11d2-b21a-00c04fa357fa")
IUserIdentity : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE GetCookie(
        GUID *puidCookie) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetName(
        WCHAR *pszName,
        ULONG ulBuffSize) = 0;

    virtual HRESULT STDMETHODCALLTYPE OpenIdentityRegKey(
        DWORD dwDesiredAccess,
        HKEY *phKey) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetIdentityFolder(
        DWORD dwFlags,
        WCHAR *pszPath,
        ULONG ulBuffSize) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IUserIdentity, 0xa9ae6c8e, 0x1d1b, 0x11d2, 0xb2,0x1a, 0x00,0xc0,0x4f,0xa3,0x57,0xfa)
#endif
#else
typedef struct IUserIdentityVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IUserIdentity *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IUserIdentity *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IUserIdentity *This);

    /*** IUserIdentity methods ***/
    HRESULT (STDMETHODCALLTYPE *GetCookie)(
        IUserIdentity *This,
        GUID *puidCookie);

    HRESULT (STDMETHODCALLTYPE *GetName)(
        IUserIdentity *This,
        WCHAR *pszName,
        ULONG ulBuffSize);

    HRESULT (STDMETHODCALLTYPE *OpenIdentityRegKey)(
        IUserIdentity *This,
        DWORD dwDesiredAccess,
        HKEY *phKey);

    HRESULT (STDMETHODCALLTYPE *GetIdentityFolder)(
        IUserIdentity *This,
        DWORD dwFlags,
        WCHAR *pszPath,
        ULONG ulBuffSize);

    END_INTERFACE
} IUserIdentityVtbl;

interface IUserIdentity {
    CONST_VTBL IUserIdentityVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IUserIdentity_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IUserIdentity_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IUserIdentity_Release(This) (This)->lpVtbl->Release(This)
/*** IUserIdentity methods ***/
#define IUserIdentity_GetCookie(This,puidCookie) (This)->lpVtbl->GetCookie(This,puidCookie)
#define IUserIdentity_GetName(This,pszName,ulBuffSize) (This)->lpVtbl->GetName(This,pszName,ulBuffSize)
#define IUserIdentity_OpenIdentityRegKey(This,dwDesiredAccess,phKey) (This)->lpVtbl->OpenIdentityRegKey(This,dwDesiredAccess,phKey)
#define IUserIdentity_GetIdentityFolder(This,dwFlags,pszPath,ulBuffSize) (This)->lpVtbl->GetIdentityFolder(This,dwFlags,pszPath,ulBuffSize)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IUserIdentity_QueryInterface(IUserIdentity* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IUserIdentity_AddRef(IUserIdentity* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IUserIdentity_Release(IUserIdentity* This) {
    return This->lpVtbl->Release(This);
}
/*** IUserIdentity methods ***/
static FORCEINLINE HRESULT IUserIdentity_GetCookie(IUserIdentity* This,GUID *puidCookie) {
    return This->lpVtbl->GetCookie(This,puidCookie);
}
static FORCEINLINE HRESULT IUserIdentity_GetName(IUserIdentity* This,WCHAR *pszName,ULONG ulBuffSize) {
    return This->lpVtbl->GetName(This,pszName,ulBuffSize);
}
static FORCEINLINE HRESULT IUserIdentity_OpenIdentityRegKey(IUserIdentity* This,DWORD dwDesiredAccess,HKEY *phKey) {
    return This->lpVtbl->OpenIdentityRegKey(This,dwDesiredAccess,phKey);
}
static FORCEINLINE HRESULT IUserIdentity_GetIdentityFolder(IUserIdentity* This,DWORD dwFlags,WCHAR *pszPath,ULONG ulBuffSize) {
    return This->lpVtbl->GetIdentityFolder(This,dwFlags,pszPath,ulBuffSize);
}
#endif
#endif

#endif


#endif  /* __IUserIdentity_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IEnumUserIdentity interface
 */
#ifndef __IEnumUserIdentity_INTERFACE_DEFINED__
#define __IEnumUserIdentity_INTERFACE_DEFINED__

DEFINE_GUID(IID_IEnumUserIdentity, 0xa9ae6c8f, 0x1d1b, 0x11d2, 0xb2,0x1a, 0x00,0xc0,0x4f,0xa3,0x57,0xfa);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("a9ae6c8f-1d1b-11d2-b21a-00c04fa357fa")
IEnumUserIdentity : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Next(
        ULONG celt,
        IUnknown **rgelt,
        ULONG *pceltFetched) = 0;

    virtual HRESULT STDMETHODCALLTYPE Skip(
        ULONG celt) = 0;

    virtual HRESULT STDMETHODCALLTYPE Reset(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        IEnumUserIdentity **ppenum) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetCount(
        ULONG *pnCount) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IEnumUserIdentity, 0xa9ae6c8f, 0x1d1b, 0x11d2, 0xb2,0x1a, 0x00,0xc0,0x4f,0xa3,0x57,0xfa)
#endif
#else
typedef struct IEnumUserIdentityVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IEnumUserIdentity *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IEnumUserIdentity *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IEnumUserIdentity *This);

    /*** IEnumUserIdentity methods ***/
    HRESULT (STDMETHODCALLTYPE *Next)(
        IEnumUserIdentity *This,
        ULONG celt,
        IUnknown **rgelt,
        ULONG *pceltFetched);

    HRESULT (STDMETHODCALLTYPE *Skip)(
        IEnumUserIdentity *This,
        ULONG celt);

    HRESULT (STDMETHODCALLTYPE *Reset)(
        IEnumUserIdentity *This);

    HRESULT (STDMETHODCALLTYPE *Clone)(
        IEnumUserIdentity *This,
        IEnumUserIdentity **ppenum);

    HRESULT (STDMETHODCALLTYPE *GetCount)(
        IEnumUserIdentity *This,
        ULONG *pnCount);

    END_INTERFACE
} IEnumUserIdentityVtbl;

interface IEnumUserIdentity {
    CONST_VTBL IEnumUserIdentityVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IEnumUserIdentity_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumUserIdentity_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumUserIdentity_Release(This) (This)->lpVtbl->Release(This)
/*** IEnumUserIdentity methods ***/
#define IEnumUserIdentity_Next(This,celt,rgelt,pceltFetched) (This)->lpVtbl->Next(This,celt,rgelt,pceltFetched)
#define IEnumUserIdentity_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#define IEnumUserIdentity_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumUserIdentity_Clone(This,ppenum) (This)->lpVtbl->Clone(This,ppenum)
#define IEnumUserIdentity_GetCount(This,pnCount) (This)->lpVtbl->GetCount(This,pnCount)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IEnumUserIdentity_QueryInterface(IEnumUserIdentity* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IEnumUserIdentity_AddRef(IEnumUserIdentity* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IEnumUserIdentity_Release(IEnumUserIdentity* This) {
    return This->lpVtbl->Release(This);
}
/*** IEnumUserIdentity methods ***/
static FORCEINLINE HRESULT IEnumUserIdentity_Next(IEnumUserIdentity* This,ULONG celt,IUnknown **rgelt,ULONG *pceltFetched) {
    return This->lpVtbl->Next(This,celt,rgelt,pceltFetched);
}
static FORCEINLINE HRESULT IEnumUserIdentity_Skip(IEnumUserIdentity* This,ULONG celt) {
    return This->lpVtbl->Skip(This,celt);
}
static FORCEINLINE HRESULT IEnumUserIdentity_Reset(IEnumUserIdentity* This) {
    return This->lpVtbl->Reset(This);
}
static FORCEINLINE HRESULT IEnumUserIdentity_Clone(IEnumUserIdentity* This,IEnumUserIdentity **ppenum) {
    return This->lpVtbl->Clone(This,ppenum);
}
static FORCEINLINE HRESULT IEnumUserIdentity_GetCount(IEnumUserIdentity* This,ULONG *pnCount) {
    return This->lpVtbl->GetCount(This,pnCount);
}
#endif
#endif

#endif


#endif  /* __IEnumUserIdentity_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IUserIdentityManager interface
 */
#ifndef __IUserIdentityManager_INTERFACE_DEFINED__
#define __IUserIdentityManager_INTERFACE_DEFINED__

#define UIMI_CREATE_NEW_IDENTITY 0x0001
#define UIL_FORCE_UI 0x80000001
DEFINE_GUID(IID_IUserIdentityManager, 0xa9ae6c90, 0x1d1b, 0x11d2, 0xb2,0x1a, 0x00,0xc0,0x4f,0xa3,0x57,0xfa);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("a9ae6c90-1d1b-11d2-b21a-00c04fa357fa")
IUserIdentityManager : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE EnumIdentities(
        IEnumUserIdentity **ppEnumUser) = 0;

    virtual HRESULT STDMETHODCALLTYPE ManageIdentities(
        HWND hwndParent,
        DWORD dwFlags) = 0;

    virtual HRESULT STDMETHODCALLTYPE Logon(
        HWND hwndParent,
        DWORD dwFlags,
        IUserIdentity **ppIdentity) = 0;

    virtual HRESULT STDMETHODCALLTYPE Logoff(
        HWND hwndParent) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetIdentityByCookie(
        GUID *uidCookie,
        IUserIdentity **ppIdentity) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IUserIdentityManager, 0xa9ae6c90, 0x1d1b, 0x11d2, 0xb2,0x1a, 0x00,0xc0,0x4f,0xa3,0x57,0xfa)
#endif
#else
typedef struct IUserIdentityManagerVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IUserIdentityManager *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IUserIdentityManager *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IUserIdentityManager *This);

    /*** IUserIdentityManager methods ***/
    HRESULT (STDMETHODCALLTYPE *EnumIdentities)(
        IUserIdentityManager *This,
        IEnumUserIdentity **ppEnumUser);

    HRESULT (STDMETHODCALLTYPE *ManageIdentities)(
        IUserIdentityManager *This,
        HWND hwndParent,
        DWORD dwFlags);

    HRESULT (STDMETHODCALLTYPE *Logon)(
        IUserIdentityManager *This,
        HWND hwndParent,
        DWORD dwFlags,
        IUserIdentity **ppIdentity);

    HRESULT (STDMETHODCALLTYPE *Logoff)(
        IUserIdentityManager *This,
        HWND hwndParent);

    HRESULT (STDMETHODCALLTYPE *GetIdentityByCookie)(
        IUserIdentityManager *This,
        GUID *uidCookie,
        IUserIdentity **ppIdentity);

    END_INTERFACE
} IUserIdentityManagerVtbl;

interface IUserIdentityManager {
    CONST_VTBL IUserIdentityManagerVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IUserIdentityManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IUserIdentityManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IUserIdentityManager_Release(This) (This)->lpVtbl->Release(This)
/*** IUserIdentityManager methods ***/
#define IUserIdentityManager_EnumIdentities(This,ppEnumUser) (This)->lpVtbl->EnumIdentities(This,ppEnumUser)
#define IUserIdentityManager_ManageIdentities(This,hwndParent,dwFlags) (This)->lpVtbl->ManageIdentities(This,hwndParent,dwFlags)
#define IUserIdentityManager_Logon(This,hwndParent,dwFlags,ppIdentity) (This)->lpVtbl->Logon(This,hwndParent,dwFlags,ppIdentity)
#define IUserIdentityManager_Logoff(This,hwndParent) (This)->lpVtbl->Logoff(This,hwndParent)
#define IUserIdentityManager_GetIdentityByCookie(This,uidCookie,ppIdentity) (This)->lpVtbl->GetIdentityByCookie(This,uidCookie,ppIdentity)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT IUserIdentityManager_QueryInterface(IUserIdentityManager* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG IUserIdentityManager_AddRef(IUserIdentityManager* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG IUserIdentityManager_Release(IUserIdentityManager* This) {
    return This->lpVtbl->Release(This);
}
/*** IUserIdentityManager methods ***/
static FORCEINLINE HRESULT IUserIdentityManager_EnumIdentities(IUserIdentityManager* This,IEnumUserIdentity **ppEnumUser) {
    return This->lpVtbl->EnumIdentities(This,ppEnumUser);
}
static FORCEINLINE HRESULT IUserIdentityManager_ManageIdentities(IUserIdentityManager* This,HWND hwndParent,DWORD dwFlags) {
    return This->lpVtbl->ManageIdentities(This,hwndParent,dwFlags);
}
static FORCEINLINE HRESULT IUserIdentityManager_Logon(IUserIdentityManager* This,HWND hwndParent,DWORD dwFlags,IUserIdentity **ppIdentity) {
    return This->lpVtbl->Logon(This,hwndParent,dwFlags,ppIdentity);
}
static FORCEINLINE HRESULT IUserIdentityManager_Logoff(IUserIdentityManager* This,HWND hwndParent) {
    return This->lpVtbl->Logoff(This,hwndParent);
}
static FORCEINLINE HRESULT IUserIdentityManager_GetIdentityByCookie(IUserIdentityManager* This,GUID *uidCookie,IUserIdentity **ppIdentity) {
    return This->lpVtbl->GetIdentityByCookie(This,uidCookie,ppIdentity);
}
#endif
#endif

#endif


#endif  /* __IUserIdentityManager_INTERFACE_DEFINED__ */

DEFINE_GUID(CLSID_UserIdentityManager, 0xa9ae6c91,0x1d1b,0x11d2,0xb2,0x1a,0x00,0xc0,0x4f,0xa3,0x57,0xfa);
/* Begin additional prototypes for all interfaces */

ULONG           __RPC_USER HWND_UserSize     (ULONG *, ULONG, HWND *);
unsigned char * __RPC_USER HWND_UserMarshal  (ULONG *, unsigned char *, HWND *);
unsigned char * __RPC_USER HWND_UserUnmarshal(ULONG *, unsigned char *, HWND *);
void            __RPC_USER HWND_UserFree     (ULONG *, HWND *);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __msident_h__ */
