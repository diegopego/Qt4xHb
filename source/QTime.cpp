/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QTime>

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
QTime()
*/
HB_FUNC( QTIME_NEW1 )
{
  QTime * o = NULL;
  o = new QTime (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTime *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QTime(int h, int m, int s = 0, int ms = 0)
*/
HB_FUNC( QTIME_NEW2 )
{
  QTime * o = NULL;
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  int par3 = ISNIL(3)? 0 : hb_parni(3);
  int par4 = ISNIL(4)? 0 : hb_parni(4);
  o = new QTime ( par1, par2, par3, par4 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QTime *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QTime()
//[2]QTime(int h, int m, int s = 0, int ms = 0)

HB_FUNC( QTIME_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QTIME_NEW1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QTIME_NEW2 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QTIME_NEW2 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QTIME_NEW2 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNIL(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QTIME_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QTIME_DELETE )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QTime addMSecs(int ms) const
*/
HB_FUNC( QTIME_ADDMSECS )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTime * ptr = new QTime( obj->addMSecs ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QTIME", true );  }
}


/*
QTime addSecs(int s) const
*/
HB_FUNC( QTIME_ADDSECS )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTime * ptr = new QTime( obj->addSecs ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QTIME", true );  }
}


/*
int elapsed() const
*/
HB_FUNC( QTIME_ELAPSED )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->elapsed (  );
    hb_retni( i );
  }
}


/*
int hour() const
*/
HB_FUNC( QTIME_HOUR )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->hour (  );
    hb_retni( i );
  }
}


/*
bool isNull() const
*/
HB_FUNC( QTIME_ISNULL )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
bool isValid() const
*/
HB_FUNC( QTIME_ISVALID1 )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
int minute() const
*/
HB_FUNC( QTIME_MINUTE )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->minute (  );
    hb_retni( i );
  }
}


/*
int msec() const
*/
HB_FUNC( QTIME_MSEC )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->msec (  );
    hb_retni( i );
  }
}


/*
int msecsTo(const QTime & t) const
*/
HB_FUNC( QTIME_MSECSTO )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTime * par1 = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->msecsTo ( *par1 );
    hb_retni( i );
  }
}


/*
int restart()
*/
HB_FUNC( QTIME_RESTART )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->restart (  );
    hb_retni( i );
  }
}


/*
int second() const
*/
HB_FUNC( QTIME_SECOND )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->second (  );
    hb_retni( i );
  }
}


/*
int secsTo(const QTime & t) const
*/
HB_FUNC( QTIME_SECSTO )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTime * par1 = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->secsTo ( *par1 );
    hb_retni( i );
  }
}


/*
bool setHMS(int h, int m, int s, int ms = 0)
*/
HB_FUNC( QTIME_SETHMS )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    int par4 = ISNIL(4)? 0 : hb_parni(4);
    bool b = obj->setHMS ( par1, par2, par3, par4 );
    hb_retl( b );
  }
}


/*
void start()
*/
HB_FUNC( QTIME_START )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->start (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString toString(const QString & format) const
*/
HB_FUNC( QTIME_TOSTRING1 )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString str1 = obj->toString ( par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString toString(Qt::DateFormat format = Qt::TextDate) const
*/
HB_FUNC( QTIME_TOSTRING2 )
{
  QTime * obj = (QTime *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) Qt::TextDate : hb_parni(1);
    QString str1 = obj->toString (  (Qt::DateFormat) par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


//[1]QString toString(const QString & format) const
//[2]QString toString(Qt::DateFormat format = Qt::TextDate) const

HB_FUNC( QTIME_TOSTRING )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QTIME_TOSTRING1 );
  }
  else if( ISBETWEEN(0,1) && (ISNUM(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QTIME_TOSTRING2 );
  }
}


/*
QTime currentTime()
*/
HB_FUNC( QTIME_CURRENTTIME )
{
  QTime * ptr = new QTime( QTime::currentTime (  ) );
  _qt4xhb_createReturnClass ( ptr, "QTIME", true );}


/*
QTime fromString(const QString & string, Qt::DateFormat format = Qt::TextDate)
*/
HB_FUNC( QTIME_FROMSTRING1 )
{
  QString par1 = hb_parc(1);
  int par2 = ISNIL(2)? (int) Qt::TextDate : hb_parni(2);
  QTime * ptr = new QTime( QTime::fromString ( par1,  (Qt::DateFormat) par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QTIME", true );}


/*
QTime fromString(const QString & string, const QString & format)
*/
HB_FUNC( QTIME_FROMSTRING2 )
{
  QString par1 = hb_parc(1);
  QString par2 = hb_parc(2);
  QTime * ptr = new QTime( QTime::fromString ( par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QTIME", true );}


//[1]QTime fromString(const QString & string, Qt::DateFormat format = Qt::TextDate)
//[2]QTime fromString(const QString & string, const QString & format)

HB_FUNC( QTIME_FROMSTRING )
{
  if( ISBETWEEN(1,2) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QTIME_FROMSTRING1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QTIME_FROMSTRING2 );
  }
}

/*
bool isValid(int h, int m, int s, int ms = 0)
*/
HB_FUNC( QTIME_ISVALID2 )
{
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  int par3 = hb_parni(3);
  int par4 = ISNIL(4)? 0 : hb_parni(4);
  bool b = QTime::isValid ( par1, par2, par3, par4 );
  hb_retl( b );
}


//[1]bool isValid() const
//[2]bool isValid(int h, int m, int s, int ms = 0)

HB_FUNC( QTIME_ISVALID )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QTIME_ISVALID1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QTIME_ISVALID2 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QTIME_ISVALID2 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QTIME_ISVALID2 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNIL(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QTIME_ISVALID2 );
  }
}


