/*

  Qt4xHb - bibliotecas de ligação entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QByteArray>

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

#include <QString>
#include <QList>

/*
QByteArray ()
*/
HB_FUNC( QBYTEARRAY_NEW1 )
{
  QByteArray * o = NULL;
  o = new QByteArray (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QByteArray *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QByteArray ( const char * str )
*/
HB_FUNC( QBYTEARRAY_NEW2 )
{
  QByteArray * o = NULL;
  const char * par1 = hb_parc(1);
  o = new QByteArray (  (const char *) par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QByteArray *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QByteArray ( const char * data, int size )
*/
HB_FUNC( QBYTEARRAY_NEW3 )
{
  QByteArray * o = NULL;
  const char * par1 = hb_parc(1);
  int par2 = hb_parni(2);
  o = new QByteArray (  (const char *) par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QByteArray *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QByteArray ( int size, char ch )
*/
HB_FUNC( QBYTEARRAY_NEW4 )
{
  QByteArray * o = NULL;
  int par1 = hb_parni(1);
  char par2 = ISCHAR(2)? (char) hb_parc(2)[0] : (ISNUM(2)? hb_parni(2) : 0);
  o = new QByteArray ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QByteArray *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QByteArray ( const QByteArray & other )
*/
HB_FUNC( QBYTEARRAY_NEW5 )
{
  QByteArray * o = NULL;
  QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QByteArray ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QByteArray *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QByteArray ()
//[2]QByteArray ( const char * str )
//[3]QByteArray ( const char * data, int size )
//[4]QByteArray ( int size, char ch )
//[5]QByteArray ( const QByteArray & other )

HB_FUNC( QBYTEARRAY_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_NEW1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_NEW2 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_NEW3 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_NEW4 );
  }
  else if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_NEW5 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QBYTEARRAY_DELETE )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QByteArray & append ( const QByteArray & ba )
*/
HB_FUNC( QBYTEARRAY_APPEND1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QByteArray * ptr = new QByteArray( obj->append ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & append ( const QString & str )
*/
HB_FUNC( QBYTEARRAY_APPEND2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QByteArray * ptr = new QByteArray( obj->append ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & append ( const char * str )
*/
HB_FUNC( QBYTEARRAY_APPEND3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    QByteArray * ptr = new QByteArray( obj->append (  (const char *) par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & append ( const char * str, int len )
*/
HB_FUNC( QBYTEARRAY_APPEND4 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    int par2 = hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->append (  (const char *) par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & append ( char ch )
*/
HB_FUNC( QBYTEARRAY_APPEND5 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    QByteArray * ptr = new QByteArray( obj->append ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


//[1]QByteArray & append ( const QByteArray & ba )
//[2]QByteArray & append ( const QString & str )
//[3]QByteArray & append ( const char * str )
//[4]QByteArray & append ( const char * str, int len )
//[5]QByteArray & append ( char ch )

HB_FUNC( QBYTEARRAY_APPEND )
{
  if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_APPEND1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_APPEND2 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_APPEND4 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_APPEND5 );
  }
}

/*
char at ( int i ) const
*/
HB_FUNC( QBYTEARRAY_AT )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    char i = obj->at ( par1 );
    hb_retni( i );
  }
}


/*
int capacity () const
*/
HB_FUNC( QBYTEARRAY_CAPACITY )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->capacity (  );
    hb_retni( i );
  }
}


/*
void chop ( int n )
*/
HB_FUNC( QBYTEARRAY_CHOP )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->chop ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void clear ()
*/
HB_FUNC( QBYTEARRAY_CLEAR )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
const char * constData () const
*/
HB_FUNC( QBYTEARRAY_CONSTDATA )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * str1 = obj->constData (  );
    hb_retc( str1 );
  }
}


/*
bool contains ( const QByteArray & ba ) const
*/
HB_FUNC( QBYTEARRAY_CONTAINS1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->contains ( *par1 );
    hb_retl( b );
  }
}


/*
bool contains ( const char * str ) const
*/
HB_FUNC( QBYTEARRAY_CONTAINS2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    bool b = obj->contains (  (const char *) par1 );
    hb_retl( b );
  }
}


/*
bool contains ( char ch ) const
*/
HB_FUNC( QBYTEARRAY_CONTAINS3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    bool b = obj->contains ( par1 );
    hb_retl( b );
  }
}


//[1]bool contains ( const QByteArray & ba ) const
//[2]bool contains ( const char * str ) const
//[3]bool contains ( char ch ) const

HB_FUNC( QBYTEARRAY_CONTAINS )
{
  if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_CONTAINS1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_CONTAINS2 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_CONTAINS3 );
  }
}

/*
int count ( const QByteArray & ba ) const
*/
HB_FUNC( QBYTEARRAY_COUNT1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->count ( *par1 );
    hb_retni( i );
  }
}


/*
int count ( const char * str ) const
*/
HB_FUNC( QBYTEARRAY_COUNT2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    int i = obj->count (  (const char *) par1 );
    hb_retni( i );
  }
}


/*
int count ( char ch ) const
*/
HB_FUNC( QBYTEARRAY_COUNT3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    int i = obj->count ( par1 );
    hb_retni( i );
  }
}


/*
int count () const
*/
HB_FUNC( QBYTEARRAY_COUNT4 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->count (  );
    hb_retni( i );
  }
}


