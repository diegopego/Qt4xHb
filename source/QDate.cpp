/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QDate>

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
QDate ()
*/
HB_FUNC( QDATE_NEW1 )
{
  QDate * o = NULL;
  o = new QDate (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDate *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QDate ( int y, int m, int d )
*/
HB_FUNC( QDATE_NEW2 )
{
  QDate * o = NULL;
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  int par3 = hb_parni(3);
  o = new QDate ( par1, par2, par3 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QDate *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QDate ()
//[2]QDate ( int y, int m, int d )

HB_FUNC( QDATE_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QDATE_NEW1 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QDATE_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}


HB_FUNC( QDATE_DELETE )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QDate addDays ( int ndays ) const
*/
HB_FUNC( QDATE_ADDDAYS )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QDate * ptr = new QDate( obj->addDays ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QDATE", true );  }
}


/*
QDate addMonths ( int nmonths ) const
*/
HB_FUNC( QDATE_ADDMONTHS )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QDate * ptr = new QDate( obj->addMonths ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QDATE", true );  }
}


/*
QDate addYears ( int nyears ) const
*/
HB_FUNC( QDATE_ADDYEARS )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QDate * ptr = new QDate( obj->addYears ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QDATE", true );  }
}


/*
int day () const
*/
HB_FUNC( QDATE_DAY )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->day (  );
    hb_retni( i );
  }
}


/*
int dayOfWeek () const
*/
HB_FUNC( QDATE_DAYOFWEEK )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->dayOfWeek (  );
    hb_retni( i );
  }
}


/*
int dayOfYear () const
*/
HB_FUNC( QDATE_DAYOFYEAR )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->dayOfYear (  );
    hb_retni( i );
  }
}


/*
int daysInMonth () const
*/
HB_FUNC( QDATE_DAYSINMONTH )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->daysInMonth (  );
    hb_retni( i );
  }
}


/*
int daysInYear () const
*/
HB_FUNC( QDATE_DAYSINYEAR )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->daysInYear (  );
    hb_retni( i );
  }
}


/*
int daysTo ( const QDate & d ) const
*/
HB_FUNC( QDATE_DAYSTO )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDate * par1 = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    int i = obj->daysTo ( *par1 );
    hb_retni( i );
  }
}


/*
void getDate ( int * year, int * month, int * day )
*/
HB_FUNC( QDATE_GETDATE )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1;
    int par2;
    int par3;
    obj->getDate ( &par1, &par2, &par3 );
    hb_storni( par1, 1 );
    hb_storni( par2, 2 );
    hb_storni( par3, 3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool isNull () const
*/
HB_FUNC( QDATE_ISNULL )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
bool isValid () const
*/
HB_FUNC( QDATE_ISVALID1 )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
int month () const
*/
HB_FUNC( QDATE_MONTH )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->month (  );
    hb_retni( i );
  }
}


/*
bool setDate ( int year, int month, int day )
*/
HB_FUNC( QDATE_SETDATE )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    bool b = obj->setDate ( par1, par2, par3 );
    hb_retl( b );
  }
}


/*
int toJulianDay () const
*/
HB_FUNC( QDATE_TOJULIANDAY )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->toJulianDay (  );
    hb_retni( i );
  }
}


/*
QString toString ( const QString & format ) const
*/
HB_FUNC( QDATE_TOSTRING1 )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString str1 = obj->toString ( par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString toString ( Qt::DateFormat format = Qt::TextDate ) const
*/
HB_FUNC( QDATE_TOSTRING2 )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) Qt::TextDate : hb_parni(1);
    QString str1 = obj->toString (  (Qt::DateFormat) par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


//[1]QString toString ( const QString & format ) const
//[2]QString toString ( Qt::DateFormat format = Qt::TextDate ) const

HB_FUNC( QDATE_TOSTRING )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QDATE_TOSTRING1 );
  }
  else if( ISBETWEEN(0,1) && (ISNUM(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QDATE_TOSTRING2 );
  }
}

/*
int weekNumber ( int * yearNumber = 0 ) const
*/
HB_FUNC( QDATE_WEEKNUMBER )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1;
    int i = obj->weekNumber ( &par1 );
    hb_retni( i );
    hb_storni( par1, 1 );
  }
}


/*
int year () const
*/
HB_FUNC( QDATE_YEAR )
{
  QDate * obj = (QDate *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->year (  );
    hb_retni( i );
  }
}



/*
QDate currentDate ()
*/
HB_FUNC( QDATE_CURRENTDATE )
{
  QDate * ptr = new QDate( QDate::currentDate (  ) );
  _qt4xhb_createReturnClass ( ptr, "QDATE", true );}


/*
QDate fromJulianDay ( int jd )
*/
HB_FUNC( QDATE_FROMJULIANDAY )
{
  int par1 = hb_parni(1);
  QDate * ptr = new QDate( QDate::fromJulianDay ( par1 ) );
  _qt4xhb_createReturnClass ( ptr, "QDATE", true );}


