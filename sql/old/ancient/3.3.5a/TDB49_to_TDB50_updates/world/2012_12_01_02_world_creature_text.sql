-- ------------------------------- --
-- Creature text conversion part 4 --
-- ------------------------------- --

-- kodo round
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000350 AND -1000348;
DELETE FROM `creature_text` WHERE `entry`=11596;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11596,0,0,12,0,100,"kodo round SAY_SMEED_HOME_1","Ah...the wondrous sound of kodos. I love the way they make the ground shake... inspect the beast for me."),
(11596,0,1,12,0,100,"kodo round SAY_SMEED_HOME_2","Hey, look out with that kodo! You had better inspect that beast before I give you credit!"),
(11596,0,2,12,0,100,"kodo round SAY_SMEED_HOME_3","That kodo sure is a beauty. Wait a minute, where are my bifocals? Perhaps you should inspect the beast for me.");

-- lazy peon
DELETE FROM `script_texts` WHERE `entry`=-1000600;
DELETE FROM `creature_text` WHERE `entry`=10556;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(10556,0,0,12,0,100,"lazy peon SAY_WP_0","Ow! OK, I'll get back to work, $N!");

-- amnennar
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1129004 AND -1129000;
DELETE FROM `creature_text` WHERE `entry`=7358;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(7358,0,0,14,5825,100,"amnennar SAY_AGGRO","You'll never leave this place... alive."),
(7358,1,0,14,5828,100,"amnennar SAY_SUMMON60","To me, my servants!"),
(7358,2,0,14,5829,100,"amnennar SAY_SUMMON30","Come, spirits, attend your master!"),
(7358,3,0,14,5827,100,"amnennar SAY_HP","I am the hand of the Lich King!"),
(7358,4,0,14,5826,100,"amnennar SAY_KILL","Too...easy!");

-- clintar
DELETE FROM `script_texts` WHERE `entry`=-1000286;
DELETE FROM `creature_text` WHERE `entry`=22916;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(22916,0,0,12,0,100,"clintar SAY_END","Lurosa, I am entrusting the Relics of Aviana to $N, who will take them to Morthis Whisperwing. I must return completely to the Emerald Dream now. Do not let $N fail!");

-- gilthares
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000380 AND -1000370;
DELETE FROM `creature_text` WHERE `entry`=3465;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(3465,0,0,12,0,100,"gilthares SAY_GIL_START","Stay close, $n. I'll need all the help I can get to break out of here. Let's go!"),
(3465,1,0,12,0,100,"gilthares SAY_GIL_AT_LAST","At last! Free from Northwatch Hold! I need a moment to catch my breath..."),
(3465,2,0,12,0,100,"gilthares SAY_GIL_PROCEED","Now I feel better. Let's get back to Ratchet. Come on, $n."),
(3465,3,0,12,0,100,"gilthares SAY_GIL_FREEBOOTERS","Looks like the Southsea Freeboters are heavily entrenched on the coast. This could get rough."),
(3465,4,0,12,0,100,"gilthares SAY_GIL_AGGRO_1","Help! $C attacking!"),
(3465,4,1,12,0,100,"gilthares SAY_GIL_AGGRO_2","$C heading this way fast! Time for revenge!"),
(3465,4,2,12,0,100,"gilthares SAY_GIL_AGGRO_3","$C coming right at us!"),
(3465,4,3,12,0,100,"gilthares SAY_GIL_AGGRO_4","Get this $C off of me!"),
(3465,5,0,12,0,100,"gilthares SAY_GIL_ALMOST","Almost back to Ratchet! Let's keep up the pace..."),
(3465,6,0,12,0,100,"gilthares SAY_GIL_SWEET","Ah, the sweet salt air of Ratchet."),
(3465,7,0,12,0,100,"gilthares SAY_GIL_FREED","Captain Brightsun, $N here has freed me! $N, I am certain the Captain will reward your bravery.");

-- twiggy
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000380 AND -1000370;
DELETE FROM `creature_text` WHERE `entry` IN (6238,6248);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(6238,0,0,12,0,100,"big will SAY_BIG_WILL_READY","Ready when you are, $c."),
(6248,0,0,12,0,100,"twiggy SAY_TWIGGY_BEGIN","The Affray has begun. $n, get ready to fight!"),
(6248,1,0,12,0,100,"twiggy SAY_TWIGGY_FRAY","You! Enter the fray!"),
(6248,2,0,12,0,100,"twiggy SAY_TWIGGY_DOWN","Challenger is down!"),
(6248,3,0,12,0,100,"twiggy SAY_TWIGGY_OVER","The Affray is over.");

