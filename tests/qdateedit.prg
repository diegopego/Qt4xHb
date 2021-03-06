/*

  Exemplo do projeto Qt4xHb

  (C) 2012-2017 Marcos Antonio Gambeta

  E-mail: marcosgambeta@uol.com.br

  Website: https://github.com/marcosgambeta

*/

PROCEDURE Main ()

   LOCAL oApp
   LOCAL oWindow
   LOCAL oDateEdit

   oApp := QApplication():new()

   oWindow := QWidget():new()
   oWindow:setWindowTitle("Teste")
   oWindow:resize(640,480)
   oWindow:show()

   oDateEdit := QDateEdit():new(oWindow)
   oDateEdit:move(20,20)
   oDateEdit:setTooltip("Eu sou um DateEdit")
   oDateEdit:show()

   oApp:exec()
   
   oWindow:delete()
   
   oApp:delete()

RETURN
