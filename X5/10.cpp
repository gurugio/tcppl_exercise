gkim@laptop:~/tcppl_exercise/X5$ g++ 7.cpp
7.cpp: In function ‘int main()’:
7.cpp:8:9: error: missing template arguments before ‘numbers’
    8 |  vector numbers {5, 9, -1, 200, 0};
      |         ^~~~~~~
gkim@laptop:~/tcppl_exercise/X5$ g++ 7.cpp
gkim@laptop:~/tcppl_exercise/X5$ g++ 7.cpp
gkim@laptop:~/tcppl_exercise/X5$ ./a.out
5
9
-1
200
0
gkim@laptop:~/tcppl_exercise/X5$ g++ 7.cpp
gkim@laptop:~/tcppl_exercise/X5$ ./a.out
5
9
-1
200
0
-1
0
5
9
200
gkim@laptop:~/tcppl_exercise/X5$ g++ 7.cpp
7.cpp: In function ‘int main()’:
7.cpp:18:18: error: expected ‘;’ before ‘for’
   18 |  cout << "after:"
      |                  ^
      |                  ;
   19 |  for (auto a: numbers)
      |  ~~~              
gkim@laptop:~/tcppl_exercise/X5$ g++ 7.cpp
gkim@laptop:~/tcppl_exercise/X5$ ./a.out
before5
9
-1
200
0
after:-1
0
5
9
200
gkim@laptop:~/tcppl_exercise/X5$ g++ 7.cpp
gkim@laptop:~/tcppl_exercise/X5$ ./a.out
before:5
9
-1
200
0
after:-1
0
5
9
200
gkim@laptop:~/tcppl_exercise/X5$ g++ 8.cpp
8.cpp: In function ‘int main()’:
8.cpp:12:2: error: expected ‘,’ or ‘;’ before ‘cout’
   12 |  cout << "before:";
      |  ^~~~
