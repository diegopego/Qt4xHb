/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


CLASS QInputMethodEvent INHERIT QEvent

   DATA class_id INIT Class_Id_QInputMethodEvent
   DATA self_destruction INIT .f.

   METHOD new1
   METHOD new3
   METHOD new
   METHOD delete
   METHOD commitString
   METHOD preeditString
   METHOD replacementLength
   METHOD replacementStart
   METHOD setCommitString
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QInputMethodEvent
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
