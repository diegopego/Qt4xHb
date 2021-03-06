/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QWidget>

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

#include <QIcon>
#include <QVariant>
#include <QLocale>

/*
QWidget ( QWidget * parent = 0, Qt::WindowFlags f = 0 )
*/
HB_FUNC( QWIDGET_NEW )
{
  QWidget * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) 0 : hb_parni(2);
  o = new QWidget ( par1,  (Qt::WindowFlags) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QWidget *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QWIDGET_DELETE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
HB_FUNC( QWIDGET_ACCEPTDROPS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->acceptDrops (  );
    hb_retl( b );
  }
}


/*
QString accessibleDescription () const
*/
HB_FUNC( QWIDGET_ACCESSIBLEDESCRIPTION )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->accessibleDescription (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString accessibleName () const
*/
HB_FUNC( QWIDGET_ACCESSIBLENAME )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->accessibleName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QList<QAction *> actions () const
*/
HB_FUNC( QWIDGET_ACTIONS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QAction *> list = obj->actions (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QACTION" );
    #else
    pDynSym = hb_dynsymFindName( "QACTION" );
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
        hb_itemPutPtr( pItem, (QAction *) list[i] );
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
void activateWindow ()
*/
HB_FUNC( QWIDGET_ACTIVATEWINDOW )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->activateWindow (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addAction ( QAction * action )
*/
HB_FUNC( QWIDGET_ADDACTION )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * par1 = (QAction *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addAction ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addActions ( QList<QAction *> actions )
*/
HB_FUNC( QWIDGET_ADDACTIONS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
QList<QAction *> par1;
PHB_ITEM aList1 = hb_param(1, HB_IT_ARRAY);
int i1;
int nLen1 = hb_arrayLen(aList1);
for (i1=0;i1<nLen1;i1++)
{
par1 << (QAction *) hb_itemGetPtr( hb_objSendMsg( hb_arrayGetItemPtr( aList1, i1+1 ), "POINTER", 0 ) );}
    obj->addActions ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void adjustSize ()
*/
HB_FUNC( QWIDGET_ADJUSTSIZE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->adjustSize (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool autoFillBackground () const
*/
HB_FUNC( QWIDGET_AUTOFILLBACKGROUND )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->autoFillBackground (  );
    hb_retl( b );
  }
}


/*
QPalette::ColorRole backgroundRole () const
*/
HB_FUNC( QWIDGET_BACKGROUNDROLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->backgroundRole (  );
    hb_retni( i );
  }
}


/*
QSize baseSize () const
*/
HB_FUNC( QWIDGET_BASESIZE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->baseSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
QWidget * childAt ( int x, int y ) const
*/
HB_FUNC( QWIDGET_CHILDAT1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QWidget * ptr = obj->childAt ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
QWidget * childAt ( const QPoint & p ) const
*/
HB_FUNC( QWIDGET_CHILDAT2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QWidget * ptr = obj->childAt ( *par1 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


//[1]QWidget * childAt ( int x, int y ) const
//[2]QWidget * childAt ( const QPoint & p ) const

HB_FUNC( QWIDGET_CHILDAT )
{
  if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_CHILDAT1 );
  }
  else if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QWIDGET_CHILDAT2 );
  }
}

/*
QRect childrenRect () const
*/
HB_FUNC( QWIDGET_CHILDRENRECT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->childrenRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
QRegion childrenRegion () const
*/
HB_FUNC( QWIDGET_CHILDRENREGION )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * ptr = new QRegion( obj->childrenRegion (  ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


/*
void clearFocus ()
*/
HB_FUNC( QWIDGET_CLEARFOCUS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearFocus (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void clearMask ()
*/
HB_FUNC( QWIDGET_CLEARMASK )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearMask (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QMargins contentsMargins () const
*/
HB_FUNC( QWIDGET_CONTENTSMARGINS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QMargins * ptr = new QMargins( obj->contentsMargins (  ) );
    _qt4xhb_createReturnClass ( ptr, "QMARGINS", true );  }
}


/*
QRect contentsRect () const
*/
HB_FUNC( QWIDGET_CONTENTSRECT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->contentsRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
Qt::ContextMenuPolicy contextMenuPolicy () const
*/
HB_FUNC( QWIDGET_CONTEXTMENUPOLICY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->contextMenuPolicy (  );
    hb_retni( i );
  }
}


/*
QCursor cursor () const
*/
HB_FUNC( QWIDGET_CURSOR )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QCursor * ptr = new QCursor( obj->cursor (  ) );
    _qt4xhb_createReturnClass ( ptr, "QCURSOR", true );  }
}


/*
WId effectiveWinId () const
*/
HB_FUNC( QWIDGET_EFFECTIVEWINID )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    WId r = obj->effectiveWinId (  );
    hb_retptr( r );
  }
}


/*
void ensurePolished () const
*/
HB_FUNC( QWIDGET_ENSUREPOLISHED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->ensurePolished (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
Qt::FocusPolicy focusPolicy () const
*/
HB_FUNC( QWIDGET_FOCUSPOLICY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->focusPolicy (  );
    hb_retni( i );
  }
}


/*
QWidget * focusProxy () const
*/
HB_FUNC( QWIDGET_FOCUSPROXY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->focusProxy (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
QWidget * focusWidget () const
*/
HB_FUNC( QWIDGET_FOCUSWIDGET )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->focusWidget (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
const QFont & font () const
*/
HB_FUNC( QWIDGET_FONT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QFont * ptr = &obj->font (  );
    _qt4xhb_createReturnClass ( ptr, "QFONT" );  }
}


/*
QFontInfo fontInfo () const
*/
HB_FUNC( QWIDGET_FONTINFO )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFontInfo * ptr = new QFontInfo( obj->fontInfo (  ) );
    _qt4xhb_createReturnClass ( ptr, "QFONTINFO", true );  }
}


/*
QFontMetrics fontMetrics () const
*/
HB_FUNC( QWIDGET_FONTMETRICS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFontMetrics * ptr = new QFontMetrics( obj->fontMetrics (  ) );
    _qt4xhb_createReturnClass ( ptr, "QFONTMETRICS", true );  }
}


/*
QPalette::ColorRole foregroundRole () const
*/
HB_FUNC( QWIDGET_FOREGROUNDROLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->foregroundRole (  );
    hb_retni( i );
  }
}


/*
QRect frameGeometry () const
*/
HB_FUNC( QWIDGET_FRAMEGEOMETRY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->frameGeometry (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
QSize frameSize () const
*/
HB_FUNC( QWIDGET_FRAMESIZE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->frameSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
const QRect & geometry () const
*/
HB_FUNC( QWIDGET_GEOMETRY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QRect * ptr = &obj->geometry (  );
    _qt4xhb_createReturnClass ( ptr, "QRECT" );  }
}


/*
void getContentsMargins ( int * left, int * top, int * right, int * bottom ) const
*/
HB_FUNC( QWIDGET_GETCONTENTSMARGINS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1;
    int par2;
    int par3;
    int par4;
    obj->getContentsMargins ( &par1, &par2, &par3, &par4 );
    hb_storni( par1, 1 );
    hb_storni( par2, 2 );
    hb_storni( par3, 3 );
    hb_storni( par4, 4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void grabGesture ( Qt::GestureType gesture, Qt::GestureFlags flags = Qt::GestureFlags() )
*/
HB_FUNC( QWIDGET_GRABGESTURE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? (int) Qt::GestureFlags() : hb_parni(2);
    obj->grabGesture (  (Qt::GestureType) par1,  (Qt::GestureFlags) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void grabKeyboard ()
*/
HB_FUNC( QWIDGET_GRABKEYBOARD )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->grabKeyboard (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void grabMouse ()
*/
HB_FUNC( QWIDGET_GRABMOUSE1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->grabMouse (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void grabMouse ( const QCursor & cursor )
*/
HB_FUNC( QWIDGET_GRABMOUSE2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QCursor * par1 = (QCursor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->grabMouse ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void grabMouse ()
//[2]void grabMouse ( const QCursor & cursor )

HB_FUNC( QWIDGET_GRABMOUSE )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QWIDGET_GRABMOUSE1 );
  }
  else if( ISNUMPAR(1) && ISQCURSOR(1) )
  {
    HB_FUNC_EXEC( QWIDGET_GRABMOUSE2 );
  }
}

/*
int grabShortcut ( const QKeySequence & key, Qt::ShortcutContext context = Qt::WindowShortcut )
*/
HB_FUNC( QWIDGET_GRABSHORTCUT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QKeySequence * par1 = (QKeySequence *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) Qt::WindowShortcut : hb_parni(2);
    int i = obj->grabShortcut ( *par1,  (Qt::ShortcutContext) par2 );
    hb_retni( i );
  }
}


/*
QGraphicsEffect * graphicsEffect () const
*/
HB_FUNC( QWIDGET_GRAPHICSEFFECT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsEffect * ptr = obj->graphicsEffect (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSEFFECT" );  }
}


/*
QGraphicsProxyWidget * graphicsProxyWidget () const
*/
HB_FUNC( QWIDGET_GRAPHICSPROXYWIDGET )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsProxyWidget * ptr = obj->graphicsProxyWidget (  );
    _qt4xhb_createReturnClass ( ptr, "QGRAPHICSPROXYWIDGET" );  }
}



/*
bool hasFocus () const
*/
HB_FUNC( QWIDGET_HASFOCUS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasFocus (  );
    hb_retl( b );
  }
}


/*
bool hasMouseTracking () const
*/
HB_FUNC( QWIDGET_HASMOUSETRACKING )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasMouseTracking (  );
    hb_retl( b );
  }
}


/*
int height () const
*/
HB_FUNC( QWIDGET_HEIGHT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->height (  );
    hb_retni( i );
  }
}


/*
virtual int heightForWidth ( int w ) const
*/
HB_FUNC( QWIDGET_HEIGHTFORWIDTH )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->heightForWidth ( par1 );
    hb_retni( i );
  }
}


/*
QInputContext * inputContext ()
*/
HB_FUNC( QWIDGET_INPUTCONTEXT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QInputContext * ptr = obj->inputContext (  );
    _qt4xhb_createReturnClass ( ptr, "QINPUTCONTEXT" );  }
}


/*
Qt::InputMethodHints inputMethodHints () const
*/
HB_FUNC( QWIDGET_INPUTMETHODHINTS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->inputMethodHints (  );
    hb_retni( i );
  }
}


/*
virtual QVariant inputMethodQuery ( Qt::InputMethodQuery query ) const
*/
HB_FUNC( QWIDGET_INPUTMETHODQUERY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QVariant * ptr = new QVariant( obj->inputMethodQuery (  (Qt::InputMethodQuery) par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
void insertAction ( QAction * before, QAction * action )
*/
HB_FUNC( QWIDGET_INSERTACTION )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * par1 = (QAction *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QAction * par2 = (QAction *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->insertAction ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void insertActions ( QAction * before, QList<QAction *> actions )
*/
HB_FUNC( QWIDGET_INSERTACTIONS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * par1 = (QAction *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
QList<QAction *> par2;
PHB_ITEM aList2 = hb_param(2, HB_IT_ARRAY);
int i2;
int nLen2 = hb_arrayLen(aList2);
for (i2=0;i2<nLen2;i2++)
{
par2 << (QAction *) hb_itemGetPtr( hb_objSendMsg( hb_arrayGetItemPtr( aList2, i2+1 ), "POINTER", 0 ) );}
    obj->insertActions ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool isActiveWindow () const
*/
HB_FUNC( QWIDGET_ISACTIVEWINDOW )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isActiveWindow (  );
    hb_retl( b );
  }
}


/*
bool isAncestorOf ( const QWidget * child ) const
*/
HB_FUNC( QWIDGET_ISANCESTOROF )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QWidget * par1 = (const QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isAncestorOf ( par1 );
    hb_retl( b );
  }
}


/*
bool isEnabled () const
*/
HB_FUNC( QWIDGET_ISENABLED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isEnabled (  );
    hb_retl( b );
  }
}


/*
bool isEnabledTo ( QWidget * ancestor ) const
*/
HB_FUNC( QWIDGET_ISENABLEDTO )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isEnabledTo ( par1 );
    hb_retl( b );
  }
}


/*
bool isFullScreen () const
*/
HB_FUNC( QWIDGET_ISFULLSCREEN )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isFullScreen (  );
    hb_retl( b );
  }
}


/*
bool isHidden () const
*/
HB_FUNC( QWIDGET_ISHIDDEN )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isHidden (  );
    hb_retl( b );
  }
}


