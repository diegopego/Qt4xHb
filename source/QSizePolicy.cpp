/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QSizePolicy>

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
QSizePolicy ()
*/
HB_FUNC( QSIZEPOLICY_NEW1 )
{
  QSizePolicy * o = NULL;
  o = new QSizePolicy (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSizePolicy *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QSizePolicy ( Policy horizontal, Policy vertical )
*/
HB_FUNC( QSIZEPOLICY_NEW2 )
{
  QSizePolicy * o = NULL;
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  o = new QSizePolicy (  (QSizePolicy::Policy) par1,  (QSizePolicy::Policy) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSizePolicy *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QSizePolicy ( Policy horizontal, Policy vertical, ControlType type )
*/
HB_FUNC( QSIZEPOLICY_NEW3 )
{
  QSizePolicy * o = NULL;
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  int par3 = hb_parni(3);
  o = new QSizePolicy (  (QSizePolicy::Policy) par1,  (QSizePolicy::Policy) par2,  (QSizePolicy::ControlType) par3 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QSizePolicy *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QSizePolicy ()
//[2]QSizePolicy ( Policy horizontal, Policy vertical )
//[3]QSizePolicy ( Policy horizontal, Policy vertical, ControlType type )

HB_FUNC( QSIZEPOLICY_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QSIZEPOLICY_NEW1 );
  }
  else if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QSIZEPOLICY_NEW2 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISNUM(3) )
  {
    HB_FUNC_EXEC( QSIZEPOLICY_NEW3 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QSIZEPOLICY_DELETE )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
ControlType controlType () const
*/
HB_FUNC( QSIZEPOLICY_CONTROLTYPE )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->controlType (  );
    hb_retni( i );
  }
}


/*
Qt::Orientations expandingDirections () const
*/
HB_FUNC( QSIZEPOLICY_EXPANDINGDIRECTIONS )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->expandingDirections (  );
    hb_retni( i );
  }
}


/*
bool hasHeightForWidth () const
*/
HB_FUNC( QSIZEPOLICY_HASHEIGHTFORWIDTH )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasHeightForWidth (  );
    hb_retl( b );
  }
}


/*
bool hasWidthForHeight () const
*/
HB_FUNC( QSIZEPOLICY_HASWIDTHFORHEIGHT )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasWidthForHeight (  );
    hb_retl( b );
  }
}


/*
Policy horizontalPolicy () const
*/
HB_FUNC( QSIZEPOLICY_HORIZONTALPOLICY )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->horizontalPolicy (  );
    hb_retni( i );
  }
}


/*
int horizontalStretch () const
*/
HB_FUNC( QSIZEPOLICY_HORIZONTALSTRETCH )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->horizontalStretch (  );
    hb_retni( i );
  }
}


/*
void setControlType ( ControlType type )
*/
HB_FUNC( QSIZEPOLICY_SETCONTROLTYPE )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setControlType (  (QSizePolicy::ControlType) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHeightForWidth ( bool dependent )
*/
HB_FUNC( QSIZEPOLICY_SETHEIGHTFORWIDTH )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setHeightForWidth ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHorizontalPolicy ( Policy policy )
*/
HB_FUNC( QSIZEPOLICY_SETHORIZONTALPOLICY )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setHorizontalPolicy (  (QSizePolicy::Policy) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setHorizontalStretch ( uchar stretchFactor )
*/
HB_FUNC( QSIZEPOLICY_SETHORIZONTALSTRETCH )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    uchar par1 = ISCHAR(1)? (uchar) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    obj->setHorizontalStretch ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setVerticalPolicy ( Policy policy )
*/
HB_FUNC( QSIZEPOLICY_SETVERTICALPOLICY )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setVerticalPolicy (  (QSizePolicy::Policy) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setVerticalStretch ( uchar stretchFactor )
*/
HB_FUNC( QSIZEPOLICY_SETVERTICALSTRETCH )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    uchar par1 = ISCHAR(1)? (uchar) hb_parc(1)[0] : (ISNUM(1)? hb_parni(1) : 0);
    obj->setVerticalStretch ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWidthForHeight ( bool dependent )
*/
HB_FUNC( QSIZEPOLICY_SETWIDTHFORHEIGHT )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setWidthForHeight ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void transpose ()
*/
HB_FUNC( QSIZEPOLICY_TRANSPOSE )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->transpose (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
Policy verticalPolicy () const
*/
HB_FUNC( QSIZEPOLICY_VERTICALPOLICY )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->verticalPolicy (  );
    hb_retni( i );
  }
}


/*
int verticalStretch () const
*/
HB_FUNC( QSIZEPOLICY_VERTICALSTRETCH )
{
  QSizePolicy * obj = (QSizePolicy *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->verticalStretch (  );
    hb_retni( i );
  }
}



