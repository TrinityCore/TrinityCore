-- ------------------------------- --
-- Creature text conversion part 8 --
-- ------------------------------- --
-- omrogg
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1540017 AND -1540000;
DELETE FROM `creature_text` WHERE `entry` IN (19523,19524,16809);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(19523,0,0,14,10306,100,"omrogg GoCombat_1","Smash!"),
(19523,1,0,14,10308,100,"omrogg GoCombat_2","If you nice me let you live."),
(19523,2,0,14,10309,100,"omrogg GoCombat_3","Me hungry!"),
(19524,0,0,14,10317,100,"omrogg GoCombatDelay_1","Why don't you let me do the talking?"),
(19524,1,0,14,10318,100,"omrogg GoCombatDelay_2","No, we will NOT let you live!"),
(19524,2,0,14,10319,100,"omrogg GoCombatDelay_3","You always hungry. That why we so fat!"),
(19523,3,0,14,10303,100,"omrogg Threat_1","You stay here. Me go kill someone else!"),
(19524,3,0,14,10315,100,"omrogg Threat_2","What are you doing!"),
(19523,4,0,14,10302,100,"omrogg Threat_3","Me kill someone else..."),
(19523,5,0,14,10300,100,"omrogg Threat_4","Me not like this one..."),
(19524,4,0,14,10314,100,"omrogg ThreatDelay1_1","That's not funny!"),
(19523,6,0,14,10305,100,"omrogg ThreatDelay1_2","Me get bored..."),
(19524,5,0,14,10313,100,"omrogg ThreatDelay1_3","I'm not done yet, idiot!"),
(19524,6,0,14,10312,100,"omrogg ThreatDelay1_4","Hey you numbskull!"),
(19523,7,0,14,10304,100,"omrogg ThreatDelay2_1","Ha ha ha."),
(19524,7,0,14,10316,100,"omrogg ThreatDelay2_2","Whhy! He almost dead!"),
(19523,8,0,14,10307,100,"omrogg ThreatDelay2_3","H'ey..."),
(19523,9,0,14,10301,100,"omrogg ThreatDelay2_4","We kill his friend!"),
(19523,10,0,14,10310,100,"omrogg Killing_1","This one die easy!"),
(19524,8,0,14,10320,100,"omrogg Killing_2","I'm tired. You kill next one!"),
(19524,9,0,14,10321,100,"omrogg KillingDelay_1","That's because I do all the hard work!"),
(19523,11,0,14,10321,100,"omrogg KillingDelay_2","That's because I do all the hard work!"),
(16809,0,0,14,10311,100,"omrogg YELL_DIE_L","This all...your fault!"),
(16809,1,0,14,10322,100,"omrogg YELL_DIE_R","I...hate...you..."),
(16809,2,0,16,0,100,"omrogg EMOTE_ENRAGE","%s enrages");

-- kargath
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1540047 AND -1540042;
DELETE FROM `creature_text` WHERE `entry`=16808;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16808,0,0,14,10323,100,"kargath SAY_AGGRO1","Ours is the true Horde! The only Horde!"),
(16808,0,1,14,10324,100,"kargath SAY_AGGRO2","I'll carve the meat from your bones!"),
(16808,0,2,14,10325,100,"kargath SAY_AGGRO3","I am called Bladefist for a reason, as you will see!"),
(16808,1,0,14,10326,100,"kargath SAY_SLAY1","For the real Horde!"),
(16808,1,1,14,10327,100,"kargath SAY_SLAY2","I am the only Warchief!"),
(16808,2,0,14,10328,100,"kargath SAY_DEATH","The true Horde... will.. prevail...");

-- aeranas
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000139 AND -1000138;
DELETE FROM `creature_text` WHERE `entry`=17085;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17085,0,0,12,0,100,"aeranas SAY_SUMMON","Avruu's magic... it still controls me. You must fight me, mortal. It's the only way to break the spell!"),
(17085,1,0,12,0,100,"aeranas SAY_FREE","Avruu's magic is broken! I'm free once again!");

-- ancestral wolf
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000498 AND -1000496;
DELETE FROM `creature_text` WHERE `entry` IN (17077,17023);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17077,0,0,16,0,100,"ancestral wolf EMOTE_WOLF_LIFT_HEAD","%s lifts its head into the air, as if listening for something."),
(17077,1,0,16,0,100,"ancestral wolf EMOTE_WOLF_HOWL","%s lets out a howl that rings across the mountains to the north and motions for you to follow."),
(17023,0,0,12,0,100,"ancestral wolf SAY_WOLF_WELCOME","Welcome, kind spirit. What has brought you to us?");

-- wounded elf
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000122 AND -1000117;
DELETE FROM `creature_text` WHERE `entry`=16993;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(16993,0,0,12,0,100,"wounded elf SAY_ELF_START","Thank you for agreeing to help. Now, let's get out of here $N."),
(16993,1,0,12,0,100,"wounded elf SAY_ELF_SUMMON1","Over there! They're following us!"),
(16993,2,0,12,0,100,"wounded elf SAY_ELF_RESTING","Allow me a moment to rest. The journey taxes what little strength I have."),
(16993,3,0,12,0,100,"wounded elf SAY_ELF_SUMMON2","Did you hear something?"),
(16993,4,0,12,0,100,"wounded elf SAY_ELF_COMPLETE","Falcon Watch, at last! Now, where's my... Oh no! My pack, it's missing! Where has -"),
(16993,5,0,12,0,100,"wounded elf SAY_ELF_AGGRO","You won't keep me from getting to Falcon Watch!");

