/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QGraphicsItem>

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

#include <QCursor>


HB_FUNC( QGRAPHICSITEM_DELETE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool acceptDrops () const
*/
HB_FUNC( QGRAPHICSITEM_ACCEPTDROPS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->acceptDrops (  );
    hb_retl( b );
  }
}


/*
bool acceptHoverEvents () const
*/
HB_FUNC( QGRAPHICSITEM_ACCEPTHOVEREVENTS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->acceptHoverEvents (  );
    hb_retl( b );
  }
}


/*
bool acceptTouchEvents () const
*/
HB_FUNC( QGRAPHICSITEM_ACCEPTTOUCHEVENTS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->acceptTouchEvents (  );
    hb_retl( b );
  }
}


/*
Qt::MouseButtons acceptedMouseButtons () const
*/
HB_FUNC( QGRAPHICSITEM_ACCEPTEDMOUSEBUTTONS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->acceptedMouseButtons (  );
    hb_retni( i );
  }
}


/*
virtual void advance ( int phase )
*/
HB_FUNC( QGRAPHICSITEM_ADVANCE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->advance ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QRectF boundingRect () const = 0
*/
HB_FUNC( QGRAPHICSITEM_BOUNDINGRECT )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->boundingRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QRegion boundingRegion ( const QTransform & itemToDeviceTransform ) const
*/
HB_FUNC( QGRAPHICSITEM_BOUNDINGREGION )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * par1 = (QTransform *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion * ptr = new QRegion( obj->boundingRegion ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


/*
qreal boundingRegionGranularity () const
*/
HB_FUNC( QGRAPHICSITEM_BOUNDINGREGIONGRANULARITY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->boundingRegionGranularity (  );
    hb_retnd( r );
  }
}


/*
CacheMode cacheMode () const
*/
HB_FUNC( QGRAPHICSITEM_CACHEMODE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->cacheMode (  );
    hb_retni( i );
  }
}


/*
QList<QGraphicsItem *> childItems () const
*/
HB_FUNC( QGRAPHICSITEM_CHILDITEMS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QGraphicsItem *> list = obj->childItems (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QGRAPHICSITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QGRAPHICSITEM" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QGraphicsItem *) list[i] );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
        hb_itemRelease( pItem );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QRectF childrenBoundingRect () const
*/
HB_FUNC( QGRAPHICSITEM_CHILDRENBOUNDINGRECT )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->childrenBoundingRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
void clearFocus ()
*/
HB_FUNC( QGRAPHICSITEM_CLEARFOCUS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearFocus (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QPainterPath clipPath () const
*/
HB_FUNC( QGRAPHICSITEM_CLIPPATH )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * ptr = new QPainterPath( obj->clipPath (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
virtual bool collidesWithItem ( const QGraphicsItem * other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape ) const
*/
HB_FUNC( QGRAPHICSITEM_COLLIDESWITHITEM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) Qt::IntersectsItemShape : hb_parni(2);
    bool b = obj->collidesWithItem ( par1,  (Qt::ItemSelectionMode) par2 );
    hb_retl( b );
  }
}


/*
virtual bool collidesWithPath ( const QPainterPath & path, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape ) const
*/
HB_FUNC( QGRAPHICSITEM_COLLIDESWITHPATH )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) Qt::IntersectsItemShape : hb_parni(2);
    bool b = obj->collidesWithPath ( *par1,  (Qt::ItemSelectionMode) par2 );
    hb_retl( b );
  }
}


/*
QList<QGraphicsItem *> collidingItems ( Qt::ItemSelectionMode mode = Qt::IntersectsItemShape ) const
*/
HB_FUNC( QGRAPHICSITEM_COLLIDINGITEMS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) Qt::IntersectsItemShape : hb_parni(1);
    QList<QGraphicsItem *> list = obj->collidingItems (  (Qt::ItemSelectionMode) par1 );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QGRAPHICSITEM" );
    #else
    pDynSym = hb_dynsymFindName( "QGRAPHICSITEM" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QGraphicsItem *) list[i] );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
        hb_itemRelease( pItem );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QGraphicsItem * commonAncestorItem ( const QGraphicsItem * other ) const
*/
HB_FUNC( QGRAPHICSITEM_COMMONANCESTORITEM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QGraphicsItem * ptr = obj->commonAncestorItem ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSITEM" );  }
}


/*
virtual bool contains ( const QPointF & point ) const
*/
HB_FUNC( QGRAPHICSITEM_CONTAINS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->contains ( *par1 );
    hb_retl( b );
  }
}


/*
QCursor cursor () const
*/
HB_FUNC( QGRAPHICSITEM_CURSOR )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QCursor * ptr = new QCursor( obj->cursor (  ) );
    _qt4xhb_createReturnClass ( ptr, "QCURSOR", true );  }
}


