/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


CLASS QDeclarativeExtensionPlugin INHERIT QObject

   DATA class_id INIT Class_Id_QDeclarativeExtensionPlugin
   DATA self_destruction INIT .f.

   METHOD initializeEngine
   METHOD registerTypes
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QDeclarativeExtensionPlugin
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
