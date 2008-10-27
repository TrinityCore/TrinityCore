-- 
-- trinityscript_script_texts.sql Contains data for table `script_texts` mainly used in C++ parts.
-- valid entries for table are between -1000000 and -1999999
-- 

TRUNCATE `script_texts`;

-- 
-- -1 000 000 First 100 entries are reserved for special use, do not add regular text here.
-- 

INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1000000,'<TrinityScript Text Entry Missing!>',0,0,0,'DEFAULT_TEXT');

-- 
-- Normal text entries. Say/Yell/Whisper/Emote for any regular world object.
-- 

-- -1 000 100 GENERAL MAPS (not typical instance maps)

-- -1 033 000 SHADOWFANG KEEP

-- -1 034 000 STOCKADES

-- -1 036 000 DEADMINES

-- -1 043 000 WAILING CAVERNS

-- -1 047 000 RAZORFEN KRAUL

-- -1 048 000 BLACKFATHOM DEEPS

-- -1 070 000 ULDAMAN

-- -1 090 000 GNOMEREGAN

-- -1 109 000 SUNKEN TEMPLE

-- -1 129 000 RAZORFEN DOWNS

-- -1 189 000 SCARLET MONASTERY

-- -1 209 000 ZUL'FARRAK

-- -1 229 000 BLACKROCK SPIRE

-- -1 230 000 BLACKROCK DEPTHS

-- -1 249 000 ONYXIA'S LAIR

-- -1 269 000 OPENING OF THE DARK PORTAL (BLACK MORASS)
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1269000,'Why do you persist? Surely you can see the futility of it all. It is not too late! You may still leave with your lives ...',10442,1,0,'temporus SAY_ENTER'),
(-1269001,'So be it ... you have been warned.',10444,1,0,'temporus SAY_AGGRO'),
(-1269002,'Time... sands of time is run out for you.',10443,1,0,'temporus SAY_BANISH'),
(-1269003,'You should have left when you had the chance.',10445,1,0,'temporus SAY_SLAY1'),
(-1269004,'Your days are done.',10446,1,0,'temporus SAY_SLAY2'),
(-1269005,'My death means ... little.',10447,1,0,'temporus SAY_DEATH'),

(-1269006,'Why do you aid the Magus? Just think of how many lives could be saved if the portal is never opened, if the resulting wars could be erased ...',10412,1,0,'chrono_lord_deja SAY_ENTER'),
(-1269007,'If you will not cease this foolish quest, then you will die!',10414,1,0,'chrono_lord_deja SAY_AGGRO'),
(-1269008,'You have outstayed your welcome, Timekeeper. Begone!',10413,1,0,'chrono_lord_deja SAY_BANISH'),
(-1269009,'I told you it was a fool\'s quest!',10415,1,0,'chrono_lord_deja SAY_SLAY1'),
(-1269010,'Leaving so soon?',10416,1,0,'chrono_lord_deja SAY_SLAY2'),
(-1269011,'Time ... is on our side.',10417,1,0,'chrono_lord_deja SAY_DEATH'),

(-1269012,'The time has come to shatter this clockwork universe forever! Let us no longer be slaves of the hourglass! I warn you: those who do not embrace the greater path shall become victims of its passing!',10400,1,0,'aeonus SAY_ENTER'),
(-1269013,'Let us see what fate lays in store...',10402,1,0,'aeonus SAY_AGGRO'),
(-1269014,'Your time is up, slave of the past!',10401,1,0,'aeonus SAY_BANISH'),
(-1269015,'One less obstacle in our way!',10403,1,0,'aeonus SAY_SLAY1'),
(-1269016,'No one can stop us! No one!',10404,1,0,'aeonus SAY_SLAY2'),
(-1269017,'It is only a matter...of time.',10405,1,0,'aeonus SAY_DEATH');

-- -1 289 000 SCHOLOMANCE

-- -1 309 000 ZUL'GURUB

-- -1 329 000 STRATHOLME

-- -1 349 000 MARAUDON

-- -1 389 000 RAGEFIRE CHASM

-- -1 409 000 MOLTEN CORE

-- -1 429 000 DIRE MAUL

-- -1 469 000 BLACKWING LAIR
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1469000,'None of your kind should be here! You\'ve doomed only yourselves!',8286,1,0,'broodlord SAY_AGGRO'),
(-1469001,'Clever Mortals but I am not so easily lured away from my sanctum!',8287,1,0,'broodlord SAY_LEASH'),

