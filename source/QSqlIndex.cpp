/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QSqlIndex>

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
QSqlIndex ( const QString & cursorname = QString(), const QString & name = QString() )
*/
HB_FUNC( QSQLINDEX_NEW1 )
{
  QSqlIndex * o = NULL;
  QString par1 = ISNIL(1)? QString() : hb_parc(1);
  QString par2 = ISNIL(2)? QString() : hb_parc(2);
  o = new QSqlIndex ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSqlIndex *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QSqlIndex ( const QSqlIndex & other )
*/
HB_FUNC( QSQLINDEX_NEW2 )
{
  QSqlIndex * o = NULL;
  QSqlIndex * par1 = (QSqlIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QSqlIndex ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSqlIndex *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QSqlIndex ( const QString & cursorname = QString(), const QString & name = QString() )
//[2]QSqlIndex ( const QSqlIndex & other )

HB_FUNC( QSQLINDEX_NEW )
{
  if( ISBETWEEN(0,2) && (ISCHAR(1)||ISNIL(1)) && (ISCHAR(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QSQLINDEX_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQSQLINDEX(1) )
  {
    HB_FUNC_EXEC( QSQLINDEX_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QSQLINDEX_DELETE )
{
  QSqlIndex * obj = (QSqlIndex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void append ( const QSqlField & field )
*/
HB_FUNC( QSQLINDEX_APPEND1 )
{
  QSqlIndex * obj = (QSqlIndex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSqlField * par1 = (QSqlField *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->append ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void append ( const QSqlField & field, bool desc )
*/
HB_FUNC( QSQLINDEX_APPEND2 )
{
  QSqlIndex * obj = (QSqlIndex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QSqlField * par1 = (QSqlField *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool par2 = hb_parl(2);
    obj->append ( *par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void append ( const QSqlField & field )
//[2]void append ( const QSqlField & field, bool desc )

HB_FUNC( QSQLINDEX_APPEND )
{
  if( ISNUMPAR(1) && ISQSQLFIELD(1) )
  {
    HB_FUNC_EXEC( QSQLINDEX_APPEND1 );
  }
  else if( ISNUMPAR(2) && ISQSQLFIELD(1) && ISLOG(2) )
  {
    HB_FUNC_EXEC( QSQLINDEX_APPEND2 );
  }
}

/*
QString cursorName () const
*/
HB_FUNC( QSQLINDEX_CURSORNAME )
{
  QSqlIndex * obj = (QSqlIndex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->cursorName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
bool isDescending ( int i ) const
*/
HB_FUNC( QSQLINDEX_ISDESCENDING )
{
  QSqlIndex * obj = (QSqlIndex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->isDescending ( par1 );
    hb_retl( b );
  }
}


/*
QString name () const
*/
HB_FUNC( QSQLINDEX_NAME )
{
  QSqlIndex * obj = (QSqlIndex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->name (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void setCursorName ( const QString & cursorName )
*/
HB_FUNC( QSQLINDEX_SETCURSORNAME )
{
  QSqlIndex * obj = (QSqlIndex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setCursorName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setDescending ( int i, bool desc )
*/
HB_FUNC( QSQLINDEX_SETDESCENDING )
{
  QSqlIndex * obj = (QSqlIndex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool par2 = hb_parl(2);
    obj->setDescending ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setName ( const QString & name )
*/
HB_FUNC( QSQLINDEX_SETNAME )
{
  QSqlIndex * obj = (QSqlIndex *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



