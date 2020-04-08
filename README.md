# VirusSpreadModel
Using　C++　and DxLib to see path,speed and result of virus spreading.

1)If you want to compile on your own

  1.Download DxLib and any c++ compiler
  2.Add DxLib to your compiler's library folder or project folder directly
  3.compile 
  4.done
 
 
2)Don't want to?

 1.download VirusMove.exe
 
 2.done
 
How this application works


1)Set up phase

you are asked to enter number of people and which human to watch(but since using random algorithm, this does do nothing).

then Dxlib opens new window and starts the simulation


2)simulation phase

 i)How to look
 
   each AI's box color shows thier symptoms(not how healthy it is). More green less symptoms and more red more symptoms
   
   left top shows first infected AI's box color
   
   
 ii)How AI works
 
   all AIs are moving and acting randomly but has some same pattern
   
     1.When an healthy AI is near(less than 3 pixels) Infected AI , it will also get Infected.
     
     2.After infected, AI starts to get more symptoms
     
     3.After max level of symptoms, AI starts to get less symptoms
     
     4.AI will no get infected if they had been already.
     
