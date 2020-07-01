### Atelier-Auto

Proiect POO - An II

## Cerință

# Precizări generale

    1.	Puteți folosi STL si ce considerați ca e nevoie însă pentru temele care presupun structuri de date, folosirea STL pentru exact structura de date din cerință ar evita scopul temei.
    2.	Cele mai multe cerințe sunt parțiale, lăsând la latitudinea voastră cum alegeți anumite elemente concrete pentru a ilustra cat mai bine competentele voastre de OOP.
    3.	In cazul in care o cerință este neclara si nu reușiți sa o clarificați singuri, spuneți pe grup, sau discutam la laborator
    4.	1p in plus pentru folosirea de templateuri
    5.	1p in plus pentru un design pattern implementat
    6.	Încercați sa utilizați cat mai multe cunoștințe de POO pe care le-ați dobândit până acum si încercați sa implementați totul cum trebuie (cu constructori de copiere, operator=, alocare dinamica, fără memory leakuri, etc)
    
# Atelier auto: 

   Există mai multe categorii de vehicule (motocicletă, bicicletă, automobil) care pot sosi la un garaj pentru a descoperi ce probleme tehnice au si a obține un deviz de reparații. Fiecare vehicul poate avea probleme din diferite categorii: frâne, direcție, noxe, motor, caroserie. Nu toate vehiculele pot avea toate tipurile de probleme. Fiecare tip de problema are o soluție tehnica ce presupune un anumit consum de materiale (de diferite tipuri) si un anumit efort uman (in ore-om). Fiecare material are un cost la fel ca si ora-om de efort uman. Pentru fiecare vehicul ce sosește in garaj trebuie calculat devizul estimativ.
   
# Precizări: 

    1.	Tipurile de probleme vor include cel puțin: Frâne – plăcuțe uzate (față/spate la un auto/moto), discuri uzate (oricare din 4 la un auto, oricare din 2 la moto), lanț tocit (bicicletă), lanț lipsă (bicicletă), defecțiune capitală; Motor  - Nivel ulei scăzut (la moto si auto), carburator murdar (la auto), motor topit (la moto si auto); Direcție – ghidon strâmb (bicicleta, moto), roată strâmba (toate), defecțiune capitala (toate); Noxe – Vehiculul arde ulei (moto si auto), Vehiculul este anterior anului 2000 (moto si auto); Caroserie (auto) – Caroserie corodata de rugina, Caroserie strâmba (aripi stânga/dreapta, fată/spate, bară, capotă) - foarte strâmbă sau așa-și-așa (pe fiecare componentă in parte).

    2.	Soluțiile presupun un consum de materiale. Materialele sunt toate la bucată. Plăcuțele de frână de pe spate diferă de cele de pe față. Plăcutele de frână sunt aferente fiecărei roti. Nivel ulei scăzut, motor topit si vehiculul arde ulei toate presupun schimb de ulei.

    3.	Fiecare problemă are o soluție (mai puțin defecțiunea capitală). Pot exista tipuri de materiale comune mai multor soluții. Toate soluțiile consuma șuruburi (minim 5). 

    4.	Vehiculul suportă operațiuni de traumatizare (e.g. Uzează discul de frână de pe spate dreapta sau Începe sa arzi ulei).

    5.	Vehiculul odată conectat la tester (in atelier) se va putea autodiagnostica verificând fiecare componenta a sa si returnând lista de probleme.