-- maghar
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000488 AND -1000482;
DELETE FROM `creature_text` WHERE `entry` IN (18210,18202,18211);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18210,0,0,12,0,100,"maghar captive SAY_MAG_START","Look out!"),
(18211,0,0,12,0,100,"maghar captive SAY_MAG_NO_ESCAPE","Don't let them escape! Kill the strong one first!"),
(18210,1,0,12,0,100,"maghar captive SAY_MAG_MORE","More of them coming! Watch out!"),
(18202,0,0,12,0,100,"maghar captive SAY_MAG_MORE_REPLY","Where do you think you're going? Kill them all!"),
(18210,2,0,12,0,100,"maghar captive SAY_MAG_LIGHTNING","Ride the lightning, filth!"),
(18210,3,0,12,0,100,"maghar captive SAY_MAG_SHOCK","FROST SHOCK!!!"),
(18210,4,0,12,0,100,"maghar captive SAY_MAG_COMPLETE","It is best that we split up now, in case they send more after us. Hopefully one of us will make it back to Garrosh. Farewell stranger.");

-- corki
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1800073 AND -1800071;
DELETE FROM `creature_text` WHERE `entry` IN (18445,20812,18369);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18445,0,0,12,0,100,"corki NPC_CORKI","Thanks, $C! I'm sure my dad will reward you greatly! Bye!"),
(20812,0,0,12,0,100,"corki NPC_CORKI_2","This is the last time I get caught!I promise! Bye!"),
(18369,0,0,12,0,100,"corki NPC_CORKI_3","Thank you for saving me again!");

-- manaforge_control
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000216 AND -1000211;
DELETE FROM `creature_text` WHERE `entry` IN (20209,20417,20418,20440);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(20209,0,0,16,0,100,"manaforge_control EMOTE_START","Warning! %s emergency shutdown process initiated by $N. Shutdown will complete in two minutes."),
(20209,1,0,16,0,100,"manaforge_control EMOTE_60","Emergency shutdown will complete in one minute."),
(20209,2,0,16,0,100,"manaforge_control EMOTE_30","Emergency shutdown will complete in thirty seconds."),
(20209,3,0,16,0,100,"manaforge_control EMOTE_10","Emergency shutdown will complete in ten seconds."),
(20209,4,0,16,0,100,"manaforge_control EMOTE_COMPLETE","Emergency shutdown complete."),
(20209,5,0,16,0,100,"manaforge_control EMOTE_ABORT","Emergency shutdown aborted."),
(20417,0,0,16,0,100,"manaforge_control EMOTE_START","Warning! %s emergency shutdown process initiated by $N. Shutdown will complete in two minutes."),
(20417,1,0,16,0,100,"manaforge_control EMOTE_60","Emergency shutdown will complete in one minute."),
(20417,2,0,16,0,100,"manaforge_control EMOTE_30","Emergency shutdown will complete in thirty seconds."),
(20417,3,0,16,0,100,"manaforge_control EMOTE_10","Emergency shutdown will complete in ten seconds."),
(20417,4,0,16,0,100,"manaforge_control EMOTE_COMPLETE","Emergency shutdown complete."),
(20417,5,0,16,0,100,"manaforge_control EMOTE_ABORT","Emergency shutdown aborted."),
(20418,0,0,16,0,100,"manaforge_control EMOTE_START","Warning! %s emergency shutdown process initiated by $N. Shutdown will complete in two minutes."),
(20418,1,0,16,0,100,"manaforge_control EMOTE_60","Emergency shutdown will complete in one minute."),
(20418,2,0,16,0,100,"manaforge_control EMOTE_30","Emergency shutdown will complete in thirty seconds."),
(20418,3,0,16,0,100,"manaforge_control EMOTE_10","Emergency shutdown will complete in ten seconds."),
(20418,4,0,16,0,100,"manaforge_control EMOTE_COMPLETE","Emergency shutdown complete."),
(20418,5,0,16,0,100,"manaforge_control EMOTE_ABORT","Emergency shutdown aborted."),
(20440,0,0,16,0,100,"manaforge_control EMOTE_START","Warning! %s emergency shutdown process initiated by $N. Shutdown will complete in two minutes."),
(20440,1,0,16,0,100,"manaforge_control EMOTE_60","Emergency shutdown will complete in one minute."),
(20440,2,0,16,0,100,"manaforge_control EMOTE_30","Emergency shutdown will complete in thirty seconds."),
(20440,3,0,16,0,100,"manaforge_control EMOTE_10","Emergency shutdown will complete in ten seconds."),
(20440,4,0,16,0,100,"manaforge_control EMOTE_COMPLETE","Emergency shutdown complete."),
(20440,5,0,16,0,100,"manaforge_control EMOTE_ABORT","Emergency shutdown aborted.");