-- wizzlecrank
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000305 AND -1000298;
DELETE FROM `creature_text` WHERE `entry` IN (3282,3439);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(3439,0,0,12,0,100,"wizzlecrank SAY_START","Alright, alright I think I can figure out how to operate this thing..."),
(3439,1,0,12,0,100,"wizzlecrank SAY_STARTUP1","Arrrgh! This isn't right!"),
(3439,2,0,12,0,100,"wizzlecrank SAY_STARTUP2","Okay, I think I've got it, now. Follow me, $n!"),
(3282,0,0,14,0,100,"wizzlecrank SAY_MERCENARY","There's the stolen shredder! Stop it or Lugwizzle will have our hides!"),
(3439,3,0,12,0,100,"wizzlecrank SAY_PROGRESS_1","Looks like we're out of woods, eh? Wonder what this does..."),
(3439,4,0,12,0,100,"wizzlecrank SAY_PROGRESS_2","Come on, don't break down on me now!"),
(3439,5,0,12,0,100,"wizzlecrank SAY_PROGRESS_3","That was a close one! Well, let's get going, it's still a ways to Ratchet!"),
(3439,6,0,12,0,100,"wizzlecrank SAY_END","Hmm... I don't think this blinking red light is a good thing...");

-- muglash
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1800063 AND -1800054;
DELETE FROM `creature_text` WHERE `entry`=12717;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(12717,0,0,12,0,100,"muglash SAY_MUG_START1","Are you sure that you are ready? If we do not have a group of your allies to aid us, we will surely fail."),
(12717,1,0,12,0,100,"muglash SAY_MUG_START2","This will be a though fight, $N. Follow me closely."),
(12717,2,0,12,0,100,"muglash SAY_MUG_BRAZIER","This is the brazier, $N. Put it out. Vorsha is a beast, worthy of praise from no one!"),
(12717,3,0,12,0,100,"muglash SAY_MUG_BRAZIER_WAIT","Now we must wait. It won't be long before the naga realize what we have done."),
(12717,4,0,12,0,100,"muglash SAY_MUG_ON_GUARD","Be on your guard, $N!"),
(12717,5,0,12,0,100,"muglash SAY_MUG_REST","Perhaps we will get a moment to rest. But I will not give up until we have faced off against Vorsha!"),
(12717,6,0,12,0,100,"muglash SAY_MUG_DONE","We have done it!"),
(12717,7,0,12,0,100,"muglash SAY_MUG_GRATITUDE","You have my deepest gratitude. I thank you."),
(12717,8,0,12,0,100,"muglash SAY_MUG_PATROL","I am going to patrol the area for a while longer and ensure that things are truly safe."),
(12717,9,0,12,0,100,"muglash SAY_MUG_RETURN","Please return to Zoram'gar and report our success to the Warsong runner.");

-- jaina hyjal
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1534008 AND -1534000;
DELETE FROM `creature_text` WHERE `entry`=17772;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17772,0,0,14,11007,100,"jaina hyjal ATTACKED 1","I'm in jeopardy, help me if you can!"),
(17772,0,1,14,11049,100,"jaina hyjal ATTACKED 2","They've broken through!"),
(17772,1,0,14,11006,100,"jaina hyjal BEGIN","Don't give up! We must prevail!"),
(17772,2,0,14,11008,100,"jaina hyjal INCOMING","Stay alert! Another wave approaches."),
(17772,3,0,14,11050,100,"jaina hyjal RALLY 1","Hold them back as long as possible."),
(17772,3,1,14,11051,100,"jaina hyjal RALLY 2","We must hold strong!"),
(17772,4,0,14,11009,100,"jaina hyjal FAILURE","We are lost. Fall back!"),
(17772,5,0,14,11011,100,"jaina hyjal SUCCESS","We have won valuable time. Now we must pull back!"),
(17772,6,0,14,11010,100,"jaina hyjal DEATH","I did... my best.");

-- thrall hyjal
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1534017 AND -1534009;
DELETE FROM `creature_text` WHERE `entry`=17852;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17852,0,0,14,11031,100,"thrall hyjal ATTACKED 1","I will lie down for no one!"),
(17852,0,1,14,11061,100,"thrall hyjal ATTACKED 2","Bring the fight to me and pay with your lives!"),
(17852,1,0,14,11030,100,"thrall hyjal BEGIN","Hold them back! Do not falter!"),
(17852,2,0,14,11032,100,"thrall hyjal INCOMING","Make ready for another wave! LOK-TAR OGAR!"),
(17852,3,0,14,11059,100,"thrall hyjal RALLY 1","Victory or death!"),
(17852,3,1,14,11060,100,"thrall hyjal RALLY 2","Do not give an inch of ground!"),
(17852,4,0,14,11033,100,"thrall hyjal FAILURE","It is over. Withdraw! We have failed."),
(17852,5,0,14,11035,100,"thrall hyjal SUCCESS","We have played our part and done well. It is up to the others now."),
(17852,6,0,14,11034,100,"thrall hyjal DEATH","Uraaa...");

-- lieutenant drake
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1560012 AND -1560006;
DELETE FROM `creature_text` WHERE `entry`=17848;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17848,0,0,14,10428,100,"lieutenant drake SAY_ENTER","You there, fetch water quickly! Get these flames out before they spread to the rest of the keep! Hurry, damn you!"),
(17848,1,0,14,10429,100,"lieutenant drake SAY_AGGRO","I know what you're up to, and I mean to put an end to it, permanently!"),
(17848,2,0,14,10432,100,"lieutenant drake SAY_SLAY1","No more middling for you."),
(17848,2,1,14,10433,100,"lieutenant drake SAY_SLAY2","You will not interfere!"),
(17848,3,0,14,10430,100,"lieutenant drake SAY_MORTAL","Time to bleed!"),
(17848,4,0,14,10431,100,"lieutenant drake SAY_SHOUT","Run, you blasted cowards!"),
(17848,5,0,14,10434,100,"lieutenant drake SAY_DEATH","Thrall... must not... go free.");

