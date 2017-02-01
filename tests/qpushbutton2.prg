/*

  Exemplo do projeto Qt4xHb

  (C) 2012-2017 Marcos Antonio Gambeta

  E-mail: marcosgambeta@uol.com.br

  Website: https://github.com/marcosgambeta

*/

PROCEDURE Main ()

   lOCAL oApp
   LOCAL oWindow
   LOCAL oButton1
   LOCAL oButton2

   oApp := QApplication():new()

   oWindow := QWidget():new()
   oWindow:resize(320,240)

   oButton1 := QPushButton():new("PushButton 1",oWindow)
   oButton1:move(20,20)
   oButton1:onClicked({|w|qout("clicked-1")})
   oButton1:onPressed({|w|qout("pressed-1")})
   oButton1:onReleased({|w|qout("released-1")})

   oButton2 := QPushButton():new("PushButton 2",oWindow)
   oButton2:move(20,70)
   oButton2:onClicked({|w|qout("clicked-2")})
   oButton2:onPressed({|w|qout("pressed-2")})
   oButton2:onReleased({|w|qout("released-2")})

   oWindow:show()

   oApp:exec()
   
   oWindow:delete()
   
   oApp:delete()

RETURN
