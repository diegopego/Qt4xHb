/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAxScript>

#include "hbapi.h"
#include "hbapiitm.h"
#include "hbapierr.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#define ISNIL HB_ISNIL
#define ISLOG HB_ISLOG
#define ISNUM HB_ISNUM
#define ISCHAR HB_ISCHAR
#define ISPOINTER HB_ISPOINTER
#define ISOBJECT HB_ISOBJECT
#define ISARRAY HB_ISARRAY
#endif
#include "qt4xhb_clsid.h"
#include "qt4xhb_utils.h"

#include <QStringList>

/*
QAxScript ( const QString & name, QAxScriptManager * manager )
*/
HB_FUNC( QAXSCRIPT_NEW )
{
  QAxScript * o = NULL;
  QString par1 = hb_parc(1);
  QAxScriptManager * par2 = (QAxScriptManager *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QAxScript ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QAxScript *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QAXSCRIPT_DELETE )
{
  QAxScript * obj = (QAxScript *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    delete obj;
    obj = NULL;
    PHB_ITEM self = hb_stackSelfItem();
    PHB_ITEM ptr = hb_itemPutPtr( NULL, NULL );
    hb_objSendMsg( self, "_pointer", 1, ptr );
    hb_itemRelease( ptr );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QVariant call ( const QString & function, const QVariant & var1 = QVariant(), const QVariant & var2 = QVariant(), const QVariant & var3 = QVariant(), const QVariant & var4 = QVariant(), const QVariant & var5 = QVariant(), const QVariant & var6 = QVariant(), const QVariant & var7 = QVariant(), const QVariant & var8 = QVariant() )
*/
HB_FUNC( QAXSCRIPT_CALL1 )
{
  QAxScript * obj = (QAxScript *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QVariant par2 = ISNIL(2)? QVariant() : *(QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant par3 = ISNIL(3)? QVariant() : *(QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant par4 = ISNIL(4)? QVariant() : *(QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(4, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant par5 = ISNIL(5)? QVariant() : *(QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(5, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant par6 = ISNIL(6)? QVariant() : *(QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(6, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant par7 = ISNIL(7)? QVariant() : *(QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(7, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant par8 = ISNIL(8)? QVariant() : *(QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(8, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant par9 = ISNIL(9)? QVariant() : *(QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(9, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant * ptr = new QVariant( obj->call ( par1, par2, par3, par4, par5, par6, par7, par8, par9 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
QVariant call ( const QString & function, QList<QVariant> & arguments )
*/
HB_FUNC( QAXSCRIPT_CALL2 )
{
  QAxScript * obj = (QAxScript *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
QList<QVariant> par2;
PHB_ITEM aList2 = hb_param(2, HB_IT_ARRAY);
int i2;
int nLen2 = hb_arrayLen(aList2);
for (i2=0;i2<nLen2;i2++)
{
par2 << *(QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_arrayGetItemPtr( aList2, i2+1 ), "POINTER", 0 ) );
}
    QVariant * ptr = new QVariant( obj->call ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


//[1]QVariant call ( const QString & function, const QVariant & var1 = QVariant(), const QVariant & var2 = QVariant(), const QVariant & var3 = QVariant(), const QVariant & var4 = QVariant(), const QVariant & var5 = QVariant(), const QVariant & var6 = QVariant(), const QVariant & var7 = QVariant(), const QVariant & var8 = QVariant() )
//[2]QVariant call ( const QString & function, QList<QVariant> & arguments )

HB_FUNC( QAXSCRIPT_CALL )
{
  if( ISBETWEEN(1,9) && ISCHAR(1) && (ISQVARIANT(2)||ISNIL(2)) && (ISQVARIANT(3)||ISNIL(3)) && (ISQVARIANT(4)||ISNIL(4)) && (ISQVARIANT(5)||ISNIL(5)) && (ISQVARIANT(6)||ISNIL(6)) && (ISQVARIANT(7)||ISNIL(7)) && (ISQVARIANT(8)||ISNIL(8)) && (ISQVARIANT(9)||ISNIL(9)) )
  {
    HB_FUNC_EXEC( QAXSCRIPT_CALL1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISARRAY(2) )
  {
    HB_FUNC_EXEC( QAXSCRIPT_CALL2 );
  }
}

/*
QStringList functions ( FunctionFlags flags = FunctionNames ) const
*/
HB_FUNC( QAXSCRIPT_FUNCTIONS )
{
  QAxScript * obj = (QAxScript *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) QAxScript::FunctionNames : hb_parni(1);
    QStringList strl = obj->functions (  (QAxScript::FunctionFlags) par1 );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<strl.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutC( NULL, (const char *) strl[i].toLatin1().data() );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
bool load ( const QString & code, const QString & language = QString() )
*/
HB_FUNC( QAXSCRIPT_LOAD )
{
  QAxScript * obj = (QAxScript *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    bool b = obj->load ( par1, par2 );
    hb_retl( b );
  }
}


/*
QString scriptCode () const
*/
HB_FUNC( QAXSCRIPT_SCRIPTCODE )
{
  QAxScript * obj = (QAxScript *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->scriptCode (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QAxScriptEngine * scriptEngine () const
*/
HB_FUNC( QAXSCRIPT_SCRIPTENGINE )
{
  QAxScript * obj = (QAxScript *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAxScriptEngine * ptr = obj->scriptEngine (  );
    _qt4xhb_createReturnClass ( ptr, "QAXSCRIPTENGINE" );  }
}


/*
QString scriptName () const
*/
HB_FUNC( QAXSCRIPT_SCRIPTNAME )
{
  QAxScript * obj = (QAxScript *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->scriptName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}





