/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QSystemLocale>

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

/*
QSystemLocale ()
*/
HB_FUNC( QSYSTEMLOCALE_NEW )
{
  QSystemLocale * o = NULL;
  o = new QSystemLocale (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSystemLocale *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}



/*
virtual QLocale fallbackLocale () const
*/
HB_FUNC( QSYSTEMLOCALE_FALLBACKLOCALE )
{
  QSystemLocale * obj = (QSystemLocale *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLocale * ptr = new QLocale( obj->fallbackLocale (  ) );
    _qt4xhb_createReturnClass ( ptr, "QLOCALE" );  }
}


/*
virtual QVariant query ( QueryType type, QVariant in ) const
*/
HB_FUNC( QSYSTEMLOCALE_QUERY )
{
  QSystemLocale * obj = (QSystemLocale *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QVariant * par2 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant * ptr = new QVariant( obj->query (  (QSystemLocale::QueryType) par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}



