/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QUiLoader>

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

#include <QStringList>
#include <QDir>

/*
QUiLoader ( QObject * parent = 0 )
*/
HB_FUNC( QUILOADER_NEW )
{
  QUiLoader * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QUiLoader ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QUiLoader *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QUILOADER_DELETE )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void addPluginPath ( const QString & path )
*/
HB_FUNC( QUILOADER_ADDPLUGINPATH )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->addPluginPath ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QStringList availableLayouts () const
*/
HB_FUNC( QUILOADER_AVAILABLELAYOUTS )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->availableLayouts (  );
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
QStringList availableWidgets () const
*/
HB_FUNC( QUILOADER_AVAILABLEWIDGETS )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->availableWidgets (  );
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
void clearPluginPaths ()
*/
HB_FUNC( QUILOADER_CLEARPLUGINPATHS )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clearPluginPaths (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QAction * createAction ( QObject * parent = 0, const QString & name = QString() )
*/
HB_FUNC( QUILOADER_CREATEACTION )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    QAction * ptr = obj->createAction ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QACTION" );  }
}


/*
virtual QActionGroup * createActionGroup ( QObject * parent = 0, const QString & name = QString() )
*/
HB_FUNC( QUILOADER_CREATEACTIONGROUP )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    QActionGroup * ptr = obj->createActionGroup ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QACTIONGROUP" );  }
}


/*
virtual QLayout * createLayout ( const QString & className, QObject * parent = 0, const QString & name = QString() )
*/
HB_FUNC( QUILOADER_CREATELAYOUT )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QObject * par2 = ISNIL(2)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par3 = ISNIL(3)? QString() : hb_parc(3);
    QLayout * ptr = obj->createLayout ( par1, par2, par3 );
    _qt4xhb_createReturnClass ( ptr, "QLAYOUT" );  }
}


/*
virtual QWidget * createWidget ( const QString & className, QWidget * parent = 0, const QString & name = QString() )
*/
HB_FUNC( QUILOADER_CREATEWIDGET )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QWidget * par2 = ISNIL(2)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString par3 = ISNIL(3)? QString() : hb_parc(3);
    QWidget * ptr = obj->createWidget ( par1, par2, par3 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
bool isLanguageChangeEnabled () const
*/
HB_FUNC( QUILOADER_ISLANGUAGECHANGEENABLED )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isLanguageChangeEnabled (  );
    hb_retl( b );
  }
}


/*
QWidget * load ( QIODevice * device, QWidget * parentWidget = 0 )
*/
HB_FUNC( QUILOADER_LOAD )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QWidget * par2 = ISNIL(2)? 0 : (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    QWidget * ptr = obj->load ( par1, par2 );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
QStringList pluginPaths () const
*/
HB_FUNC( QUILOADER_PLUGINPATHS )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->pluginPaths (  );
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
void setLanguageChangeEnabled ( bool enabled )
*/
HB_FUNC( QUILOADER_SETLANGUAGECHANGEENABLED )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setLanguageChangeEnabled ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWorkingDirectory ( const QDir & dir )
*/
HB_FUNC( QUILOADER_SETWORKINGDIRECTORY )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDir * par1 = (QDir *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setWorkingDirectory ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QDir workingDirectory () const
*/
HB_FUNC( QUILOADER_WORKINGDIRECTORY )
{
  QUiLoader * obj = (QUiLoader *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QDir * ptr = new QDir( obj->workingDirectory (  ) );
    _qt4xhb_createReturnClass ( ptr, "QDIR", true );  }
}



