/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


CLASS QTranslator INHERIT QObject

   DATA class_id INIT Class_Id_QTranslator
   DATA self_destruction INIT .f.

   METHOD new
   METHOD delete
   METHOD isEmpty
   METHOD load1
   METHOD load2
   METHOD load
   METHOD translate
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QTranslator
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