/*
QDate fromString ( const QString & string, Qt::DateFormat format = Qt::TextDate )
*/
HB_FUNC( QDATE_FROMSTRING1 )
{
  QString par1 = hb_parc(1);
  int par2 = ISNIL(2)? (int) Qt::TextDate : hb_parni(2);
  QDate * ptr = new QDate( QDate::fromString ( par1,  (Qt::DateFormat) par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QDATE", true );}


/*
QDate fromString ( const QString & string, const QString & format )
*/
HB_FUNC( QDATE_FROMSTRING2 )
{
  QString par1 = hb_parc(1);
  QString par2 = hb_parc(2);
  QDate * ptr = new QDate( QDate::fromString ( par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QDATE", true );}


//[1]QDate fromString ( const QString & string, Qt::DateFormat format = Qt::TextDate )
//[2]QDate fromString ( const QString & string, const QString & format )

HB_FUNC( QDATE_FROMSTRING )
{
  if( ISBETWEEN(1,2) && ISCHAR(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QDATE_FROMSTRING1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QDATE_FROMSTRING2 );
  }
}

/*
bool isLeapYear ( int year )
*/
HB_FUNC( QDATE_ISLEAPYEAR )
{
  int par1 = hb_parni(1);
  bool b = QDate::isLeapYear ( par1 );
  hb_retl( b );
}


/*
bool isValid ( int year, int month, int day )
*/
HB_FUNC( QDATE_ISVALID2 )
{
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  int par3 = hb_parni(3);
  bool b = QDate::isValid ( par1, par2, par3 );
  hb_retl( b );
}


//[1]bool isValid () const
//[2]bool isValid ( int year, int month, int day )

HB_FUNC( QDATE_ISVALID )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QDATE_ISVALID1 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QDATE_ISVALID2 );
  }
}

/*
QString longDayName ( int weekday )
*/
HB_FUNC( QDATE_LONGDAYNAME1 )
{
  int par1 = hb_parni(1);
  QString str1 = QDate::longDayName ( par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString longDayName ( int weekday, MonthNameType type )
*/
HB_FUNC( QDATE_LONGDAYNAME2 )
{
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  QString str1 = QDate::longDayName ( par1,  (QDate::MonthNameType) par2 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


//[1]QString longDayName ( int weekday )
//[2]QString longDayName ( int weekday, MonthNameType type )

HB_FUNC( QDATE_LONGDAYNAME )
{
  if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QDATE_LONGDAYNAME1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QDATE_LONGDAYNAME2 );
  }
}

/*
QString longMonthName ( int month )
*/
HB_FUNC( QDATE_LONGMONTHNAME1 )
{
  int par1 = hb_parni(1);
  QString str1 = QDate::longMonthName ( par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString longMonthName ( int month, MonthNameType type )
*/
HB_FUNC( QDATE_LONGMONTHNAME2 )
{
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  QString str1 = QDate::longMonthName ( par1,  (QDate::MonthNameType) par2 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


//[1]QString longMonthName ( int month )
//[2]QString longMonthName ( int month, MonthNameType type )

HB_FUNC( QDATE_LONGMONTHNAME )
{
  if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QDATE_LONGMONTHNAME1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QDATE_LONGMONTHNAME2 );
  }
}

/*
QString shortDayName ( int weekday )
*/
HB_FUNC( QDATE_SHORTDAYNAME1 )
{
  int par1 = hb_parni(1);
  QString str1 = QDate::shortDayName ( par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString shortDayName ( int weekday, MonthNameType type )
*/
HB_FUNC( QDATE_SHORTDAYNAME2 )
{
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  QString str1 = QDate::shortDayName ( par1,  (QDate::MonthNameType) par2 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


//[1]QString shortDayName ( int weekday )
//[2]QString shortDayName ( int weekday, MonthNameType type )

HB_FUNC( QDATE_SHORTDAYNAME )
{
  if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QDATE_SHORTDAYNAME1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QDATE_SHORTDAYNAME2 );
  }
}

/*
QString shortMonthName ( int month )
*/
HB_FUNC( QDATE_SHORTMONTHNAME1 )
{
  int par1 = hb_parni(1);
  QString str1 = QDate::shortMonthName ( par1 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


/*
QString shortMonthName ( int month, MonthNameType type )
*/
HB_FUNC( QDATE_SHORTMONTHNAME2 )
{
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  QString str1 = QDate::shortMonthName ( par1,  (QDate::MonthNameType) par2 );
  hb_retc( (const char *) str1.toLatin1().data() );
}


//[1]QString shortMonthName ( int month )
//[2]QString shortMonthName ( int month, MonthNameType type )

HB_FUNC( QDATE_SHORTMONTHNAME )
{
  if( ISNUMPAR(1) && ISNUM(1) )
  {
    HB_FUNC_EXEC( QDATE_SHORTMONTHNAME1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QDATE_SHORTMONTHNAME2 );
  }
}