-- thrall hillsbrad
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1560049 AND -1560023;
DELETE FROM `creature_text` WHERE `entry` IN (17876,18887);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17876,0,0,14,10465,100,"thrall hillsbrad SAY_TH_START_EVENT_PART1","Very well then. Let's go!"),
(17876,1,0,12,0,100,"thrall hillsbrad SAY_TH_ARMORY","As long as we're going with a new plan, I may aswell pick up a weapon and some armor."),
(17876,2,0,12,10466,100,"thrall hillsbrad SAY_TH_SKARLOC_MEET","A rider approaches!"),
(17876,3,0,14,10467,100,"thrall hillsbrad SAY_TH_SKARLOC_TAUNT","I'll never be chained again!"),
(17876,4,0,14,10468,100,"thrall hillsbrad SAY_TH_START_EVENT_PART2","Very well. Tarren Mill lies just west of here. Since time is of the essence..."),
(17876,5,0,12,10469,100,"thrall hillsbrad SAY_TH_MOUNTS_UP","Let's ride!"),
(17876,6,0,12,0,100,"thrall hillsbrad SAY_TH_CHURCH_END","Taretha must be in the inn. Let's go."),
(17876,7,0,12,0,100,"thrall hillsbrad SAY_TH_MEET_TARETHA","Taretha! What foul magic is this?"),
(17876,8,0,14,10470,100,"thrall hillsbrad SAY_TH_EPOCH_WONDER","Who or what was that?"),
(17876,9,0,14,10471,100,"thrall hillsbrad SAY_TH_EPOCH_KILL_TARETHA","No!"),
(17876,10,0,14,10472,100,"thrall hillsbrad SAY_TH_EVENT_COMPLETE","Goodbye, Taretha. I will never forget your kindness."),
(17876,11,0,14,10458,100,"thrall hillsbrad SAY_TH_RANDOM_LOW_HP1","Things are looking grim..."),
(17876,11,1,14,10459,100,"thrall hillsbrad SAY_TH_RANDOM_LOW_HP2","I will fight to the last!"),
(17876,12,0,14,10460,100,"thrall hillsbrad SAY_TH_RANDOM_DIE1","Taretha..."),
(17876,12,1,14,10461,100,"thrall hillsbrad SAY_TH_RANDOM_DIE2","A good day...to die..."),
(17876,13,0,14,10448,100,"thrall hillsbrad SAY_TH_RANDOM_AGGRO1","I have earned my freedom!"),
(17876,13,1,14,10449,100,"thrall hillsbrad SAY_TH_RANDOM_AGGRO2","This day is long overdue. Out of my way!"),
(17876,13,2,14,10450,100,"thrall hillsbrad SAY_TH_RANDOM_AGGRO3","I am a slave no longer!"),
(17876,13,3,14,10451,100,"thrall hillsbrad SAY_TH_RANDOM_AGGRO4","Blackmoore has much to answer for!"),
(17876,14,0,14,10452,100,"thrall hillsbrad SAY_TH_RANDOM_KILL1","You have forced my hand!"),
(17876,14,1,14,10453,100,"thrall hillsbrad SAY_TH_RANDOM_KILL2","It should not have come to this!"),
(17876,14,2,14,10454,100,"thrall hillsbrad SAY_TH_RANDOM_KILL3","I did not ask for this!"),
(17876,15,0,14,10455,100,"thrall hillsbrad SAY_TH_LEAVE_COMBAT1","I am truly in your debt, strangers."),
(17876,15,1,14,10456,100,"thrall hillsbrad SAY_TH_LEAVE_COMBAT2","Thank you, strangers. You have given me hope."),
(17876,15,2,14,10457,100,"thrall hillsbrad SAY_TH_LEAVE_COMBAT3","I will not waste this chance. I will seek out my destiny."),
(18887,0,0,12,0,100,"taretha SAY_TA_FREE","I'm free! Thank you all!"),
(18887,1,0,12,0,100,"taretha SAY_TA_ESCAPED","Thrall, you escaped!");

-- skarloc
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1560005 AND -1560000;
DELETE FROM `creature_text` WHERE `entry`=17862;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17862,0,0,14,10406,100,"skarloc SAY_ENTER","Thrall! You didn't really think you would escape did you? You and your allies shall answer to Blackmoore - after I've had my fun!"),
(17862,1,0,14,10407,100,"skarloc SAY_TAUNT1","You're a slave. That's all you'll ever be."),
(17862,2,0,14,10408,100,"skarloc SAY_TAUNT2","I don't know what Blackmoore sees in you. For my money, you're just another ignorant savage!"),
(17862,3,0,14,10409,100,"skarloc SAY_SLAY1","Thrall will never be free!"),
(17862,3,1,14,10410,100,"skarloc SAY_SLAY2","Did you really think you would leave here alive?"),
(17862,4,0,14,10411,100,"skarloc SAY_DEATH","Guards! Urgh..Guards..!");