/*
QVariant data ( int key ) const
*/
HB_FUNC( QGRAPHICSITEM_DATA )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QVariant * ptr = new QVariant( obj->data ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
QTransform deviceTransform ( const QTransform & viewportTransform ) const
*/
HB_FUNC( QGRAPHICSITEM_DEVICETRANSFORM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * par1 = (QTransform *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QTransform * ptr = new QTransform( obj->deviceTransform ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QTRANSFORM", true );  }
}


/*
qreal effectiveOpacity () const
*/
HB_FUNC( QGRAPHICSITEM_EFFECTIVEOPACITY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->effectiveOpacity (  );
    hb_retnd( r );
  }
}


/*
void ensureVisible ( const QRectF & rect = QRectF(), int xmargin = 50, int ymargin = 50 )
*/
HB_FUNC( QGRAPHICSITEM_ENSUREVISIBLE1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF par1 = ISNIL(1)? QRectF() : *(QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? 50 : hb_parni(2);
    int par3 = ISNIL(3)? 50 : hb_parni(3);
    obj->ensureVisible ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void ensureVisible ( qreal x, qreal y, qreal w, qreal h, int xmargin = 50, int ymargin = 50 )
*/
HB_FUNC( QGRAPHICSITEM_ENSUREVISIBLE2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    int par5 = ISNIL(5)? 50 : hb_parni(5);
    int par6 = ISNIL(6)? 50 : hb_parni(6);
    obj->ensureVisible ( par1, par2, par3, par4, par5, par6 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void ensureVisible ( const QRectF & rect = QRectF(), int xmargin = 50, int ymargin = 50 )
//[2]void ensureVisible ( qreal x, qreal y, qreal w, qreal h, int xmargin = 50, int ymargin = 50 )

HB_FUNC( QGRAPHICSITEM_ENSUREVISIBLE )
{
  if( ISBETWEEN(0,3) && (ISQRECTF(1)||ISNIL(1)) && (ISNUM(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_ENSUREVISIBLE1 );
  }
  else if( ISBETWEEN(4,6) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && (ISNUM(5)||ISNIL(5)) && (ISNUM(6)||ISNIL(6)) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_ENSUREVISIBLE2 );
  }
}

/*
bool filtersChildEvents () const
*/
HB_FUNC( QGRAPHICSITEM_FILTERSCHILDEVENTS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->filtersChildEvents (  );
    hb_retl( b );
  }
}


/*
GraphicsItemFlags flags () const
*/
HB_FUNC( QGRAPHICSITEM_FLAGS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->flags (  );
    hb_retni( i );
  }
}


/*
QGraphicsItem * focusItem () const
*/
HB_FUNC( QGRAPHICSITEM_FOCUSITEM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * ptr = obj->focusItem (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSITEM" );  }
}


/*
QGraphicsItem * focusProxy () const
*/
HB_FUNC( QGRAPHICSITEM_FOCUSPROXY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * ptr = obj->focusProxy (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSITEM" );  }
}


/*
void grabKeyboard ()
*/
HB_FUNC( QGRAPHICSITEM_GRABKEYBOARD )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->grabKeyboard (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void grabMouse ()
*/
HB_FUNC( QGRAPHICSITEM_GRABMOUSE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->grabMouse (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QGraphicsEffect * graphicsEffect () const
*/
HB_FUNC( QGRAPHICSITEM_GRAPHICSEFFECT )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsEffect * ptr = obj->graphicsEffect (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSEFFECT" );  }
}


/*
QGraphicsItemGroup * group () const
*/
HB_FUNC( QGRAPHICSITEM_GROUP )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItemGroup * ptr = obj->group (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSITEMGROUP" );  }
}


/*
bool hasCursor () const
*/
HB_FUNC( QGRAPHICSITEM_HASCURSOR )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasCursor (  );
    hb_retl( b );
  }
}


/*
bool hasFocus () const
*/
HB_FUNC( QGRAPHICSITEM_HASFOCUS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasFocus (  );
    hb_retl( b );
  }
}


/*
void hide ()
*/
HB_FUNC( QGRAPHICSITEM_HIDE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->hide (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
Qt::InputMethodHints inputMethodHints () const
*/
HB_FUNC( QGRAPHICSITEM_INPUTMETHODHINTS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->inputMethodHints (  );
    hb_retni( i );
  }
}


/*
void installSceneEventFilter ( QGraphicsItem * filterItem )
*/
HB_FUNC( QGRAPHICSITEM_INSTALLSCENEEVENTFILTER )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * par1 = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->installSceneEventFilter ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool isActive () const
*/
HB_FUNC( QGRAPHICSITEM_ISACTIVE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isActive (  );
    hb_retl( b );
  }
}


/*
bool isAncestorOf ( const QGraphicsItem * child ) const
*/
HB_FUNC( QGRAPHICSITEM_ISANCESTOROF )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isAncestorOf ( par1 );
    hb_retl( b );
  }
}



/*
bool isClipped () const
*/
HB_FUNC( QGRAPHICSITEM_ISCLIPPED )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isClipped (  );
    hb_retl( b );
  }
}


/*
bool isEnabled () const
*/
HB_FUNC( QGRAPHICSITEM_ISENABLED )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isEnabled (  );
    hb_retl( b );
  }
}


/*
bool isObscured () const
*/
HB_FUNC( QGRAPHICSITEM_ISOBSCURED1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isObscured (  );
    hb_retl( b );
  }
}


/*
bool isObscured ( qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_ISOBSCURED2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    bool b = obj->isObscured ( par1, par2, par3, par4 );
    hb_retl( b );
  }
}


/*
bool isObscured ( const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_ISOBSCURED3 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isObscured ( *par1 );
    hb_retl( b );
  }
}


//[1]bool isObscured () const
//[2]bool isObscured ( qreal x, qreal y, qreal w, qreal h ) const
//[3]bool isObscured ( const QRectF & rect ) const

HB_FUNC( QGRAPHICSITEM_ISOBSCURED )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_ISOBSCURED1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_ISOBSCURED2 );
  }
  else if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_ISOBSCURED3 );
  }
}

/*
virtual bool isObscuredBy ( const QGraphicsItem * item ) const
*/
HB_FUNC( QGRAPHICSITEM_ISOBSCUREDBY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isObscuredBy ( par1 );
    hb_retl( b );
  }
}