/*
bool isMaximized () const
*/
HB_FUNC( QWIDGET_ISMAXIMIZED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isMaximized (  );
    hb_retl( b );
  }
}


/*
bool isMinimized () const
*/
HB_FUNC( QWIDGET_ISMINIMIZED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isMinimized (  );
    hb_retl( b );
  }
}


/*
bool isModal () const
*/
HB_FUNC( QWIDGET_ISMODAL )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isModal (  );
    hb_retl( b );
  }
}


/*
bool isVisible () const
*/
HB_FUNC( QWIDGET_ISVISIBLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isVisible (  );
    hb_retl( b );
  }
}


/*
bool isVisibleTo ( QWidget * ancestor ) const
*/
HB_FUNC( QWIDGET_ISVISIBLETO )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->isVisibleTo ( par1 );
    hb_retl( b );
  }
}


/*
bool isWindow () const
*/
HB_FUNC( QWIDGET_ISWINDOW )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isWindow (  );
    hb_retl( b );
  }
}


/*
bool isWindowModified () const
*/
HB_FUNC( QWIDGET_ISWINDOWMODIFIED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isWindowModified (  );
    hb_retl( b );
  }
}


/*
QLayout * layout () const
*/
HB_FUNC( QWIDGET_LAYOUT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLayout * ptr = obj->layout (  );
    _qt4xhb_createReturnClass ( ptr, "QLAYOUT" );  }
}