(-1469002,'goes into a killing frenzy!',0,2,0,'chromaggus EMOTE_FRENZY'),
(-1469003,'flinches as its skin shimmers.',0,2,0,'chromaggus EMOTE_SHIMMER'),

(-1469004,'In this world where time is your enemy, it is my greatest ally. This grand game of life that you think you play in fact plays you. To that I say...',0,0,0,'victor_nefarius SAY_GAMESBEGIN_1'),
(-1469005,'Let the games begin!',8280,1,0,'victor_nefarius SAY_GAMESBEGIN_2'),
(-1469006,'Ah, the heroes. You are persistent, aren\'t you. Your allied attempted to match his power against mine, and had to pay the price. Now he shall serve me, by slaughtering you. Get up little red wyrm and destroy them!',8279,1,0,'victor_nefarius SAY_VAEL_INTRO'),

(-1469007,'Well done, my minions. The mortals\' courage begins to wane! Now, let\'s see how they contend with the true Lord of Blackrock Spire!',8288,1,0,'nefarian SAY_AGGRO'),
(-1469008,'Enough! Now you vermin shall feel the force of my birthright, the fury of the earth itself.',8289,1,0,'nefarian SAY_XHEALTH'),
(-1469009,'Burn, you wretches! Burn!',8290,1,0,'nefarian SAY_SHADOWFLAME'),
(-1469010,'Impossible! Rise my minions! Serve your master once more!',8291,1,0,'nefarian SAY_RAISE_SKELETONS'),
(-1469011,'Worthless $N! Your friends will join you soon enough!',8293,1,0,'nefarian SAY_SLAY'),
(-1469012,'This cannot be! I am the Master here! You mortals are nothing to my kind! DO YOU HEAR? NOTHING!',8292,1,0,'nefarian SAY_DEATH'),
(-1469013,'Mages too? You should be more careful when you play with magic...',0,1,0,'nefarian SAY_MAGE'),
(-1469014,'Warriors, I know you can hit harder than that! Let\'s see it!',0,1,0,'nefarian SAY_WARRIOR'),
(-1469015,'Druids and your silly shapeshifting. Let\'s see it in action!',0,1,0,'nefarian SAY_DRUID'),
(-1469016,'Priests! If you\'re going to keep healing like that, we might as well make it a little more interesting!',0,1,0,'nefarian SAY_PRIEST'),
(-1469017,'Paladins, I\'ve heard you have many lives. Show me.',0,1,0,'nefarian SAY_PALADIN'),
(-1469018,'Shamans, show me what your totems can do!',0,1,0,'nefarian SAY_SHAMAN'),
(-1469019,'Warlocks, you shouldn\'t be playing with magic you don\'t understand. See what happens?',0,1,0,'nefarian SAY_WARLOCK'),
(-1469020,'Hunters and your annoying pea-shooters!',0,1,0,'nefarian SAY_HUNTER'),
(-1469021,'Rogues? Stop hiding and face me!',0,1,0,'nefarian SAY_ROGUE'),

(-1469022,'You\'ll pay for forcing me to do this.',8275,1,0,'razorgore SAY_EGGS_BROKEN1'),
(-1469023,'Fools! These eggs are more precious than you know.',8276,1,0,'razorgore SAY_EGGS_BROKEN2'),
(-1469024,'No! Not another one! I\'ll have your heads for this atrocity.',8277,1,0,'razorgore SAY_EGGS_BROKEN3'),
(-1469025,'If I fall into the abyss I\'ll take all of you mortals with me...',8278,1,0,'razorgore SAY_DEATH'),

(-1469026,'Too late...friends. Nefarius\' corruption has taken hold. I cannot...control myself.',8281,1,0,'vaelastrasz SAY_LINE1'),
(-1469027,'I beg you Mortals, flee! Flee before I lose all control. The Black Fire rages within my heart. I must release it!',8282,1,0,'vaelastrasz SAY_LINE2'),
(-1469028,'FLAME! DEATH! DESTRUCTION! COWER MORTALS BEFORE THE WRATH OF LORD....NO! I MUST FIGHT THIS!',8283,1,0,'vaelastrasz SAY_LINE3'),
(-1469029,'Nefarius\' hate has made me stronger than ever before. You should have fled, while you could, mortals! The fury of Blackrock courses through my veins!',8285,1,0,'vaelastrasz SAY_HALFLIFE'),
(-1469030,'Forgive me $N, your death only adds to my failure.',8284,1,0,'vaelastrasz SAY_KILLTARGET');

-- -1 509 000 RUINS OF AHN'QIRAJ

-- -1 531 000 TEMPLE OF AHN'QIRAJ

