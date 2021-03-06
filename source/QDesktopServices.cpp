/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDesktopServices>

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
QString displayName ( StandardLocation type )
*/
HB_FUNC( QDESKTOPSERVICES_DISPLAYNAME )
{
  int par1 = hb_parni(1);
  QString str1 = QDesktopServices::displayName (  (QDesktopServices::StandardLocation) par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
bool openUrl ( const QUrl & url )
*/
HB_FUNC( QDESKTOPSERVICES_OPENURL )
{
  QUrl * par1 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  bool b = QDesktopServices::openUrl ( *par1 );
  hb_retl( b );
}


/*
void setUrlHandler ( const QString & scheme, QObject * receiver, const char * method )
*/
HB_FUNC( QDESKTOPSERVICES_SETURLHANDLER )
{
  QString par1 = hb_parc(1);
  QObject * par2 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  const char * par3 = hb_parc(3);
  QDesktopServices::setUrlHandler ( par1, par2,  (const char *) par3 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString storageLocation ( StandardLocation type )
*/
HB_FUNC( QDESKTOPSERVICES_STORAGELOCATION )
{
  int par1 = hb_parni(1);
  QString str1 = QDesktopServices::storageLocation (  (QDesktopServices::StandardLocation) par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
void unsetUrlHandler ( const QString & scheme )
*/
HB_FUNC( QDESKTOPSERVICES_UNSETURLHANDLER )
{
  QString par1 = hb_parc(1);
  QDesktopServices::unsetUrlHandler ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}



