/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


CLASS QHBoxLayout INHERIT QBoxLayout

   DATA class_id INIT Class_Id_QHBoxLayout
   DATA self_destruction INIT .f.

   METHOD new1
   METHOD new2
   METHOD new
   METHOD delete
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QHBoxLayout
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
