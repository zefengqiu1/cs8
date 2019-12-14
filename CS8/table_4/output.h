#ifndef OUTPUT_H
#define OUTPUT_H
/*

  test map iterator

30766 34101 37348 37355 37701 39640 40001 44342 45651 48968 49003 51236 51746 53786 53798 55378 55597 57412 57453 57710 57843 59436 59481 60616 60713 60768 61164 62928 63060 63318 66442 68254 68509 68556 70694 73727 74271 78491 82521 82532 83415 83433 85832 86732 87173 88518 98403 98476 100385 103028 109230 110348 127185 131340 140547 ]
yours|[7577 87186 ]
yourself|[1742 60741 83573 127146 146706 ]
youth|[2926 3747 36059 58272 63134 63833 67348 77050 77249 85571 86566 90760 95709 113169 135389 ]
youthful|[2820 3075 50155 64964 121595 135658 147070 ]
ypsies|[6276 ]
yptic|[123163 ]
ys|[69522 85639 106528 120925 ]
ything|[84363 ]
z|[14138 35639 49348 77003 ]
zed|[32479 91960 101862 ]
zinc|[14189 81167 101941 113118 119364 138883 ]
zines|[143021 ]
zither|[34042 34070 39820 39840 ]
zling|[39287 ]
zoological|[141634 ]
zzards|[91188 ]



---------------------------------------------------
---------------------------------------------------
Indices of "ice"
ice: [375 6486 6527 8773 8797 8856 11211 11237 19758 46654 47121 54443 61011 78022 78706 79379 79657 92714 95734 97005 109116 117420 136951 ]



---------------------------------------------------
listing indices from "ask" to "asker"
---------------------------------------------------
ask|[4971 6200 11023 11131 24541 25403 34173 45605 57884 93167 99236 100379 114396 116041 116701 117578 118901 119646 124476 129186 131199 133976 146087 ]
aske|[10545 ]
asked|[3641 6125 8673 9464 12266 12564 14658 15032 16124 16638 16664 16696 16728 16761 19056 20326 20481 20650 20672 23270 23683 24771 25475 28351 28435 28606 28858 30623 32926 33608 34624 35657 36649 37131 37183 43452 44337 45308 45581 48956 49046 49280 50992 51330 51751 53592 54020 56225 56229 59067 60285 60399 60421 60443 62976 64013 65021 65698 65744 66097 66433 66977 67022 67070 69329 72088 74507 74530 78099 80834 82186 84719 84753 86770 89813 89947 90334 92489 94597 94689 96933 99729 100898 101000 101670 103169 104544 107122 108893 110804 111798 112212 112898 114499 115344 115636 116652 118129 119821 122149 123536 126649 127129 127658 127823 128958 134346 137234 138658 141498 146689 ]



========== E N D  ====================
Press <RETURN> to close this window...




/////----------------test sample.txt////----------
------ SQL Tables I Manage: --------
employee
student
---------------------------
please enter the command
>sample
//****************************************************************************
//		CREATE AND INSERT
//****************************************************************************

//---- employee table ----------
commmand[0]:make table employee fields  last, 		first, 			dep
SQL::create table (employee,[last first dep ])
employee table created col: [last first dep ]
SQL: DONE
commmand[1]:insert into employee values Blow, 		Joe, 			CS
SQL::inserted
SQL: DONE
commmand[2]:insert into employee values Johnson, 	"Jimmy", 		Chemistry
SQL::inserted
SQL: DONE
commmand[3]:insert into employee values Yang, 		Bo, 			CS
SQL::inserted
SQL: DONE
commmand[4]:insert into employee values "Jackson",	Billy, 			Math
SQL::inserted
SQL: DONE
commmand[5]:insert into employee values Johnson,	Billy, 			"Phys Ed"
SQL::inserted
SQL: DONE
commmand[6]:insert into employee values "Van Gogh",	"Jim Bob", 		"Phys Ed"
SQL::inserted
SQL: DONE

commmand[7]:select * from employee
table_name: select_all0      records: 6
              Record                last               first                 dep
                   0                Blow                  Joe                   CS

                   1             Johnson                Jimmy            Chemistry

                   2                Yang                   Bo                   CS

                   3             Jackson                Billy                 Math

                   4             Johnson                Billy              Phys Ed

                   5            Van Gogh              Jim Bob              Phys Ed


SQL: DONE

//----- student table ----------
commmand[8]:make table student fields 	fname, 			lname, 		major, 				age
SQL::create table (student,[fname lname major age ])
student table created col: [fname lname major age ]
SQL: DONE
commmand[9]:insert into student values 	Flo, 			Yao, 		CS, 				20
SQL::inserted
SQL: DONE
commmand[10]:insert into student values 	"Flo", 			"Jackson", 	Math,	 			21
SQL::inserted
SQL: DONE
commmand[11]:insert into student values 	Calvin, 		Woo, 	Physics,			22
SQL::inserted
SQL: DONE
commmand[12]:insert into student values 	"Anna Grace", 	"Del Rio", 	CS,	 				22
SQL::inserted
SQL: DONE
commmand[13]:select * from student
table_name: select_all1      records: 4
              Record               fname               lname               major                 age
                   0                 Flo                  Yao                   CS                   20

                   1                 Flo              Jackson                 Math                   21

                   2              Calvin                  Woo              Physics                   22

                   3          Anna Grace              Del Rio                   CS                   22


SQL: DONE



//****************************************************************************
//		SIMPLE SELECT
//****************************************************************************

commmand[14]:select * from student
table_name: select_all2      records: 4
              Record               fname               lname               major                 age
                   0                 Flo                  Yao                   CS                   20

                   1                 Flo              Jackson                 Math                   21

                   2              Calvin                  Woo              Physics                   22

                   3          Anna Grace              Del Rio                   CS                   22


SQL: DONE

//------- simple strings -------------------
commmand[15]:select * from student where lname = Jackson
table_name: result3        records: 1
              Record               fname               lname               major                 age
                   0                 Flo              Jackson                 Math                   21


SQL: DONE

//----- quoted strings ---------------------
commmand[16]:select * from student where lname = "Del Rio"
table_name: result4        records: 1
              Record               fname               lname               major                 age
                   0          Anna Grace              Del Rio                   CS                   22


SQL: DONE

//-------- non-existing string ------------------
commmand[17]:select * from student where lname = "Does Not Exist"
table_name: result5        records: 0
              Record               fname               lname               major                 age

SQL: DONE

//****************************************************************************
//		RELATIONAL OPERATORS:
//****************************************************************************

//.................
//:Greater Than   :
//.................
commmand[18]:select * from student where lname > Yang
table_name: result6        records: 1
              Record               fname               lname               major                 age
                   0                 Flo                  Yao                   CS                   20


SQL: DONE


//. . . . . . . . . . . . . (Greater Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
commmand[19]:select * from student where age > 50
table_name: result7        records: 0
              Record               fname               lname               major                 age

SQL: DONE

//. . . . . . . . . . . . . (Greater than: last item) . . . . . . . . . . . . . . . . . .
commmand[20]:select * from student where age  > 53
table_name: result8        records: 0
              Record               fname               lname               major                 age

SQL: DONE

//. . . . . . . . . . . . . (Greater Than: Passed last item) . . . . . . . . . . . . . . . . . . . . .
commmand[21]:select * from student where age > 54
table_name: result9        records: 0
              Record               fname               lname               major                 age

SQL: DONE

//.................
//:Greater Equal  :
//.................
commmand[22]:select * from student where lname >= Yang
table_name: result10        records: 1
              Record               fname               lname               major                 age
                   0                 Flo                  Yao                   CS                   20


SQL: DONE
//. . . . . .  (Greater Equal non-existing: ) . . . . . . . . . . .
commmand[23]:select * from employee where last >= Jack
table_name: result11        records: 5
              Record                last               first                 dep
                   0             Johnson                Jimmy            Chemistry

                   1                Yang                   Bo                   CS

                   2             Jackson                Billy                 Math

                   3             Johnson                Billy              Phys Ed

                   4            Van Gogh              Jim Bob              Phys Ed


SQL: DONE


//.................
//:Less Than      :
//.................


//. . . . . . . . . . . . . (Less Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
commmand[24]:select * from student where lname < Jackson
table_name: result12        records: 1
              Record               fname               lname               major                 age
                   0          Anna Grace              Del Rio                   CS                   22


SQL: DONE

//. . . . . . . . . . . . . (Less than: first item) . . . . . . . . . . . . . . . . . .
commmand[25]:select * from student where age  < 20
table_name: result13        records: 0
              Record               fname               lname               major                 age

SQL: DONE


//. . . . . . . . . . . . . (Less Than: before first item) . . . . . . . . . . . . . . . . . . . . .

commmand[26]:select * from student where age  < 19
table_name: result14        records: 0
              Record               fname               lname               major                 age

SQL: DONE


//.................
//:Less Equal     :
//.................

commmand[27]:select * from student where lname <= Smith
table_name: result15        records: 2
              Record               fname               lname               major                 age
                   0                 Flo              Jackson                 Math                   21

                   1          Anna Grace              Del Rio                   CS                   22


SQL: DONE

//. . . . . .  (Less Equal non-existing: ) . . . . . . . . . . .
commmand[28]:select * from employee where last <= Peach
table_name: result16        records: 4
              Record                last               first                 dep
                   0                Blow                  Joe                   CS

                   1             Johnson                Jimmy            Chemistry

                   2             Jackson                Billy                 Math

                   3             Johnson                Billy              Phys Ed


SQL: DONE

//****************************************************************************
//		LOGICAL OPERATORS
//****************************************************************************


//.................
//:AND            :
//.................

commmand[29]:select * from student where fname = "Flo" and lname = "Yao"
table_name: result17        records: 1
              Record               fname               lname               major                 age
                   0                 Flo                  Yao                   CS                   20


SQL: DONE


//.................
//:OR            :
//.................
commmand[30]:select * from student where fname = Flo or lname = Jackson
table_name: result18        records: 2
              Record               fname               lname               major                 age
                   0                 Flo                  Yao                   CS                   20

                   1                 Flo              Jackson                 Math                   21


SQL: DONE


//.................
//:OR AND         :
//.................
commmand[31]:select * from student where fname = Flo or major = CS and age <= 23
table_name: result19        records: 3
              Record               fname               lname               major                 age
                   0                 Flo                  Yao                   CS                   20

                   1                 Flo              Jackson                 Math                   21

                   2          Anna Grace              Del Rio                   CS                   22


SQL: DONE


//.................
//:AND OR AND     :
//.................

commmand[32]:select * from student where age <30 and major=CS or major = Physics and lname = Jackson
table_name: result20        records: 2
              Record               fname               lname               major                 age
                   0                 Flo                  Yao                   CS                   20

                   1          Anna Grace              Del Rio                   CS                   22


SQL: DONE


//.................
//:OR AND OR      :
//.................

commmand[33]:select * from student where lname = Yang or major = CS and age < 23 or lname = Jackson
table_name: result21        records: 3
              Record               fname               lname               major                 age
                   0                 Flo                  Yao                   CS                   20

                   1                 Flo              Jackson                 Math                   21

                   2          Anna Grace              Del Rio                   CS                   22


SQL: DONE


//test_select//

------ SQL Tables I Manage: --------
employee
student
---------------------------
please enter the command
>select
//****************************************************************************
//		CREATE TABLES AND INSERT RECORDS
//****************************************************************************


commmand[0]:make table employee fields  last, 		first, 			dep,  		salary, 	year
SQL::create table (employee,[last first dep salary year ])
employee table created col: [last first dep salary year ]
SQL: DONE
commmand[1]:insert into employee values Blow, 		Joe, 			CS,		 	100000, 	2018
SQL::inserted
SQL: DONE
commmand[2]:insert into employee values Blow, 		JoAnn,			Physics, 	200000, 	2016
SQL::inserted
SQL: DONE
commmand[3]:insert into employee values Johnson, 	Jack, 			HR, 		150000, 	2014
SQL::inserted
SQL: DONE
commmand[4]:insert into employee values Johnson, 	"Jimmy", 		Chemistry,	140000, 	2018
SQL::inserted
SQL: DONE
commmand[5]:insert into employee values Yao,	 	Jimmy, 			Math,		145000, 	2014
SQL::inserted
SQL: DONE
commmand[6]:insert into employee values "Yao", 		Flo, 			CS,			147000, 	2012
SQL::inserted
SQL: DONE
commmand[7]:insert into employee values Yang, 		Bo, 			CS,			160000, 	2013
SQL::inserted
SQL: DONE
commmand[8]:insert into employee values Jackson,	"Flo", 			Math,		165000, 	2017
SQL::inserted
SQL: DONE
commmand[9]:insert into employee values Jackson,	Bo,	 		Chemistry,	130000, 	2011
SQL::inserted
SQL: DONE
commmand[10]:insert into employee values "Jackson",	Billy, 			Math,	 	170000, 	2017
SQL::inserted
SQL: DONE
commmand[11]:insert into employee values Johnson,	"Mary Ann", 	Math,	165000, 	2014
SQL::inserted
SQL: DONE
commmand[12]:insert into employee values Johnson,	"Billy Bob", 	Physics142000, 	2014
SQL::inserted
SQL: DONE
commmand[13]:insert into employee values Johnson,	Billy, 			"Phys Ed",	102000, 	2014
SQL::inserted
SQL: DONE
commmand[14]:insert into employee values "Van Gogh",	Vincent, 		Art,		240000, 	2015
SQL::inserted
SQL: DONE
commmand[15]:insert into employee values "Van Gogh",	Vincent, 		CS,			245000, 	2015
SQL::inserted
SQL: DONE
commmand[16]:insert into employee values "Van Gogh",	"Jim Bob", 		"Phys Ed",	230000, 	2010
SQL::inserted
SQL: DONE
commmand[17]:select * from employee
table_name: select_all0      records: 16
              Record                last               first                 dep              salary                year
                   0                Blow                  Joe                   CS               100000                 2018

                   1                Blow                JoAnn              Physics               200000                 2016

                   2             Johnson                 Jack                   HR               150000                 2014

                   3             Johnson                Jimmy            Chemistry               140000                 2018

                   4                 Yao                Jimmy                 Math               145000                 2014

                   5                 Yao                  Flo                   CS               147000                 2012

                   6                Yang                   Bo                   CS               160000                 2013

                   7             Jackson                  Flo                 Math               165000                 2017

                   8             Jackson                   Bo            Chemistry               130000                 2011

                   9             Jackson                Billy                 Math               170000                 2017

                  10             Johnson             Mary Ann                 Math               165000                 2014

                  11             Johnson            Billy Bob              Physics               142000                 2014

                  12             Johnson                Billy              Phys Ed               102000                 2014

                  13            Van Gogh              Vincent                  Art               240000                 2015

                  14            Van Gogh              Vincent                   CS               245000                 2015

                  15            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE

commmand[18]:make table student fields fname, lname, major, age, company
SQL::create table (student,[fname lname major age company ])
student table created col: [fname lname major age company ]
SQL: DONE
commmand[19]:insert into student values Flo, 			Yao, 		CS, 				20, 	Google
SQL::inserted
SQL: DONE
commmand[20]:insert into student values Bo, 				Yang, 	CS, 				28,		Microsoft
SQL::inserted
SQL: DONE
commmand[21]:insert into student values "Sammuel L.", 	Jackson, 	CS, 	40,		Uber
SQL::inserted
SQL: DONE
commmand[22]:insert into student values "Flo", 			"Jackson", 	Math,	 			21,		Google
SQL::inserted
SQL: DONE
commmand[23]:insert into student values "Greg", 			"Pearson", 	Physics,			20,		Amazon
SQL::inserted
SQL: DONE
commmand[24]:insert into student values "Jim Bob", 		Smith, 		Math,	 			23,		Verizon
SQL::inserted
SQL: DONE
commmand[25]:insert into student values Calvin, 			Woo, 	Physics,			22,		Uber
SQL::inserted
SQL: DONE
commmand[26]:insert into student values "Anna Grace", 	"Del Rio", 	CS,	22,		USAF
SQL::inserted
SQL: DONE
commmand[27]:insert into student values "Teresa Mae", 	Gowers, 	Chemistry,			22,		Verizon
SQL::inserted
SQL: DONE
commmand[28]:insert into student values Alex,			Smith,		"Gender Studies", 	53,		Amazon
SQL::inserted
SQL: DONE
commmand[29]:select * from student
table_name: select_all1      records: 10
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                  Bo                 Yang                   CS                   28            Microsoft

                   2          Sammuel L.              Jackson                   CS                   40                 Uber

                   3                 Flo              Jackson                 Math                   21               Google

                   4                Greg              Pearson              Physics                   20               Amazon

                   5             Jim Bob                Smith                 Math                   23              Verizon

                   6              Calvin                  Woo              Physics                   22                 Uber

                   7          Anna Grace              Del Rio                   CS                   22                 USAF

                   8          Teresa Mae               Gowers            Chemistry                   22              Verizon

                   9                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE


//****************************************************************************
//		SIMPLE SELECT:
//****************************************************************************

commmand[30]:select * from student
table_name: select_all2      records: 10
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                  Bo                 Yang                   CS                   28            Microsoft

                   2          Sammuel L.              Jackson                   CS                   40                 Uber

                   3                 Flo              Jackson                 Math                   21               Google

                   4                Greg              Pearson              Physics                   20               Amazon

                   5             Jim Bob                Smith                 Math                   23              Verizon

                   6              Calvin                  Woo              Physics                   22                 Uber

                   7          Anna Grace              Del Rio                   CS                   22                 USAF

                   8          Teresa Mae               Gowers            Chemistry                   22              Verizon

                   9                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE

//------- simple strings -------------------
commmand[31]:select * from student where lname = Jackson
table_name: result3        records: 2
              Record               fname               lname               major                 age             company
                   0          Sammuel L.              Jackson                   CS                   40                 Uber

                   1                 Flo              Jackson                 Math                   21               Google


SQL: DONE
commmand[32]:select * from student where major = CS
table_name: result4        records: 4
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                  Bo                 Yang                   CS                   28            Microsoft

                   2          Sammuel L.              Jackson                   CS                   40                 Uber

                   3          Anna Grace              Del Rio                   CS                   22                 USAF


SQL: DONE
commmand[33]:select * from student where company = Uber
table_name: result5        records: 2
              Record               fname               lname               major                 age             company
                   0          Sammuel L.              Jackson                   CS                   40                 Uber

                   1              Calvin                  Woo              Physics                   22                 Uber


SQL: DONE

//----- quoted strings ---------------------
commmand[34]:select * from student where lname = "Del Rio"
table_name: result6        records: 1
              Record               fname               lname               major                 age             company
                   0          Anna Grace              Del Rio                   CS                   22                 USAF


SQL: DONE
commmand[35]:select * from student where fname = "Jim Bob"
table_name: result7        records: 1
              Record               fname               lname               major                 age             company
                   0             Jim Bob                Smith                 Math                   23              Verizon


SQL: DONE
commmand[36]:select * from student where fname = "Anna Grace"
table_name: result8        records: 1
              Record               fname               lname               major                 age             company
                   0          Anna Grace              Del Rio                   CS                   22                 USAF


SQL: DONE
commmand[37]:select * from student where fname = "Teresa Mae"
table_name: result9        records: 1
              Record               fname               lname               major                 age             company
                   0          Teresa Mae               Gowers            Chemistry                   22              Verizon


SQL: DONE

//-------- non-existing string ------------------
commmand[38]:select * from student where lname = "Does Not Exist"
table_name: result10        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE

//****************************************************************************
//		RELATIONAL OPERATORS:
//****************************************************************************

//.................
//:Greater Than   :
//.................
commmand[39]:select * from student where lname > Yang
table_name: result11        records: 1
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google


SQL: DONE
commmand[40]:select * from student where major > Math
table_name: result12        records: 2
              Record               fname               lname               major                 age             company
                   0                Greg              Pearson              Physics                   20               Amazon

                   1              Calvin                  Woo              Physics                   22                 Uber


SQL: DONE
commmand[41]:select * from student where fname > "Sammuel L."
table_name: result13        records: 1
              Record               fname               lname               major                 age             company
                   0          Teresa Mae               Gowers            Chemistry                   22              Verizon


SQL: DONE
commmand[42]:select * from employee where salary > 200000
table_name: result14        records: 3
              Record                last               first                 dep              salary                year
                   0            Van Gogh              Vincent                  Art               240000                 2015

                   1            Van Gogh              Vincent                   CS               245000                 2015

                   2            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE
commmand[43]:select * from employee where dep > Chemistry
table_name: result15        records: 9
              Record                last               first                 dep              salary                year
                   0                Blow                JoAnn              Physics               200000                 2016

                   1             Johnson                 Jack                   HR               150000                 2014

                   2                 Yao                Jimmy                 Math               145000                 2014

                   3             Jackson                  Flo                 Math               165000                 2017

                   4             Jackson                Billy                 Math               170000                 2017

                   5             Johnson             Mary Ann                 Math               165000                 2014

                   6             Johnson            Billy Bob              Physics               142000                 2014

                   7             Johnson                Billy              Phys Ed               102000                 2014

                   8            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE
commmand[44]:select * from employee where last > Jackson
table_name: result16        records: 11
              Record                last               first                 dep              salary                year
                   0             Johnson                 Jack                   HR               150000                 2014

                   1             Johnson                Jimmy            Chemistry               140000                 2018

                   2                 Yao                Jimmy                 Math               145000                 2014

                   3                 Yao                  Flo                   CS               147000                 2012

                   4                Yang                   Bo                   CS               160000                 2013

                   5             Johnson             Mary Ann                 Math               165000                 2014

                   6             Johnson            Billy Bob              Physics               142000                 2014

                   7             Johnson                Billy              Phys Ed               102000                 2014

                   8            Van Gogh              Vincent                  Art               240000                 2015

                   9            Van Gogh              Vincent                   CS               245000                 2015

                  10            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE
commmand[45]:select * from employee where first > "Billy Bob"
table_name: result17        records: 13
              Record                last               first                 dep              salary                year
                   0                Blow                  Joe                   CS               100000                 2018

                   1                Blow                JoAnn              Physics               200000                 2016

                   2             Johnson                 Jack                   HR               150000                 2014

                   3             Johnson                Jimmy            Chemistry               140000                 2018

                   4                 Yao                Jimmy                 Math               145000                 2014

                   5                 Yao                  Flo                   CS               147000                 2012

                   6                Yang                   Bo                   CS               160000                 2013

                   7             Jackson                  Flo                 Math               165000                 2017

                   8             Jackson                   Bo            Chemistry               130000                 2011

                   9             Johnson             Mary Ann                 Math               165000                 2014

                  10            Van Gogh              Vincent                  Art               240000                 2015

                  11            Van Gogh              Vincent                   CS               245000                 2015

                  12            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE


//. . . . . . . . . . . . . (Greater Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
commmand[46]:select * from student where age > 50
table_name: result18        records: 1
              Record               fname               lname               major                 age             company
                   0                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE
commmand[47]:select * from student where age > 35
table_name: result19        records: 2
              Record               fname               lname               major                 age             company
                   0          Sammuel L.              Jackson                   CS                   40                 Uber

                   1                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE
commmand[48]:select * from student where fname > T
table_name: result20        records: 1
              Record               fname               lname               major                 age             company
                   0          Teresa Mae               Gowers            Chemistry                   22              Verizon


SQL: DONE
commmand[49]:select * from employee where salary > 130000
table_name: result21        records: 13
              Record                last               first                 dep              salary                year
                   0                Blow                JoAnn              Physics               200000                 2016

                   1             Johnson                 Jack                   HR               150000                 2014

                   2             Johnson                Jimmy            Chemistry               140000                 2018

                   3                 Yao                Jimmy                 Math               145000                 2014

                   4                 Yao                  Flo                   CS               147000                 2012

                   5                Yang                   Bo                   CS               160000                 2013

                   6             Jackson                  Flo                 Math               165000                 2017

                   7             Jackson                Billy                 Math               170000                 2017

                   8             Johnson             Mary Ann                 Math               165000                 2014

                   9             Johnson            Billy Bob              Physics               142000                 2014

                  10            Van Gogh              Vincent                  Art               240000                 2015

                  11            Van Gogh              Vincent                   CS               245000                 2015

                  12            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE
commmand[50]:select * from employee where  year > 2009
table_name: result22        records: 16
              Record                last               first                 dep              salary                year
                   0                Blow                  Joe                   CS               100000                 2018

                   1                Blow                JoAnn              Physics               200000                 2016

                   2             Johnson                 Jack                   HR               150000                 2014

                   3             Johnson                Jimmy            Chemistry               140000                 2018

                   4                 Yao                Jimmy                 Math               145000                 2014

                   5                 Yao                  Flo                   CS               147000                 2012

                   6                Yang                   Bo                   CS               160000                 2013

                   7             Jackson                  Flo                 Math               165000                 2017

                   8             Jackson                   Bo            Chemistry               130000                 2011

                   9             Jackson                Billy                 Math               170000                 2017

                  10             Johnson             Mary Ann                 Math               165000                 2014

                  11             Johnson            Billy Bob              Physics               142000                 2014

                  12             Johnson                Billy              Phys Ed               102000                 2014

                  13            Van Gogh              Vincent                  Art               240000                 2015

                  14            Van Gogh              Vincent                   CS               245000                 2015

                  15            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE

//. . . . . . . . . . . . . (Greater than: last item) . . . . . . . . . . . . . . . . . .
commmand[51]:select * from student where age  > 53
table_name: result23        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[52]:select * from student where lname > Yao
table_name: result24        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[53]:select * from student where fname > "Teresa Mae"
table_name: result25        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[54]:select * from employee where last > "Van Gogh"
table_name: result26        records: 3
              Record                last               first                 dep              salary                year
                   0                 Yao                Jimmy                 Math               145000                 2014

                   1                 Yao                  Flo                   CS               147000                 2012

                   2                Yang                   Bo                   CS               160000                 2013


SQL: DONE
commmand[55]:select * from employee where first > Vincent
table_name: result27        records: 0
              Record                last               first                 dep              salary                year

SQL: DONE
commmand[56]:select * from employee where salary > 260000
table_name: result28        records: 0
              Record                last               first                 dep              salary                year

SQL: DONE

//. . . . . . . . . . . . . (Greater Than: Passed last item) . . . . . . . . . . . . . . . . . . . . .
commmand[57]:select * from student where age > 54
table_name: result29        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[58]:select * from student where lname > Zoolander
table_name: result30        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[59]:select * from employee where last > Zoolaner
table_name: result31        records: 0
              Record                last               first                 dep              salary                year

SQL: DONE
commmand[60]:select * from employee where first > Xu
table_name: result32        records: 0
              Record                last               first                 dep              salary                year

SQL: DONE

//.................
//:Greater Equal  :
//.................
commmand[61]:select * from student where lname >= Yang
table_name: result33        records: 2
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                  Bo                 Yang                   CS                   28            Microsoft


SQL: DONE
commmand[62]:select * from student where fname >= "Sammuel L."
table_name: result34        records: 2
              Record               fname               lname               major                 age             company
                   0          Sammuel L.              Jackson                   CS                   40                 Uber

                   1          Teresa Mae               Gowers            Chemistry                   22              Verizon


SQL: DONE
commmand[63]:select * from student where age >= 40
table_name: result35        records: 2
              Record               fname               lname               major                 age             company
                   0          Sammuel L.              Jackson                   CS                   40                 Uber

                   1                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE
//. . . . . .  (Greater Equal non-existing: ) . . . . . . . . . . .
commmand[64]:select * from employee where last >= Jack
table_name: result36        records: 14
              Record                last               first                 dep              salary                year
                   0             Johnson                 Jack                   HR               150000                 2014

                   1             Johnson                Jimmy            Chemistry               140000                 2018

                   2                 Yao                Jimmy                 Math               145000                 2014

                   3                 Yao                  Flo                   CS               147000                 2012

                   4                Yang                   Bo                   CS               160000                 2013

                   5             Jackson                  Flo                 Math               165000                 2017

                   6             Jackson                   Bo            Chemistry               130000                 2011

                   7             Jackson                Billy                 Math               170000                 2017

                   8             Johnson             Mary Ann                 Math               165000                 2014

                   9             Johnson            Billy Bob              Physics               142000                 2014

                  10             Johnson                Billy              Phys Ed               102000                 2014

                  11            Van Gogh              Vincent                  Art               240000                 2015

                  12            Van Gogh              Vincent                   CS               245000                 2015

                  13            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE
commmand[65]:select * from employee where first >= Bill
table_name: result37        records: 16
              Record                last               first                 dep              salary                year
                   0                Blow                  Joe                   CS               100000                 2018

                   1                Blow                JoAnn              Physics               200000                 2016

                   2             Johnson                 Jack                   HR               150000                 2014

                   3             Johnson                Jimmy            Chemistry               140000                 2018

                   4                 Yao                Jimmy                 Math               145000                 2014

                   5                 Yao                  Flo                   CS               147000                 2012

                   6                Yang                   Bo                   CS               160000                 2013

                   7             Jackson                  Flo                 Math               165000                 2017

                   8             Jackson                   Bo            Chemistry               130000                 2011

                   9             Jackson                Billy                 Math               170000                 2017

                  10             Johnson             Mary Ann                 Math               165000                 2014

                  11             Johnson            Billy Bob              Physics               142000                 2014

                  12             Johnson                Billy              Phys Ed               102000                 2014

                  13            Van Gogh              Vincent                  Art               240000                 2015

                  14            Van Gogh              Vincent                   CS               245000                 2015

                  15            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE
commmand[66]:select * from employee where salary >= 235000
table_name: result38        records: 2
              Record                last               first                 dep              salary                year
                   0            Van Gogh              Vincent                  Art               240000                 2015

                   1            Van Gogh              Vincent                   CS               245000                 2015


SQL: DONE


//.................
//:Less Than      :
//.................


//. . . . . . . . . . . . . (Less Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
commmand[67]:select * from student where lname < Jackson
table_name: result39        records: 2
              Record               fname               lname               major                 age             company
                   0          Anna Grace              Del Rio                   CS                   22                 USAF

                   1          Teresa Mae               Gowers            Chemistry                   22              Verizon


SQL: DONE
commmand[68]:select * from student where major < Math
table_name: result40        records: 6
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                  Bo                 Yang                   CS                   28            Microsoft

                   2          Sammuel L.              Jackson                   CS                   40                 Uber

                   3          Anna Grace              Del Rio                   CS                   22                 USAF

                   4          Teresa Mae               Gowers            Chemistry                   22              Verizon

                   5                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE
commmand[69]:select * from student where fname < "Jim Bob"
table_name: result41        records: 7
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                  Bo                 Yang                   CS                   28            Microsoft

                   2                 Flo              Jackson                 Math                   21               Google

                   3                Greg              Pearson              Physics                   20               Amazon

                   4              Calvin                  Woo              Physics                   22                 Uber

                   5          Anna Grace              Del Rio                   CS                   22                 USAF

                   6                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE
commmand[70]:select * from employee where salary < 200000
table_name: result42        records: 12
              Record                last               first                 dep              salary                year
                   0                Blow                  Joe                   CS               100000                 2018

                   1             Johnson                 Jack                   HR               150000                 2014

                   2             Johnson                Jimmy            Chemistry               140000                 2018

                   3                 Yao                Jimmy                 Math               145000                 2014

                   4                 Yao                  Flo                   CS               147000                 2012

                   5                Yang                   Bo                   CS               160000                 2013

                   6             Jackson                  Flo                 Math               165000                 2017

                   7             Jackson                   Bo            Chemistry               130000                 2011

                   8             Jackson                Billy                 Math               170000                 2017

                   9             Johnson             Mary Ann                 Math               165000                 2014

                  10             Johnson            Billy Bob              Physics               142000                 2014

                  11             Johnson                Billy              Phys Ed               102000                 2014


SQL: DONE
commmand[71]:select * from employee where dep < CS
table_name: result43        records: 1
              Record                last               first                 dep              salary                year
                   0            Van Gogh              Vincent                  Art               240000                 2015


SQL: DONE
commmand[72]:select * from employee where last < Jackson
table_name: result44        records: 2
              Record                last               first                 dep              salary                year
                   0                Blow                  Joe                   CS               100000                 2018

                   1                Blow                JoAnn              Physics               200000                 2016


SQL: DONE
commmand[73]:select * from employee where first < "Billy Bob"
table_name: result45        records: 2
              Record                last               first                 dep              salary                year
                   0             Jackson                Billy                 Math               170000                 2017

                   1             Johnson                Billy              Phys Ed               102000                 2014


SQL: DONE

//. . . . . . . . . . . . . (Less than: first item) . . . . . . . . . . . . . . . . . .
commmand[74]:select * from student where age  < 20
table_name: result46        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[75]:select * from student where lname < "Del Rio"
table_name: result47        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[76]:select * from student where fname < Alex
table_name: result48        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[77]:select * from employee where last < Blow
table_name: result49        records: 0
              Record                last               first                 dep              salary                year

SQL: DONE
commmand[78]:select * from employee where first < Billy
table_name: result50        records: 0
              Record                last               first                 dep              salary                year

SQL: DONE
commmand[79]:select * from employee where salary < 100000
table_name: result51        records: 0
              Record                last               first                 dep              salary                year

SQL: DONE


//. . . . . . . . . . . . . (Less Than: before first item) . . . . . . . . . . . . . . . . . . . . .

commmand[80]:select * from student where age  < 19
table_name: result52        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[81]:select * from student where lname < Adams
table_name: result53        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[82]:select * from student where fname < Adam
table_name: result54        records: 0
              Record               fname               lname               major                 age             company

SQL: DONE
commmand[83]:select * from employee where last < Alex
table_name: result55        records: 0
              Record                last               first                 dep              salary                year

SQL: DONE
commmand[84]:select * from employee where first < Avory
table_name: result56        records: 0
              Record                last               first                 dep              salary                year

SQL: DONE
commmand[85]:select * from employee where dep < Alchemy
table_name: result57        records: 0
              Record                last               first                 dep              salary                year

SQL: DONE


//.................
//:Less Equal     :
//.................

commmand[86]:select * from student where lname <= Smith
table_name: result58        records: 7
              Record               fname               lname               major                 age             company
                   0          Sammuel L.              Jackson                   CS                   40                 Uber

                   1                 Flo              Jackson                 Math                   21               Google

                   2                Greg              Pearson              Physics                   20               Amazon

                   3             Jim Bob                Smith                 Math                   23              Verizon

                   4          Anna Grace              Del Rio                   CS                   22                 USAF

                   5          Teresa Mae               Gowers            Chemistry                   22              Verizon

                   6                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE
commmand[87]:select * from student where fname <= Greg
table_name: result59        records: 7
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                  Bo                 Yang                   CS                   28            Microsoft

                   2                 Flo              Jackson                 Math                   21               Google

                   3                Greg              Pearson              Physics                   20               Amazon

                   4              Calvin                  Woo              Physics                   22                 Uber

                   5          Anna Grace              Del Rio                   CS                   22                 USAF

                   6                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE
commmand[88]:select * from student where age <= 40
table_name: result60        records: 9
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                  Bo                 Yang                   CS                   28            Microsoft

                   2          Sammuel L.              Jackson                   CS                   40                 Uber

                   3                 Flo              Jackson                 Math                   21               Google

                   4                Greg              Pearson              Physics                   20               Amazon

                   5             Jim Bob                Smith                 Math                   23              Verizon

                   6              Calvin                  Woo              Physics                   22                 Uber

                   7          Anna Grace              Del Rio                   CS                   22                 USAF

                   8          Teresa Mae               Gowers            Chemistry                   22              Verizon


SQL: DONE

//. . . . . .  (Less Equal non-existing: ) . . . . . . . . . . .
commmand[89]:select * from employee where last <= Peach
table_name: result61        records: 10
              Record                last               first                 dep              salary                year
                   0                Blow                  Joe                   CS               100000                 2018

                   1                Blow                JoAnn              Physics               200000                 2016

                   2             Johnson                 Jack                   HR               150000                 2014

                   3             Johnson                Jimmy            Chemistry               140000                 2018

                   4             Jackson                  Flo                 Math               165000                 2017

                   5             Jackson                   Bo            Chemistry               130000                 2011

                   6             Jackson                Billy                 Math               170000                 2017

                   7             Johnson             Mary Ann                 Math               165000                 2014

                   8             Johnson            Billy Bob              Physics               142000                 2014

                   9             Johnson                Billy              Phys Ed               102000                 2014


SQL: DONE
commmand[90]:select * from employee where first <= Gary
table_name: result62        records: 7
              Record                last               first                 dep              salary                year
                   0                 Yao                  Flo                   CS               147000                 2012

                   1                Yang                   Bo                   CS               160000                 2013

                   2             Jackson                  Flo                 Math               165000                 2017

                   3             Jackson                   Bo            Chemistry               130000                 2011

                   4             Jackson                Billy                 Math               170000                 2017

                   5             Johnson            Billy Bob              Physics               142000                 2014

                   6             Johnson                Billy              Phys Ed               102000                 2014


SQL: DONE
commmand[91]:select * from employee where salary <= 23500
table_name: result63        records: 14
              Record                last               first                 dep              salary                year
                   0                Blow                  Joe                   CS               100000                 2018

                   1                Blow                JoAnn              Physics               200000                 2016

                   2             Johnson                 Jack                   HR               150000                 2014

                   3             Johnson                Jimmy            Chemistry               140000                 2018

                   4                 Yao                Jimmy                 Math               145000                 2014

                   5                 Yao                  Flo                   CS               147000                 2012

                   6                Yang                   Bo                   CS               160000                 2013

                   7             Jackson                  Flo                 Math               165000                 2017

                   8             Jackson                   Bo            Chemistry               130000                 2011

                   9             Jackson                Billy                 Math               170000                 2017

                  10             Johnson             Mary Ann                 Math               165000                 2014

                  11             Johnson            Billy Bob              Physics               142000                 2014

                  12             Johnson                Billy              Phys Ed               102000                 2014

                  13            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE

//****************************************************************************
//		LOGICAL OPERATORS
//****************************************************************************


//.................
//:AND            :
//.................

commmand[92]:select * from student where fname = "Flo" and lname = "Yao"
table_name: result64        records: 1
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google


SQL: DONE
commmand[93]:select * from student where major = "CS" and age < 25
table_name: result65        records: 2
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1          Anna Grace              Del Rio                   CS                   22                 USAF


SQL: DONE
commmand[94]:select * from student where major < Math and age > 25
table_name: result66        records: 3
              Record               fname               lname               major                 age             company
                   0                  Bo                 Yang                   CS                   28            Microsoft

                   1          Sammuel L.              Jackson                   CS                   40                 Uber

                   2                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE
commmand[95]:select * from employee where dep = CS and salary > 150000
table_name: result67        records: 2
              Record                last               first                 dep              salary                year
                   0                Yang                   Bo                   CS               160000                 2013

                   1            Van Gogh              Vincent                   CS               245000                 2015


SQL: DONE
commmand[96]:select * from employee where last = Jackson and year < 2015
table_name: result68        records: 1
              Record                last               first                 dep              salary                year
                   0             Jackson                   Bo            Chemistry               130000                 2011


SQL: DONE
commmand[97]:select * from employee where last = Johnson and year >=2014
table_name: result69        records: 5
              Record                last               first                 dep              salary                year
                   0             Johnson                 Jack                   HR               150000                 2014

                   1             Johnson                Jimmy            Chemistry               140000                 2018

                   2             Johnson             Mary Ann                 Math               165000                 2014

                   3             Johnson            Billy Bob              Physics               142000                 2014

                   4             Johnson                Billy              Phys Ed               102000                 2014


SQL: DONE


//.................
//:OR            :
//.................
commmand[98]:select * from student where fname = Flo or lname = Jackson
table_name: result70        records: 3
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1          Sammuel L.              Jackson                   CS                   40                 Uber

                   2                 Flo              Jackson                 Math                   21               Google


SQL: DONE
commmand[99]:select * from student where age >=40  or company = Verizon
table_name: result71        records: 4
              Record               fname               lname               major                 age             company
                   0          Sammuel L.              Jackson                   CS                   40                 Uber

                   1             Jim Bob                Smith                 Math                   23              Verizon

                   2          Teresa Mae               Gowers            Chemistry                   22              Verizon

                   3                Alex                Smith       Gender Studies                   53               Amazon


SQL: DONE
commmand[100]:select * from employee where first = Bo or last = Johnson
table_name: result72        records: 7
              Record                last               first                 dep              salary                year
                   0             Johnson                 Jack                   HR               150000                 2014

                   1             Johnson                Jimmy            Chemistry               140000                 2018

                   2                Yang                   Bo                   CS               160000                 2013

                   3             Jackson                   Bo            Chemistry               130000                 2011

                   4             Johnson             Mary Ann                 Math               165000                 2014

                   5             Johnson            Billy Bob              Physics               142000                 2014

                   6             Johnson                Billy              Phys Ed               102000                 2014


SQL: DONE
commmand[101]:select * from employee where year >= 2015 or dep = CS
table_name: result73        records: 9
              Record                last               first                 dep              salary                year
                   0                Blow                  Joe                   CS               100000                 2018

                   1                Blow                JoAnn              Physics               200000                 2016

                   2             Johnson                Jimmy            Chemistry               140000                 2018

                   3                 Yao                  Flo                   CS               147000                 2012

                   4                Yang                   Bo                   CS               160000                 2013

                   5             Jackson                  Flo                 Math               165000                 2017

                   6             Jackson                Billy                 Math               170000                 2017

                   7            Van Gogh              Vincent                  Art               240000                 2015

                   8            Van Gogh              Vincent                   CS               245000                 2015


SQL: DONE


//.................
//:OR AND         :
//.................
commmand[102]:select * from student where fname = Flo or major = CS and age <= 23
table_name: result74        records: 3
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                 Flo              Jackson                 Math                   21               Google

                   2          Anna Grace              Del Rio                   CS                   22                 USAF


SQL: DONE
commmand[103]:select * from student where lname = Jackson or age < 23 and company > Uber
table_name: result75        records: 3
              Record               fname               lname               major                 age             company
                   0          Sammuel L.              Jackson                   CS                   40                 Uber

                   1                 Flo              Jackson                 Math                   21               Google

                   2          Teresa Mae               Gowers            Chemistry                   22              Verizon


SQL: DONE
commmand[104]:select * from employee where last = "Van Gogh" or last = Jackson and salary >= 165000
table_name: result76        records: 5
              Record                last               first                 dep              salary                year
                   0             Jackson                  Flo                 Math               165000                 2017

                   1             Jackson                Billy                 Math               170000                 2017

                   2            Van Gogh              Vincent                  Art               240000                 2015

                   3            Van Gogh              Vincent                   CS               245000                 2015

                   4            Van Gogh              Jim Bob              Phys Ed               230000                 2010


SQL: DONE


//.................
//:AND OR AND     :
//.................

commmand[105]:select * from student where age <30 and major=CS or major = Physics and company = Amazon
table_name: result77        records: 4
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                  Bo                 Yang                   CS                   28            Microsoft

                   2                Greg              Pearson              Physics                   20               Amazon

                   3          Anna Grace              Del Rio                   CS                   22                 USAF


SQL: DONE
commmand[106]:select * from student where age <=40 and company=Uber or major = CS and company = Google
table_name: result78        records: 3
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1          Sammuel L.              Jackson                   CS                   40                 Uber

                   2              Calvin                  Woo              Physics                   22                 Uber


SQL: DONE
commmand[107]:select * from employee where dep = CS and salary >= 160000 or year > 2014 and last = "Van Gogh"
table_name: result79        records: 3
              Record                last               first                 dep              salary                year
                   0                Yang                   Bo                   CS               160000                 2013

                   1            Van Gogh              Vincent                  Art               240000                 2015

                   2            Van Gogh              Vincent                   CS               245000                 2015


SQL: DONE


//.................
//:OR AND OR      :
//.................

commmand[108]:select * from student where lname = Yang or major = CS and age < 23 or company = Google
table_name: result80        records: 4
              Record               fname               lname               major                 age             company
                   0                 Flo                  Yao                   CS                   20               Google

                   1                  Bo                 Yang                   CS                   28            Microsoft

                   2                 Flo              Jackson                 Math                   21               Google

                   3          Anna Grace              Del Rio                   CS                   22                 USAF


SQL: DONE
commmand[109]:select * from student where major = Physics or major = Math and company = Google or lname = Jackson
table_name: result81        records: 4
              Record               fname               lname               major                 age             company
                   0          Sammuel L.              Jackson                   CS                   40                 Uber

                   1                 Flo              Jackson                 Math                   21               Google

                   2                Greg              Pearson              Physics                   20               Amazon

                   3              Calvin                  Woo              Physics                   22                 Uber


SQL: DONE
commmand[110]:select * from employee where dep = CS or year >2014 and year < 2018 or salary >= 265000
table_name: result82        records: 8
              Record                last               first                 dep              salary                year
                   0                Blow                  Joe                   CS               100000                 2018

                   1                Blow                JoAnn              Physics               200000                 2016

                   2                 Yao                  Flo                   CS               147000                 2012

                   3                Yang                   Bo                   CS               160000                 2013

                   4             Jackson                  Flo                 Math               165000                 2017

                   5             Jackson                Billy                 Math               170000                 2017

                   6            Van Gogh              Vincent                  Art               240000                 2015

                   7            Van Gogh              Vincent                   CS               245000                 2015


SQL: DONE


*/
#endif // OUTPUT_H
