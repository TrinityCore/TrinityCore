-- Azjol-Nerub
UPDATE `instance_template` SET `script`='instance_azjol_nerub' WHERE `map`=601;
-- Krik'thir the Gatewatcher
UPDATE creature_template SET `ScriptName`='npc_watcher_narjil' WHERE `entry`=28729;
UPDATE creature_template SET `ScriptName`='npc_watcher_silthik' WHERE `entry`=28731;
UPDATE creature_template SET `ScriptName`='npc_anub_ar_warrior' WHERE `entry`=28732;
UPDATE creature_template SET `ScriptName`='npc_watcher_gashra' WHERE `entry`=28730;
UPDATE creature_template SET `ScriptName`='boss_krik_thir' WHERE `entry`=28684;
UPDATE creature_template SET `ScriptName`='npc_skittering_infector' WHERE `entry`=28736;
UPDATE creature_template SET `ScriptName`='npc_anub_ar_skirmisher' WHERE `entry`=28734;
UPDATE creature_template SET `ScriptName`='npc_anub_ar_shadowcaster' WHERE `entry`=28733;

-- Halls of Stone
-- scripts
UPDATE `instance_template` SET `script`='instance_halls_of_stone' WHERE `map`=599;
UPDATE `creature_template` SET `ScriptName`='boss_krystallus' WHERE `entry`=27977;
UPDATE `creature_template` SET `ScriptName`='boss_sjonnir' WHERE `entry`=27978;
UPDATE `creature_template` SET `ScriptName`='mob_tribuna_controller' WHERE `entry`=28234;
UPDATE `creature_template` SET `ScriptName`='npc_brann_hos' WHERE `entry`=28070;
-- waypoints
DELETE FROM script_waypoint WHERE `entry`=28070;
INSERT INTO script_waypoint VALUES
   (28070, 0, 1053.789795, 476.639343, 207.744, 0, ''),
   (28070, 1, 1032.293945, 467.623444, 207.736, 0, ''),
   (28070, 2, 1017.908752, 454.765656, 207.719, 0, ''),
   (28070, 3, 1004.810120, 441.305115, 207.373, 0, ''),
   (28070, 4, 988.694214, 424.422485, 207.425, 0, ''),
   (28070, 5, 984.816345, 422.177917, 205.994, 0, ''),
   (28070, 6, 977.204468, 420.026917, 205.994, 0, ''),
   (28070, 7, 962.388123, 421.983307, 205.994, 0, ''),
   (28070, 8, 950.419556, 416.515198, 205.994, 0, ''),
   (28070, 9, 943.972290, 403.071228, 205.994, 0, ''),
   (28070, 10, 947.921936, 387.683563, 205.994, 0, ''),
   (28070, 11, 946.554749, 383.270782, 205.994, 0, ''),
   (28070, 12, 944.654724, 380.630859, 207.286, 0, ''),
   (28070, 13, 941.101563, 377.373413, 207.421, 0, 'reach tribunal, set pause'),
   (28070, 14, 935.217896, 370.557343, 207.421, 0, ''),
   (28070, 15, 928.035950, 363.026733, 204.018, 0, ''),
   (28070, 16, 909.287292, 344.392792, 203.706, 0, ''),
   (28070, 17, 897.946838, 333.634735, 203.706, 0, 'reach panel'),
   (28070, 18, 918.914429, 351.312866, 203.706, 0, 'reach floor disc (end event begin)'),
   (28070, 19, 928.070068, 363.296326, 204.091, 0, 'stealth'),
   (28070, 20, 934.817627, 370.136261, 207.421, 0, ''),
   (28070, 21, 941.501465, 377.254456, 207.421, 0, '');
