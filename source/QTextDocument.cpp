/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTextDocument>

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

#include <QTextBlock>
#include <QTextOption>
#include <QTextCursor>
#include <QVariant>

/*
QTextDocument ( QObject * parent = 0 )
*/
HB_FUNC( QTEXTDOCUMENT_NEW1 )
{
  QTextDocument * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QTextDocument ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTextDocument *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QTextDocument ( const QString & text, QObject * parent = 0 )
*/
HB_FUNC( QTEXTDOCUMENT_NEW2 )
{
  QTextDocument * o = NULL;
  QString par1 = hb_parc(1);
  QObject * par2 = ISNIL(2)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QTextDocument ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTextDocument *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QTextDocument ( QObject * parent = 0 )
//[2]QTextDocument ( const QString & text, QObject * parent = 0 )

HB_FUNC( QTEXTDOCUMENT_NEW )
{
  if( ISBETWEEN(0,1) && (ISQOBJECT(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QTEXTDOCUMENT_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISCHAR(1) && (ISQOBJECT(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QTEXTDOCUMENT_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QTEXTDOCUMENT_DELETE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void addResource ( int type, const QUrl & name, const QVariant & resource )
*/
HB_FUNC( QTEXTDOCUMENT_ADDRESOURCE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QUrl * par2 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant * par3 = (QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->addResource ( par1, *par2, *par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void adjustSize ()
*/
HB_FUNC( QTEXTDOCUMENT_ADJUSTSIZE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->adjustSize (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QVector<QTextFormat> allFormats () const
*/
HB_FUNC( QTEXTDOCUMENT_ALLFORMATS )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector<QTextFormat> list = obj->allFormats (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QTEXTFORMAT" );
    #else
    pDynSym = hb_dynsymFindName( "QTEXTFORMAT" );
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
        hb_itemPutPtr( pItem, (QTextFormat *) new QTextFormat ( list[i] ) );
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
int availableRedoSteps () const
*/
HB_FUNC( QTEXTDOCUMENT_AVAILABLEREDOSTEPS )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->availableRedoSteps (  );
    hb_retni( i );
  }
}


/*
int availableUndoSteps () const
*/
HB_FUNC( QTEXTDOCUMENT_AVAILABLEUNDOSTEPS )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->availableUndoSteps (  );
    hb_retni( i );
  }
}


/*
QTextBlock begin () const
*/
HB_FUNC( QTEXTDOCUMENT_BEGIN )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlock * ptr = new QTextBlock( obj->begin (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCK" );  }
}


/*
int blockCount () const
*/
HB_FUNC( QTEXTDOCUMENT_BLOCKCOUNT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->blockCount (  );
    hb_retni( i );
  }
}


/*
QChar characterAt ( int pos ) const
*/
HB_FUNC( QTEXTDOCUMENT_CHARACTERAT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QChar * ptr = new QChar( obj->characterAt ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QCHAR" );  }
}


/*
int characterCount () const
*/
HB_FUNC( QTEXTDOCUMENT_CHARACTERCOUNT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->characterCount (  );
    hb_retni( i );
  }
}


/*
virtual void clear ()
*/
HB_FUNC( QTEXTDOCUMENT_CLEAR )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void clearUndoRedoStacks ( Stacks stacksToClear = UndoAndRedoStacks )
*/
HB_FUNC( QTEXTDOCUMENT_CLEARUNDOREDOSTACKS )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) QTextDocument::UndoAndRedoStacks : hb_parni(1);
    obj->clearUndoRedoStacks (  (QTextDocument::Stacks) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QTextDocument * clone ( QObject * parent = 0 ) const
*/
HB_FUNC( QTEXTDOCUMENT_CLONE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QTextDocument * ptr = obj->clone ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTEXTDOCUMENT" );  }
}


/*
Qt::CursorMoveStyle defaultCursorMoveStyle () const
*/
HB_FUNC( QTEXTDOCUMENT_DEFAULTCURSORMOVESTYLE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->defaultCursorMoveStyle (  );
    hb_retni( i );
  }
}


/*
QFont defaultFont () const
*/
HB_FUNC( QTEXTDOCUMENT_DEFAULTFONT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFont * ptr = new QFont( obj->defaultFont (  ) );
    _qt4xhb_createReturnClass ( ptr, "QFONT", true );  }
}


/*
QString defaultStyleSheet () const
*/
HB_FUNC( QTEXTDOCUMENT_DEFAULTSTYLESHEET )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->defaultStyleSheet (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QTextOption defaultTextOption () const
*/
HB_FUNC( QTEXTDOCUMENT_DEFAULTTEXTOPTION )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextOption * ptr = new QTextOption( obj->defaultTextOption (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTOPTION" );  }
}


/*
QAbstractTextDocumentLayout * documentLayout () const
*/
HB_FUNC( QTEXTDOCUMENT_DOCUMENTLAYOUT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractTextDocumentLayout * ptr = obj->documentLayout (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTTEXTDOCUMENTLAYOUT" );  }
}


/*
qreal documentMargin () const
*/
HB_FUNC( QTEXTDOCUMENT_DOCUMENTMARGIN )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->documentMargin (  );
    hb_retnd( r );
  }
}


/*
void drawContents ( QPainter * p, const QRectF & rect = QRectF() )
*/
HB_FUNC( QTEXTDOCUMENT_DRAWCONTENTS )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainter * par1 = (QPainter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRectF par2 = ISNIL(2)? QRectF() : *(QRectF *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->drawContents ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QTextBlock end () const
*/
HB_FUNC( QTEXTDOCUMENT_END )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlock * ptr = new QTextBlock( obj->end (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCK" );  }
}


/*
QTextCursor find ( const QString & subString, const QTextCursor & cursor, FindFlags options = 0 ) const
*/
HB_FUNC( QTEXTDOCUMENT_FIND1 )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QTextCursor * par2 = (QTextCursor *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par3 = ISNIL(3)? (int) 0 : hb_parni(3);
    QTextCursor * ptr = new QTextCursor( obj->find ( par1, *par2,  (QTextDocument::FindFlags) par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTCURSOR", true );  }
}


/*
QTextCursor find ( const QRegExp & expr, const QTextCursor & cursor, FindFlags options = 0 ) const
*/
HB_FUNC( QTEXTDOCUMENT_FIND2 )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegExp * par1 = (QRegExp *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QTextCursor * par2 = (QTextCursor *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par3 = ISNIL(3)? (int) 0 : hb_parni(3);
    QTextCursor * ptr = new QTextCursor( obj->find ( *par1, *par2,  (QTextDocument::FindFlags) par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTCURSOR", true );  }
}


/*
QTextCursor find ( const QString & subString, int position = 0, FindFlags options = 0 ) const
*/
HB_FUNC( QTEXTDOCUMENT_FIND3 )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    int par3 = ISNIL(3)? (int) 0 : hb_parni(3);
    QTextCursor * ptr = new QTextCursor( obj->find ( par1, par2,  (QTextDocument::FindFlags) par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTCURSOR", true );  }
}


/*
QTextCursor find ( const QRegExp & expr, int position = 0, FindFlags options = 0 ) const
*/
HB_FUNC( QTEXTDOCUMENT_FIND4 )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegExp * par1 = (QRegExp *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    int par3 = ISNIL(3)? (int) 0 : hb_parni(3);
    QTextCursor * ptr = new QTextCursor( obj->find ( *par1, par2,  (QTextDocument::FindFlags) par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTCURSOR", true );  }
}


//[1]QTextCursor find ( const QString & subString, const QTextCursor & cursor, FindFlags options = 0 ) const
//[2]QTextCursor find ( const QRegExp & expr, const QTextCursor & cursor, FindFlags options = 0 ) const
//[3]QTextCursor find ( const QString & subString, int position = 0, FindFlags options = 0 ) const
//[4]QTextCursor find ( const QRegExp & expr, int position = 0, FindFlags options = 0 ) const

HB_FUNC( QTEXTDOCUMENT_FIND )
{
  if( ISBETWEEN(2,3) && ISCHAR(1) && ISQTEXTCURSOR(2) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QTEXTDOCUMENT_FIND1 );
  }
  else if( ISBETWEEN(2,3) && ISQREGEXP(1) && ISQTEXTCURSOR(2) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QTEXTDOCUMENT_FIND2 );
  }
  else if( ISBETWEEN(1,3) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QTEXTDOCUMENT_FIND3 );
  }
  else if( ISBETWEEN(1,3) && ISQREGEXP(1) && (ISNUM(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(3)) )
  {
    HB_FUNC_EXEC( QTEXTDOCUMENT_FIND4 );
  }
}

/*
QTextBlock findBlock ( int pos ) const
*/
HB_FUNC( QTEXTDOCUMENT_FINDBLOCK )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTextBlock * ptr = new QTextBlock( obj->findBlock ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCK" );  }
}


/*
QTextBlock findBlockByLineNumber ( int lineNumber ) const
*/
HB_FUNC( QTEXTDOCUMENT_FINDBLOCKBYLINENUMBER )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTextBlock * ptr = new QTextBlock( obj->findBlockByLineNumber ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCK" );  }
}


/*
QTextBlock findBlockByNumber ( int blockNumber ) const
*/
HB_FUNC( QTEXTDOCUMENT_FINDBLOCKBYNUMBER )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTextBlock * ptr = new QTextBlock( obj->findBlockByNumber ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCK" );  }
}


/*
QTextBlock firstBlock () const
*/
HB_FUNC( QTEXTDOCUMENT_FIRSTBLOCK )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlock * ptr = new QTextBlock( obj->firstBlock (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCK" );  }
}


/*
qreal idealWidth () const
*/
HB_FUNC( QTEXTDOCUMENT_IDEALWIDTH )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->idealWidth (  );
    hb_retnd( r );
  }
}


/*
qreal indentWidth () const
*/
HB_FUNC( QTEXTDOCUMENT_INDENTWIDTH )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->indentWidth (  );
    hb_retnd( r );
  }
}


/*
bool isEmpty () const
*/
HB_FUNC( QTEXTDOCUMENT_ISEMPTY )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isEmpty (  );
    hb_retl( b );
  }
}


/*
bool isModified () const
*/
HB_FUNC( QTEXTDOCUMENT_ISMODIFIED )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isModified (  );
    hb_retl( b );
  }
}


/*
bool isRedoAvailable () const
*/
HB_FUNC( QTEXTDOCUMENT_ISREDOAVAILABLE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isRedoAvailable (  );
    hb_retl( b );
  }
}


/*
bool isUndoAvailable () const
*/
HB_FUNC( QTEXTDOCUMENT_ISUNDOAVAILABLE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isUndoAvailable (  );
    hb_retl( b );
  }
}


/*
bool isUndoRedoEnabled () const
*/
HB_FUNC( QTEXTDOCUMENT_ISUNDOREDOENABLED )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isUndoRedoEnabled (  );
    hb_retl( b );
  }
}


/*
QTextBlock lastBlock () const
*/
HB_FUNC( QTEXTDOCUMENT_LASTBLOCK )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlock * ptr = new QTextBlock( obj->lastBlock (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCK" );  }
}


/*
int lineCount () const
*/
HB_FUNC( QTEXTDOCUMENT_LINECOUNT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->lineCount (  );
    hb_retni( i );
  }
}


/*
void markContentsDirty ( int position, int length )
*/
HB_FUNC( QTEXTDOCUMENT_MARKCONTENTSDIRTY )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->markContentsDirty ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int maximumBlockCount () const
*/
HB_FUNC( QTEXTDOCUMENT_MAXIMUMBLOCKCOUNT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->maximumBlockCount (  );
    hb_retni( i );
  }
}


/*
QString metaInformation ( MetaInformation info ) const
*/
HB_FUNC( QTEXTDOCUMENT_METAINFORMATION )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString str1 = obj->metaInformation (  (QTextDocument::MetaInformation) par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QTextObject * object ( int objectIndex ) const
*/
HB_FUNC( QTEXTDOCUMENT_OBJECT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTextObject * ptr = obj->object ( par1 );
    _qt4xhb_createReturnClass ( ptr, "QTEXTOBJECT" );  }
}


/*
QTextObject * objectForFormat ( const QTextFormat & f ) const
*/
HB_FUNC( QTEXTDOCUMENT_OBJECTFORFORMAT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextFormat * par1 = (QTextFormat *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QTextObject * ptr = obj->objectForFormat ( *par1 );
    _qt4xhb_createReturnClass ( ptr, "QTEXTOBJECT" );  }
}


/*
int pageCount () const
*/
HB_FUNC( QTEXTDOCUMENT_PAGECOUNT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->pageCount (  );
    hb_retni( i );
  }
}


/*
QSizeF pageSize () const
*/
HB_FUNC( QTEXTDOCUMENT_PAGESIZE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSizeF * ptr = new QSizeF( obj->pageSize (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZEF", true );  }
}


/*
void print ( QPrinter * printer ) const
*/
HB_FUNC( QTEXTDOCUMENT_PRINT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPrinter * par1 = (QPrinter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->print ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void redo ( QTextCursor * cursor )
*/
HB_FUNC( QTEXTDOCUMENT_REDO1 )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextCursor * par1 = (QTextCursor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->redo ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QVariant resource ( int type, const QUrl & name ) const
*/
HB_FUNC( QTEXTDOCUMENT_RESOURCE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QUrl * par2 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QVariant * ptr = new QVariant( obj->resource ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
int revision () const
*/
HB_FUNC( QTEXTDOCUMENT_REVISION )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->revision (  );
    hb_retni( i );
  }
}


/*
QTextFrame * rootFrame () const
*/
HB_FUNC( QTEXTDOCUMENT_ROOTFRAME )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextFrame * ptr = obj->rootFrame (  );
    _qt4xhb_createReturnClass ( ptr, "QTEXTFRAME" );  }
}


/*
void setDefaultCursorMoveStyle ( Qt::CursorMoveStyle style )
*/
HB_FUNC( QTEXTDOCUMENT_SETDEFAULTCURSORMOVESTYLE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setDefaultCursorMoveStyle (  (Qt::CursorMoveStyle) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDefaultFont ( const QFont & font )
*/
HB_FUNC( QTEXTDOCUMENT_SETDEFAULTFONT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFont * par1 = (QFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setDefaultFont ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDefaultStyleSheet ( const QString & sheet )
*/
HB_FUNC( QTEXTDOCUMENT_SETDEFAULTSTYLESHEET )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setDefaultStyleSheet ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDefaultTextOption ( const QTextOption & option )
*/
HB_FUNC( QTEXTDOCUMENT_SETDEFAULTTEXTOPTION )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextOption * par1 = (QTextOption *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setDefaultTextOption ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDocumentLayout ( QAbstractTextDocumentLayout * layout )
*/
HB_FUNC( QTEXTDOCUMENT_SETDOCUMENTLAYOUT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractTextDocumentLayout * par1 = (QAbstractTextDocumentLayout *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setDocumentLayout ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDocumentMargin ( qreal margin )
*/
HB_FUNC( QTEXTDOCUMENT_SETDOCUMENTMARGIN )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setDocumentMargin ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHtml ( const QString & html )
*/
HB_FUNC( QTEXTDOCUMENT_SETHTML )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setHtml ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setIndentWidth ( qreal width )
*/
HB_FUNC( QTEXTDOCUMENT_SETINDENTWIDTH )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setIndentWidth ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMaximumBlockCount ( int maximum )
*/
HB_FUNC( QTEXTDOCUMENT_SETMAXIMUMBLOCKCOUNT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMaximumBlockCount ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setMetaInformation ( MetaInformation info, const QString & string )
*/
HB_FUNC( QTEXTDOCUMENT_SETMETAINFORMATION )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString par2 = hb_parc(2);
    obj->setMetaInformation (  (QTextDocument::MetaInformation) par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPageSize ( const QSizeF & size )
*/
HB_FUNC( QTEXTDOCUMENT_SETPAGESIZE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSizeF * par1 = (QSizeF *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setPageSize ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPlainText ( const QString & text )
*/
HB_FUNC( QTEXTDOCUMENT_SETPLAINTEXT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setPlainText ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTextWidth ( qreal width )
*/
HB_FUNC( QTEXTDOCUMENT_SETTEXTWIDTH )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal par1 = hb_parnd(1);
    obj->setTextWidth ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUndoRedoEnabled ( bool enable )
*/
HB_FUNC( QTEXTDOCUMENT_SETUNDOREDOENABLED )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setUndoRedoEnabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUseDesignMetrics ( bool b )
*/
HB_FUNC( QTEXTDOCUMENT_SETUSEDESIGNMETRICS )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setUseDesignMetrics ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QSizeF size () const
*/
HB_FUNC( QTEXTDOCUMENT_SIZE )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSizeF * ptr = new QSizeF( obj->size (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSIZEF", true );  }
}


/*
qreal textWidth () const
*/
HB_FUNC( QTEXTDOCUMENT_TEXTWIDTH )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qreal r = obj->textWidth (  );
    hb_retnd( r );
  }
}


/*
QString toHtml ( const QByteArray & encoding = QByteArray() ) const
*/
HB_FUNC( QTEXTDOCUMENT_TOHTML )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray par1 = ISNIL(1)? QByteArray() : *(QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString str1 = obj->toHtml ( par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString toPlainText () const
*/
HB_FUNC( QTEXTDOCUMENT_TOPLAINTEXT )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->toPlainText (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void undo ( QTextCursor * cursor )
*/
HB_FUNC( QTEXTDOCUMENT_UNDO1 )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextCursor * par1 = (QTextCursor *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->undo ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool useDesignMetrics () const
*/
HB_FUNC( QTEXTDOCUMENT_USEDESIGNMETRICS )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->useDesignMetrics (  );
    hb_retl( b );
  }
}


/*
void redo ()
*/
HB_FUNC( QTEXTDOCUMENT_REDO2 )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->redo (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void redo ( QTextCursor * cursor )
//[2]void redo ()

HB_FUNC( QTEXTDOCUMENT_REDO )
{
  if( ISNUMPAR(1) && ISQTEXTCURSOR(1) )
  {
    HB_FUNC_EXEC( QTEXTDOCUMENT_REDO1 );
  }
  else if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QTEXTDOCUMENT_REDO2 );
  }
}

/*
void setModified ( bool m = true )
*/
HB_FUNC( QTEXTDOCUMENT_SETMODIFIED )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = ISNIL(1)? true : hb_parl(1);
    obj->setModified ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void undo ()
*/
HB_FUNC( QTEXTDOCUMENT_UNDO2 )
{
  QTextDocument * obj = (QTextDocument *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->undo (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void undo ( QTextCursor * cursor )
//[2]void undo ()

HB_FUNC( QTEXTDOCUMENT_UNDO )
{
  if( ISNUMPAR(1) && ISQTEXTCURSOR(1) )
  {
    HB_FUNC_EXEC( QTEXTDOCUMENT_UNDO1 );
  }
  else if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QTEXTDOCUMENT_UNDO2 );
  }
}



