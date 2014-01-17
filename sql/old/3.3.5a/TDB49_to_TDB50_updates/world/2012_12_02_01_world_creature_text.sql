-- ------------------------------- --
-- Creature text conversion part 5 --
-- ------------------------------- --

-- draenei survivor
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000183 AND -1000176;
DELETE FROM `creature_text` WHERE `entry`=16483;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16483,0,0,12,0,100,"draenei survivor SAY_HEAL1","The last thing I remember is the ship falling and us getting into the pods. I'll go see how I can help. Thank you!"),
(16483,0,1,12,0,100,"draenei survivor SAY_HEAL2","$C, Where am I? Who are you? Oh no! What happened to the ship?"),
(16483,0,2,12,0,100,"draenei survivor SAY_HEAL3","$C You saved me! I owe you a debt that I can never repay. I'll go see if I can help the others."),
(16483,0,3,12,0,100,"draenei survivor SAY_HEAL4","Ugh... what is this place? Is that all that's left of the ship over there?"),
(16483,1,0,12,0,100,"draenei survivor SAY_HELP1","Oh, the pain..."),
(16483,1,1,12,0,100,"draenei survivor SAY_HELP2","Everything hurts, Please make it stop..."),
(16483,1,2,12,0,100,"draenei survivor SAY_HELP3","Ughhh... I hurt. Can you help me?"),
(16483,1,3,12,0,100,"draenei survivor SAY_HELP4","I don't know if I can make it, please help me...");

-- engineer spark
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000186 AND -1000184;
DELETE FROM `creature_text` WHERE `entry`=17243;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17243,0,0,12,0,100,"engineer spark SAY_TEXT","Yes Master, all goes along as planned."),
(17243,1,0,16,0,100,"engineer spark EMOTE_SHELL","%s puts the shell to his ear."),
(17243,2,0,14,0,100,"engineer spark SAY_ATTACK","Now I cut you!");

-- magwin
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000116 AND -1000111;
DELETE FROM `creature_text` WHERE `entry`=17312;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17312,0,0,12,0,100,"magwin SAY_START","Our house is this way, through the thicket."),
(17312,1,0,12,0,100,"magwin SAY_AGGRO","Help me!"),
(17312,2,0,12,0,100,"magwin SAY_PROGRESS","My poor family. Everything has been destroyed."),
(17312,3,0,12,0,100,"magwin SAY_END1","Father! Father! You're alive!"),
(17312,4,0,12,0,100,"magwin SAY_END2","You can thank $N for getting me back here safely, father."),
(17312,5,0,16,0,100,"magwin EMOTE_HUG","%s hugs her father.");

-- geezle
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000636 AND -1000629;
DELETE FROM `creature_text` WHERE `entry` IN (17243,17318);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17318,0,0,12,0,100,"geezle GEEZLE_SAY_1","What's the big idea, Spark?"),
(17243,0,0,12,0,100,"geezle SPARK_SAY_2","What's the big idea? You nearly blew my cover, idiot! I told you to put the compass and navigation maps somewhere safe - not out in the open for any fool to discover."),
(17243,1,0,12,0,100,"geezle SPARK_SAY_3","The Master has gone to great lengths to secure information about the whereabouts of the Exodar. You could have blown the entire operation, including the cover of our spy on the inside."),
(17318,1,0,12,0,100,"geezle GEEZLE_SAY_4","Relax, Spark! I have it all under control. We'll strip mine the Exodar right out from under 'em - making both you and I very, very rich in the process."),
(17243,2,0,12,0,100,"geezle SPARK_SAY_5","Relax? Do you know what Kael'thas does to those that fail him, Geezle? Eternal suffering and pain... Do NOT screw this up, fool."),
(17243,3,0,12,0,100,"geezle SPARK_SAY_6","Our Bloodmyst scouts have located our contact. The fool, Velen, will soon leave himself open and defenseless -- long enough for us to strike! Now get out of my sight before I vaporize you..."),
(17318,2,0,12,0,100,"geezle GEEZLE_SAY_7","Yes, sir. It won't happen again..."),
(17243,4,0,16,0,100,"geezle EMOTE_SPARK","picks up the naga flag.");

-- stillpine capitive
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000476 AND -1000474;
DELETE FROM `creature_text` WHERE `entry`=17375;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17375,0,0,12,0,100,"stillpine capitive CAPITIVE_SAY_1","[Fulborg] The Stillpine furbolgs will not soon forget your bravery!"),
(17375,0,1,12,0,100,"stillpine capitive CAPITIVE_SAY_2","[Fulborg] Thank you, $N"),
(17375,0,2,12,0,100,"stillpine capitive CAPITIVE_SAY_3","[Fulborg] Those remaining at Stillpine Hold will welcome you as a hero!");

-- morridune
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1048004 AND -1048003;
DELETE FROM `creature_text` WHERE `entry`=6729;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(6729,0,0,14,0,100,"morridune SAY_MORRIDUNE_1","Aku'mai is dead! At last,I can leave this wretched place."),
(6729,1,0,12,0,100,"morridune SAY_MORRIDUNE_2","Speak with me to hear my tale");

-- princess stillpine
DELETE FROM `script_texts` WHERE `entry`=1800074;
DELETE FROM `creature_text` WHERE `entry`=17682;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17682,0,0,12,0,100,"princess stillpine SAY_DIRECTION","Go to the west");

-- kerlonian
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000444 AND -1000434;
DELETE FROM `creature_text` WHERE `entry`=11218;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(11218,0,0,12,0,100,"kerlonian SAY_KER_START","Liladris has been waiting for me at Maestra's Post, so we should make haste, $N."),
(11218,1,0,16,0,100,"kerlonian EMOTE_KER_SLEEP_1","%s looks very sleepy..."),
(11218,1,1,16,0,100,"kerlonian EMOTE_KER_SLEEP_2","%s suddenly falls asleep"),
(11218,1,2,16,0,100,"kerlonian EMOTE_KER_SLEEP_3","%s begins to drift off..."),
(11218,2,0,12,0,100,"kerlonian SAY_KER_SLEEP_1","This looks like the perfect place for a nap..."),
(11218,2,1,12,0,100,"kerlonian SAY_KER_SLEEP_2","Yaaaaawwwwwnnnn..."),
(11218,2,2,12,0,100,"kerlonian SAY_KER_SLEEP_3","Oh, I am so tired..."),
(11218,2,3,12,0,100,"kerlonian SAY_KER_SLEEP_4","You don't mind if I stop here for a moment, do you?"),
(11218,3,0,12,0,100,"kerlonian SAY_KER_ALERT_1","Be on the alert! The Blackwood furbolgs are numerous in the area..."),
(11218,3,1,12,0,100,"kerlonian SAY_KER_ALERT_2","It's quiet... Too quiet..."),
(11218,4,0,12,0,100,"kerlonian SAY_KER_END","Oh, I can see Liladris from here... Tell her I'm here, won't you?"),
(11218,5,0,16,0,100,"kerlonian EMOTE_KER_AWAKEN","%s wakes up!");

-- remtravel
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000339 AND -1000327;
DELETE FROM `creature_text` WHERE `entry`=2917;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(2917,0,0,12,0,100,"remtravel SAY_REM_START","Ok, $n, let's go find where I left that mysterious fossil. Follow me!"),
(2917,1,0,12,0,100,"remtravel SAY_REM_RAMP1_1","Now where did I put that mysterious fossil? Ah, maybe up there..."),
(2917,2,0,12,0,100,"remtravel SAY_REM_RAMP1_2","Hrm, nothing up here."),
(2917,3,0,12,0,100,"remtravel SAY_REM_BOOK","No mysterious fossil here... Ah, but my copy of Green Hills of Stranglethorn. What a good book!"),
(2917,4,0,12,0,100,"remtravel SAY_REM_TENT1_1","I bet you I left it in the tent!"),
(2917,5,0,12,0,100,"remtravel SAY_REM_TENT1_2","Oh wait, that's Hollee's tent... and it's empty."),
(2917,6,0,12,0,100,"remtravel SAY_REM_MOSS","Interesting... I hadn't noticed this earlier..."),
(2917,7,0,16,0,100,"remtravel EMOTE_REM_MOSS","%s inspects the ancient, mossy stone."),
(2917,8,0,12,0,100,"remtravel SAY_REM_MOSS_PROGRESS","Oh wait! I'm supposed to be looking for that mysterious fossil!"),
(2917,9,0,12,0,100,"remtravel SAY_REM_PROGRESS","Nope. didn't leave the fossil back here!"),
(2917,10,0,12,0,100,"remtravel SAY_REM_REMEMBER","Ah. I remember now! I gave the mysterious fossil to Hollee! Check with her."),
(2917,11,0,16,0,100,"remtravel EMOTE_REM_END","%s goes back to work, oblivious to everything around him."),
(2917,12,0,12,0,100,"remtravel SAY_REM_AGGRO","Something tells me this $r wants the mysterious fossil too. Help!");

