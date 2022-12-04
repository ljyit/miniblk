

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Sun Dec 04 15:35:30 2022
 */
/* Compiler settings for .\miniblk.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __miniblkidl_h__
#define __miniblkidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IJSValue_FWD_DEFINED__
#define __IJSValue_FWD_DEFINED__
typedef interface IJSValue IJSValue;
#endif 	/* __IJSValue_FWD_DEFINED__ */


#ifndef __JSValue_FWD_DEFINED__
#define __JSValue_FWD_DEFINED__

#ifdef __cplusplus
typedef class JSValue JSValue;
#else
typedef struct JSValue JSValue;
#endif /* __cplusplus */

#endif 	/* __JSValue_FWD_DEFINED__ */


#ifndef __IHeaders_FWD_DEFINED__
#define __IHeaders_FWD_DEFINED__
typedef interface IHeaders IHeaders;
#endif 	/* __IHeaders_FWD_DEFINED__ */


#ifndef __Headers_FWD_DEFINED__
#define __Headers_FWD_DEFINED__

#ifdef __cplusplus
typedef class Headers Headers;
#else
typedef struct Headers Headers;
#endif /* __cplusplus */

#endif 	/* __Headers_FWD_DEFINED__ */


#ifndef ___Dminiblk_FWD_DEFINED__
#define ___Dminiblk_FWD_DEFINED__
typedef interface _Dminiblk _Dminiblk;
#endif 	/* ___Dminiblk_FWD_DEFINED__ */


#ifndef ___DminiblkEvents_FWD_DEFINED__
#define ___DminiblkEvents_FWD_DEFINED__
typedef interface _DminiblkEvents _DminiblkEvents;
#endif 	/* ___DminiblkEvents_FWD_DEFINED__ */


#ifndef __miniblk_FWD_DEFINED__
#define __miniblk_FWD_DEFINED__

#ifdef __cplusplus
typedef class miniblk miniblk;
#else
typedef struct miniblk miniblk;
#endif /* __cplusplus */

#endif 	/* __miniblk_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __miniblkLib_LIBRARY_DEFINED__
#define __miniblkLib_LIBRARY_DEFINED__

/* library miniblkLib */
/* [control][helpstring][helpfile][version][uuid] */ 

typedef 
enum tagFontAlign
    {	Left	= 0,
	Center	= 1,
	Right	= 2
    } 	FontAlign;


EXTERN_C const IID LIBID_miniblkLib;

#ifndef __IJSValue_DISPINTERFACE_DEFINED__
#define __IJSValue_DISPINTERFACE_DEFINED__

/* dispinterface IJSValue */
/* [uuid] */ 


EXTERN_C const IID DIID_IJSValue;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B4AE6DFE-0137-4CEA-9AAF-D925DC41CD73")
    IJSValue : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IJSValueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IJSValue * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IJSValue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IJSValue * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IJSValue * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IJSValue * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IJSValue * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IJSValue * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IJSValueVtbl;

    interface IJSValue
    {
        CONST_VTBL struct IJSValueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IJSValue_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IJSValue_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IJSValue_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IJSValue_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IJSValue_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IJSValue_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IJSValue_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IJSValue_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_JSValue;

#ifdef __cplusplus

class DECLSPEC_UUID("04ED7311-AE2A-4E80-8D62-EA408724D070")
JSValue;
#endif

#ifndef __IHeaders_DISPINTERFACE_DEFINED__
#define __IHeaders_DISPINTERFACE_DEFINED__

/* dispinterface IHeaders */
/* [uuid] */ 


EXTERN_C const IID DIID_IHeaders;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4AE5F4F4-D042-4D45-B530-AC83A0FF287A")
    IHeaders : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IHeadersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHeaders * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHeaders * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHeaders * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHeaders * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHeaders * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHeaders * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHeaders * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IHeadersVtbl;

    interface IHeaders
    {
        CONST_VTBL struct IHeadersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHeaders_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHeaders_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHeaders_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHeaders_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHeaders_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHeaders_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHeaders_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IHeaders_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Headers;

#ifdef __cplusplus

class DECLSPEC_UUID("C8EAF9DD-964D-491E-B65A-4CAA5BC7CD07")
Headers;
#endif

#ifndef ___Dminiblk_DISPINTERFACE_DEFINED__
#define ___Dminiblk_DISPINTERFACE_DEFINED__

/* dispinterface _Dminiblk */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__Dminiblk;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C063C610-02D3-4893-BF59-7A8206ED668E")
    _Dminiblk : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DminiblkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _Dminiblk * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _Dminiblk * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _Dminiblk * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _Dminiblk * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _Dminiblk * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _Dminiblk * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _Dminiblk * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DminiblkVtbl;

    interface _Dminiblk
    {
        CONST_VTBL struct _DminiblkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _Dminiblk_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _Dminiblk_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _Dminiblk_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _Dminiblk_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _Dminiblk_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _Dminiblk_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _Dminiblk_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___Dminiblk_DISPINTERFACE_DEFINED__ */


#ifndef ___DminiblkEvents_DISPINTERFACE_DEFINED__
#define ___DminiblkEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DminiblkEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DminiblkEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("13340B10-871F-4023-9843-B75583FA160B")
    _DminiblkEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DminiblkEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DminiblkEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DminiblkEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DminiblkEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DminiblkEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DminiblkEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DminiblkEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DminiblkEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DminiblkEventsVtbl;

    interface _DminiblkEvents
    {
        CONST_VTBL struct _DminiblkEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DminiblkEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DminiblkEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DminiblkEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DminiblkEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DminiblkEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DminiblkEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DminiblkEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DminiblkEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_miniblk;

#ifdef __cplusplus

class DECLSPEC_UUID("24354416-5082-41E6-AE04-D01A23BB567B")
miniblk;
#endif
#endif /* __miniblkLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