-- -1 532 000 KARAZHAN

-- -1 533 000 NAXXRAMAS

-- -1 534 000 THE BATTLE OF MT. HYJAL

-- -1 540 000 SHATTERED HALLS

-- -1 542 000 BLOOD FURNACE

-- -1 543 000 HELLFIRE RAMPARTS

-- -1 544 000 MAGTHERIDON'S LAIR

-- -1 545 000 THE STEAMVAULT

-- -1 546 000 THE UNDERBOG

-- -1 547 000 THE SLAVE PENS

-- -1 548 000 SERPENTSHRINE CAVERN

-- -1 550 000 THE EYE

-- -1 552 000 THE ARCATRAZ

-- -1 553 000 THE BOTANICA

-- -1 554 000 THE MECHANAR

-- -1 555 000 SHADOW LABYRINTH
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1555000,'Infidels have invaded the sanctuary! Sniveling pests...You have yet to learn the true meaning of agony!',10473,1,0,'hellmaw SAY_INTRO'),
(-1555001,'Pathetic mortals! You will pay dearly!',10475,1,0,'hellmaw SAY_AGGRO1'),
(-1555002,'I will break you!',10476,1,0,'hellmaw SAY_AGGRO2'),
(-1555003,'Finally! Something to relieve the tedium!',10477,1,0,'hellmaw SAY_AGGRO3'),
(-1555004,'Aid me, you fools, before it\'s too late!',10474,1,0,'hellmaw SAY_HELP'),
(-1555005,'Do you fear death?',10478,1,0,'hellmaw SAY_SLAY1'),
(-1555006,'This is the part I enjoy most.',10479,1,0,'hellmaw SAY_SLAY2'),
(-1555007,'Do not...grow...overconfident, mortal.',10480,1,0,'hellmaw SAY_DEATH'),

(-1555008,'All flesh must burn.',10482,1,0,'blackhearth SAY_INTRO1'),
(-1555009,'All creation must be unmade!',10483,1,0,'blackhearth SAY_INTRO2'),
(-1555010,'Power will be yours!',10484,1,0,'blackhearth SAY_INTRO3'),
(-1555011,'You\'ll be sorry!',10486,1,0,'blackhearth SAY_AGGRO1'),
(-1555012,'Time for fun!',10487,1,0,'blackhearth SAY_AGGRO2'),
(-1555013,'I see dead people!',10488,1,0,'blackhearth SAY_AGGRO3'),
(-1555014,'No comin\' back for you!',10489,1,0,'blackhearth SAY_SLAY1'),
(-1555015,'Nice try!',10490,1,0,'blackhearth SAY_SLAY2'),
(-1555016,'Help us, hurry!',10485,1,0,'blackhearth SAY_HELP'),
(-1555017,'This... no... good...',10491,1,0,'blackhearth SAY_DEATH'),

(-1555018,'Be ready for Dark One\'s return.',10492,1,0,'blackhearth SAY2_INTRO1'),
(-1555019,'So we have place in new universe.',10493,1,0,'blackhearth SAY2_INTRO2'),
(-1555020,'Dark one promise!',10494,1,0,'blackhearth SAY2_INTRO3'),
(-1555021,'You\'ll be sorry!',10496,1,0,'blackhearth SAY2_AGGRO1'),
(-1555022,'Time to kill!',10497,1,0,'blackhearth SAY2_AGGRO2'),
(-1555023,'You be dead people!',10498,1,0,'blackhearth SAY2_AGGRO3'),
(-1555024,'Now you gone for good.',10499,1,0,'blackhearth SAY2_SLAY1'),
(-1555025,'You failed, haha haha',10500,1,0,'blackhearth SAY2_SLAY2'),
(-1555026,'Help us, hurry!',10495,1,0,'blackhearth SAY2_HELP'),
(-1555027,'Arrgh, aah...ahhh',10501,1,0,'blackhearth SAY2_DEATH'),

(-1555028,'Keep your minds focused for the days of reckoning are close at hand. Soon, the destroyer of worlds will return to make good on his promise. Soon the destruction of all that is will begin!',10522,1,0,'vorpil SAY_INTRO'),
(-1555029,'I\'ll make an offering of your blood!',10524,1,0,'vorpil SAY_AGGRO1'),
(-1555030,'You\'ll be a fine example, for the others.',10525,1,0,'vorpil SAY_AGGRO2'),
(-1555031,'Good, a worthy sacrifice.',10526,1,0,'vorpil SAY_AGGRO3'),
(-1555032,'Come to my aid, heed your master now!',10523,1,0,'vorpil SAY_HELP'),
(-1555033,'I serve with pride.',10527,1,0,'vorpil SAY_SLAY1'),
(-1555034,'Your death is for the greater cause!',10528,1,0,'vorpil SAY_SLAY2'),
(-1555035,'I give my life... Gladly.',10529,1,0,'vorpil SAY_DEATH'),

