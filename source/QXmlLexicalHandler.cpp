/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QXmlLexicalHandler>

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

HB_FUNC( QXMLLEXICALHANDLER_DELETE )
{
  QXmlLexicalHandler * obj = (QXmlLexicalHandler *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual bool comment ( const QString & ch ) = 0
*/
HB_FUNC( QXMLLEXICALHANDLER_COMMENT )
{
  QXmlLexicalHandler * obj = (QXmlLexicalHandler *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->comment ( par1 );
    hb_retl( b );
  }
}


/*
virtual bool endCDATA () = 0
*/
HB_FUNC( QXMLLEXICALHANDLER_ENDCDATA )
{
  QXmlLexicalHandler * obj = (QXmlLexicalHandler *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->endCDATA (  );
    hb_retl( b );
  }
}


/*
virtual bool endDTD () = 0
*/
HB_FUNC( QXMLLEXICALHANDLER_ENDDTD )
{
  QXmlLexicalHandler * obj = (QXmlLexicalHandler *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->endDTD (  );
    hb_retl( b );
  }
}


/*
virtual bool endEntity ( const QString & name ) = 0
*/
HB_FUNC( QXMLLEXICALHANDLER_ENDENTITY )
{
  QXmlLexicalHandler * obj = (QXmlLexicalHandler *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->endEntity ( par1 );
    hb_retl( b );
  }
}


/*
virtual QString errorString () const = 0
*/
HB_FUNC( QXMLLEXICALHANDLER_ERRORSTRING )
{
  QXmlLexicalHandler * obj = (QXmlLexicalHandler *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->errorString (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual bool startCDATA () = 0
*/
HB_FUNC( QXMLLEXICALHANDLER_STARTCDATA )
{
  QXmlLexicalHandler * obj = (QXmlLexicalHandler *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->startCDATA (  );
    hb_retl( b );
  }
}


/*
virtual bool startDTD ( const QString & name, const QString & publicId, const QString & systemId ) = 0
*/
HB_FUNC( QXMLLEXICALHANDLER_STARTDTD )
{
  QXmlLexicalHandler * obj = (QXmlLexicalHandler *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    QString par3 = hb_parc(3);
    bool b = obj->startDTD ( par1, par2, par3 );
    hb_retl( b );
  }
}


/*
virtual bool startEntity ( const QString & name ) = 0
*/
HB_FUNC( QXMLLEXICALHANDLER_STARTENTITY )
{
  QXmlLexicalHandler * obj = (QXmlLexicalHandler *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->startEntity ( par1 );
    hb_retl( b );
  }
}



