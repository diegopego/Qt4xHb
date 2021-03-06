/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QApplication>

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

#include <QFont>
#include <QLocale>
#include <QIcon>
#include <QSessionManager>
#include <QFontMetrics>
#include <QPalette>

//QApplication ( int & argc, char ** argv )
//QApplication ( int & argc, char ** argv, bool GUIenabled )
//QApplication ( int & argc, char ** argv, Type type )
//QApplication ( Display * display, Qt::HANDLE visual = 0, Qt::HANDLE colormap = 0 )
//QApplication ( Display * display, int & argc, char ** argv, Qt::HANDLE visual = 0, Qt::HANDLE colormap = 0 )
//QApplication ( QApplication::QS60MainApplicationFactory factory, int & argc, char ** argv )

/*
QApplication ( int & argc, char ** argv )
*/
HB_FUNC( QAPPLICATION_NEW )
{
  int argc;
  char ** argv;
  argc = hb_cmdargARGC();
  argv = hb_cmdargARGV();
  QApplication * o = NULL;
  o = new QApplication( argc, argv );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,   (QApplication *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}

HB_FUNC( QAPPLICATION_DELETE )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual void commitData ( QSessionManager & manager )
*/
HB_FUNC( QAPPLICATION_COMMITDATA )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSessionManager * par1 = (QSessionManager *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->commitData ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QInputContext * inputContext () const
*/
HB_FUNC( QAPPLICATION_INPUTCONTEXT )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QInputContext * ptr = obj->inputContext (  );
    _qt4xhb_createReturnClass ( ptr, "QINPUTCONTEXT" );  }
}


/*
bool isSessionRestored () const
*/
HB_FUNC( QAPPLICATION_ISSESSIONRESTORED )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSessionRestored (  );
    hb_retl( b );
  }
}





