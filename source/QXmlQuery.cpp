/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QXmlQuery>

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
QXmlQuery ()
*/
HB_FUNC( QXMLQUERY_NEW1 )
{
  QXmlQuery * o = NULL;
  o = new QXmlQuery (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlQuery *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QXmlQuery ( const QXmlQuery & other )
*/
HB_FUNC( QXMLQUERY_NEW2 )
{
  QXmlQuery * o = NULL;
  QXmlQuery * par1 = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QXmlQuery ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlQuery *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QXmlQuery ( const QXmlNamePool & np )
*/
HB_FUNC( QXMLQUERY_NEW3 )
{
  QXmlQuery * o = NULL;
  QXmlNamePool * par1 = (QXmlNamePool *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QXmlQuery ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlQuery *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QXmlQuery ( QueryLanguage,QXmlNamePool & np = QXmlNamePool() )
*/
HB_FUNC( QXMLQUERY_NEW4 )
{
  QXmlQuery * o = NULL;
  int par1 = hb_parni(1);
  QXmlNamePool par2 = ISNIL(2)? QXmlNamePool() : *(QXmlNamePool *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QXmlQuery (  (QXmlQuery::QueryLanguage) par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlQuery *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QXmlQuery ()
//[2]QXmlQuery ( const QXmlQuery & other )
//[3]QXmlQuery ( const QXmlNamePool & np )
//[4]QXmlQuery ( QueryLanguage queryLanguage, const QXmlNamePool & np = QXmlNamePool() )

HB_FUNC( QXMLQUERY_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QXMLQUERY_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQXMLQUERY(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_NEW2 );
  }
  else if( ISNUMPAR(1) && ISQXMLNAMEPOOL(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_NEW3 );
  }
  else if( ISBETWEEN(1,2) && ISNUM(1) && (ISQXMLNAMEPOOL(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QXMLQUERY_NEW4 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QXMLQUERY_DELETE )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void bindVariable ( const QXmlName & name, const QXmlItem & value )
*/
HB_FUNC( QXMLQUERY_BINDVARIABLE1 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlName * par1 = (QXmlName *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QXmlItem * par2 = (QXmlItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->bindVariable ( *par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void bindVariable ( const QXmlName & name, QIODevice * device )
*/
HB_FUNC( QXMLQUERY_BINDVARIABLE2 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlName * par1 = (QXmlName *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QIODevice * par2 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->bindVariable ( *par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void bindVariable ( const QXmlName & name, const QXmlQuery & query )
*/
HB_FUNC( QXMLQUERY_BINDVARIABLE3 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlName * par1 = (QXmlName *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QXmlQuery * par2 = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->bindVariable ( *par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void bindVariable ( const QString & localName, const QXmlItem & value )
*/
HB_FUNC( QXMLQUERY_BINDVARIABLE4 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QXmlItem * par2 = (QXmlItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->bindVariable ( par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void bindVariable ( const QString & localName, QIODevice * device )
*/
HB_FUNC( QXMLQUERY_BINDVARIABLE5 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QIODevice * par2 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->bindVariable ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void bindVariable ( const QString & localName, const QXmlQuery & query )
*/
HB_FUNC( QXMLQUERY_BINDVARIABLE6 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QXmlQuery * par2 = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->bindVariable ( par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void bindVariable ( const QXmlName & name, const QXmlItem & value )
//[2]void bindVariable ( const QXmlName & name, QIODevice * device )
//[3]void bindVariable ( const QXmlName & name, const QXmlQuery & query )
//[4]void bindVariable ( const QString & localName, const QXmlItem & value )
//[5]void bindVariable ( const QString & localName, QIODevice * device )
//[6]void bindVariable ( const QString & localName, const QXmlQuery & query )

HB_FUNC( QXMLQUERY_BINDVARIABLE )
{
  if( ISNUMPAR(2) && ISQXMLNAME(1) && ISQXMLITEM(2) )
  {
    HB_FUNC_EXEC( QXMLQUERY_BINDVARIABLE1 );
  }
  else if( ISNUMPAR(2) && ISQXMLNAME(1) && ISQIODEVICE(2) )
  {
    HB_FUNC_EXEC( QXMLQUERY_BINDVARIABLE2 );
  }
  else if( ISNUMPAR(2) && ISQXMLNAME(1) && ISQXMLQUERY(2) )
  {
    HB_FUNC_EXEC( QXMLQUERY_BINDVARIABLE3 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISQXMLITEM(2) )
  {
    HB_FUNC_EXEC( QXMLQUERY_BINDVARIABLE4 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISQIODEVICE(2) )
  {
    HB_FUNC_EXEC( QXMLQUERY_BINDVARIABLE5 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISQXMLQUERY(2) )
  {
    HB_FUNC_EXEC( QXMLQUERY_BINDVARIABLE6 );
  }
}

/*
void evaluateTo ( QXmlResultItems * result ) const
*/
HB_FUNC( QXMLQUERY_EVALUATETO1 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlResultItems * par1 = (QXmlResultItems *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->evaluateTo ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool evaluateTo ( QAbstractXmlReceiver * callback ) const
*/
HB_FUNC( QXMLQUERY_EVALUATETO2 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractXmlReceiver * par1 = (QAbstractXmlReceiver *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->evaluateTo ( par1 );
    hb_retl( b );
  }
}



/*
bool evaluateTo ( QString * output ) const
*/
HB_FUNC( QXMLQUERY_EVALUATETO4 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString * par1 = NULL;
    bool b = obj->evaluateTo ( par1 );
    hb_retl( b );
  }
}


/*
bool evaluateTo ( QIODevice * target ) const
*/
HB_FUNC( QXMLQUERY_EVALUATETO5 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->evaluateTo ( par1 );
    hb_retl( b );
  }
}


//[1]void evaluateTo ( QXmlResultItems * result ) const
//[2]bool evaluateTo ( QAbstractXmlReceiver * callback ) const
//[3]bool evaluateTo ( QStringList * target ) const
//[4]bool evaluateTo ( QString * output ) const
//[5]bool evaluateTo ( QIODevice * target ) const

HB_FUNC( QXMLQUERY_EVALUATETO )
{
  if( ISNUMPAR(1) && ISQXMLRESULTITEMS(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_EVALUATETO1 );
  }
  else if( ISNUMPAR(1) && ISQABSTRACTXMLRECEIVER(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_EVALUATETO2 );
  }
  //else if( ISNUMPAR(1) && ISARRAY(1) )
  //{
  //  HB_FUNC_EXEC( QXMLQUERY_EVALUATETO3 );
  //}
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_EVALUATETO4 );
  }
  else if( ISNUMPAR(1) && ISQIODEVICE(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_EVALUATETO5 );
  }
}

/*
QXmlName initialTemplateName () const
*/
HB_FUNC( QXMLQUERY_INITIALTEMPLATENAME )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlName * ptr = new QXmlName( obj->initialTemplateName (  ) );
    _qt4xhb_createReturnClass ( ptr, "QXMLNAME", true );  }
}


/*
bool isValid () const
*/
HB_FUNC( QXMLQUERY_ISVALID )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
QAbstractMessageHandler * messageHandler () const
*/
HB_FUNC( QXMLQUERY_MESSAGEHANDLER )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractMessageHandler * ptr = obj->messageHandler (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTMESSAGEHANDLER" );  }
}


/*
QXmlNamePool namePool () const
*/
HB_FUNC( QXMLQUERY_NAMEPOOL )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlNamePool * ptr = new QXmlNamePool( obj->namePool (  ) );
    _qt4xhb_createReturnClass ( ptr, "QXMLNAMEPOOL", true );  }
}


/*
QNetworkAccessManager * networkAccessManager () const
*/
HB_FUNC( QXMLQUERY_NETWORKACCESSMANAGER )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QNetworkAccessManager * ptr = obj->networkAccessManager (  );
    _qt4xhb_createReturnClass ( ptr, "QNETWORKACCESSMANAGER" );  }
}


/*
QueryLanguage queryLanguage () const
*/
HB_FUNC( QXMLQUERY_QUERYLANGUAGE )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->queryLanguage (  );
    hb_retni( i );
  }
}


/*
void setFocus ( const QXmlItem & item )
*/
HB_FUNC( QXMLQUERY_SETFOCUS1 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlItem * par1 = (QXmlItem *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setFocus ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool setFocus ( const QUrl & documentURI )
*/
HB_FUNC( QXMLQUERY_SETFOCUS2 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * par1 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->setFocus ( *par1 );
    hb_retl( b );
  }
}


/*
bool setFocus ( QIODevice * document )
*/
HB_FUNC( QXMLQUERY_SETFOCUS3 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->setFocus ( par1 );
    hb_retl( b );
  }
}


/*
bool setFocus ( const QString & focus )
*/
HB_FUNC( QXMLQUERY_SETFOCUS4 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->setFocus ( par1 );
    hb_retl( b );
  }
}


//[1]void setFocus ( const QXmlItem & item )
//[2]bool setFocus ( const QUrl & documentURI )
//[3]bool setFocus ( QIODevice * document )
//[4]bool setFocus ( const QString & focus )

HB_FUNC( QXMLQUERY_SETFOCUS )
{
  if( ISNUMPAR(1) && ISQXMLITEM(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_SETFOCUS1 );
  }
  else if( ISNUMPAR(1) && ISQURL(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_SETFOCUS2 );
  }
  else if( ISNUMPAR(1) && ISQIODEVICE(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_SETFOCUS3 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_SETFOCUS4 );
  }
}

/*
void setInitialTemplateName ( const QXmlName & name )
*/
HB_FUNC( QXMLQUERY_SETINITIALTEMPLATENAME1 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlName * par1 = (QXmlName *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setInitialTemplateName ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setInitialTemplateName ( const QString & localName )
*/
HB_FUNC( QXMLQUERY_SETINITIALTEMPLATENAME2 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setInitialTemplateName ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setInitialTemplateName ( const QXmlName & name )
//[2]void setInitialTemplateName ( const QString & localName )

HB_FUNC( QXMLQUERY_SETINITIALTEMPLATENAME )
{
  if( ISNUMPAR(1) && ISQXMLNAME(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_SETINITIALTEMPLATENAME1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QXMLQUERY_SETINITIALTEMPLATENAME2 );
  }
}

/*
void setMessageHandler ( QAbstractMessageHandler * aMessageHandler )
*/
HB_FUNC( QXMLQUERY_SETMESSAGEHANDLER )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractMessageHandler * par1 = (QAbstractMessageHandler *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setMessageHandler ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setNetworkAccessManager ( QNetworkAccessManager * newManager )
*/
HB_FUNC( QXMLQUERY_SETNETWORKACCESSMANAGER )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QNetworkAccessManager * par1 = (QNetworkAccessManager *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setNetworkAccessManager ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setQuery ( QIODevice * sourceCode, const QUrl & documentURI = QUrl() )
*/
HB_FUNC( QXMLQUERY_SETQUERY1 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QUrl par2 = ISNIL(2)? QUrl() : *(QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setQuery ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setQuery ( const QUrl & queryURI, const QUrl & baseURI = QUrl() )
*/
HB_FUNC( QXMLQUERY_SETQUERY2 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QUrl * par1 = (QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QUrl par2 = ISNIL(2)? QUrl() : *(QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setQuery ( *par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setQuery ( const QString & sourceCode, const QUrl & documentURI = QUrl() )
*/
HB_FUNC( QXMLQUERY_SETQUERY3 )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QUrl par2 = ISNIL(2)? QUrl() : *(QUrl *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setQuery ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setQuery ( QIODevice * sourceCode, const QUrl & documentURI = QUrl() )
//[2]void setQuery ( const QUrl & queryURI, const QUrl & baseURI = QUrl() )
//[3]void setQuery ( const QString & sourceCode, const QUrl & documentURI = QUrl() )

HB_FUNC( QXMLQUERY_SETQUERY )
{
  if( ISBETWEEN(1,2) && ISQIODEVICE(1) && (ISQURL(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QXMLQUERY_SETQUERY1 );
  }
  else if( ISBETWEEN(1,2) && ISQURL(1) && (ISQURL(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QXMLQUERY_SETQUERY2 );
  }
  else if( ISBETWEEN(1,2) && ISCHAR(1) && (ISQURL(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QXMLQUERY_SETQUERY3 );
  }
}

/*
void setUriResolver ( const QAbstractUriResolver * resolver )
*/
HB_FUNC( QXMLQUERY_SETURIRESOLVER )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QAbstractUriResolver * par1 = (const QAbstractUriResolver *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setUriResolver ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
const QAbstractUriResolver * uriResolver () const
*/
HB_FUNC( QXMLQUERY_URIRESOLVER )
{
  QXmlQuery * obj = (QXmlQuery *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QAbstractUriResolver * ptr = obj->uriResolver (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTURIRESOLVER" );  }
}