/*
bool isPanel () const
*/
HB_FUNC( QGRAPHICSITEM_ISPANEL )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isPanel (  );
    hb_retl( b );
  }
}


/*
bool isSelected () const
*/
HB_FUNC( QGRAPHICSITEM_ISSELECTED )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSelected (  );
    hb_retl( b );
  }
}


/*
bool isUnderMouse () const
*/
HB_FUNC( QGRAPHICSITEM_ISUNDERMOUSE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isUnderMouse (  );
    hb_retl( b );
  }
}


/*
bool isVisible () const
*/
HB_FUNC( QGRAPHICSITEM_ISVISIBLE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isVisible (  );
    hb_retl( b );
  }
}


/*
bool isVisibleTo ( const QGraphicsItem * parent ) const
*/
HB_FUNC( QGRAPHICSITEM_ISVISIBLETO )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isVisibleTo ( par1 );
    hb_retl( b );
  }
}


/*
bool isWidget () const
*/
HB_FUNC( QGRAPHICSITEM_ISWIDGET )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isWidget (  );
    hb_retl( b );
  }
}


/*
bool isWindow () const
*/
HB_FUNC( QGRAPHICSITEM_ISWINDOW )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isWindow (  );
    hb_retl( b );
  }
}


/*
QTransform itemTransform ( const QGraphicsItem * other, bool * ok = 0 ) const
*/
HB_FUNC( QGRAPHICSITEM_ITEMTRANSFORM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool par2;
    QTransform * ptr = new QTransform( obj->itemTransform ( par1, &par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QTRANSFORM", true );    hb_storl( par2, 2 );
  }
}


/*
QPointF mapFromItem ( const QGraphicsItem * item, const QPointF & point ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMITEM1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * par2 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * ptr = new QPointF( obj->mapFromItem ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPolygonF mapFromItem ( const QGraphicsItem * item, const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMITEM2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * par2 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapFromItem ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPolygonF mapFromItem ( const QGraphicsItem * item, const QPolygonF & polygon ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMITEM3 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * par2 = (QPolygonF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapFromItem ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPainterPath mapFromItem ( const QGraphicsItem * item, const QPainterPath & path ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMITEM4 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * par2 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * ptr = new QPainterPath( obj->mapFromItem ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
QPolygonF mapFromItem ( const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMITEM5 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    qreal par5 = hb_parnd(5);
    QPolygonF * ptr = new QPolygonF( obj->mapFromItem ( par1, par2, par3, par4, par5 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPointF mapFromItem ( const QGraphicsItem * item, qreal x, qreal y ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMITEM6 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    QPointF * ptr = new QPointF( obj->mapFromItem ( par1, par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


//[1]QPointF mapFromItem ( const QGraphicsItem * item, const QPointF & point ) const
//[2]QPolygonF mapFromItem ( const QGraphicsItem * item, const QRectF & rect ) const
//[3]QPolygonF mapFromItem ( const QGraphicsItem * item, const QPolygonF & polygon ) const
//[4]QPainterPath mapFromItem ( const QGraphicsItem * item, const QPainterPath & path ) const
//[5]QPolygonF mapFromItem ( const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h ) const
//[6]QPointF mapFromItem ( const QGraphicsItem * item, qreal x, qreal y ) const

HB_FUNC( QGRAPHICSITEM_MAPFROMITEM )
{
  if( ISNUMPAR(2) && ISQGRAPHICSITEM(1) && ISQPOINTF(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMITEM1 );
  }
  else if( ISNUMPAR(2) && ISQGRAPHICSITEM(1) && ISQRECTF(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMITEM2 );
  }
  else if( ISNUMPAR(2) && ISQGRAPHICSITEM(1) && ISQPOLYGONF(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMITEM3 );
  }
  else if( ISNUMPAR(2) && ISQGRAPHICSITEM(1) && ISQPAINTERPATH(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMITEM4 );
  }
  else if( ISNUMPAR(5) && ISQGRAPHICSITEM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMITEM5 );
  }
  else if( ISNUMPAR(3) && ISQGRAPHICSITEM(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMITEM6 );
  }
}

/*
QPointF mapFromParent ( const QPointF & point ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMPARENT1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * ptr = new QPointF( obj->mapFromParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPolygonF mapFromParent ( const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMPARENT2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapFromParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPolygonF mapFromParent ( const QPolygonF & polygon ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMPARENT3 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPolygonF * par1 = (QPolygonF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapFromParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPainterPath mapFromParent ( const QPainterPath & path ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMPARENT4 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * ptr = new QPainterPath( obj->mapFromParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
QPolygonF mapFromParent ( qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMPARENT5 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    QPolygonF * ptr = new QPolygonF( obj->mapFromParent ( par1, par2, par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPointF mapFromParent ( qreal x, qreal y ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMPARENT6 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    QPointF * ptr = new QPointF( obj->mapFromParent ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


//[1]QPointF mapFromParent ( const QPointF & point ) const
//[2]QPolygonF mapFromParent ( const QRectF & rect ) const
//[3]QPolygonF mapFromParent ( const QPolygonF & polygon ) const
//[4]QPainterPath mapFromParent ( const QPainterPath & path ) const
//[5]QPolygonF mapFromParent ( qreal x, qreal y, qreal w, qreal h ) const
//[6]QPointF mapFromParent ( qreal x, qreal y ) const

HB_FUNC( QGRAPHICSITEM_MAPFROMPARENT )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMPARENT1 );
  }
  else if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMPARENT2 );
  }
  else if( ISNUMPAR(1) && ISQPOLYGONF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMPARENT3 );
  }
  else if( ISNUMPAR(1) && ISQPAINTERPATH(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMPARENT4 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMPARENT5 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMPARENT6 );
  }
}

/*
QPointF mapFromScene ( const QPointF & point ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMSCENE1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * ptr = new QPointF( obj->mapFromScene ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPolygonF mapFromScene ( const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMSCENE2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapFromScene ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPolygonF mapFromScene ( const QPolygonF & polygon ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMSCENE3 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPolygonF * par1 = (QPolygonF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapFromScene ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPainterPath mapFromScene ( const QPainterPath & path ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMSCENE4 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * ptr = new QPainterPath( obj->mapFromScene ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
QPolygonF mapFromScene ( qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMSCENE5 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    QPolygonF * ptr = new QPolygonF( obj->mapFromScene ( par1, par2, par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPointF mapFromScene ( qreal x, qreal y ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPFROMSCENE6 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    QPointF * ptr = new QPointF( obj->mapFromScene ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


//[1]QPointF mapFromScene ( const QPointF & point ) const
//[2]QPolygonF mapFromScene ( const QRectF & rect ) const
//[3]QPolygonF mapFromScene ( const QPolygonF & polygon ) const
//[4]QPainterPath mapFromScene ( const QPainterPath & path ) const
//[5]QPolygonF mapFromScene ( qreal x, qreal y, qreal w, qreal h ) const
//[6]QPointF mapFromScene ( qreal x, qreal y ) const

HB_FUNC( QGRAPHICSITEM_MAPFROMSCENE )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMSCENE1 );
  }
  else if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMSCENE2 );
  }
  else if( ISNUMPAR(1) && ISQPOLYGONF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMSCENE3 );
  }
  else if( ISNUMPAR(1) && ISQPAINTERPATH(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMSCENE4 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMSCENE5 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPFROMSCENE6 );
  }
}

/*
QRectF mapRectFromItem ( const QGraphicsItem * item, const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTFROMITEM1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * par2 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * ptr = new QRectF( obj->mapRectFromItem ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QRectF mapRectFromItem ( const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTFROMITEM2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * par1 = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    qreal par5 = hb_parnd(5);
    QRectF * ptr = new QRectF( obj->mapRectFromItem ( par1, par2, par3, par4, par5 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


//[1]QRectF mapRectFromItem ( const QGraphicsItem * item, const QRectF & rect ) const
//[2]QRectF mapRectFromItem ( const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h ) const

HB_FUNC( QGRAPHICSITEM_MAPRECTFROMITEM )
{
  if( ISNUMPAR(2) && ISQGRAPHICSITEM(1) && ISQRECTF(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTFROMITEM1 );
  }
  else if( ISNUMPAR(5) && ISQGRAPHICSITEM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTFROMITEM2 );
  }
}

/*
QRectF mapRectFromParent ( const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTFROMPARENT1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * ptr = new QRectF( obj->mapRectFromParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QRectF mapRectFromParent ( qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTFROMPARENT2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    QRectF * ptr = new QRectF( obj->mapRectFromParent ( par1, par2, par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


//[1]QRectF mapRectFromParent ( const QRectF & rect ) const
//[2]QRectF mapRectFromParent ( qreal x, qreal y, qreal w, qreal h ) const

HB_FUNC( QGRAPHICSITEM_MAPRECTFROMPARENT )
{
  if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTFROMPARENT1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTFROMPARENT2 );
  }
}

/*
QRectF mapRectFromScene ( const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTFROMSCENE1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * ptr = new QRectF( obj->mapRectFromScene ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QRectF mapRectFromScene ( qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTFROMSCENE2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    QRectF * ptr = new QRectF( obj->mapRectFromScene ( par1, par2, par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


//[1]QRectF mapRectFromScene ( const QRectF & rect ) const
//[2]QRectF mapRectFromScene ( qreal x, qreal y, qreal w, qreal h ) const

HB_FUNC( QGRAPHICSITEM_MAPRECTFROMSCENE )
{
  if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTFROMSCENE1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTFROMSCENE2 );
  }
}

/*
QRectF mapRectToItem ( const QGraphicsItem * item, const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTTOITEM1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * par2 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * ptr = new QRectF( obj->mapRectToItem ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QRectF mapRectToItem ( const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTTOITEM2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    qreal par5 = hb_parnd(5);
    QRectF * ptr = new QRectF( obj->mapRectToItem ( par1, par2, par3, par4, par5 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


//[1]QRectF mapRectToItem ( const QGraphicsItem * item, const QRectF & rect ) const
//[2]QRectF mapRectToItem ( const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h ) const

HB_FUNC( QGRAPHICSITEM_MAPRECTTOITEM )
{
  if( ISNUMPAR(2) && ISQGRAPHICSITEM(1) && ISQRECTF(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTTOITEM1 );
  }
  else if( ISNUMPAR(5) && ISQGRAPHICSITEM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTTOITEM2 );
  }
}

/*
QRectF mapRectToParent ( const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTTOPARENT1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * ptr = new QRectF( obj->mapRectToParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QRectF mapRectToParent ( qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTTOPARENT2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    QRectF * ptr = new QRectF( obj->mapRectToParent ( par1, par2, par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


//[1]QRectF mapRectToParent ( const QRectF & rect ) const
//[2]QRectF mapRectToParent ( qreal x, qreal y, qreal w, qreal h ) const

HB_FUNC( QGRAPHICSITEM_MAPRECTTOPARENT )
{
  if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTTOPARENT1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTTOPARENT2 );
  }
}

/*
QRectF mapRectToScene ( const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTTOSCENE1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * ptr = new QRectF( obj->mapRectToScene ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QRectF mapRectToScene ( qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPRECTTOSCENE2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    QRectF * ptr = new QRectF( obj->mapRectToScene ( par1, par2, par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


//[1]QRectF mapRectToScene ( const QRectF & rect ) const
//[2]QRectF mapRectToScene ( qreal x, qreal y, qreal w, qreal h ) const

HB_FUNC( QGRAPHICSITEM_MAPRECTTOSCENE )
{
  if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTTOSCENE1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPRECTTOSCENE2 );
  }
}

/*
QPointF mapToItem ( const QGraphicsItem * item, const QPointF & point ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOITEM1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * par2 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * ptr = new QPointF( obj->mapToItem ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPolygonF mapToItem ( const QGraphicsItem * item, const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOITEM2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF * par2 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapToItem ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPolygonF mapToItem ( const QGraphicsItem * item, const QPolygonF & polygon ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOITEM3 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * par2 = (QPolygonF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapToItem ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPainterPath mapToItem ( const QGraphicsItem * item, const QPainterPath & path ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOITEM4 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * par2 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * ptr = new QPainterPath( obj->mapToItem ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
QPolygonF mapToItem ( const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOITEM5 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    qreal par5 = hb_parnd(5);
    QPolygonF * ptr = new QPolygonF( obj->mapToItem ( par1, par2, par3, par4, par5 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPointF mapToItem ( const QGraphicsItem * item, qreal x, qreal y ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOITEM6 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    QPointF * ptr = new QPointF( obj->mapToItem ( par1, par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


//[1]QPointF mapToItem ( const QGraphicsItem * item, const QPointF & point ) const
//[2]QPolygonF mapToItem ( const QGraphicsItem * item, const QRectF & rect ) const
//[3]QPolygonF mapToItem ( const QGraphicsItem * item, const QPolygonF & polygon ) const
//[4]QPainterPath mapToItem ( const QGraphicsItem * item, const QPainterPath & path ) const
//[5]QPolygonF mapToItem ( const QGraphicsItem * item, qreal x, qreal y, qreal w, qreal h ) const
//[6]QPointF mapToItem ( const QGraphicsItem * item, qreal x, qreal y ) const

HB_FUNC( QGRAPHICSITEM_MAPTOITEM )
{
  if( ISNUMPAR(2) && ISQGRAPHICSITEM(1) && ISQPOINTF(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOITEM1 );
  }
  else if( ISNUMPAR(2) && ISQGRAPHICSITEM(1) && ISQRECTF(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOITEM2 );
  }
  else if( ISNUMPAR(2) && ISQGRAPHICSITEM(1) && ISQPOLYGONF(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOITEM3 );
  }
  else if( ISNUMPAR(2) && ISQGRAPHICSITEM(1) && ISQPAINTERPATH(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOITEM4 );
  }
  else if( ISNUMPAR(5) && ISQGRAPHICSITEM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && ISNUM(5) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOITEM5 );
  }
  else if( ISNUMPAR(3) && ISQGRAPHICSITEM(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOITEM6 );
  }
}

/*
QPointF mapToParent ( const QPointF & point ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOPARENT1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * ptr = new QPointF( obj->mapToParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPolygonF mapToParent ( const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOPARENT2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapToParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPolygonF mapToParent ( const QPolygonF & polygon ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOPARENT3 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPolygonF * par1 = (QPolygonF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapToParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPainterPath mapToParent ( const QPainterPath & path ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOPARENT4 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * ptr = new QPainterPath( obj->mapToParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
QPolygonF mapToParent ( qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOPARENT5 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    QPolygonF * ptr = new QPolygonF( obj->mapToParent ( par1, par2, par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPointF mapToParent ( qreal x, qreal y ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOPARENT6 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    QPointF * ptr = new QPointF( obj->mapToParent ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


//[1]QPointF mapToParent ( const QPointF & point ) const
//[2]QPolygonF mapToParent ( const QRectF & rect ) const
//[3]QPolygonF mapToParent ( const QPolygonF & polygon ) const
//[4]QPainterPath mapToParent ( const QPainterPath & path ) const
//[5]QPolygonF mapToParent ( qreal x, qreal y, qreal w, qreal h ) const
//[6]QPointF mapToParent ( qreal x, qreal y ) const

HB_FUNC( QGRAPHICSITEM_MAPTOPARENT )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOPARENT1 );
  }
  else if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOPARENT2 );
  }
  else if( ISNUMPAR(1) && ISQPOLYGONF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOPARENT3 );
  }
  else if( ISNUMPAR(1) && ISQPAINTERPATH(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOPARENT4 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOPARENT5 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOPARENT6 );
  }
}

/*
QPointF mapToScene ( const QPointF & point ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOSCENE1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPointF * ptr = new QPointF( obj->mapToScene ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QPolygonF mapToScene ( const QRectF & rect ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOSCENE2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * par1 = (QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapToScene ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPolygonF mapToScene ( const QPolygonF & polygon ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOSCENE3 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPolygonF * par1 = (QPolygonF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPolygonF * ptr = new QPolygonF( obj->mapToScene ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPainterPath mapToScene ( const QPainterPath & path ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOSCENE4 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * par1 = (QPainterPath *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPainterPath * ptr = new QPainterPath( obj->mapToScene ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
QPolygonF mapToScene ( qreal x, qreal y, qreal w, qreal h ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOSCENE5 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    QPolygonF * ptr = new QPolygonF( obj->mapToScene ( par1, par2, par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOLYGONF", true );  }
}


/*
QPointF mapToScene ( qreal x, qreal y ) const
*/
HB_FUNC( QGRAPHICSITEM_MAPTOSCENE6 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    QPointF * ptr = new QPointF( obj->mapToScene ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


//[1]QPointF mapToScene ( const QPointF & point ) const
//[2]QPolygonF mapToScene ( const QRectF & rect ) const
//[3]QPolygonF mapToScene ( const QPolygonF & polygon ) const
//[4]QPainterPath mapToScene ( const QPainterPath & path ) const
//[5]QPolygonF mapToScene ( qreal x, qreal y, qreal w, qreal h ) const
//[6]QPointF mapToScene ( qreal x, qreal y ) const

HB_FUNC( QGRAPHICSITEM_MAPTOSCENE )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOSCENE1 );
  }
  else if( ISNUMPAR(1) && ISQRECTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOSCENE2 );
  }
  else if( ISNUMPAR(1) && ISQPOLYGONF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOSCENE3 );
  }
  else if( ISNUMPAR(1) && ISQPAINTERPATH(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOSCENE4 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOSCENE5 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_MAPTOSCENE6 );
  }
}