-- dawnforge
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000137 AND -1000128;
DELETE FROM `creature_text` WHERE `entry` IN (19830,21504,19831);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(19830,0,0,12,0,100,"dawnforge SAY_ARCANIST_ARDONIS_1","You cannot be serious! We are severely understaffed and can barely keep this manaforge functional!"),
(19830,1,0,12,0,100,"dawnforge SAY_ARCANIST_ARDONIS_2","Yes, my lord."),
(21504,0,0,12,0,100,"dawnforge SAY_PATHALEON_CULATOR_IMAGE_1","Indeed, it is not a request."),
(21504,1,0,12,0,100,"dawnforge SAY_PATHALEON_CULATOR_IMAGE_2","Duro will be reinforced! Ultris was a complete disaster. I will NOT have that mistake repeated!"),
(21504,2,0,12,0,100,"dawnforge SAY_PATHALEON_CULATOR_IMAGE_2_1","We've had too many setbacks along the way: Hellfire Citadel, Fallen Sky Ridge, Firewing Point... Prince Kael'thas will tolerate no further delays. I will tolerate nothing other than complete success!"),
(21504,3,0,12,0,100,"dawnforge SAY_PATHALEON_CULATOR_IMAGE_2_2","I am returning to Tempest Keep. See to it that I do not have reason to return!"),
(19831,0,0,12,0,100,"dawnforge SAY_COMMANDER_DAWNFORGE_1","We need you to send reinforcements to Manaforge Duro, Ardonis. This is not a request, it's an order."),
(19831,1,0,12,0,100,"dawnforge SAY_COMMANDER_DAWNFORGE_2","You will do as ordered. Manaforge Duro has come under heavy attack by mana creatures and the situation is out of control. Failure to comply will not be tolerated!"),
(19831,2,0,12,0,100,"dawnforge SAY_COMMANDER_DAWNFORGE_3","My lord!"),
(19831,3,0,12,0,100,"dawnforge SAY_COMMANDER_DAWNFORGE_4","Yes, my lord."),
(19831,4,0,12,0,100,"dawnforge SAY_COMMANDER_DAWNFORGE_5","See to it, Ardonis!");

-- bessy
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000525 AND -1000524;
DELETE FROM `creature_text` WHERE `entry`=20415;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(20415,0,0,12,0,100,"bessy SAY_THADELL_1","Bessy, is that you?"),
(20415,1,0,12,0,100,"bessy SAY_THADELL_2","Thank you for bringing back my Bessy, $N. I couldn't live without her!");

-- mature netherwing drake
DELETE FROM `script_texts` WHERE `entry`=-1000175;
DELETE FROM `creature_text` WHERE `entry`=21648;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(21648,0,0,12,0,100,"mature netherwing drake SAY_JUST_EATEN","Thank you, mortal.");

-- overlord morghor
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000621 AND -1000606;
DELETE FROM `creature_text` WHERE `entry` IN (23139,22083,23141);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(23139,0,0,12,0,100,"overlord morghor OVERLORD_SAY_1","Come, $N. Lord Stormrage awaits."),
(23139,1,0,12,0,100,"overlord morghor OVERLORD_SAY_2","Lord Illidan will be here shortly."),
(23139,3,0,12,0,100,"overlord morghor OVERLORD_SAY_4","But... My lord, I do not understand. $N... He is the orc that has..."),
(23139,4,0,12,0,100,"overlord morghor OVERLORD_SAY_5","It will be done, my lord."),
(23139,5,0,12,0,100,"overlord morghor OVERLORD_SAY_6","So you thought to make a fool of Mor'ghor, eh? Before you are delivered to Lord Illidan, you will feel pain that you could not know to exist. I will take pleasure in exacting my own vengeance."),
(23139,6,0,14,0,100,"overlord morghor OVERLORD_YELL_1","Warriors of Dragonmaw, gather 'round! One among you has attained the rank of highlord! Bow your heads in reverence! Show your respect and allegiance to Highlord $N!"),
(23139,7,0,14,0,100,"overlord morghor OVERLORD_YELL_2","All hail Lord Illidan!"),
(22083,0,0,12,0,100,"overlord morghor LORD_ILLIDAN_SAY_1","What is the meaning of this, Mor'ghor?"),
(22083,1,0,12,0,100,"overlord morghor LORD_ILLIDAN_SAY_2","SILENCE!"),
(22083,2,0,12,0,100,"overlord morghor LORD_ILLIDAN_SAY_3","Blathering idiot. You incomprehensibly incompetent buffoon..."),
(22083,3,0,12,0,100,"overlord morghor LORD_ILLIDAN_SAY_4","THIS is your hero?"),
(22083,4,0,12,0,100,"overlord morghor LORD_ILLIDAN_SAY_5","You have been deceived, imbecile."),
(22083,5,0,12,0,100,"overlord morghor LORD_ILLIDAN_SAY_6","This... whole... operation... HAS BEEN COMPROMISED!"),
(22083,6,0,12,0,100,"overlord morghor LORD_ILLIDAN_SAY_7","I expect to see this insect's carcass in pieces in my lair within the hour. Fail and you will suffer a fate so much worse than death."),
(23141,0,0,12,0,100,"overlord morghor YARZILL_THE_MERC_SAY","You will not harm the boy, Mor'ghor! Quickly, $N, climb on my back!");

-- wilda
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000390 AND -1000381;
DELETE FROM `creature_text` WHERE `entry`=21027;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(21027,0,0,12,0,100,"wilda SAY_WIL_START","I sense the tortured spirits, $n. They are this way, come quickly!"),
(21027,1,0,12,0,100,"wilda SAY_WIL_AGGRO1","Watch out!"),
(21027,1,1,12,0,100,"wilda SAY_WIL_AGGRO2","Naga attackers! Defend yourself!"),
(21027,2,0,12,0,100,"wilda SAY_WIL_PROGRESS1","Grant me protection $n, I must break trough their foul magic!"),
(21027,3,0,12,0,100,"wilda SAY_WIL_PROGRESS2","The naga of Coilskar are exceptionally cruel to their prisoners. It is a miracle that I survived inside that watery prison for as long as I did. Earthmother be praised."),
(21027,3,1,12,0,100,"wilda SAY_WIL_PROGRESS4","Lady Vashj must answer for these atrocities. She must be brought to justice!"),
(21027,3,2,12,0,100,"wilda SAY_WIL_PROGRESS5","The tumultuous nature of the great waterways of Azeroth and Draenor are a direct result of tormented water spirits."),
(21027,4,0,12,0,100,"wilda SAY_WIL_FIND_EXIT","Now we must find the exit."),
(21027,5,0,12,0,100,"wilda SAY_WIL_JUST_AHEAD","It shouldn't be much further, $n. The exit is just up ahead."),
(21027,6,0,12,0,100,"wilda SAY_WIL_END","Thank you, $n. Please return to my brethren at the Altar of Damnation, near the Hand of Gul'dan, and tell them that Wilda is safe. May the Earthmother watch over you...");