(-1555036,'draws energy from the air.',0,2,0,'murmur EMOTE_SONIC_BOOM');

-- -1 556 000 SETHEKK HALLS
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1556000,'I have pets..<squawk>..of my own!',10502,1,0,'syth SAY_SUMMON'),
(-1556001,'Hrrmm.. Time to.. hrrm.. make my move.',10503,1,0,'syth SAY_AGGRO_1'),
(-1556002,'Nice pets..hrm.. Yes! <squawking>',10504,1,0,'syth SAY_AGGRO_2'),
(-1556003,'Nice pets have.. weapons. No so..<squawk>..nice.',10505,1,0,'syth SAY_AGGRO_3'),
(-1556004,'Death.. meeting life is.. <squawking>',10506,1,0,'syth SAY_SLAY_1'),
(-1556005,'Uhn.. Be free..<squawk>',10507,1,0,'syth SAY_SLAY_2'),
(-1556006,'No more life..hrm. No more pain. <squawks weakly>',10508,1,0,'syth SAY_DEATH'),

(-1556007,'<squawk>..Trinkets yes pretty Trinkets..<squawk>..power, great power.<squawk>..power in Trinkets..<squawk>',10557,1,0,'ikiss SAY_INTRO'),
(-1556008,'You make war on Ikiss?..<squawk>',10554,1,0,'ikiss SAY_AGGRO_1'),
(-1556009,'Ikiss cut you pretty..<squawk>..slice you. Yes!',10555,1,0,'ikiss SAY_AGGRO_2'),
(-1556010,'No escape for..<squawk>..for you',10556,1,0,'ikiss SAY_AGGRO_3'),
(-1556011,'You die..<squawk>..stay away from Trinkets',10558,1,0,'ikiss SAY_SLAY_1'),
(-1556012,'<squawk>',10559,1,0,'ikiss SAY_SLAY_2'),
(-1556013,'Ikiss will not..<squawk>..die',10560,1,0,'ikiss SAY_DEATH'),
(-1556015,'begins to channel arcane energy...',0,3,0,'ikiss EMOTE_ARCANE_EXP');

-- -1 557 000 MANA TOMBS
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1557000,'What is this? You must forgive me, but I was not expecting company. As you can see, we are somewhat preoccupied right now. But no matter. As I am a gracious host, I will tend to you... personally.',10539,1,0,'shaffar SAY_INTRO'),
(-1557001,'We have not yet been properly introduced.',10541,1,0,'shaffar SAY_AGGRO_1'),
(-1557002,'An epic battle. How exciting!',10542,1,0,'shaffar SAY_AGGRO_2'),
(-1557003,'I have longed for a good adventure.',10543,1,0,'shaffar SAY_AGGRO_3'),
(-1557004,'It has been... entertaining.',10544,1,0,'shaffar SAY_SLAY_1'),
(-1557005,'And now we part company.',10545,1,0,'shaffar SAY_SLAY_2'),
(-1557006,'I have such fascinating things to show you.',10540,1,0,'shaffar SAY_SUMMON'),
(-1557007,'I must bid you... farewell.',10546,1,0,'shaffar SAY_DEAD'),

(-1557008,'I will feed on your soul.',10561,1,0,'pandemonius SAY_AGGRO_1'),
(-1557009,'So... full of life!',10562,1,0,'pandemonius SAY_AGGRO_2'),
(-1557010,'Do not... resist.',10563,1,0,'pandemonius SAY_AGGRO_3'),
(-1557011,'Yes! I am... empowered!',10564,1,0,'pandemonius SAY_KILL_1'),
(-1557012,'More... I must have more!',10565,1,0,'pandemonius SAY_KILL_2'),
(-1557013,'To the void... once... more..',10566,1,0,'pandemonius SAY_DEATH'),
(-1557014,'shifts into the void...',0,3,0,'pandemonius EMOTE_DARK_SHELL');