-- epoch hunter
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1560022 AND -1560013;
DELETE FROM `creature_text` WHERE `entry`=18096;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18096,0,0,14,10418,100,"epoch hunter SAY_ENTER1","Thrall! Come outside and face your fate!"),
(18096,0,1,14,10419,100,"epoch hunter SAY_ENTER2","Taretha's life hangs in the balance. Surely you care for her. Surely you wish to save her..."),
(18096,0,2,14,10420,100,"epoch hunter SAY_ENTER3","Ah, there you are. I had hoped to accomplish this with a bit of subtlety, but I suppose direct confrontation was inevitable. Your future, Thrall, must not come to pass and so...you and your troublesome friends must die!"),
(18096,1,0,14,10421,100,"epoch hunter SAY_AGGRO1","Enough! I will erase your very existence!"),
(18096,1,1,14,10422,100,"epoch hunter SAY_AGGRO2","You cannot fight fate!"),
(18096,2,0,14,10425,100,"epoch hunter SAY_SLAY1","You are...irrelevant."),
(18096,2,1,14,10426,100,"epoch hunter SAY_SLAY2","Thrall will remain a slave. Taretha will die. You have failed."),
(18096,3,0,14,10423,100,"epoch hunter SAY_BREATH1","Not so fast!"),
(18096,3,1,14,10424,100,"epoch hunter SAY_BREATH2","Struggle as much as you like!"),
(18096,4,0,14,10427,100,"epoch hunter SAY_DEATH","No!...The master... will not... be pleased.");

-- meathook
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1595031 AND -1595026;
DELETE FROM `creature_text` WHERE `entry`=26529;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26529,0,0,14,13428,100,"meathook SAY_AGGRO","Play time!"),
(26529,1,0,14,13430,100,"meathook SAY_SLAY_1","Boring..."),
(26529,1,1,14,13431,100,"meathook SAY_SLAY_2","Why you stop moving?"),
(26529,1,2,14,13432,100,"meathook SAY_SLAY_3","Get up! Me not done!"),
(26529,2,0,14,13429,100,"meathook SAY_SPAWN","New toys!"),
(26529,3,0,14,13433,100,"meathook SAY_DEATH","This... not fun...");

-- epoch
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1595008 AND -1595000;
DELETE FROM `creature_text` WHERE `entry`=26532;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26532,0,0,14,13408,100,"epoch SAY_INTRO | culling SAY_PHASE314","Prince Arthas Menethil, on this day, a powerful darkness has taken hold of your soul. The death you are destined to visit upon others will this day be your own."),
(26532,1,0,14,13409,100,"epoch SAY_AGGRO","We'll see about that, young prince."),
(26532,2,0,14,13410,100,"epoch SAY_TIME_WARP_1","Tick tock, tick tock..."),
(26532,2,1,14,13411,100,"epoch SAY_TIME_WARP_2","Not quick enough!"),
(26532,2,2,14,13412,100,"epoch SAY_TIME_WARP_3","Let's get this over with. "),
(26532,3,0,14,13413,100,"epoch SAY_SLAY_1","There is no future for you."),
(26532,3,1,14,13414,100,"epoch SAY_SLAY_2","This is the hour of our greatest triumph!"),
(26532,3,2,14,13415,100,"epoch SAY_SLAY_3","You were destined to fail."),
(26532,4,0,12,13416,100,"epoch SAY_DEATH","");

-- salramm
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1595044 AND -1595032;
DELETE FROM `creature_text` WHERE `entry`=26530;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26530,0,0,14,13472,100,"salramm SAY_AGGRO","Ah, the entertainment has arrived!"),
(26530,1,0,14,13471,100,"salramm SAY_SPAWN","You are too late, champion of Lordaeron. The dead shall have their day."),
(26530,2,0,14,13473,100,"salramm SAY_SLAY_1","The fun is just beginning!"),
(26530,2,1,14,13474,100,"salramm SAY_SLAY_2","Aah, quality materials!"),
(26530,2,2,14,13475,100,"salramm SAY_SLAY_3","Don't worry, I'll make good use of you."),
(26530,3,0,14,13483,100,"salramm SAY_DEATH","You only advance... the master's plan..."),
(26530,4,0,14,13478,100,"salramm SAY_EXPLODE_GHOUL_1","BOOM! Hahahahah..."),
(26530,4,1,14,13479,100,"salramm SAY_EXPLODE_GHOUL_2","Blood... destruction... EXHILARATING!"),
(26530,5,0,14,13480,100,"salramm SAY_STEAL_FLESH_1","I want a sample..."),
(26530,5,1,14,13481,100,"salramm SAY_STEAL_FLESH_2","Such strength... it must be mine!"),
(26530,5,2,14,13482,100,"salramm SAY_STEAL_FLESH_3","Your flesh betrays you."),
(26530,6,0,14,13476,100,"salramm SAY_SUMMON_GHOULS_1","Say hello to some friends of mine."),
(26530,6,1,14,13477,100,"salramm SAY_SUMMON_GHOULS_2","Come, citizen of Stratholme! Meet your saviors.");

