/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QAccessibleObject>

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
virtual QString actionText ( int action, Text t, int child ) const
*/
HB_FUNC( QACCESSIBLEOBJECT_ACTIONTEXT )
{
  QAccessibleObject * obj = (QAccessibleObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    int par3 = hb_parni(3);
    QString str1 = obj->actionText ( par1,  (QAccessibleObject::Text) par2, par3 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual bool doAction ( int action, int child, const QVariantList & params )
*/
HB_FUNC( QACCESSIBLEOBJECT_DOACTION )
{
  QAccessibleObject * obj = (QAccessibleObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
QVariantList par3;
PHB_ITEM aList3 = hb_param(3, HB_IT_ARRAY);
int i3;
int nLen3 = hb_arrayLen(aList3);
for (i3=0;i3<nLen3;i3++)
{
par3 << *(QVariant *) hb_itemGetPtr( hb_objSendMsg( hb_arrayGetItemPtr( aList3, i3+1 ), "POINTER", 0 ) );
}
    bool b = obj->doAction ( par1, par2, par3 );
    hb_retl( b );
  }
}


/*
virtual bool isValid () const
*/
HB_FUNC( QACCESSIBLEOBJECT_ISVALID )
{
  QAccessibleObject * obj = (QAccessibleObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
virtual QObject * object () const
*/
HB_FUNC( QACCESSIBLEOBJECT_OBJECT )
{
  QAccessibleObject * obj = (QAccessibleObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QObject * ptr = obj->object (  );
    _qt4xhb_createReturnClass ( ptr, "QOBJECT" );  }
}


/*
virtual QRect rect ( int child ) const
*/
HB_FUNC( QACCESSIBLEOBJECT_RECT )
{
  QAccessibleObject * obj = (QAccessibleObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QRect * ptr = new QRect( obj->rect ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
virtual void setText ( Text t, int child, const QString & text )
*/
HB_FUNC( QACCESSIBLEOBJECT_SETTEXT )
{
  QAccessibleObject * obj = (QAccessibleObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QString par3 = hb_parc(3);
    obj->setText (  (QAccessibleObject::Text) par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual int userActionCount ( int child ) const
*/
HB_FUNC( QACCESSIBLEOBJECT_USERACTIONCOUNT )
{
  QAccessibleObject * obj = (QAccessibleObject *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int i = obj->userActionCount ( par1 );
    hb_retni( i );
  }
}



