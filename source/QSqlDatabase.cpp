/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QSqlDatabase>

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

#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include <QSqlIndex>
#include <QSqlRecord>

/*
QSqlDatabase ()
*/
HB_FUNC( QSQLDATABASE_NEW1 )
{
  QSqlDatabase * o = NULL;
  o = new QSqlDatabase (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSqlDatabase *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QSqlDatabase ( const QSqlDatabase & other )
*/
HB_FUNC( QSQLDATABASE_NEW2 )
{
  QSqlDatabase * o = NULL;
  QSqlDatabase * par1 = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QSqlDatabase ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSqlDatabase *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QSqlDatabase ()
//[2]QSqlDatabase ( const QSqlDatabase & other )

HB_FUNC( QSQLDATABASE_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QSQLDATABASE_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQSQLDATABASE(1) )
  {
    HB_FUNC_EXEC( QSQLDATABASE_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QSQLDATABASE_DELETE )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void close ()
*/
HB_FUNC( QSQLDATABASE_CLOSE )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->close (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool commit ()
*/
HB_FUNC( QSQLDATABASE_COMMIT )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->commit (  );
    hb_retl( b );
  }
}


/*
QString connectOptions () const
*/
HB_FUNC( QSQLDATABASE_CONNECTOPTIONS )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->connectOptions (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString connectionName () const
*/
HB_FUNC( QSQLDATABASE_CONNECTIONNAME )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->connectionName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString databaseName () const
*/
HB_FUNC( QSQLDATABASE_DATABASENAME )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->databaseName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QSqlDriver * driver () const
*/
HB_FUNC( QSQLDATABASE_DRIVER )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSqlDriver * ptr = obj->driver (  );
    _qt4xhb_createReturnClass ( ptr, "QSQLDRIVER" );  }
}


/*
QString driverName () const
*/
HB_FUNC( QSQLDATABASE_DRIVERNAME )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->driverName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QSqlQuery exec ( const QString & query = QString() ) const
*/
HB_FUNC( QSQLDATABASE_EXEC )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = ISNIL(1)? QString() : hb_parc(1);
    QSqlQuery * ptr = new QSqlQuery( obj->exec ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSQLQUERY", true );  }
}


/*
QString hostName () const
*/
HB_FUNC( QSQLDATABASE_HOSTNAME )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->hostName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
bool isOpen () const
*/
HB_FUNC( QSQLDATABASE_ISOPEN )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isOpen (  );
    hb_retl( b );
  }
}


/*
bool isOpenError () const
*/
HB_FUNC( QSQLDATABASE_ISOPENERROR )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isOpenError (  );
    hb_retl( b );
  }
}


/*
bool isValid () const
*/
HB_FUNC( QSQLDATABASE_ISVALID )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
QSqlError lastError () const
*/
HB_FUNC( QSQLDATABASE_LASTERROR )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSqlError * ptr = new QSqlError( obj->lastError (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSQLERROR", true );  }
}


/*
QSql::NumericalPrecisionPolicy numericalPrecisionPolicy () const
*/
HB_FUNC( QSQLDATABASE_NUMERICALPRECISIONPOLICY )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->numericalPrecisionPolicy (  );
    hb_retni( i );
  }
}


/*
bool open ()
*/
HB_FUNC( QSQLDATABASE_OPEN1 )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->open (  );
    hb_retl( b );
  }
}


/*
bool open ( const QString & user, const QString & password )
*/
HB_FUNC( QSQLDATABASE_OPEN2 )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    bool b = obj->open ( par1, par2 );
    hb_retl( b );
  }
}


//[1]bool open ()
//[2]bool open ( const QString & user, const QString & password )

HB_FUNC( QSQLDATABASE_OPEN )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QSQLDATABASE_OPEN1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QSQLDATABASE_OPEN2 );
  }
}

/*
QString password () const
*/
HB_FUNC( QSQLDATABASE_PASSWORD )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->password (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
int port () const
*/
HB_FUNC( QSQLDATABASE_PORT )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->port (  );
    hb_retni( i );
  }
}


/*
QSqlIndex primaryIndex ( const QString & tablename ) const
*/
HB_FUNC( QSQLDATABASE_PRIMARYINDEX )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QSqlIndex * ptr = new QSqlIndex( obj->primaryIndex ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSQLINDEX", true );  }
}


/*
QSqlRecord record ( const QString & tablename ) const
*/
HB_FUNC( QSQLDATABASE_RECORD )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QSqlRecord * ptr = new QSqlRecord( obj->record ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSQLRECORD", true );  }
}