-- -1 558 000 AUCHENAI CRYPTS
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1558000,'You have defiled the resting place of our ancestors. For this offense, there can be but one punishment. It is fitting that you have come to a place of the dead... for you will soon be joining them.',10509,1,0,'maladaar SAY_INTRO'),
(-1558001,'Rise my fallen brothers. Take form and fight!',10512,1,0,'maladaar SAY_SUMMON'),
(-1558002,'You will pay with your life!',10513,1,0,'maladaar SAY_AGGRO_1'),
(-1558003,'There\'s no turning back now!',10514,1,0,'maladaar SAY_AGGRO_2'),
(-1558004,'Serve your penitence!',10515,1,0,'maladaar SAY_AGGRO_3'),
(-1558005,'Let your mind be clouded.',10510,1,0,'maladaar SAY_ROAR'),
(-1558006,'Stare into the darkness of your soul.',10511,1,0,'maladaar SAY_SOUL_CLEAVE'),
(-1558007,'These walls will be your doom.',10516,1,0,'maladaar SAY_SLAY_1'),
(-1558008,'<laugh> Now, you\'ll stay for eternity!',10517,1,0,'maladaar SAY_SLAY_2'),
(-1558009,'This is... where.. I belong...',10518,1,0,'maladaar SAY_DEATH');

-- -1 560 000 ESCAPE FROM DURNHOLDE (OLD HILLSBRAD)
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
(-1560000,'Thrall! You didn\'t really think you would escape did you? You and your allies shall answer to Blackmoore - after I\'ve had my fun!',10406,1,0,'skarloc SAY_ENTER'),
(-1560001,'You\'re a slave. That\'s all you\'ll ever be.',10407,1,0,'skarloc SAY_TAUNT1'),
(-1560002,'I don\'t know what Blackmoore sees in you. For my money, you\'re just another ignorant savage!',10408,1,0,'skarloc SAY_TAUNT2'),
(-1560003,'Thrall will never be free!',10409,1,0,'skarloc SAY_SLAY1'),
(-1560004,'Did you really think you would leave here alive?',10410,1,0,'skarloc SAY_SLAY2'),
(-1560005,'Guards! Urgh..Guards..!',10411,1,0,'skarloc SAY_DEATH'),

(-1560006,'You there, fetch water quickly! Get these flames out before they spread to the rest of the keep! Hurry, damn you!',10428,1,0,'lieutenant_drake SAY_ENTER'),
(-1560007,'I know what you\'re up to, and I mean to put an end to it, permanently!',10429,1,0,'lieutenant_drake SAY_AGGRO'),
(-1560008,'No more middling for you.',10432,1,0,'lieutenant_drake SAY_SLAY1'),
(-1560009,'You will not interfere!',10433,1,0,'lieutenant_drake SAY_SLAY2'),
(-1560010,'Time to bleed!',10430,1,0,'lieutenant_drake SAY_MORTAL'),
(-1560011,'Run, you blasted cowards!',10431,1,0,'lieutenant_drake SAY_SHOUT'),
(-1560012,'Thrall... must not... go free.',10434,1,0,'lieutenant_drake SAY_DEATH'),

(-1560013,'Thrall! Come outside and face your fate!',10418,1,0,'epoch SAY_ENTER1'),
(-1560014,'Taretha\'s life hangs in the balance. Surely you care for her. Surely you wish to save her...',10419,1,0,'epoch SAY_ENTER2'),
(-1560015,'Ah, there you are. I had hoped to accomplish this with a bit of subtlety, but I suppose direct confrontation was inevitable. Your future, Thrall, must not come to pass and so...you and your troublesome friends must die!',10420,1,0,'epoch SAY_ENTER3'),
(-1560016,'Enough! I will erase your very existence!',10421,1,0,'epoch SAY_AGGRO1'),
(-1560017,'You cannot fight fate!',10422,1,0,'epoch SAY_AGGRO2'),
(-1560018,'You are...irrelevant.',10425,1,0,'epoch SAY_SLAY1'),
(-1560019,'Thrall will remain a slave. Taretha will die. You have failed.',10426,1,0,'epoch SAY_SLAY2'),
(-1560020,'Not so fast!',10423,1,0,'epoch SAY_BREATH1'),
(-1560021,'Struggle as much as you like!',10424,1,0,'epoch SAY_BREATH2'),
(-1560022,'No!...The master... will not... be pleased.',10427,1,0,'epoch SAY_DEATH');

-- -1 564 000 BLACK TEMPLE

-- -1 565 000 GRUUL'S LAIR

-- -1 568 000 ZUL'AMAN

-- -1 580 000 SUNWELL PLATEAU

-- -1 585 000 MAGISTER'S TERRACE


-- 
-- Below just for beautiful view in table, run at own desire
-- 

-- ALTER TABLE `script_texts` ORDER BY `entry` desc;
