/*** Autogenerated by WIDL 3.0 from d2d1_1.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __d2d1_1_h__
#define __d2d1_1_h__

/* Forward declarations */

#ifndef __ID2D1Factory1_FWD_DEFINED__
#define __ID2D1Factory1_FWD_DEFINED__
typedef interface ID2D1Factory1 ID2D1Factory1;
#ifdef __cplusplus
interface ID2D1Factory1;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <d2d1.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ID2D1Device_FWD_DEFINED__
#define __ID2D1Device_FWD_DEFINED__
typedef interface ID2D1Device ID2D1Device;
#ifdef __cplusplus
interface ID2D1Device;
#endif /* __cplusplus */
#endif

#ifndef __ID2D1StrokeStyle1_FWD_DEFINED__
#define __ID2D1StrokeStyle1_FWD_DEFINED__
typedef interface ID2D1StrokeStyle1 ID2D1StrokeStyle1;
#ifdef __cplusplus
interface ID2D1StrokeStyle1;
#endif /* __cplusplus */
#endif

#ifndef __ID2D1PathGeometry1_FWD_DEFINED__
#define __ID2D1PathGeometry1_FWD_DEFINED__
typedef interface ID2D1PathGeometry1 ID2D1PathGeometry1;
#ifdef __cplusplus
interface ID2D1PathGeometry1;
#endif /* __cplusplus */
#endif

#ifndef __ID2D1DrawingStateBlock1_FWD_DEFINED__
#define __ID2D1DrawingStateBlock1_FWD_DEFINED__
typedef interface ID2D1DrawingStateBlock1 ID2D1DrawingStateBlock1;
#ifdef __cplusplus
interface ID2D1DrawingStateBlock1;
#endif /* __cplusplus */
#endif

#ifndef __ID2D1GdiMetafile_FWD_DEFINED__
#define __ID2D1GdiMetafile_FWD_DEFINED__
typedef interface ID2D1GdiMetafile ID2D1GdiMetafile;
#ifdef __cplusplus
interface ID2D1GdiMetafile;
#endif /* __cplusplus */
#endif

#ifndef __ID2D1Properties_FWD_DEFINED__
#define __ID2D1Properties_FWD_DEFINED__
typedef interface ID2D1Properties ID2D1Properties;
#ifdef __cplusplus
interface ID2D1Properties;
#endif /* __cplusplus */
#endif

typedef enum D2D1_STROKE_TRANSFORM_TYPE {
    D2D1_STROKE_TRANSFORM_TYPE_NORMAL = 0x0,
    D2D1_STROKE_TRANSFORM_TYPE_FIXED = 0x1,
    D2D1_STROKE_TRANSFORM_TYPE_HAIRLINE = 0x2,
    D2D1_STROKE_TRANSFORM_TYPE_FORCE_DWORD = 0xffffffff
} D2D1_STROKE_TRANSFORM_TYPE;
typedef enum D2D1_PRIMITIVE_BLEND {
    D2D1_PRIMITIVE_BLEND_SOURCE_OVER = 0x0,
    D2D1_PRIMITIVE_BLEND_COPY = 0x1,
    D2D1_PRIMITIVE_BLEND_MIN = 0x2,
    D2D1_PRIMITIVE_BLEND_ADD = 0x3,
    D2D1_PRIMITIVE_BLEND_MAX = 0x4,
    D2D1_PRIMITIVE_BLEND_FORCE_DWORD = 0xffffffff
} D2D1_PRIMITIVE_BLEND;
typedef enum D2D1_UNIT_MODE {
    D2D1_UNIT_MODE_DIPS = 0x0,
    D2D1_UNIT_MODE_PIXELS = 0x1,
    D2D1_UNIT_MODE_FORCE_DWORD = 0xffffffff
} D2D1_UNIT_MODE;
typedef struct D2D1_PROPERTY_BINDING D2D1_PROPERTY_BINDING;
typedef struct D2D1_STROKE_STYLE_PROPERTIES1 {
    D2D1_CAP_STYLE startCap;
    D2D1_CAP_STYLE endCap;
    D2D1_CAP_STYLE dashCap;
    D2D1_LINE_JOIN lineJoin;
    float miterLimit;
    D2D1_DASH_STYLE dashStyle;
    float dashOffset;
    D2D1_STROKE_TRANSFORM_TYPE transformType;
} D2D1_STROKE_STYLE_PROPERTIES1;
typedef struct D2D1_DRAWING_STATE_DESCRIPTION1 {
    D2D1_ANTIALIAS_MODE antialiasMode;
    D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode;
    D2D1_TAG tag1;
    D2D1_TAG tag2;
    D2D1_MATRIX_3X2_F transform;
    D2D1_PRIMITIVE_BLEND primitiveBlend;
    D2D1_UNIT_MODE unitMode;
} D2D1_DRAWING_STATE_DESCRIPTION1;
typedef HRESULT (__stdcall *PD2D1_EFFECT_FACTORY)(IUnknown **effect);
/*****************************************************************************
 * ID2D1Factory1 interface
 */