-- culling of stratholme
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1595120 AND -1595070;
DELETE FROM `creature_text` WHERE `entry` IN (26499,26528,31126,28169,28167,26497);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
-- 26499
(26499,0,0,12,12828,100,"culling SAY_PHASE101","Glad you could make it, Uther."),
(26499,1,0,12,12829,100,"culling SAY_PHASE103","As if I could forget. Listen, Uther, there's something about the plague you should know..."),
(26499,2,0,12,12830,100,"culling SAY_PHASE104","Oh, no. We're too late. These people have all been infected! They may look fine now, but it's just a matter of time before they turn into the undead!"),
(26499,3,0,12,12831,100,"culling SAY_PHASE106","This entire city must be purged."),
(26499,4,0,12,12832,100,"culling SAY_PHASE108","Damn it, Uther! As your future king, I order you to purge this city!"),
(26499,5,0,12,12833,100,"culling SAY_PHASE110","Then I must consider this an act of treason."),
(26499,6,0,12,12834,100,"culling SAY_PHASE112","Have I? Lord Uther, by my right of succession and the sovereignty of my crown, I hereby relieve you of your command and suspend your paladins from service."),
(26499,7,0,12,12835,100,"culling SAY_PHASE114","It's done! Those of you who have the will to save this land, follow me! The rest of you... get out of my sight!"),
(26499,8,0,12,12836,100,"culling SAY_PHASE116","Jaina?"),
(26499,9,0,14,14327,100,"culling SAY_PHASE118","Take position here, and I will lead a small force inside Stratholme to begin the culling. We must contain and purge the infected for the sake of all of Lordaeron!"),
(26499,10,0,12,14293,100,"culling SAY_PHASE201","Everyone looks ready. Remember, these people are all infected with the plague and will die soon. We must purge Stratholme to protect the remainder of Lordaeron from the Scourge. Let's go."),
(26499,11,0,12,14294,100,"culling SAY_PHASE203","I can only help you with a clean death."),
(26499,12,0,12,14295,100,"culling SAY_PHASE205","That was just the beginning."),
(26499,13,0,14,14296,100,"culling SAY_PHASE208","I won't allow it, Mal'Ganis! Better that these people die by my hand than serve as your slaves in death!"),
(26499,14,0,14,14885,100,"culling SAY_PHASE209","Mal'ganis will send out some of his Scourge minions to interfere with us. Those of you with the strongest steel and magic shall go forth and destroy them. I will lead the rest of my forces in purging Stratholme of the infected."),
(26499,15,0,14,14297,100,"culling SAY_PHASE210","Champions, meet me at the Town Hall at once. We must take the fight to Mal'Ganis."),
(26499,16,0,12,14298,100,"culling SAY_PHASE301","Follow me, I know the way through."),
(26499,17,0,12,14299,100,"culling SAY_PHASE303","Yes, I'm glad I could get to you before the plague."),
(26499,18,0,12,14300,100,"culling SAY_PHASE304","What is this sorcery?"),
(26499,19,0,12,14301,100,"culling SAY_PHASE306. NEEDS VERIFICATION","Mal'Ganis appears to have more than scourge in his arsenal. We should make haste."),
(26499,20,0,12,14302,100,"culling SAY_PHASE307","More vile sorcery! Be ready for anything!"),
(26499,21,0,12,14303,100,"culling SAY_PHASE308","Let's move on."),
(26499,22,0,12,14304,100,"culling SAY_PHASE309","Watch your backs: they have us surrounded in this hall."),
(26499,23,0,12,0,100,"culling SAY_PHASE310. NEEDS VERIFICATION","One less obstacle to deal with."),
(26499,24,0,12,14305,100,"culling SAY_PHASE311","Mal'Ganis is not making this easy."),
(26499,25,0,12,14306,100,"culling SAY_PHASE312","They're very persistent."),
(26499,26,0,12,14307,100,"culling SAY_PHASE313","What else can he put in my way?"),
(26499,27,0,12,14309,100,"culling SAY_PHASE315","I do what I must for Lordaeron, and neither your words nor your actions will stop me."),
(26499,28,0,12,14308,100,"culling SAY_PHASE401","The quickest path to Mal'Ganis lies behind that bookshelf ahead."),
(26499,29,0,12,14310,100,"culling SAY_PHASE402","This will only take a moment."),
(26499,30,0,12,14311,100,"culling SAY_PHASE403","I'm relieved this secret passage still works."),
(26499,31,0,12,14312,100,"culling SAY_PHASE404","Let's move through here as quickly as possible. If the undead don't kill us, the fires might."),
(26499,32,0,12,14313,100,"culling SAY_PHASE405","Rest a moment and clear your lungs, but we must move again soon."),
(26499,33,0,12,14314,100,"culling SAY_PHASE406","That's enough; we must move again. Mal'Ganis awaits."),
(26499,34,0,12,14315,100,"culling SAY_PHASE407","At last some good luck. Market Row has not caught fire yet. Mal'Ganis is supposed to be in Crusaders' Square, which is just ahead. Tell me when you're ready to move forward."),
(26499,35,0,12,14316,100,"culling SAY_PHASE501","Justice will be done."),
(26499,36,0,12,14317,100,"culling SAY_PHASE502","We're going to finish this right now, Mal'Ganis. Just you... and me."),
(26499,37,0,12,14318,100,"culling SAY_PHASE503","I'll hunt you to the ends of the earth if I have to! Do you hear me? To the ends of the earth!"),
(26499,38,0,12,14319,100,"culling SAY_PHASE504","You performed well this day. Anything that Mal'Ganis has left behind is yours. Take it as your reward. I must now begin plans for an expedition to Northrend."),
-- 26528
(26528,0,0,12,12839,100,"culling SAY_PHASE102","Watch your tone with me, boy. You may be the prince, but I'm still your superior as a paladin!"),
(26528,1,0,12,12840,100,"culling SAY_PHASE105","What?"),
(26528,2,0,12,12841,100,"culling SAY_PHASE107","How can you even consider that? There's got to be some other way."),
(26528,3,0,12,12842,100,"culling SAY_PHASE109","You are not my king yet, boy! Nor would I obey that command even if you were!"),
(26528,4,0,12,12843,100,"culling SAY_PHASE111","Treason? Have you lost your mind, Arthas?"),
(26528,5,0,12,12844,100,"culling SAY_PHASE115","You've just crossed a terrible threshold, Arthas."),
-- 26497
(26497,0,0,12,12837,100,"culling SAY_PHASE113","Arthas! You can't just--"),
(26497,1,0,12,12838,100,"culling SAY_PHASE117","I'm sorry, Arthas. I can't watch you do this."),
-- 28167
(28167,0,0,12,0,100,"culling SAY_PHASE202","Prince Arthas, may the light be praised! Many people in the town have begun to fall seriously ill, can you help us?"),
-- 28169
(28169,0,0,12,0,100,"culling SAY_PHASE204","What? This can't be!"),
-- 31126
(31126,0,0,12,0,100,"culling SAY_PHASE302","Ah, you've finally arrived Prince Arthas. You're here just in the nick of time."),
(31126,1,0,12,0,100,"culling SAY_PHASE305","There's no need for you to understand, Arthas. All you need to do is die.");

