/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QKeyEvent>

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
QKeyEvent ( Type type, int key, Qt::KeyboardModifiers modifiers, const QString & text = QString(), bool autorep = false, ushort count = 1 )
*/
HB_FUNC( QKEYEVENT_NEW )
{
  QKeyEvent * o = NULL;
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  int par3 = hb_parni(3);
  QString par4 = ISNIL(4)? QString() : hb_parc(4);
  bool par5 = ISNIL(5)? false : hb_parl(5);
  ushort par6 = ISNIL(6)? 1 : hb_parni(6);
  o = new QKeyEvent (  (QEvent::Type) par1, par2,  (Qt::KeyboardModifiers) par3, par4, par5, par6 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QKeyEvent *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


HB_FUNC( QKEYEVENT_DELETE )
{
  QKeyEvent * obj = (QKeyEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
int count () const
*/
HB_FUNC( QKEYEVENT_COUNT )
{
  QKeyEvent * obj = (QKeyEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->count (  );
    hb_retni( i );
  }
}


/*
bool isAutoRepeat () const
*/
HB_FUNC( QKEYEVENT_ISAUTOREPEAT )
{
  QKeyEvent * obj = (QKeyEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isAutoRepeat (  );
    hb_retl( b );
  }
}


/*
int key () const
*/
HB_FUNC( QKEYEVENT_KEY )
{
  QKeyEvent * obj = (QKeyEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->key (  );
    hb_retni( i );
  }
}


/*
bool matches ( QKeySequence::StandardKey key ) const
*/
HB_FUNC( QKEYEVENT_MATCHES )
{
  QKeyEvent * obj = (QKeyEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->matches (  (QKeySequence::StandardKey) par1 );
    hb_retl( b );
  }
}


/*
Qt::KeyboardModifiers modifiers () const
*/
HB_FUNC( QKEYEVENT_MODIFIERS )
{
  QKeyEvent * obj = (QKeyEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->modifiers (  );
    hb_retni( i );
  }
}


/*
quint32 nativeModifiers () const
*/
HB_FUNC( QKEYEVENT_NATIVEMODIFIERS )
{
  QKeyEvent * obj = (QKeyEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    quint32 i = obj->nativeModifiers (  );
    hb_retni( i );
  }
}


/*
quint32 nativeScanCode () const
*/
HB_FUNC( QKEYEVENT_NATIVESCANCODE )
{
  QKeyEvent * obj = (QKeyEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    quint32 i = obj->nativeScanCode (  );
    hb_retni( i );
  }
}


/*
quint32 nativeVirtualKey () const
*/
HB_FUNC( QKEYEVENT_NATIVEVIRTUALKEY )
{
  QKeyEvent * obj = (QKeyEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    quint32 i = obj->nativeVirtualKey (  );
    hb_retni( i );
  }
}


/*
QString text () const
*/
HB_FUNC( QKEYEVENT_TEXT )
{
  QKeyEvent * obj = (QKeyEvent *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->text (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}



/*
static QKeyEvent *createExtendedKeyEvent(Type type, int key, Qt::KeyboardModifiers modifiers, quint32 nativeScanCode, quint32 nativeVirtualKey,quint32 nativeModifiers,const QString& text = QString(), bool autorep = false,ushort count = 1)
*/
HB_FUNC( QKEYEVENT_CREATEEXTENDEDKEYEVENT )
{
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  int par3 = hb_parni(3);
  quint32 par4 = hb_parni(4);
  quint32 par5 = hb_parni(5);
  quint32 par6 = hb_parni(6);
  QString par7 = ISNIL(7)? QString() : hb_parc(7);
  bool par8 = ISNIL(8)? false : hb_parl(8);
  ushort par9 = ISNIL(9)? 1 : hb_parni(9);
  QKeyEvent * ptr = QKeyEvent::createExtendedKeyEvent (  (QEvent::Type) par1, par2,  (Qt::KeyboardModifiers) par3, par4, par5, par6, par7, par8, par9 );
  _qt4xhb_createReturnClass ( ptr, "QKEYEVENT" );}