#ifndef __ID2D1Factory1_INTERFACE_DEFINED__
#define __ID2D1Factory1_INTERFACE_DEFINED__

DEFINE_GUID(IID_ID2D1Factory1, 0xbb12d362, 0xdaee, 0x4b9a, 0xaa,0x1d, 0x14,0xba,0x40,0x1c,0xfa,0x1f);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("bb12d362-daee-4b9a-aa1d-14ba401cfa1f")
ID2D1Factory1 : public ID2D1Factory
{
    virtual HRESULT STDMETHODCALLTYPE CreateDevice(
        IDXGIDevice *dxgi_device,
        ID2D1Device **device) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateStrokeStyle(
        const D2D1_STROKE_STYLE_PROPERTIES1 *desc,
        const float *dashes,
        UINT32 dash_count,
        ID2D1StrokeStyle1 **stroke_style) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreatePathGeometry(
        ID2D1PathGeometry1 **geometry) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateDrawingStateBlock(
        const D2D1_DRAWING_STATE_DESCRIPTION1 *desc,
        IDWriteRenderingParams *text_rendering_params,
        ID2D1DrawingStateBlock1 **state_block) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateGdiMetafile(
        IStream *stream,
        ID2D1GdiMetafile **metafile) = 0;

    virtual HRESULT STDMETHODCALLTYPE RegisterEffectFromStream(
        REFCLSID effect_id,
        IStream *property_xml,
        const D2D1_PROPERTY_BINDING *bindings,
        UINT32 binding_count,
        HRESULT (__stdcall * effect_factory)(IUnknown **effect)) = 0;

    virtual HRESULT STDMETHODCALLTYPE RegisterEffectFromString(
        REFCLSID effect_id,
        const WCHAR *property_xml,
        const D2D1_PROPERTY_BINDING *bindings,
        UINT32 binding_count,
        HRESULT (__stdcall * effect_factory)(IUnknown **effect)) = 0;

    virtual HRESULT STDMETHODCALLTYPE UnregisterEffect(
        REFCLSID effect_id) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetRegisteredEffects(
        CLSID *effects,
        UINT32 effect_count,
        UINT32 *returned,
        UINT32 *registered) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetEffectProperties(
        REFCLSID effect_id,
        ID2D1Properties **props) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ID2D1Factory1, 0xbb12d362, 0xdaee, 0x4b9a, 0xaa,0x1d, 0x14,0xba,0x40,0x1c,0xfa,0x1f)
