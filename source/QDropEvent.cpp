/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDropEvent>

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
QDropEvent ( const QPoint & pos, Qt::DropActions actions, const QMimeData * data, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Type type = Drop )
*/
HB_FUNC( QDROPEVENT_NEW )
{
  QDropEvent * o = NULL;
  QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = hb_parni(2);
  const QMimeData * par3 = (const QMimeData *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par4 = hb_parni(4);
  int par5 = hb_parni(5);
  int par6 = ISNIL(6)? (int) QDropEvent::Drop : hb_parni(6);
  o = new QDropEvent ( *par1,  (Qt::DropActions) par2, par3,  (Qt::MouseButtons) par4,  (Qt::KeyboardModifiers) par5,  (QDropEvent::Type) par6 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDropEvent *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QDROPEVENT_DELETE )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void acceptProposedAction ()
*/
HB_FUNC( QDROPEVENT_ACCEPTPROPOSEDACTION )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->acceptProposedAction (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
Qt::DropAction dropAction () const
*/
HB_FUNC( QDROPEVENT_DROPACTION )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->dropAction (  );
    hb_retni( i );
  }
}


/*
Qt::KeyboardModifiers keyboardModifiers () const
*/
HB_FUNC( QDROPEVENT_KEYBOARDMODIFIERS )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->keyboardModifiers (  );
    hb_retni( i );
  }
}


/*
const QMimeData * mimeData () const
*/
HB_FUNC( QDROPEVENT_MIMEDATA )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QMimeData * ptr = obj->mimeData (  );
    _qt4xhb_createReturnClass ( ptr, "QMIMEDATA" );  }
}


/*
Qt::MouseButtons mouseButtons () const
*/
HB_FUNC( QDROPEVENT_MOUSEBUTTONS )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->mouseButtons (  );
    hb_retni( i );
  }
}


/*
const QPoint &  pos () const
*/
HB_FUNC( QDROPEVENT_POS )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QPoint * ptr = &obj->pos (  );
    _qt4xhb_createReturnClass ( ptr, "QPOINT" );  }
}


/*
Qt::DropActions possibleActions () const
*/
HB_FUNC( QDROPEVENT_POSSIBLEACTIONS )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->possibleActions (  );
    hb_retni( i );
  }
}


/*
Qt::DropAction proposedAction () const
*/
HB_FUNC( QDROPEVENT_PROPOSEDACTION )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->proposedAction (  );
    hb_retni( i );
  }
}


/*
void setDropAction ( Qt::DropAction action )
*/
HB_FUNC( QDROPEVENT_SETDROPACTION )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setDropAction (  (Qt::DropAction) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWidget * source () const
*/
HB_FUNC( QDROPEVENT_SOURCE )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->source (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
virtual QByteArray encodedData ( const char * format ) const
*/
HB_FUNC( QDROPEVENT_ENCODEDDATA )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    QByteArray * ptr = new QByteArray( obj->encodedData (  (const char *) par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
virtual const char * format ( int n = 0 ) const
*/
HB_FUNC( QDROPEVENT_FORMAT )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? 0 : hb_parni(1);
    const char * str1 = obj->format ( par1 );
    hb_retc( str1 );
  }
}


/*
virtual bool provides ( const char * mimeType ) const
*/
HB_FUNC( QDROPEVENT_PROVIDES )
{
  QDropEvent * obj = (QDropEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    bool b = obj->provides (  (const char *) par1 );
    hb_retl( b );
  }
}