-- malganis
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1595025 AND -1595009;
DELETE FROM `creature_text` WHERE `entry`=26533;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26533,0,0,14,14410,100,"malganis SAY_INTRO_1 | culling SAY_PHASE206","Yes, this is the beginning. I've been waiting for you, young prince. I am Mal'Ganis."),
(26533,1,0,14,14411,100,"malganis SAY_INTRO_2 | culling SAY_PHASE207","As you can see, your people are now mine. I will now turn this city household by household, until the flame of life has been snuffed out... forever."),
(26533,2,0,14,14413,100,"malganis SAY_AGGRO","This will be a fine test...Prince Arthas..."),
(26533,3,0,14,14416,100,"malganis SAY_KILL_1","All too easy..."),
(26533,3,1,14,14417,100,"malganis SAY_KILL_2","The dark lord is displeased with your interference..."),
(26533,3,2,14,14418,100,"malganis SAY_KILL_3","It is Prince Arthas I want... not you..."),
(26533,4,0,14,14422,100,"malganis SAY_SLAY_1","Anak'Keri..."),
(26533,4,1,14,14423,100,"malganis SAY_SLAY_2","My onslaught will wash over the Lich King's forces..."),
(26533,4,2,14,14424,100,"malganis SAY_SLAY_3","Your death is in vain, tiny mortal..."),
(26533,4,3,14,14425,100,"malganis SAY_SLAY_4","Your time has come to an end!"),
(26533,5,0,14,14414,100,"malganis SAY_SLEEP_1","Time out..."),
(26533,5,1,14,14415,100,"malganis SAY_SLEEP_2","You seem...tired..."),
(26533,6,0,14,14426,100,"malganis SAY_30HEALTH","I spent too much time in that weak little shell..."),
(26533,7,0,14,14427,100,"malganis SAY_15HEALTH","(Eredun) I AM MAL'GANIS! I AM ETERNAL!"),
(26533,8,0,14,14428,100,"malganis SAY_ESCAPE_SPEECH_1","ENOUGH! I waste my time here...I must gather my strength on the home world..."),
(26533,9,0,14,14429,100,"malganis SAY_ESCAPE_SPEECH_2","You'll never defeat the Lich King without my forces! I'll have my revenge...on him, AND you..."),
(26533,10,0,14,14412,100,"malganis SAY_OUTRO","Your journey has just begun, young prince. Gather your forces and meet me in the artic land of Northrend. It is there that we shall settle the score between us. It is there that your true destiny will unfold.");

-- chrono lord deja
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1269011 AND -1269006;
DELETE FROM `creature_text` WHERE `entry`=17879;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17879,0,0,14,10412,100,"chrono lord deja SAY_ENTER","Why do you aid the Magus? Just think of how many lives could be saved if the portal is never opened, if the resulting wars could be erased ..."),
(17879,1,0,14,10414,100,"chrono lord deja SAY_AGGRO","If you will not cease this foolish quest, then you will die!"),
(17879,2,0,14,10413,100,"chrono lord deja SAY_BANISH","You have outstayed your welcome, Timekeeper. Begone!"),
(17879,3,0,14,10415,100,"chrono lord deja SAY_SLAY1","I told you it was a fool's quest!"),
(17879,3,1,14,10416,100,"chrono lord deja SAY_SLAY2","Leaving so soon?"),
(17879,4,0,14,10417,100,"chrono lord deja SAY_DEATH","Time ... is on our side.");