/*
void moveBy ( qreal dx, qreal dy )
*/
HB_FUNC( QGRAPHICSITEM_MOVEBY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    obj->moveBy ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
qreal opacity () const
*/
HB_FUNC( QGRAPHICSITEM_OPACITY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->opacity (  );
    hb_retnd( r );
  }
}


/*
virtual QPainterPath opaqueArea () const
*/
HB_FUNC( QGRAPHICSITEM_OPAQUEAREA )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * ptr = new QPainterPath( obj->opaqueArea (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
virtual void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 ) = 0
*/
HB_FUNC( QGRAPHICSITEM_PAINT )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainter * par1 = (QPainter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    const QStyleOptionGraphicsItem * par2 = (const QStyleOptionGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QWidget * par3 = ISNIL(3)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->paint ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QGraphicsItem * panel () const
*/
HB_FUNC( QGRAPHICSITEM_PANEL )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * ptr = obj->panel (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSITEM" );  }
}


/*
PanelModality panelModality () const
*/
HB_FUNC( QGRAPHICSITEM_PANELMODALITY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->panelModality (  );
    hb_retni( i );
  }
}


/*
QGraphicsItem * parentItem () const
*/
HB_FUNC( QGRAPHICSITEM_PARENTITEM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * ptr = obj->parentItem (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSITEM" );  }
}


/*
QGraphicsObject * parentObject () const
*/
HB_FUNC( QGRAPHICSITEM_PARENTOBJECT )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsObject * ptr = obj->parentObject (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSOBJECT" );  }
}


/*
QGraphicsWidget * parentWidget () const
*/
HB_FUNC( QGRAPHICSITEM_PARENTWIDGET )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsWidget * ptr = obj->parentWidget (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSWIDGET" );  }
}


/*
QPointF pos () const
*/
HB_FUNC( QGRAPHICSITEM_POS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->pos (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
void removeSceneEventFilter ( QGraphicsItem * filterItem )
*/
HB_FUNC( QGRAPHICSITEM_REMOVESCENEEVENTFILTER )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * par1 = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->removeSceneEventFilter ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void resetTransform ()
*/
HB_FUNC( QGRAPHICSITEM_RESETTRANSFORM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->resetTransform (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
qreal rotation () const
*/
HB_FUNC( QGRAPHICSITEM_ROTATION )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->rotation (  );
    hb_retnd( r );
  }
}


/*
qreal scale () const
*/
HB_FUNC( QGRAPHICSITEM_SCALE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->scale (  );
    hb_retnd( r );
  }
}


/*
QGraphicsScene * scene () const
*/
HB_FUNC( QGRAPHICSITEM_SCENE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsScene * ptr = obj->scene (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSSCENE" );  }
}


/*
QRectF sceneBoundingRect () const
*/
HB_FUNC( QGRAPHICSITEM_SCENEBOUNDINGRECT )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF * ptr = new QRectF( obj->sceneBoundingRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECTF", true );  }
}


/*
QPointF scenePos () const
*/
HB_FUNC( QGRAPHICSITEM_SCENEPOS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->scenePos (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QTransform sceneTransform () const
*/
HB_FUNC( QGRAPHICSITEM_SCENETRANSFORM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * ptr = new QTransform( obj->sceneTransform (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTRANSFORM", true );  }
}


/*
void scroll ( qreal dx, qreal dy, const QRectF & rect = QRectF() )
*/
HB_FUNC( QGRAPHICSITEM_SCROLL )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    QRectF par3 = ISNIL(3)? QRectF() : *(QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->scroll ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAcceptDrops ( bool on )
*/
HB_FUNC( QGRAPHICSITEM_SETACCEPTDROPS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAcceptDrops ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAcceptHoverEvents ( bool enabled )
*/
HB_FUNC( QGRAPHICSITEM_SETACCEPTHOVEREVENTS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAcceptHoverEvents ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAcceptTouchEvents ( bool enabled )
*/
HB_FUNC( QGRAPHICSITEM_SETACCEPTTOUCHEVENTS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAcceptTouchEvents ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAcceptedMouseButtons ( Qt::MouseButtons buttons )
*/
HB_FUNC( QGRAPHICSITEM_SETACCEPTEDMOUSEBUTTONS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setAcceptedMouseButtons (  (Qt::MouseButtons) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setActive ( bool active )
*/
HB_FUNC( QGRAPHICSITEM_SETACTIVE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setActive ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setBoundingRegionGranularity ( qreal granularity )
*/
HB_FUNC( QGRAPHICSITEM_SETBOUNDINGREGIONGRANULARITY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setBoundingRegionGranularity ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCacheMode ( CacheMode mode, const QSize & logicalCacheSize = QSize() )
*/
HB_FUNC( QGRAPHICSITEM_SETCACHEMODE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QSize par2 = ISNIL(2)? QSize() : *(QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCacheMode (  (QGraphicsItem::CacheMode) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCursor ( const QCursor & cursor )
*/
HB_FUNC( QGRAPHICSITEM_SETCURSOR )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QCursor * par1 = (QCursor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCursor ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setData ( int key, const QVariant & value )
*/
HB_FUNC( QGRAPHICSITEM_SETDATA )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QVariant * par2 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setData ( par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setEnabled ( bool enabled )
*/
HB_FUNC( QGRAPHICSITEM_SETENABLED )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setEnabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFiltersChildEvents ( bool enabled )
*/
HB_FUNC( QGRAPHICSITEM_SETFILTERSCHILDEVENTS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setFiltersChildEvents ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFlag ( GraphicsItemFlag flag, bool enabled = true )
*/
HB_FUNC( QGRAPHICSITEM_SETFLAG )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = ISNIL(2)? true : hb_parl(2);
    obj->setFlag (  (QGraphicsItem::GraphicsItemFlag) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFlags ( GraphicsItemFlags flags )
*/
HB_FUNC( QGRAPHICSITEM_SETFLAGS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFlags (  (QGraphicsItem::GraphicsItemFlags) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFocus ( Qt::FocusReason focusReason = Qt::OtherFocusReason )
*/
HB_FUNC( QGRAPHICSITEM_SETFOCUS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) Qt::OtherFocusReason : hb_parni(1);
    obj->setFocus (  (Qt::FocusReason) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFocusProxy ( QGraphicsItem * item )
*/
HB_FUNC( QGRAPHICSITEM_SETFOCUSPROXY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * par1 = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setFocusProxy ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setGraphicsEffect ( QGraphicsEffect * effect )
*/
HB_FUNC( QGRAPHICSITEM_SETGRAPHICSEFFECT )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsEffect * par1 = (QGraphicsEffect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGraphicsEffect ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setGroup ( QGraphicsItemGroup * group )
*/
HB_FUNC( QGRAPHICSITEM_SETGROUP )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItemGroup * par1 = (QGraphicsItemGroup *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGroup ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setInputMethodHints ( Qt::InputMethodHints hints )
*/
HB_FUNC( QGRAPHICSITEM_SETINPUTMETHODHINTS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setInputMethodHints (  (Qt::InputMethodHints) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOpacity ( qreal opacity )
*/
HB_FUNC( QGRAPHICSITEM_SETOPACITY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setOpacity ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPanelModality ( PanelModality panelModality )
*/
HB_FUNC( QGRAPHICSITEM_SETPANELMODALITY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setPanelModality (  (QGraphicsItem::PanelModality) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setParentItem ( QGraphicsItem * newParent )
*/
HB_FUNC( QGRAPHICSITEM_SETPARENTITEM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * par1 = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setParentItem ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPos ( const QPointF & pos )
*/
HB_FUNC( QGRAPHICSITEM_SETPOS1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setPos ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPos ( qreal x, qreal y )
*/
HB_FUNC( QGRAPHICSITEM_SETPOS2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    obj->setPos ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setPos ( const QPointF & pos )
//[2]void setPos ( qreal x, qreal y )

HB_FUNC( QGRAPHICSITEM_SETPOS )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_SETPOS1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_SETPOS2 );
  }
}

/*
void setRotation ( qreal angle )
*/
HB_FUNC( QGRAPHICSITEM_SETROTATION )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setRotation ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setScale ( qreal factor )
*/
HB_FUNC( QGRAPHICSITEM_SETSCALE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setScale ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSelected ( bool selected )
*/
HB_FUNC( QGRAPHICSITEM_SETSELECTED )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setSelected ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setToolTip ( const QString & toolTip )
*/
HB_FUNC( QGRAPHICSITEM_SETTOOLTIP )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setToolTip ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTransform ( const QTransform & matrix, bool combine = false )
*/
HB_FUNC( QGRAPHICSITEM_SETTRANSFORM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * par1 = (QTransform *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool par2 = ISNIL(2)? false : hb_parl(2);
    obj->setTransform ( *par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTransformOriginPoint ( const QPointF & origin )
*/
HB_FUNC( QGRAPHICSITEM_SETTRANSFORMORIGINPOINT1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * par1 = (QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setTransformOriginPoint ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTransformOriginPoint ( qreal x, qreal y )
*/
HB_FUNC( QGRAPHICSITEM_SETTRANSFORMORIGINPOINT2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    obj->setTransformOriginPoint ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setTransformOriginPoint ( const QPointF & origin )
//[2]void setTransformOriginPoint ( qreal x, qreal y )

HB_FUNC( QGRAPHICSITEM_SETTRANSFORMORIGINPOINT )
{
  if( ISNUMPAR(1) && ISQPOINTF(1) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_SETTRANSFORMORIGINPOINT1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_SETTRANSFORMORIGINPOINT2 );
  }
}

/*
void setTransformations ( const QList<QGraphicsTransform *> & transformations )
*/
HB_FUNC( QGRAPHICSITEM_SETTRANSFORMATIONS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
QList<QGraphicsTransform *> par1;
PHB_ITEM aList1 = hb_param(1, HB_IT_ARRAY);
int i1;
int nLen1 = hb_arrayLen(aList1);
for (i1=0;i1<nLen1;i1++)
{
par1 << (QGraphicsTransform *) hb_itemGetPtr( hb_objSendMsg( hb_arrayGetItemPtr( aList1, i1+1 ), "POINTER", 0 ) );}
    obj->setTransformations ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setVisible ( bool visible )
*/
HB_FUNC( QGRAPHICSITEM_SETVISIBLE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setVisible ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setX ( qreal x )
*/
HB_FUNC( QGRAPHICSITEM_SETX )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setX ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setY ( qreal y )
*/
HB_FUNC( QGRAPHICSITEM_SETY )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setY ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setZValue ( qreal z )
*/
HB_FUNC( QGRAPHICSITEM_SETZVALUE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setZValue ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QPainterPath shape () const
*/
HB_FUNC( QGRAPHICSITEM_SHAPE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainterPath * ptr = new QPainterPath( obj->shape (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPAINTERPATH", true );  }
}


/*
void show ()
*/
HB_FUNC( QGRAPHICSITEM_SHOW )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->show (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void stackBefore ( const QGraphicsItem * sibling )
*/
HB_FUNC( QGRAPHICSITEM_STACKBEFORE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsItem * par1 = (const QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->stackBefore ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QGraphicsObject * toGraphicsObject ()
*/
HB_FUNC( QGRAPHICSITEM_TOGRAPHICSOBJECT1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsObject * ptr = obj->toGraphicsObject (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSOBJECT" );  }
}


/*
const QGraphicsObject * toGraphicsObject () const
*/
HB_FUNC( QGRAPHICSITEM_TOGRAPHICSOBJECT2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QGraphicsObject * ptr = obj->toGraphicsObject (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSOBJECT" );  }
}


//[1]QGraphicsObject * toGraphicsObject ()
//[2]const QGraphicsObject * toGraphicsObject () const

HB_FUNC( QGRAPHICSITEM_TOGRAPHICSOBJECT )
{
  HB_FUNC_EXEC( QGRAPHICSITEM_TOGRAPHICSOBJECT1 );
}

/*
QString toolTip () const
*/
HB_FUNC( QGRAPHICSITEM_TOOLTIP )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->toolTip (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QGraphicsItem * topLevelItem () const
*/
HB_FUNC( QGRAPHICSITEM_TOPLEVELITEM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsItem * ptr = obj->topLevelItem (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSITEM" );  }
}


/*
QGraphicsWidget * topLevelWidget () const
*/
HB_FUNC( QGRAPHICSITEM_TOPLEVELWIDGET )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsWidget * ptr = obj->topLevelWidget (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSWIDGET" );  }
}


/*
QTransform transform () const
*/
HB_FUNC( QGRAPHICSITEM_TRANSFORM )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTransform * ptr = new QTransform( obj->transform (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTRANSFORM", true );  }
}


/*
QPointF transformOriginPoint () const
*/
HB_FUNC( QGRAPHICSITEM_TRANSFORMORIGINPOINT )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPointF * ptr = new QPointF( obj->transformOriginPoint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINTF", true );  }
}


/*
QList<QGraphicsTransform *> transformations () const
*/
HB_FUNC( QGRAPHICSITEM_TRANSFORMATIONS )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QGraphicsTransform *> list = obj->transformations (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QGRAPHICSTRANSFORM" );
    #else
    pDynSym = hb_dynsymFindName( "QGRAPHICSTRANSFORM" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QGraphicsTransform *) list[i] );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
        hb_itemRelease( pItem );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
virtual int type () const
*/
HB_FUNC( QGRAPHICSITEM_TYPE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->type (  );
    hb_retni( i );
  }
}


/*
void ungrabKeyboard ()
*/
HB_FUNC( QGRAPHICSITEM_UNGRABKEYBOARD )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->ungrabKeyboard (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void ungrabMouse ()
*/
HB_FUNC( QGRAPHICSITEM_UNGRABMOUSE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->ungrabMouse (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void unsetCursor ()
*/
HB_FUNC( QGRAPHICSITEM_UNSETCURSOR )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->unsetCursor (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void update ( const QRectF & rect = QRectF() )
*/
HB_FUNC( QGRAPHICSITEM_UPDATE1 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRectF par1 = ISNIL(1)? QRectF() : *(QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->update ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void update ( qreal x, qreal y, qreal width, qreal height )
*/
HB_FUNC( QGRAPHICSITEM_UPDATE2 )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    qreal par2 = hb_parnd(2);
    qreal par3 = hb_parnd(3);
    qreal par4 = hb_parnd(4);
    obj->update ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void update ( const QRectF & rect = QRectF() )
//[2]void update ( qreal x, qreal y, qreal width, qreal height )

HB_FUNC( QGRAPHICSITEM_UPDATE )
{
  if( ISBETWEEN(0,1) && (ISQRECTF(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_UPDATE1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QGRAPHICSITEM_UPDATE2 );
  }
}

/*
QGraphicsWidget * window () const
*/
HB_FUNC( QGRAPHICSITEM_WINDOW )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsWidget * ptr = obj->window (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSWIDGET" );  }
}


/*
qreal x () const
*/
HB_FUNC( QGRAPHICSITEM_X )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->x (  );
    hb_retnd( r );
  }
}


/*
qreal y () const
*/
HB_FUNC( QGRAPHICSITEM_Y )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->y (  );
    hb_retnd( r );
  }
}


/*
qreal zValue () const
*/
HB_FUNC( QGRAPHICSITEM_ZVALUE )
{
  QGraphicsItem * obj = (QGraphicsItem *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->zValue (  );
    hb_retnd( r );
  }
}



