#ifndef OUTPUT_H
#define OUTPUT_H


/*
=======test_insert_and_print========
        [80]
    [75]
        [65]
[50]
    [25]
        [15]
====================================

======= test_search=================

        [80]
    [75]
        [65]
[50]
    [25]
        [15]
the number program searched is 25
the output is 25

=====================================

======= test_remove_max=================
        [80]
    [75]
        [65]
[50]
    [25]
        [15]
max number is 80
after remove_max()
    [75]
        [65]
[50]
    [25]
        [15]

=====================================


======= test_erase=================
        [80]
    [75]
        [65]
[50]
    [25]
        [15]
the number program erase is 25

after erase()
        [80]
    [75]
        [65]
[50]
    [15]

=====================================


======= test_sorted_list to tree=================
        [9]
    [8]
        [7]
[6]
        [5]
    [4]
        [3]

=====================================


======= test_tree_copy=================
        [80]
    [75]
        [65]
[50]
    [25]
        [15]
after copy
        [80]
    [75]
        [65]
[50]
    [25]
        [15]
=====================================



======= test_height_update=================
                    [80]{0}0
          [75]{1}0
                    [65]{0}0
[50]{2}0
          [25]{1}-1
                    [15]{0}0




after remove max
          [75]{1}-1
                    [65]{0}0
[50]{2}0
          [25]{1}-1
                    [15]{0}0




after erase 75
          [65]{0}0
[50]{2}-1
          [25]{1}-1
                    [15]{0}0



after insert
                    [80]{0}0
          [65]{1}-1
[50]{2}0
          [25]{1}-1
                    [15]{0}0
=====================================


=======test_bst_class=========
Welcome to Binary Search tree !
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:r
R:35[35]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:r
R:79          [79]{0}0
[35]{1}-1
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:r
R:39          [79]{1}-1
                    [39]{0}0
[35]{2}-1
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:r
R:21          [79]{1}-1
                    [39]{0}0
[35]{2}1
          [21]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:r
R:71          [79]{2}-1
                              [71]{0}0
                    [39]{1}-1
[35]{3}2
          [21]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:i
I:28
          [79]{2}-1
                              [71]{0}0
                    [39]{1}-1
[35]{3}1
                    [28]{0}0
          [21]{1}-1
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:i
I:19
          [79]{2}-1
                              [71]{0}0
                    [39]{1}-1
[35]{3}1
                    [28]{0}0
          [21]{1}0
                    [19]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:s
S:28
found!28
          [79]{2}-1
                              [71]{0}0
                    [39]{1}-1
[35]{3}1
                    [28]{0}0
          [21]{1}0
                    [19]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:s
S:100
not found!
          [79]{2}-1
                              [71]{0}0
                    [39]{1}-1
[35]{3}1
                    [28]{0}0
          [21]{1}0
                    [19]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:e
E:71
Erase 71 successfully.
          [79]{2}-1
                    [39]{1}0
[35]{3}1
                    [28]{0}0
          [21]{1}0
                    [19]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:e
E:100
fail 100 not found
          [79]{2}-1
                    [39]{1}0
[35]{3}1
                    [28]{0}0
          [21]{1}0
                    [19]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:c
C: clear
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:r
R:94[94]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:r
R:67[94]{1}-1
          [67]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:r
R:96          [96]{0}0
[94]{1}0
          [67]{0}0
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:r
R:74          [96]{0}0
[94]{2}-1
                    [74]{0}0
          [67]{1}-1
-------------------------------------
[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:
:x
Press <RETURN> to close this window...


*/
#endif // OUTPUT_H
