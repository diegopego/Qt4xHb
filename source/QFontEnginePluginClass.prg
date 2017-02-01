/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


REQUEST QFONTENGINEINFO
REQUEST QABSTRACTFONTENGINE

CLASS QFontEnginePlugin INHERIT QObject

   DATA class_id INIT Class_Id_QFontEnginePlugin
   DATA self_destruction INIT .f.

   METHOD delete
   METHOD availableFontEngines
   METHOD create
   METHOD keys
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QFontEnginePlugin
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