/*
bool rollback ()
*/
HB_FUNC( QSQLDATABASE_ROLLBACK )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->rollback (  );
    hb_retl( b );
  }
}


/*
void setConnectOptions ( const QString & options = QString() )
*/
HB_FUNC( QSQLDATABASE_SETCONNECTOPTIONS )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = ISNIL(1)? QString() : hb_parc(1);
    obj->setConnectOptions ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDatabaseName ( const QString & name )
*/
HB_FUNC( QSQLDATABASE_SETDATABASENAME )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setDatabaseName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHostName ( const QString & host )
*/
HB_FUNC( QSQLDATABASE_SETHOSTNAME )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setHostName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setNumericalPrecisionPolicy ( QSql::NumericalPrecisionPolicy precisionPolicy )
*/
HB_FUNC( QSQLDATABASE_SETNUMERICALPRECISIONPOLICY )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setNumericalPrecisionPolicy (  (QSql::NumericalPrecisionPolicy) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPassword ( const QString & password )
*/
HB_FUNC( QSQLDATABASE_SETPASSWORD )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setPassword ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPort ( int port )
*/
HB_FUNC( QSQLDATABASE_SETPORT )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setPort ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUserName ( const QString & name )
*/
HB_FUNC( QSQLDATABASE_SETUSERNAME )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setUserName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QStringList tables ( QSql::TableType type = QSql::Tables ) const
*/
HB_FUNC( QSQLDATABASE_TABLES )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = ISNIL(1)? (int) QSql::Tables : hb_parni(1);
    QStringList strl = obj->tables (  (QSql::TableType) par1 );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<strl.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutC( NULL, (const char *) strl[i].toLatin1().data() );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
bool transaction ()
*/
HB_FUNC( QSQLDATABASE_TRANSACTION )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->transaction (  );
    hb_retl( b );
  }
}


/*
QString userName () const
*/
HB_FUNC( QSQLDATABASE_USERNAME )
{
  QSqlDatabase * obj = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->userName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
  Static Public Members
*/



/*
QSqlDatabase addDatabase ( const QString & type, const QString & connectionName = QLatin1String( defaultConnection ) )
*/
HB_FUNC( QSQLDATABASE_ADDDATABASE1 )
{
  QString par1 = hb_parc(1);
  QString par2;
  if( ISNIL(2) )
  {
    par2 = QLatin1String(QSqlDatabase::defaultConnection);
  }
  else
  {
    par2 = hb_parc(2);
  }
  QSqlDatabase * ptr = new QSqlDatabase( QSqlDatabase::addDatabase ( par1, par2 ) );
  PHB_DYNS pDynSym;
  #ifdef __XHARBOUR__
  pDynSym = hb_dynsymFind( "QSQLDATABASE" );
  #else
  pDynSym = hb_dynsymFindName( "QSQLDATABASE" );
  #endif
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
    hb_itemPutPtr( pItem, (QSqlDatabase *) ptr );
    hb_objSendMsg( pObject, "NEWFROMPOINTER", 1, pItem );
    hb_itemReturn( pObject );
    hb_itemRelease( pObject );
    hb_itemRelease( pItem );
  }
}


/*
QSqlDatabase addDatabase ( QSqlDriver * driver, const QString & connectionName = QLatin1String( defaultConnection ) )
*/
HB_FUNC( QSQLDATABASE_ADDDATABASE2 )
{
  QSqlDriver * par1 = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QString par2;
  if( ISNIL(2) )
  {
    par2 = QLatin1String(QSqlDatabase::defaultConnection);
  }
  else
  {
    par2 = hb_parc(2);
  }
  QSqlDatabase * ptr = new QSqlDatabase( QSqlDatabase::addDatabase ( par1, par2 ) );
  PHB_DYNS pDynSym;
  #ifdef __XHARBOUR__
  pDynSym = hb_dynsymFind( "QSQLDATABASE" );
  #else
  pDynSym = hb_dynsymFindName( "QSQLDATABASE" );
  #endif
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
    hb_itemPutPtr( pItem, (QSqlDatabase *) ptr );
    hb_objSendMsg( pObject, "NEWFROMPOINTER", 1, pItem );
    hb_itemReturn( pObject );
    hb_itemRelease( pObject );
    hb_itemRelease( pItem );
  }
}

//[1]QSqlDatabase addDatabase ( const QString & type, const QString & connectionName = QLatin1String( defaultConnection ) )
//[2]QSqlDatabase addDatabase ( QSqlDriver * driver, const QString & connectionName = QLatin1String( defaultConnection ) )