-- kservant
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000255 AND -1000234;
DELETE FROM `creature_text` WHERE `entry`=19685;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(19685,0,0,12,0,100,"kservant SAY_KHAD_SERV_0","Follow me, stranger. This won't take long."),
(19685,1,0,15,0,100,"kservant SAY_KHAD_SERV_1","Shattrath was once the draenei capital of this world. Its name means \"dwelling of light.\""),
(19685,2,0,15,0,100,"kservant SAY_KHAD_SERV_2","When the Burning Legion turned the orcs against the draenei, the fiercest battle was fought here. The draenei fought tooth and nail, but in the end the city fell."),
(19685,3,0,15,0,100,"kservant SAY_KHAD_SERV_3","The city was left in ruins and darkness... until the Sha'tar arrived."),
(19685,4,0,15,0,100,"kservant SAY_KHAD_SERV_4","Let us go into the Lower City. I will warn you that as one of the only safe havens in Outland, Shattrath has attracted droves of refugees from all wars, current and past."),
(19685,5,0,15,0,100,"kservant SAY_KHAD_SERV_5","The Sha'tar, or \"born from light\" are the naaru that came to Outland to fight the demons of the Burning Legion."),
(19685,6,0,15,0,100,"kservant SAY_KHAD_SERV_6","They were drawn to the ruins of Shattrath City where a small remnant of the draenei priesthood conducted its rites inside a ruined temple on this very spot."),
(19685,7,0,15,0,100,"kservant SAY_KHAD_SERV_7","The priesthood, known as the Aldor, quickly regained its strength as word spread that the naaru had returned and reconstruction soon began. The ruined temple is now used as an infirmary for injured refugees."),
(19685,8,0,15,0,100,"kservant SAY_KHAD_SERV_8","It wouldn't be long, however, before the city came under attack once again. This time, the attack came from Illidan's armies. A large regiment of blood elves had been sent by Illidan's ally, Kael'thas Sunstrider, to lay waste to the city."),
(19685,9,0,15,0,100,"kservant SAY_KHAD_SERV_9","As the regiment of blood elves crossed this very bridge, the Aldor's exarchs and vindicators lined up to defend the Terrace of Light. But then the unexpected happened."),
(19685,10,0,15,0,100,"kservant SAY_KHAD_SERV_10","The blood elves laid down their weapons in front of the city's defenders; their leader, a blood elf elder known as Voren'thal, stormed into the Terrace of Light and demanded to speak to A'dal."),
(19685,11,0,15,0,100,"kservant SAY_KHAD_SERV_11","As the naaru approached him, Voren'thal kneeled before him and uttered the following words: \"I've seen you in a vision, naaru. My race's only hope for survival lies with you. My followers and I are here to serve you.\""),
(19685,12,0,15,0,100,"kservant SAY_KHAD_SERV_12","The defection of Voren'thal and his followers was the largest loss ever incurred by Kael's forces. And these weren't just any blood elves. Many of the best and brightest amongst Kael's scholars and magisters had been swayed by Voren'thal's influence."),
(19685,13,0,15,0,100,"kservant SAY_KHAD_SERV_13","The naaru accepted the defectors, who would become known as the Scryers; their dwelling lies in the platform above. Only those initiated with the Scryers are allowed there."),
(19685,14,0,15,0,100,"kservant SAY_KHAD_SERV_14","The Aldor are followers of the Light and forgiveness and redemption are values they understand. However, they found hard to forget the deeds of the blood elves while under Kael's command."),
(19685,15,0,15,0,100,"kservant SAY_KHAD_SERV_15","Many of the priesthood had been slain by the same magisters who now vowed to serve the naaru. They were not happy to share the city with their former enemies."),
(19685,16,0,15,0,100,"kservant SAY_KHAD_SERV_16","The Aldor's most holy temple and its surrounding dwellings lie on the terrace above. As a holy site, only the initiated are welcome inside."),
(19685,17,0,15,0,100,"kservant SAY_KHAD_SERV_17","The attacks against Shattrath continued, but the city did not fall, as you can see. On the contrary, the naaru known as Xi'ri led a successful incursion into Shadowmoon Valley - Illidan's doorstep."),
(19685,18,0,15,0,100,"kservant SAY_KHAD_SERV_18","There he continues to wage war on Illidan with the assistance of the Aldor and the Scryers. The two factions have not given up on their old feuds, though."),
(19685,19,0,15,0,100,"kservant SAY_KHAD_SERV_19","Such is their animosity that they vie for the honor of being sent to assist the naaru there. Each day, that decision is made here by A'dal. The armies gather here to receive A'dal's blessing before heading to Shadowmoon."),
(19685,20,0,15,0,100,"kservant SAY_KHAD_SERV_20","Khadgar should be ready to see you again. Just remember that to serve the Sha'tar you will most likely have to ally with the Aldor or the Scryers. And seeking the favor of one group will cause the others' dislike."),
(19685,21,0,15,0,100,"kservant SAY_KHAD_SERV_21","Good luck stranger, and welcome to Shattrath City.");

