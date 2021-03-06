/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTextObject>

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
QTextDocument * document () const
*/
HB_FUNC( QTEXTOBJECT_DOCUMENT )
{
  QTextObject * obj = (QTextObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextDocument * ptr = obj->document (  );
    _qt4xhb_createReturnClass ( ptr, "QTEXTDOCUMENT" );  }
}


/*
QTextFormat format () const
*/
HB_FUNC( QTEXTOBJECT_FORMAT )
{
  QTextObject * obj = (QTextObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextFormat * ptr = new QTextFormat( obj->format (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTFORMAT" );  }
}


/*
int formatIndex () const
*/
HB_FUNC( QTEXTOBJECT_FORMATINDEX )
{
  QTextObject * obj = (QTextObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->formatIndex (  );
    hb_retni( i );
  }
}


/*
int objectIndex () const
*/
HB_FUNC( QTEXTOBJECT_OBJECTINDEX )
{
  QTextObject * obj = (QTextObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->objectIndex (  );
    hb_retni( i );
  }
}



