/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


CLASS QDomEntityReference INHERIT QDomNode

   DATA class_id INIT Class_Id_QDomEntityReference
   DATA class_flags INIT 0
   DATA self_destruction INIT .f.

   METHOD new1
   METHOD new2
   METHOD new
   METHOD nodeType
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QDomEntityReference
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