-- hendel
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000415 AND -1000411;
DELETE FROM `creature_text` WHERE `entry`=4966;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(4966,0,0,12,0,100,"hendel SAY_PROGRESS_1_TER","Why don't we deal with you now, Hendel? Lady Proudmoore will speak for you back in the tower."),
(4966,1,0,12,0,100,"hendel SAY_PROGRESS_2_HEN","Please... please... Miss Proudmore. I didn't mean to..."),
(4966,2,0,12,0,100,"hendel SAY_PROGRESS_3_TER","I apologize for taking so long to get here. I wanted Lady Proudmoore to be present also."),
(4966,3,0,12,0,100,"hendel SAY_PROGRESS_4_TER","We can only stay a few moments before returning to the tower. If you wish to speak to us more you may find us there."),
(4966,4,0,16,0,100,"hendel EMOTE_SURRENDER","%s, too injured, gives up the chase.");

-- zelfrax
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000473 AND -1000472;
DELETE FROM `creature_text` WHERE `entry`=23864;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(23864,0,0,14,0,100,"zelfrax SAY_ZELFRAX1","This land was mine long before your wretched kind set foot here."),
(23864,1,0,14,0,100,"zelfrax SAY_ZELFRAX2","All who venture here belong to me,including you!");

-- oox
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000292 AND -1000287;
DELETE FROM `creature_text` WHERE `entry`=7807;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(7807,0,0,12,0,100,"oox SAY_OOX_START","Emergency power activated! Initializing ambulanory motor! CLUCK!"),
(7807,1,0,12,0,100,"oox SAY_OOX_AGGRO1","Physical threat detected! Evasive action! CLUCK!"),
(7807,1,1,12,0,100,"oox SAY_OOX_AGGRO2","Thread analyzed! Activating combat plan beta! CLUCK!"),
(7807,2,0,12,0,100,"oox SAY_OOX_AMBUSH","CLUCK! Sensors detect spatial anomaly - danger imminent! CLUCK!"),
(7807,3,0,12,0,100,"oox SAY_OOX_END","Cloaking systems online! CLUCK! Engaging cloak for transport to Booty Bay!");

-- kyle
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000342 AND -1000340;
DELETE FROM `creature_text` WHERE `entry`=23616;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(23616,0,0,16,0,100,"kyle EMOTE_SEE_LUNCH","%s howls in delight at the sight of his lunch!"),
(23616,1,0,16,0,100,"kyle EMOTE_EAT_LUNCH","%s eats his lunch."),
(23616,2,0,16,0,100,"kyle EMOTE_DANCE","%s thanks you with a special dance.");

-- willix
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1047010 AND -1047000;
DELETE FROM `creature_text` WHERE `entry`=4508;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(4508,0,0,12,0,100,"willix SAY_READY","Phew! Finally, out here. However, it will not become easy. Detain your eyes after annoyance."),
(4508,1,0,12,0,100,"willix SAY_POINT","There on top resides Charlga Razorflank. The damned old Crone."),
(4508,2,0,12,0,100,"willix SAY_AGGRO1","Help! Get this Raging Agam'ar from me!"),
(4508,3,0,12,0,100,"willix SAY_BLUELEAF","In this ditch there are Blueleaf Tuber! As if the gold waited only to be dug out, I say it you!"),
(4508,4,0,12,0,100,"willix SAY_DANGER","Danger is behind every corner."),
(4508,5,0,12,0,100,"willix SAY_BAD","I do not understand how these disgusting animals can live at such a place.... puh as this stinks!"),
(4508,6,0,12,0,100,"willix SAY_THINK","I think, I see a way how we come out of this damned thorn tangle."),
(4508,7,0,12,0,100,"willix SAY_SOON","I am glad that we are out again from this damned ditch. However, up here it is not much better!"),
(4508,8,0,12,0,100,"willix SAY_FINALY","Finally! I am glad that I come, finally out here."),
(4508,9,0,12,0,100,"willix SAY_WIN","I will rather rest a moment and come again to breath, before I return to Ratchet."),
(4508,10,0,12,0,100,"willix SAY_END","Many thanks for your help.");

-- threshwackonator
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000326 AND -1000325;
DELETE FROM `creature_text` WHERE `entry`=6669;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(6669,0,0,16,0,100,"threshwackonator EMOTE_START","\"Threshwackonator First Mate unit prepared to follow\""),
(6669,1,0,12,0,100,"threshwackonator SAY_AT_CLOSE","YARRR! Swabie, what have ye done?! He's gone mad! Baton him down the hatches! Hoist the mast! ARRRR! Every man for hi'self!");

-- kodo round
DELETE FROM `script_texts` WHERE `entry`=-1000350;
DELETE FROM `creature_text` WHERE `entry`=9453;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(9453,0,0,12,0,100,"kodo round SAY_SMEED_HOME_3","That kodo sure is a beauty. Wait a minute, where are my bifocals? Perhaps you should inspect the beast for me.");

-- oox
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000292 AND -1000287;
DELETE FROM `creature_text` WHERE `entry` IN (7784,7805);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(7784,0,0,12,0,100,"oox SAY_OOX_START","Emergency power activated! Initializing ambulanory motor! CLUCK!"),
(7784,1,0,12,0,100,"oox SAY_OOX_AGGRO1","Physical threat detected! Evasive action! CLUCK!"),
(7784,1,1,12,0,100,"oox SAY_OOX_AGGRO2","Thread analyzed! Activating combat plan beta! CLUCK!"),
(7784,2,0,12,0,100,"oox SAY_OOX_AMBUSH","CLUCK! Sensors detect spatial anomaly - danger imminent! CLUCK!"),
(7805,0,0,12,0,100,"oox SAY_OOX17_AMBUSH_REPLY","No one challanges the Wastewander nomads - not even robotic chickens! ATTACK!"),
(7784,3,0,12,0,100,"oox SAY_OOX_END","Cloaking systems online! CLUCK! Engaging cloak for transport to Booty Bay!");

-- tooga
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000398 AND -1000391;
DELETE FROM `creature_text` WHERE `entry` IN (5955,6015);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(5955,0,0,12,0,100,"tooga SAY_TOOG_THIRST","I'm Thirsty."),
(5955,0,1,12,0,100,"tooga SAY_TOOG_WORRIED","Torta must be so worried."),
(5955,1,0,12,0,100,"tooga SAY_TOOG_POST_1","Torta, my love! I have returned at long last."),
(6015,0,0,12,0,100,"tooga SAY_TORT_POST_2","You have any idea how long I've been waiting here? And where's dinner? All that time gone and nothing to show for it?"),
(5955,2,0,12,0,100,"tooga SAY_TOOG_POST_3","My dearest Torta. I have been gone for so long. Finally we are reunited. At long last our love can blossom again."),
(6015,1,0,12,0,100,"tooga SAY_TORT_POST_4","Enough with the rambling. I am starving! Now, get your dusty shell into that ocean and bring momma some grub."),
(5955,3,0,12,0,100,"tooga SAY_TOOG_POST_5","Yes Torta. Whatever your heart desires..."),
(6015,2,0,12,0,100,"tooga SAY_TORT_POST_6","And try not to get lost this time...");

-- cthun
DELETE FROM `script_texts` WHERE `entry`=-1531011;
DELETE FROM `creature_text` WHERE `entry`=15727;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15727,0,0,16,0,100,"cthun EMOTE_WEAKENED","%s is weakened!");

-- huhuran
DELETE FROM `creature_text` WHERE `entry`=15509;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15509,0,0,16,0,100,"huhuran EMOTE_FRENZY_KILL","%s goes into a killing frenzy!"),
(15509,1,0,16,0,100,"huhuran EMOTE_BERSERK","%s goes into a berserker rage!");

-- sartura
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1531010 AND -1531008;
DELETE FROM `creature_text` WHERE `entry`=15516;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15516,0,0,14,8646,100,"sartura SAY_AGGRO","You will be judged for defiling these sacred grounds! The laws of the Ancients will not be challenged! Trespassers will be annihilated!"),
(15516,1,0,14,8647,100,"sartura SAY_SLAY","I sentence you to death!"),
(15516,2,0,14,8648,100,"sartura SAY_DEATH","I serve to the last!");

-- skeram
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1531007 AND -1531000;
DELETE FROM `creature_text` WHERE `entry`=15263;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(15263,0,0,14,8615,100,"skeram SAY_AGGRO1","Are you so eager to die? I would be happy to accomodate you."),
(15263,0,1,14,8616,100,"skeram SAY_AGGRO2","Cower mortals! The age of darkness is at hand."),
(15263,0,2,14,8621,100,"skeram SAY_AGGRO3","Tremble! The end is upon you."),
(15263,1,0,14,8617,100,"skeram SAY_SLAY1","Let your death serve as an example!"),
(15263,1,1,14,8619,100,"skeram SAY_SLAY2","Spineless wretches! You will drown in rivers of blood!"),
(15263,1,2,14,8620,100,"skeram SAY_SLAY3","The screams of the dying will fill the air. A symphony of terror is about to begin!"),
(15263,2,0,14,8618,100,"skeram SAY_SPLIT","Prepare for the return of the ancient ones!"),
(15263,3,0,14,8622,100,"skeram SAY_DEATH","You only delay... the inevetable.");

-- kanati
DELETE FROM `script_texts` WHERE `entry`=-1000410;
DELETE FROM `creature_text` WHERE `entry`=10638;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(10638,0,0,12,0,100,"kanati SAY_KAN_START","Here they come! Defend yourself!");

