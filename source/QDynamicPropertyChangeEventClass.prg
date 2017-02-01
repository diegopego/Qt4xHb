/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


REQUEST QBYTEARRAY

CLASS QDynamicPropertyChangeEvent INHERIT QEvent

   DATA class_id INIT Class_Id_QDynamicPropertyChangeEvent
   DATA self_destruction INIT .f.

   METHOD new
   METHOD delete
   METHOD propertyName
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QDynamicPropertyChangeEvent
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