-- larry
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000279 AND -1000274;
DELETE FROM `creature_text` WHERE `entry`=19720;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(19720,0,0,12,0,100,"larry SAY_START","Time to teach you a lesson in manners, little $Gboy:girl;!"),
(19720,1,0,12,0,100,"larry SAY_COUNT","Now I'm gonna give you to the count of '3' to get out of here before I sick the dogs on you."),
(19720,2,0,12,0,100,"larry SAY_COUNT_1","1..."),
(19720,3,0,12,0,100,"larry SAY_COUNT_2","2..."),
(19720,4,0,12,0,100,"larry SAY_ATTACK_5","Time to meet your maker!"),
(19720,5,0,12,0,100,"larry SAY_GIVEUP","Alright, we give up! Don't hurt us!");

-- skyriss
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1552009 AND -1552000;
DELETE FROM `creature_text` WHERE `entry`=20912;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(20912,0,0,14,11122,100,"skyriss SAY_INTRO","It is a small matter to control the mind of the weak... for I bear allegiance to powers untouched by time, unmoved by fate. No force on this world or beyond harbors the strength to bend our knee... not even the mighty Legion!"),
(20912,1,0,14,11123,100,"skyriss SAY_AGGRO","Bear witness to the agent of your demise!"),
(20912,2,0,14,11124,100,"skyriss SAY_KILL_1","Your fate is written!"),
(20912,2,1,14,11125,100,"skyriss SAY_KILL_2","The chaos I have sown here is but a taste..."),
(20912,3,0,14,11127,100,"skyriss SAY_MIND_1","You will do my bidding, weakling."),
(20912,3,1,14,11128,100,"skyriss SAY_MIND_2","Your will is no longer your own."),
(20912,4,0,14,11129,100,"skyriss SAY_FEAR_1","Flee in terror!"),
(20912,4,1,14,11130,100,"skyriss SAY_FEAR_2","I will show you horrors undreamed of!"),
(20912,5,0,14,11131,100,"skyriss SAY_IMAGE","We span the universe, as countless as the stars!"),
(20912,6,0,14,11126,100,"skyriss SAY_DEATH","I am merely one of... infinite multitudes.");

-- freywinn
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1553005 AND -1553000;
DELETE FROM `creature_text` WHERE `entry`=17975;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17975,0,0,14,11144,100,"freywinn SAY_AGGRO","What are you doing? These specimens are very delicate!"),
(17975,1,0,14,11145,100,"freywinn SAY_KILL_1","Your life cycle is now concluded!"),
(17975,1,1,14,11146,100,"freywinn SAY_KILL_2","You will feed the worms."),
(17975,2,0,14,11147,100,"freywinn SAY_TREE_1","Endorel aluminor!"),
(17975,2,1,14,11148,100,"freywinn SAY_TREE_2","Nature bends to my will!"),
(17975,3,0,14,11149,100,"freywinn SAY_DEATH","The specimens...must be preserved.");

-- laj
DELETE FROM `script_texts` WHERE `entry`=-1553006;
DELETE FROM `creature_text` WHERE `entry`=17980;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17980,0,0,16,0,100,"laj EMOTE_SUMMON","emits a strange noise.");

-- warp
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1553012 AND -1553007;
DELETE FROM `creature_text` WHERE `entry`=17977;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17977,0,0,14,11230,100,"warp SAY_AGGRO","Who disturbs this sanctuary?"),
(17977,1,0,14,11231,100,"warp SAY_SLAY_1","You must die! But wait: this does not-- No, no... you must die!"),
(17977,1,1,14,11232,100,"warp SAY_SLAY_2","What am I doing? Why do I..."),
(17977,2,0,14,11233,100,"warp SAY_SUMMON_1","Children, come to me!"),
(17977,2,1,14,11234,100,"warp SAY_SUMMON_2","Maybe this is not-- No, we fight! Come to my aid."),
(17977,3,0,14,11235,100,"warp SAY_DEATH","So... confused. Do not... belong here!");

-- solarian
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1550015 AND -1550007;
DELETE FROM `creature_text` WHERE `entry`=18805;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18805,0,0,14,11134,100,"solarian SAY_AGGRO","Tal anu'men no Sin'dorei!"),
(18805,1,0,14,11139,100,"solarian SAY_SUMMON1","Ha ha ha! You are hopelessly outmatched!"),
(18805,2,0,14,11140,100,"solarian SAY_SUMMON2","I will crush your delusions of grandeur!"),
(18805,3,0,14,11136,100,"solarian SAY_KILL1","Your soul belongs to the Abyss!"),
(18805,3,1,14,11137,100,"solarian SAY_KILL2","By the blood of the Highborne!"),
(18805,3,2,14,11138,100,"solarian SAY_KILL3","For the Sunwell!"),
(18805,4,0,14,11135,100,"solarian SAY_DEATH","The warmth of the sun... awaits."),
(18805,5,0,14,0,100,"solarian SAY_VOIDA","Enough of this! Now I call upon the fury of the cosmos itself."),
(18805,6,0,14,0,100,"solarian SAY_VOIDB","I become ONE... with the VOID!");

