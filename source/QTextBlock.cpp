/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTextBlock>

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
QTextBlock ( const QTextBlock & other )
*/
HB_FUNC( QTEXTBLOCK_NEW )
{
  QTextBlock * o = NULL;
  QTextBlock * par1 = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QTextBlock ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTextBlock *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QTEXTBLOCK_DELETE )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QTextBlockFormat blockFormat () const
*/
HB_FUNC( QTEXTBLOCK_BLOCKFORMAT )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlockFormat * ptr = new QTextBlockFormat( obj->blockFormat (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCKFORMAT" );  }
}


/*
int blockFormatIndex () const
*/
HB_FUNC( QTEXTBLOCK_BLOCKFORMATINDEX )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->blockFormatIndex (  );
    hb_retni( i );
  }
}


/*
int blockNumber () const
*/
HB_FUNC( QTEXTBLOCK_BLOCKNUMBER )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->blockNumber (  );
    hb_retni( i );
  }
}


/*
QTextCharFormat charFormat () const
*/
HB_FUNC( QTEXTBLOCK_CHARFORMAT )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextCharFormat * ptr = new QTextCharFormat( obj->charFormat (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTCHARFORMAT" );  }
}


/*
int charFormatIndex () const
*/
HB_FUNC( QTEXTBLOCK_CHARFORMATINDEX )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->charFormatIndex (  );
    hb_retni( i );
  }
}


/*
void clearLayout ()
*/
HB_FUNC( QTEXTBLOCK_CLEARLAYOUT )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearLayout (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool contains ( int position ) const
*/
HB_FUNC( QTEXTBLOCK_CONTAINS )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->contains ( par1 );
    hb_retl( b );
  }
}


/*
const QTextDocument * document () const
*/
HB_FUNC( QTEXTBLOCK_DOCUMENT )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QTextDocument * ptr = obj->document (  );
    _qt4xhb_createReturnClass ( ptr, "QTEXTDOCUMENT" );  }
}



/*
int firstLineNumber () const
*/
HB_FUNC( QTEXTBLOCK_FIRSTLINENUMBER )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->firstLineNumber (  );
    hb_retni( i );
  }
}


/*
bool isValid () const
*/
HB_FUNC( QTEXTBLOCK_ISVALID )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
bool isVisible () const
*/
HB_FUNC( QTEXTBLOCK_ISVISIBLE )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isVisible (  );
    hb_retl( b );
  }
}


/*
QTextLayout * layout () const
*/
HB_FUNC( QTEXTBLOCK_LAYOUT )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextLayout * ptr = obj->layout (  );
    _qt4xhb_createReturnClass ( ptr, "QTEXTLAYOUT" );  }
}


/*
int length () const
*/
HB_FUNC( QTEXTBLOCK_LENGTH )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->length (  );
    hb_retni( i );
  }
}


/*
int lineCount () const
*/
HB_FUNC( QTEXTBLOCK_LINECOUNT )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->lineCount (  );
    hb_retni( i );
  }
}


/*
QTextBlock next () const
*/
HB_FUNC( QTEXTBLOCK_NEXT )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlock * ptr = new QTextBlock( obj->next (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCK" );  }
}


/*
int position () const
*/
HB_FUNC( QTEXTBLOCK_POSITION )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->position (  );
    hb_retni( i );
  }
}


/*
QTextBlock previous () const
*/
HB_FUNC( QTEXTBLOCK_PREVIOUS )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlock * ptr = new QTextBlock( obj->previous (  ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCK" );  }
}


/*
int revision () const
*/
HB_FUNC( QTEXTBLOCK_REVISION )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->revision (  );
    hb_retni( i );
  }
}


/*
void setLineCount ( int count )
*/
HB_FUNC( QTEXTBLOCK_SETLINECOUNT )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setLineCount ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRevision ( int rev )
*/
HB_FUNC( QTEXTBLOCK_SETREVISION )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setRevision ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUserData ( QTextBlockUserData * data )
*/
HB_FUNC( QTEXTBLOCK_SETUSERDATA )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlockUserData * par1 = (QTextBlockUserData *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setUserData ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUserState ( int state )
*/
HB_FUNC( QTEXTBLOCK_SETUSERSTATE )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setUserState ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setVisible ( bool visible )
*/
HB_FUNC( QTEXTBLOCK_SETVISIBLE )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setVisible ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString text () const
*/
HB_FUNC( QTEXTBLOCK_TEXT )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->text (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
Qt::LayoutDirection textDirection () const
*/
HB_FUNC( QTEXTBLOCK_TEXTDIRECTION )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->textDirection (  );
    hb_retni( i );
  }
}


/*
QTextList * textList () const
*/
HB_FUNC( QTEXTBLOCK_TEXTLIST )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextList * ptr = obj->textList (  );
    _qt4xhb_createReturnClass ( ptr, "QTEXTLIST" );  }
}


/*
QTextBlockUserData * userData () const
*/
HB_FUNC( QTEXTBLOCK_USERDATA )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextBlockUserData * ptr = obj->userData (  );
    _qt4xhb_createReturnClass ( ptr, "QTEXTBLOCKUSERDATA" );  }
}


/*
int userState () const
*/
HB_FUNC( QTEXTBLOCK_USERSTATE )
{
  QTextBlock * obj = (QTextBlock *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->userState (  );
    hb_retni( i );
  }
}



