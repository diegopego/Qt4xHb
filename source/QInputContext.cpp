/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QInputContext>

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

#include <QTextFormat>


HB_FUNC( QINPUTCONTEXT_DELETE )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
virtual QList<QAction *> actions ()
*/
HB_FUNC( QINPUTCONTEXT_ACTIONS )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QList<QAction *> list = obj->actions (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QACTION" );
    #else
    pDynSym = hb_dynsymFindName( "QACTION" );
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
        hb_itemPutPtr( pItem, (QAction *) list[i] );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
        hb_itemRelease( pItem );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
virtual bool filterEvent ( const QEvent * event )
*/
HB_FUNC( QINPUTCONTEXT_FILTEREVENT )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QEvent * par1 = (const QEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->filterEvent ( par1 );
    hb_retl( b );
  }
}


/*
QWidget * focusWidget () const
*/
HB_FUNC( QINPUTCONTEXT_FOCUSWIDGET )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->focusWidget (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
virtual QFont font () const
*/
HB_FUNC( QINPUTCONTEXT_FONT )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QFont * ptr = new QFont( obj->font (  ) );
    _qt4xhb_createReturnClass ( ptr, "QFONT", true );  }
}


/*
virtual QString identifierName () = 0
*/
HB_FUNC( QINPUTCONTEXT_IDENTIFIERNAME )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->identifierName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual bool isComposing () const = 0
*/
HB_FUNC( QINPUTCONTEXT_ISCOMPOSING )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isComposing (  );
    hb_retl( b );
  }
}


/*
virtual QString language () = 0
*/
HB_FUNC( QINPUTCONTEXT_LANGUAGE )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->language (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
virtual void mouseHandler ( int x, QMouseEvent * event )
*/
HB_FUNC( QINPUTCONTEXT_MOUSEHANDLER )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QMouseEvent * par2 = (QMouseEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->mouseHandler ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void reset () = 0
*/
HB_FUNC( QINPUTCONTEXT_RESET )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->reset (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void sendEvent ( const QInputMethodEvent & event )
*/
HB_FUNC( QINPUTCONTEXT_SENDEVENT )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QInputMethodEvent * par1 = (QInputMethodEvent *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->sendEvent ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void setFocusWidget ( QWidget * widget )
*/
HB_FUNC( QINPUTCONTEXT_SETFOCUSWIDGET )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setFocusWidget ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QTextFormat standardFormat ( StandardFormat s ) const
*/
HB_FUNC( QINPUTCONTEXT_STANDARDFORMAT )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    QTextFormat * ptr = new QTextFormat( obj->standardFormat (  (QInputContext::StandardFormat) par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QTEXTFORMAT" );  }
}



/*
virtual void update ()
*/
HB_FUNC( QINPUTCONTEXT_UPDATE )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->update (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual void widgetDestroyed ( QWidget * widget )
*/
HB_FUNC( QINPUTCONTEXT_WIDGETDESTROYED )
{
  QInputContext * obj = (QInputContext *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->widgetDestroyed ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