-- kaelthas
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1550043 AND -1550016;
DELETE FROM `creature_text` WHERE `entry` IN (19622,20064,20060,20062,20063);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(19622,0,0,14,11256,100,"kaelthas SAY_INTRO","Energy. Power. My people are addicted to it... a dependence made manifest after the Sunwell was destroyed. Welcome... to the future. A pity you are too late to stop it. No one can stop me now! Selama ashal'anore!"),
(19622,1,0,14,11257,100,"kaelthas SAY_INTRO_CAPERNIAN","Capernian will see to it that your stay here is a short one."),
(19622,2,0,14,11258,100,"kaelthas SAY_INTRO_TELONICUS","Well done, you have proven worthy to test your skills against my master engineer, Telonicus."),
(19622,3,0,14,11259,100,"kaelthas SAY_INTRO_THALADRED","Let us see how your nerves hold up against the Darkener, Thaladred."),
(19622,4,0,14,11260,100,"kaelthas SAY_INTRO_SANGUINAR","You have persevered against some of my best advisors... but none can withstand the might of the Blood Hammer. Behold, Lord Sanguinar!"),
(19622,5,0,14,11261,100,"kaelthas SAY_PHASE2_WEAPON","As you see, I have many weapons in my arsenal..."),
(19622,6,0,14,11262,100,"kaelthas SAY_PHASE3_ADVANCE","Perhaps I underestimated you. It would be unfair to make you fight all four advisors at once, but... fair treatment was never shown to my people. I'm just returning the favor."),
(19622,7,0,14,11263,100,"kaelthas SAY_PHASE4_INTRO2","Alas, sometimes one must take matters into one's own hands. Balamore shanal!"),
(19622,8,0,14,11273,100,"kaelthas SAY_PHASE5_NUTS","I have not come this far to be stopped! The future I have planned will not be jeopardized! Now you will taste true power!!"),
(19622,9,0,14,11270,100,"kaelthas SAY_SLAY1","You will not prevail."),
(19622,9,1,14,11271,100,"kaelthas SAY_SLAY2","You gambled...and lost."),
(19622,9,2,14,11272,100,"kaelthas SAY_SLAY3","This was Child's play."),
(19622,10,0,14,11268,100,"kaelthas SAY_MINDCONTROL1","Obey me."),
(19622,10,1,14,11269,100,"kaelthas SAY_MINDCONTROL2","Bow to my will."),
(19622,11,0,14,11264,100,"kaelthas SAY_GRAVITYLAPSE1","Let us see how you fare when your world is turned upside down."),
(19622,11,1,14,11265,100,"kaelthas SAY_GRAVITYLAPSE2","Having trouble staying grounded?"),
(19622,12,0,14,11267,100,"kaelthas SAY_SUMMON_PHOENIX1","Anara'nel belore!"),
(19622,12,1,14,11266,100,"kaelthas SAY_SUMMON_PHOENIX2","By the power of the sun!"),
(19622,13,0,14,11274,100,"kaelthas SAY_DEATH","For...Quel...thalas!"),
(20064,0,0,14,11203,100,"thaladred SAY_THALADRED_AGGRO","Prepare yourselves!"),
(20064,1,0,14,11204,100,"thaladred SAY_THALADRED_DEATH","Forgive me, my prince! I have... failed."),
(20064,2,0,16,0,100,"thaladred EMOTE_THALADRED_GAZE","sets his gaze on $N!"),
(20060,0,0,14,11152,100,"sanguinar SAY_SANGUINAR_AGGRO","Blood for blood!"),
(20060,1,0,14,11153,100,"sanguinar SAY_SANGUINAR_DEATH","NO! I ...will... not..."),
(20062,0,0,14,11117,100,"capernian SAY_CAPERNIAN_AGGRO","The sin'dore reign supreme!"),
(20062,1,0,14,11118,100,"capernian SAY_CAPERNIAN_DEATH","This is not over!"),
(20063,0,0,14,11157,100,"telonicus SAY_TELONICUS_AGGRO","Anar'alah belore!"),
(20063,1,0,14,11158,100,"telonicus SAY_TELONICUS_DEATH","More perils... await");

-- voidreaver
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1550006 AND -1550000;
DELETE FROM `creature_text` WHERE `entry`=19516;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(19516,0,0,14,11213,100,"voidreaver SAY_AGGRO","Alert, you are marked for extermination!"),
(19516,1,0,14,11215,100,"voidreaver SAY_SLAY1","Extermination, successful."),
(19516,1,1,14,11216,100,"voidreaver SAY_SLAY2","Imbecile life form, no longer functional."),
(19516,1,2,14,11217,100,"voidreaver SAY_SLAY3","Threat neutralized."),
(19516,2,0,14,11214,100,"voidreaver SAY_DEATH","Systems... shutting... down..."),
(19516,3,0,14,11218,100,"voidreaver SAY_POUNDING1","Alternative measure commencing..."),
(19516,3,1,14,11219,100,"voidreaver SAY_POUNDING2","Calculating force parameters...");

-- ironhand
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1554012 AND -1554006;
DELETE FROM `creature_text` WHERE `entry`=19710;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(19710,0,0,14,11109,100,"ironhand SAY_AGGRO_1","You have approximately five seconds to live."),
(19710,1,0,14,11112,100,"ironhand SAY_HAMMER_1","With the precise angle and velocity..."),
(19710,1,1,14,11113,100,"ironhand SAY_HAMMER_2","Low tech yet quiet effective!"),
(19710,2,0,14,11110,100,"ironhand SAY_SLAY_1","A foregone conclusion."),
(19710,2,1,14,11111,100,"ironhand SAY_SLAY_2","The processing will continue a schedule!"),
(19710,3,0,14,11114,100,"ironhand SAY_DEATH_1","My calculations did not..."),
(19710,4,0,41,0,100,"ironhand EMOTE_HAMMER","raises his hammer menacingly...");