HB_FUNC( QSQLDATABASE_ADDDATABASE )
{
  if( ISBETWEEN(1,2) && ISCHAR(1) && (ISCHAR(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QSQLDATABASE_ADDDATABASE1 );
  }
  else if( ISBETWEEN(1,2) && ISQSQLDRIVER(1) && (ISCHAR(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QSQLDATABASE_ADDDATABASE2 );
  }
}

/*
QSqlDatabase cloneDatabase ( const QSqlDatabase & other, const QString & connectionName )
*/
HB_FUNC( QSQLDATABASE_CLONEDATABASE )
{
  QSqlDatabase * par1 = (QSqlDatabase *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QString par2 = hb_parc(2);
  QSqlDatabase * ptr = new QSqlDatabase( QSqlDatabase::cloneDatabase ( *par1, par2 ) );
  _qt4xhb_createReturnClass ( ptr, "QSQLDATABASE" );}


/*
QStringList connectionNames ()
*/
HB_FUNC( QSQLDATABASE_CONNECTIONNAMES )
{
  QStringList strl = QSqlDatabase::connectionNames (  );
  PHB_ITEM pArray;
  pArray = hb_itemArrayNew(0);
  int i;
  for(i=0;i<strl.count();i++)
  {
    PHB_ITEM pItem = hb_itemPutC( NULL, (const char *) strl[i].toLatin1().data() );
    hb_arrayAddForward( pArray, pItem );
    hb_itemRelease(pItem);
  }
  hb_itemReturnRelease(pArray);
}



/*
bool contains ( const QString & connectionName = QLatin1String( defaultConnection ) )
*/
HB_FUNC( QSQLDATABASE_CONTAINS )
{
  QString par1;
  if( ISNIL(1) )
  {
    par1 = QLatin1String(QSqlDatabase::defaultConnection);
  }
  else
  {
    par1 = hb_parc(1);
  }
  bool b = QSqlDatabase::contains ( par1 );
  hb_retl( b );
}


/*
QSqlDatabase database ( const QString & connectionName = QLatin1String( defaultConnection ), bool open = true )
*/
HB_FUNC( QSQLDATABASE_DATABASE )
{
  QString par1;
  if( ISNIL(1) )
  {
    par1 = QLatin1String(QSqlDatabase::defaultConnection);
  }
  else
  {
    par1 = hb_parc(1);
  }
  bool par2 = hb_parl(2);
  QSqlDatabase * ptr = new QSqlDatabase( QSqlDatabase::database ( par1, par2 ) );
  PHB_DYNS pDynSym;
  #ifdef __XHARBOUR__
  pDynSym = hb_dynsymFind( "QSQLDATABASE" );
  #else
  pDynSym = hb_dynsymFindName( "QSQLDATABASE" );
  #endif
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
    hb_itemPutPtr( pItem, (QSqlDatabase *) ptr );
    hb_objSendMsg( pObject, "NEWFROMPOINTER", 1, pItem );
    hb_itemReturn( pObject );
    hb_itemRelease( pObject );
    hb_itemRelease( pItem );
  }
}

/*
QStringList drivers ()
*/
HB_FUNC( QSQLDATABASE_DRIVERS )
{
  QStringList strl = QSqlDatabase::drivers (  );
  PHB_ITEM pArray;
  pArray = hb_itemArrayNew(0);
  int i;
  for(i=0;i<strl.count();i++)
  {
    PHB_ITEM pItem = hb_itemPutC( NULL, (const char *) strl[i].toLatin1().data() );
    hb_arrayAddForward( pArray, pItem );
    hb_itemRelease(pItem);
  }
  hb_itemReturnRelease(pArray);
}


/*
bool isDriverAvailable ( const QString & name )
*/
HB_FUNC( QSQLDATABASE_ISDRIVERAVAILABLE )
{
  QString par1 = hb_parc(1);
  bool b = QSqlDatabase::isDriverAvailable ( par1 );
  hb_retl( b );
}


/*
void registerSqlDriver ( const QString & name, QSqlDriverCreatorBase * creator )
*/
HB_FUNC( QSQLDATABASE_REGISTERSQLDRIVER )
{
  QString par1 = hb_parc(1);
  QSqlDriverCreatorBase * par2 = (QSqlDriverCreatorBase *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  QSqlDatabase::registerSqlDriver ( par1, par2 );
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeDatabase ( const QString & connectionName )
*/
HB_FUNC( QSQLDATABASE_REMOVEDATABASE )
{
  QString par1 = hb_parc(1);
  QSqlDatabase::removeDatabase ( par1 );
  hb_itemReturn( hb_stackSelfItem() );
}