/*
virtual void saveState ( QSessionManager & manager )
*/
HB_FUNC( QAPPLICATION_SAVESTATE )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSessionManager * par1 = (QSessionManager *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->saveState ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString sessionId () const
*/
HB_FUNC( QAPPLICATION_SESSIONID )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->sessionId (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString sessionKey () const
*/
HB_FUNC( QAPPLICATION_SESSIONKEY )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->sessionKey (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void setInputContext ( QInputContext * inputContext )
*/
HB_FUNC( QAPPLICATION_SETINPUTCONTEXT )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QInputContext * par1 = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setInputContext ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString styleSheet () const
*/
HB_FUNC( QAPPLICATION_STYLESHEET )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->styleSheet (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}






// Reimplemented Public Functions

/*
virtual bool notify ( QObject * receiver, QEvent * e )
*/
HB_FUNC( QAPPLICATION_NOTIFY )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QEvent * par2 = (QEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->notify ( par1, par2 );
    hb_retl( b );
  }
}


// Public Slots

/*
void aboutQt ()
*/
HB_FUNC( QAPPLICATION_ABOUTQT )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->aboutQt (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




/*
void closeAllWindows ()
*/
HB_FUNC( QAPPLICATION_CLOSEALLWINDOWS )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->closeAllWindows (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




/*
void setStyleSheet ( const QString & sheet )
*/
HB_FUNC( QAPPLICATION_SETSTYLESHEET )
{
  QApplication * obj = (QApplication *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setStyleSheet ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



// Static Public Members

/*
QWidget * activeModalWidget ()
*/
HB_FUNC( QAPPLICATION_ACTIVEMODALWIDGET )
{
  QWidget * ptr = QApplication::activeModalWidget (  );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


/*
QWidget * activePopupWidget ()
*/
HB_FUNC( QAPPLICATION_ACTIVEPOPUPWIDGET )
{
  QWidget * ptr = QApplication::activePopupWidget (  );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


/*
QWidget * activeWindow ()
*/
HB_FUNC( QAPPLICATION_ACTIVEWINDOW )
{
  QWidget * ptr = QApplication::activeWindow (  );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


/*
void alert ( QWidget * widget, int msec = 0 )
*/
HB_FUNC( QAPPLICATION_ALERT )
{
  QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? 0 : hb_parni(2);
  QApplication::alert ( par1, par2 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWidgetList allWidgets ()
*/
HB_FUNC( QAPPLICATION_ALLWIDGETS )
{
  QWidgetList list = QApplication::allWidgets (  );
  PHB_DYNS pDynSym;
  #ifdef __XHARBOUR__
  pDynSym = hb_dynsymFind( "QWIDGET" );
  #else
  pDynSym = hb_dynsymFindName( "QWIDGET" );
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
      hb_itemPutPtr( pItem, (QWidget *) list[i] );
      hb_objSendMsg( pObject, "_POINTER", 1, pItem );
      hb_arrayAddForward( pArray, pObject );
      hb_itemRelease( pObject );
      hb_itemRelease( pItem );
    }
  }
  hb_itemReturnRelease(pArray);
}


/*
void beep ()
*/
HB_FUNC( QAPPLICATION_BEEP )
{
  QApplication::beep (  );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void changeOverrideCursor ( const QCursor & cursor )
*/
HB_FUNC( QAPPLICATION_CHANGEOVERRIDECURSOR )
{
  QCursor * par1 = (QCursor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QApplication::changeOverrideCursor ( *par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QClipboard * clipboard ()
*/
HB_FUNC( QAPPLICATION_CLIPBOARD )
{
  QClipboard * ptr = QApplication::clipboard (  );
  _qt4xhb_createReturnClass ( ptr, "QCLIPBOARD" );}


/*
int colorSpec ()
*/
HB_FUNC( QAPPLICATION_COLORSPEC )
{
  int i = QApplication::colorSpec (  );
  hb_retni( i );
}


/*
int cursorFlashTime ()
*/
HB_FUNC( QAPPLICATION_CURSORFLASHTIME )
{
  int i = QApplication::cursorFlashTime (  );
  hb_retni( i );
}


/*
QDesktopWidget * desktop ()
*/
HB_FUNC( QAPPLICATION_DESKTOP )
{
  QDesktopWidget * ptr = QApplication::desktop (  );
  _qt4xhb_createReturnClass ( ptr, "QDESKTOPWIDGET" );}


/*
bool desktopSettingsAware ()
*/
HB_FUNC( QAPPLICATION_DESKTOPSETTINGSAWARE )
{
  bool b = QApplication::desktopSettingsAware (  );
  hb_retl( b );
}


/*
int doubleClickInterval ()
*/
HB_FUNC( QAPPLICATION_DOUBLECLICKINTERVAL )
{
  int i = QApplication::doubleClickInterval (  );
  hb_retni( i );
}


/*
int exec ()
*/
HB_FUNC( QAPPLICATION_EXEC )
{
  int i = QApplication::exec (  );
  hb_retni( i );
}


/*
QWidget * focusWidget ()
*/
HB_FUNC( QAPPLICATION_FOCUSWIDGET )
{
  QWidget * ptr = QApplication::focusWidget (  );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


/*
QFont font ()
*/
HB_FUNC( QAPPLICATION_FONT1 )
{
  QFont * ptr = new QFont( QApplication::font (  ) );
  _qt4xhb_createReturnClass ( ptr, "QFONT", true );}


/*
QFont font ( const QWidget * widget )
*/
HB_FUNC( QAPPLICATION_FONT2 )
{
  QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QFont * ptr = new QFont( QApplication::font ( par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QFONT", true );}


/*
QFont font ( const char * className )
*/
HB_FUNC( QAPPLICATION_FONT3 )
{
  const char * par1 = hb_parc(1);
  QFont * ptr = new QFont( QApplication::font (  (const char *) par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QFONT", true );}


//[1]QFont font ()
//[2]QFont font ( const QWidget * widget )
//[3]QFont font ( const char * className )

HB_FUNC( QAPPLICATION_FONT )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QAPPLICATION_FONT1 );
  }
  else if( ISNUMPAR(1) && ISQWIDGET(1) )
  {
    HB_FUNC_EXEC( QAPPLICATION_FONT2 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QAPPLICATION_FONT3 );
  }
}

/*
QFontMetrics fontMetrics ()
*/
HB_FUNC( QAPPLICATION_FONTMETRICS )
{
  QFontMetrics * ptr = new QFontMetrics( QApplication::fontMetrics (  ) );
  _qt4xhb_createReturnClass ( ptr, "QFONTMETRICS", true );}


/*
QSize globalStrut ()
*/
HB_FUNC( QAPPLICATION_GLOBALSTRUT )
{
  QSize * ptr = new QSize( QApplication::globalStrut (  ) );
  _qt4xhb_createReturnClass ( ptr, "QSIZE", true );}


/*
bool isEffectEnabled ( Qt::UIEffect effect )
*/
HB_FUNC( QAPPLICATION_ISEFFECTENABLED )
{
  int par1 = hb_parni(1);
  bool b = QApplication::isEffectEnabled (  (Qt::UIEffect) par1 );
  hb_retl( b );
}


/*
bool isLeftToRight ()
*/
HB_FUNC( QAPPLICATION_ISLEFTTORIGHT )
{
  bool b = QApplication::isLeftToRight (  );
  hb_retl( b );
}


/*
bool isRightToLeft ()
*/
HB_FUNC( QAPPLICATION_ISRIGHTTOLEFT )
{
  bool b = QApplication::isRightToLeft (  );
  hb_retl( b );
}


/*
Qt::LayoutDirection keyboardInputDirection ()
*/
HB_FUNC( QAPPLICATION_KEYBOARDINPUTDIRECTION )
{
  int i = QApplication::keyboardInputDirection (  );
  hb_retni( i );
}


/*
int keyboardInputInterval ()
*/
HB_FUNC( QAPPLICATION_KEYBOARDINPUTINTERVAL )
{
  int i = QApplication::keyboardInputInterval (  );
  hb_retni( i );
}


/*
QLocale keyboardInputLocale ()
*/
HB_FUNC( QAPPLICATION_KEYBOARDINPUTLOCALE )
{
  QLocale * ptr = new QLocale( QApplication::keyboardInputLocale (  ) );
  _qt4xhb_createReturnClass ( ptr, "QLOCALE" );}


/*
Qt::KeyboardModifiers keyboardModifiers ()
*/
HB_FUNC( QAPPLICATION_KEYBOARDMODIFIERS )
{
  int i = QApplication::keyboardModifiers (  );
  hb_retni( i );
}



/*
Qt::LayoutDirection layoutDirection ()
*/
HB_FUNC( QAPPLICATION_LAYOUTDIRECTION )
{
  int i = QApplication::layoutDirection (  );
  hb_retni( i );
}


/*
Qt::MouseButtons mouseButtons ()
*/
HB_FUNC( QAPPLICATION_MOUSEBUTTONS )
{
  int i = QApplication::mouseButtons (  );
  hb_retni( i );
}



/*
QCursor * overrideCursor ()
*/
HB_FUNC( QAPPLICATION_OVERRIDECURSOR )
{
  QCursor * ptr = QApplication::overrideCursor (  );
  _qt4xhb_createReturnClass ( ptr, "QCURSOR" );}


/*
QPalette palette ()
*/
HB_FUNC( QAPPLICATION_PALETTE1 )
{
  QPalette * ptr = new QPalette( QApplication::palette (  ) );
  _qt4xhb_createReturnClass ( ptr, "QPALETTE", true );}


/*
QPalette palette ( const QWidget * widget )
*/
HB_FUNC( QAPPLICATION_PALETTE2 )
{
  QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QPalette * ptr = new QPalette( QApplication::palette ( par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QPALETTE", true );}


/*
QPalette palette ( const char * className )
*/
HB_FUNC( QAPPLICATION_PALETTE3 )
{
  const char * par1 = hb_parc(1);
  QPalette * ptr = new QPalette( QApplication::palette (  (const char *) par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QPALETTE", true );}


//[1]QPalette palette ()
//[2]QPalette palette ( const QWidget * widget )
//[3]QPalette palette ( const char * className )

HB_FUNC( QAPPLICATION_PALETTE )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QAPPLICATION_PALETTE1 );
  }
  else if( ISNUMPAR(1) && ISQWIDGET(1) )
  {
    HB_FUNC_EXEC( QAPPLICATION_PALETTE2 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QAPPLICATION_PALETTE3 );
  }
}

/*
Qt::KeyboardModifiers queryKeyboardModifiers ()
*/
HB_FUNC( QAPPLICATION_QUERYKEYBOARDMODIFIERS )
{
  int i = QApplication::queryKeyboardModifiers (  );
  hb_retni( i );
}


/*
bool quitOnLastWindowClosed ()
*/
HB_FUNC( QAPPLICATION_QUITONLASTWINDOWCLOSED )
{
  bool b = QApplication::quitOnLastWindowClosed (  );
  hb_retl( b );
}





/*
void restoreOverrideCursor ()
*/
HB_FUNC( QAPPLICATION_RESTOREOVERRIDECURSOR )
{
  QApplication::restoreOverrideCursor (  );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setActiveWindow ( QWidget * active )
*/
HB_FUNC( QAPPLICATION_SETACTIVEWINDOW )
{
  QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QApplication::setActiveWindow ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setColorSpec ( int spec )
*/
HB_FUNC( QAPPLICATION_SETCOLORSPEC )
{
  int par1 = hb_parni(1);
  QApplication::setColorSpec ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCursorFlashTime ( int )
*/
HB_FUNC( QAPPLICATION_SETCURSORFLASHTIME )
{
  int par1 = hb_parni(1);
  QApplication::setCursorFlashTime ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDesktopSettingsAware ( bool on )
*/
HB_FUNC( QAPPLICATION_SETDESKTOPSETTINGSAWARE )
{
  bool par1 = hb_parl(1);
  QApplication::setDesktopSettingsAware ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDoubleClickInterval ( int )
*/
HB_FUNC( QAPPLICATION_SETDOUBLECLICKINTERVAL )
{
  int par1 = hb_parni(1);
  QApplication::setDoubleClickInterval ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setEffectEnabled ( Qt::UIEffect effect, bool enable = true )
*/
HB_FUNC( QAPPLICATION_SETEFFECTENABLED )
{
  int par1 = hb_parni(1);
  bool par2 = ISNIL(2)? true : hb_parl(2);
  QApplication::setEffectEnabled (  (Qt::UIEffect) par1, par2 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFont ( const QFont & font, const char * className = 0 )
*/
HB_FUNC( QAPPLICATION_SETFONT )
{
  QFont * par1 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  const char * par2 = ISNIL(2)? 0 : hb_parc(2);
  QApplication::setFont ( *par1,  (const char *) par2 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setGlobalStrut ( const QSize & )
*/
HB_FUNC( QAPPLICATION_SETGLOBALSTRUT )
{
  QSize * par1 = (QSize *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QApplication::setGlobalStrut ( *par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setGraphicsSystem ( const QString & system )
*/
HB_FUNC( QAPPLICATION_SETGRAPHICSSYSTEM )
{
  QString par1 = hb_parc(1);
  QApplication::setGraphicsSystem ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setKeyboardInputInterval ( int )
*/
HB_FUNC( QAPPLICATION_SETKEYBOARDINPUTINTERVAL )
{
  int par1 = hb_parni(1);
  QApplication::setKeyboardInputInterval ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLayoutDirection ( Qt::LayoutDirection direction )
*/
HB_FUNC( QAPPLICATION_SETLAYOUTDIRECTION )
{
  int par1 = hb_parni(1);
  QApplication::setLayoutDirection (  (Qt::LayoutDirection) par1 );
  hb_itemReturn( hb_stackSelfItem() );
}



/*
void setOverrideCursor ( const QCursor & cursor )
*/
HB_FUNC( QAPPLICATION_SETOVERRIDECURSOR )
{
  QCursor * par1 = (QCursor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QApplication::setOverrideCursor ( *par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPalette ( const QPalette & palette, const char * className = 0 )
*/
HB_FUNC( QAPPLICATION_SETPALETTE )
{
  QPalette * par1 = (QPalette *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  const char * par2 = ISNIL(2)? 0 : hb_parc(2);
  QApplication::setPalette ( *par1,  (const char *) par2 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setQuitOnLastWindowClosed ( bool quit )
*/
HB_FUNC( QAPPLICATION_SETQUITONLASTWINDOWCLOSED )
{
  bool par1 = hb_parl(1);
  QApplication::setQuitOnLastWindowClosed ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStartDragDistance ( int l )
*/
HB_FUNC( QAPPLICATION_SETSTARTDRAGDISTANCE )
{
  int par1 = hb_parni(1);
  QApplication::setStartDragDistance ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStartDragTime ( int ms )
*/
HB_FUNC( QAPPLICATION_SETSTARTDRAGTIME )
{
  int par1 = hb_parni(1);
  QApplication::setStartDragTime ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStyle ( QStyle * style )
*/
HB_FUNC( QAPPLICATION_SETSTYLE1 )
{
  QStyle * par1 = (QStyle *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QApplication::setStyle ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QStyle * setStyle ( const QString & style )
*/
HB_FUNC( QAPPLICATION_SETSTYLE2 )
{
  QString par1 = hb_parc(1);
  QStyle * ptr = QApplication::setStyle ( par1 );
  _qt4xhb_createReturnClass ( ptr, "QSTYLE" );}


//[1]void setStyle ( QStyle * style )
//[2]QStyle * setStyle ( const QString & style )

HB_FUNC( QAPPLICATION_SETSTYLE )
{
  if( ISNUMPAR(1) && ISQSTYLE(1) )
  {
    HB_FUNC_EXEC( QAPPLICATION_SETSTYLE1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QAPPLICATION_SETSTYLE2 );
  }
}

/*
void setWheelScrollLines ( int )
*/
HB_FUNC( QAPPLICATION_SETWHEELSCROLLLINES )
{
  int par1 = hb_parni(1);
  QApplication::setWheelScrollLines ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWindowIcon ( const QIcon & icon )
*/
HB_FUNC( QAPPLICATION_SETWINDOWICON )
{
  QIcon par1 = ISOBJECT(1)? *(QIcon *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) ) : QIcon(hb_parc(1));
  QApplication::setWindowIcon ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int startDragDistance ()
*/
HB_FUNC( QAPPLICATION_STARTDRAGDISTANCE )
{
  int i = QApplication::startDragDistance (  );
  hb_retni( i );
}


/*
int startDragTime ()
*/
HB_FUNC( QAPPLICATION_STARTDRAGTIME )
{
  int i = QApplication::startDragTime (  );
  hb_retni( i );
}


/*
QStyle * style ()
*/
HB_FUNC( QAPPLICATION_STYLE )
{
  QStyle * ptr = QApplication::style (  );
  _qt4xhb_createReturnClass ( ptr, "QSTYLE" );}


/*
void syncX ()
*/
HB_FUNC( QAPPLICATION_SYNCX )
{
  QApplication::syncX (  );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWidget * topLevelAt ( const QPoint & point )
*/
HB_FUNC( QAPPLICATION_TOPLEVELAT1 )
{
  QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * ptr = QApplication::topLevelAt ( *par1 );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


/*
QWidget * topLevelAt ( int x, int y )
*/
HB_FUNC( QAPPLICATION_TOPLEVELAT2 )
{
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  QWidget * ptr = QApplication::topLevelAt ( par1, par2 );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


//[1]QWidget * topLevelAt ( const QPoint & point )
//[2]QWidget * topLevelAt ( int x, int y )

HB_FUNC( QAPPLICATION_TOPLEVELAT )
{
  if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QAPPLICATION_TOPLEVELAT1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QAPPLICATION_TOPLEVELAT2 );
  }
}

/*
QWidgetList topLevelWidgets ()
*/
HB_FUNC( QAPPLICATION_TOPLEVELWIDGETS )
{
  QWidgetList list = QApplication::topLevelWidgets (  );
  PHB_DYNS pDynSym;
  #ifdef __XHARBOUR__
  pDynSym = hb_dynsymFind( "QWIDGET" );
  #else
  pDynSym = hb_dynsymFindName( "QWIDGET" );
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
      hb_itemPutPtr( pItem, (QWidget *) list[i] );
      hb_objSendMsg( pObject, "_POINTER", 1, pItem );
      hb_arrayAddForward( pArray, pObject );
      hb_itemRelease( pObject );
      hb_itemRelease( pItem );
    }
  }
  hb_itemReturnRelease(pArray);
}


/*
QApplication::Type type ()
*/
HB_FUNC( QAPPLICATION_TYPE )
{
  int i = QApplication::type (  );
  hb_retni( i );
}


/*
int wheelScrollLines ()
*/
HB_FUNC( QAPPLICATION_WHEELSCROLLLINES )
{
  int i = QApplication::wheelScrollLines (  );
  hb_retni( i );
}


/*
QWidget * widgetAt ( const QPoint & point )
*/
HB_FUNC( QAPPLICATION_WIDGETAT1 )
{
  QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QWidget * ptr = QApplication::widgetAt ( *par1 );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


/*
QWidget * widgetAt ( int x, int y )
*/
HB_FUNC( QAPPLICATION_WIDGETAT2 )
{
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  QWidget * ptr = QApplication::widgetAt ( par1, par2 );
  _qt4xhb_createReturnClass ( ptr, "QWIDGET" );}


//[1]QWidget * widgetAt ( const QPoint & point )
//[2]QWidget * widgetAt ( int x, int y )

HB_FUNC( QAPPLICATION_WIDGETAT )
{
  if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QAPPLICATION_WIDGETAT1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QAPPLICATION_WIDGETAT2 );
  }
}

/*
QIcon windowIcon ()
*/
HB_FUNC( QAPPLICATION_WINDOWICON )
{
  QIcon * ptr = new QIcon( QApplication::windowIcon (  ) );
  _qt4xhb_createReturnClass ( ptr, "QICON", true );}


// Signals