-- sepethrea
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1554019 AND -1554013;
DELETE FROM `creature_text` WHERE `entry`=19221;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(19221,0,0,14,11186,100,"sepethrea SAY_AGGRO","Don't value your life very much, do you?"),
(19221,1,0,14,11191,100,"sepethrea SAY_SUMMON","I am not alone."),
(19221,2,0,14,11189,100,"sepethrea SAY_DRAGONS_BREATH_1","Think you can take the heat?"),
(19221,2,1,14,11190,100,"sepethrea SAY_DRAGONS_BREATH_2","Anar'endal dracon!"),
(19221,3,0,14,11187,100,"sepethrea SAY_SLAY1","And don't come back!"),
(19221,3,1,14,11188,100,"sepethrea SAY_SLAY2","En'dala finel el'dal"),
(19221,4,0,14,11192,100,"sepethrea SAY_DEATH","Anu... bala belore...alon.");

-- pathaleon
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1554027 AND -1554020;
DELETE FROM `creature_text` WHERE `entry`=19220;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(19220,0,0,14,11193,100,"pathaleon SAY_AGGRO","We are on a strict timetable. You will not interfere!"),
(19220,1,0,14,11197,100,"pathaleon SAY_DOMINATION_1","I'm looking for a team player..."),
(19220,1,1,14,11198,100,"pathaleon SAY_DOMINATION_2","You work for me now!"),
(19220,2,0,14,11196,100,"pathaleon SAY_SUMMON","Time to supplement my work force."),
(19220,3,0,14,11199,100,"pathaleon SAY_ENRAGE","I prefeer to be hands-on..."),
(19220,4,0,14,11194,100,"pathaleon SAY_SLAY_1","A minor inconvenience."),
(19220,4,1,14,11195,100,"pathaleon SAY_SLAY_2","Looks like you lose."),
(19220,5,0,14,11200,100,"pathaleon SAY_DEATH","The project will... continue.");

-- unkor
DELETE FROM `script_texts` WHERE `entry`=-1000194;
DELETE FROM `creature_text` WHERE `entry`=18262;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18262,0,0,12,0,100,"unkor SAY_SUBMIT","I give up! Please don't kill me!");

-- floon
DELETE FROM `script_texts` WHERE `entry`=-1000195;
DELETE FROM `creature_text` WHERE `entry`=18588;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18588,0,0,12,0,100,"floon SAY_FLOON_ATTACK","I choose the third option: KILLING YOU!");

-- isla starmane
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000574 AND -1000571;
DELETE FROM `creature_text` WHERE `entry`=18760;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(18760,0,0,12,0,100,"isla starmane SAY_PROGRESS_1","Ok let's get out of here!"),
(18760,1,0,12,0,100,"isla starmane SAY_PROGRESS_2","You sure you're ready? Take a moment."),
(18760,2,0,12,0,100,"isla starmane SAY_PROGRESS_3","Alright, let's do this!"),
(18760,3,0,12,0,100,"isla starmane SAY_PROGRESS_4","Ok, I think I can make it on my own from here. Thank you so much for breaking me out of there!");

-- guards
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1070003 AND -1070001;
DELETE FROM `creature_text` WHERE `entry` IN (68,1976,3218,3296,3502,4624,9460,11190,15184);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(68,0,0,12,0,100,"SAY_GUARD_SIL_AGGRO1","Taste blade, mongrel!"),
(68,0,1,12,0,100,"SAY_GUARD_SIL_AGGRO2","Please tell me that you didn't just do what I think you just did. Please tell me that I'm not going to have to hurt you..."),
(68,0,2,12,0,100,"SAY_GUARD_SIL_AGGRO3","As if we don't have enough problems, you go and create more!"),
(1976,0,0,12,0,100,"SAY_GUARD_SIL_AGGRO1","Taste blade, mongrel!"),
(1976,0,1,12,0,100,"SAY_GUARD_SIL_AGGRO2","Please tell me that you didn't just do what I think you just did. Please tell me that I'm not going to have to hurt you..."),
(1976,0,2,12,0,100,"SAY_GUARD_SIL_AGGRO3","As if we don't have enough problems, you go and create more!"),
(3218,0,0,12,0,100,"SAY_GUARD_SIL_AGGRO1","Taste blade, mongrel!"),
(3218,0,1,12,0,100,"SAY_GUARD_SIL_AGGRO2","Please tell me that you didn't just do what I think you just did. Please tell me that I'm not going to have to hurt you..."),
(3218,0,2,12,0,100,"SAY_GUARD_SIL_AGGRO3","As if we don't have enough problems, you go and create more!"),
(3296,0,0,12,0,100,"SAY_GUARD_SIL_AGGRO1","Taste blade, mongrel!"),
(3296,0,1,12,0,100,"SAY_GUARD_SIL_AGGRO2","Please tell me that you didn't just do what I think you just did. Please tell me that I'm not going to have to hurt you..."),
(3296,0,2,12,0,100,"SAY_GUARD_SIL_AGGRO3","As if we don't have enough problems, you go and create more!"),
(3502,0,0,12,0,100,"SAY_GUARD_SIL_AGGRO1","Taste blade, mongrel!"),
(3502,0,1,12,0,100,"SAY_GUARD_SIL_AGGRO2","Please tell me that you didn't just do what I think you just did. Please tell me that I'm not going to have to hurt you..."),
(3502,0,2,12,0,100,"SAY_GUARD_SIL_AGGRO3","As if we don't have enough problems, you go and create more!"),
(4624,0,0,12,0,100,"SAY_GUARD_SIL_AGGRO1","Taste blade, mongrel!"),
(4624,0,1,12,0,100,"SAY_GUARD_SIL_AGGRO2","Please tell me that you didn't just do what I think you just did. Please tell me that I'm not going to have to hurt you..."),
(4624,0,2,12,0,100,"SAY_GUARD_SIL_AGGRO3","As if we don't have enough problems, you go and create more!"),
(9460,0,0,12,0,100,"SAY_GUARD_SIL_AGGRO1","Taste blade, mongrel!"),
(9460,0,1,12,0,100,"SAY_GUARD_SIL_AGGRO2","Please tell me that you didn't just do what I think you just did. Please tell me that I'm not going to have to hurt you..."),
(9460,0,2,12,0,100,"SAY_GUARD_SIL_AGGRO3","As if we don't have enough problems, you go and create more!"),
(11190,0,0,12,0,100,"SAY_GUARD_SIL_AGGRO1","Taste blade, mongrel!"),
(11190,0,1,12,0,100,"SAY_GUARD_SIL_AGGRO2","Please tell me that you didn't just do what I think you just did. Please tell me that I'm not going to have to hurt you..."),
(11190,0,2,12,0,100,"SAY_GUARD_SIL_AGGRO3","As if we don't have enough problems, you go and create more!"),
(15184,0,0,12,0,100,"SAY_GUARD_SIL_AGGRO1","Taste blade, mongrel!"),
(15184,0,1,12,0,100,"SAY_GUARD_SIL_AGGRO2","Please tell me that you didn't just do what I think you just did. Please tell me that I'm not going to have to hurt you..."),
(15184,0,2,12,0,100,"SAY_GUARD_SIL_AGGRO3","As if we don't have enough problems, you go and create more!");