//[1]int count ( const QByteArray & ba ) const
//[2]int count ( const char * str ) const
//[3]int count ( char ch ) const
//[4]int count () const

HB_FUNC( QBYTEARRAY_COUNT )
{
  if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_COUNT1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_COUNT2 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_COUNT3 );
  }
  else if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_COUNT4 );
  }
}



//[1]char * data ()
//[2]const char * data () const

//HB_FUNC( QBYTEARRAY_DATA )
//{
//  HB_FUNC_EXEC( QBYTEARRAY_DATA1 );
//}

/*
bool endsWith ( const QByteArray & ba ) const
*/
HB_FUNC( QBYTEARRAY_ENDSWITH1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->endsWith ( *par1 );
    hb_retl( b );
  }
}


/*
bool endsWith ( const char * str ) const
*/
HB_FUNC( QBYTEARRAY_ENDSWITH2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    bool b = obj->endsWith (  (const char *) par1 );
    hb_retl( b );
  }
}


/*
bool endsWith ( char ch ) const
*/
HB_FUNC( QBYTEARRAY_ENDSWITH3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    bool b = obj->endsWith ( par1 );
    hb_retl( b );
  }
}


//[1]bool endsWith ( const QByteArray & ba ) const
//[2]bool endsWith ( const char * str ) const
//[3]bool endsWith ( char ch ) const

HB_FUNC( QBYTEARRAY_ENDSWITH )
{
  if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_ENDSWITH1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_ENDSWITH2 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_ENDSWITH3 );
  }
}

/*
QByteArray & fill ( char ch, int size = -1 )
*/
HB_FUNC( QBYTEARRAY_FILL )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    int par2 = ISNIL(2)? -1 : hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->fill ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
int indexOf ( const QByteArray & ba, int from = 0 ) const
*/
HB_FUNC( QBYTEARRAY_INDEXOF1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    int i = obj->indexOf ( *par1, par2 );
    hb_retni( i );
  }
}


/*
int indexOf ( const QString & str, int from = 0 ) const
*/
HB_FUNC( QBYTEARRAY_INDEXOF2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    int i = obj->indexOf ( par1, par2 );
    hb_retni( i );
  }
}


/*
int indexOf ( const char * str, int from = 0 ) const
*/
HB_FUNC( QBYTEARRAY_INDEXOF3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    int i = obj->indexOf (  (const char *) par1, par2 );
    hb_retni( i );
  }
}


/*
int indexOf ( char ch, int from = 0 ) const
*/
HB_FUNC( QBYTEARRAY_INDEXOF4 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    int par2 = ISNIL(2)? 0 : hb_parni(2);
    int i = obj->indexOf ( par1, par2 );
    hb_retni( i );
  }
}


//[1]int indexOf ( const QByteArray & ba, int from = 0 ) const
//[2]int indexOf ( const QString & str, int from = 0 ) const
//[3]int indexOf ( const char * str, int from = 0 ) const
//[4]int indexOf ( char ch, int from = 0 ) const

HB_FUNC( QBYTEARRAY_INDEXOF )
{
  if( ISBETWEEN(1,2) && ISQBYTEARRAY(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_INDEXOF1 );
  }
  else if( ISBETWEEN(1,2) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_INDEXOF2 );
  }
  else if( ISBETWEEN(1,2) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_INDEXOF3 ); // WARNING: conflita com [2]
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_INDEXOF4 );
  }
}

