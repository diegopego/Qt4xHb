/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QMouseEvent>

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
QMouseEvent(Type type, const QPoint &pos, Qt::MouseButton button,Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers)
*/
HB_FUNC( QMOUSEEVENT_NEW1 )
{
  QMouseEvent * o = NULL;
  int par1 = hb_parni(1);
  QPoint * par2 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par3 = hb_parni(3);
  int par4 = hb_parni(4);
  int par5 = hb_parni(5);
  o = new QMouseEvent (  (QEvent::Type) par1, *par2,  (Qt::MouseButton) par3,  (Qt::MouseButtons) par4,  (Qt::KeyboardModifiers) par5 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QMouseEvent *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QMouseEvent(Type type, const QPoint &pos, const QPoint &globalPos,Qt::MouseButton button, Qt::MouseButtons buttons,Qt::KeyboardModifiers modifiers)
*/
HB_FUNC( QMOUSEEVENT_NEW2 )
{
  QMouseEvent * o = NULL;
  int par1 = hb_parni(1);
  QPoint * par2 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  QPoint * par3 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par4 = hb_parni(4);
  int par5 = hb_parni(5);
  int par6 = hb_parni(6);
  o = new QMouseEvent (  (QEvent::Type) par1, *par2, *par3,  (Qt::MouseButton) par4,  (Qt::MouseButtons) par5,  (Qt::KeyboardModifiers) par6 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QMouseEvent *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QMouseEvent(Type type, const QPoint &pos, Qt::MouseButton button,Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers)
//[2]QMouseEvent(Type type, const QPoint &pos, const QPoint &globalPos,Qt::MouseButton button, Qt::MouseButtons buttons,Qt::KeyboardModifiers modifiers)

HB_FUNC( QMOUSEEVENT_NEW )
{
  if( ISNUMPAR(5) && ISNUM(1) && ISQPOINT(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) )
  {
    HB_FUNC_EXEC( QMOUSEEVENT_NEW1 );
  }
  else if( ISNUMPAR(6) && ISNUM(1) && ISQPOINT(2) && ISQPOINT(3) && ISNUM(4) && ISNUM(5) && ISNUM(6) )
  {
    HB_FUNC_EXEC( QMOUSEEVENT_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QMOUSEEVENT_DELETE )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
const QPoint &pos() const
*/
HB_FUNC( QMOUSEEVENT_POS )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QPoint * ptr = &obj->pos (  );
    _qt4xhb_createReturnClass ( ptr, "QPOINT" );  }
}


/*
const QPoint &globalPos() const
*/
HB_FUNC( QMOUSEEVENT_GLOBALPOS )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QPoint * ptr = &obj->globalPos (  );
    _qt4xhb_createReturnClass ( ptr, "QPOINT" );  }
}


/*
int x() const
*/
HB_FUNC( QMOUSEEVENT_X )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->x (  );
    hb_retni( i );
  }
}


/*
int y() const
*/
HB_FUNC( QMOUSEEVENT_Y )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->y (  );
    hb_retni( i );
  }
}


/*
int globalX() const
*/
HB_FUNC( QMOUSEEVENT_GLOBALX )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->globalX (  );
    hb_retni( i );
  }
}


/*
int globalY() const
*/
HB_FUNC( QMOUSEEVENT_GLOBALY )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->globalY (  );
    hb_retni( i );
  }
}


/*
Qt::MouseButton button() const
*/
HB_FUNC( QMOUSEEVENT_BUTTON )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->button (  );
    hb_retni( i );
  }
}


/*
Qt::MouseButtons buttons() const
*/
HB_FUNC( QMOUSEEVENT_BUTTONS )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->buttons (  );
    hb_retni( i );
  }
}


/*
bool hasExtendedInfo() const
*/
HB_FUNC( QMOUSEEVENT_HASEXTENDEDINFO )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasExtendedInfo (  );
    hb_retl( b );
  }
}


/*
QPointF posF() const
*/
HB_FUNC( QMOUSEEVENT_POSF )
{
  QMouseEvent * obj = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->posF (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}



/*
static QMouseEvent *createExtendedMouseEvent(Type type, const QPointF &pos,const QPoint &globalPos, Qt::MouseButton button,Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers)
*/
HB_FUNC( QMOUSEEVENT_CREATEEXTENDEDMOUSEEVENT )
{
  int par1 = hb_parni(1);
  QPointF * par2 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  QPoint * par3 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par4 = hb_parni(4);
  int par5 = hb_parni(5);
  int par6 = hb_parni(6);
  QMouseEvent * ptr = QMouseEvent::createExtendedMouseEvent (  (QEvent::Type) par1, *par2, *par3,  (Qt::MouseButton) par4,  (Qt::MouseButtons) par5,  (Qt::KeyboardModifiers) par6 );
  _qt4xhb_createReturnClass ( ptr, "QMOUSEEVENT" );}



