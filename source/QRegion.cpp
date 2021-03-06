/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QRegion>

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

#include <QVector>

/*
QRegion ()
*/
HB_FUNC( QREGION_NEW1 )
{
  QRegion * o = NULL;
  o = new QRegion (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QRegion *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QRegion ( int x, int y, int w, int h, RegionType t = Rectangle )
*/
HB_FUNC( QREGION_NEW2 )
{
  QRegion * o = NULL;
  int par1 = hb_parni(1);
  int par2 = hb_parni(2);
  int par3 = hb_parni(3);
  int par4 = hb_parni(4);
  int par5 = ISNIL(5)? (int) QRegion::Rectangle : hb_parni(5);
  o = new QRegion ( par1, par2, par3, par4,  (QRegion::RegionType) par5 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QRegion *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QRegion ( const QPolygon & a, Qt::FillRule fillRule = Qt::OddEvenFill )
*/
HB_FUNC( QREGION_NEW3 )
{
  QRegion * o = NULL;
  QPolygon * par1 = (QPolygon *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) Qt::OddEvenFill : hb_parni(2);
  o = new QRegion ( *par1,  (Qt::FillRule) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QRegion *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QRegion ( const QRegion & r )
*/
HB_FUNC( QREGION_NEW4 )
{
  QRegion * o = NULL;
  QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QRegion ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QRegion *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QRegion ( const QBitmap & bm )
*/
HB_FUNC( QREGION_NEW5 )
{
  QRegion * o = NULL;
  QBitmap * par1 = (QBitmap *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QRegion ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QRegion *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QRegion ( const QRect & r, RegionType t = Rectangle )
*/
HB_FUNC( QREGION_NEW6 )
{
  QRegion * o = NULL;
  QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  int par2 = ISNIL(2)? (int) QRegion::Rectangle : hb_parni(2);
  o = new QRegion ( *par1,  (QRegion::RegionType) par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QRegion *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QRegion ()
//[2]QRegion ( int x, int y, int w, int h, RegionType t = Rectangle )
//[3]QRegion ( const QPolygon & a, Qt::FillRule fillRule = Qt::OddEvenFill )
//[4]QRegion ( const QRegion & r )
//[5]QRegion ( const QBitmap & bm )
//[6]QRegion ( const QRect & r, RegionType t = Rectangle )

HB_FUNC( QREGION_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QREGION_NEW1 );
  }
  else if( ISBETWEEN(4,5) && ISNUM(1) && ISNUM(2) && ISNUM(3) && ISNUM(4) && (ISNUM(5)||ISNIL(5)) )
  {
    HB_FUNC_EXEC( QREGION_NEW2 );
  }
  else if( ISBETWEEN(1,2) && ISQPOLYGON(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QREGION_NEW3 );
  }
  else if( ISNUMPAR(1) && ISQREGION(1) )
  {
    HB_FUNC_EXEC( QREGION_NEW4 );
  }
  else if( ISNUMPAR(1) && ISQBITMAP(1) )
  {
    HB_FUNC_EXEC( QREGION_NEW5 );
  }
  else if( ISBETWEEN(1,2) && ISQRECT(1) && (ISNUM(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QREGION_NEW6 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QREGION_DELETE )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
QRect boundingRect () const
*/
HB_FUNC( QREGION_BOUNDINGRECT )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->boundingRect (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
bool contains ( const QPoint & p ) const
*/
HB_FUNC( QREGION_CONTAINS1 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->contains ( *par1 );
    hb_retl( b );
  }
}


/*
bool contains ( const QRect & r ) const
*/
HB_FUNC( QREGION_CONTAINS2 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->contains ( *par1 );
    hb_retl( b );
  }
}


//[1]bool contains ( const QPoint & p ) const
//[2]bool contains ( const QRect & r ) const

HB_FUNC( QREGION_CONTAINS )
{
  if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QREGION_CONTAINS1 );
  }
  else if( ISNUMPAR(1) && ISQRECT(1) )
  {
    HB_FUNC_EXEC( QREGION_CONTAINS2 );
  }
}


/*
QRegion intersected ( const QRegion & r ) const
*/
HB_FUNC( QREGION_INTERSECTED1 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion * ptr = new QRegion( obj->intersected ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


/*
QRegion intersected ( const QRect & rect ) const
*/
HB_FUNC( QREGION_INTERSECTED2 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion * ptr = new QRegion( obj->intersected ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


//[1]QRegion intersected ( const QRegion & r ) const
//[2]QRegion intersected ( const QRect & rect ) const

HB_FUNC( QREGION_INTERSECTED )
{
  if( ISNUMPAR(1) && ISQREGION(1) )
  {
    HB_FUNC_EXEC( QREGION_INTERSECTED1 );
  }
  else if( ISNUMPAR(1) && ISQRECT(1) )
  {
    HB_FUNC_EXEC( QREGION_INTERSECTED2 );
  }
}

/*
bool intersects ( const QRegion & region ) const
*/
HB_FUNC( QREGION_INTERSECTS1 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->intersects ( *par1 );
    hb_retl( b );
  }
}


/*
bool intersects ( const QRect & rect ) const
*/
HB_FUNC( QREGION_INTERSECTS2 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->intersects ( *par1 );
    hb_retl( b );
  }
}


//[1]bool intersects ( const QRegion & region ) const
//[2]bool intersects ( const QRect & rect ) const

HB_FUNC( QREGION_INTERSECTS )
{
  if( ISNUMPAR(1) && ISQREGION(1) )
  {
    HB_FUNC_EXEC( QREGION_INTERSECTS1 );
  }
  else if( ISNUMPAR(1) && ISQRECT(1) )
  {
    HB_FUNC_EXEC( QREGION_INTERSECTS2 );
  }
}

/*
bool isEmpty () const
*/
HB_FUNC( QREGION_ISEMPTY )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isEmpty (  );
    hb_retl( b );
  }
}


/*
int rectCount () const
*/
HB_FUNC( QREGION_RECTCOUNT )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->rectCount (  );
    hb_retni( i );
  }
}


/*
QVector<QRect> rects () const
*/
HB_FUNC( QREGION_RECTS )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector<QRect> list = obj->rects (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QRECT" );
    #else
    pDynSym = hb_dynsymFindName( "QRECT" );
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
        hb_itemPutPtr( pItem, (QRect *) new QRect ( list[i] ) );
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
QRegion subtracted ( const QRegion & r ) const
*/
HB_FUNC( QREGION_SUBTRACTED )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion * ptr = new QRegion( obj->subtracted ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


/*
void swap ( QRegion & other )
*/
HB_FUNC( QREGION_SWAP )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->swap ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void translate ( int dx, int dy )
*/
HB_FUNC( QREGION_TRANSLATE1 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    obj->translate ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void translate ( const QPoint & point )
*/
HB_FUNC( QREGION_TRANSLATE2 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->translate ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void translate ( int dx, int dy )
//[2]void translate ( const QPoint & point )

HB_FUNC( QREGION_TRANSLATE )
{
  if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QREGION_TRANSLATE1 );
  }
  else if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QREGION_TRANSLATE2 );
  }
}

/*
QRegion translated ( int dx, int dy ) const
*/
HB_FUNC( QREGION_TRANSLATED1 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QRegion * ptr = new QRegion( obj->translated ( par1, par2 ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


/*
QRegion translated ( const QPoint & p ) const
*/
HB_FUNC( QREGION_TRANSLATED2 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPoint * par1 = (QPoint *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion * ptr = new QRegion( obj->translated ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


//[1]QRegion translated ( int dx, int dy ) const
//[2]QRegion translated ( const QPoint & p ) const

HB_FUNC( QREGION_TRANSLATED )
{
  if( ISNUMPAR(2) && ISNUM(1) && ISNUM(2) )
  {
    HB_FUNC_EXEC( QREGION_TRANSLATED1 );
  }
  else if( ISNUMPAR(1) && ISQPOINT(1) )
  {
    HB_FUNC_EXEC( QREGION_TRANSLATED2 );
  }
}

/*
QRegion united ( const QRegion & r ) const
*/
HB_FUNC( QREGION_UNITED1 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion * ptr = new QRegion( obj->united ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


/*
QRegion united ( const QRect & rect ) const
*/
HB_FUNC( QREGION_UNITED2 )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * par1 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion * ptr = new QRegion( obj->united ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}


//[1]QRegion united ( const QRegion & r ) const
//[2]QRegion united ( const QRect & rect ) const

HB_FUNC( QREGION_UNITED )
{
  if( ISNUMPAR(1) && ISQREGION(1) )
  {
    HB_FUNC_EXEC( QREGION_UNITED1 );
  }
  else if( ISNUMPAR(1) && ISQRECT(1) )
  {
    HB_FUNC_EXEC( QREGION_UNITED2 );
  }
}

/*
QRegion xored ( const QRegion & r ) const
*/
HB_FUNC( QREGION_XORED )
{
  QRegion * obj = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRegion * par1 = (QRegion *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRegion * ptr = new QRegion( obj->xored ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QREGION", true );  }
}



