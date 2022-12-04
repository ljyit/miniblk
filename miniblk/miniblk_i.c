

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_miniblkLib,0x775B09F0,0x2D0C,0x4E6F,0x80,0xD0,0x02,0x45,0x6A,0xAE,0x45,0x68);


MIDL_DEFINE_GUID(IID, DIID_IJSValue,0xB4AE6DFE,0x0137,0x4CEA,0x9A,0xAF,0xD9,0x25,0xDC,0x41,0xCD,0x73);


MIDL_DEFINE_GUID(CLSID, CLSID_JSValue,0x04ED7311,0xAE2A,0x4E80,0x8D,0x62,0xEA,0x40,0x87,0x24,0xD0,0x70);


MIDL_DEFINE_GUID(IID, DIID_IHeaders,0x4AE5F4F4,0xD042,0x4D45,0xB5,0x30,0xAC,0x83,0xA0,0xFF,0x28,0x7A);


MIDL_DEFINE_GUID(CLSID, CLSID_Headers,0xC8EAF9DD,0x964D,0x491E,0xB6,0x5A,0x4C,0xAA,0x5B,0xC7,0xCD,0x07);


MIDL_DEFINE_GUID(IID, DIID__Dminiblk,0xC063C610,0x02D3,0x4893,0xBF,0x59,0x7A,0x82,0x06,0xED,0x66,0x8E);


MIDL_DEFINE_GUID(IID, DIID__DminiblkEvents,0x13340B10,0x871F,0x4023,0x98,0x43,0xB7,0x55,0x83,0xFA,0x16,0x0B);


MIDL_DEFINE_GUID(CLSID, CLSID_miniblk,0x24354416,0x5082,0x41E6,0xAE,0x04,0xD0,0x1A,0x23,0xBB,0x56,0x7B);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