/*
QByteArray & insert ( int i, const QByteArray & ba )
*/
HB_FUNC( QBYTEARRAY_INSERT1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QByteArray * par2 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QByteArray * ptr = new QByteArray( obj->insert ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & insert ( int i, const QString & str )
*/
HB_FUNC( QBYTEARRAY_INSERT2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString par2 = hb_parc(2);
    QByteArray * ptr = new QByteArray( obj->insert ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & insert ( int i, const char * str )
*/
HB_FUNC( QBYTEARRAY_INSERT3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    const char * par2 = hb_parc(2);
    QByteArray * ptr = new QByteArray( obj->insert ( par1,  (const char *) par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & insert ( int i, const char * str, int len )
*/
HB_FUNC( QBYTEARRAY_INSERT4 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    const char * par2 = hb_parc(2);
    int par3 = hb_parni(3);
    QByteArray * ptr = new QByteArray( obj->insert ( par1,  (const char *) par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & insert ( int i, char ch )
*/
HB_FUNC( QBYTEARRAY_INSERT5 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    char par2 = ISCHAR(2)? (char) hb_parc(2)[0] : (ISNUM(2)? hb_parni(2) : 0);
    QByteArray * ptr = new QByteArray( obj->insert ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


//[1]QByteArray & insert ( int i, const QByteArray & ba )
//[2]QByteArray & insert ( int i, const QString & str )
//[3]QByteArray & insert ( int i, const char * str )
//[4]QByteArray & insert ( int i, const char * str, int len )
//[5]QByteArray & insert ( int i, char ch )

HB_FUNC( QBYTEARRAY_INSERT )
{
  if( ISNUMPAR(2) && ISNUM(1) && ISQBYTEARRAY(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_INSERT1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_INSERT2 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISCHAR(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_INSERT4 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_INSERT5 );
  }
}

/*
bool isEmpty () const
*/
HB_FUNC( QBYTEARRAY_ISEMPTY )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isEmpty (  );
    hb_retl( b );
  }
}


/*
bool isNull () const
*/
HB_FUNC( QBYTEARRAY_ISNULL )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
int lastIndexOf ( const QByteArray & ba, int from = -1 ) const
*/
HB_FUNC( QBYTEARRAY_LASTINDEXOF1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int par2 = ISNIL(2)? -1 : hb_parni(2);
    int i = obj->lastIndexOf ( *par1, par2 );
    hb_retni( i );
  }
}


/*
int lastIndexOf ( const QString & str, int from = -1 ) const
*/
HB_FUNC( QBYTEARRAY_LASTINDEXOF2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = ISNIL(2)? -1 : hb_parni(2);
    int i = obj->lastIndexOf ( par1, par2 );
    hb_retni( i );
  }
}


/*
int lastIndexOf ( const char * str, int from = -1 ) const
*/
HB_FUNC( QBYTEARRAY_LASTINDEXOF3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    int par2 = ISNIL(2)? -1 : hb_parni(2);
    int i = obj->lastIndexOf (  (const char *) par1, par2 );
    hb_retni( i );
  }
}


/*
int lastIndexOf ( char ch, int from = -1 ) const
*/
HB_FUNC( QBYTEARRAY_LASTINDEXOF4 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    int par2 = ISNIL(2)? -1 : hb_parni(2);
    int i = obj->lastIndexOf ( par1, par2 );
    hb_retni( i );
  }
}


//[1]int lastIndexOf ( const QByteArray & ba, int from = -1 ) const
//[2]int lastIndexOf ( const QString & str, int from = -1 ) const
//[3]int lastIndexOf ( const char * str, int from = -1 ) const
//[4]int lastIndexOf ( char ch, int from = -1 ) const

HB_FUNC( QBYTEARRAY_LASTINDEXOF )
{
  if( ISBETWEEN(1,2) && ISQBYTEARRAY(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_LASTINDEXOF1 );
  }
  else if( ISBETWEEN(1,2) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_LASTINDEXOF2 );
  }
  else if( ISBETWEEN(1,2) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_LASTINDEXOF3 ); // WARNING: conflita com [2]
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_LASTINDEXOF4 );
  }
}

/*
QByteArray left ( int len ) const
*/
HB_FUNC( QBYTEARRAY_LEFT )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QByteArray * ptr = new QByteArray( obj->left ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray leftJustified ( int width, char fill = ' ', bool truncate = false ) const
*/
HB_FUNC( QBYTEARRAY_LEFTJUSTIFIED )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    char par2 = ISNIL(2)? 32 : (ISCHAR(2)? (char) hb_parc(2)[0] : (ISNUM(2)? hb_parni(2) : 0));
    bool par3 = ISNIL(3)? false : hb_parl(3);
    QByteArray * ptr = new QByteArray( obj->leftJustified ( par1, par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
int length () const
*/
HB_FUNC( QBYTEARRAY_LENGTH )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->length (  );
    hb_retni( i );
  }
}


/*
QByteArray mid ( int pos, int len = -1 ) const
*/
HB_FUNC( QBYTEARRAY_MID )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? -1 : hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->mid ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & prepend ( const QByteArray & ba )
*/
HB_FUNC( QBYTEARRAY_PREPEND1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QByteArray * ptr = new QByteArray( obj->prepend ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & prepend ( const char * str )
*/
HB_FUNC( QBYTEARRAY_PREPEND2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    QByteArray * ptr = new QByteArray( obj->prepend (  (const char *) par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & prepend ( const char * str, int len )
*/
HB_FUNC( QBYTEARRAY_PREPEND3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    int par2 = hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->prepend (  (const char *) par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & prepend ( char ch )
*/
HB_FUNC( QBYTEARRAY_PREPEND4 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    QByteArray * ptr = new QByteArray( obj->prepend ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


//[1]QByteArray & prepend ( const QByteArray & ba )
//[2]QByteArray & prepend ( const char * str )
//[3]QByteArray & prepend ( const char * str, int len )
//[4]QByteArray & prepend ( char ch )

HB_FUNC( QBYTEARRAY_PREPEND )
{
  if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_PREPEND1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_PREPEND2 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_PREPEND3 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_PREPEND4 );
  }
}

/*
void push_back ( const QByteArray & other )
*/
HB_FUNC( QBYTEARRAY_PUSH_BACK1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->push_back ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void push_back ( const char * str )
*/
HB_FUNC( QBYTEARRAY_PUSH_BACK2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    obj->push_back (  (const char *) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void push_back ( char ch )
*/
HB_FUNC( QBYTEARRAY_PUSH_BACK3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    obj->push_back ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void push_back ( const QByteArray & other )
//[2]void push_back ( const char * str )
//[3]void push_back ( char ch )

HB_FUNC( QBYTEARRAY_PUSH_BACK )
{
  if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_PUSH_BACK1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_PUSH_BACK2 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_PUSH_BACK3 );
  }
}

/*
void push_front ( const QByteArray & other )
*/
HB_FUNC( QBYTEARRAY_PUSH_FRONT1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->push_front ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void push_front ( const char * str )
*/
HB_FUNC( QBYTEARRAY_PUSH_FRONT2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    obj->push_front (  (const char *) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void push_front ( char ch )
*/
HB_FUNC( QBYTEARRAY_PUSH_FRONT3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    obj->push_front ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void push_front ( const QByteArray & other )
//[2]void push_front ( const char * str )
//[3]void push_front ( char ch )

HB_FUNC( QBYTEARRAY_PUSH_FRONT )
{
  if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_PUSH_FRONT1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_PUSH_FRONT2 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_PUSH_FRONT3 );
  }
}

/*
QByteArray & remove ( int pos, int len )
*/
HB_FUNC( QBYTEARRAY_REMOVE )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->remove ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray repeated ( int times ) const
*/
HB_FUNC( QBYTEARRAY_REPEATED )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QByteArray * ptr = new QByteArray( obj->repeated ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( int pos, int len, const QByteArray & after )
*/
HB_FUNC( QBYTEARRAY_REPLACE1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QByteArray * par3 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    QByteArray * ptr = new QByteArray( obj->replace ( par1, par2, *par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( int pos, int len, const char * after )
*/
HB_FUNC( QBYTEARRAY_REPLACE2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    const char * par3 = hb_parc(3);
    QByteArray * ptr = new QByteArray( obj->replace ( par1, par2,  (const char *) par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( int pos, int len, const char * after, int alen )
*/
HB_FUNC( QBYTEARRAY_REPLACE3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    const char * par3 = hb_parc(3);
    int par4 = hb_parni(4);
    QByteArray * ptr = new QByteArray( obj->replace ( par1, par2,  (const char *) par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( const QByteArray & before, const QByteArray & after )
*/
HB_FUNC( QBYTEARRAY_REPLACE4 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QByteArray * par2 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QByteArray * ptr = new QByteArray( obj->replace ( *par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( const char * before, const QByteArray & after )
*/
HB_FUNC( QBYTEARRAY_REPLACE5 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    QByteArray * par2 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QByteArray * ptr = new QByteArray( obj->replace (  (const char *) par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( const char * before, int bsize, const char * after, int asize )
*/
HB_FUNC( QBYTEARRAY_REPLACE6 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    int par2 = hb_parni(2);
    const char * par3 = hb_parc(3);
    int par4 = hb_parni(4);
    QByteArray * ptr = new QByteArray( obj->replace (  (const char *) par1, par2,  (const char *) par3, par4 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( const QByteArray & before, const char * after )
*/
HB_FUNC( QBYTEARRAY_REPLACE7 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    const char * par2 = hb_parc(2);
    QByteArray * ptr = new QByteArray( obj->replace ( *par1,  (const char *) par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( const QString & before, const QByteArray & after )
*/
HB_FUNC( QBYTEARRAY_REPLACE8 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QByteArray * par2 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QByteArray * ptr = new QByteArray( obj->replace ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( const QString & before, const char * after )
*/
HB_FUNC( QBYTEARRAY_REPLACE9 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    const char * par2 = hb_parc(2);
    QByteArray * ptr = new QByteArray( obj->replace ( par1,  (const char *) par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( const char * before, const char * after )
*/
HB_FUNC( QBYTEARRAY_REPLACE10 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    const char * par2 = hb_parc(2);
    QByteArray * ptr = new QByteArray( obj->replace (  (const char *) par1,  (const char *) par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( char before, const QByteArray & after )
*/
HB_FUNC( QBYTEARRAY_REPLACE11 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    QByteArray * par2 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QByteArray * ptr = new QByteArray( obj->replace ( par1, *par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( char before, const QString & after )
*/
HB_FUNC( QBYTEARRAY_REPLACE12 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    QString par2 = hb_parc(2);
    QByteArray * ptr = new QByteArray( obj->replace ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( char before, const char * after )
*/
HB_FUNC( QBYTEARRAY_REPLACE13 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    const char * par2 = hb_parc(2);
    QByteArray * ptr = new QByteArray( obj->replace ( par1,  (const char *) par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & replace ( char before, char after )
*/
HB_FUNC( QBYTEARRAY_REPLACE14 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    char par2 = ISCHAR(2)? (char) hb_parc(2)[0] : (ISNUM(2)? hb_parni(2) : 0);
    QByteArray * ptr = new QByteArray( obj->replace ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


//[01]QByteArray & replace ( int pos, int len, const QByteArray & after )
//[02]QByteArray & replace ( int pos, int len, const char * after )
//[03]QByteArray & replace ( int pos, int len, const char * after, int alen )
//[04]QByteArray & replace ( const QByteArray & before, const QByteArray & after )
//[05]QByteArray & replace ( const char * before, const QByteArray & after )
//[06]QByteArray & replace ( const char * before, int bsize, const char * after, int asize )
//[07]QByteArray & replace ( const QByteArray & before, const char * after )
//[08]QByteArray & replace ( const QString & before, const QByteArray & after )
//[09]QByteArray & replace ( const QString & before, const char * after )
//[10]QByteArray & replace ( const char * before, const char * after )
//[11]QByteArray & replace ( char before, const QByteArray & after )
//[12]QByteArray & replace ( char before, const QString & after )
//[13]QByteArray & replace ( char before, const char * after )
//[14]QByteArray & replace ( char before, char after )

HB_FUNC( QBYTEARRAY_REPLACE )
{
  if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISQBYTEARRAY(3) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE1 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISCHAR(3) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE2 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISCHAR(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE3 );
  }
  else if( ISNUMPAR(2) && ISQBYTEARRAY(1) && ISQBYTEARRAY(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE4 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISQBYTEARRAY(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE5 );
  }
  else if( ISNUMPAR(4) && ISCHAR(1) && ISNUM(2) && ISCHAR(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE6 );
  }
  else if( ISNUMPAR(2) && ISQBYTEARRAY(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE7 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISQBYTEARRAY(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE8 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE9 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE10 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISQBYTEARRAY(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE11 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE12 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE13 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_REPLACE14 );
  }
}

/*
void reserve ( int size )
*/
HB_FUNC( QBYTEARRAY_RESERVE )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->reserve ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void resize ( int size )
*/
HB_FUNC( QBYTEARRAY_RESIZE )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->resize ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QByteArray right ( int len ) const
*/
HB_FUNC( QBYTEARRAY_RIGHT )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QByteArray * ptr = new QByteArray( obj->right ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray rightJustified ( int width, char fill = ' ', bool truncate = false ) const
*/
HB_FUNC( QBYTEARRAY_RIGHTJUSTIFIED )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    char par2 = ISNIL(2)? 32 : (ISCHAR(2)? (char) hb_parc(2)[0] : (ISNUM(2)? hb_parni(2) : 0));
    bool par3 = ISNIL(3)? false : hb_parl(3);
    QByteArray * ptr = new QByteArray( obj->rightJustified ( par1, par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & setNum ( int n, int base = 10 )
*/
HB_FUNC( QBYTEARRAY_SETNUM1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->setNum ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & setNum ( uint n, int base = 10 )
*/
HB_FUNC( QBYTEARRAY_SETNUM2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    uint par1 = hb_parni(1);
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->setNum ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & setNum ( short n, int base = 10 )
*/
HB_FUNC( QBYTEARRAY_SETNUM3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    short par1 = hb_parni(1);
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->setNum ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & setNum ( ushort n, int base = 10 )
*/
HB_FUNC( QBYTEARRAY_SETNUM4 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    ushort par1 = hb_parni(1);
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->setNum ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & setNum ( qlonglong n, int base = 10 )
*/
HB_FUNC( QBYTEARRAY_SETNUM5 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qlonglong par1 = hb_parnl(1);
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->setNum ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & setNum ( qulonglong n, int base = 10 )
*/
HB_FUNC( QBYTEARRAY_SETNUM6 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    qulonglong par1 = hb_parnl(1);
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->setNum ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & setNum ( double n, char f = 'g', int prec = 6 )
*/
HB_FUNC( QBYTEARRAY_SETNUM7 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    double par1 = hb_parnd(1);
    char par2 = ISNIL(2)? 103 : (ISCHAR(2)? (char) hb_parc(2)[0] : (ISNUM(2)? hb_parni(2) : 0));
    int par3 = ISNIL(3)? 6 : hb_parni(3);
    QByteArray * ptr = &obj->setNum ( par1, par2, par3 );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray & setNum ( float n, char f = 'g', int prec = 6 )
*/
HB_FUNC( QBYTEARRAY_SETNUM8 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    float par1 = hb_parnd(1);
    char par2 = ISNIL(2)? 103 : (ISCHAR(2)? (char) hb_parc(2)[0] : (ISNUM(2)? hb_parni(2) : 0));
    int par3 = ISNIL(3)? 6 : hb_parni(3);
    QByteArray * ptr = &obj->setNum ( par1, par2, par3 );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


//[1]QByteArray & setNum ( int n, int base = 10 )
//[2]QByteArray & setNum ( uint n, int base = 10 )
//[3]QByteArray & setNum ( short n, int base = 10 )
//[4]QByteArray & setNum ( ushort n, int base = 10 )
//[5]QByteArray & setNum ( qlonglong n, int base = 10 )
//[6]QByteArray & setNum ( qulonglong n, int base = 10 )
//[7]QByteArray & setNum ( double n, char f = 'g', int prec = 6 )
//[8]QByteArray & setNum ( float n, char f = 'g', int prec = 6 )

// TODO: implementar identificação de números inteiros e fracionários

HB_FUNC( QBYTEARRAY_SETNUM )
{
  if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_SETNUM1 );
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_SETNUM2 );
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_SETNUM3 );
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_SETNUM4 );
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_SETNUM5 );
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_SETNUM6 );
  }
  else if( ISBETWEEN(1,3) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_SETNUM7 );
  }
  else if( ISBETWEEN(1,3) && ISNUM(1) && (ISNUM(2)||ISNIL(2)) && (ISNUM(3)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_SETNUM8 );
  }
}

/*
QByteArray & setRawData ( const char * data, uint size )
*/
HB_FUNC( QBYTEARRAY_SETRAWDATA )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    uint par2 = hb_parni(2);
    QByteArray * ptr = new QByteArray( obj->setRawData (  (const char *) par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray simplified () const
*/
HB_FUNC( QBYTEARRAY_SIMPLIFIED )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->simplified (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
int size () const
*/
HB_FUNC( QBYTEARRAY_SIZE )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->size (  );
    hb_retni( i );
  }
}


/*
QList<QByteArray> split ( char sep ) const
*/
HB_FUNC( QBYTEARRAY_SPLIT )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    QList<QByteArray> list = obj->split ( par1 );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QBYTEARRAY" );
    #else
    pDynSym = hb_dynsymFindName( "QBYTEARRAY" );
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
        hb_itemPutPtr( pItem, (QByteArray *) new QByteArray ( list[i] ) );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_itemRelease( pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
void squeeze ()
*/
HB_FUNC( QBYTEARRAY_SQUEEZE )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->squeeze (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool startsWith ( const QByteArray & ba ) const
*/
HB_FUNC( QBYTEARRAY_STARTSWITH1 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->startsWith ( *par1 );
    hb_retl( b );
  }
}


/*
bool startsWith ( const char * str ) const
*/
HB_FUNC( QBYTEARRAY_STARTSWITH2 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    bool b = obj->startsWith (  (const char *) par1 );
    hb_retl( b );
  }
}


/*
bool startsWith ( char ch ) const
*/
HB_FUNC( QBYTEARRAY_STARTSWITH3 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    char par1 = ISCHAR(1)? (char) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    bool b = obj->startsWith ( par1 );
    hb_retl( b );
  }
}


//[1]bool startsWith ( const QByteArray & ba ) const
//[2]bool startsWith ( const char * str ) const
//[3]bool startsWith ( char ch ) const

HB_FUNC( QBYTEARRAY_STARTSWITH )
{
  if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_STARTSWITH1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_STARTSWITH2 );
  }
  else if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QBYTEARRAY_STARTSWITH3 );
  }
}

/*
QByteArray toBase64 () const
*/
HB_FUNC( QBYTEARRAY_TOBASE64 )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->toBase64 (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
double toDouble ( bool * ok = 0 ) const
*/
HB_FUNC( QBYTEARRAY_TODOUBLE )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1;
    double r = obj->toDouble ( &par1 );
    hb_retnd( r );
    hb_storl( par1, 1 );
  }
}


/*
float toFloat ( bool * ok = 0 ) const
*/
HB_FUNC( QBYTEARRAY_TOFLOAT )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1;
    float r = obj->toFloat ( &par1 );
    hb_retnd( r );
    hb_storl( par1, 1 );
  }
}


/*
QByteArray toHex () const
*/
HB_FUNC( QBYTEARRAY_TOHEX )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->toHex (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
int toInt ( bool * ok = 0, int base = 10 ) const
*/
HB_FUNC( QBYTEARRAY_TOINT )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1;
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    int i = obj->toInt ( &par1, par2 );
    hb_retni( i );
    hb_storl( par1, 1 );
  }
}


/*
long toLong ( bool * ok = 0, int base = 10 ) const
*/
HB_FUNC( QBYTEARRAY_TOLONG )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1;
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    long l = obj->toLong ( &par1, par2 );
    hb_retnl( l );
    hb_storl( par1, 1 );
  }
}


/*
qlonglong toLongLong ( bool * ok = 0, int base = 10 ) const
*/
HB_FUNC( QBYTEARRAY_TOLONGLONG )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1;
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    qlonglong l = obj->toLongLong ( &par1, par2 );
    hb_retnl( l );
    hb_storl( par1, 1 );
  }
}


/*
QByteArray toLower () const
*/
HB_FUNC( QBYTEARRAY_TOLOWER )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->toLower (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray toPercentEncoding ( const QByteArray & exclude = QByteArray(), const QByteArray & include = QByteArray(), char percent = '%' ) const
*/
HB_FUNC( QBYTEARRAY_TOPERCENTENCODING )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray par1 = ISNIL(1)? QByteArray() : *(QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QByteArray par2 = ISNIL(2)? QByteArray() : *(QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    char par3 = ISNIL(3)? 37 : (ISCHAR(3)? (char) hb_parc(3)[0] : (ISNUM(3)? hb_parni(3) : 0));
    QByteArray * ptr = new QByteArray( obj->toPercentEncoding ( par1, par2, par3 ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
short toShort ( bool * ok = 0, int base = 10 ) const
*/
HB_FUNC( QBYTEARRAY_TOSHORT )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1;
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    short i = obj->toShort ( &par1, par2 );
    hb_retni( i );
    hb_storl( par1, 1 );
  }
}


/*
uint toUInt ( bool * ok = 0, int base = 10 ) const
*/
HB_FUNC( QBYTEARRAY_TOUINT )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1;
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    uint i = obj->toUInt ( &par1, par2 );
    hb_retni( i );
    hb_storl( par1, 1 );
  }
}


/*
ulong toULong ( bool * ok = 0, int base = 10 ) const
*/
HB_FUNC( QBYTEARRAY_TOULONG )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1;
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    ulong l = obj->toULong ( &par1, par2 );
    hb_retnl( l );
    hb_storl( par1, 1 );
  }
}


/*
qulonglong toULongLong ( bool * ok = 0, int base = 10 ) const
*/
HB_FUNC( QBYTEARRAY_TOULONGLONG )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1;
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    qulonglong l = obj->toULongLong ( &par1, par2 );
    hb_retnl( l );
    hb_storl( par1, 1 );
  }
}


/*
ushort toUShort ( bool * ok = 0, int base = 10 ) const
*/
HB_FUNC( QBYTEARRAY_TOUSHORT )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1;
    int par2 = ISNIL(2)? 10 : hb_parni(2);
    ushort i = obj->toUShort ( &par1, par2 );
    hb_retni( i );
    hb_storl( par1, 1 );
  }
}


/*
QByteArray toUpper () const
*/
HB_FUNC( QBYTEARRAY_TOUPPER )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->toUpper (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
QByteArray trimmed () const
*/
HB_FUNC( QBYTEARRAY_TRIMMED )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QByteArray * ptr = new QByteArray( obj->trimmed (  ) );
    _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );  }
}


/*
void truncate ( int pos )
*/
HB_FUNC( QBYTEARRAY_TRUNCATE )
{
  QByteArray * obj = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->truncate ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
QByteArray fromBase64 ( const QByteArray & base64 )
*/
HB_FUNC( QBYTEARRAY_FROMBASE64 )
{
  QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QByteArray * ptr = new QByteArray( QByteArray::fromBase64 ( *par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


/*
QByteArray fromHex ( const QByteArray & hexEncoded )
*/
HB_FUNC( QBYTEARRAY_FROMHEX )
{
  QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QByteArray * ptr = new QByteArray( QByteArray::fromHex ( *par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


/*
QByteArray fromPercentEncoding ( const QByteArray & input, char percent = '%' )
*/
HB_FUNC( QBYTEARRAY_FROMPERCENTENCODING )
{
  QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  char par2 = ISNIL(2)? 37 : (ISCHAR(2)? (char) hb_parc(2)[0] : (ISNUM(2)? hb_parni(2) : 0));
  QByteArray * ptr = new QByteArray( QByteArray::fromPercentEncoding ( *par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


/*
QByteArray fromRawData ( const char * data, int size )
*/
HB_FUNC( QBYTEARRAY_FROMRAWDATA )
{
  const char * par1 = hb_parc(1);
  int par2 = hb_parni(2);
  QByteArray * ptr = new QByteArray( QByteArray::fromRawData (  (const char *) par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


/*
QByteArray number ( int n, int base = 10 )
*/
HB_FUNC( QBYTEARRAY_NUMBER1 )
{
  int par1 = hb_parni(1);
  int par2 = ISNIL(2)? 10 : hb_parni(2);
  QByteArray * ptr = new QByteArray( QByteArray::number ( par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


/*
QByteArray number ( uint n, int base = 10 )
*/
HB_FUNC( QBYTEARRAY_NUMBER2 )
{
  uint par1 = hb_parni(1);
  int par2 = ISNIL(2)? 10 : hb_parni(2);
  QByteArray * ptr = new QByteArray( QByteArray::number ( par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


/*
QByteArray number ( qlonglong n, int base = 10 )
*/
HB_FUNC( QBYTEARRAY_NUMBER3 )
{
  qlonglong par1 = hb_parnl(1);
  int par2 = ISNIL(2)? 10 : hb_parni(2);
  QByteArray * ptr = new QByteArray( QByteArray::number ( par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


/*
QByteArray number ( qulonglong n, int base = 10 )
*/
HB_FUNC( QBYTEARRAY_NUMBER4 )
{
  qulonglong par1 = hb_parnl(1);
  int par2 = ISNIL(2)? 10 : hb_parni(2);
  QByteArray * ptr = new QByteArray( QByteArray::number ( par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}


/*
QByteArray number ( double n, char f = 'g', int prec = 6 )
*/
HB_FUNC( QBYTEARRAY_NUMBER5 )
{
  double par1 = hb_parnd(1);
  char par2 = ISNIL(2)? 103 : (ISCHAR(2)? (char) hb_parc(2)[0] : (ISNUM(2)? hb_parni(2) : 0));
  int par3 = ISNIL(3)? 6 : hb_parni(3);
  QByteArray * ptr = new QByteArray( QByteArray::number ( par1, par2, par3 ) );
  _qt4xhb_createReturnClass ( ptr, "QBYTEARRAY" );}



