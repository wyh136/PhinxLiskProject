// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'uLkJSON.pas' rev: 31.00 (Windows)

#ifndef UlkjsonHPP
#define UlkjsonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Variants.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ulkjson
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TlkJSONbase;
class DELPHICLASS TlkJSONnumber;
class DELPHICLASS TlkJSONstring;
class DELPHICLASS TlkJSONboolean;
class DELPHICLASS TlkJSONnull;
class DELPHICLASS TlkJSONcustomlist;
class DELPHICLASS TlkJSONlist;
class DELPHICLASS TlkJSONobjectmethod;
struct TlkBalNode;
class DELPHICLASS TlkBalTree;
class DELPHICLASS TlkJSONobject;
class DELPHICLASS TlkJSON;
class DELPHICLASS TlkJSONstreamed;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TlkJSONtypes : unsigned char { jsBase, jsNumber, jsString, jsBoolean, jsNull, jsList, jsObject };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkJSONbase : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	virtual TlkJSONbase* __fastcall GetChild(int idx);
	virtual void __fastcall SetChild(int idx, TlkJSONbase* const AValue);
	virtual int __fastcall GetCount(void);
	virtual TlkJSONbase* __fastcall GetField(const System::Variant &AName);
	
public:
	__property TlkJSONbase* Field[System::Variant AName] = {read=GetField};
	__property int Count = {read=GetCount, nodefault};
	__property TlkJSONbase* Child[int idx] = {read=GetChild, write=SetChild};
	__property System::Variant Value = {read=GetValue, write=SetValue};
	__classmethod virtual TlkJSONtypes __fastcall SelfType();
	__classmethod virtual System::UnicodeString __fastcall SelfTypeName();