-- lakota
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000369 AND -1000365;
DELETE FROM `creature_text` WHERE `entry`=10646;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(10646,0,0,12,0,100,"lakota SAY_LAKO_START","Be on guard... Arnak has some strange power over the Grimtotem... they will not be happy to see me escape."),
(10646,1,0,12,0,100,"lakota SAY_LAKO_LOOK_OUT","Look out, the Grimtotem are upon us!"),
(10646,2,0,12,0,100,"lakota SAY_LAKO_HERE_COME","Here they come."),
(10646,3,0,12,0,100,"lakota SAY_LAKO_MORE","More Grimtotems are coming this way!"),
(10646,4,0,12,0,100,"lakota SAY_LAKO_END","Finally, free at last... I must be going now, thanks for helping me escape. I can get back to Freewind Post by myself.");

-- paoka
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000364 AND -1000362;
DELETE FROM `creature_text` WHERE `entry`=10427;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(10427,0,0,12,0,100,"paoka SAY_START","Let's go $N. I am ready to reach Whitereach Post."),
(10427,1,0,12,0,100,"paoka SAY_WYVERN","Now this looks familiar. If we keep heading east, I think we can... Ahh, Wyvern on the attack!"),
(10427,2,0,12,0,100,"paoka SAY_COMPLETE","Thanks a bunch... I can find my way back to Whitereach Post from here. Be sure to talk with Motega Firemane; perhaps you can keep him from sending me home.");

-- disciple
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1043017 AND -1043000;
DELETE FROM `creature_text` WHERE `entry` IN (3679,3678);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(3678,0,0,14,0,100,"disciple SAY_AT_LAST","At last! Naralex can be awakened! Come aid me, brave adventurers!"),
(3678,1,0,12,0,100,"disciple SAY_MAKE_PREPARATIONS","I must make the necessary preparations before the awakening ritual can begin. You must protect me!"),
(3678,2,0,12,0,100,"disciple SAY_TEMPLE_OF_PROMISE","These caverns were once a temple of promise for regrowth in the Barrens. Now, they are the halls of nightmares."),
(3678,3,0,12,0,100,"disciple SAY_MUST_CONTINUE","Come. We must continue. There is much to be done before we can pull Naralex from his nightmare."),
(3678,4,0,12,0,100,"disciple SAY_BANISH_THE_SPIRITS","Within this circle of fire I must cast the spell to banish the spirits of the slain Fanglords."),
(3678,5,0,12,0,100,"disciple SAY_CAVERNS_PURIFIED","The caverns have been purified. To Naralex's chamber we go!"),
(3678,6,0,12,0,100,"disciple SAY_BEYOND_THIS_CORRIDOR","Beyond this corridor, Naralex lies in fitful sleep. Let us go awaken him before it is too late."),
(3678,7,0,12,0,100,"disciple SAY_EMERALD_DREAM","Protect me brave souls as I delve into this Emerald Dream to rescue Naralex and put an end to this corruption!"),
(3678,8,0,16,0,100,"disciple EMOTE_AWAKENING_RITUAL","%s begins to perform the awakening ritual on Naralex."),
(3679,0,0,16,0,100,"naralex EMOTE_TROUBLED_SLEEP","%s tosses fitfully in troubled sleep."),
(3679,1,0,16,0,100,"naralex EMOTE_WRITHE_IN_AGONY","%s writhes in agony. The Disciple seems to be breaking through."),
(3679,2,0,16,0,100,"naralex EMOTE_HORRENDOUS_VISION","%s dreams up a horrendous vision. Something stirs beneath the murky waters."),
(3678,9,0,12,0,100,"disciple SAY_MUTANUS_THE_DEVOURER","This Mutanus the Devourer is a minion from Naralex's nightmare no doubt!"),
(3679,3,0,14,0,100,"naralex SAY_I_AM_AWAKE","I AM AWAKE, AT LAST!"),
(3678,10,0,12,0,100,"disciple SAY_NARALEX_AWAKES","At last! Naralex awakes from the nightmare."),
(3679,4,0,12,0,100,"naralex SAY_THANK_YOU","Ah, to be pulled from the dreaded nightmare! I thank you, my loyal Disciple, along with your brave companions."),
(3679,5,0,12,0,100,"naralex SAY_FAREWELL","We must go and gather with the other Disciples. There is much work to be done before I can make another attempt to restore the Barrens. Farewell, brave souls!"),
(3678,11,0,12,0,100,"disciple SAY_ATTACKED","Attacked! Help get this $N off of me!");

-- weegli blastfuse
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1209001 AND -1209000;
DELETE FROM `creature_text` WHERE `entry`=7607;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(7607,0,0,12,0,100,"weegli blastfuse SAY_WEEGLI_OHNO","Oh no! Here they come!"),
(7607,1,0,12,0,100,"weegli blastfuse SAY_WEEGLI_OK_I_GO","OK. Here I go.");

-- anub arak
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1601010 AND -1601000;
DELETE FROM `creature_text` WHERE `entry`=29120;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29120,0,0,14,14054,100,"anub arak SAY_AGGRO","Eternal aggony awaits you!"),
(29120,1,0,14,14057,100,"anub arak SAY_SLAY_1","Soon, the Master's voice will call to you."),
(29120,1,1,14,14056,100,"anub arak SAY_SLAY_2","You have made your choice."),
(29120,1,2,14,14055,100,"anub arak SAY_SLAY_3","You shall experience my torment, first-hand!"),
(29120,2,0,14,14069,100,"anub arak SAY_DEATH","Ahhh... RAAAAAGH! Never thought... I would be free of him..."),
(29120,3,0,14,14060,100,"anub arak SAY_LOCUST_1","Your armor is useless againts my locusts."),
(29120,3,1,14,14067,100,"anub arak SAY_LOCUST_2","Uunak-hissss tik-k-k-k-k!"),
(29120,3,2,14,14068,100,"anub arak SAY_LOCUST_3","The pestilence upon you!"),
(29120,4,0,14,14058,100,"anub arak SAY_SUBMERGE_1","Auum na-l ak-k-k-k, isshhh."),
(29120,4,1,14,14059,100,"anub arak SAY_SUBMERGE_2","Come forth my brethren! Feast on their flesh."),
(29120,5,0,14,14053,100,"anub arak SAY_INTRO","I was king of this empire once, long ago. In life I stood as champion. In death I returned as conqueror. Now I protect the kingdom once more. Ironic, yes? ");

-- krik thir
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1601022 AND -1601011;
DELETE FROM `creature_text` WHERE `entry`=28684;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28684,0,0,14,14075,100,"krik thir SAY_AGGRO","This kingdom belongs to the Scourge! Only the dead may enter."),
(28684,1,0,14,14077,100,"krik thir SAY_SLAY_1","You were foolish to come."),
(28684,1,1,14,14078,100,"krik thir SAY_SLAY_2","As Anub'Arak commands!"),
(28684,2,0,14,14087,100,"krik thir SAY_DEATH","I should be grateful. But I long ago lost the capacity."),
(28684,3,0,14,14085,100,"krik thir SAY_SWARM_1","They hunger."),
(28684,3,1,14,14086,100,"krik thir SAY_SWARM_2","Dinner time, my pets."),
(28684,4,0,14,14082,100,"krik thir SAY_PREFIGHT_1","Keep an eye on the tunnel. We must not let anyone through!"),
(28684,4,1,14,14083,100,"krik thir SAY_PREFIGHT_2","I hear footsteps. Be on your guard."),
(28684,4,2,14,14084,100,"krik thir SAY_PREFIGHT_3","I sense the living. Be ready."),
(28684,5,0,14,14079,100,"krik thir SAY_SEND_GROUP_1","We are besieged. Strike out and bring back their corpses!"),
(28684,5,1,14,14080,100,"krik thir SAY_SEND_GROUP_2","We must hold the gate. Attack! Tear them limb from limb!"),
(28684,5,2,14,14081,100,"krik thir SAY_SEND_GROUP_3","The gate must be protected at all costs. Rip them to shreds!");