-- aeonus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1269018 AND -1269012;
DELETE FROM `creature_text` WHERE `entry`=17881;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17881,0,0,14,10400,100,"aeonus SAY_ENTER","The time has come to shatter this clockwork universe forever! Let us no longer be slaves of the hourglass! I warn you: those who do not embrace the greater path shall become victims of its passing!"),
(17881,1,0,14,10402,100,"aeonus SAY_AGGRO","Let us see what fate lays in store..."),
(17881,2,0,14,10401,100,"aeonus SAY_BANISH","Your time is up, slave of the past!"),
(17881,3,0,14,10403,100,"aeonus SAY_SLAY1","One less obstacle in our way!"),
(17881,3,1,14,10404,100,"aeonus SAY_SLAY2","No one can stop us! No one!"),
(17881,4,0,14,10405,100,"aeonus SAY_DEATH","It is only a matter...of time."),
(17881,5,0,16,0,100,"aeonus EMOTE_FRENZY","goes into a frenzy!");

-- medivh
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1269028 AND -1269020;
DELETE FROM `creature_text` WHERE `entry`=15608;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15608,0,0,14,10435,100,"medivh SAY_ENTER","The time has come! Gul'dan, order your warlocks to double their efforts! Moments from now the gateway will open, and your Horde will be released upon this ripe, unsuspecting world!"),
(15608,1,0,14,10436,100,"medivh SAY_INTRO","What is this? Champions, coming to my aid? I sense the hand of the dark one in this. Truly this sacred event bears his blessing?"),
(15608,2,0,14,10437,100,"medivh SAY_WEAK75","Champions, my shield grows weak!"),
(15608,3,0,14,10438,100,"medivh SAY_WEAK50","My powers must be concentrated on the portal! I do not have time to hold the shield!"),
(15608,4,0,14,10439,100,"medivh SAY_WEAK25","The shield is nearly gone! All that I have worked for is in danger!"),
(15608,5,0,14,10441,100,"medivh SAY_DEATH","No... damn this feeble mortal coil..."),
(15608,6,0,14,10440,100,"medivh SAY_WIN","I am grateful for your aid, champions. Now, Gul'dan's Horde will sweep across this world, like a locust swarm, and all my designs, all my carefully laid plans will at last fall into place."),
(15608,7,0,14,0,100,"medivh SAY_ORCS_ENTER","Orcs of the Horde! This portalis the gateway to your new destiny! Azeroth lies before you, ripe for the taking!"),
(15608,8,0,14,0,100,"medivh SAY_ORCS_ANSWER","Gul'dan speaks the truth! We should return at once to tell our brothers of the news! Retreat back trought the portal!");

-- temporus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1269005 AND -1269000;
DELETE FROM `creature_text` WHERE `entry`=17880;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17880,0,0,14,10442,100,"temporus SAY_ENTER","Why do you persist? Surely you can see the futility of it all. It is not too late! You may still leave with your lives ..."),
(17880,1,0,14,10444,100,"temporus SAY_AGGRO","So be it ... you have been warned."),
(17880,2,0,14,10443,100,"temporus SAY_BANISH","Time... sands of time is run out for you."),
(17880,3,0,14,10445,100,"temporus SAY_SLAY1","You should have left when you had the chance."),
(17880,3,1,14,10446,100,"temporus SAY_SLAY2","Your days are done."),
(17880,4,0,14,10447,100,"temporus SAY_DEATH","My death means ... little.");

-- sprysprocket
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000356 AND -1000351;
DELETE FROM `creature_text` WHERE `entry`=23002;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(23002,0,0,14,0,100,"sprysprocket SAY_START","You, there! Hand over that moonstone and nobody gets hurt!"),
(23002,1,0,15,0,100,"sprysprocket SAY_WHISPER_CHILL","Just chill!"),
(23002,2,0,14,0,100,"sprysprocket SAY_END","All right, you win! I surrender! Just don't hurt me!"),
(23002,3,0,41,0,100,"sprysprocket EMOTE_START","%s takes the Southfury moonstone and escapes into the river. Follow her!");


-- mist
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000324 AND -1000323;
DELETE FROM `creature_text` WHERE `entry`=3568;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(3568,0,0,12,0,100,"mist SAY_AT_HOME","Mist! I feared I would never see you again! Yes, I am well, do not worry for me. You must rest and recover your health."),
(3568,1,0,16,0,100,"mist EMOTE_AT_HOME","%s growls in acknowledgement before straightening and making her way off into the forest.");

