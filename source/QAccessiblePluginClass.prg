/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


REQUEST QACCESSIBLEINTERFACE

CLASS QAccessiblePlugin INHERIT QObject,QAccessible

   DATA class_id INIT Class_Id_QAccessiblePlugin
   DATA self_destruction INIT .f.

   METHOD delete
   METHOD create
   METHOD keys
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QAccessiblePlugin
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
