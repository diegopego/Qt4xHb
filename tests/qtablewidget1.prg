/*

  Exemplo do projeto Qt4xHb

  (C) 2012-2017 Marcos Antonio Gambeta

  E-mail: marcosgambeta@uol.com.br

  Website: https://github.com/marcosgambeta

*/

#include "qt4xhb.ch"

PROCEDURE Main ()

   LOCAL oApp
   LOCAL oWindow
   LOCAL oTable

   oApp := QApplication():new()

   oWindow := QWidget():new()
   oWindow:setWindowTitle("Qt4xHb - teste")
   oWindow:resize(320,240)

   oTable := QTableWidget():new(12,2,oWindow)

   oTable:move(10,10)

   oWindow:show()

   oApp:exec()

   oWindow:delete()

   oApp:delete()

RETURN
