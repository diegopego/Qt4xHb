/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAbstractExtensionManager>

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

HB_FUNC( QABSTRACTEXTENSIONMANAGER_DELETE )
{
  QAbstractExtensionManager * obj = (QAbstractExtensionManager *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual QObject * extension ( QObject * object, const QString & iid ) const = 0
*/
HB_FUNC( QABSTRACTEXTENSIONMANAGER_EXTENSION )
{
  QAbstractExtensionManager * obj = (QAbstractExtensionManager *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = hb_parc(2);
    QObject * ptr = obj->extension ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QOBJECT" );  }
}


/*
virtual void registerExtensions ( QAbstractExtensionFactory * factory, const QString & iid ) = 0
*/
HB_FUNC( QABSTRACTEXTENSIONMANAGER_REGISTEREXTENSIONS )
{
  QAbstractExtensionManager * obj = (QAbstractExtensionManager *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractExtensionFactory * par1 = (QAbstractExtensionFactory *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = hb_parc(2);
    obj->registerExtensions ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void unregisterExtensions ( QAbstractExtensionFactory * factory, const QString & iid ) = 0
*/
HB_FUNC( QABSTRACTEXTENSIONMANAGER_UNREGISTEREXTENSIONS )
{
  QAbstractExtensionManager * obj = (QAbstractExtensionManager *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractExtensionFactory * par1 = (QAbstractExtensionFactory *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = hb_parc(2);
    obj->unregisterExtensions ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



