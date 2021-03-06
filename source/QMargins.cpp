/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QMargins>

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
QMargins ()
*/
HB_FUNC( QMARGINS_NEW1 )
{
  QMargins * o = NULL;
  o = new QMargins (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QMargins *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QMargins ( int left, int top, int right, int bottom )
*/
HB_FUNC( QMARGINS_NEW2 )
{
  QMargins * o = NULL;
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  int par3 = hb_parni(3);
  int par4 = hb_parni(4);
  o = new QMargins ( par1, par2, par3, par4 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QMargins *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QMargins ()
//[2]QMargins ( int left, int top, int right, int bottom )

HB_FUNC( QMARGINS_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QMARGINS_NEW1 );
  }
  else if( ISNUMPAR(4) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) )
  {
    HB_FUNC_EXEC( QMARGINS_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QMARGINS_DELETE )
{
  QMargins * obj = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
int bottom () const
*/
HB_FUNC( QMARGINS_BOTTOM )
{
  QMargins * obj = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->bottom (  );
    hb_retni( i );
  }
}


/*
bool isNull () const
*/
HB_FUNC( QMARGINS_ISNULL )
{
  QMargins * obj = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
int left () const
*/
HB_FUNC( QMARGINS_LEFT )
{
  QMargins * obj = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->left (  );
    hb_retni( i );
  }
}


/*
int right () const
*/
HB_FUNC( QMARGINS_RIGHT )
{
  QMargins * obj = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->right (  );
    hb_retni( i );
  }
}


/*
void setBottom ( int bottom )
*/
HB_FUNC( QMARGINS_SETBOTTOM )
{
  QMargins * obj = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setBottom ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setLeft ( int left )
*/
HB_FUNC( QMARGINS_SETLEFT )
{
  QMargins * obj = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setLeft ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setRight ( int right )
*/
HB_FUNC( QMARGINS_SETRIGHT )
{
  QMargins * obj = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setRight ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setTop ( int Top )
*/
HB_FUNC( QMARGINS_SETTOP )
{
  QMargins * obj = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setTop ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
int top () const
*/
HB_FUNC( QMARGINS_TOP )
{
  QMargins * obj = (QMargins *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->top (  );
    hb_retni( i );
  }
}