gkim@laptop:~/tcppl_exercise/X5$g++ 8.cpp
gkim@laptop:~/tcppl_exercise/X5$ ./a.out
before:Kant
Plato
Aristotle
Kierkegard
Hume
after:Aristotle
Hume
Kant
Kierkegard
Plato
gkim@laptop:~/tcppl_exercise/X5$ g++ 9.cpp
gkim@laptop:~/tcppl_exercise/X5$ ./a.out
gkim@laptop:~/tcppl_exercise/X5$ ls
1-4.txt  5.cpp  5.cpp~  6.cpp  6.cpp~  7.cpp  7.cpp~  8.cpp  8.cpp~  9.cpp  a.out  intfile.txt
gkim@laptop:~/tcppl_exercise/X5$ cat intfile.txt 
1234gkim@laptop:~/tcppl_exercise/X5$ 
gkim@laptop:~/tcppl_exercise/X5$ 
gkim@laptop:~/tcppl_exercise/X5$ g++ 9.cpp
gkim@laptop:~/tcppl_exercise/X5$ ./a.out
gkim@laptop:~/tcppl_exercise/X5$ cat intfile.txt 
1513060223gkim@laptop:~/tcppl_exercise/X5$ g++ 9.cpp
gkim@laptop:~/tcppl_exercise/X5$ ./a.out
gkim@laptop:~/tcppl_exercise/X5$ cat intfile.txt 
1425469030362841936101195326071755812517974559981777575846380261345785917104212729245525090054616074959889010627458879799554533312131592557709189411857574347214213140714459527885258372167567935475042131479481354168738841559332582450250516939896150377036173481092318294046167156414751882486878110738999810784834117469564901824948123728455761377048688577258211514372865356857495308626367974385205125792024011966063221427716418702994302943241249237049122017065747189602977486092166966312960321091777226760675915046889355441443255845466561655065972131471600266467624223223799201395847813738576221301707210613431320105132209820301629729904800081109047919139705218913473375031417674286223953747457774096466796960165167016511607683981410038209167537507810303504971158584336388813099169348010111202784104564198581050685388166442273510409665145582677121795894335130743413878149151116623691655338081132083198722128316837158513021119658780461118796845546694482121544658731865070119643687681439400334776424797283682080943586852193719319516937202894714782828200600447048209778602913813660564971825099388131671123914167418861342038475210194106197500959899044916315176282446090174625053346802051436357544732536633651518148908292036312693417524483632035777402157857352120710990641852662522870490208700040213213634460218140770604897497601682581244138071694130980980523991857399836307516758663022065017961167590666945124540125957278937778477277265049110253830418954130171381667953607872984179936572619264004891241524502114096499914204377584648921810292587531720617296770104634734437628443623856147014484872329858211021726819598946082583961782482889621122220765498314752124665203765060342041584906514142427041595727960167542185417920274762208948031777960158153995684516025627562383494951191838924138147959714798739971853202751523523372178879567121457902810966570219489842021949016656154028087727164540252483159116504981468405636278322776918987871081206277128128154252199795549818568805481697391587264714554130512486012253297932056742030152601966485580630414492152289810987721094155799493570504215094722426546148678890779173861809460542571618934698076877914671554409918169500281680588697182605532072350759173108684319101116828555785281482390303968905162213712105033286215367830206216870289895975767071983426923764875134506835090136196293916206814381956050318195578063567353589302137174410672785993899738981027953180723215993254547270141126895986991006251724274533280770187396684823396346884039353790591447451430120246256818361808951416356593119209997021559400209465865573164531161913610819306019301496520445112597119811450812219697182369345378681340659285153707182512366750421751332070383487915702193471753139302198281336979723345929525435484158144510717667401065441750152640484114186507791419232342197385627247362969911079295891242729217166572966911294889891189904224249891332174862509797302250717464117787271126472118103728568646366166165051513112793652105718191750841909915127788341722459821061256520783442177052180161829471681603779610186336265425778081881479547397554819196122858711532282412239274432873746391136741821466656660195310430812431631715090772375551199384430462114820997441801923771157141726814527198242230864891085584136616515542181321032183642604515316433305230434915100036542052426772700095672212829837072098092117187292985233925304549768202116284117337137469160820506119272791362451210817218792431659384573430132769817558766209781624856447621661863387150307790614008488510857970088083140833631713742389749614248296255444924061860323541808989307106753589822284354771393243117676315702036582691434913352133887722072705079918898901721307677689106418826913506115851500405602168870037792500718010123065282118833146174256594710332846904569942601256945686388878949597079145195259046119719303296025051921915654247453900915047429262079480084128352831642479517615483998319974607474494309835849825312848904521383820318108554905210272969765440143592253673230424914204441996216909540511155432094909242842166230354975051439319425275322119297810200746008018392283356889330755235478138111586515291438272743920211855654874886403105206388457991699542131119828136122844084167664213561413797197266932126567094592478049180527574610063804221136492408180752941912368053361033428722135099982224475378319426715648658197249952681761737715449837633886855244608192163828214065271939104800871155270500788187372118487210886344172616745904771391260565185514126983830511017524890055493342634696284132473205152841770963944089021300077971534798131177593329917900535686241198206618783739935697438688736034570662901859389467186414177947298091549539705571902740196893637319560668981482382827976723225596770623519771287184016495212387745219110318521547822573962182563151603720920971568361009145404184076926047809089716485862951823293409201288902812770359461465863330489525200193891431931194942513583988032484969612385524410750569352957950525733949491646959675117247778381978199981858854109397100397874882215016301417866523071102626275126517834518699123220648088386337319061366644209264705943270175196147553174275732412827280480160698170460918714686906109696858981496039859178064003518060105417445368201804495279125565798920403318732304065807551340161009600361238478017369928701104067006159113360210911393631890719314546276229208834060207771054646360141984256596666891319139007201411695834856816466361817645255117241076611618073341374770795493617728213149323372332700612677411616461063932038017819312693951420268628213228403141923282791899622332440662657710817649118661327391413702270627085675811070627079616503292917401641100085397710801047111759967607106774529632269307778206744517493919332140338333195447821176371561913676254803006122917477252042090952486427386407912335843263849016211172155185120823477077420225364483213039819700401826851941591197795168520277932399221686535390356189509366701538671945145643725919517906484712930091068921219872052296793986086185098866447396058178684077116579832271237676201698260319585955181985401405209793508923849827875025360121430045844967043393537442469137787867503491611484142441391779704152697650797888228112720892963016615121517917900755423181840333458826871511202733296616414281918957927307519016159581289051599297746122586219617449696771109797325316054749175195228092090919615397250717024037221159407474904226108191670418016090779071839600532460598410136629175840531128185237811416636056821819413410976983762196526719411898476621052526081165811700420167191739323753991822259823176502825616842770146329050811216842354762655563230391110179156032107871031219823433901100065228123268281915372634641119890542136908927130648399617210669611829025812176708240618576961365220732921471976873137381817019400305430147698711916017161383850716135400306870223507312530862421388948203770112488706308501823171834100991632920874732044383437491240307439119145588151705406210751671821219210816602253233464946998133119987059167851317714309959047831832732206771391029753614995671795293969715522978198881384198929702410169999661032931910225664092223519386173516698314787503343624142062112178231201897536381023939746109131418870934764461426743470426103268119935002041142601886148024349844826979016075488856639597201039948303123149623215687429041313168980475042337362549272108462949119056531620250687699502763256008163491051703111759404182836010204982003665072071046460152274628949497091046416841176201437505862850991734116056376215049405671112024415100658031950005880544478426514548501092107607690110874398634731476411916202745300032421660483744166666261256625816916214630457097442804438432904242557237698259141354360321160019614110534269341852560687210740324516994421611679719896690242382360761331605477851152001597213966398969629347704845567402557365671462993576929341005171058667614231176182038084991205790144046725424542060458515709015362133916857986862755104488093369617748914307060451469136656146600340363758271992184914937194668934265975888176874720713888515106317471550792985159981336211610959992332531015566212329315607211407882050181235779924707064918973940713754608271670188268803407511285878619213744251350094533670929650721238757221487808091175417744167256956377103048910758304492138572966140861320819976795993630360071751272966731964698286941210114421066135274035446922547830470171058599345200354377910146077383189977471668417931126167838850873715589639511078438300858907790634790082774341873109002324274408658975073394743034768635078038214233035101201378175142661083214143928284625077351276806783177742883566297053200877148120643700461807181192144045516363808945263765136105516121421986907612783728751374158961188828700739256761518828961166371984701176950623324490374671988552195129249614145136171416075141554542795184486130317668555241977846305898755830104598270812447554851361263565175305843874700672142756061836593676791587070160827873833155544115539601518720438741088316758137526509210029331013149920721116068451139550071650404540175326692142496769137489491527777182522877653917894085321693846967783319334148678618713132188436136819912380583692117179031858437476159932193438702374658565450187939890442361742213772415713401939944567729663851539396475422115450897251760419031106768732218600817977290038343157043911910486337334787108740672082137897604612558933969448622192730613615892225217527679561266608675147214109521896630015046670441683858998207740377695650533020708827445155746291835904235347016518189281620128614581803789485130486492933688022013955621890905523gkim@laptop:~/tcppl_exercise/X5$ 
gkim@laptop:~/tcppl_exercise/X5$ 
gkim@laptop:~/tcppl_exercise/X5$ g++ 9.cpp
gkim@laptop:~/tcppl_exercise/X5$ ./a.out
gkim@laptop:~/tcppl_exercise/X5$ cat intfile.txt 
250998439
234889465
1985393870
212270874
333426081
1738425220
1457850448
1466527543
2143182587
1385644841
1989281890
739225470
306177917
325185377
1295445314
1422762845
1341772872
1898646434
2000142697
674794611
1482795711
189658499
1705743593
1275606594
903148457
823256720
1872066838
1820573229
1148572651
1101238545
2128194793
1399571090
1336128010
1966105015
1611841964
1669554092
1557046587
922208765
988597987
1552745526
160369958
830396229
144487348
466547875
1155581606
1439932662
1889310720
349870830
1191095448
1741969769
1024665441
526407511
1931628269
582925386
1802014106
687293078
1406182106
1526597296
360382660
407271109
480352194
341093805
1806842200
1816480204
159715172
1271200516
1338550648
1716761759
45925633
179664987
1122023637
206295591
1010061216
1266510985
672843467
18159174
558959999
414670539
368030004
1750055448
9156661
1392695446
128979311
1940784930
1975620832
1930993417
480594360
1234319291
1310107066
840977020
1641590400
1790459260
1182070825
1300948952
1459455816
1341785997
424665821
650522817
911064108
470591454
830187804
2033087745
676887046
1840249021
1152115082
1349730513
1858408195
1711075082
1764401052
78954552
1313646882
1773557713
1471649998
1442626193
1566858995
1299787182
1226135963
2047453356
386622825
388759381
740946728
2028213226
31734993
1923017554
1181678530
1491190809
1117319903
1606344351
2141713626
2028384012
2076935806
824417783
1913988109
606339204
517183156
918619544
1956069717
228107703
482210978
1572987121
307062255
1795857860
1199061187
1778712253
1091000405
618436534
931015788
169652720
518406242
1317638613
558412101
1259352971
1198368191
590147094
1034886877
232563074
2081337904
4723132
1838907425
2075567882
2033107144
1768359583
752502017
1799611606
227215139
1269685173
570747502
35801208
1497792877
1052958480
1608788330
1804855132
701332692
660365869
1436083738
1792333097
1278802403
219615878
1961985818
1797208646
1537254491
372914271
909077969
588139035
963061366
1943964846
820702109
896915622
1948687978
512125886
824999856
1834311475
133001822
1577501874
1486439433
360216961
699703399
2057186935
396018170
50012628
962661767
2004806500
1854867761
1663994459
517688721
1143467851
1308843908
1796491124
1363083729
1123346078
1446216122
752854572
1496260350
207810443
1340993607
311838068
4291641
14212068
1208753690
1952979620
526337955
2033753546
1639807447
659339777
1463771772
978763232
1019556738
15991524
888466519
1415574908
66004152
1851128286
1272897760
1920871913
1367639097
1790586481
916856116
528999357
1439593958
132456197
1652345436
738326432
885310770
1001122138
946136876
78820729
1312960206
950428517
93032798
374230248
755924489
619370753
260500146
248248288
1278710530
1724271919
1227011520
150783620
1740263443
2115478039
1566358529
1806267595
1819122677
691772641
1579655861
1039278126
334875475
349028329
1568277484
1774469433
481484527
1073139272
365312217
1366795297
2074261410
1311449093
1445616026
1239737968
114393963
1538648824
1613968216
870318452
10535929
1874468362
1118566741
1289246459
1451256633
198094613
1440030080
1044036428
166089005
858904961
702820376
1985211682
1550677602
134992589
877006161
1885553077
484020918
297799997
1512538862
965505445
1370939269
1877851080
184817094
1297717031
1041816525
1630433121
389971351
1156210488
1021598297
2003939567
2026528941
1032134227
1730924281
997612034
173897038
1034697267
1195706647
1613927118
2078733695
1361795652
325348431
634070423
1199523687
1876026034
769063012
2076529848
1614095463
1253083931
226846197
979150678
71105728
1597785466
709518110
255922823
748018849
1751334635
1886355944
1137990200
760061476
760470593
994446119
639106769
1792604820
577886752
1636718803
1966501859
1612584019
684941802
1432945329
1543834067
2046737455
1758293761
30420842
1098777494
1486836147
799483855
1027823694
953447962
2052567786
1254669891
1932598640
2123673514
704971709
494633102
232112689
1452990558
98484090
2118468633
443497110
858545566
731455579
1437943229
1497652335
376576751
2015829981
986887490
195594962
1480930353
1671829292
1628540292
877280772
1571083099
1239350405
907701614
522376945
578702904
1707185469
1550200639
1532150866
1612269607
657386882
1317265859
1588459474
1362358591
1811898961
1820572163
667865501
1910383051
1791557149
1111362611
621444969
375529080
401822192
2119097304
752105831
270168526
958501146
947700794
1751098879
482846791
428757438
480896003
2053929890
1668107843
1388597617
428823188
99327099
948299439
1979023827
1631477965
413085398
488927062
801260176
2001544872
1851285653
465675490
1674633388
371667507
228574893
1318706889
1483030118
850019863
1694235969
1884852311
821633519
298858152
7537189
1780134666
1246558946
1758636068
115497809
1675316384
92048423
21944051
1195940579
1480646040
450767239
1295267678
281461831
282307419
779261996
694547230
771234481
1580522172
548608454
475036486
2046197662
75758194
846703993
127288908
1394465083
182250464
977308771
941217404
2067102775
1798942290
1240075557
2074639964
1431593308
339150855
1685792384
1547091117
2014467240
1777840807
1569035169
1062924171
1111003199
2019802408
210708202
1392465031
154626179
989970198
2087012261
925860660
423008722
488137067
1400897147
321722737
563895262
100117492
449011645
1958360345
282367956
1426320416
752094102
201987083
1077779058
1992169659
129143399
361888719
183836866
1814935783
1908979836
50820458
1445292942
1330531357
1113744630
408812494
1202850118
1324452832
1801277525
1357476297
166939382
1740806138
135853310
589948104
81459557
1536750457
911670841
645354819
1636867949
1360682486
456231517
1919235906
639519254
1208325619
2121222989
1717298313
1053011630
102882741
2079187032
1236848496
1917818524
1840683220
1287668955
1215627819
1023730930
253929937
1624440313
79097400
1578382769
1278234190
1436573697
1745322151
871556680
1572427007
187786607
953016237
961693816
1099457449
1598371057
451078118
312656287
2054602574
222830376
952175542
1115444545
196569717
521990207
20972527
299452458
453693591
1257821023
69787335
146893163
398006330
1285415154
1170624093
651936267
762371819
1249721493
82835388
2040606009
538811543
1828157539
764679041
2111238550
2015944147
1717695278
925448719
967917948
1168582687
1376526837
1280574235
1075701613
1599357213
85266129
43662510
1795926930
607256336
64635037
2095379389
1060949927
1322456061
17683076
1207843091
1720462391
1303098230
230983536
224915011
2065470049
1480705030
307750399
1958592410
2019516573
2135907939
575787803
1983271475
2004368438
145999433
761236546
824802738
1314582121
2137763383
2105376973
242800086
1589636948
43159455
286462597
1238080231
650415791
351097634
1185975972
1711365719
1673553695
1203659048
771725162
1246532439
359273630
1002708698
1471447450
277260031
335930080
1779197849
88368793
207963005
1767622140
664156596
43750833
1624506930
810156029
804987379
301826020
2124738150
795267115
259719346
220054589
237420415
302878801
506517186
1475500646
953294592
857614820
513992970
517176663
383684868
1717652018
1288901825
1630217307
2076925648
144126876
954181109
206702031
480056956
585895310
295070824
688019962
206033803
959227420
731770795
1830540733
1769383450
1536758174
2132366754
1746637952
184541641
244602452
1966692541
421962057
547481253
325726079
1897462703
1500775845
1183340900
263972026
2017952509
1567025768
1981624044
1159370686
1049759427
1911066045
1303497562
2003940536
2117768076
1783554519
442352198
265355253
324090833
648386001
1224582673
1055861628
331443087
846482475
445136154
316326193
445636780
629677796
560928645
264845673
1051639853
1108409898
590571753
801618908
461702095
1773912653
1065590934
332170956
1193454773
899731331
1491541643
95730552
663313728
647555557
2099671088
633598156
283626428
394539638
898953409
607717261
1042925640
2123536083
1663578889
1374368727
822534910
2108715044
1690694920
1268171690
590909192
104139917
1533017364
1642549045
1212549815
2123589117
296684305
1674251910
1750018122
1362275240
2006422867
795989247
114522923
1350480862
891719799
777836651
1998036419
843907239
1411434807
134179200
1238446877
162904569
741896461
133888869
138957004
257991703
1508257596
961491914
219223099
1051468868
82179957
810132291
1155608785
1615197321
305197688
220674952
1591302790
601881993
1894926863
1193837264
1964157233
1753866082
1989826511
2078680156
956863296
734062662
709033159
807416067
1577969901
2120467967
941595267
668933130
135888888
1683491729
802822000
274845892
1941483432
163595948
1236337806
13222883
1215064817
1318517763
823355174
223189954
786231436
1128552862
443864907
230050578
1730434855
191308122
1423887842
1547108441
1945174204
1266230705
1478304949
754553852
2000293367
39854461
1561969919
1430779620
12838780
356081539
2099712751
148727668
2039573268
755051103
423573560
1833573052
918647051
1659911366
1846795935
2133711868
830945482
522667461
209418175
1617176918
1651220323
653283082
1847227497
1234171530
844591204
1123631691
633796323
642281760
242378749
2112101273
1396835612
95188468
4472086
811321883
1525968089
17310866
1167403422
1478197192
166038534
1059493042
85764647
589612094
745582446
1004411698
102039812
444894733
990639919
932985294
967562194
1200058094
402678565
471298869
1853341176
102422414
1705470400
550448732
1226054105
191783075
1192730492
1468432854
156400700
442082456
1563621323
160872786
1253404339
942105764
178183652
273324114
272819308
344222186
1332817156
358583955
933834280
2078399603
1362995653
1035874093
375810688
206151924
1968859387
1343372883
1406210018
224054304
1814671752
1112067546
326476718
1372658504
1662516278
1552530824
1564441580
707763122
873480030
1720842280
1149845578
289617705
1881715067
255766270
1231723469
2059898719
529090384
1504542777
256637258
1861907540
1863126732
1190471538
1792823495
1078638738
78861983
21150536
1284790662
2047721371
1364523419
543517033
124292027
1031711523
1655584579
450768746
256886380
1170617210
2003299570
1821327960
1878380332
729295952
1394686592
880742263
1018913658
1128918011
1136508533
103153479
1041333083
1665598917
1607696257
1297970341
1380022809
1323339341
340958231
1025362657
254494431
419820215
1046513193
1539285094
320057938
263552964
2082802127
444349965
1295264487
1590903058
895118711
1552150867
614036620
750934633
1225995179
344933305
1480230586
473198124
1225675568
351660596
1602116135
214700453
454814075
495965570
1880299370
2062510332
1793935911
1112838531
1238366026
2134894143
2138201188
1492860457
407230710
1037230733
884661903
727288648
1300783697
819980382
1171638613
448564537
263399793
2066757325
2000715404
877436413
670208310
1079226936
1222369718
2955248
1552425060
gkim@laptop:~/tcppl_exercise/X5$ 