/*
Qt::LayoutDirection layoutDirection () const
*/
HB_FUNC( QWIDGET_LAYOUTDIRECTION )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->layoutDirection (  );
    hb_retni( i );
  }
}


/*
QLocale locale () const
*/
HB_FUNC( QWIDGET_LOCALE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLocale * ptr = new QLocale( obj->locale (  ) );
    _qt4xhb_createReturnClass ( ptr, "QLOCALE" );  }
}




/*
QPoint mapFrom ( QWidget * parent, const QPoint & pos ) const
*/
HB_FUNC( QWIDGET_MAPFROM )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint * par2 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint * ptr = new QPoint( obj->mapFrom ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
QPoint mapFromGlobal ( const QPoint & pos ) const
*/
HB_FUNC( QWIDGET_MAPFROMGLOBAL )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint * ptr = new QPoint( obj->mapFromGlobal ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
QPoint mapFromParent ( const QPoint & pos ) const
*/
HB_FUNC( QWIDGET_MAPFROMPARENT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint * ptr = new QPoint( obj->mapFromParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
QPoint mapTo ( QWidget * parent, const QPoint & pos ) const
*/
HB_FUNC( QWIDGET_MAPTO )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint * par2 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint * ptr = new QPoint( obj->mapTo ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
QPoint mapToGlobal ( const QPoint & pos ) const
*/
HB_FUNC( QWIDGET_MAPTOGLOBAL )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint * ptr = new QPoint( obj->mapToGlobal ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
QPoint mapToParent ( const QPoint & pos ) const
*/
HB_FUNC( QWIDGET_MAPTOPARENT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint * ptr = new QPoint( obj->mapToParent ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
QRegion mask () const
*/
HB_FUNC( QWIDGET_MASK )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * ptr = new QRegion( obj->mask (  ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


/*
int maximumHeight () const
*/
HB_FUNC( QWIDGET_MAXIMUMHEIGHT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->maximumHeight (  );
    hb_retni( i );
  }
}


/*
QSize maximumSize () const
*/
HB_FUNC( QWIDGET_MAXIMUMSIZE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->maximumSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
int maximumWidth () const
*/
HB_FUNC( QWIDGET_MAXIMUMWIDTH )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->maximumWidth (  );
    hb_retni( i );
  }
}


/*
int minimumHeight () const
*/
HB_FUNC( QWIDGET_MINIMUMHEIGHT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->minimumHeight (  );
    hb_retni( i );
  }
}


/*
QSize minimumSize () const
*/
HB_FUNC( QWIDGET_MINIMUMSIZE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->minimumSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual QSize minimumSizeHint () const
*/
HB_FUNC( QWIDGET_MINIMUMSIZEHINT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->minimumSizeHint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
int minimumWidth () const
*/
HB_FUNC( QWIDGET_MINIMUMWIDTH )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->minimumWidth (  );
    hb_retni( i );
  }
}


/*
void move ( const QPoint & )
*/
HB_FUNC( QWIDGET_MOVE1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->move ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void move ( int x, int y )
*/
HB_FUNC( QWIDGET_MOVE2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->move ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void move ( const QPoint & )
//[2]void move ( int x, int y )

HB_FUNC( QWIDGET_MOVE )
{
  if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QWIDGET_MOVE1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_MOVE2 );
  }
}

/*
QWidget * nativeParentWidget () const
*/
HB_FUNC( QWIDGET_NATIVEPARENTWIDGET )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->nativeParentWidget (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
QWidget * nextInFocusChain () const
*/
HB_FUNC( QWIDGET_NEXTINFOCUSCHAIN )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->nextInFocusChain (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
QRect normalGeometry () const
*/
HB_FUNC( QWIDGET_NORMALGEOMETRY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->normalGeometry (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
void overrideWindowFlags ( Qt::WindowFlags flags )
*/
HB_FUNC( QWIDGET_OVERRIDEWINDOWFLAGS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->overrideWindowFlags (  (Qt::WindowFlags) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
const QPalette & palette () const
*/
HB_FUNC( QWIDGET_PALETTE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QPalette * ptr = &obj->palette (  );
    _qt4xhb_createReturnClass ( ptr, "QPALETTE" );  }
}


/*
QWidget * parentWidget () const
*/
HB_FUNC( QWIDGET_PARENTWIDGET )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->parentWidget (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
QPoint pos () const
*/
HB_FUNC( QWIDGET_POS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * ptr = new QPoint( obj->pos (  ) );
    _qt4xhb_createReturnClass ( ptr, "QPOINT", true );  }
}


/*
QWidget * previousInFocusChain () const
*/
HB_FUNC( QWIDGET_PREVIOUSINFOCUSCHAIN )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->previousInFocusChain (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
QRect rect () const
*/
HB_FUNC( QWIDGET_RECT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->rect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
void releaseKeyboard ()
*/
HB_FUNC( QWIDGET_RELEASEKEYBOARD )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->releaseKeyboard (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void releaseMouse ()
*/
HB_FUNC( QWIDGET_RELEASEMOUSE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->releaseMouse (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void releaseShortcut ( int id )
*/
HB_FUNC( QWIDGET_RELEASESHORTCUT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->releaseShortcut ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeAction ( QAction * action )
*/
HB_FUNC( QWIDGET_REMOVEACTION )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAction * par1 = (QAction *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->removeAction ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void render ( QPaintDevice * target, const QPoint & targetOffset = QPoint(), const QRegion & sourceRegion = QRegion(), RenderFlags renderFlags = RenderFlags( DrawWindowBackground | DrawChildren ) )
*/
HB_FUNC( QWIDGET_RENDER1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPaintDevice * par1 = (QPaintDevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint par2 = ISNIL(2)? QPoint() : *(QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion par3 = ISNIL(3)? QRegion() : *(QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par4 = ISNIL(4)? (int) QWidget::DrawWindowBackground | QWidget::DrawChildren : hb_parni(4);
    obj->render ( par1, par2, par3,  (QWidget::RenderFlags) par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void render ( QPainter * painter, const QPoint & targetOffset = QPoint(), const QRegion & sourceRegion = QRegion(), RenderFlags renderFlags = RenderFlags( DrawWindowBackground | DrawChildren ) )
*/
HB_FUNC( QWIDGET_RENDER2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainter * par1 = (QPainter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QPoint par2 = ISNIL(2)? QPoint() : *(QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion par3 = ISNIL(3)? QRegion() : *(QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par4 = ISNIL(4)? (int) QWidget::DrawWindowBackground | QWidget::DrawChildren : hb_parni(4);
    obj->render ( par1, par2, par3,  (QWidget::RenderFlags) par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void render ( QPaintDevice * target, const QPoint & targetOffset = QPoint(), const QRegion & sourceRegion = QRegion(), RenderFlags renderFlags = RenderFlags( DrawWindowBackground | DrawChildren ) )
//[2]void render ( QPainter * painter, const QPoint & targetOffset = QPoint(), const QRegion & sourceRegion = QRegion(), RenderFlags renderFlags = RenderFlags( DrawWindowBackground | DrawChildren ) )

// TODO: implementar reconhecimento de QPaintDevice

HB_FUNC( QWIDGET_RENDER )
{
  if( ISBETWEEN(1,4) && ISQPAINTER(1) && (ISQPOINT(2)||ISNIL(2)) && (ISQREGION(3)||ISNIL(3)) && (ISNUM(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QWIDGET_RENDER2 );
  }
  else if( ISBETWEEN(1,4) && ISOBJECT(1) && (ISQPOINT(2)||ISNIL(2)) && (ISQREGION(3)||ISNIL(3)) && (ISNUM(4)||ISNIL(4)) )
  {
    HB_FUNC_EXEC( QWIDGET_RENDER1 );
  }
}

/*
void repaint ( int x, int y, int w, int h )
*/
HB_FUNC( QWIDGET_REPAINT1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    obj->repaint ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void repaint ( const QRect & rect )
*/
HB_FUNC( QWIDGET_REPAINT2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->repaint ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void repaint ( const QRegion & rgn )
*/
HB_FUNC( QWIDGET_REPAINT3 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->repaint ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void repaint ( int x, int y, int w, int h )
//[2]void repaint ( const QRect & rect )
//[3]void repaint ( const QRegion & rgn )

HB_FUNC( QWIDGET_REPAINT )
{
  if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QWIDGET_REPAINT1 );
  }
  else if( ISNUMPAR(1) && ISQRECT(1) )
  {
    HB_FUNC_EXEC( QWIDGET_REPAINT2 );
  }
  else if( ISNUMPAR(1) && ISQREGION(1) )
  {
    HB_FUNC_EXEC( QWIDGET_REPAINT3 );
  }
}

/*
void resize ( const QSize & )
*/
HB_FUNC( QWIDGET_RESIZE1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->resize ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void resize ( int w, int h )
*/
HB_FUNC( QWIDGET_RESIZE2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->resize ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void resize ( const QSize & )
//[2]void resize ( int w, int h )

HB_FUNC( QWIDGET_RESIZE )
{
  if( ISNUMPAR(1) && ISQSIZE(1) )
  {
    HB_FUNC_EXEC( QWIDGET_RESIZE1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_RESIZE2 );
  }
}

/*
bool restoreGeometry ( const QByteArray & geometry )
*/
HB_FUNC( QWIDGET_RESTOREGEOMETRY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->restoreGeometry ( *par1 );
    hb_retl( b );
  }
}


/*
QByteArray saveGeometry () const
*/
HB_FUNC( QWIDGET_SAVEGEOMETRY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->saveGeometry (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
void scroll ( int dx, int dy )
*/
HB_FUNC( QWIDGET_SCROLL1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->scroll ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void scroll ( int dx, int dy, const QRect & r )
*/
HB_FUNC( QWIDGET_SCROLL2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QRect * par3 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->scroll ( par1, par2, *par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void scroll ( int dx, int dy )
//[2]void scroll ( int dx, int dy, const QRect & r )

HB_FUNC( QWIDGET_SCROLL )
{
  if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_SCROLL1 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISQRECT(3) )
  {
    HB_FUNC_EXEC( QWIDGET_SCROLL2 );
  }
}

/*
void setAcceptDrops ( bool on )
*/
HB_FUNC( QWIDGET_SETACCEPTDROPS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAcceptDrops ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAccessibleDescription ( const QString & description )
*/
HB_FUNC( QWIDGET_SETACCESSIBLEDESCRIPTION )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setAccessibleDescription ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAccessibleName ( const QString & name )
*/
HB_FUNC( QWIDGET_SETACCESSIBLENAME )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setAccessibleName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAttribute ( Qt::WidgetAttribute attribute, bool on = true )
*/
HB_FUNC( QWIDGET_SETATTRIBUTE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = ISNIL(2)? true : hb_parl(2);
    obj->setAttribute (  (Qt::WidgetAttribute) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAutoFillBackground ( bool enabled )
*/
HB_FUNC( QWIDGET_SETAUTOFILLBACKGROUND )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAutoFillBackground ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setBackgroundRole ( QPalette::ColorRole role )
*/
HB_FUNC( QWIDGET_SETBACKGROUNDROLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setBackgroundRole (  (QPalette::ColorRole) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setBaseSize ( const QSize & )
*/
HB_FUNC( QWIDGET_SETBASESIZE1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setBaseSize ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setBaseSize ( int basew, int baseh )
*/
HB_FUNC( QWIDGET_SETBASESIZE2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setBaseSize ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setBaseSize ( const QSize & )
//[2]void setBaseSize ( int basew, int baseh )

HB_FUNC( QWIDGET_SETBASESIZE )
{
  if( ISNUMPAR(1) && ISQSIZE(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETBASESIZE1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_SETBASESIZE2 );
  }
}

/*
void setContentsMargins ( int left, int top, int right, int bottom )
*/
HB_FUNC( QWIDGET_SETCONTENTSMARGINS1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    obj->setContentsMargins ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setContentsMargins ( const QMargins & margins )
*/
HB_FUNC( QWIDGET_SETCONTENTSMARGINS2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QMargins * par1 = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setContentsMargins ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setContentsMargins ( int left, int top, int right, int bottom )
//[2]void setContentsMargins ( const QMargins & margins )

HB_FUNC( QWIDGET_SETCONTENTSMARGINS )
{
  if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QWIDGET_SETCONTENTSMARGINS1 );
  }
  else if( ISNUMPAR(1) && ISQMARGINS(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETCONTENTSMARGINS2 );
  }
}

/*
void setContextMenuPolicy ( Qt::ContextMenuPolicy policy )
*/
HB_FUNC( QWIDGET_SETCONTEXTMENUPOLICY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setContextMenuPolicy (  (Qt::ContextMenuPolicy) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCursor ( const QCursor & )
*/
HB_FUNC( QWIDGET_SETCURSOR )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QCursor * par1 = (QCursor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCursor ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
void setFixedHeight ( int h )
*/
HB_FUNC( QWIDGET_SETFIXEDHEIGHT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFixedHeight ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFixedSize ( const QSize & s )
*/
HB_FUNC( QWIDGET_SETFIXEDSIZE1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setFixedSize ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFixedSize ( int w, int h )
*/
HB_FUNC( QWIDGET_SETFIXEDSIZE2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setFixedSize ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setFixedSize ( const QSize & s )
//[2]void setFixedSize ( int w, int h )

HB_FUNC( QWIDGET_SETFIXEDSIZE )
{
  if( ISNUMPAR(1) && ISQSIZE(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETFIXEDSIZE1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_SETFIXEDSIZE2 );
  }
}

/*
void setFixedWidth ( int w )
*/
HB_FUNC( QWIDGET_SETFIXEDWIDTH )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFixedWidth ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFocus ( Qt::FocusReason reason )
*/
HB_FUNC( QWIDGET_SETFOCUS1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFocus (  (Qt::FocusReason) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFocus ()
*/
HB_FUNC( QWIDGET_SETFOCUS2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->setFocus (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setFocus ( Qt::FocusReason reason )
//[2]void setFocus ()

HB_FUNC( QWIDGET_SETFOCUS )
{
  if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETFOCUS1 );
  }
  else if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QWIDGET_SETFOCUS2 );
  }
}

/*
void setFocusPolicy ( Qt::FocusPolicy policy )
*/
HB_FUNC( QWIDGET_SETFOCUSPOLICY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setFocusPolicy (  (Qt::FocusPolicy) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFocusProxy ( QWidget * w )
*/
HB_FUNC( QWIDGET_SETFOCUSPROXY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setFocusProxy ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFont ( const QFont & )
*/
HB_FUNC( QWIDGET_SETFONT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFont * par1 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setFont ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setForegroundRole ( QPalette::ColorRole role )
*/
HB_FUNC( QWIDGET_SETFOREGROUNDROLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setForegroundRole (  (QPalette::ColorRole) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setGeometry ( const QRect & )
*/
HB_FUNC( QWIDGET_SETGEOMETRY1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGeometry ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setGeometry ( int x, int y, int w, int h )
*/
HB_FUNC( QWIDGET_SETGEOMETRY2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    obj->setGeometry ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setGeometry ( const QRect & )
//[2]void setGeometry ( int x, int y, int w, int h )

HB_FUNC( QWIDGET_SETGEOMETRY )
{
  if( ISNUMPAR(1) && ISQRECT(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETGEOMETRY1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QWIDGET_SETGEOMETRY2 );
  }
}

/*
void setGraphicsEffect ( QGraphicsEffect * effect )
*/
HB_FUNC( QWIDGET_SETGRAPHICSEFFECT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QGraphicsEffect * par1 = (QGraphicsEffect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setGraphicsEffect ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setInputContext ( QInputContext * context )
*/
HB_FUNC( QWIDGET_SETINPUTCONTEXT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QInputContext * par1 = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setInputContext ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setInputMethodHints ( Qt::InputMethodHints hints )
*/
HB_FUNC( QWIDGET_SETINPUTMETHODHINTS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setInputMethodHints (  (Qt::InputMethodHints) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLayout ( QLayout * layout )
*/
HB_FUNC( QWIDGET_SETLAYOUT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLayout * par1 = (QLayout *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setLayout ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLayoutDirection ( Qt::LayoutDirection direction )
*/
HB_FUNC( QWIDGET_SETLAYOUTDIRECTION )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setLayoutDirection (  (Qt::LayoutDirection) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLocale ( const QLocale & locale )
*/
HB_FUNC( QWIDGET_SETLOCALE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QLocale * par1 = (QLocale *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setLocale ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMask ( const QBitmap & bitmap )
*/
HB_FUNC( QWIDGET_SETMASK1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QBitmap * par1 = (QBitmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setMask ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMask ( const QRegion & region )
*/
HB_FUNC( QWIDGET_SETMASK2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setMask ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setMask ( const QBitmap & bitmap )
//[2]void setMask ( const QRegion & region )

HB_FUNC( QWIDGET_SETMASK )
{
  if( ISNUMPAR(1) && ISQBITMAP(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETMASK1 );
  }
  else if( ISNUMPAR(1) && ISQREGION(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETMASK2 );
  }
}

/*
void setMaximumHeight ( int maxh )
*/
HB_FUNC( QWIDGET_SETMAXIMUMHEIGHT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMaximumHeight ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMaximumSize ( const QSize & )
*/
HB_FUNC( QWIDGET_SETMAXIMUMSIZE1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setMaximumSize ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMaximumSize ( int maxw, int maxh )
*/
HB_FUNC( QWIDGET_SETMAXIMUMSIZE2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setMaximumSize ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setMaximumSize ( const QSize & )
//[2]void setMaximumSize ( int maxw, int maxh )

HB_FUNC( QWIDGET_SETMAXIMUMSIZE )
{
  if( ISNUMPAR(1) && ISQSIZE(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETMAXIMUMSIZE1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_SETMAXIMUMSIZE2 );
  }
}

/*
void setMaximumWidth ( int maxw )
*/
HB_FUNC( QWIDGET_SETMAXIMUMWIDTH )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMaximumWidth ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMinimumHeight ( int minh )
*/
HB_FUNC( QWIDGET_SETMINIMUMHEIGHT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMinimumHeight ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMinimumSize ( const QSize & )
*/
HB_FUNC( QWIDGET_SETMINIMUMSIZE1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setMinimumSize ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMinimumSize ( int minw, int minh )
*/
HB_FUNC( QWIDGET_SETMINIMUMSIZE2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setMinimumSize ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setMinimumSize ( const QSize & )
//[2]void setMinimumSize ( int minw, int minh )

HB_FUNC( QWIDGET_SETMINIMUMSIZE )
{
  if( ISNUMPAR(1) && ISQSIZE(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETMINIMUMSIZE1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_SETMINIMUMSIZE2 );
  }
}

/*
void setMinimumWidth ( int minw )
*/
HB_FUNC( QWIDGET_SETMINIMUMWIDTH )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMinimumWidth ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMouseTracking ( bool enable )
*/
HB_FUNC( QWIDGET_SETMOUSETRACKING )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setMouseTracking ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPalette ( const QPalette & )
*/
HB_FUNC( QWIDGET_SETPALETTE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPalette * par1 = (QPalette *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setPalette ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setParent ( QWidget * parent )
*/
HB_FUNC( QWIDGET_SETPARENT1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setParent ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setParent ( QWidget * parent, Qt::WindowFlags f )
*/
HB_FUNC( QWIDGET_SETPARENT2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = hb_parni(2);
    obj->setParent ( par1,  (Qt::WindowFlags) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setParent ( QWidget * parent )
//[2]void setParent ( QWidget * parent, Qt::WindowFlags f )

HB_FUNC( QWIDGET_SETPARENT )
{
  if( ISNUMPAR(1) && ISQWIDGET(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETPARENT1 );
  }
  else if( ISNUMPAR(2) && ISQWIDGET(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_SETPARENT2 );
  }
}

/*
void setShortcutAutoRepeat ( int id, bool enable = true )
*/
HB_FUNC( QWIDGET_SETSHORTCUTAUTOREPEAT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = ISNIL(2)? true : hb_parl(2);
    obj->setShortcutAutoRepeat ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setShortcutEnabled ( int id, bool enable = true )
*/
HB_FUNC( QWIDGET_SETSHORTCUTENABLED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = ISNIL(2)? true : hb_parl(2);
    obj->setShortcutEnabled ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSizeIncrement ( const QSize & )
*/
HB_FUNC( QWIDGET_SETSIZEINCREMENT1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setSizeIncrement ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSizeIncrement ( int w, int h )
*/
HB_FUNC( QWIDGET_SETSIZEINCREMENT2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setSizeIncrement ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setSizeIncrement ( const QSize & )
//[2]void setSizeIncrement ( int w, int h )

HB_FUNC( QWIDGET_SETSIZEINCREMENT )
{
  if( ISNUMPAR(1) && ISQSIZE(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETSIZEINCREMENT1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_SETSIZEINCREMENT2 );
  }
}

/*
void setSizePolicy ( QSizePolicy & )
*/
HB_FUNC( QWIDGET_SETSIZEPOLICY1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSizePolicy * par1 = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setSizePolicy ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setSizePolicy ( QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical )
*/
HB_FUNC( QWIDGET_SETSIZEPOLICY2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->setSizePolicy (  (QSizePolicy::Policy) par1,  (QSizePolicy::Policy) par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setSizePolicy ( QSizePolicy & )
//[2]void setSizePolicy ( QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical )

HB_FUNC( QWIDGET_SETSIZEPOLICY )
{
  if( ISNUMPAR(1) && ISQSIZEPOLICY(1) )
  {
    HB_FUNC_EXEC( QWIDGET_SETSIZEPOLICY1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QWIDGET_SETSIZEPOLICY2 );
  }
}

/*
void setStatusTip ( const QString & )
*/
HB_FUNC( QWIDGET_SETSTATUSTIP )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setStatusTip ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStyle ( QStyle * style )
*/
HB_FUNC( QWIDGET_SETSTYLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStyle * par1 = (QStyle *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setStyle ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setToolTip ( const QString & )
*/
HB_FUNC( QWIDGET_SETTOOLTIP )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setToolTip ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUpdatesEnabled ( bool enable )
*/
HB_FUNC( QWIDGET_SETUPDATESENABLED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setUpdatesEnabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWhatsThis ( const QString & )
*/
HB_FUNC( QWIDGET_SETWHATSTHIS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setWhatsThis ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowFilePath ( const QString & filePath )
*/
HB_FUNC( QWIDGET_SETWINDOWFILEPATH )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setWindowFilePath ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowFlags ( Qt::WindowFlags type )
*/
HB_FUNC( QWIDGET_SETWINDOWFLAGS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setWindowFlags (  (Qt::WindowFlags) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowIcon ( const QIcon & icon )
*/
HB_FUNC( QWIDGET_SETWINDOWICON )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIcon par1 = ISOBJECT(1)? *(QIcon *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) ) : QIcon(hb_parc(1));
    obj->setWindowIcon ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowIconText ( const QString & )
*/
HB_FUNC( QWIDGET_SETWINDOWICONTEXT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setWindowIconText ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowModality ( Qt::WindowModality windowModality )
*/
HB_FUNC( QWIDGET_SETWINDOWMODALITY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setWindowModality (  (Qt::WindowModality) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowOpacity ( qreal level )
*/
HB_FUNC( QWIDGET_SETWINDOWOPACITY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setWindowOpacity ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowRole ( const QString & role )
*/
HB_FUNC( QWIDGET_SETWINDOWROLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setWindowRole ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowState ( Qt::WindowStates windowState )
*/
HB_FUNC( QWIDGET_SETWINDOWSTATE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setWindowState (  (Qt::WindowStates) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




/*
QSize size () const
*/
HB_FUNC( QWIDGET_SIZE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->size (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
virtual QSize sizeHint () const
*/
HB_FUNC( QWIDGET_SIZEHINT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->sizeHint (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
QSize sizeIncrement () const
*/
HB_FUNC( QWIDGET_SIZEINCREMENT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSize * ptr = new QSize( obj->sizeIncrement (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZE", true );  }
}


/*
QSizePolicy sizePolicy () const
*/
HB_FUNC( QWIDGET_SIZEPOLICY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSizePolicy * ptr = new QSizePolicy( obj->sizePolicy (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZEPOLICY", true );  }
}


/*
void stackUnder ( QWidget * w )
*/
HB_FUNC( QWIDGET_STACKUNDER )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->stackUnder ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString statusTip () const
*/
HB_FUNC( QWIDGET_STATUSTIP )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->statusTip (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QStyle * style () const
*/
HB_FUNC( QWIDGET_STYLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStyle * ptr = obj->style (  );
    _qt4xhb_createReturnClass ( ptr, "QSTYLE" );  }
}


/*
QString styleSheet () const
*/
HB_FUNC( QWIDGET_STYLESHEET )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->styleSheet (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
bool testAttribute ( Qt::WidgetAttribute attribute ) const
*/
HB_FUNC( QWIDGET_TESTATTRIBUTE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->testAttribute (  (Qt::WidgetAttribute) par1 );
    hb_retl( b );
  }
}


/*
QString toolTip () const
*/
HB_FUNC( QWIDGET_TOOLTIP )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->toolTip (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
bool underMouse () const
*/
HB_FUNC( QWIDGET_UNDERMOUSE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->underMouse (  );
    hb_retl( b );
  }
}


/*
void ungrabGesture ( Qt::GestureType gesture )
*/
HB_FUNC( QWIDGET_UNGRABGESTURE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->ungrabGesture (  (Qt::GestureType) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void unsetCursor ()
*/
HB_FUNC( QWIDGET_UNSETCURSOR )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->unsetCursor (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void unsetLayoutDirection ()
*/
HB_FUNC( QWIDGET_UNSETLAYOUTDIRECTION )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->unsetLayoutDirection (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void unsetLocale ()
*/
HB_FUNC( QWIDGET_UNSETLOCALE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->unsetLocale (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void update ( int x, int y, int w, int h )
*/
HB_FUNC( QWIDGET_UPDATE1 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = hb_parni(4);
    obj->update ( par1, par2, par3, par4 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void update ( const QRect & rect )
*/
HB_FUNC( QWIDGET_UPDATE2 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->update ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void update ( const QRegion & rgn )
*/
HB_FUNC( QWIDGET_UPDATE3 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->update ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void update ()
*/
HB_FUNC( QWIDGET_UPDATE4 )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->update (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void update ( int x, int y, int w, int h )
//[2]void update ( const QRect & rect )
//[3]void update ( const QRegion & rgn )
//[4]void update ()

HB_FUNC( QWIDGET_UPDATE )
{
  if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QWIDGET_UPDATE1 );
  }
  else if( ISNUMPAR(1) && ISQRECT(1) )
  {
    HB_FUNC_EXEC( QWIDGET_UPDATE2 );
  }
  else if( ISNUMPAR(1) && ISQREGION(1) )
  {
    HB_FUNC_EXEC( QWIDGET_UPDATE3 );
  }
  else if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QWIDGET_UPDATE4 );
  }
}

/*
void updateGeometry ()
*/
HB_FUNC( QWIDGET_UPDATEGEOMETRY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->updateGeometry (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool updatesEnabled () const
*/
HB_FUNC( QWIDGET_UPDATESENABLED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->updatesEnabled (  );
    hb_retl( b );
  }
}


/*
QRegion visibleRegion () const
*/
HB_FUNC( QWIDGET_VISIBLEREGION )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * ptr = new QRegion( obj->visibleRegion (  ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


/*
QString whatsThis () const
*/
HB_FUNC( QWIDGET_WHATSTHIS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->whatsThis (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
int width () const
*/
HB_FUNC( QWIDGET_WIDTH )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->width (  );
    hb_retni( i );
  }
}


/*
WId winId () const
*/
HB_FUNC( QWIDGET_WINID )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    WId r = obj->winId (  );
    hb_retptr( r );
  }
}


/*
QWidget * window () const
*/
HB_FUNC( QWIDGET_WINDOW )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->window (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
QString windowFilePath () const
*/
HB_FUNC( QWIDGET_WINDOWFILEPATH )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->windowFilePath (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
Qt::WindowFlags windowFlags () const
*/
HB_FUNC( QWIDGET_WINDOWFLAGS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->windowFlags (  );
    hb_retni( i );
  }
}


/*
QIcon windowIcon () const
*/
HB_FUNC( QWIDGET_WINDOWICON )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIcon * ptr = new QIcon( obj->windowIcon (  ) );
    _qt4xhb_createReturnClass ( ptr, "QICON", true );  }
}


/*
QString windowIconText () const
*/
HB_FUNC( QWIDGET_WINDOWICONTEXT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->windowIconText (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
Qt::WindowModality windowModality () const
*/
HB_FUNC( QWIDGET_WINDOWMODALITY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->windowModality (  );
    hb_retni( i );
  }
}


/*
qreal windowOpacity () const
*/
HB_FUNC( QWIDGET_WINDOWOPACITY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->windowOpacity (  );
    hb_retnd( r );
  }
}


/*
QString windowRole () const
*/
HB_FUNC( QWIDGET_WINDOWROLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->windowRole (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
Qt::WindowStates windowState () const
*/
HB_FUNC( QWIDGET_WINDOWSTATE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->windowState (  );
    hb_retni( i );
  }
}



/*
QString windowTitle () const
*/
HB_FUNC( QWIDGET_WINDOWTITLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->windowTitle (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
Qt::WindowType windowType () const
*/
HB_FUNC( QWIDGET_WINDOWTYPE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->windowType (  );
    hb_retni( i );
  }
}


/*
int x () const
*/
HB_FUNC( QWIDGET_X )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->x (  );
    hb_retni( i );
  }
}




/*
int y () const
*/
HB_FUNC( QWIDGET_Y )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->y (  );
    hb_retni( i );
  }
}



/*
virtual QPaintEngine * paintEngine () const
*/
HB_FUNC( QWIDGET_PAINTENGINE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPaintEngine * ptr = obj->paintEngine (  );
    _qt4xhb_createReturnClass ( ptr, "QPAINTENGINE" );  }
}



/*
bool close ()
*/
HB_FUNC( QWIDGET_CLOSE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->close (  );
    hb_retl( b );
  }
}


/*
void hide ()
*/
HB_FUNC( QWIDGET_HIDE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->hide (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void lower ()
*/
HB_FUNC( QWIDGET_LOWER )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->lower (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void raise ()
*/
HB_FUNC( QWIDGET_RAISE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->raise (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
void setDisabled ( bool disable )
*/
HB_FUNC( QWIDGET_SETDISABLED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setDisabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setEnabled ( bool )
*/
HB_FUNC( QWIDGET_SETENABLED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setEnabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHidden ( bool hidden )
*/
HB_FUNC( QWIDGET_SETHIDDEN )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setHidden ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStyleSheet ( const QString & styleSheet )
*/
HB_FUNC( QWIDGET_SETSTYLESHEET )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setStyleSheet ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setVisible ( bool visible )
*/
HB_FUNC( QWIDGET_SETVISIBLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setVisible ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowModified ( bool )
*/
HB_FUNC( QWIDGET_SETWINDOWMODIFIED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setWindowModified ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowTitle ( const QString & )
*/
HB_FUNC( QWIDGET_SETWINDOWTITLE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setWindowTitle ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void show ()
*/
HB_FUNC( QWIDGET_SHOW )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->show (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void showFullScreen ()
*/
HB_FUNC( QWIDGET_SHOWFULLSCREEN )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->showFullScreen (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void showMaximized ()
*/
HB_FUNC( QWIDGET_SHOWMAXIMIZED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->showMaximized (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void showMinimized ()
*/
HB_FUNC( QWIDGET_SHOWMINIMIZED )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->showMinimized (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void showNormal ()
*/
HB_FUNC( QWIDGET_SHOWNORMAL )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->showNormal (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



//=============================================================================
// QPaintDevice methods
//=============================================================================

/*
int colorCount () const
*/
HB_FUNC( QWIDGET_COLORCOUNT )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->colorCount (  );
    hb_retni( i );
  }
}


/*
int depth () const
*/
HB_FUNC( QWIDGET_DEPTH )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->depth (  );
    hb_retni( i );
  }
}



/*
int heightMM () const
*/
HB_FUNC( QWIDGET_HEIGHTMM )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->heightMM (  );
    hb_retni( i );
  }
}


/*
int logicalDpiX () const
*/
HB_FUNC( QWIDGET_LOGICALDPIX )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->logicalDpiX (  );
    hb_retni( i );
  }
}


/*
int logicalDpiY () const
*/
HB_FUNC( QWIDGET_LOGICALDPIY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->logicalDpiY (  );
    hb_retni( i );
  }
}


/*
int numColors () const (deprecated)
*/
HB_FUNC( QWIDGET_NUMCOLORS )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->numColors (  );
    hb_retni( i );
  }
}



/*
bool paintingActive () const
*/
HB_FUNC( QWIDGET_PAINTINGACTIVE )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->paintingActive (  );
    hb_retl( b );
  }
}


/*
int physicalDpiX () const
*/
HB_FUNC( QWIDGET_PHYSICALDPIX )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->physicalDpiX (  );
    hb_retni( i );
  }
}


/*
int physicalDpiY () const
*/
HB_FUNC( QWIDGET_PHYSICALDPIY )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->physicalDpiY (  );
    hb_retni( i );
  }
}



/*
int widthMM () const
*/
HB_FUNC( QWIDGET_WIDTHMM )
{
  QWidget * obj = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->widthMM (  );
    hb_retni( i );
  }
}


//=============================================================================
// QPaindDevice Methods
//=============================================================================


/*
QWidget * find ( WId id )
*/
HB_FUNC( QWIDGET_FIND )
{
  WId par1 = (WId) hb_parptr(1);
  QWidget * ptr = QWidget::find ( par1 );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


/*
QWidget * keyboardGrabber ()
*/
HB_FUNC( QWIDGET_KEYBOARDGRABBER )
{
  QWidget * ptr = QWidget::keyboardGrabber (  );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


/*
QWidget * mouseGrabber ()
*/
HB_FUNC( QWIDGET_MOUSEGRABBER )
{
  QWidget * ptr = QWidget::mouseGrabber (  );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


/*
void setTabOrder ( QWidget * first, QWidget * second )
*/
HB_FUNC( QWIDGET_SETTABORDER )
{
  QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * par2 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget::setTabOrder ( par1, par2 );
  hb_itemReturn( hb_stackSelfItem() );
}