-- anachronos the ancient
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1350030 AND -1350000;
DELETE FROM `creature_text` WHERE `entry` IN (15381,15382,15379,15380,15378);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15381,0,0,12,0,100,"anachronos the ancient ANACHRONOS_SAY_1","We must act quickly or all shall be lost!"),
(15381,1,0,12,0,100,"anachronos the ancient ANACHRONOS_SAY_2","NOW, STAGHELM! WE GO NOW! Prepare your magic!"),
(15381,2,0,12,0,100,"anachronos the ancient ANACHRONOS_SAY_3","Stay close..."),
(15381,3,0,12,0,100,"anachronos the ancient ANACHRONOS_SAY_4","The sands of time will halt, but only for a moment! I will now conjure the barrier."),
(15381,4,0,12,0,100,"anachronos the ancient ANACHRONOS_SAY_5","FINISH THE SPELL STAGHELM! I CANNOT HOLD THE GLYPHS OF WARDING IN PLACE MUCH LONGER! CALL FORTH THE ROOTS!"),
(15381,5,0,12,0,100,"anachronos the ancient ANACHRONOS_SAY_6","It... It is over, Lord Staghelm. We are victorious. Albeit the cost for this victory was great."),
(15381,6,0,12,0,100,"anachronos the ancient ANACHRONOS_SAY_7","There is but one duty that remains..."),
(15381,7,0,12,0,100,"anachronos the ancient ANACHRONOS_SAY_8","Before I leave this place, I make one final offreing to you, Lord Staghelm. Should a time arise in which you must gain entry to this accursed fortress, use the Scepter of the Shifting Sands on the sacred gong. The magic holding the barrier together will dissipate and the horrors of Ahn'Qiraj will be unleashed upon the world once more."),
(15381,8,0,12,0,100,"anachronos the ancient ANACHRONOS_SAY_9","Lord Staghelm, where are you going? You would shatter our bond for the sake of pride?"),
(15381,9,0,12,0,100,"anachronos the ancient ANACHRONOS_SAY_10","And now you know all that there is to know, mortal..."),
(15381,10,0,16,0,100,"anachronos the ancient ANACHRONOS_EMOTE_1","hands the Scepter of the Shifting Sands to Fandral Staghelm."),
(15381,11,0,16,0,100,"anachronos the ancient ANACHRONOS_EMOTE_2","shakes his head in dissapointment."),
(15381,12,0,16,0,100,"anachronos the ancient ANACHRONOS_EMOTE_3","kneels down to pick up the fragments of the shattered scepter."),
(15382,0,0,12,0,100,"anachronos the ancient FANDRAL_SAY_1","My forces cannot overcome the Qiraji defenses. We will not be able to get close enough to place your precious barrier, dragon."),
(15382,1,0,12,0,100,"anachronos the ancient FANDRAL_SAY_2","It is done dragon. Lead the way..."),
(15382,2,0,12,0,100,"anachronos the ancient FANDRAL_SAY_3","Ancient ones guide my hand... Wake from your slumber! WAKE AND SEAL THIS CURSED PLACE!"),
(15382,3,0,12,0,100,"anachronos the ancient FANDRAL_SAY_4","After the savagery that my people have witnessed and felt, you expect me to accept another burden, dragon? Surely you are mad."),
(15382,4,0,12,0,100,"anachronos the ancient FANDRAL_SAY_5","I want nothing to do with Silithus, the Qiraji and least of all, any damned dragons!"),
(15382,5,0,12,0,100,"anachronos the ancient FANDRAL_SAY_6","My son's soul will find no comfort in this hollow victory, dragon. I will have him back.Thought it takes a millennia, I WILL have my son back!"),
(15382,6,0,16,0,100,"anachronos the ancient FANDRAL_EMOTE_1","falls to one knee - exhausted."),
(15382,7,0,16,0,100,"anachronos the ancient FANDRAL_EMOTE_2","hurls the Scepter of the Shifting Sands into the barrier, shattering it."),
(15379,0,0,12,0,100,"anachronos the ancient CAELESTRASZ_SAY_1","Aye, Fandral, remember these words: Let not your grief guide your faith. These thoughts you hold... dark places you go, night elf. Absolution cannot be had through misguided vengeance."),
(15379,1,0,12,0,100,"anachronos the ancient CAELESTRASZ_SAY_2","Do not forget the sacrifices made on this day, night elf. We have all suffered immensely at the hands of these beasts."),
(15379,2,0,14,0,100,"anachronos the ancient CAELESTRASZ_YELL_1","Alexstrasza grant me the resolve to drive our enemies back!"),
(15380,0,0,12,0,100,"anachronos the ancient ARYGOS_SAY_1","This distraction will give you and the young druid time enough to seal the gate. Do not falter. Now, let us see how they deal with chaotic magic."),
(15380,1,0,14,0,100,"anachronos the ancient ARYGOS_YELL_1","Let them feel the wrath of the Blue Flight! May Malygos protect me!"),
(15380,2,0,16,0,100,"anachronos the ancient ARYGOS_EMOTE_1","nods knowingly."),
(15378,0,0,12,0,100,"anachronos the ancient MERITHRA_SAY_1","There is a way..."),
(15378,1,0,12,0,100,"anachronos the ancient MERITHRA_SAY_2","We will push them back, Anachronos. This I vow. Uphold the end of this task. Let not your hands falter as you seal our fates behind the barrier."),
(15378,2,0,14,0,100,"anachronos the ancient MERITHRA_YELL_1","Succumb to the endless dream, little ones. Let it consume you!"),
(15378,3,0,16,0,100,"anachronos the ancient MERITHRA_EMOTE_1","glances at her compatriots.");
