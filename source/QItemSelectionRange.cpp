/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QItemSelectionRange>

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
QItemSelectionRange ()
*/
HB_FUNC( QITEMSELECTIONRANGE_NEW1 )
{
  QItemSelectionRange * o = NULL;
  o = new QItemSelectionRange (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QItemSelectionRange *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QItemSelectionRange ( const QItemSelectionRange & other )
*/
HB_FUNC( QITEMSELECTIONRANGE_NEW2 )
{
  QItemSelectionRange * o = NULL;
  QItemSelectionRange * par1 = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QItemSelectionRange ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QItemSelectionRange *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QItemSelectionRange ( const QModelIndex & topLeft, const QModelIndex & bottomRight )
*/
HB_FUNC( QITEMSELECTIONRANGE_NEW3 )
{
  QItemSelectionRange * o = NULL;
  QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QModelIndex * par2 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QItemSelectionRange ( *par1, *par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QItemSelectionRange *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QItemSelectionRange ( const QModelIndex & index )
*/
HB_FUNC( QITEMSELECTIONRANGE_NEW4 )
{
  QItemSelectionRange * o = NULL;
  QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QItemSelectionRange ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QItemSelectionRange *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QItemSelectionRange ()
//[2]QItemSelectionRange ( const QItemSelectionRange & other )
//[3]QItemSelectionRange ( const QModelIndex & topLeft, const QModelIndex & bottomRight )
//[4]QItemSelectionRange ( const QModelIndex & index )

HB_FUNC( QITEMSELECTIONRANGE_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QITEMSELECTIONRANGE_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQITEMSELECTIONRANGE(1) )
  {
    HB_FUNC_EXEC( QITEMSELECTIONRANGE_NEW2 );
  }
  else if( ISNUMPAR(2) && ISQMODELINDEX(1) && ISQMODELINDEX(2) )
  {
    HB_FUNC_EXEC( QITEMSELECTIONRANGE_NEW3 );
  }
  else if( ISNUMPAR(1) && ISQMODELINDEX(1) )
  {
    HB_FUNC_EXEC( QITEMSELECTIONRANGE_NEW4 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QITEMSELECTIONRANGE_DELETE )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
HB_FUNC( QITEMSELECTIONRANGE_BOTTOM )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->bottom (  );
    hb_retni( i );
  }
}


/*
QModelIndex bottomRight () const
*/
HB_FUNC( QITEMSELECTIONRANGE_BOTTOMRIGHT )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * ptr = new QModelIndex( obj->bottomRight (  ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
bool contains ( const QModelIndex & index ) const
*/
HB_FUNC( QITEMSELECTIONRANGE_CONTAINS1 )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->contains ( *par1 );
    hb_retl( b );
  }
}


/*
bool contains ( int row, int column, const QModelIndex & parentIndex ) const
*/
HB_FUNC( QITEMSELECTIONRANGE_CONTAINS2 )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    int par2 = hb_parni(2);
    QModelIndex * par3 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(3, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->contains ( par1, par2, *par3 );
    hb_retl( b );
  }
}


//[1]bool contains ( const QModelIndex & index ) const
//[2]bool contains ( int row, int column, const QModelIndex & parentIndex ) const

HB_FUNC( QITEMSELECTIONRANGE_CONTAINS )
{
  if( ISNUMPAR(1) && ISQMODELINDEX(1) )
  {
    HB_FUNC_EXEC( QITEMSELECTIONRANGE_CONTAINS1 );
  }
  else if( ISNUMPAR(3) && ISNUM(1) && ISNUM(2) && ISQMODELINDEX(3) )
  {
    HB_FUNC_EXEC( QITEMSELECTIONRANGE_CONTAINS2 );
  }
}

/*
int height () const
*/
HB_FUNC( QITEMSELECTIONRANGE_HEIGHT )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->height (  );
    hb_retni( i );
  }
}


/*
QModelIndexList indexes () const
*/
HB_FUNC( QITEMSELECTIONRANGE_INDEXES )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndexList list = obj->indexes (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QMODELINDEX" );
    #else
    pDynSym = hb_dynsymFindName( "QMODELINDEX" );
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
        hb_itemPutPtr( pItem, (QModelIndex *) new QModelIndex( list[i] ) );
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
QItemSelectionRange intersected ( const QItemSelectionRange & other ) const
*/
HB_FUNC( QITEMSELECTIONRANGE_INTERSECTED )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QItemSelectionRange * par1 = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QItemSelectionRange * ptr = new QItemSelectionRange( obj->intersected ( *par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QITEMSELECTIONRANGE" );  }
}


/*
bool intersects ( const QItemSelectionRange & other ) const
*/
HB_FUNC( QITEMSELECTIONRANGE_INTERSECTS )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QItemSelectionRange * par1 = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    bool b = obj->intersects ( *par1 );
    hb_retl( b );
  }
}


/*
bool isEmpty () const
*/
HB_FUNC( QITEMSELECTIONRANGE_ISEMPTY )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isEmpty (  );
    hb_retl( b );
  }
}


/*
bool isValid () const
*/
HB_FUNC( QITEMSELECTIONRANGE_ISVALID )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isValid (  );
    hb_retl( b );
  }
}


/*
int left () const
*/
HB_FUNC( QITEMSELECTIONRANGE_LEFT )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->left (  );
    hb_retni( i );
  }
}


/*
const QAbstractItemModel * model () const
*/
HB_FUNC( QITEMSELECTIONRANGE_MODEL )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const QAbstractItemModel * ptr = obj->model (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTITEMMODEL" );  }
}


/*
QModelIndex parent () const
*/
HB_FUNC( QITEMSELECTIONRANGE_PARENT )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * ptr = new QModelIndex( obj->parent (  ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
int right () const
*/
HB_FUNC( QITEMSELECTIONRANGE_RIGHT )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->right (  );
    hb_retni( i );
  }
}


/*
int top () const
*/
HB_FUNC( QITEMSELECTIONRANGE_TOP )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->top (  );
    hb_retni( i );
  }
}


/*
QModelIndex topLeft () const
*/
HB_FUNC( QITEMSELECTIONRANGE_TOPLEFT )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * ptr = new QModelIndex( obj->topLeft (  ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
int width () const
*/
HB_FUNC( QITEMSELECTIONRANGE_WIDTH )
{
  QItemSelectionRange * obj = (QItemSelectionRange *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->width (  );
    hb_retni( i );
  }
}