-- cluck
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1070006 AND -1070004;
DELETE FROM `creature_text` WHERE `entry`=620;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(620,0,0,16,0,100,"cluck EMOTE_A_HELLO","looks up at you quizzically. Maybe you should inspect it?"),
(620,1,0,16,0,100,"cluck EMOTE_H_HELLO","looks at you unexpectadly."),
(620,2,0,16,0,100,"cluck EMOTE_CLUCK_TEXT2","starts pecking at the feed.");

-- injured_patient
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000203 AND -1000201;
DELETE FROM `creature_text` WHERE `entry` IN (12920,12939);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(12920,0,0,12,0,100,"injured_patient SAY_DOC1","I'm saved! Thank you, doctor!"),
(12920,0,1,12,0,100,"injured_patient SAY_DOC2","HOORAY! I AM SAVED!"),
(12920,0,2,12,0,100,"injured_patient SAY_DOC3","Sweet, sweet embrace... take me..."),
(12939,0,0,12,0,100,"injured_patient SAY_DOC1","I'm saved! Thank you, doctor!"),
(12939,0,1,12,0,100,"injured_patient SAY_DOC2","HOORAY! I AM SAVED!"),
(12939,0,2,12,0,100,"injured_patient SAY_DOC3","Sweet, sweet embrace... take me...");

-- kayra
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000347 AND -1000343;
DELETE FROM `creature_text` WHERE `entry`=17969;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17969,0,0,12,0,100,"kayra SAY_START","Is the way clear? Let's get out while we can, $N."),
(17969,1,0,12,0,100,"kayra SAY_AMBUSH1","Looks like we won't get away so easy. Get ready!"),
(17969,2,0,12,0,100,"kayra SAY_PROGRESS","Let's keep moving. We're not safe here!"),
(17969,3,0,12,0,100,"kayra SAY_AMBUSH2","Look out, $N! Enemies ahead!"),
(17969,4,0,12,0,100,"kayra SAY_END","We're almost to the refuge! Let's go.");

-- ashyen and keleth
DELETE FROM `script_texts` WHERE `entry`=-1000359;
DELETE FROM `creature_text` WHERE `entry` IN (17900,17901);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(17900,0,0,12,0,100,"ashyen and keleth GOSSIP_REWARD_BLESS","Thank you for helping me. I know my way back from here."),
(17901,0,0,12,0,100,"ashyen and keleth GOSSIP_REWARD_BLESS","Thank you for helping me. I know my way back from here.");

-- cyanigosa - fix mistake in previous commit
DELETE FROM `creature_text` WHERE `entry`=31134;
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`type`,`sound`,`probability`,`comment`,`text`) VALUES
(31134,0,0,14,13947,100,"cyanigosa SAY_AGGRO","We finish this now, champions of Kirin Tor!"),
(31134,1,0,14,13952,100,"cyanigosa SAY_SLAY_1","I will end the Kirin Tor!"),
(31134,1,1,14,13953,100,"cyanigosa SAY_SLAY_2","Dalaran will fall!"),
(31134,1,2,14,13954,100,"cyanigosa SAY_SLAY_3","So ends your defiance of the Spell-Weaver!"),
(31134,2,0,14,13955,100,"cyanigosa SAY_DEATH","Perhaps... we have... underestimated... you."),
(31134,3,0,14,13946,100,"cyanigosa SAY_SPAWN","A valiant defense, but this city must be razed. I will fulfill Malygos's wishes myself!"),
(31134,4,0,14,13951,100,"cyanigosa SAY_DISRUPTION","Am I interrupting?"),
(31134,5,0,14,13948,100,"cyanigosa SAY_BREATH_ATTACK","Shiver and die!"),
(31134,6,0,14,13949,100,"cyanigosa SAY_SPECIAL_ATTACK_1","The world has forgotten what true magic is! Let this be a reminder!"),
(31134,6,1,14,13950,100,"cyanigosa SAY_SPECIAL_ATTACK_2","Who among you can withstand my power?");