-- thassarian
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1571023 AND -1571004;
DELETE FROM `creature_text` WHERE `entry` IN (25301,26203,26170,25250,25251);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
-- talbot
(25301,0,0,12,0,100,"thassarian SAY_TALBOT_1","My liege, the infiltration and control of the Alliance power structure by our cultists is well underway."),
(25301,1,0,12,0,100,"thassarian SAY_TALBOT_2","The power you've bestowed upon me has allowed me great mental influence over human minds. I bear these offerings as proof of my progress."),
(25301,2,0,12,0,100,"thassarian SAY_TALBOT_3","Allow me to take care of the intruders, lord. I will feed their entrails to the maggots."),
(25301,3,0,12,0,100,"thassarian SAY_TALBOT_4","Yes, my lord!"),
-- arthas
(26203,0,0,12,0,100,"thassarian SAY_LICH_1","Your progress in this region has been impressive, Blood Prince. I am pleased..."),
(26203,1,0,12,0,100,"thassarian SAY_LICH_2","Now this is a surprise, Thassarian. I hadn't heard from Mograine or the other death knights for months. You've come to rejoin the Scourge, I take it?"),
(26203,2,0,12,0,100,"thassarian SAY_LICH_3","Do not fail me, San'layn. Return to Icecrown with this fool's head or do not bother to return."),
-- thassarian
(26170,0,0,14,0,100,"thassarian SAY_THASSARIAN_1","Leryssa!"),
(26170,1,0,14,0,100,"thassarian SAY_THASSARIAN_2","What have you done to my sister, you motherless elf scum!?"),
(26170,2,0,12,0,100,"thassarian SAY_THASSARIAN_3","I would sooner slit my own throat. You will pay for what you did to your own men, Arthas... for what you did to me! I swear it."),
(26170,3,0,12,0,100,"thassarian SAY_THASSARIAN_4","Leryssa... you... you're all right!"),
(26170,4,0,12,0,100,"thassarian SAY_THASSARIAN_5","I cannot return home with you just yet, Leryssa. I am not quite done with the Scourge."),
(26170,5,0,12,0,100,"thassarian SAY_THASSARIAN_6","You might be right, sister. My obligations to my land and King have been fulfilled. But there is still something that I owe to myself."),
(26170,6,0,12,0,100,"thassarian SAY_THASSARIAN_7","Do not worry, Leryssa. I will come back to you when I'm done. Nothing in the world will stop me from coming home to the only family that I have left."),
-- arlos
(25250,0,0,12,0,100,"thassarian SAY_ARLOS_1","What... what happened to me?"),
(25250,1,0,12,0,100,"thassarian SAY_ARLOS_2","Ugh! My head won't stop spinning..."),
-- leryssa
(25251,0,0,14,0,100,"thassarian SAY_LERYSSA_1","Thassarian, you're alive!"),
(25251,1,0,12,0,100,"thassarian SAY_LERYSSA_2","I thought... I thought you were... dead."),
(25251,2,0,12,0,100,"thassarian SAY_LERYSSA_3","Don't leave me again! You want to fight for your country, but they don't even want you! They sent you here to die!"),
(25251,3,0,12,0,100,"thassarian SAY_LERYSSA_4","I know that look in your eye... I'm not going to be able to talk you out of this. If you die on me again...");

-- mootoo the younger
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1750044 AND -1750040;
DELETE FROM `creature_text` WHERE `entry`=25504;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(25504,0,0,12,0,100,"mootoo the younger SAY_1","My father's aura is quite strong,he cannot be far. Could you be a doll and fight off the monsters wandering throught the mist?"),
(25504,1,0,12,0,100,"mootoo the younger SAY_2","Watch out for the monsters!Which way should we go first? Let's try this way..."),
(25504,2,0,12,0,100,"mootoo the younger SAY_3","What could this be?"),
(25504,3,0,12,0,100,"mootoo the younger SAY_4","There's no sign of it ending! Where could my father be?"),
(25504,4,0,12,0,100,"mootoo the younger SAY_5","Father! You're safe!");

-- imprisoned beryl sorcerer
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1571030 AND -1571024;
DELETE FROM `creature_text` WHERE `entry`=25478;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(25478,0,0,12,0,100,"imprisoned beryl sorcerer SAY_IMPRISIONED_BERYL_1","Pathetic fool! A servant of Malygos would sooner die than aid an enemy..."),
(25478,1,0,12,0,100,"imprisoned beryl sorcerer SAY_IMPRISIONED_BERYL_2","Aargh! Do your worst, $C ! I'll tell you NOTHING!"),
(25478,2,0,12,0,100,"imprisoned beryl sorcerer SAY_IMPRISIONED_BERYL_3","Aahhhh! Release me! I am of no use to you. I swear it!"),
(25478,3,0,12,0,100,"imprisoned beryl sorcerer SAY_IMPRISIONED_BERYL_4","Stop! I beg you, please stop. Please..."),
(25478,4,0,12,0,100,"imprisoned beryl sorcerer SAY_IMPRISIONED_BERYL_5","Alright! I am beaten. Your previous archmage is held in a prison, elevated and sealed. Even if you manage to reach her, Salrand herself holds the key. Your mission is folly!"),
(25478,5,0,12,0,100,"imprisoned beryl sorcerer SAY_IMPRISIONED_BERYL_6","I've given you the information, $C ! You're wasting your time...."),
(25478,6,0,12,0,100,"imprisoned beryl sorcerer SAY_IMPRISIONED_BERYL_7","Noooo! This torture is inhumane! You have what you want... why don't you just kill me?");

-- bonker togglevolt
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1700003 AND -1700002;
DELETE FROM `creature_text` WHERE `entry`=25589;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(25589,0,0,12,0,100,"bonker togglevolt","I AM NOT AN APPETIZER!"),
(25589,1,0,12,0,100,"bonker togglevolt","I'll make you a deal: If you get me out of here alive,you'll get a reward larger than you can imagine!");