#endif
#else
typedef struct ID2D1Factory1Vtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ID2D1Factory1 *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ID2D1Factory1 *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ID2D1Factory1 *This);

    /*** ID2D1Factory methods ***/
    HRESULT (STDMETHODCALLTYPE *ReloadSystemMetrics)(
        ID2D1Factory1 *This);

    void (STDMETHODCALLTYPE *GetDesktopDpi)(
        ID2D1Factory1 *This,
        float *dpi_x,
        float *dpi_y);

    HRESULT (STDMETHODCALLTYPE *CreateRectangleGeometry)(
        ID2D1Factory1 *This,
        const D2D1_RECT_F *rect,
        ID2D1RectangleGeometry **geometry);

    HRESULT (STDMETHODCALLTYPE *CreateRoundedRectangleGeometry)(
        ID2D1Factory1 *This,
        const D2D1_ROUNDED_RECT *rect,
        ID2D1RoundedRectangleGeometry **geometry);

    HRESULT (STDMETHODCALLTYPE *CreateEllipseGeometry)(
        ID2D1Factory1 *This,
        const D2D1_ELLIPSE *ellipse,
        ID2D1EllipseGeometry **geometry);

    HRESULT (STDMETHODCALLTYPE *CreateGeometryGroup)(
        ID2D1Factory1 *This,
        D2D1_FILL_MODE fill_mode,
        ID2D1Geometry **geometries,
        UINT32 geometry_count,
        ID2D1GeometryGroup **group);

    HRESULT (STDMETHODCALLTYPE *CreateTransformedGeometry)(
        ID2D1Factory1 *This,
        ID2D1Geometry *src_geometry,
        const D2D1_MATRIX_3X2_F *transform,
        ID2D1TransformedGeometry **transformed_geometry);

    HRESULT (STDMETHODCALLTYPE *CreatePathGeometry)(
        ID2D1Factory1 *This,
        ID2D1PathGeometry **geometry);

    HRESULT (STDMETHODCALLTYPE *CreateStrokeStyle)(
        ID2D1Factory1 *This,
        const D2D1_STROKE_STYLE_PROPERTIES *desc,
        const float *dashes,
        UINT32 dash_count,
        ID2D1StrokeStyle **stroke_style);

    HRESULT (STDMETHODCALLTYPE *CreateDrawingStateBlock)(
        ID2D1Factory1 *This,
        const D2D1_DRAWING_STATE_DESCRIPTION *desc,
        IDWriteRenderingParams *text_rendering_params,
        ID2D1DrawingStateBlock **state_block);

    HRESULT (STDMETHODCALLTYPE *CreateWicBitmapRenderTarget)(
        ID2D1Factory1 *This,
        IWICBitmap *target,
        const D2D1_RENDER_TARGET_PROPERTIES *desc,
        ID2D1RenderTarget **render_target);

    HRESULT (STDMETHODCALLTYPE *CreateHwndRenderTarget)(
        ID2D1Factory1 *This,
        const D2D1_RENDER_TARGET_PROPERTIES *desc,
        const D2D1_HWND_RENDER_TARGET_PROPERTIES *hwnd_rt_desc,
        ID2D1HwndRenderTarget **render_target);

    HRESULT (STDMETHODCALLTYPE *CreateDxgiSurfaceRenderTarget)(
        ID2D1Factory1 *This,
        IDXGISurface *surface,
        const D2D1_RENDER_TARGET_PROPERTIES *desc,
        ID2D1RenderTarget **render_target);

    HRESULT (STDMETHODCALLTYPE *CreateDCRenderTarget)(
        ID2D1Factory1 *This,
        const D2D1_RENDER_TARGET_PROPERTIES *desc,
        ID2D1DCRenderTarget **render_target);

    /*** ID2D1Factory1 methods ***/
    HRESULT (STDMETHODCALLTYPE *CreateDevice)(
        ID2D1Factory1 *This,
        IDXGIDevice *dxgi_device,
        ID2D1Device **device);

    HRESULT (STDMETHODCALLTYPE *ID2D1Factory1_CreateStrokeStyle)(
        ID2D1Factory1 *This,
        const D2D1_STROKE_STYLE_PROPERTIES1 *desc,
        const float *dashes,
        UINT32 dash_count,
        ID2D1StrokeStyle1 **stroke_style);

    HRESULT (STDMETHODCALLTYPE *ID2D1Factory1_CreatePathGeometry)(
        ID2D1Factory1 *This,
        ID2D1PathGeometry1 **geometry);

    HRESULT (STDMETHODCALLTYPE *ID2D1Factory1_CreateDrawingStateBlock)(
        ID2D1Factory1 *This,
        const D2D1_DRAWING_STATE_DESCRIPTION1 *desc,
        IDWriteRenderingParams *text_rendering_params,
        ID2D1DrawingStateBlock1 **state_block);

    HRESULT (STDMETHODCALLTYPE *CreateGdiMetafile)(
        ID2D1Factory1 *This,
        IStream *stream,
        ID2D1GdiMetafile **metafile);

    HRESULT (STDMETHODCALLTYPE *RegisterEffectFromStream)(
        ID2D1Factory1 *This,
        REFCLSID effect_id,
        IStream *property_xml,
        const D2D1_PROPERTY_BINDING *bindings,
        UINT32 binding_count,
        HRESULT (__stdcall * effect_factory)(IUnknown **effect));

    HRESULT (STDMETHODCALLTYPE *RegisterEffectFromString)(
        ID2D1Factory1 *This,
        REFCLSID effect_id,
        const WCHAR *property_xml,
        const D2D1_PROPERTY_BINDING *bindings,
        UINT32 binding_count,
        HRESULT (__stdcall * effect_factory)(IUnknown **effect));

    HRESULT (STDMETHODCALLTYPE *UnregisterEffect)(
        ID2D1Factory1 *This,
        REFCLSID effect_id);

    HRESULT (STDMETHODCALLTYPE *GetRegisteredEffects)(
        ID2D1Factory1 *This,
        CLSID *effects,
        UINT32 effect_count,
        UINT32 *returned,
        UINT32 *registered);

    HRESULT (STDMETHODCALLTYPE *GetEffectProperties)(
        ID2D1Factory1 *This,
        REFCLSID effect_id,
        ID2D1Properties **props);

    END_INTERFACE
} ID2D1Factory1Vtbl;

