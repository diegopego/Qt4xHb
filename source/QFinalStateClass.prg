/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


CLASS QFinalState INHERIT QAbstractState

   DATA class_id INIT Class_Id_QFinalState
   DATA self_destruction INIT .f.

   METHOD new
   METHOD delete
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QFinalState
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
