/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QChar>

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
QChar ()
*/
HB_FUNC( QCHAR_NEW1 )
{
  QChar * o = NULL;
  o = new QChar (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QChar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QChar ( char ch )
*/
HB_FUNC( QCHAR_NEW2 )
{
  QChar * o = NULL;
  char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
  o = new QChar ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QChar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QChar ( uchar ch )
*/
HB_FUNC( QCHAR_NEW3 )
{
  QChar * o = NULL;
  uchar par1 = ISCHAR(1)? (uchar) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
  o = new QChar ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QChar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QChar ( QLatin1Char ch )
*/
HB_FUNC( QCHAR_NEW4 )
{
  QChar * o = NULL;
  QLatin1Char * par1 = (QLatin1Char *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QChar ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QChar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QChar ( uchar cell, uchar row )
*/
HB_FUNC( QCHAR_NEW5 )
{
  QChar * o = NULL;
  uchar par1 = ISCHAR(1)? (uchar) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
  uchar par2 = ISCHAR(2)? (uchar) hb_parc(2)[0] : (ISNUM(2)? hb_parni(2) : 0);
  o = new QChar ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QChar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QChar ( ushort code )
*/
HB_FUNC( QCHAR_NEW6 )
{
  QChar * o = NULL;
  ushort par1 = hb_parni(1);
  o = new QChar ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QChar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QChar ( short code )
*/
HB_FUNC( QCHAR_NEW7 )
{
  QChar * o = NULL;
  short par1 = hb_parni(1);
  o = new QChar ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QChar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QChar ( uint code )
*/
HB_FUNC( QCHAR_NEW8 )
{
  QChar * o = NULL;
  uint par1 = hb_parni(1);
  o = new QChar ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QChar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QChar ( int code )
*/
HB_FUNC( QCHAR_NEW9 )
{
  QChar * o = NULL;
  int par1 = hb_parni(1);
  o = new QChar ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QChar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QChar ( SpecialCharacter ch )
*/
HB_FUNC( QCHAR_NEW10 )
{
  QChar * o = NULL;
  int par1 = hb_parni(1);
  o = new QChar (  (QChar::SpecialCharacter) par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QChar *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[01]QChar ()
//[02]QChar ( char ch )
//[03]QChar ( uchar ch )
//[04]QChar ( QLatin1Char ch )
//[05]QChar ( uchar cell, uchar row )
//[06]QChar ( ushort code )
//[07]QChar ( short code )
//[08]QChar ( uint code )
//[09]QChar ( int code )
//[10]QChar ( SpecialCharacter ch )

HB_FUNC( QCHAR_NEW )
{
  HB_FUNC_EXEC( QCHAR_NEW1 );
}

HB_FUNC( QCHAR_DELETE )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
Category category () const
*/
HB_FUNC( QCHAR_CATEGORY )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->category (  );
    hb_retni( i );
  }
}





/*
Decomposition decompositionTag () const
*/
HB_FUNC( QCHAR_DECOMPOSITIONTAG )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->decompositionTag (  );
    hb_retni( i );
  }
}


/*
int digitValue () const
*/
HB_FUNC( QCHAR_DIGITVALUE )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->digitValue (  );
    hb_retni( i );
  }
}


/*
Direction direction () const
*/
HB_FUNC( QCHAR_DIRECTION )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->direction (  );
    hb_retni( i );
  }
}


/*
bool hasMirrored () const
*/
HB_FUNC( QCHAR_HASMIRRORED )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasMirrored (  );
    hb_retl( b );
  }
}


/*
bool isDigit () const
*/
HB_FUNC( QCHAR_ISDIGIT )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isDigit (  );
    hb_retl( b );
  }
}


/*
bool isHighSurrogate () const
*/
HB_FUNC( QCHAR_ISHIGHSURROGATE )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isHighSurrogate (  );
    hb_retl( b );
  }
}


/*
bool isLetter () const
*/
HB_FUNC( QCHAR_ISLETTER )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isLetter (  );
    hb_retl( b );
  }
}


/*
bool isLetterOrNumber () const
*/
HB_FUNC( QCHAR_ISLETTERORNUMBER )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isLetterOrNumber (  );
    hb_retl( b );
  }
}


/*
bool isLowSurrogate () const
*/
HB_FUNC( QCHAR_ISLOWSURROGATE )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isLowSurrogate (  );
    hb_retl( b );
  }
}


/*
bool isLower () const
*/
HB_FUNC( QCHAR_ISLOWER )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isLower (  );
    hb_retl( b );
  }
}


/*
bool isMark () const
*/
HB_FUNC( QCHAR_ISMARK )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isMark (  );
    hb_retl( b );
  }
}


/*
bool isNull () const
*/
HB_FUNC( QCHAR_ISNULL )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
bool isNumber () const
*/
HB_FUNC( QCHAR_ISNUMBER )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNumber (  );
    hb_retl( b );
  }
}


/*
bool isPrint () const
*/
HB_FUNC( QCHAR_ISPRINT )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isPrint (  );
    hb_retl( b );
  }
}


/*
bool isPunct () const
*/
HB_FUNC( QCHAR_ISPUNCT )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isPunct (  );
    hb_retl( b );
  }
}


/*
bool isSpace () const
*/
HB_FUNC( QCHAR_ISSPACE )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSpace (  );
    hb_retl( b );
  }
}


/*
bool isSymbol () const
*/
HB_FUNC( QCHAR_ISSYMBOL )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isSymbol (  );
    hb_retl( b );
  }
}


/*
bool isTitleCase () const
*/
HB_FUNC( QCHAR_ISTITLECASE )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isTitleCase (  );
    hb_retl( b );
  }
}


/*
bool isUpper () const
*/
HB_FUNC( QCHAR_ISUPPER )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isUpper (  );
    hb_retl( b );
  }
}


/*
Joining joining () const
*/
HB_FUNC( QCHAR_JOINING )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->joining (  );
    hb_retni( i );
  }
}


/*
QChar mirroredChar () const
*/
HB_FUNC( QCHAR_MIRROREDCHAR )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * ptr = new QChar( obj->mirroredChar (  ) );
    _qt4xhb_createReturnClass ( ptr, "QCHAR" );  }
}




/*
QChar toCaseFolded () const
*/
HB_FUNC( QCHAR_TOCASEFOLDED )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * ptr = new QChar( obj->toCaseFolded (  ) );
    _qt4xhb_createReturnClass ( ptr, "QCHAR" );  }
}



/*
QChar toLower () const
*/
HB_FUNC( QCHAR_TOLOWER )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * ptr = new QChar( obj->toLower (  ) );
    _qt4xhb_createReturnClass ( ptr, "QCHAR" );  }
}


/*
QChar toTitleCase () const
*/
HB_FUNC( QCHAR_TOTITLECASE )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * ptr = new QChar( obj->toTitleCase (  ) );
    _qt4xhb_createReturnClass ( ptr, "QCHAR" );  }
}


/*
QChar toUpper () const
*/
HB_FUNC( QCHAR_TOUPPER )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QChar * ptr = new QChar( obj->toUpper (  ) );
    _qt4xhb_createReturnClass ( ptr, "QCHAR" );  }
}




/*
UnicodeVersion unicodeVersion () const
*/
HB_FUNC( QCHAR_UNICODEVERSION )
{
  QChar * obj = (QChar *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->unicodeVersion (  );
    hb_retni( i );
  }
}



// TODO: implementar met�dos est�ticos



