-- texts
DELETE FROM `script_texts` WHERE `npc_entry` IN (27977,27978,28070);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
/* Krystallus */
   (27977,-1603007,'Crush....',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14176,1,0,0,'krystallus SAY_AGGRO'),
   (27977,-1603008,'Ha...ha...ha...ha...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14177,1,0,0,'krystallus SAY_KILL'),
   (27977,-1603009,'Uuuuhhhhhhhhhh......',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14179,1,0,0,'krystallus SAY_DEATH'),
   (27977,-1603010,'Break.... you....',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14178,1,0,0,'krystallus SAY_SHATTER'),
/* Sjonnir */
   (27978,-1603011,'Soft, vulnerable shells. Brief, fragile lives. You can not escape the curse of flesh!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'Sjonnir SAY_AGGRO'),
   (27978,-1603012,'Flesh is no match for iron!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'Sjonnir SAY_SLAY_1'),
   (27978,-1603013,'Armies of iron will smother the world!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'Sjonnir SAY_SLAY_2'),
   (27978,-1603015,'Loken will not rest, until the forge is retaken. You changed nothing!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'Sjonnir SAY_DEATH'),
   (28070,-1603012,'Now that''s owning your supper!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14244,1,0,0,'brann SAY_KILL_1'),
   (28070,-1603013,'Press on, that''s the way!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14245,1,0,0,'brann SAY_KILL_2'),
   (28070,-1603014,'Keep it up now. Plenty of death-dealing for everyone!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14246,1,0,0,'brann SAY_KILL_3'),
   (28070,-1603015,'I''m all kinds of busted up. Might not... make it...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14257,1,0,0,'brann SAY_LOW_HEALTH'),
   (28070,-1603016,'Not yet, not... yet-',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14258,1,0,0,'brann SAY_DEATH'),
   (28070,-1603017,'I''m doing everything I can!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14260,1,0,0,'brann SAY_PLAYER_DEATH_1'),
   (28070,-1603018,'Light preserve you!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14261,1,0,0,'brann SAY_PLAYER_DEATH_2'),
   (28070,-1603019,'I hope this is all worth it!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14262,1,0,0,'brann SAY_PLAYER_DEATH_3'),
   (28070,-1603020,'Time to get some answers! Let''s get this show on the road!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14259,1,0,0,'brann SAY_ESCORT_START'),
   (28070,-1603021,'Don''t worry. Old Brann has got your back. Keep that metal monstrosity busy and I''ll see if I can sweet talk this machine into helping you.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14274,1,0,0,'brann SAY_SPAWN_DWARF'),
   (28070,-1603022,'This is a wee bit trickier that before... Oh, bloody--incomin''!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14275,1,0,0,'brann SAY_SPAWN_TROGG'),
   (28070,-1603023,'What in the name o'' Madoran did THAT do? Oh! Wait: I just about got it...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14276,1,0,0,'brann SAY_SPAWN_OOZE'),
   (28070,-1603024,'Ha, that did it. Help''s a-coming. Take this you glow-eying brute!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14277,1,0,0,'brann SAY_SPAWN_EARTHEN'),
   (28070,-1603025,'Take a moment and relish this with me! Soon all will be revealed! Okay then, let''s do this!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14247,1,0,0,'brann SAY_EVENT_INTRO_1'),
   (28070,-1603026,'Now keep an eye out! I''ll have this licked in two shakes of a--',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14248,1,0,0,'brann SAY_EVENT_INTRO_2'),
   (28070,-1603027,'Warning! Life form pattern not recognized. Archival processing terminated. Continued interference will result in targeted response.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13765,1,0,0,'brann SAY_EVENT_INTRO_3_ABED'),
   (28070,-1603028,'Oh, that doesn''t sound good. We might have a complication or two...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14249,1,0,0,'brann SAY_EVENT_A_1'),
   (28070,-1603029,'Security breach in progress. Analysis of historical archives transferred to lower priority queue. Countermeasures engaged.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13756,1,0,0,'brann SAY_EVENT_A_2_KADD'),
   (28070,-1603030,'Ah, you want to play hardball, eh? That''s just my game!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14250,1,0,0,'brann SAY_EVENT_A_3'),
   (28070,-1603031,'Couple more minutes and I''ll--',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14251,1,0,0,'brann SAY_EVENT_B_1'),
   (28070,-1603032,'Threat index threshold exceeded. Celestial archive aborted. Security level heightened.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13761,1,0,0,'brann SAY_EVENT_B_2_MARN'),
   (28070,-1603033,'Heightened? What''s the good news?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14252,1,0,0,'brann SAY_EVENT_B_3'),
   (28070,-1603034,'So that was the problem? Now I''m makin'' progress...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14253,1,0,0,'brann SAY_EVENT_C_1'),
   (28070,-1603035,'Critical threat index. Void analysis diverted. Initiating sanitization protocol.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13767,1,0,0,'brann SAY_EVENT_C_2_ABED'),
   (28070,-1603036,'Hang on! Nobody''s gonna'' be sanitized as long as I have a say in it!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14254,1,0,0,'brann SAY_EVENT_C_3'),
   (28070,-1603037,'Ha! The old magic fingers finally won through! Now let''s get down to-',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14255,1,0,0,'brann SAY_EVENT_D_1'),
   (28070,-1603038,'Alert! Security fail safes deactivated. Beginning memory purge...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13768,1,0,0,'brann SAY_EVENT_D_2_ABED'),
   (28070,-1603039,'Purge? No no no no no! Where did I-- Aha, this should do the trick...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14256,1,0,0,'brann SAY_EVENT_D_3'),
   (28070,-1603040,'System online. Life form pattern recognized. Welcome Branbronzan. Query?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13769,1,0,0,'brann SAY_EVENT_D_4_ABED'),
   (28070,-1603041,'Query? What do you think I&#65533;m here for? Tea and biscuits? Spill the beans already!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14263,1,0,0,'brann SAY_EVENT_END_01'),
   (28070,-1603042,'Tell me how that dwarfs came to be! And start at the beginning!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14264,1,0,0,'brann SAY_EVENT_END_02'),
   (28070,-1603043,'Accessing prehistoric data. Retrieved. In the beginning Earthen were created to-',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13770,1,0,0,'brann SAY_EVENT_END_03_ABED'),
   (28070,-1603044,'Right, right! I know that the Earthen were made of stone to shape the deep reaches of the world but what about the anomalies? Matrix non-stabilizing and whatnot.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14265,1,0,0,'brann SAY_EVENT_END_04'),
   (28070,-1603045,'Accessing. In the early stages of its development cycle Azeroth suffered infection by parasitic, necrophotic symbiotes.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13771,1,0,0,'brann SAY_EVENT_END_05_ABED'),
   (28070,-1603046,'Necro-what? Speak bloody common will ya?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14266,1,0,0,'brann SAY_EVENT_END_06'),
   (28070,-1603047,'Designation: Old Gods. Old Gods rendered all systems, including Earthen defenseless in order to facilitate assimilation. This matrix destabilization has been termed the Curse of Flesh. Effects of destabilization increased over time.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13772,1,0,0,'brann SAY_EVENT_END_07_ABED'),
   (28070,-1603048,'Old Gods eh? So they zapped the Earthen with this Curse of Flesh. And then what?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14267,1,0,0,'brann SAY_EVENT_END_08'),
   (28070,-1603049,'Accessing. Creators arrived to extirpate symbiotic infection. Assessment revealed that Old God infestation had grown malignant. Excising parasites would result in loss of host.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13757,1,0,0,'brann SAY_EVENT_END_09_KADD'),
   (28070,-1603050,'If they killed the Old Gods Azeroth would have been destroyed.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14268,1,0,0,'brann SAY_EVENT_END_10'),
   (28070,-1603051,'Correct. Creators neutralized parasitic threat and contained it within the host. Forge of Wills and other systems were instituted to create new Earthen. Safeguards were implemented and protectors were appointed.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13758,1,0,0,'brann SAY_EVENT_END_11_KADD'),
   (28070,-1603052,'What protectors?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14269,1,0,0,'brann SAY_EVENT_END_12'),
   (28070,-1603053,'Designations: Aesir and Vanir or in common nomenclator Storm and Earth Giants. Sentinel Loken designated supreme. Dragon Aspects appointed to monitor evolution of Azeroth.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13759,1,0,0,'brann SAY_EVENT_END_13_KADD'),
   (28070,-1603054,'Aesir and Vanir. Okay. So the Forge of Wills started to make new Earthen. But what happened to the old ones?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14270,1,0,0,'brann SAY_EVENT_END_14'),
   (28070,-1603055,'Additional background is relevant to your query. Following global combat between-',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13762,1,0,0,'brann SAY_EVENT_END_15_MARN'),
   (28070,-1603056,'Hold everything! The Aesir and Vanir went to war? Why?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14271,1,0,0,'brann SAY_EVENT_END_16'),
   (28070,-1603057,'Unknown. Data suggests that impetus for global combat originated with prime designate Loken who neutralized all remaining Aesir and Vanir affecting termination of conflict. Prime designate Loken then initiated stasis of several seed races including Earthen, Giant and Vrykul at designated holding facilities.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13763,1,0,0,'brann SAY_EVENT_END_17_MARN'),
   (28070,-1603058,'This Loken sounds like a nasty character. Glad we don&#65533;t have to worry about the likes of him anymore. So if I&#65533;m understanding you lads the original Earthen eventually woke up from this statis. And by that time this destabily-whatever had turned them into our brother dwarfs. Or at least dwarf ancestors. Hm?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14272,1,0,0,'brann SAY_EVENT_END_18'),
   (28070,-1603059,'Essentially that is correct.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13764,1,0,0,'brann SAY_EVENT_END_19_MARN'),
   (28070,-1603060,'Well now. That&#65533;s a lot to digest. I&#65533;m gonna need some time to take all of this in. Thank you!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14273,1,0,0,'brann SAY_EVENT_END_20'),
   (28070,-1603061,'Acknowledged Branbronzan. Session terminated.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13773,1,0,0,'brann SAY_EVENT_END_21_ABED'),
   (28070,-1603062,'Loken?! That''s downright bothersome... We might''ve neutralized the iron dwarves, but I''d lay odds there''s another machine somewhere else churnin'' out a whole mess o'' these iron vrykul!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14278,1,0,0,'brann SAY_VICTORY_SJONNIR_1'),
   (28070,-1603063,'I''ll use the forge to make badtches o'' earthen to stand guard... But our greatest challenge still remains: find and stop Loken!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14279,1,0,0,'brann SAY_VICTORY_SJONNIR_2'),
   (28070,-1603064,'I think it''s time to see what''s behind the door near the entrance. I''m going to sneak over there, nice and quiet. Meet me at the door and I''ll get us in.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,'brann SAY_ENTRANCE_MEET');
