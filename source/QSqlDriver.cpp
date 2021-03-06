/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QSqlDriver>

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

#include <QSqlError>
#include <QSqlIndex>
#include <QSqlRecord>
#include <QVariant>


HB_FUNC( QSQLDRIVER_DELETE )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual bool beginTransaction ()
*/
HB_FUNC( QSQLDRIVER_BEGINTRANSACTION )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->beginTransaction (  );
    hb_retl( b );
  }
}


/*
virtual void close () = 0
*/
HB_FUNC( QSQLDRIVER_CLOSE )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->close (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual bool commitTransaction ()
*/
HB_FUNC( QSQLDRIVER_COMMITTRANSACTION )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->commitTransaction (  );
    hb_retl( b );
  }
}


/*
virtual QSqlResult * createResult () const = 0
*/
HB_FUNC( QSQLDRIVER_CREATERESULT )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSqlResult * ptr = obj->createResult (  );
    _qt4xhb_createReturnClass ( ptr, "QSQLRESULT" );  }
}


/*
virtual QString escapeIdentifier ( const QString & identifier, IdentifierType type ) const
*/
HB_FUNC( QSQLDRIVER_ESCAPEIDENTIFIER )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = hb_parni(2);
    QString str1 = obj->escapeIdentifier ( par1,  (QSqlDriver::IdentifierType) par2 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual QString formatValue ( const QSqlField & field, bool trimStrings = false ) const
*/
HB_FUNC( QSQLDRIVER_FORMATVALUE )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSqlField * par1 = (QSqlField *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool par2 = ISNIL(2)? false : hb_parl(2);
    QString str1 = obj->formatValue ( *par1, par2 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual QVariant handle () const
*/
HB_FUNC( QSQLDRIVER_HANDLE )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVariant * ptr = new QVariant( obj->handle (  ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
virtual bool hasFeature ( DriverFeature feature ) const = 0
*/
HB_FUNC( QSQLDRIVER_HASFEATURE )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->hasFeature (  (QSqlDriver::DriverFeature) par1 );
    hb_retl( b );
  }
}


/*
bool isIdentifierEscaped ( const QString & identifier, IdentifierType type ) const
*/
HB_FUNC( QSQLDRIVER_ISIDENTIFIERESCAPED )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = hb_parni(2);
    bool b = obj->isIdentifierEscaped ( par1,  (QSqlDriver::IdentifierType) par2 );
    hb_retl( b );
  }
}


/*
virtual bool isOpen () const
*/
HB_FUNC( QSQLDRIVER_ISOPEN )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isOpen (  );
    hb_retl( b );
  }
}


/*
bool isOpenError () const
*/
HB_FUNC( QSQLDRIVER_ISOPENERROR )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isOpenError (  );
    hb_retl( b );
  }
}


/*
QSqlError lastError () const
*/
HB_FUNC( QSQLDRIVER_LASTERROR )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSqlError * ptr = new QSqlError( obj->lastError (  ) );
    _qt4xhb_createReturnClass ( ptr, "QSQLERROR", true );  }
}


/*
QSql::NumericalPrecisionPolicy numericalPrecisionPolicy () const
*/
HB_FUNC( QSQLDRIVER_NUMERICALPRECISIONPOLICY )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->numericalPrecisionPolicy (  );
    hb_retni( i );
  }
}


/*
virtual bool open ( const QString & db, const QString & user = QString(), const QString & password = QString(), const QString & host = QString(), int port = -1, const QString & options = QString() ) = 0
*/
HB_FUNC( QSQLDRIVER_OPEN )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    QString par3 = ISNIL(3)? QString() : hb_parc(3);
    QString par4 = ISNIL(4)? QString() : hb_parc(4);
    int par5 = ISNIL(5)? -1 : hb_parni(5);
    QString par6 = ISNIL(6)? QString() : hb_parc(6);
    bool b = obj->open ( par1, par2, par3, par4, par5, par6 );
    hb_retl( b );
  }
}


/*
virtual QSqlIndex primaryIndex ( const QString & tableName ) const
*/
HB_FUNC( QSQLDRIVER_PRIMARYINDEX )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QSqlIndex * ptr = new QSqlIndex( obj->primaryIndex ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSQLINDEX", true );  }
}


/*
virtual QSqlRecord record ( const QString & tableName ) const
*/
HB_FUNC( QSQLDRIVER_RECORD )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QSqlRecord * ptr = new QSqlRecord( obj->record ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QSQLRECORD", true );  }
}


/*
virtual bool rollbackTransaction ()
*/
HB_FUNC( QSQLDRIVER_ROLLBACKTRANSACTION )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->rollbackTransaction (  );
    hb_retl( b );
  }
}


/*
void setNumericalPrecisionPolicy ( QSql::NumericalPrecisionPolicy precisionPolicy )
*/
HB_FUNC( QSQLDRIVER_SETNUMERICALPRECISIONPOLICY )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setNumericalPrecisionPolicy (  (QSql::NumericalPrecisionPolicy) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QString sqlStatement ( StatementType type, const QString & tableName, const QSqlRecord & rec, bool preparedStatement ) const
*/
HB_FUNC( QSQLDRIVER_SQLSTATEMENT )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QString par2 = hb_parc(2);
    QSqlRecord * par3 = (QSqlRecord *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool par4 = hb_parl(4);
    QString str1 = obj->sqlStatement (  (QSqlDriver::StatementType) par1, par2, *par3, par4 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString stripDelimiters ( const QString & identifier, IdentifierType type ) const
*/
HB_FUNC( QSQLDRIVER_STRIPDELIMITERS )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = hb_parni(2);
    QString str1 = obj->stripDelimiters ( par1,  (QSqlDriver::IdentifierType) par2 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
bool subscribeToNotification ( const QString & name )
*/
HB_FUNC( QSQLDRIVER_SUBSCRIBETONOTIFICATION )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->subscribeToNotification ( par1 );
    hb_retl( b );
  }
}


/*
QStringList subscribedToNotifications () const
*/
HB_FUNC( QSQLDRIVER_SUBSCRIBEDTONOTIFICATIONS )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->subscribedToNotifications (  );
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
virtual QStringList tables ( QSql::TableType tableType ) const
*/
HB_FUNC( QSQLDRIVER_TABLES )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
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
bool unsubscribeFromNotification ( const QString & name )
*/
HB_FUNC( QSQLDRIVER_UNSUBSCRIBEFROMNOTIFICATION )
{
  QSqlDriver * obj = (QSqlDriver *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->unsubscribeFromNotification ( par1 );
    hb_retl( b );
  }
}




