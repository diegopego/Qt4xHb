/*

  Exemplo do projeto Qt4xHb

  (C) 2012-2017 Marcos Antonio Gambeta

  E-mail: marcosgambeta@uol.com.br

  Website: https://github.com/marcosgambeta

*/

PROCEDURE Main ()

   lOCAL oApp
   LOCAL oWindow
   LOCAL oButton

   oApp := QApplication():new()

   oWindow := QWidget():new()

   oButton := QPushButton():new("Clique aqui",oWindow)
   oButton:move(20,20)
   oButton:onClicked({|w|qout("clicked")})
   oButton:onPressed({|w|qout("pressed")})
   oButton:onReleased({|w|qout("released")})

   oWindow:show()

   oApp:exec()
   
   oWindow:delete()
   
   oApp:delete()

RETURN
