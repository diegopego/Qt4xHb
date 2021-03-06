/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QWebView>

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


#include <QWidget>
#include <QUrl>

/*
QWebView ( QWidget * parent = 0 )
*/
HB_FUNC( QWEBVIEW_NEW )
{
  QWebView * o = NULL;
  QWidget * par1 = ISNIL(1)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QWebView ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QWebView *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QWEBVIEW_DELETE )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool findText ( const QString & subString, QWebPage::FindFlags options = 0 )
*/
HB_FUNC( QWEBVIEW_FINDTEXT )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = ISNIL(2)? (int) 0 : hb_parni(2);
    bool b = obj->findText ( par1,  (QWebPage::FindFlags) par2 );
    hb_retl( b );
  }
}


/*
QWebHistory * history () const
*/
HB_FUNC( QWEBVIEW_HISTORY )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebHistory * ptr = obj->history (  );
    _qt4xhb_createReturnClass ( ptr, "QWEBHISTORY" );  }
}


/*
QIcon icon () const
*/
HB_FUNC( QWEBVIEW_ICON )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIcon * ptr = new QIcon( obj->icon (  ) );
    _qt4xhb_createReturnClass ( ptr, "QICON", true );  }
}


/*
bool isModified () const
*/
HB_FUNC( QWEBVIEW_ISMODIFIED )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isModified (  );
    hb_retl( b );
  }
}


/*
void load ( const QUrl & url )
*/
HB_FUNC( QWEBVIEW_LOAD1 )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * par1 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->load ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void load ( const QNetworkRequest & request, QNetworkAccessManager::Operation operation = QNetworkAccessManager::GetOperation, const QByteArray & body = QByteArray() )
*/
HB_FUNC( QWEBVIEW_LOAD2 )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QNetworkRequest * par1 = (QNetworkRequest *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? (int) QNetworkAccessManager::GetOperation : hb_parni(2);
    QByteArray par3 = ISNIL(3)? QByteArray() : *(QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->load ( *par1,  (QNetworkAccessManager::Operation) par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void load ( const QUrl & url )
//[2]void load ( const QNetworkRequest & request, QNetworkAccessManager::Operation operation = QNetworkAccessManager::GetOperation, const QByteArray & body = QByteArray() )

HB_FUNC( QWEBVIEW_LOAD )
{
  if( ISNUMPAR(1) && ISQURL(1) )
  {
    HB_FUNC_EXEC( QWEBVIEW_LOAD1 );
  }
  else if( ISBETWEEN(1,3) && ISQNETWORKREQUEST(1) && (ISNUM(2)||ISNIL(2)) && (ISQBYTEARRAY(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QWEBVIEW_LOAD2 );
  }
}

/*
QWebPage * page () const
*/
HB_FUNC( QWEBVIEW_PAGE )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebPage * ptr = obj->page (  );
    _qt4xhb_createReturnClass ( ptr, "QWEBPAGE" );  }
}


/*
QAction * pageAction ( QWebPage::WebAction action ) const
*/
HB_FUNC( QWEBVIEW_PAGEACTION )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QAction * ptr = obj->pageAction (  (QWebPage::WebAction) par1 );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
QPainter::RenderHints renderHints () const
*/
HB_FUNC( QWEBVIEW_RENDERHINTS )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->renderHints (  );
    hb_retni( i );
  }
}


/*
QString selectedText () const
*/
HB_FUNC( QWEBVIEW_SELECTEDTEXT )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->selectedText (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void setContent ( const QByteArray & data, const QString & mimeType = QString(), const QUrl & baseUrl = QUrl() )
*/
HB_FUNC( QWEBVIEW_SETCONTENT )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    QUrl par3 = ISNIL(3)? QUrl() : *(QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setContent ( *par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHtml ( const QString & html, const QUrl & baseUrl = QUrl() )
*/
HB_FUNC( QWEBVIEW_SETHTML )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QUrl par2 = ISNIL(2)? QUrl() : *(QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setHtml ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPage ( QWebPage * page )
*/
HB_FUNC( QWEBVIEW_SETPAGE )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebPage * par1 = (QWebPage *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setPage ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRenderHint ( QPainter::RenderHint hint, bool enabled = true )
*/
HB_FUNC( QWEBVIEW_SETRENDERHINT )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = ISNIL(2)? true : hb_parl(2);
    obj->setRenderHint (  (QPainter::RenderHint) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRenderHints ( QPainter::RenderHints hints )
*/
HB_FUNC( QWEBVIEW_SETRENDERHINTS )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setRenderHints (  (QPainter::RenderHints) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTextSizeMultiplier ( qreal factor )
*/
HB_FUNC( QWEBVIEW_SETTEXTSIZEMULTIPLIER )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setTextSizeMultiplier ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUrl ( const QUrl & url )
*/
HB_FUNC( QWEBVIEW_SETURL )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * par1 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setUrl ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setZoomFactor ( qreal factor )
*/
HB_FUNC( QWEBVIEW_SETZOOMFACTOR )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setZoomFactor ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWebSettings * settings () const
*/
HB_FUNC( QWEBVIEW_SETTINGS )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebSettings * ptr = obj->settings (  );
    _qt4xhb_createReturnClass ( ptr, "QWEBSETTINGS" );  }
}


/*
qreal textSizeMultiplier () const
*/
HB_FUNC( QWEBVIEW_TEXTSIZEMULTIPLIER )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->textSizeMultiplier (  );
    hb_retnd( r );
  }
}


/*
QString title () const
*/
HB_FUNC( QWEBVIEW_TITLE )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->title (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void triggerPageAction ( QWebPage::WebAction action, bool checked = false )
*/
HB_FUNC( QWEBVIEW_TRIGGERPAGEACTION )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = ISNIL(2)? false : hb_parl(2);
    obj->triggerPageAction (  (QWebPage::WebAction) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QUrl url () const
*/
HB_FUNC( QWEBVIEW_URL )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * ptr = new QUrl( obj->url (  ) );
    _qt4xhb_createReturnClass ( ptr, "QURL", true );  }
}


/*
qreal zoomFactor () const
*/
HB_FUNC( QWEBVIEW_ZOOMFACTOR )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->zoomFactor (  );
    hb_retnd( r );
  }
}


/*
void back ()
*/
HB_FUNC( QWEBVIEW_BACK )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->back (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void forward ()
*/
HB_FUNC( QWEBVIEW_FORWARD )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->forward (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void print ( QPrinter * printer ) const
*/
HB_FUNC( QWEBVIEW_PRINT )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPrinter * par1 = (QPrinter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->print ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void reload ()
*/
HB_FUNC( QWEBVIEW_RELOAD )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->reload (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void stop ()
*/
HB_FUNC( QWEBVIEW_STOP )
{
  QWebView * obj = (QWebView *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->stop (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//Signals
//void iconChanged ()
//void linkClicked ( const QUrl & url )
//void loadFinished ( bool ok )
//void loadProgress ( int progress )
//void loadStarted ()
//void selectionChanged ()
//void statusBarMessage ( const QString & text )
//void titleChanged ( const QString & title )
//void urlChanged ( const QUrl & url )