interface ID2D1Factory1 {
    CONST_VTBL ID2D1Factory1Vtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ID2D1Factory1_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ID2D1Factory1_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ID2D1Factory1_Release(This) (This)->lpVtbl->Release(This)
/*** ID2D1Factory methods ***/
#define ID2D1Factory1_ReloadSystemMetrics(This) (This)->lpVtbl->ReloadSystemMetrics(This)
#define ID2D1Factory1_GetDesktopDpi(This,dpi_x,dpi_y) (This)->lpVtbl->GetDesktopDpi(This,dpi_x,dpi_y)
#define ID2D1Factory1_CreateRectangleGeometry(This,rect,geometry) (This)->lpVtbl->CreateRectangleGeometry(This,rect,geometry)
#define ID2D1Factory1_CreateRoundedRectangleGeometry(This,rect,geometry) (This)->lpVtbl->CreateRoundedRectangleGeometry(This,rect,geometry)
#define ID2D1Factory1_CreateEllipseGeometry(This,ellipse,geometry) (This)->lpVtbl->CreateEllipseGeometry(This,ellipse,geometry)
#define ID2D1Factory1_CreateGeometryGroup(This,fill_mode,geometries,geometry_count,group) (This)->lpVtbl->CreateGeometryGroup(This,fill_mode,geometries,geometry_count,group)
#define ID2D1Factory1_CreateTransformedGeometry(This,src_geometry,transform,transformed_geometry) (This)->lpVtbl->CreateTransformedGeometry(This,src_geometry,transform,transformed_geometry)
#define ID2D1Factory1_CreateWicBitmapRenderTarget(This,target,desc,render_target) (This)->lpVtbl->CreateWicBitmapRenderTarget(This,target,desc,render_target)
#define ID2D1Factory1_CreateHwndRenderTarget(This,desc,hwnd_rt_desc,render_target) (This)->lpVtbl->CreateHwndRenderTarget(This,desc,hwnd_rt_desc,render_target)
#define ID2D1Factory1_CreateDxgiSurfaceRenderTarget(This,surface,desc,render_target) (This)->lpVtbl->CreateDxgiSurfaceRenderTarget(This,surface,desc,render_target)
#define ID2D1Factory1_CreateDCRenderTarget(This,desc,render_target) (This)->lpVtbl->CreateDCRenderTarget(This,desc,render_target)
/*** ID2D1Factory1 methods ***/
#define ID2D1Factory1_CreateDevice(This,dxgi_device,device) (This)->lpVtbl->CreateDevice(This,dxgi_device,device)
#define ID2D1Factory1_CreateStrokeStyle(This,desc,dashes,dash_count,stroke_style) (This)->lpVtbl->ID2D1Factory1_CreateStrokeStyle(This,desc,dashes,dash_count,stroke_style)
#define ID2D1Factory1_CreatePathGeometry(This,geometry) (This)->lpVtbl->ID2D1Factory1_CreatePathGeometry(This,geometry)
#define ID2D1Factory1_CreateDrawingStateBlock(This,desc,text_rendering_params,state_block) (This)->lpVtbl->ID2D1Factory1_CreateDrawingStateBlock(This,desc,text_rendering_params,state_block)
#define ID2D1Factory1_CreateGdiMetafile(This,stream,metafile) (This)->lpVtbl->CreateGdiMetafile(This,stream,metafile)
#define ID2D1Factory1_RegisterEffectFromStream(This,effect_id,property_xml,bindings,binding_count,effect_factory) (This)->lpVtbl->RegisterEffectFromStream(This,effect_id,property_xml,bindings,binding_count,effect_factory)
#define ID2D1Factory1_RegisterEffectFromString(This,effect_id,property_xml,bindings,binding_count,effect_factory) (This)->lpVtbl->RegisterEffectFromString(This,effect_id,property_xml,bindings,binding_count,effect_factory)
#define ID2D1Factory1_UnregisterEffect(This,effect_id) (This)->lpVtbl->UnregisterEffect(This,effect_id)
#define ID2D1Factory1_GetRegisteredEffects(This,effects,effect_count,returned,registered) (This)->lpVtbl->GetRegisteredEffects(This,effects,effect_count,returned,registered)
#define ID2D1Factory1_GetEffectProperties(This,effect_id,props) (This)->lpVtbl->GetEffectProperties(This,effect_id,props)
#else
/*** IUnknown methods ***/
static FORCEINLINE HRESULT ID2D1Factory1_QueryInterface(ID2D1Factory1* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static FORCEINLINE ULONG ID2D1Factory1_AddRef(ID2D1Factory1* This) {
    return This->lpVtbl->AddRef(This);
}
static FORCEINLINE ULONG ID2D1Factory1_Release(ID2D1Factory1* This) {
    return This->lpVtbl->Release(This);
}
/*** ID2D1Factory methods ***/
static FORCEINLINE HRESULT ID2D1Factory1_ReloadSystemMetrics(ID2D1Factory1* This) {
    return This->lpVtbl->ReloadSystemMetrics(This);
}
static FORCEINLINE void ID2D1Factory1_GetDesktopDpi(ID2D1Factory1* This,float *dpi_x,float *dpi_y) {
    This->lpVtbl->GetDesktopDpi(This,dpi_x,dpi_y);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateRectangleGeometry(ID2D1Factory1* This,const D2D1_RECT_F *rect,ID2D1RectangleGeometry **geometry) {
    return This->lpVtbl->CreateRectangleGeometry(This,rect,geometry);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateRoundedRectangleGeometry(ID2D1Factory1* This,const D2D1_ROUNDED_RECT *rect,ID2D1RoundedRectangleGeometry **geometry) {
    return This->lpVtbl->CreateRoundedRectangleGeometry(This,rect,geometry);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateEllipseGeometry(ID2D1Factory1* This,const D2D1_ELLIPSE *ellipse,ID2D1EllipseGeometry **geometry) {
    return This->lpVtbl->CreateEllipseGeometry(This,ellipse,geometry);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateGeometryGroup(ID2D1Factory1* This,D2D1_FILL_MODE fill_mode,ID2D1Geometry **geometries,UINT32 geometry_count,ID2D1GeometryGroup **group) {
    return This->lpVtbl->CreateGeometryGroup(This,fill_mode,geometries,geometry_count,group);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateTransformedGeometry(ID2D1Factory1* This,ID2D1Geometry *src_geometry,const D2D1_MATRIX_3X2_F *transform,ID2D1TransformedGeometry **transformed_geometry) {
    return This->lpVtbl->CreateTransformedGeometry(This,src_geometry,transform,transformed_geometry);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateWicBitmapRenderTarget(ID2D1Factory1* This,IWICBitmap *target,const D2D1_RENDER_TARGET_PROPERTIES *desc,ID2D1RenderTarget **render_target) {
    return This->lpVtbl->CreateWicBitmapRenderTarget(This,target,desc,render_target);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateHwndRenderTarget(ID2D1Factory1* This,const D2D1_RENDER_TARGET_PROPERTIES *desc,const D2D1_HWND_RENDER_TARGET_PROPERTIES *hwnd_rt_desc,ID2D1HwndRenderTarget **render_target) {
    return This->lpVtbl->CreateHwndRenderTarget(This,desc,hwnd_rt_desc,render_target);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateDxgiSurfaceRenderTarget(ID2D1Factory1* This,IDXGISurface *surface,const D2D1_RENDER_TARGET_PROPERTIES *desc,ID2D1RenderTarget **render_target) {
    return This->lpVtbl->CreateDxgiSurfaceRenderTarget(This,surface,desc,render_target);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateDCRenderTarget(ID2D1Factory1* This,const D2D1_RENDER_TARGET_PROPERTIES *desc,ID2D1DCRenderTarget **render_target) {
    return This->lpVtbl->CreateDCRenderTarget(This,desc,render_target);
}
/*** ID2D1Factory1 methods ***/
static FORCEINLINE HRESULT ID2D1Factory1_CreateDevice(ID2D1Factory1* This,IDXGIDevice *dxgi_device,ID2D1Device **device) {
    return This->lpVtbl->CreateDevice(This,dxgi_device,device);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateStrokeStyle(ID2D1Factory1* This,const D2D1_STROKE_STYLE_PROPERTIES1 *desc,const float *dashes,UINT32 dash_count,ID2D1StrokeStyle1 **stroke_style) {
    return This->lpVtbl->ID2D1Factory1_CreateStrokeStyle(This,desc,dashes,dash_count,stroke_style);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreatePathGeometry(ID2D1Factory1* This,ID2D1PathGeometry1 **geometry) {
    return This->lpVtbl->ID2D1Factory1_CreatePathGeometry(This,geometry);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateDrawingStateBlock(ID2D1Factory1* This,const D2D1_DRAWING_STATE_DESCRIPTION1 *desc,IDWriteRenderingParams *text_rendering_params,ID2D1DrawingStateBlock1 **state_block) {
    return This->lpVtbl->ID2D1Factory1_CreateDrawingStateBlock(This,desc,text_rendering_params,state_block);
}
static FORCEINLINE HRESULT ID2D1Factory1_CreateGdiMetafile(ID2D1Factory1* This,IStream *stream,ID2D1GdiMetafile **metafile) {
    return This->lpVtbl->CreateGdiMetafile(This,stream,metafile);
}
static FORCEINLINE HRESULT ID2D1Factory1_RegisterEffectFromStream(ID2D1Factory1* This,REFCLSID effect_id,IStream *property_xml,const D2D1_PROPERTY_BINDING *bindings,UINT32 binding_count,HRESULT (__stdcall * effect_factory)(IUnknown **effect)) {
    return This->lpVtbl->RegisterEffectFromStream(This,effect_id,property_xml,bindings,binding_count,effect_factory);
}
static FORCEINLINE HRESULT ID2D1Factory1_RegisterEffectFromString(ID2D1Factory1* This,REFCLSID effect_id,const WCHAR *property_xml,const D2D1_PROPERTY_BINDING *bindings,UINT32 binding_count,HRESULT (__stdcall * effect_factory)(IUnknown **effect)) {
    return This->lpVtbl->RegisterEffectFromString(This,effect_id,property_xml,bindings,binding_count,effect_factory);
}
static FORCEINLINE HRESULT ID2D1Factory1_UnregisterEffect(ID2D1Factory1* This,REFCLSID effect_id) {
    return This->lpVtbl->UnregisterEffect(This,effect_id);
}
static FORCEINLINE HRESULT ID2D1Factory1_GetRegisteredEffects(ID2D1Factory1* This,CLSID *effects,UINT32 effect_count,UINT32 *returned,UINT32 *registered) {
    return This->lpVtbl->GetRegisteredEffects(This,effects,effect_count,returned,registered);
}
static FORCEINLINE HRESULT ID2D1Factory1_GetEffectProperties(ID2D1Factory1* This,REFCLSID effect_id,ID2D1Properties **props) {
    return This->lpVtbl->GetEffectProperties(This,effect_id,props);
}
#endif
#endif

#endif


#endif  /* __ID2D1Factory1_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __d2d1_1_h__ */