public:
	/* TObject.Create */ inline __fastcall TlkJSONbase(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TlkJSONbase(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TlkJSONnumber : public TlkJSONbase
{
	typedef TlkJSONbase inherited;
	
protected:
	System::Extended FValue;
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	
public:
	virtual void __fastcall AfterConstruction(void);
	__classmethod TlkJSONnumber* __fastcall Generate(System::Extended AValue = 0.000000E+00);
	__classmethod virtual TlkJSONtypes __fastcall SelfType();
	__classmethod virtual System::UnicodeString __fastcall SelfTypeName();
public:
	/* TObject.Create */ inline __fastcall TlkJSONnumber(void) : TlkJSONbase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TlkJSONnumber(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkJSONstring : public TlkJSONbase
{
	typedef TlkJSONbase inherited;
	
protected:
	System::WideString FValue;
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	
public:
	virtual void __fastcall AfterConstruction(void);
	__classmethod TlkJSONstring* __fastcall Generate(const System::WideString wsValue = System::WideString());
	__classmethod virtual TlkJSONtypes __fastcall SelfType();
	__classmethod virtual System::UnicodeString __fastcall SelfTypeName();
public:
	/* TObject.Create */ inline __fastcall TlkJSONstring(void) : TlkJSONbase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TlkJSONstring(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkJSONboolean : public TlkJSONbase
{
	typedef TlkJSONbase inherited;
	
protected:
	bool FValue;
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	
public:
	virtual void __fastcall AfterConstruction(void);
	__classmethod TlkJSONboolean* __fastcall Generate(bool AValue = true);
	__classmethod virtual TlkJSONtypes __fastcall SelfType();
	__classmethod virtual System::UnicodeString __fastcall SelfTypeName();
public:
	/* TObject.Create */ inline __fastcall TlkJSONboolean(void) : TlkJSONbase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TlkJSONboolean(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkJSONnull : public TlkJSONbase
{
	typedef TlkJSONbase inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(void);
	TlkJSONnull* __fastcall Generate(void);
	
public:
	__classmethod virtual TlkJSONtypes __fastcall SelfType();
	__classmethod virtual System::UnicodeString __fastcall SelfTypeName();
public:
	/* TObject.Create */ inline __fastcall TlkJSONnull(void) : TlkJSONbase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TlkJSONnull(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TlkJSONFuncEnum)(System::UnicodeString ElName, TlkJSONbase* Elem, void * data, bool &Continue);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkJSONcustomlist : public TlkJSONbase
{
	typedef TlkJSONbase inherited;
	
protected:
	System::Classes::TList* fList;
	virtual int __fastcall GetCount(void);
	virtual TlkJSONbase* __fastcall GetChild(int idx);
	virtual void __fastcall SetChild(int idx, TlkJSONbase* const AValue);
	virtual TlkJSONbase* __fastcall ForEachElement(int idx, System::UnicodeString &nm);
	virtual TlkJSONbase* __fastcall GetField(const System::Variant &AName);
	virtual int __fastcall _Add(TlkJSONbase* obj);
	virtual void __fastcall _Delete(int iIndex);
	virtual int __fastcall _IndexOf(TlkJSONbase* obj);
	
public:
	void __fastcall ForEach(TlkJSONFuncEnum fnCallBack, void * pUserData);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	virtual int __fastcall getInt(int idx);
	virtual System::UnicodeString __fastcall getString(int idx);
	virtual System::WideString __fastcall getWideString(int idx);
	virtual double __fastcall getDouble(int idx);
	virtual bool __fastcall getBoolean(int idx);
public:
	/* TObject.Create */ inline __fastcall TlkJSONcustomlist(void) : TlkJSONbase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TlkJSONcustomlist(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkJSONlist : public TlkJSONcustomlist
{
	typedef TlkJSONcustomlist inherited;
	
public:
	int __fastcall Add(TlkJSONbase* obj)/* overload */;
	int __fastcall Add(bool aboolean)/* overload */;
	int __fastcall Add(double nmb)/* overload */;
	int __fastcall Add(System::UnicodeString s)/* overload */;
	int __fastcall Add(const System::WideString ws)/* overload */;
	int __fastcall Add(int inmb)/* overload */;
	void __fastcall Delete(int idx);
	int __fastcall IndexOf(TlkJSONbase* obj);
	__classmethod TlkJSONlist* __fastcall Generate();
	__classmethod virtual TlkJSONtypes __fastcall SelfType();
	__classmethod virtual System::UnicodeString __fastcall SelfTypeName();
public:
	/* TObject.Create */ inline __fastcall TlkJSONlist(void) : TlkJSONcustomlist() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TlkJSONlist(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkJSONobjectmethod : public TlkJSONbase
{
	typedef TlkJSONbase inherited;
	
protected:
	TlkJSONbase* FValue;
	System::WideString FName;
	void __fastcall SetName(const System::WideString AValue);
	
public:
	__property TlkJSONbase* ObjValue = {read=FValue};
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	__property System::WideString Name = {read=FName, write=SetName};
	__classmethod TlkJSONobjectmethod* __fastcall Generate(const System::WideString aname, TlkJSONbase* aobj);
public:
	/* TObject.Create */ inline __fastcall TlkJSONobjectmethod(void) : TlkJSONbase() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TlkJSONobjectmethod(void) { }
	
};

#pragma pack(pop)

typedef TlkBalNode *PlkBalNode;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TlkBalNode
{
public:
	TlkBalNode *left;
	TlkBalNode *right;
	System::Byte level;
	int key;
	System::WideString nm;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkBalTree : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TlkBalNode *fdeleted;
	TlkBalNode *flast;
	TlkBalNode *fbottom;
	TlkBalNode *froot;
	void __fastcall skew(PlkBalNode &t);
	void __fastcall split(PlkBalNode &t);
	
public:
	System::UnicodeString __fastcall counters(void);
	void __fastcall Clear(void);
	bool __fastcall Insert(const System::WideString ws, int x);
	bool __fastcall Delete(const System::WideString ws);
	int __fastcall IndexOf(const System::WideString ws);
	__fastcall TlkBalTree(void);
	__fastcall virtual ~TlkBalTree(void);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkJSONobject : public TlkJSONcustomlist
{
	typedef TlkJSONcustomlist inherited;
	
public:
	TlkJSONbase* operator[](System::WideString nm) { return this->Field[nm]; }
	
protected:
	TlkBalTree* ht;
	bool FUseHash;
	TlkJSONbase* __fastcall GetFieldByIndex(int idx);
	System::WideString __fastcall GetNameOf(int idx);
	void __fastcall SetFieldByIndex(int idx, TlkJSONbase* const AValue);
	TlkBalTree* __fastcall GetHashTable(void);
	virtual TlkJSONbase* __fastcall ForEachElement(int idx, System::UnicodeString &nm);
	virtual TlkJSONbase* __fastcall GetField(const System::Variant &AName);
	
public:
	__property bool UseHash = {read=FUseHash, nodefault};
	__property TlkBalTree* HashTable = {read=GetHashTable};
	int __fastcall Add(const System::WideString aname, TlkJSONbase* aobj)/* overload */;
	TlkJSONbase* __fastcall OldGetField(System::WideString nm);
	void __fastcall OldSetField(System::WideString nm, TlkJSONbase* const AValue);
	int __fastcall Add(const System::WideString aname, bool aboolean)/* overload */;
	int __fastcall Add(const System::WideString aname, double nmb)/* overload */;
	int __fastcall Add(const System::WideString aname, System::UnicodeString s)/* overload */;
	int __fastcall Add(const System::WideString aname, const System::WideString ws)/* overload */;
	int __fastcall Add(const System::WideString aname, int inmb)/* overload */;
	void __fastcall Delete(int idx);
	int __fastcall IndexOfName(const System::WideString aname);
	int __fastcall IndexOfObject(TlkJSONbase* aobj);
	__property TlkJSONbase* Field[System::WideString nm] = {read=OldGetField, write=OldSetField/*, default*/};
	__fastcall TlkJSONobject(bool bUseHash);
	__fastcall virtual ~TlkJSONobject(void);
	__classmethod TlkJSONobject* __fastcall Generate(bool AUseHash = true);
	__classmethod virtual TlkJSONtypes __fastcall SelfType();
	__classmethod virtual System::UnicodeString __fastcall SelfTypeName();
	__property TlkJSONbase* FieldByIndex[int idx] = {read=GetFieldByIndex, write=SetFieldByIndex};
	__property System::WideString NameOf[int idx] = {read=GetNameOf};
	virtual double __fastcall getDouble(int idx)/* overload */;
	virtual int __fastcall getInt(int idx)/* overload */;
	virtual System::UnicodeString __fastcall getString(int idx)/* overload */;
	virtual System::WideString __fastcall getWideString(int idx)/* overload */;
	virtual bool __fastcall getBoolean(int idx)/* overload */;
	HIDESBASE double __fastcall getDouble(System::UnicodeString nm)/* overload */;
	HIDESBASE int __fastcall getInt(System::UnicodeString nm)/* overload */;
	HIDESBASE System::UnicodeString __fastcall getString(System::UnicodeString nm)/* overload */;
	HIDESBASE System::WideString __fastcall getWideString(System::UnicodeString nm)/* overload */;
	HIDESBASE bool __fastcall getBoolean(System::UnicodeString nm)/* overload */;
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkJSON : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod TlkJSONbase* __fastcall ParseText(const System::UnicodeString txt);
	__classmethod System::UnicodeString __fastcall GenerateText(TlkJSONbase* obj);
public:
	/* TObject.Create */ inline __fastcall TlkJSON(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TlkJSON(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TlkJSONstreamed : public TlkJSON
{
	typedef TlkJSON inherited;
	
public:
	__classmethod TlkJSONbase* __fastcall LoadFromStream(System::Classes::TStream* src);
	__classmethod void __fastcall SaveToStream(TlkJSONbase* obj, System::Classes::TStream* dst);
	__classmethod TlkJSONbase* __fastcall LoadFromFile(System::UnicodeString srcname);
	__classmethod void __fastcall SaveToFile(TlkJSONbase* obj, System::UnicodeString dstname);
public:
	/* TObject.Create */ inline __fastcall TlkJSONstreamed(void) : TlkJSON() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TlkJSONstreamed(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::UnicodeString __fastcall GenerateReadableText(TlkJSONbase* vObj, int &vLevel);
}	/* namespace Ulkjson */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_ULKJSON)
using namespace Ulkjson;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// UlkjsonHPP
