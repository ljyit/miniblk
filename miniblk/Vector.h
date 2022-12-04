#ifndef __VECTOR_H_
#define __VECTOR_H_

#include "resource.h"       // main symbols

#include <vector>
#include <atlcom.h>

typedef std::vector<VARIANT> CollType;

typedef CComEnumOnSTL<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT>, CollType > EnumType;
typedef ICollectionOnSTLImpl<IVector, CollType, VARIANT, _Copy<VARIANT>, EnumType > CollectionType;

/////////////////////////////////////////////////////////////////////////////
// CVector
class ATL_NO_VTABLE CVector : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVector, &CLSID_Vector>,
	//public IDispatchImpl<IVector, &IID_IVector, &LIBID_DYNAMICARRAYLib>,
	public IDispatchImpl<CollectionType, &IID_IVector, &LIBID_DYNAMICARRAYLib>
	//public CollectionType
{
public:
	CVector()
	{
		m_coll.push_back( CComVariant(100) );
		m_coll.push_back( CComVariant(200) );
		m_coll.push_back( CComVariant(300) );
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_VECTOR)

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(CVector)
		COM_INTERFACE_ENTRY(IVector)
		COM_INTERFACE_ENTRY(IDispatch)
		// COM_INTERFACE_ENTRY(ICollection)
	END_COM_MAP()

	// IVector
public:

};