-- hidden cultist
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1571047 AND -1571044;
DELETE FROM `creature_text` WHERE `entry` IN (25827,25248,25828);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(25827,0,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_1","Well..."),
(25827,1,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_2","Finally! This charade is over... Arthas give me strength!"),
(25827,2,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_3","You don't know who you're messing with! Death beckons!"),
(25827,3,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_4","I suppose this is it, then? I won't go down quietly!"),
(25248,0,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_1","Well..."),
(25248,1,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_2","Finally! This charade is over... Arthas give me strength!"),
(25248,2,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_3","You don't know who you're messing with! Death beckons!"),
(25248,3,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_4","I suppose this is it, then? I won't go down quietly!"),
(25828,0,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_1","Well..."),
(25828,1,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_2","Finally! This charade is over... Arthas give me strength!"),
(25828,2,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_3","You don't know who you're messing with! Death beckons!"),
(25828,3,0,12,0,100,"hidden cultist SAY_HIDDEN_CULTIST_4","I suppose this is it, then? I won't go down quietly!");

-- lord kelriss
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1048002 AND -1048000;
DELETE FROM `creature_text` WHERE `entry`=4832;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(4832,0,0,14,5803,100,"lord kelriss SAY_AGRRO","Just...Dust..."),
(4832,1,0,14,5804,100,"lord kelriss SAY_SLEEP","Sleep..."),
(4832,2,0,14,5802,100,"lord kelriss SAY_DEATH","Who dares disturb my meditation!");

-- theramore guard
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000649 AND -1000641;
DELETE FROM `creature_text` WHERE `entry`=4979;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(4979,0,0,12,0,100,"theramore guard SAY_QUEST1","Hey, thanks."),
(4979,1,0,12,0,100,"theramore guard SAY_QUEST2","...receive 50 percent off deserter undergarments? What is this garbage?"),
(4979,1,1,12,0,100,"theramore guard SAY_QUEST2","...to establish a fund for the purchase of hair gel? I like my hair the way it is, thanks!"),
(4979,1,2,12,0,100,"theramore guard SAY_QUEST2","...the deserters seek a Theramore where citizens will be free to juggle at all hours of the day? What is this nonsense?"),
(4979,1,3,12,0,100,"theramore guard SAY_QUEST2","...to establish the chicken as the official symbol of Theramore?! These guys are nuts!"),
(4979,1,4,12,0,100,"theramore guard SAY_QUEST2","...as a deserter, you'll enjoy activities like tethered swimming and dog grooming? How ridiculous!"),
(4979,2,0,12,0,100,"theramore guard SAY_QUEST3","This... this is a joke, right?"),
(4979,2,1,12,0,100,"theramore guard SAY_QUEST3","I'd never join anything like this. Better keep this, though. It'll come in handy in the privy..."),
(4979,2,2,12,0,100,"theramore guard SAY_QUEST3","What a bunch of lunatics! You actually believe this stuff?");

-- sartharion
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1615031 AND -1615018;
DELETE FROM `creature_text` WHERE `entry`=28860;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(28860,0,0,14,14093,100,"sartharion SAY_SARTHARION_AGGRO","It is my charge to watch over these eggs. I will see you burn before any harm comes to them!"),
(28860,1,0,14,14103,100,"sartharion SAY_SARTHARION_BERSERK","This pathetic siege ends NOW!"),
(28860,2,0,14,14098,100,"sartharion SAY_SARTHARION_BREATH","Burn, you miserable wretches!"),
(28860,3,0,14,14105,100,"sartharion SAY_SARTHARION_CALL_SHADRON","Shadron! Come to me, all is at risk!"),
(28860,4,0,14,14106,100,"sartharion SAY_SARTHARION_CALL_TENEBRON","Tenebron! The eggs are yours to protect as well!"),
(28860,5,0,14,14104,100,"sartharion SAY_SARTHARION_CALL_VESPERON","Vesperon! The clutch is in danger! Assist me!"),
(28860,6,0,14,14107,100,"sartharion SAY_SARTHARION_DEATH","Such is the price... of failure..."),
(28860,7,0,14,14099,100,"sartharion SAY_SARTHARION_SPECIAL_1","Such flammable little insects...."),
(28860,7,1,14,14100,100,"sartharion SAY_SARTHARION_SPECIAL_2","Your charred bones will litter the floor!"),
(28860,7,2,14,14101,100,"sartharion SAY_SARTHARION_SPECIAL_3","How much heat can you take?"),
(28860,7,3,14,14102,100,"sartharion SAY_SARTHARION_SPECIAL_4","All will be reduced to ash!"),
(28860,8,0,14,14094,100,"sartharion SAY_SARTHARION_SLAY_1","You will make a fine meal for the hatchlings."),
(28860,8,1,14,14096,100,"sartharion SAY_SARTHARION_SLAY_2","You are the grave disadvantage."),
(28860,8,2,14,14097,100,"sartharion SAY_SARTHARION_SLAY_3","This is why we call you lesser beeings."),
(28860,9,0,42,0,100,"sartharion WHISPER_LAVA_CHURN","The lava surrounding %s churns!");

-- tenebron
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1615016 AND -1615009;
DELETE FROM `creature_text` WHERE `entry`=30452;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(30452,0,0,14,14122,100,"tenebron SAY_TENEBRON_AGGRO","You have no place here. Your place is among the departed."),
(30452,1,0,14,14123,100,"tenebron SAY_TENEBRON_SLAY_1","No contest."),
(30452,1,1,14,14124,100,"tenebron SAY_TENEBRON_SLAY_2","Typical... Just as I was having fun."),
(30452,2,0,14,14129,100,"tenebron SAY_TENEBRON_DEATH","I should not... have held back..."),
(30452,3,0,14,14125,100,"tenebron SAY_TENEBRON_BREATH","To darkness I condemn you..."),
(30452,4,0,14,14128,100,"tenebron SAY_TENEBRON_RESPOND","It is amusing to watch you struggle. Very well, witness how it is done."),
(30452,5,0,14,14126,100,"tenebron SAY_TENEBRON_SPECIAL_1","Arrogant little creatures! To challenge powers you do not yet understand..."),
(30452,5,1,14,14127,100,"tenebron SAY_TENEBRON_SPECIAL_2","I am no mere dragon! You will find I am much, much, more..."),
(30452,6,0,42,0,100,"tenebron WHISPER_HATCH_EGGS","%s begins to hatch eggs in the twilight!");

-- shadron
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1615007 AND -1615000;
DELETE FROM `creature_text` WHERE `entry`=30451;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(30451,0,0,14,14111,100,"shadron SAY_SHADRON_AGGRO","I fear nothing! Least of all you!"),
(30451,1,0,14,14112,100,"shadron SAY_SHADRON_SLAY_1","You are insignificant!"),
(30451,1,1,14,14113,100,"shadron SAY_SHADRON_SLAY_2","Such mediocre resistance!"),
(30451,2,0,14,14118,100,"shadron SAY_SHADRON_DEATH","We...are superior! How could this...be..."),
(30451,3,0,14,14114,100,"shadron SAY_SHADRON_BREATH","You are easily bested! "),
(30451,4,0,14,14117,100,"shadron SAY_SHADRON_RESPOND","I will take pity on you Sartharion, just this once."),
(30451,5,0,14,14115,100,"shadron SAY_SHADRON_SPECIAL_1","Father tought me well!"),
(30451,5,1,14,14116,100,"shadron SAY_SHADRON_SPECIAL_2","On your knees!"),
(30451,6,0,42,0,100,"shadron WHISPER_OPEN_PORTAL","%s begins to open a Twilight Portal!");

-- vesperon
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1615040 AND -1615033;
DELETE FROM `creature_text` WHERE `entry`=30449;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(30449,0,0,14,14133,100,"vesperon SAY_VESPERON_AGGRO","You pose no threat, lesser beings...give me your worst!"),
(30449,1,0,14,14134,100,"vesperon SAY_VESPERON_SLAY_1","The least you could do is put up a fight..."),
(30449,1,1,14,14135,100,"vesperon SAY_VESPERON_SLAY_2","Was that the best you can do?"),
(30449,2,0,14,14140,100,"vesperon SAY_VESPERON_DEATH","I still have some...fight..in...me..."),
(30449,3,0,14,14136,100,"vesperon SAY_VESPERON_BREATH","I will pick my teeth with your bones!"),
(30449,4,0,14,14139,100,"vesperon SAY_VESPERON_RESPOND","Father was right about you, Sartharion...You are a weakling!"),
(30449,5,0,14,14137,100,"vesperon SAY_VESPERON_SPECIAL_1","Aren't you tricky...I have a few tricks of my own..."),
(30449,5,1,14,14138,100,"vesperon SAY_VESPERON_SPECIAL_2","Unlike, I have many talents."),
(30449,6,0,42,0,100,"vesperon WHISPER_OPEN_PORTAL","%s begins to open a Twilight Portal!");

-- novos
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1600005 AND -1600000;
DELETE FROM `creature_text` WHERE `entry`=26631;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26631,0,0,14,13173,100,"novos SAY_AGGRO","The chill that you feel is the herald of your doom!"),
(26631,1,0,14,13175,100,"novos SAY_KILL","Such is the fate of all who oppose the Lich King."),
(26631,2,0,14,13174,100,"novos SAY_DEATH","Your efforts... are in vain."),
(26631,3,0,14,13176,100,"novos SAY_NECRO_ADD","Bolster my defenses! Hurry, curse you!"),
(26631,4,0,14,13177,100,"novos SAY_REUBBLE_1","Surely you can see the futility of it all!"),
(26631,4,1,14,13178,100,"novos SAY_REUBBLE_2","Just give up and die already!");

-- tharon ja
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1600018 AND -1600011;
DELETE FROM `creature_text` WHERE `entry`=26632;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26632,0,0,14,13862,100,"tharon ja SAY_AGGRO","Tharon'ja sees all! The work of mortals shall not end the eternal dynasty!"),
(26632,1,0,14,13863,100,"tharon ja SAY_KILL_1","As Tharon'ja predicted."),
(26632,1,1,14,13864,100,"tharon ja SAY_KILL_2","As it was written."),
(26632,2,0,14,13865,100,"tharon ja SAY_FLESH_1","Your flesh serves Tharon'ja now!"),
(26632,2,1,14,13866,100,"tharon ja SAY_FLESH_2","Tharon'ja has a use for your mortal shell!"),
(26632,3,0,14,13867,100,"tharon ja SAY_SKELETON_1","No! A taste... all too brief!"),
(26632,3,1,14,13868,100,"tharon ja SAY_SKELETON_2","Tharon'ja will have more!"),
(26632,4,0,14,13869,100,"tharon ja SAY_DEATH","I'm... impossible! Tharon'ja is eternal! Tharon'ja... is...");

-- trollgore
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1600010 AND -1600006;
DELETE FROM `creature_text` WHERE `entry`=26630;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26630,0,0,14,13181,100,"trollgore SAY_AGGRO","More grunts, more glands, more FOOD!"),
(26630,1,0,14,13185,100,"trollgore SAY_KILL","You have gone, me gonna eat you!"),
(26630,2,0,14,13182,100,"trollgore SAY_CONSUME","So hungry! Must feed!"),
(26630,3,0,14,13184,100,"trollgore SAY_EXPLODE","Corpse go boom!"),
(26630,4,0,14,13183,100,"trollgore SAY_DEATH","Aaaargh...");

-- bronjham
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1632006 AND -1632001;
DELETE FROM `creature_text` WHERE `entry`=36497;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(36497,0,0,14,16595,100,"bronjham SAY_AGGRO","Finally...a captive audience!"),
(36497,1,0,14,16596,100,"bronjham SAY_SLAY_1","Fodder for the engine!"),
(36497,1,1,14,16597,100,"bronjham SAY_SLAY_2","Another soul to strengthen the host!"),
(36497,2,0,14,16598,100,"bronjham SAY_DEATH",""),
(36497,3,0,14,16599,100,"bronjham SAY_SOUL_STORM","The vortex of the harvested calls to you!"),
(36497,4,0,14,16600,100,"bronjham SAY_CORRUPT_SOUL","I will sever the soul from your body!");

-- devoureur
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1632030 AND -1632010;
DELETE FROM `creature_text` WHERE `entry` IN (36502,38160,38161);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(36502,0,0,14,16884,100,"devoureur SAY_FACE_ANGER_AGGRO","You dare look upon the host of souls? I SHALL DEVOUR YOU WHOLE!"),
(36502,0,1,14,16890,100,"devoureur SAY_FACE_DESIRE_AGGRO","You dare look upon the host of souls? I SHALL DEVOUR YOU WHOLE!"),
(36502,1,0,14,16885,100,"devoureur SAY_FACE_ANGER_SLAY_1","Damnation!"),
(36502,1,1,14,16886,100,"devoureur SAY_FACE_ANGER_SLAY_2","Doomed for eternity!"),
(36502,2,0,14,16896,100,"devoureur SAY_FACE_SORROW_SLAY_1","Damnation!"),
(36502,2,1,14,16897,100,"devoureur SAY_FACE_SORROW_SLAY_2","Doomed for eternity!"),
(36502,3,0,14,16891,100,"devoureur SAY_FACE_DESIRE_SLAY_1","Damnation!"),
(36502,3,1,14,16892,100,"devoureur SAY_FACE_DESIRE_SLAY_2","Doomed for eternity!"),
(36502,4,0,14,16887,100,"devoureur SAY_FACE_ANGER_DEATH","The swell of souls will not be abated! You only delay the inevitable!"),
(36502,4,1,14,16898,100,"devoureur SAY_FACE_SORROW_DEATH","The swell of souls will not be abated! You only delay the inevitable!"),
(36502,4,2,14,16893,100,"devoureur SAY_FACE_DESIRE_DEATH","The swell of souls will not be abated! You only delay the inevitable!"),
(36502,5,0,41,0,100,"devoureur EMOTE_MIRRORED_SOUL","Devourer of Souls begins to cast Mirrored Soul!"),
(36502,6,0,41,0,100,"devoureur EMOTE_UNLEASH_SOUL","Devourer of Souls begins to Unleash Souls!"),
(36502,7,0,14,16888,100,"devoureur SAY_FACE_ANGER_UNLEASH_SOUL","SUFFERING! ANGUISH! CHAOS! RISE AND FEED!"),
(36502,7,1,14,16899,100,"devoureur SAY_FACE_SORROW_UNLEASH_SOUL","SUFFERING! ANGUISH! CHAOS! RISE AND FEED!"),
(36502,7,2,14,16894,100,"devoureur SAY_FACE_DESIRE_UNLEASH_SOUL","SUFFERING! ANGUISH! CHAOS! RISE AND FEED!"),
(36502,8,0,41,0,100,"devoureur EMOTE_WAILING_SOUL","Devourer of Souls begins to cast Wailing Souls!"),
(36502,9,0,14,16889,100,"devoureur SAY_FACE_ANGER_WAILING_SOUL","Stare into the abyss, and see your end!"),
(36502,9,1,14,16895,100,"devoureur SAY_FACE_DESIRE_WAILING_SOUL","Stare into the abyss, and see your end!"),
(38160,0,0,14,16625,100,"jaina SAY_JAINA_OUTRO","Excellent work, champions! We shall set up our base camp in these chambers. My mages will get the Scourge transport device working shortly. Step inside it when you're ready for your next mission. I will meet you on the other side."),
(38161,0,0,14,17044,100,"sylvanas SAY_SYLVANAS_OUTRO","Excellent work, champions! We shall set up our base camp in these chambers. My mages will get the Scourge transport device working shortly. Step inside when you are ready for your next mission. I will meet you on the other side.");

-- lurgglbr
DELETE FROM `creature_text` WHERE `entry`=25208;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(25208,0,0,12,0,100,"lurgglbr SAY_START_1","Together we will fight our way out of here. Are you ready?"),
(25208,1,0,12,0,100,"lurgglbr SAY_START_2","Then we leave."),
(25208,2,0,12,0,100,"lurgglbr SAY_END_1","This is far enough. I can make it on my own from here."),
(25208,3,0,12,0,100,"lurgglbr SAY_END_2","Thank you for helping me $r. Please tell the king I am back.");

-- jaina
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1632047 AND -1632040;
DELETE FROM `creature_text` WHERE `entry`=37597;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(37597,0,0,12,16617,100,"jaina SAY_INTRO_1","Thank the light for seeing you here safely. We have much work to do if we are to defeat the Lich King and put an end to the Scourge."),
(37597,1,0,12,16618,100,"jaina SAY_INTRO_2","Our allies within the Argent Crusade and the Knights of the Ebon Blade have broken through the front gate of Icecrown and are attempting to establish a foothold within the Citadel."),
(37597,2,0,12,16619,100,"jaina SAY_INTRO_3","Their success hinges upon what we discover in these cursed halls. Although our mission is a wrought with peril, we must persevere!"),
(37597,3,0,12,16620,100,"jaina SAY_INTRO_4","With the attention of the Lich King drawn toward the front gate, we will be working our way through the side in search of information that will enable us to defeat the Scourge - once and for all."),
(37597,4,0,12,16621,100,"jaina SAY_INTRO_5","King Varian's SI7 agents have gathered information about a private sanctum of the Lich King's deep within a place called the Halls of Reflection."),
(37597,5,0,12,16622,100,"jaina SAY_INTRO_6","We will carve a path through this wretched place and find a way to enter the Halls of Reflection. I sense powerful magic hidden away within those walls... Magic that could be the key to destroy the Scourge."),
(37597,6,0,12,16623,100,"jaina SAY_INTRO_7","Your first mission is to destroy the machines of death within this malevolent engine of souls, and clear a path for our soldiers."),
(37597,7,0,12,16624,100,"jaina SAY_INTRO_8","Make haste, champions! I will prepare the troops to fall in behind you.");

-- sylvanas
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1632055 AND -1632050;
DELETE FROM `creature_text` WHERE `entry`=37596;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(37596,0,0,12,17038,100,"sylvanas SAY_INTRO_1","The Argent Crusade and the Knights of the Ebon Blade have assaulted the gates of Icecrown Citadel and are preparing for a massive attack upon the Scourge. Our missition is a bit more subtle, but equally as important."),
(37596,1,0,12,17039,100,"sylvanas SAY_INTRO_2","With the attention of the Lich King turned towards the front gate, we'll be working our way through the side in search of information that will enable us to defeat the Lich King - once and for all."),
(37596,2,0,12,17040,100,"sylvanas SAY_INTRO_3","Our scouts have reported that the Lich King has a private chamber, outside of the Frozen Throne, deep within a place called the Halls of Reflection. That is our target, champions."),
(37596,3,0,12,17041,100,"sylvanas SAY_INTRO_4","We will cut a swath of destruction through this cursed place and find a way to enter the Halls of Reflection. If there is anything of value to be found here, it will be found in the Halls."),
(37596,4,0,12,17042,100,"sylvanas SAY_INTRO_5","Your first mission is to destroy the machines of death within this wretched engine of souls, and clear a path for our soldiers."),
(37596,5,0,12,17043,100,"sylvanas SAY_INTRO_6","The Dark Lady watches over you. Make haste!");

-- falric
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1668055 AND -1668050;
DELETE FROM `creature_text` WHERE `entry`=38112;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(38112,0,0,14,16710,100,"falric SAY_AGGRO","Men, women and children... None were spared the master's wrath. Your death will be no different."),
(38112,1,0,14,16711,100,"falric SAY_SLAY_1","Sniveling maggot!"),
(38112,1,1,14,16712,100,"falric SAY_SLAY_2","The children of Stratholme fought with more ferocity!"),
(38112,2,0,14,16713,100,"falric SAY_DEATH","Marwyn, finish them..."),
(38112,3,0,14,16715,100,"falric SAY_IMPENDING_DESPAIR","Despair... so delicious..."),
(38112,4,0,14,16716,100,"falric SAY_DEFILING_HORROR","Fear... so exhilarating...");

-- marwyn
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1668065 AND -1668060;
DELETE FROM `creature_text` WHERE `entry`=38113;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(38113,0,0,14,16734,100,"marwyn SAY_AGGRO","Death is all that you will find here!"),
(38113,1,0,14,16735,100,"marwyn SAY_SLAY_1","I saw the same look in his eyes when he died. Terenas could hardly believe it. Hahahaha!"),
(38113,1,1,14,16736,100,"marwyn SAY_SLAY_2","Choke on your suffering!"),
(38113,2,0,14,16737,100,"marwyn SAY_DEATH","Yes... Run... Run to meet your destiny... Its bitter, cold embrace, awaits you."),
(38113,3,0,14,16739,100,"marwyn SAY_CORRUPTED_FLESH_1","Your flesh has decayed before your very eyes!"),
(38113,3,1,14,16740,100,"marwyn SAY_CORRUPTED_FLESH_2","Waste away into nothingness!");

-- jaina or sylvanas halls of reflection
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1668043 AND -1668001;
DELETE FROM `creature_text` WHERE `entry` IN (37221,37225,37223,37226,38113) OR (`entry`=38112 AND `groupid` IN (5,6));
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
-- Jaina
(37221,0,0,14,16631,100,"Jaina SAY_JAINA_INTRO_1","The chill of this place... Brr... I can feel my blood freezing."),
(37221,1,0,14,16632,100,"Jaina SAY_JAINA_INTRO_2","What is that? Up ahead! Could it be... ? Heroes at my side!"),
(37221,2,0,14,16633,100,"Jaina SAY_JAINA_INTRO_3","Frostmourne! The blade that destroyed our kingdom..."),
(37221,3,0,14,16634,100,"Jaina SAY_JAINA_INTRO_4","Stand back! Touch that blade and your soul will be scarred for all eternity! I must attempt to commune with the spirits locked away within Frostmourne. Give me space, back up please!"),
(37221,4,0,12,16635,100,"Jaina SAY_JAINA_INTRO_5","Uther! Dear Uther! ... I... I'm so sorry."),
(37221,5,0,12,16636,100,"Jaina SAY_JAINA_INTRO_6","Arthas is here? Maybe I..."),
(37221,6,0,12,16637,100,"Jaina SAY_JAINA_INTRO_7","But Uther, if there's any hope of reaching Arthas. I... I must try."),
(37221,7,0,12,16638,100,"Jaina SAY_JAINA_INTRO_8","Tell me how, Uther? How do I destroy my prince? My..."),
(37221,8,0,12,16639,100,"Jaina SAY_JAINA_INTRO_9","You're right, Uther. Forgive me. I... I don't know what got a hold of me. We will deliver this information to the King and the knights that battle the Scourge within Icecrown Citadel."),
(37221,9,0,12,16640,100,"Jaina SAY_JAINA_INTRO_10","Who could bear such a burden?"),
(37221,10,0,12,16641,100,"Jaina SAY_JAINA_INTRO_11","Then maybe there is still hope..."),
(37221,11,0,14,16642,100,"Jaina SAY_JAINA_INTRO_END","You won't deny me this Arthas! I must know! I must find out!"),
-- Lich King
(37226,0,0,14,17225,100,"Lich King SAY_LK_INTRO_1","SILENCE, PALADIN!"),
(37226,1,0,14,17226,100,"Lich King SAY_LK_INTRO_2","So you wish to commune with the dead? You shall have your wish."),
(37226,2,0,14,17227,100,"Lich King SAY_LK_INTRO_3","Falric. Marwyn. Bring their corpses to my chamber when you are through."),
-- Marwyn
(38113,0,0,14,16741,100,"Marwyn SAY_MARWYN_INTRO_1","As you wish, my lord."),
-- Falric
(38112,5,0,14,16717,100,"Falric SAY_FALRIC_INTRO_1","As you wish, my lord."),
(38112,6,0,14,16714,100,"Falric SAY_FALRIC_INTRO_2","Soldiers of Lordaeron, rise to meet your master's call!"),
-- Sylvanas
(37223,0,0,14,17049,100,"Sylvanas SAY_SYLVANAS_INTRO_1","I... I don't believe it! Frostmourne stands before us, unguarded! Just as the Gnome claimed. Come, heroes!"),
(37223,1,0,14,17050,100,"Sylvanas SAY_SYLVANAS_INTRO_2","Standing this close to the blade that ended my life... The pain... It is renewed."),
(37223,2,0,14,17051,100,"Sylvanas SAY_SYLVANAS_INTRO_3","I dare not touch it. Stand back! Stand back as I attempt to commune with the blade! Perhaps our salvation lies within..."),
(37223,3,0,12,17052,100,"Sylvanas SAY_SYLVANAS_INTRO_4","Uther...Uther the Lightbringer. How..."),
(37223,4,0,12,17053,100,"Sylvanas SAY_SYLVANAS_INTRO_5","The Lich King is here? Then my destiny shall be fulfilled today!"),
(37223,5,0,12,17054,100,"Sylvanas SAY_SYLVANAS_INTRO_6","There must be a way... "),
(37223,6,0,12,17055,100,"Sylvanas SAY_SYLVANAS_INTRO_7","Who could bear such a burden?"),
(37223,7,0,12,17056,100,"Sylvanas SAY_SYLVANAS_INTRO_8","The Frozen Throne..."),
(37223,8,0,14,17057,100,"Sylvanas SAY_SYLVANAS_INTRO_END","You will not escape me that easily, Arthas! I will have my vengeance!"),
-- Uther
(37225,0,0,14,16666,100,"Uther SAY_UTHER_INTRO_A2_1","Jaina! Could it truly be you?"),
(37225,1,0,12,16667,100,"Uther SAY_UTHER_INTRO_A2_2","Jaina you haven't much time. The Lich King sees what the sword sees. He will be here shortly!"),
(37225,2,0,12,16668,100,"Uther SAY_UTHER_INTRO_A2_3","No, girl. Arthas is not here. Arthas is merely a presence within the Lich King's mind. A dwindling presence..."),
(37225,3,0,12,16669,100,"Uther SAY_UTHER_INTRO_A2_4","Jaina, listen to me. You must destroy the Lich King. You cannot reason with him. He will kill you and your allies and raise you all as powerful soldiers of the Scourge."),
(37225,4,0,12,16670,100,"Uther SAY_UTHER_INTRO_A2_5","Snap out of it, girl. You must destroy the Lich King at the place where he merged with Ner'zhul - atop the spire, at the Frozen Throne. It is the only way."),
(37225,5,0,12,16671,100,"Uther SAY_UTHER_INTRO_A2_6","There is... something else that you should know about the Lich King. Control over the Scourge must never be lost. Even if you were to strike down the Lich King, another would have to take his place. For without the control of its master, the Scourge would run rampant across the world - destroying all living things."),
(37225,6,0,12,16672,100,"Uther SAY_UTHER_INTRO_A2_7","A grand sacrifice by a noble soul..."),
(37225,7,0,12,16673,100,"Uther SAY_UTHER_INTRO_A2_8","I do not know, Jaina. I suspect that the piece of Arthas that might be left inside the Lich King is all that holds the Scourge from annihilating Azeroth."),
(37225,8,0,12,16674,100,"Uther SAY_UTHER_INTRO_A2_9","No, Jaina! Aargh! He... He is coming! You... You must..."),
(37225,9,0,12,16659,100,"Uther SAY_UTHER_INTRO_H2_1","Careful, girl. I've heard talk of that cursed blade saving us before. Look around you and see what has been born of Frostmourne."),
(37225,10,0,12,16660,100,"Uther SAY_UTHER_INTRO_H2_2","You haven't much time. The Lich King sees what the sword sees. He will be here shortly."),
(37225,11,0,12,16661,100,"Uther SAY_UTHER_INTRO_H2_3","You cannot defeat the Lich King. Not here. You would be a fool to try. He will kill those who follow you and raise them as powerful servants of the Scourge. But for you, Sylvanas, his reward for you would be worse than the last."),
(37225,12,0,12,16662,100,"Uther SAY_UTHER_INTRO_H2_4","Perhaps, but know this: there must always be a Lich King. Even if you were to strike down Arthas, another would have to take his place, for without the control of the Lich King, the Scourge would wash over this world like locusts, destroying all that they touched."),
(37225,13,0,12,16663,100,"Uther SAY_UTHER_INTRO_H2_5","I do not know, Banshee Queen. I suspect that the piece of Arthas that might be left inside the Lich King is all that holds the Scourge from annihilating Azeroth."),
(37225,14,0,12,16664,100,"Uther SAY_UTHER_INTRO_H2_6","Alas, the only way to defeat the Lich King is to destroy him at the place he was created."),
(37225,15,0,12,16665,100,"Uther SAY_UTHER_INTRO_H2_7","I... Aargh... He... He is coming... You... You must...");

-- Some deletions for halls of reflection
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1658041 AND -1658030;
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1658018 AND -1658010;
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1658021 AND -1658020;
DELETE FROM `script_texts` WHERE `entry`=-1658007;

-- Krick
DELETE FROM `creature_text` WHERE `entry`=36477;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(36477,0,0,14,16926,100,"Krick SAY_AGGRO","Our work must not be interrupted! Ick! Take care of them!"),
(36477,1,0,14,16927,100,"Krick SAY_SLAY_1","Ooh...We could probably use these parts!"),
(36477,1,1,14,16928,100,"Krick SAY_SLAY_2","Arms and legs are in short supply...Thanks for your contribution!"),
(36477,2,0,14,16929,100,"Krick SAY_BARRAGE_1","Enough moving around! Hold still while I blow them all up!"),
(36477,3,0,41,0,100,"Krick SAY_BARRAGE_2","Krick begins rapidly conjuring explosive mines!"),
(36477,4,0,14,16930,100,"Krick SAY_POISON_NOVA","Quickly! Poison them all while they're still close!"),
(36477,5,0,14,16931,100,"Krick SAY_CHASE_1","No! That one! That one! Get that one!"),
(36477,5,1,14,16932,100,"Krick SAY_CHASE_2","I've changed my mind...go get that one instead!"),
(36477,5,2,14,16933,100,"Krick SAY_CHASE_3","What are you attacking him for? The dangerous one is over there,fool!"),
(36477,6,0,14,16934,100,"Krick SAY_KRICK_OUTRO_1","Wait! Stop! Don't kill me, please! I'll tell you everything!"),
(36477,7,0,14,16935,100,"Krick SAY_KRICK_OUTRO_3","What you seek is in the master's lair, but you must destroy Tyrannus to gain entry. Within the Halls of Reflection you will find Frostmourne. It... it holds the truth."),
(36477,8,0,14,16936,100,"Krick SAY_KRICK_OUTRO_5","I swear it is true! Please, don't kill me!!"),
(36477,9,0,14,16937,100,"Krick SAY_KRICK_OUTRO_8","Urg... no!!");

-- Ick
DELETE FROM `creature_text` WHERE `entry`=36476;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(36476,0,0,41,0,100,"Ick SAY_ICK_POISON_NOVA","Ick begins to unleash a toxic poison cloud!"),
(36476,1,0,41,0,100,"Ick SAY_ICK_CHASE_1","Ick is chasing you!");

-- Tyrannus
DELETE FROM `creature_text` WHERE `entry`=36658;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(36658,0,0,14,16752,100,"Tyrannus SAY_TYRANNUS_DEATH","Another shall take his place. You waste your time."),
(36658,1,0,14,16753,100,"Tyrannus SAY_TYRANNUS_OUTRO_7","Worthless gnat! Death is all that awaits you!"),
(36658,2,0,14,16754,100,"Tyrannus SAY_TYRANNUS_OUTRO_9","Do not think that I shall permit you entry into my master's sanctum so easily. Pursue me if you dare."),
(36658,3,0,14,16755,100,"Tyrannus SAY_AMBUSH_1","Your pursuit shall be in vain, adventurers, for the Lich King has placed an army of undead at my command! Behold!"),
(36658,4,0,14,16756,100,"Tyrannus SAY_AMBUSH_2","Persistent whelps! You will not reach the entrance of my lord's lair! Soldiers, destroy them!"),
(36658,5,0,14,16757,100,"Tyrannus SAY_GAUNTLET_START","Rimefang! Trap them within the tunnel! Bury them alive!"),
(36658,6,0,14,16758,100,"Tyrannus SAY_TYRANNUS_INTRO_1","Alas, brave, brave adventurers, your meddling has reached its end. Do you hear the clatter of bone and steel coming up the tunnel behind you? That is the sound of your impending demise."),
(36658,7,0,14,16759,100,"Tyrannus SAY_TYRANNUS_INTRO_3","Ha, such an amusing gesture from the rabble. When I have finished with you, my master's blade will feast upon your souls. Die!"),
(36658,8,0,14,16760,100,"Tyrannus SAY_AGGRO","I shall not fail The Lich King! Come and meet your end!"),
(36658,9,0,14,16761,100,"Tyrannus SAY_SLAY_1","Such a shameful display... You are better off dead!"),
(36658,9,1,14,16762,100,"Tyrannus SAY_SLAY_2","Perhaps you should have stayed in the mountains!"),
(36658,10,0,14,16763,100,"Tyrannus SAY_DEATH","Impossible! Rimefang... Warn..."),
(36658,11,0,14,16764,100,"Tyrannus SAY_MARK_RIMEFANG_1","Rimefang, destroy this fool!"),
(36658,12,0,41,0,100,"Tyrannus SAY_MARK_RIMEFANG_2","The frostwyrm Rimefang gazes at $N and readies an icy attack!"),
(36658,13,0,14,16765,100,"Tyrannus SAY_DARK_MIGHT_1","Power... overwhelming!"),
(36658,14,0,41,0,100,"Tyrannus SAY_DARK_MIGHT_2","Scourgelord Tyrannus roars and swells with dark might!");

-- Gorkun
DELETE FROM `creature_text` WHERE `entry`=37592;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(37592,0,0,14,17150,100,"Gorkun SAY_GORKUN_INTRO_2","Heroes! We will hold off the undead as long as we can, even to our dying breath. Deal with the Scourgelord!"),
(37592,1,0,14,0,100,"Gorkun SAY_GORKUN_OUTRO_1","Brave champions, we owe you our lives, our freedom... Though it be a tiny gesture in the face of this enormous debt, I pledge that from this day forth, all will know of your deeds, and the blazing path of light you cut through the shadow of this dark citadel."),
(37592,2,0,14,0,100,"Gorkun SAY_GORKUN_OUTRO_2","This day will stand as a testament not only to your valor, but to the fact that no foe, not even the Lich King himself, can stand when Alliance and Horde set aside their differences and ---");

-- Jaina
DELETE FROM `creature_text` WHERE `entry`=36993;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(36993,0,0,14,16611,100,"Jaina SAY_JAINA_OUTRO_2","I'm not so naive as to believe your appeal for clemency, but I will listen."),
(36993,1,0,14,16612,100,"Jaina SAY_JAINA_OUTRO_4","Frostmourne lies unguarded? Impossible!"),
(36993,2,0,14,16613,100,"Jaina SAY_JAINA_OUTRO_10","What a cruel end. Come, heroes. We must see if the gnome's story is true. If we can separate Arthas from Frostmourne, we might have a chance at stopping him."),
(36993,3,0,14,16614,100,"Jaina SAY_JAYNA_OUTRO_3","Heroes, to me!"),
(36993,4,0,12,16615,100,"Jaina SAY_JAYNA_OUTRO_4","The Frost Queen is gone. We must keep moving - our objective is near."),
(36993,5,0,12,16616,100,"Jaina SAY_JAYNA_OUTRO_5","I... I could not save them... Damn you, Arthas! DAMN YOU!");

-- Sylvanas
DELETE FROM `creature_text` WHERE `entry`=36990;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(36990,0,0,14,17033,100,"Sylvanas SAY_SYLVANAS_OUTRO_2","Why should the Banshee Queen spare your miserable life?"),
(36990,1,0,14,17034,100,"Sylvanas SAY_SYLVANAS_OUTRO_4","Frostmourne? The Lich King is never without his blade! If you are lying to me..."),
(36990,2,0,14,17035,100,"Sylvanas SAY_SYLVANAS_OUTRO_10","A fitting end for a traitor. Come, we must free the slaves and see what is within the Lich King's chamber for ourselves."),
(36990,3,0,14,17037,100,"Sylvanas SAY_SYLVANAS_OUTRO_3","Take cover behind me! Quickly!"),
(36990,4,0,12,17036,100,"Sylvanas SAY_SYLVANAS_OUTRO_4","I thought he'd never shut up. At last, Sindragosa silenced that long-winded fool. To the Halls of Reflection, champions! Our objective is near... I can sense it.");

-- emily
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1800013 AND -1800001;
DELETE FROM `creature_text` WHERE `entry`=26588;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(26588,0,0,12,0,100,"emily SAY_WORGHAGGRO1","Um... I think one of those wolves is back..."),
(26588,1,0,12,0,100,"emily SAY_WORGHAGGRO2","He's going for Mr. Floppy! "),
(26588,2,0,12,0,100,"emily SAY_WORGRAGGRO3","Oh, no! Look, it's another wolf, and it's a biiiiiig one!"),
(26588,3,0,12,0,100,"emily SAY_WORGRAGGRO4","He's gonna eat Mr. Floppy! You gotta help Mr. Floppy! You just gotta!"),
(26588,4,0,12,0,100,"emily SAY_RANDOMAGGRO","There's a big meanie attacking Mr. Floppy! Help! "),
(26588,5,0,12,0,100,"emily SAY_VICTORY1","Let's get out of here before more wolves find us!"),
(26588,6,0,12,0,100,"emily SAY_VICTORY2","Don't go toward the light, Mr. Floppy!"),
(26588,7,0,12,0,100,"emily SAY_VICTORY3","Mr. Floppy, you're ok! Thank you so much for saving Mr. Floppy!"),
(26588,8,0,12,0,100,"emily SAY_VICTORY4","I think I see the camp! We're almost home, Mr. Floppy! Let's go!"),
(26588,9,0,15,0,100,"emily TEXT_EMOTE_WP1","Mr. Floppy revives"),
(26588,10,0,15,0,100,"emily TEXT_EMOTE_AGGRO","The Ravenous Worg chomps down on Mr. Floppy"),
(26588,11,0,12,0,100,"emily SAY_QUEST_ACCEPT","Are you ready, Mr. Floppy? Stay close to me and watch out for those wolves!"),
(26588,12,0,12,0,100,"emily SAY_QUEST_COMPLETE","Thank you for helping me get back to the camp. Go tell Walter that I'm safe now!");

-- venture co straggler
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1603539 AND -1603535;
DELETE FROM `creature_text` WHERE `entry`=27570;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(27570,0,0,12,0,100,"venture co straggler SAY1","We're all gonna die!"),
(27570,0,1,12,0,100,"venture co straggler SAY2","Gotta get out of here!"),
(27570,0,2,12,0,100,"venture co straggler SAY3","No way I'm stickin' around!"),
(27570,0,3,12,0,100,"venture co straggler SAY4","Forget this! I'm going home!"),
(27570,0,4,12,0,100,"venture co straggler SAY5","I didn't sign up for this!");

-- wounded skirmisher
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1800046 AND -1800044;
DELETE FROM `creature_text` WHERE `entry`=27463;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(27463,0,0,12,0,100,"wounded skirmisher RANDOM_SAY_1","Ahh..better.."),
(27463,0,1,12,0,100,"wounded skirmisher RANDOM_SAY_2","Whoa.. i nearly died there. Thank you, $Race!"),
(27463,0,2,12,0,100,"wounded skirmisher RANDOM_SAY_3","Thank you. $Class!");

-- Gal'darah
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1604009 AND -1604000;
DELETE FROM `creature_text` WHERE `entry`=29306;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(29306,0,0,12,0,100,"Gal'darah SAY_AGGRO","I'm gonna spill your guts, mon!"),
(29306,1,0,12,0,100,"Gal'darah SAY_SLAY_1","What a rush!"),
(29306,1,1,12,0,100,"Gal'darah SAY_SLAY_2","Who needs gods, when WE ARE GODS!"),
(29306,1,2,12,0,100,"Gal'darah SAY_SLAY_3","I told ya so!"),
(29306,2,0,12,0,100,"Gal'darah SAY_DEATH","Even the mighty... can fall."),
(29306,3,0,12,0,100,"Gal'darah SAY_SUMMON_RHINO_1","Gut them! Impale them!"),
(29306,3,1,12,0,100,"Gal'darah SAY_SUMMON_RHINO_2","KILL THEM ALL!"),
(29306,3,2,12,0,100,"Gal'darah SAY_SUMMON_RHINO_3","Say hello to my BIG friend!"),
(29306,4,0,12,0,100,"Gal'darah SAY_TRANSFORM_1","Ain't gonna be nottin' left after this!"),
(29306,5,0,12,0,100,"Gal'darah SAY_TRANSFORM_2","You wanna see power? I'm gonna show you power!");
