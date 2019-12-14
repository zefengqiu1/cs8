#ifndef OUTPUT2_H
#define OUTPUT2_H
/*

==========priority queue with bigger============(first come last out)

Priority Test
allocate: capacity: 8
please input your command
R for random number i for insert, p for pop,x for exit
:r
64

[64]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
658

[658]
   [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
974

   [658]

[974]
   [64]
-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
972

   [658]

[972]
   [974]
       [64]
-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
531

   [658]

[531]
       [974]

   [972]
       [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
748

   [531]
       [658]


[748]
       [974]

   [972]
       [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
604

       [531]

   [748]
       [658]


[604]
       [974]

   [972]
       [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
996

       [531]

   [748]
       [658]


[996]
       [974]

   [604]
       [972]
           [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
allocate: capacity: 16
687

       [531]

   [748]
       [658]


[687]
       [974]

   [996]
           [972]

       [604]
           [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
222

       [531]

   [748]
       [658]


[222]
       [996]
           [974]


   [687]
           [972]

       [604]
           [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
478

       [531]

   [748]
       [658]


[478]
           [996]

       [687]
           [974]


   [222]
           [972]

       [604]
           [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
478
       [531]

   [748]
       [658]


[222]
       [996]
           [974]


   [687]
           [972]

       [604]
           [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
222
       [531]

   [748]
       [658]


[687]
       [974]

   [996]
           [972]

       [604]
           [64]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
687
       [531]

   [748]
       [658]


[996]
       [974]

   [604]
       [972]
           [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
996
       [531]

   [748]
       [658]


[604]
       [974]

   [972]
       [64]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
604
   [531]
       [658]


[748]
       [974]

   [972]
       [64]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
748
   [658]

[531]
       [974]

   [972]
       [64]



-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
531
   [658]

[972]
   [974]
       [64]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
972
   [658]

[974]
   [64]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
974
[658]
   [64]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
658
[64]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
64

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:x


====================priority queue with smaller============(first come first out)
Priority Test
allocate: capacity: 8
please input your command
R for random number i for insert, p for pop,x for exit
:r
679

[679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
946

[946]
   [679]



-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
658

   [946]

[658]
   [679]



-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
566

   [946]

[566]
   [658]
       [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
646

   [946]

[646]
       [658]

   [566]
       [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
860

   [646]
       [946]


[860]
       [658]

   [566]
       [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
42

       [646]

   [860]
       [946]


[42]
       [658]

   [566]
       [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
840

       [646]

   [860]
       [946]


[840]
       [658]

   [42]
       [566]
           [679]



-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
allocate: capacity: 16
18

       [646]

   [860]
       [946]


[18]
       [658]

   [840]
           [566]

       [42]
           [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
741

       [646]

   [860]
       [946]


[741]
       [840]
           [658]


   [18]
           [566]

       [42]
           [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
749

       [646]

   [860]
       [946]


[749]
           [840]

       [18]
           [658]


   [741]
           [566]

       [42]
           [679]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
749
       [646]

   [860]
       [946]


[741]
       [840]
           [658]


   [18]
           [566]

       [42]
           [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
741
       [646]

   [860]
       [946]


[18]
       [658]

   [840]
           [566]

       [42]
           [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
18
       [646]

   [860]
       [946]


[840]
       [658]

   [42]
       [566]
           [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
840
       [646]

   [860]
       [946]


[42]
       [658]

   [566]
       [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
42
   [646]
       [946]


[860]
       [658]

   [566]
       [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
860
   [946]

[646]
       [658]

   [566]
       [679]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
646
   [946]

[566]
   [658]
       [679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
566
   [946]

[658]
   [679]



-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
658
[946]
   [679]



-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
946
[679]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
679

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:x
Press <RETURN> to close this window...


=====================priority queue with same priority and smaller class======(first come first serve)
Priority Test
allocate: capacity: 8
please input your command
R for random number i for insert, p for pop,x for exit
:r
420

[420]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
237

[420]
   [237]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
714

   [714]

[420]
   [237]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
510

   [714]

[420]
   [237]
       [510]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
696

   [714]

[420]
       [696]

   [237]
       [510]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
57

   [714]
       [57]


[420]
       [696]

   [237]
       [510]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
479

       [479]

   [714]
       [57]


[420]
       [696]

   [237]
       [510]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
420
   [714]
       [57]


[237]
       [696]

   [510]
       [479]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
237
   [57]

[714]
       [696]

   [510]
       [479]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
714
   [57]

[510]
   [696]
       [479]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
510
   [57]

[696]
   [479]

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
696
[57]
   [479]


------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
57
[479]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
479

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:x
Press <RETURN> to close this window...



=====================priority queue with same priority and bigger class======(also first come first serve)
Priority Test
allocate: capacity: 8
please input your command
R for random number i for insert, p for pop,x for exit
:r
676

[676]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
326

[676]
   [326]



-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
388

   [388]

[676]
   [326]



-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
711

   [388]

[676]
   [326]
       [711]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
250

   [388]

[676]
       [250]

   [326]
       [711]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
42

   [388]
       [42]


[676]
       [250]

   [326]
       [711]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:r
410

       [410]

   [388]
       [42]


[676]
       [250]

   [326]
       [711]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
676
   [388]
       [42]


[326]
       [250]

   [711]
       [410]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
326
   [42]

[388]
       [250]

   [711]
       [410]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
388
   [42]

[711]
   [250]
       [410]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
711
   [42]

[250]
   [410]



-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
250
[42]
   [410]



-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
42
[410]


-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:p
410

-------------------------------------
please input your command
R for random number, i for insert, p for pop, x for exit
:x
Press <RETURN> to close this window...

*/
#endif // OUTPUT2_H
