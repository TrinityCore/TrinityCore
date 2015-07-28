SET @HO_SOOSAY := 28027;
SET @HO_GOSSIP := 9742;
SET @O_STATE   := 50503;
SET @T_STORM   := 53071;
SET @FI_LAFOO  := 52547;
SET @FI_JALOOT := 52548;
SET @FI_MOODLE := 52549;
SET @SEEINVIS  := 52214;
SET @RAINSPEAKERAURA := 51639;
SET @TREASUREPING:= 51420;
SET @GORLOCPING  := 51794;
SET @WOLVARPING  := 51791;
SET @DIGUPGLINTINGBUG:= 51443;
SET @DIGUPSPARKINGHARE   := 51441;
SET @DIGUPSHININGCRYSTAL := 51397;
SET @DIGUPGLINTINGARMOR  := 51398;
SET @DIGUPGLOWINGGEM := 51400;
SET @DIGUPPOLISHEDPLATTER  := 51401;
SET @DIGUPSPARKINGTREASURE := 51402;
SET @BLESSINGOFTHESPARKINGHARE := 51442;
SET @JALOOTSINTENSITY := 52119;
SET @RAINSPEAKERBUNNY := 28455;
SET @LAFOO := 28120;
SET @MOODLE := 28122;
SET @JALOOT := 28121;
SET @GLINTINGDIRT := 28362;
SET @GLINTINGBUG := 28372;
SET @SPARKLINGHARE := 28371;
SET @GLINTINGDIRTSCRIPT := 2836201;
SET @GORLOCTREASURESCRIPT := 2812000;
SET @ELDER_HARKEK := 28138;
SET @SHAMAN_RAKJAK := 28082;
SET @EH_GOSSIP:= 9741;
SET @FRENZYAURA := 51234;
SET @FRENZYBUNNY := 28299;
SET @GOREGEK := 28214;
SET @DAJIK := 28215;
SET @ZEPIK := 28216;
SET @FI_GOREGEK := 52542;
SET @FI_DAJIK := 52544;
SET @FI_ZEPIK := 52545;
SET @CHICKENSEEINVIS := 50735;
SET @DESSAWNRETAINER := 53163;
SET @MOSSWALKERAURA := 51644;
SET @MOSSWALKERBUNNY := 28459;
SET @ANGRYGORLOCCREDIT := 54057;
SET @MISTWHISPERAURA := 51239;
SET @MISTWHISPERBUNNY := 28300;
SET @SPEARBORNAURA := 51642;
SET @SPEARBORNBUNNY := 28457;
SET @KARTAKHOLDAURA := 51643;
SET @KARTAKHOLDBUNNY := 28458;
SET @SPARKTOUCHEDAURA := 51641;
SET @SPARKTOUCHEDBUNNY := 28456;
SET @SAPPHIREHIVEAURA := 51651;
SET @LIFEBLOODPILLARBUNNY := 28460;
SET @LIFEBLOODPILLARAURA:= 51649;
SET @SKYREACHPILLARBUNNY := 28454;
SET @SKYREACHPILLARAURA:= 51645;
SET @SAPPHIREHIVEBUNNY := 28462;
SET @GORLOCLOCATIONPERIODIC := 51793;
SET @WOLVARLOCATIONPERIODIC := 51792;
SET @LOOKINGFORTREASUREAURA := 51407;
SET @SHOLAZARGUARDIANHEARTBEAT := 51623;
SET @DIGGINGFORTEASURE := 51405;
SET @GOREGEKSSHACKLE := 38619;
SET @DAJIKSCHALK := 38621;
SET @ZEPIKSHUNTINGHORN := 38512;
SET @LAFOOSBUGBAG := 38622;
SET @JALOOTSCRYSTAL := 38623;
SET @MOODLESSTRESSBALL := 38624;
SET @INVISIBILTY := 52213;
SET @HARDKNUCKLE := 28096;
SET @HARDKNUCKLEMATRIARCH := 28213;
SET @SAPPHIREQUEEN := 28087;
SET @VENOMTIP := 28358;

UPDATE `creature_template` SET `minlevel`=77, `maxlevel`=77, `exp`=2,`mindmg`=371, `maxdmg`=522,`attackpower`=478 WHERE  `entry`IN (@GOREGEK,@DAJIK,@ZEPIK);
UPDATE `creature_template` SET `unit_flags` =33555200 WHERE `entry`IN (@MOSSWALKERBUNNY,@MISTWHISPERBUNNY,@SPEARBORNBUNNY,@KARTAKHOLDBUNNY,@SPARKTOUCHEDBUNNY,@SAPPHIREHIVEBUNNY,@LIFEBLOODPILLARBUNNY,@SKYREACHPILLARBUNNY);
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN(@HO_SOOSAY,@ELDER_HARKEK,@SHAMAN_RAKJAK);
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`IN(@HO_SOOSAY,@ELDER_HARKEK,@SHAMAN_RAKJAK);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(@HO_SOOSAY,@ELDER_HARKEK,@SHAMAN_RAKJAK);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@HO_SOOSAY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 0, 0, 75, @O_STATE, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - Out of combat - Add Oracle State Aura'),
(@HO_SOOSAY, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 12000, 16000, 11, @T_STORM, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - In Combat - Cast Thunderstorm'),
(@HO_SOOSAY,0,2,8,62,0,100,0,@HO_GOSSIP,0,0,0,85,@FI_LAFOO,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Oracle Soo-say - On gossip select - Spellcast Forceitem Lafoo'),
(@HO_SOOSAY,0,3,8,62,0,100,0,@HO_GOSSIP,1,0,0,85,@FI_LAFOO,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Oracle Soo-say - On gossip select - Spellcast Forceitem Lafoo'),
(@HO_SOOSAY,0,4,8,62,0,100,0,@HO_GOSSIP,2,0,0,85,@FI_JALOOT,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Oracle Soo-say - On gossip select - Spellcast Forceitem Jaloot'),
(@HO_SOOSAY,0,5,8,62,0,100,0,@HO_GOSSIP,3,0,0,85,@FI_JALOOT,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Oracle Soo-say - On gossip select - Spellcast Forceitem Jaloot'),
(@HO_SOOSAY,0,6,8,62,0,100,0,@HO_GOSSIP,4,0,0,85,@FI_MOODLE,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Oracle Soo-say - On gossip select - Spellcast Forceitem Moodle'),
(@HO_SOOSAY,0,7,8,62,0,100,0,@HO_GOSSIP,5,0,0,85,@FI_MOODLE,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Oracle Soo-say - On gossip select - Spellcast Forceitem Moodle'),
(@HO_SOOSAY,0,8,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Oracle Soo-say - On gossip select - Close gossip'),
(@HO_SOOSAY,0,9, 0, 20, 0, 100, 0, 12704, 0, 0, 0, 28, @SEEINVIS, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - On Quest Complete - Remove Aura Rainspeaker Treasures: See Invisibility'),
(@HO_SOOSAY,0,10, 0, 19, 0, 100, 0, 12704, 0, 0, 0, 85, @SEEINVIS, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - On Quest Accept - Invoker Cast Rainspeaker Treasures: See Invisibility'),
(@HO_SOOSAY, 0, 11, 0, 20, 0, 100, 0, 12572, 0, 0, 0, 28, @SEEINVIS, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - On Quest Complete - Remove Aura Rainspeaker Treasures: See Invisibility'),
(@HO_SOOSAY, 0, 12, 0, 19, 0, 100, 0, 12574, 0, 0, 0, 57, @LAFOOSBUGBAG, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - On Quest Accept - Remove Lafoos Bug bag'),
(@HO_SOOSAY, 0, 13, 0, 20, 0, 100, 0, 12577, 0, 0, 0, 57, @JALOOTSCRYSTAL, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - On Quest Complete - Remove Jaloots favourite crystal'),
(@HO_SOOSAY, 0, 14, 0, 20, 0, 100, 0, 12581, 0, 0, 0, 57, @MOODLESSTRESSBALL, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Oracle Soo-say - On Quest Complete - Remove Moodles Stress Ball'),
-- 
(@SHAMAN_RAKJAK,0,0,0,19,0,100,0,12529,0,0,0,11,@FI_GOREGEK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Shaman Rakjak - On quest accept - Spellcast Forceitem Goregek'),
(@SHAMAN_RAKJAK,0,1,0,19,0,100,0,12530,0,0,0,11,@FI_GOREGEK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Shaman Rakjak - On quest accept - Spellcast Forceitem Goregek'),
(@SHAMAN_RAKJAK,0,2,0,19,0,100,0,12533,0,0,0,11,@FI_DAJIK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Shaman Rakjak - On quest accept - Spellcast Forceitem Dajik'),
(@SHAMAN_RAKJAK,0,3,0,19,0,100,0,12534,0,0,0,11,@FI_DAJIK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Shaman Rakjak - On quest accept - Spellcast Forceitem Dajik'),
(@SHAMAN_RAKJAK,0,4,0,19,0,100,0,12536,0,0,0,11,@FI_ZEPIK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High-Shaman Rakjak - On quest accept - Spellcast Forceitem Zepik'),
(@SHAMAN_RAKJAK, 0, 15, 0, 19, 0, 100, 0, 12533, 0, 0, 0, 57, @GOREGEKSSHACKLE, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Shaman Rakjak - On Quest Accept - Remove Goregeks Shackes'),
(@SHAMAN_RAKJAK, 0, 16, 0, 19, 0, 100, 0, 12536, 0, 0, 0, 57, @DAJIKSCHALK, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Shaman Rakjak - On Quest Accept - Remove Dajiks Chalk'),
(@SHAMAN_RAKJAK, 0, 17, 0, 19, 0, 100, 0, 12540, 0, 0, 0, 57, @ZEPIKSHUNTINGHORN, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'High-Shaman Rakjak - On Quest Accept - Remove Zepiks Hunting Horn'),
-- 
(@ELDER_HARKEK,0,4,10,62,0,100,0,@EH_GOSSIP,0,0,0,85,@FI_GOREGEK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Elder Harkek - On gossip select - Spellcast Forceitem Goregek'),
(@ELDER_HARKEK,0,5,10,62,0,100,0,@EH_GOSSIP,1,0,0,85,@FI_GOREGEK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Elder Harkek - On gossip select - Spellcast Forceitem Goregek'),
(@ELDER_HARKEK,0,6,10,62,0,100,0,@EH_GOSSIP,2,0,0,85,@FI_DAJIK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Elder Harkek - On gossip select - Spellcast Forceitem Dajik'),
(@ELDER_HARKEK,0,7,10,62,0,100,0,@EH_GOSSIP,3,0,0,85,@FI_DAJIK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Elder Harkek - On gossip select - Spellcast Forceitem Dajik'),
(@ELDER_HARKEK,0,8,10,62,0,100,0,@EH_GOSSIP,4,0,0,85,@FI_ZEPIK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Elder Harkek - On gossip select - Spellcast Forceitem Zepik'),
(@ELDER_HARKEK,0,9,10,62,0,100,0,@EH_GOSSIP,5,0,0,85,@FI_ZEPIK,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Elder Harkek - On gossip select - Spellcast Forceitem Zepik'),
(@ELDER_HARKEK,0,10,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Elder Harkek - On gossip select - Close gossip'),
(@ELDER_HARKEK, 0, 3, 0, 20, 0, 100, 0, 12702, 0, 0, 0, 28, @CHICKENSEEINVIS, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elder Harkek - On Quest Complete - Remove Aura Frenzyheart Chicken: See Invisibility'),
(@ELDER_HARKEK, 0, 2, 0, 20, 0, 100, 0, 12532, 0, 0, 0, 28, @CHICKENSEEINVIS, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elder Harkek - On Quest Complete - Remove Aura Frenzyheart Chicken: See Invisibility'),
(@ELDER_HARKEK, 0, 1, 0, 19, 0, 100, 0, 12702, 0, 0, 0, 85, @CHICKENSEEINVIS, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elder Harkek - On Quest Accept - Invoker Cast Frenzyheart Chicken: See Invisibility'),
(@ELDER_HARKEK, 0, 0, 0, 19, 0, 100, 0, 12532, 0, 0, 0, 85, @CHICKENSEEINVIS, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elder Harkek - On Quest Accept - Invoker Cast Frenzyheart Chicken: See Invisibility'),
(@ELDER_HARKEK, 0, 11, 0, 19, 0, 100, 0, 12534, 0, 0, 0, 57, @GOREGEKSSHACKLE, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elder Harkek - On Quest Accept - Remove Goregeks Shackes');
-- 
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(@HO_GOSSIP,@EH_GOSSIP) AND `id` IN(0,1,2,3,4,5);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@HO_GOSSIP,0,0, 'I need to find Lafoo, do you have his bug bag?',1,1,0,0,0,0, ''),
(@HO_GOSSIP,1,0, 'I need to find Lafoo, do you have his bug bag?',1,1,0,0,0,0, ''),
(@HO_GOSSIP,2,0, 'I need to find Jaloot, do you have his favorite crystal?',1,1,0,0,0,0, ''),
(@HO_GOSSIP,3,0, 'I need to find Jaloot, do you have his favorite crystal?',1,1,0,0,0,0, ''),
(@HO_GOSSIP,4,0, 'I need to find Moodle, do you have his stress ball?',1,1,0,0,0,0, ''),
(@HO_GOSSIP,5,0, 'I need to find Moodle, do you have his stress ball?',1,1,0,0,0,0, ''),
(@EH_GOSSIP,0,0, 'I need to find Goregek, do you have his shackles?',1,1,0,0,0,0, ''),
(@EH_GOSSIP,1,0, 'I need to find Goregek, do you have his shackles?',1,1,0,0,0,0, ''),
(@EH_GOSSIP,2,0, 'I need to find Dajik, do you have his chalk?',1,1,0,0,0,0, ''),
(@EH_GOSSIP,3,0, 'I need to find Dajik, do you have his chalk?',1,1,0,0,0,0, ''),
(@EH_GOSSIP,4,0, 'I need to find Zepik, do you have his hunting horn?',1,1,0,0,0,0, ''),
(@EH_GOSSIP,5,0, 'I need to find Zepik, do you have his hunting horn?',1,1,0,0,0,0, '');
-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`IN(@HO_GOSSIP,@EH_GOSSIP);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@HO_GOSSIP,0,0,0,2,0,@LAFOOSBUGBAG,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Lafoo''s Bug Bag'),
(15,@HO_GOSSIP,0,0,0,9,0,12571,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Taken Quest Make the Bad Snake go away'),
(15,@HO_GOSSIP,0,0,2,2,0,@LAFOOSBUGBAG,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Lafoo''s Bug Bag'),
(15,@HO_GOSSIP,0,0,2,8,0,12571,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Rewarded Quest Make the Bad Snake go away'),
(15,@HO_GOSSIP,0,0,1,2,0,@LAFOOSBUGBAG,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Lafoo''s Bug Bag'),
(15,@HO_GOSSIP,0,0,1,28,0,12571,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has completed Quest Make the Bad Snake go away'),
(15,@HO_GOSSIP,0,0,0,8,0,12573,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Quest Making Peace'),
(15,@HO_GOSSIP,0,0,1,8,0,12573,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Quest Making Peace'),
(15,@HO_GOSSIP,0,0,2,8,0,12573,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Quest Making Peace'),
(15,@HO_GOSSIP,1,0,0,8,0,12695,0,0,0,0,0, '', 'High-Oracle Soo-say - Show gossip option only if player has rewarded quest Return of the Friendly Dryskin'),
(15,@HO_GOSSIP,1,0,0,5,0,1105,224,0,0,0,0, '', 'High-Oracle Soo-say - Show gossip option only if player is at least honored with The Oracles'),
(15,@HO_GOSSIP,1,0,0,2,0,@LAFOOSBUGBAG,1,0,1,0,0, '', 'High-Oracle Soo-say - Show gossip option only if player has no item Lafoo''s Bug Bag'),
(15,@HO_GOSSIP,4,0,0,2,0,@MOODLESSTRESSBALL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Moodle''s Stress Ball'),
(15,@HO_GOSSIP,4,0,0,9,0,12578,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Taken Quest The Angry Gorloc'),
(15,@HO_GOSSIP,4,0,2,2,0,@MOODLESSTRESSBALL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Moodle''s Stress Ball'),
(15,@HO_GOSSIP,4,0,2,8,0,12578,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Rewarded Quest The Angry Gorloc'),
(15,@HO_GOSSIP,4,0,1,2,0,@MOODLESSTRESSBALL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Moodle''s Stress Ball'),
(15,@HO_GOSSIP,4,0,1,28,0,12578,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Completed Quest The Angry Gorloc'),
(15,@HO_GOSSIP,4,0,0,8,0,12579,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Quest Lifeblood of the Mosswalker Shrine'),
(15,@HO_GOSSIP,4,0,1,8,0,12579,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Quest Lifeblood of the Mosswalker Shrine'),
(15,@HO_GOSSIP,4,0,2,8,0,12579,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Quest Lifeblood of the Mosswalker Shrine'),
(15,@HO_GOSSIP,4,0,3,2,0,@MOODLESSTRESSBALL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Moodle''s Stress Ball'),
(15,@HO_GOSSIP,4,0,3,9,0,12578,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Taken Quest The Angry Gorloc'),
(15,@HO_GOSSIP,4,0,5,2,0,@MOODLESSTRESSBALL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Moodle''s Stress Ball'),
(15,@HO_GOSSIP,4,0,5,8,0,12578,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Rewarded Quest The Angry Gorloc'),
(15,@HO_GOSSIP,4,0,4,2,0,@MOODLESSTRESSBALL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Moodle''s Stress Ball'),
(15,@HO_GOSSIP,4,0,4,28,0,12578,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Completed Quest The Angry Gorloc'),
(15,@HO_GOSSIP,4,0,3,8,0,12580,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Quest The Mosswalker Savior'),
(15,@HO_GOSSIP,4,0,4,8,0,12580,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Quest The Mosswalker Savior'),
(15,@HO_GOSSIP,4,0,5,8,0,12580,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Quest The Mosswalker Savior'),
(15,@HO_GOSSIP,5,0,0,8,0,12695,0,0,0,0,0, '', 'High-Oracle Soo-say - Show gossip option only if player has rewarded quest Return of the Friendly Dryskin'),
(15,@HO_GOSSIP,5,0,0,5,0,1105,224,0,0,0,0, '', 'High-Oracle Soo-say - Show gossip option only if player is at least honored with The Oracles'),
(15,@HO_GOSSIP,5,0,0,2,0,@JALOOTSCRYSTAL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show gossip option only if player has no item Jaloot''s Favorite Crystal'),
(15,@HO_GOSSIP,2,0,0,2,0,@JALOOTSCRYSTAL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Jaloot''s Favourite Crystal'),
(15,@HO_GOSSIP,2,0,0,9,0,12574,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Taken Quest Back so soon?'),
(15,@HO_GOSSIP,2,0,2,2,0,@JALOOTSCRYSTAL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Jaloot''s Favourite Crystal'),
(15,@HO_GOSSIP,2,0,2,8,0,12574,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Rewarded Back so soon?'),
(15,@HO_GOSSIP,2,0,1,2,0,@JALOOTSCRYSTAL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player doesn''t already have Jaloot''s Favourite Crystal'),
(15,@HO_GOSSIP,2,0,1,28,0,12574,0,0,0,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has Completed Back so soon?'),
(15,@HO_GOSSIP,2,0,0,8,0,12577,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Home Time'),
(15,@HO_GOSSIP,2,0,1,8,0,12577,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Home Time'),
(15,@HO_GOSSIP,2,0,2,8,0,12577,0,0,1,0,0, '', 'High-Oracle Soo-say - Show Gossip if player Has not completed Home Time'),
(15,@HO_GOSSIP,3,0,0,8,0,12695,0,0,0,0,0, '', 'High-Oracle Soo-say - Show gossip option only if player has rewarded quest Return of the Friendly Dryskin'),
(15,@HO_GOSSIP,3,0,0,5,0,1105,224,0,0,0,0, '', 'High-Oracle Soo-say - Show gossip option only if player is at least honored with The Oracles'),
(15,@HO_GOSSIP,3,0,0,2,0,@MOODLESSTRESSBALL,1,0,1,0,0, '', 'High-Oracle Soo-say - Show gossip option only if player has no item Moodle''s Stress Ball'),
(15,@EH_GOSSIP,0,0,0,2,0,@GOREGEKSSHACKLE,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Gorekeks Shackles'),
(15,@EH_GOSSIP,0,0,0,9,0,12529,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has Taken Quest The Ape Hunters Slave'),
(15,@EH_GOSSIP,0,0,2,2,0,@GOREGEKSSHACKLE,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Gorekeks Shackles'),
(15,@EH_GOSSIP,0,0,2,8,0,12529,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has Rewarded Quest The Ape Hunters Slave'),
(15,@EH_GOSSIP,0,0,1,2,0,@GOREGEKSSHACKLE,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Gorekeks Shackles'),
(15,@EH_GOSSIP,0,0,1,28,0,12529,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has completed Quest The Ape Hunters Slave'),
(15,@EH_GOSSIP,0,0,3,2,0,@GOREGEKSSHACKLE,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Gorekeks Shackles'),
(15,@EH_GOSSIP,0,0,3,9,0,12530,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has Taken Quest Tormenting the Softknuckles'),
(15,@EH_GOSSIP,0,0,4,2,0,@GOREGEKSSHACKLE,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Gorekeks Shackles'),
(15,@EH_GOSSIP,0,0,4,8,0,12530,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has Rewarded Quest Tormenting the Softknuckles'),
(15,@EH_GOSSIP,0,0,5,2,0,@GOREGEKSSHACKLE,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Gorekeks Shackles'),
(15,@EH_GOSSIP,0,0,5,28,0,12530,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has completed Quest Tormenting the Softknuckles'),
(15,@EH_GOSSIP,0,0,0,14,0,12533,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Wasp Hunters Apprentice'),
(15,@EH_GOSSIP,0,0,1,14,0,12533,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Wasp Hunters Apprentice'),
(15,@EH_GOSSIP,0,0,2,14,0,12533,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Wasp Hunters Apprentice'),
(15,@EH_GOSSIP,0,0,3,14,0,12533,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Wasp Hunters Apprentice'),
(15,@EH_GOSSIP,0,0,4,14,0,12533,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Wasp Hunters Apprentice'),
(15,@EH_GOSSIP,0,0,5,14,0,12533,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Wasp Hunters Apprentice'),
(15,@EH_GOSSIP,0,0,0,14,0,12534,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Underground Menace '),
(15,@EH_GOSSIP,0,0,1,14,0,12534,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Underground Menace '),
(15,@EH_GOSSIP,0,0,2,14,0,12534,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Underground Menace '),
(15,@EH_GOSSIP,0,0,3,14,0,12534,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Underground Menace '),
(15,@EH_GOSSIP,0,0,4,14,0,12534,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Underground Menace '),
(15,@EH_GOSSIP,0,0,5,14,0,12534,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest The Underground Menace '),
(15,@EH_GOSSIP,2,0,0,2,0,@DAJIKSCHALK,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Dajiks Worn Chalk'),
(15,@EH_GOSSIP,2,0,0,9,0,12533,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has Taken Quest The Wasp Hunters Apprentice'),
(15,@EH_GOSSIP,2,0,2,2,0,@DAJIKSCHALK,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Dajiks Worn Chalk'),
(15,@EH_GOSSIP,2,0,2,8,0,12533,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has Rewarded Quest The Wasp Hunters Apprentice'),
(15,@EH_GOSSIP,2,0,1,2,0,@DAJIKSCHALK,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Dajiks Worn Chalk'),
(15,@EH_GOSSIP,2,0,1,28,0,12533,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has completed Quest The Wasp Hunters Apprentice'),
(15,@EH_GOSSIP,2,0,3,2,0,@DAJIKSCHALK,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Dajiks Worn Chalk'),
(15,@EH_GOSSIP,2,0,3,9,0,12534,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has Taken Quest The Underground Menace'),
(15,@EH_GOSSIP,2,0,4,2,0,@DAJIKSCHALK,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Dajiks Worn Chalk'),
(15,@EH_GOSSIP,2,0,4,8,0,12534,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has Rewarded Quest The Underground Menace'),
(15,@EH_GOSSIP,2,0,5,2,0,@DAJIKSCHALK,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Dajiks Worn Chalk'),
(15,@EH_GOSSIP,2,0,5,28,0,12534,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has completed Quest The Underground Menace'),
(15,@EH_GOSSIP,2,0,0,14,0,12536,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest A Rough Ride'),
(15,@EH_GOSSIP,2,0,1,14,0,12536,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest A Rough Ride'),
(15,@EH_GOSSIP,2,0,2,14,0,12536,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest A Rough Ride'),
(15,@EH_GOSSIP,2,0,3,14,0,12536,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest A Rough Ride'),
(15,@EH_GOSSIP,2,0,4,14,0,12536,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest A Rough Ride'),
(15,@EH_GOSSIP,2,0,5,14,0,12536,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest A Rough Ride'),
(15,@EH_GOSSIP,4,0,0,2,0,@ZEPIKSHUNTINGHORN,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Zepiks Hunting Horn'),
(15,@EH_GOSSIP,4,0,0,9,0,12536,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has Taken Quest A Rough Ride'),
(15,@EH_GOSSIP,4,0,2,2,0,@ZEPIKSHUNTINGHORN,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Zepiks Hunting Horn'),
(15,@EH_GOSSIP,4,0,2,8,0,12536,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has Rewarded Quest A Rough Ride'),
(15,@EH_GOSSIP,4,0,1,2,0,@ZEPIKSHUNTINGHORN,1,1,1,0,0, '', 'Elder Harkek - Show Gossip if player doesn''t already have Zepiks Hunting Horn'),
(15,@EH_GOSSIP,4,0,1,28,0,12536,0,0,0,0,0, '', 'Elder Harkek - Show Gossip if player Has completed Quest A Rough Ride'),
(15,@EH_GOSSIP,4,0,0,8,0,12539,0,0,1,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest Hoofing It'),
(15,@EH_GOSSIP,4,0,1,8,0,12539,0,0,1,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest Hoofing It'),
(15,@EH_GOSSIP,4,0,2,8,0,12539,0,0,1,0,0, '', 'Elder Harkek - Show Gossip if player Has not completed Quest Hoofing It');
-- 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, @EH_GOSSIP,1,0,8,12692,0,0,0,0, '', 'Elder Harkek - Show gossip option only if player has rewarded quest Return of the Lich Hunter'),
(15, @EH_GOSSIP,1,0,5,1104,224,0,0,0, '', 'Elder Harkek - Show gossip option only if player is at least honored with Frenzheart Tribe'),
(15, @EH_GOSSIP,1,0,2,@GOREGEKSSHACKLE,1,0,1,0, '', 'Elder Harkek - Show gossip option only if player has no item Goregek''s Shackles'),
(15, @EH_GOSSIP,3,0,8,12692,0,0,0,0, '', 'Elder Harkek - Show gossip option only if player has rewarded quest Return of the Lich Hunter'),
(15, @EH_GOSSIP,3,0,5,1104,224,0,0,0, '', 'Elder Harkek - Show gossip option only if player is at least honored with Frenzheart Tribe'),
(15, @EH_GOSSIP,3,0,2,@DAJIKSCHALK,1,0,1,0, '', 'Elder Harkek - Show gossip option only if player has no item Dajiks Worn Chalk'),
(15, @EH_GOSSIP,5,0,8,12692,0,0,0,0, '', 'Elder Harkek - Show gossip option only if player has rewarded quest Return of the Lich Hunter'),
(15, @EH_GOSSIP,5,0,5,1104,224,0,0,0, '', 'Elder Harkek - Show gossip option only if player is at least honored with Frenzheart Tribe'),
(15, @EH_GOSSIP,5,0,2,@ZEPIKSHUNTINGHORN,1,0,1,0, '', 'Elder Harkek - Show gossip option only if player has no item Zepiks Hunting Horn');
-- Jaloot's Itensity and Blessing of the Sparkling Hare don't stack
DELETE FROM `spell_group` WHERE `id`=@BLESSINGOFTHESPARKINGHARE;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES 
(@BLESSINGOFTHESPARKINGHARE, @BLESSINGOFTHESPARKINGHARE),
(@BLESSINGOFTHESPARKINGHARE, @JALOOTSINTENSITY);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=@BLESSINGOFTHESPARKINGHARE;
INSERT INTO `spell_group_stack_rules` (`group_id`,`stack_rule`) VALUES 
(@BLESSINGOFTHESPARKINGHARE,1);
DELETE FROM `creature_template_addon` WHERE `entry`IN(@GLINTINGDIRT,@LAFOO,@JALOOT,@MOODLE,@GLINTINGBUG,@GOREGEK,@DAJIK,@ZEPIK);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GLINTINGBUG,0,0,0,1,0, '51444'),
(@GOREGEK,0,0,0,1,0, '54178'),
(@DAJIK,0,0,0,1,0, '52734'),
(@ZEPIK,0,0,0,1,0, '54176');
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=@SEEINVIS AND `spell_effect`=@LOOKINGFORTREASUREAURA;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES 
(@SEEINVIS,@LOOKINGFORTREASUREAURA,2, 'Looking for treasure aura triggered by Rainspeaker Treasures: See Invisibility');
DELETE FROM `spell_area` WHERE `spell` =@ANGRYGORLOCCREDIT;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=@GLINTINGDIRT;
DELETE FROM `smart_scripts` WHERE `entryorguid` =@GLINTINGDIRT;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @GLINTINGDIRTSCRIPT AND @GLINTINGDIRTSCRIPT+5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GLINTINGDIRT,0,0 ,0,38, 0,100,1,1,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - On Data Set - Increment Phase'),
(@GLINTINGDIRT,0,1 ,0,1, 1,100,1,0,0,0,0,87,@GLINTINGDIRTSCRIPT,@GLINTINGDIRTSCRIPT+1,@GLINTINGDIRTSCRIPT+2,@GLINTINGDIRTSCRIPT+3,@GLINTINGDIRTSCRIPT+4,@GLINTINGDIRTSCRIPT+5,1,0,0,0,0,0,0,0, 'Glinting Dirt - OOC (Phase 2)  - Run Random Script'),
(@GLINTINGDIRT,0,2 ,0,1, 1,100,1,400,400,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - OOC (Phase 2)  - Despawn'),
(@GLINTINGDIRT,0,3 ,0,11, 0,100,0,0,0,0,0,11,@INVISIBILTY,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - On Spawn  - Cast Rainspeaker Treasures: Invisibility'),
(@GLINTINGDIRTSCRIPT,9,0 ,0,0, 0,100,0,5000,5000,0,0,11,@DIGUPSPARKINGHARE,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Cast Dig Up Sparking Hare'),
(@GLINTINGDIRTSCRIPT,9,1 ,0,0, 0,100,0,5500,5500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Despawn'),
(@GLINTINGDIRTSCRIPT+1,9,0 ,0,0, 0,100,0,5000,5000,0,0,11,@DIGUPSHININGCRYSTAL,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Cast Dig Up Shining Crystal'),
(@GLINTINGDIRTSCRIPT+1,9,1 ,0,0, 0,100,0,5500,5500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Despawn'),
(@GLINTINGDIRTSCRIPT+2,9,0 ,0,0, 0,100,0,5000,5000,0,0,11,@DIGUPGLINTINGARMOR,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Cast Dig Up Glinting Armor'),
(@GLINTINGDIRTSCRIPT+2,9,1 ,0,0, 0,100,0,5500,5500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Despawn'),
(@GLINTINGDIRTSCRIPT+3,9,0 ,0,0, 0,100,0,5000,5000,0,0,11,@DIGUPGLOWINGGEM,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Cast Dig Up Glowing Gem'),
(@GLINTINGDIRTSCRIPT+3,9,1 ,0,0, 0,100,0,5500,5500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Despawn'),
(@GLINTINGDIRTSCRIPT+4,9,0 ,0,0, 0,100,0,5000,5000,0,0,11,@DIGUPPOLISHEDPLATTER,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Cast Dig Up Polished Platter'),
(@GLINTINGDIRTSCRIPT+4,9,1 ,0,0, 0,100,0,5500,5500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Despawn'),
(@GLINTINGDIRTSCRIPT+5,9,0 ,0,0, 0,100,0,5000,5000,0,0,11,@DIGUPSPARKINGTREASURE,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Cast Dig Up Sparking Treasure'),
(@GLINTINGDIRTSCRIPT+5,9,1 ,0,0, 0,100,0,5500,5500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Glinting Dirt - Script  - Despawn');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(@RAINSPEAKERBUNNY,@FRENZYBUNNY,@MOSSWALKERBUNNY,@MISTWHISPERBUNNY,@SPEARBORNBUNNY,@KARTAKHOLDBUNNY,@SPARKTOUCHEDBUNNY,@SAPPHIREHIVEBUNNY,@LIFEBLOODPILLARBUNNY,@SKYREACHPILLARBUNNY);
UPDATE `creature_template` SET `AIName`= 'SmartAI',`unit_flags`=32776,`InhabitType`=3 WHERE  `entry`In(@LAFOO,@MOODLE,@JALOOT,@GOREGEK,@DAJIK,@ZEPIK);
UPDATE `creature_template` SET `gossip_menu_id`=9747, `npcflag`=`npcflag`|1, `speed_run`=1.30952 WHERE `entry`=@JALOOT;
UPDATE `creature_template` SET `npcflag`=`npcflag`|1, `speed_run`=1.19048 WHERE `entry`=@MOODLE;
UPDATE `gossip_menu_option` SET `action_menu_id`=9684 WHERE `menu_id`=9677;
UPDATE `creature_template` SET `gossip_menu_id`=9745 WHERE `entry`=28106;
UPDATE `creature_template` SET `speed_walk`=0.66667, `speed_run`=0.99206 WHERE `entry`=@GOREGEK;
UPDATE `creature_template` SET `speed_walk`=0.66667, `speed_run`=0.99206, `npcflag`=`npcflag`|1 WHERE `entry`=@ZEPIK;
UPDATE `gossip_menu_option` SET `action_menu_id`=9684 WHERE `menu_id`=9677;
DELETE FROM `creature_involvedrelation` WHERE  `id`=28216 AND `quest`=12582;

DELETE FROM `gossip_menu` WHERE `entry`=9747;
DELETE FROM `gossip_menu` WHERE `entry`=9562 AND `text_id`=12883;
DELETE FROM `gossip_menu` WHERE `entry`=9570 AND `text_id`=12905;
DELETE FROM `gossip_menu` WHERE `entry`=9678 AND `text_id`=13136;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9562,12883),
(9570,12905),
(9678,13136),
(9747,13367);

DELETE FROM `npc_text` WHERE `ID`=13136;
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`lang0`,`prob0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`lang1`,`prob1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`lang2`,`prob2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`lang3`,`prob3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`lang4`,`prob4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`lang5`,`prob5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`lang6`,`prob6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`lang7`,`prob7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(13136,'Vekjik no want to be bothered.','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340);

DELETE FROM `creature_equip_template` WHERE `entry` IN (@GOREGEK,@DAJIK,@ZEPIK);
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@GOREGEK,1,36488,0,0),
(@DAJIK,1,28325,0,0),
(@ZEPIK,1,28914,0,5258);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@LAFOO,@MOODLE,@JALOOT,@GOREGEK,@DAJIK,@ZEPIK,@GORLOCTREASURESCRIPT,@RAINSPEAKERBUNNY,@FRENZYBUNNY,@MOSSWALKERBUNNY,@MISTWHISPERBUNNY,@SPEARBORNBUNNY,@KARTAKHOLDBUNNY,@SPARKTOUCHEDBUNNY,@SAPPHIREHIVEBUNNY,@LIFEBLOODPILLARBUNNY,@SKYREACHPILLARBUNNY);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GOREGEK,0,0 ,0,11,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On Spawn - Set React State'),
(@GOREGEK,0,1,0,8,0,100,0,@FRENZYAURA,0,45000,70000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On spellhit - Say line'),
(@GOREGEK,0,2,0,8,0,100,0,@DESSAWNRETAINER,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On spellhit - Despawn'),
(@GOREGEK,0,3,0,0,0,100,0,3000,6000,8000,16000,11,54188,2,0,0,0,0,5,0,0,0,0,0,0,0, 'Goregek - IC - Cast Sunder Armor'),
(@GOREGEK,0,4,0,0,0,100,0,5000,8000,15000,20000,11,52743,2,0,0,0,0,2,0,0,0,0,0,0,0, 'Goregek - IC - Cast Head Smack'),
(@GOREGEK,0,5,0,2,0,100,0,0,30,60000,60000,11,52748,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On Less than 30% HP - Cast Voracious Appetite'),
(@GOREGEK,0,6,0,13,0,100,0,12000,20000,0,0,11,6713,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On Target Casting - Cast Disarm'),
(@GOREGEK,0,7 ,0,5,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On Creature Death - Say'),
(@GOREGEK,0,8 ,0,1,0,100,0,10000,40000,45000,90000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gorekek - OOC - Say'),
(@GOREGEK,0,9 ,0,11,0,100,0,0,0,0,0,11,@WOLVARLOCATIONPERIODIC,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On Spawn - Cast Wolvar Location Periodic'),
(@GOREGEK,0,10 ,0,11,0,100,0,0,0,0,0,11,@SHOLAZARGUARDIANHEARTBEAT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On Spawn - Cast Sholazar Guardian Heartbeat'),
(@GOREGEK,0,11 ,0,1,0,100,0,10000,40000,45000,90000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Gorekek - OOC - Say'),
(@GOREGEK,0,12 ,0,1,0,100,0,10000,10000,10000,10000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - OOC - Set Phase 2'),
(@GOREGEK,0,13 ,0,4,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On Agro - Set Phase 1'),
(@GOREGEK,0,14 ,0,38,0,100,0,1,1,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On Data Set - Say'),
(@GOREGEK,0,15,0,8,2,100,0,@KARTAKHOLDAURA,0,40000,70000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - On spellhit - Say line'),
(@DAJIK,0,0 ,0,11,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On Spawn - Set React State'),
(@DAJIK,0,1,0,8,0,100,0,@FRENZYAURA,0,45000,70000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On spellhit - Say line'),
(@DAJIK,0,2,0,8,0,100,0,@DESSAWNRETAINER,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On spellhit - Despawn'),
(@DAJIK,0,3,0,0,0,100,0,3000,6000,8000,12000,11,54195,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Dajik - IC - Cast Earth''s Wrath'),
(@DAJIK,0,4,0,0,0,100,0,5000,8000,15000,20000,11,54193,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Dajik - IC - Cast Earth''s Fury'),
(@DAJIK,0,5,0,2,0,100,0,0,30,60000,60000,11,54206,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On Less than 30% HP - Cast Mend'),
(@DAJIK,0,6 ,0,5,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On Creature Death - Say'),
(@DAJIK,0,8 ,0,1,0,100,0,10000,40000,45000,90000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - OOC - Say'),
(@DAJIK,0,9,0,8,2,100,0,@SAPPHIREHIVEAURA,0,40000,70000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On spellhit - Say line'),
(@DAJIK,0,10 ,0,11,0,100,0,0,0,0,0,11,@WOLVARLOCATIONPERIODIC,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On Spawn - Cast Wolvar Location Periodic'),
(@DAJIK,0,11 ,0,11,0,100,0,0,0,0,0,11,@SHOLAZARGUARDIANHEARTBEAT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik -Goregek - On Spawn - Cast Sholazar Guardian Heartbeat'),
(@DAJIK,0,12 ,0,38,0,100,0,1,1,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On Creature Death (Sapphire Queen) - Say'),
(@DAJIK,0,13 ,0,38,0,100,0,1,2,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On Creature Death (Serfex the Reaver) - Say'),
(@DAJIK,0,14 ,0,1,0,100,0,10000,10000,10000,10000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - OOC - Set Phase 2'),
(@DAJIK,0,15 ,0,4,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On Agro - Set Phase 1'),
(@DAJIK,0,16 ,0,52,0,100,0,4,@DAJIK,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik On - Text Over - Say'),
(@DAJIK,0,17,0,8,2,100,0,@SKYREACHPILLARAURA,0,40000,70000,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On spellhit - Say line'),
(@DAJIK,0,18 ,0,1,0,100,0,10000,40000,45000,90000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - OOC - Say'),
(@DAJIK,0,19,0,8,2,100,0,@LIFEBLOODPILLARAURA,0,40000,70000,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dajik - On spellhit - Say line'),
(@ZEPIK,0,0 ,0,11,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - On Spawn - Set React State'),
(@ZEPIK,0,1,0,8,0,100,0,@FRENZYAURA,0,45000,70000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - On spellhit - Say line'),
(@ZEPIK,0,2,0,8,0,100,0,@DESSAWNRETAINER,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - On spellhit - Despawn'),
(@ZEPIK,0,3,0,0,0,100,0,4000,7000,15000,18000,11,52761,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Zepik the Gorloc Hunter - IC - Cast Barbed Net'),
(@ZEPIK,0,4,0,0,0,100,0,5000,8000,12000,15000,11,52889,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Zepik the Gorloc Hunter - IC - Cast Envenomed Shot'),
(@ZEPIK,0,5,0,0,0,100,0,0,6000,15000,18000,11,52873,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Zepik the Gorloc Hunter - IC - Cast Open Wound'),
(@ZEPIK,0,6,0,0,0,100,0,3000,5000,3000,7000,11,52758,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Zepik the Gorloc Hunter - IC - Cast Piercing Arrow'),
(@ZEPIK,0,7,0,2,0,100,0,0,30,60000,60000,11,52895,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik the Gorloc Hunter - On Less than 30% HP Cast Bandage - Cast Bandage'),
(@ZEPIK,0,8 ,0,5,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - On Creature Death - Say'),
(@ZEPIK,0,9 ,0,1,0,100,0,10000,40000,45000,90000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - OOC - Say'),
(@ZEPIK,0,10,0,8,2,100,0,@MISTWHISPERAURA,0,40000,70000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - On spellhit - Say line'),
(@ZEPIK,0,11 ,0,11,0,100,0,0,0,0,0,11,@WOLVARLOCATIONPERIODIC,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - On Spawn - Cast Wolvar Location Periodic'),
(@ZEPIK,0,12 ,0,11,0,100,0,0,0,0,0,11,@SHOLAZARGUARDIANHEARTBEAT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - On Spawn - Cast Sholazar Guardian Heartbeat'),
(@ZEPIK,0,13 ,0,1,0,100,0,10000,10000,10000,10000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Goregek - OOC - Set Phase 2'),
(@ZEPIK,0,14 ,0,4,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - On Agro - Set Phase 1'),
(@ZEPIK,0,15 ,0,38,0,100,0,1,2,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - On Data Set - Say'),
(@ZEPIK,0,16 ,0,52,0,100,0,4,@ZEPIK,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zepik - On Text Over - Say'),
(@LAFOO,0,0 ,1,8, 2,100,1,@TREASUREPING,0,60000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - On Spellhit - Say'),
(@LAFOO,0,1 ,0,61, 0,100,0,0,0,0,0,80,@GORLOCTREASURESCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - Linked with Previous Event - Run Script'),
(@LAFOO,0,2 ,0,11,0,100,0,0,0,0,0,11,@GORLOCLOCATIONPERIODIC,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - On Spawn - Cast Gorloc Location Periodic'),
(@LAFOO,0,3 ,0,11,0,100,0,0,0,0,0,11,@SHOLAZARGUARDIANHEARTBEAT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - On Spawn - Cast Sholazar Guardian Heartbeat'),
(@LAFOO,0,4 ,0,38, 0,100,0,1,1,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - On Data Set - Say'),
(@GORLOCTREASURESCRIPT,9,0 ,0,61, 0,100,0,0,0,0,0,69,0,0,0,0,0,0,11,28362,10,0,0,0,0,0, 'Lafoo - Script  - Move to Glinting Dirt'),
(@GORLOCTREASURESCRIPT,9,1 ,0,61, 0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,9,@GLINTINGDIRT,0,2,0,0,0,0, 'Lafoo - Script  - Set Data'),
(@GORLOCTREASURESCRIPT,9,2 ,0,61, 0,100,0,1500,1500,0,0,11,51405,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - Script  - Cast Digging for Treasure'),
(@GORLOCTREASURESCRIPT,9,3 ,0,61, 0,100,0,5000,5000,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - Script  - Evade'),
(@LAFOO,0,6 ,0,0, 0,100,0,0,5000,10000,12000,11,52931,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Lafoo - IC - Cast Toxic Spit'),
(@LAFOO,0,7 ,0,2,0,100,0,0,50,60000,60000,11,52940,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - On Friendly Health - Cast Sleepy Time'),
(@LAFOO,0,8 ,0,11,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - On Spawn - Set React State'),
(@LAFOO,0,9 ,0,5,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - On Creature Death - Say'),
(@LAFOO,0,10 ,0,1,0,100,0,10000,40000,45000,90000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - OOC - Say'),
(@LAFOO,0,11,0,8,0,100,0,@RAINSPEAKERAURA,0,45000,70000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - On spellhit - Say line'),
(@LAFOO,0,12,0,8,0,100,0,@DESSAWNRETAINER,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - On spellhit - Despawn'),
(@LAFOO,0,13,0,19,0,100,0,12572,0,0,0,85,@SEEINVIS,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Lafoo - On Quest Accept - Invoker Cast Rainspeaker Treasures: See Invisibility'),
(@LAFOO,0,14 ,0,1,0,100,0,10000,10000,10000,10000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - OOC - Set Phase 2'),
(@LAFOO,0,15 ,0,4,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lafoo - On Agro - Set Phase 1'),
(@JALOOT,0,0 ,1,8, 2,100,1,@TREASUREPING,0,60000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On Spellhit - Say'),
(@JALOOT,0,1 ,0,61, 0,100,0,0,0,0,0,80,@GORLOCTREASURESCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - Linked with Previous Event - Run Script'),
(@JALOOT,0,2 ,0,11,0,100,0,0,0,0,0,11,@GORLOCLOCATIONPERIODIC,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On Spawn - Cast Gorloc Location Periodic'),
(@JALOOT,0,3 ,0,11,0,100,0,0,0,0,0,11,@SHOLAZARGUARDIANHEARTBEAT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On Spawn - Cast Sholazar Guardian Heartbeat'),
(@JALOOT,0,4 ,0,38, 0,100,0,1,1,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On Data Set - Say'),
(@JALOOT,0,6,0,0,0,100,0,9000,15000,20000,25000,11,52943,2,0,0,0,0,5,0,0,0,0,0,0,0, 'Jaloot - IC - Cast Lightning Whirl'),
(@JALOOT,0,7,0,0,0,100,0,5000,8000,15000,18000,11,52944,2,0,0,0,0,5,0,0,0,0,0,0,0, 'Jaloot - IC - Cast Lightning Strike'),
(@JALOOT,0,8,0,0,0,100,0,7000,15000,20000,25000,11,52964,2,0,0,0,0,5,0,0,0,0,0,0,0, 'Jaloot - IC - Cast Spark Frenzy'),
(@JALOOT,0,9,0,2,0,100,0,0,30,30000,45000,11,52969,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On Less than 30% HP - Cast Energy Siphon'),
(@JALOOT,0,10 ,0,11,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On Spawn - Set React State'),
(@JALOOT,0,11 ,0,5,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On Creature Death - Say'),
(@JALOOT,0,12 ,0,1,0,100,0,10000,40000,45000,90000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - OOC - Say'),
(@JALOOT,0,13,0,8,0,100,0,@RAINSPEAKERAURA,0,45000,70000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On spellhit - Say line'),
(@JALOOT,0,14,0,11,0,100,0,0,0,0,0,11,@JALOOTSINTENSITY,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On Spawn - Cast Jaloot''s Intensity'),
(@JALOOT,0,15,0,8,0,100,0,@DESSAWNRETAINER,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On spellhit - Despawn'),
(@JALOOT,0,16,0,8,2,100,0,@SPEARBORNAURA,0,40000,70000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On spellhit - Say line'),
(@JALOOT,0,17 ,0,1,0,100,0,10000,10000,10000,10000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - OOC - Set Phase 2'),
(@JALOOT,0,18 ,0,4,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Jaloot - On Agro - Set Phase 1'),
(@MOODLE,0,0 ,1,8, 2,100,1,@TREASUREPING,0,60000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On Spellhit - Say'),
(@MOODLE,0,1 ,0,61, 0,100,0,0,0,0,0,80,@GORLOCTREASURESCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - Linked with Previous Event - Run Script'),
(@MOODLE,0,2 ,0,11,0,100,0,0,0,0,0,11,@GORLOCLOCATIONPERIODIC,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On Spawn - Cast Gorloc Location Periodic'),
(@MOODLE,0,3 ,0,11,0,100,0,0,0,0,0,11,@SHOLAZARGUARDIANHEARTBEAT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On Spawn - Cast Sholazar Guardian Heartbeat'),
(@MOODLE,0,4 ,0,0, 0,100,0,0,5000,20000,30000,11,52974,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - IC - Cast Vicious Roar'),
(@MOODLE,0,5 ,0,20, 0,100,0,12580,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On Quest Complete - Say'),
(@MOODLE,0,6 ,0,0, 0,100,0,0,5000,20000,24000,11,52973,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Moodle - IC - Cast Frost Breath'),
(@MOODLE,0,7,0,0,0,100,0,9000,15000,20000,25000,11,52979,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Moodle - IC - Cast Whirlwind'),
(@MOODLE,0,8,0,0,0,100,0,2000,10000,40000,50000,11,52972,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - IC - Cast Dispersal'),
(@MOODLE,0,9 ,0,2,0,100,0,0,50,60000,60000,11,52979,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On less than 50% HP - Cast Frigid Absorbtion'),
(@MOODLE,0,10 ,0,11,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On Spawn - Set React State'),
(@MOODLE,0,11 ,0,5,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On Creature Death - Say'),
(@MOODLE,0,12 ,0,1,0,100,0,10000,40000,45000,90000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - OOC - Say'),
(@MOODLE,0,13,0,8,0,100,0,@RAINSPEAKERAURA,0,45000,70000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On spellhit - Say line'),
(@MOODLE,0,14,0,8,0,100,1,@DESSAWNRETAINER,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On spellhit - Despawn'),
(@MOODLE,0,15,0,8,2,100,0,@MOSSWALKERAURA,0,40000,70000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On spellhit - Say line'),
(@MOODLE,0,16 ,0,61, 0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - Linked with Previous Event - Run Passive'),
(@MOODLE,0,17 ,0,19, 0,100,0,12581,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On Quest Accept - Say'),
(@MOODLE,0,18 ,0,1,0,100,0,10000,10000,10000,10000,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - OOC - Set Phase 2'),
(@MOODLE,0,19 ,0,4,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Moodle - On Agro - Set Phase 1'),
(@RAINSPEAKERBUNNY,0,0,0,10,0,100,0,1,150,10000,10000,11,@RAINSPEAKERAURA,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Rainspeaker Canopy Bunny - On update OOC - Spellcast Rainspeaker Canopy Aura'),
(@FRENZYBUNNY,0,0,0,10,0,100,0,1,150,10000,10000,11,@FRENZYAURA,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Frenzyheart Hill Bunny - On update OOC - Spellcast Frenzyheart Hill Aura'),
(@MOSSWALKERBUNNY,0,0,0,10,0,100,0,1,200,10000,10000,11,@MOSSWALKERAURA,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Mosswalker Village Bunny - On update OOC - Spellcast Mosswalker Village Aura'),
(@MOSSWALKERBUNNY,0,1,0,10,0,100,0,1,200,1000,1000,85,@ANGRYGORLOCCREDIT,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Mosswalker Village Bunny - On update OOC - Cast quest credit'),
(@MISTWHISPERBUNNY,0,0,0,10,0,100,0,1,200,10000,10000,11,@MISTWHISPERAURA,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Mistwhisper Refuge Bunny - On update OOC - Spellcast Mistwhisper Refuge Aura'),
(@SPEARBORNBUNNY,0,0,0,10,0,100,0,1,200,10000,10000,11,@SPEARBORNAURA,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Spearborn Encampment Bunny - On update OOC - Spellcast Spearborn Encampment Aura'),
(@KARTAKHOLDBUNNY,0,0,0,10,0,100,0,1,200,10000,10000,11,@KARTAKHOLDAURA,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Kartak Hold Bunny - On update OOC - Spellcast Kartak Hold Aura'),
(@SPARKTOUCHEDBUNNY,0,0,0,10,0,100,0,1,200,10000,10000,11,@SPARKTOUCHEDAURA,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Sparktouched Haven Bunny - On update OOC - Spellcast Sparktouched Haven Aura'),
(@SAPPHIREHIVEBUNNY,0,0,0,10,0,100,0,1,200,10000,10000,11,@SAPPHIREHIVEAURA,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Sapphire Hive Bunny - On update OOC - Spellcast Sapphire Hive Aura'),
(@SKYREACHPILLARBUNNY,0,0,0,10,0,100,0,1,200,10000,10000,11,@SKYREACHPILLARAURA,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Skyreach Pillar Bunny - On update OOC - Spellcast Skyreach Pillar Aura'),
(@LIFEBLOODPILLARBUNNY,0,0,0,10,0,100,0,1,200,10000,10000,11,@LIFEBLOODPILLARAURA,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Lifeblood Pillar Bunny - On update OOC - Spellcast Lifeblood Pillar Aura');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`=@SPARKLINGHARE;
DELETE FROM `smart_scripts` WHERE `entryorguid` =@SPARKLINGHARE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SPARKLINGHARE,0,0 ,0,6, 0,100,0,0,0,0,0,11,@BLESSINGOFTHESPARKINGHARE,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Sparking Hare - On Death - Cast Blessing of the Sparkling Hare');

DELETE FROM `creature_text` WHERE `entry` IN(@LAFOO,@JALOOT,@MOODLE,@GOREGEK,@DAJIK,@ZEPIK);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@LAFOO, 0, 0, 'Ooh! Shinies!', 12, 0, 18, 0, 0, 0, 'Lafoo'),
(@LAFOO, 0, 1, 'Maybe more shiny bugs! We like bugs!', 12, 0, 17, 0, 0, 0, 'Lafoo'),
(@LAFOO, 0, 2, 'Treasure for Lafoo! Treasure for shrine!', 12, 0, 17, 0, 0, 0, 'Lafoo'),
(@LAFOO, 0, 3, 'Dig, dig, dig...', 12, 0, 16, 0, 0, 0, 'Lafoo'),
(@LAFOO, 0, 4, 'Crunchy bugs so delicious. Want?', 12, 0, 16, 0, 0, 0, 'Lafoo'),
(@LAFOO, 0, 5, 'That weird. Someone took our bugs. You have maybe?', 12, 0, 16, 0, 0, 0, 'Lafoo'),
(@LAFOO, 1, 0, 'No come back this time!', 12, 0, 100, 0, 0, 0, 'Lafoo'),
(@LAFOO, 2, 0, 'One day maybe you can be Soo-dryskin. You like?', 12, 0, 20, 0, 0, 0, 'Lafoo'),
(@LAFOO, 2, 1, 'You have pie? Someone gave us pie year ago. Really yummy.', 12, 0, 20, 0, 0, 0, 'Lafoo'),
(@LAFOO, 2, 2, 'Big comfy tree. Good Home.', 12, 0, 20, 0, 0, 0, 'Lafoo'),
(@LAFOO, 2, 3, 'Never meet Great Ones. Nope, just met their shrines.', 12, 0, 20, 0, 0, 0, 'Lafoo'),
(@LAFOO, 2, 4, 'You got funny looking eyeballs.', 12, 0, 20, 0, 0, 0, 'Lafoo'),
(@LAFOO, 3, 0, 'Home good, but not stay long! More adventures!.', 12, 0, 100, 0, 0, 0, 'Lafoo'),
(@LAFOO, 4, 0, 'Hiss... hiss... dead. All dead', 12, 0, 100, 0, 0, 0, 'Lafoo'),
(@JALOOT, 0, 0, 'Shiny things! Shiny things! Not as shiny as my crystal, but still shiny!', 12, 0, 25, 0, 0, 0, 'Jaloot'),
(@JALOOT, 0, 1, 'More treasures! Treasures of all kinds! Yay treasures!', 12, 0, 25, 0, 0, 0, 'Jaloot'),
(@JALOOT, 0, 2, 'Can never have too many shiny crystals! Nope!', 12, 0, 25, 0, 0, 0, 'Jaloot'),
(@JALOOT, 0, 3, 'We are fast digger! Really fast! See... all done! That was fast, huh?', 12, 0, 25, 0, 0, 0, 'Jaloot'),
(@JALOOT, 1, 0, 'You like that? Bet not! Bet not cause you dead! Hahah!', 12, 0, 34, 0, 0, 0, 'Jaloot'),
(@JALOOT, 1, 1, 'Vic...tor...ious! Dun nun nun dun da da!', 12, 0, 33, 0, 0, 0, 'Jaloot'),
(@JALOOT, 1, 2, 'Killing Spree!', 12, 0, 33, 0, 0, 0, 'Jaloot'),
(@JALOOT, 2, 0, 'Mistcaller really good at controlling weather with shrine. They know just which crystals to use! Really good!', 12, 0, 16, 0, 0, 0, 'Jaloot'),
(@JALOOT, 2, 1, 'Ever trip over own feet? We have. Kind of hurt. No do it, not fun. Nope.', 12, 0, 16, 0, 0, 0, 'Jaloot'),
(@JALOOT, 2, 2, 'Want us to help with something? What we help with? We good at helping.', 12, 0, 16, 0, 0, 0, 'Jaloot'),
(@JALOOT, 2, 3, 'Hello! You''re pretty strong and nice and stuff. I like you. Lets stay friends, okay?', 12, 0, 16, 0, 0, 0, 'Jaloot'),
(@JALOOT, 2, 4, 'Misty. Very misty. Seem sort of misty to you? Maybe not so much.', 12, 0, 16, 0, 0, 0, 'Jaloot'),
(@JALOOT, 2, 5, 'Lets go jump off tree! Fun fun!', 12, 0, 15, 0, 0, 0, 'Jaloot'),
(@JALOOT, 3, 0, 'Chase the hatchlings! Chase the hatchlings! So fast!', 12, 0, 34, 0, 0, 0, 'Jaloot'),
(@JALOOT, 3, 1, 'Great Ones keep home safe because they like Oracles I think! They know we good and nice.', 12, 0, 33, 0, 0, 0, 'Jaloot'),
(@JALOOT, 3, 2, 'Home home home... place of the shinies!', 12, 0, 33, 0, 0, 0, 'Jaloot'),
(@JALOOT, 4, 0, 'We know you have dragon thing! We not scared! We going to get you and dragon thing!', 12, 0, 34, 0, 0, 0, 'Jaloot'),
(@JALOOT, 4, 1, 'Teach you to steal our treasures! Our treasures are... ours, okay?', 12, 0, 33, 0, 0, 0, 'Jaloot'),
(@JALOOT, 4, 2, 'Time to hide puppy-men! We are coming for you!', 12, 0, 33, 0, 0, 0, 'Jaloot'),
(@JALOOT, 5, 0, 'Tartek no match for you! You got the skills. Yeah!', 12, 0, 100, 0, 0, 0, 'Jaloot'),
(@MOODLE, 0, 0, 'What the heck are shiny rabbits doing here anyway?', 12, 0, 25, 0, 0, 0, 'Moodle'),
(@MOODLE, 0, 1, 'Here I am, digging up some useless bauble on the will of someone I just met...does that seem right to you?', 12, 0, 25, 0, 0, 0, 'Moodle'),
(@MOODLE, 0, 2, 'Hey, maybe we''ll find some more useless bugs!', 12, 0, 25, 0, 0, 0, 'Moodle'),
(@MOODLE, 0, 3, 'Yay... more dirt.', 12, 0, 25, 0, 0, 0, 'Moodle'),
(@MOODLE, 1, 0, 'I can''t believe ... they''re all ... dead', 12, 0, 50, 0, 0, 0, 'Moodle'),
(@MOODLE, 1, 1, 'Another one falls to our Onslaught, As it should be.', 12, 0, 50, 0, 0, 0, 'Moodle'),
(@MOODLE, 2, 0, 'There some reason why we''re still here? I''d love to hear it', 12, 0, 33, 0, 0, 0, 'Moodle'),
(@MOODLE, 2, 1, 'Yeah, let''s go now', 12, 0, 33, 0, 0, 0, 'Moodle'),
(@MOODLE, 2, 2, 'I''m done here', 12, 0, 34, 0, 0, 0, 'Moodle'),
(@MOODLE, 3, 0, 'Going to go take a nap? I apologize in advance for accidentally stepping on your face while you sleep.', 12, 0, 33, 0, 0, 0, 'Moodle'),
(@MOODLE, 3, 1, 'Planning to sit on your butt some more, or are we going to go do something that''s actually useful?', 12, 0, 34, 0, 0, 0, 'Moodle'),
(@MOODLE, 3, 2, 'Here I am, brain the size of a planet, and they ask me to take you to the other village. Call that job satisfaction? ''Cause I don''t.', 12, 0, 33, 0, 0, 0, 'Moodle'),
(@MOODLE, 4, 0, 'The Mosswalkers were good people... they did not deserve this.', 12, 0, 17, 0, 0, 0, 'Moodle'),
(@MOODLE, 4, 1, 'I know I talk down to them, but I never want to see any of my people die.', 12, 0, 17, 0, 0, 0, 'Moodle'),
(@MOODLE, 4, 2, 'It''s good to see some of the mosswalker were more resilient than I thought.', 12, 0, 17, 0, 0, 0, 'Moodle'),
(@MOODLE, 4, 3, 'It''s hard to believe any of them survived this.', 12, 0, 17, 0, 0, 0, 'Moodle'),
(@MOODLE, 4, 4, 'There are more that might still be alive! We need to keep moving.', 12, 0, 16, 0, 0, 0, 'Moodle'),
(@MOODLE, 4, 5, 'Where are they dragging those bodies? What are they doing to them?', 12, 0, 16, 0, 0, 0, 'Moodle'),
(@MOODLE, 5, 0, 'This fight''s all yours', 12, 0, 10, 0, 0, 0, 'Moodle'),
(@MOODLE, 6, 0, 'It''s a small comfort to see that they haven''t brought any back in undeath.', 12, 0, 100, 0, 0, 0, 'Moodle'),
(@GOREGEK,0,0,'Home! You better have brought back meat for Goregek, slave.',12,0,20,0,0,0,'Goregek'),
(@GOREGEK,0,1,'Goregek get some sleep. Go bring foodstuffs back, slave thing.',12,0,20,0,0,0,'Goregek'),
(@GOREGEK,0,2,'Goregek go get drink. You sit in corner til Goregek ready.',12,0,20,0,0,0,'Goregek'),
(@GOREGEK,0,3,'Goregek hungry. Go get on fire spit, slave thing. Tell Goregek when you well roasted.',12,0,20,0,0,0,'Goregek'),
(@GOREGEK,0,4,'Gorgek gonna catch chicken good!',12,0,20,0,0,0,'Goregek'),
(@GOREGEK,0,5,'You wait until Goregek ready.',12,0,20,0,0,0,'Goregek'),
(@GOREGEK,0,6,'You wait, slave thing. Goregek eating.',12,0,20,0,0,0,'Goregek'),
(@GOREGEK,1,0,'Goregek best hunter... ever.',12,0,15,0,0,0,'Goregek'),
(@GOREGEK,1,1,'Hah! Goregek''s kill!',12,0,15,0,0,0,'Goregek'),
(@GOREGEK,1,2,'Next time, maybe Goregek let you try.',12,0,15,0,0,0,'Goregek'),
(@GOREGEK,1,3,'I stabbed it in the face! Goregek so good.',12,0,15,0,0,0,'Goregek'),
(@GOREGEK,1,4,'Squeal! Squeal! So good!',12,0,15,0,0,0,'Goregek'),
(@GOREGEK,1,5,'Frenzyheart the strongest!',12,0,15,0,0,0,'Goregek'),
(@GOREGEK,1,6,'That how it done, slave thing. Maybe you figure out how someday.',12,0,10,0,0,0,'Goregek'),
(@GOREGEK,2,0,'Why Goregek even bring you. You useless.',12,0,25,0,0,0,'Goregek'),
(@GOREGEK,2,1,'Elder maybe says other stuff, but you always be slave thing to Goregek.',12,0,25,0,0,0,'Goregek'),
(@GOREGEK,2,2,'Pitch was weakling anyway... why else you think Goregek not bother with him?',12,0,25,0,0,0,'Goregek'),
(@GOREGEK,2,3,'You just get yourself beat up! Hah! You so dumb, slave thing.',12,0,25,0,0,0,'Goregek'),
(@GOREGEK,3,0,'Careful slave thing, the big bad softnuckles might eat you! Hah!',12,0,13,0,0,0,'Goregek'),
(@GOREGEK,3,1,'Hardknuckles still walk on hands... seem kind of dumb to Goregek.',12,0,13,0,0,0,'Goregek'),
(@GOREGEK,3,2,'Run away dumb softknuckle! We gonna poke you more!',12,0,13,0,0,0,'Goregek'),
(@GOREGEK,3,3,'Run away softknuckle! Goregek gonna get you!',12,0,13,0,0,0,'Goregek'),
(@GOREGEK,3,4,'You just watch slave thing, Goregek take care of these hardknuckles!',12,0,12,0,0,0,'Goregek'),
(@GOREGEK,3,5,'Better not get in Goregek''s way!',12,0,12,0,0,0,'Goregek'),
(@GOREGEK,3,6,'Get out of way silly slave thing! Goregek''s kill!',12,0,12,0,0,0,'Goregek'),
(@GOREGEK,3,7,'There were hundreds of times these hardknuckles before Goregek.',12,0,12,0,0,0,'Goregek'),
(@GOREGEK,4,0,'Hah! Goregek the greatest hunter ever! Goregek get biggest hardknuckle!',12,0,100,0,0,0,'Goregek'),
(@GOREGEK,5,0,'Frenzyheart feed Kartak big-tongue so Kartak not eat us. That why we smarter than you, slave thing.',12,0,100,0,0,0,'Goregek'),
(@DAJIK,0,0,'Frenzyheart came here not long ago for new home... big-tongue homes pretty nice, so we maybe take those too. They ugly anyway.',12,0,12,0,0,0,'Dajik'),
(@DAJIK,0,1,'Lot of strong Frenzyheart here. Dajik taught most of them. First time I teach something like you though. You not a Frenzyheart, you know.',12,0,12,0,0,0,'Dajik'),
(@DAJIK,0,2,'Let''s just eat bristlepine instead, okay? All done with chasing.',12,0,12,0,0,0,'Dajik'),
(@DAJIK,0,3,'There reason Frenzyheart not chase back chickens. Look kind of dumb to lose to chicken.',12,0,12,0,0,0,'Dajik'),
(@DAJIK,0,4,'Maybe you not notice, chicken move kind of fast.',12,0,13,0,0,0,'Dajik'),
(@DAJIK,0,5,'Time for more smart Dajik tip! If Goregek let chickens out again, make Goregek get chickens back again.',12,0,13,0,0,0,'Dajik'),
(@DAJIK,0,6,'I placed most of the spikes. Good amount of pointiness I think. You like?',12,0,13,0,0,0,'Dajik'),
(@DAJIK,0,7,'Oh! Dajik has idea! Make chicken sounds and maybe they come to you!',12,0,13,0,0,0,'Dajik'),
(@DAJIK,1,0,'Get the stuff off of body! Dajik hate it when he go skin something and there stuff in the way. So annoying.',12,0,20,0,0,0,'Dajik'),
(@DAJIK,1,1,'Did you see face? Looked so scared, "Ah, big thing going to smash me!" Hah.',12,0,20,0,0,0,'Dajik'),
(@DAJIK,1,2,'Hah! Maybe you learn a little after all!',12,0,20,0,0,0,'Dajik'),
(@DAJIK,1,3,'Yes! Stab few more time just in case! Stab good!',12,0,20,0,0,0,'Dajik'),
(@DAJIK,1,4,'Not sure how thing got here. Not matter if dead though',12,0,20,0,0,0,'Dajik'),
(@DAJIK,2,0,'We came for something, yes? Can''t remember.',12,0,20,0,0,0,'Dajik'),
(@DAJIK,2,1,'Make sure you not forget anything! I forgot stuff once.',12,0,20,0,0,0,'Dajik'),
(@DAJIK,2,2,'Dajik not think he seen you eat anything. You eat sometimes, yeah?',12,0,20,0,0,0,'Dajik'),
(@DAJIK,2,3,'I was going to draw picture of best attack plan... but you have my chalk.',12,0,20,0,0,0,'Dajik'),
(@DAJIK,2,4,'Time for more smart Dajik tip! Make sure thing dead before reach in mouth for loots.',12,0,20,0,0,0,'Dajik'),
(@DAJIK,3,0,'Seem like there more wasps every time Dajik come back. Why they not run out?',12,0,20,0,0,0,'Dajik'),
(@DAJIK,3,1,'Time for more smart Dajik tip! Try not to catch stinger with face. Not work so much.',12,0,20,0,0,0,'Dajik'),
(@DAJIK,3,2,'In case you wonder, wasp sting not feel so good. No need to try.',12,0,20,0,0,0,'Dajik'),
(@DAJIK,3,3,'Drone things not as tough as they look. Wasp things a bit nastier.',12,0,20,0,0,0,'Dajik'),
(@DAJIK,3,4,'Try not to catch stinger with face. Not work so much.',12,0,20,0,0,0,'Dajik'),
(@DAJIK,4,0,'No! You killed the queen thing! What have you... wait, nevermind. Sorry, that okay.',12,0,100,0,7000,0,'Dajik'),
(@DAJIK,5,0,'Dajik''s last learner eaten by sand-thing. We do better this time though!',12,0,100,0,0,0,'Dajik'),
(@DAJIK,6,0,'This not first queen slain by Frenzyheart. Seem like there always more.',12,0,100,0,0,0,'Dajik'),
(@DAJIK,7,0,'Sometimes big-tongues try to come get crystals. Not now because they not like it when we kill them.',12,0,34,0,0,0,'Dajik'),
(@DAJIK,7,1,'Time for more smart Dajik tip! Crystals work little too good for back scratch. No try.',12,0,33,0,0,0,'Dajik'),
(@DAJIK,7,2,'Something big make pillars and crystals and everything. Frenzyheart not care much cause it not here anymore.',12,0,33,0,0,0,'Dajik'),
(@DAJIK,8,0,'If you here to poke more softnuckles, Dajik going to poke you too.That a bad Goregek habit.',12,0,50,0,0,0,'Dajik'),
(@DAJIK,8,1,'Huh... where are we? This not right. I not tell you find hardknuckles, did I?',12,0,50,0,0,0,'Dajik'),
(@DAJIK,9,0,'Time for more smart Dajik tip! Lot of dead things mean lot of chance of being dead thing. Dajik leaving now.',12,0,33,0,0,0,'Dajik'),
(@DAJIK,9,1,'Dead thing there already learn lesson of broken pillar. Leave this lesson for dumb, dead things. Going home now.',12,0,33,0,0,0,'Dajik'),
(@DAJIK,9,2,'You all done with learning! Yup! All done! Dajik leave you and evil red pillar thing now.',12,0,34,0,0,0,'Dajik'),
(@ZEPIK,0,0,'Bring back good meat and the camp treat you like high-shaman for a day. Good deal.',12,0,20,0,0,0,'Zepik'),
(@ZEPIK,0,1,'Elder Harkek pretty good Frenzyheart. He help me a lot when I was littler and not liking Dajik.',12,0,20,0,0,0,'Zepik'),
(@ZEPIK,0,2,'I not in a big hurry. We can rest here a while if want.',12,0,20,0,0,0,'Zepik'),
(@ZEPIK,0,3,'I not live here always... I traveled lot of world on my own not long ago. I like all the stories of beasts and dragons and gods and stuff.',12,0,20,0,0,0,'Zepik'),
(@ZEPIK,0,4,'You should go let chickens out again and say Goregek did it. Never get old.',12,0,20,0,0,0,'Zepik'),
(@ZEPIK,1,0,'Hahah! You see that? Lightning bolt hit him right in the head!',12,0,33,0,0,0,'Zepik'),
(@ZEPIK,1,1,'Good one! It not even see it coming.',12,0,33,0,0,0,'Zepik'),
(@ZEPIK,1,2,'No more play?',12,0,34,0,0,0,'Zepik'),
(@ZEPIK,2,0,'You ever fought big dragon or god or anything? Zepik like hearing stories.',12,0,12,0,0,0,'Zepik'),
(@ZEPIK,2,1,'You pretty good! Natural at hunt, like me.',12,0,12,0,0,0,'Zepik'),
(@ZEPIK,2,2,'Goregek think he the boss of everyone, but he eat too much and hunt too little.',12,0,12,0,0,0,'Zepik'),
(@ZEPIK,2,3,'Bring back good meat and the camp treat you like high-shaman for a day. Good deal.',12,0,12,0,0,0,'Zepik'),
(@ZEPIK,2,4,'Dajik forget what he doing, where he at... sometime even forget his own name. Make him not so good teacher sometimes.',12,0,13,0,0,0,'Zepik'),
(@ZEPIK,2,5,'Elder Harkek pretty good Frenzyheart. He help me a lot when I was littler and not liking Dajik.',12,0,13,0,0,0,'Zepik'),
(@ZEPIK,2,6,'I think one reason I like hunting big-tongues so much... they not as dumb as the other hunts. They give a real fight.',12,0,13,0,0,0,'Zepik'),
(@ZEPIK,2,7,'Dajik tried to show me ways of hunt, but I do better when I do things my way.',12,0,13,0,0,0,'Zepik'),
(@ZEPIK,3,0,'Eat it big-tongues!',12,0,14,0,0,0,'Zepik'),
(@ZEPIK,3,1,'Hah! Leave some for Zepik too.',12,0,14,0,0,0,'Zepik'),
(@ZEPIK,3,2,'That lake near here actually full of sea things. Not sure how it all get here... maybe in floods?',12,0,14,0,0,0,'Zepik'),
(@ZEPIK,3,3,'I think one reason I like hunting big-tongues so much... they not as dumb as the other hunts. They give a real fight.',12,0,14,0,0,0,'Zepik'),
(@ZEPIK,3,4,'Mist big-tongues are smart with their shrine thing sometimes... cover whole area with mist and it get hard to find any.',12,0,14,0,0,0,'Zepik'),
(@ZEPIK,3,5,'Hah! This the fun part!',12,0,15,0,0,0,'Zepik'),
(@ZEPIK,3,6,'Flame! Death! Destruction! The black fire rages within my heart! I must... release it! Hahah!',12,0,15,0,0,0,'Zepik'),
(@ZEPIK,4,0,'Trust me - you going love this!',12,0,100,0,0,0,'Zepik'),
(@ZEPIK,5,0,'BOOM! That so good! More! More!',12,0,100,0,0,0,'Zepik');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9678 AND `SourceEntry`=13137;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@FRENZYAURA,@RAINSPEAKERAURA,@WOLVARPING,@GORLOCPING,@DESSAWNRETAINER,@TREASUREPING,@DIGGINGFORTEASURE,@MOSSWALKERAURA,@SPEARBORNAURA,@MISTWHISPERAURA,@SAPPHIREHIVEAURA,@SKYREACHPILLARAURA);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,7,@FRENZYAURA,0,31,@GOREGEK,0,0,0,0,'','Spell Frenzyheart Hill Aura targets Goregek the Bristlepine Hunter'),
(13,7,@FRENZYAURA,1,31,@DAJIK,0,0,0,0,'','Spell Frenzyheart Hill Aura targets Dajik the Wasp Hunter'),
(13,7,@FRENZYAURA,2,31,@ZEPIK,0,0,0,0,'','Spell Frenzyheart Hill Aura targets Zepik the Gorloc Hunter'),
(13,7,@RAINSPEAKERAURA,0,31,@LAFOO,0,0,0,0,'','Spell Rainspeaker Canopy Aura targets Lafoo'),
(13,7,@RAINSPEAKERAURA,1,31,@MOODLE,0,0,0,0,'','Spell Rainspeaker Canopy Aura targets Jaloot'),
(13,7,@RAINSPEAKERAURA,2,31,@JALOOT,0,0,0,0,'','Spell Rainspeaker Canopy Aura targets Moodle'),
(13,7,@WOLVARPING,0,31,@GOREGEK,0,0,0,0,'','Spell Wolvar Location Ping targets Goregek the Bristlepine Hunter'),
(13,7,@WOLVARPING,1,31,@DAJIK,0,0,0,0,'','Spell Wolvar Location Ping targets Dajik the Wasp Hunter'),
(13,7,@WOLVARPING,2,31,@ZEPIK,0,0,0,0,'','Spell Wolvar Location Ping targets Zepik the Gorloc Hunter'),
(13,7,@GORLOCPING,0,31,@LAFOO,0,0,0,0,'','Spell Gorloc Location Ping targets Lafoo'),
(13,7,@GORLOCPING,1,31,@JALOOT,0,0,0,0,'','Spell Gorloc Location Ping targets Jaloot'),
(13,7,@GORLOCPING,2,31,@MOODLE,0,0,0,0,'','Spell Gorloc Location Ping targets Moodle'),
(13,7,@DESSAWNRETAINER,0,31,@LAFOO,0,0,0,0,'','Spell Dessawn Retainer targets Lafoo'),
(13,7,@DESSAWNRETAINER,1,31,@DAJIK,0,0,0,0,'','Spell Dessawn Retainer targets Dajik the Wasp Hunter'),
(13,7,@DESSAWNRETAINER,2,31,@ZEPIK,0,0,0,0,'','Spell Dessawn Retainer targets  Zepik the Gorloc Hunter'),
(13,7,@DESSAWNRETAINER,3,31,@JALOOT,0,0,0,0,'','Spell Dessawn Retainer targets Jaloot '),
(13,7,@DESSAWNRETAINER,4,31,@MOODLE,0,0,0,0,'','Spell Dessawn Retainer targets Moodle'),
(13,7,@DESSAWNRETAINER,5,31,@GOREGEK,0,0,0,0,'','Spell Dessawn Retainer targets  Goregek'),
(13,7,@TREASUREPING,0,31,@LAFOO,0,0,0,0,'','Spell Dessawn Retainer targets Lafoo'),
(13,7,@TREASUREPING,1,31,@JALOOT,0,0,0,0,'','Spell Dessawn Retainer targets Jaloot '),
(13,7,@TREASUREPING,2,31,@MOODLE,0,0,0,0,'','Spell Dessawn Retainer targets Moodle'),
(13,7,@DIGGINGFORTEASURE,0,31,@GLINTINGDIRT,0,0,0,0,'','digging for treasure targets glinting dirt'),
(13,7,@MOSSWALKERAURA,0,31,@MOODLE,0,0,0,0,'','Mosswalker village aura targets moodle'),
(13,7,@SPEARBORNAURA,0,31,@JALOOT,0,0,0,0,'','spearborn encampment aura targets moodle'),
(13,7,@MISTWHISPERAURA,0,31,@ZEPIK,0,0,0,0,'','mistwhisper refuge aura targets zepik'),
(13,7,@SAPPHIREHIVEAURA,0,31,@DAJIK,0,0,0,0,'','sapphire hive aura targets dajik'),
(13,7,@SKYREACHPILLARAURA,0,31,@DAJIK,0,0,0,0,'','skyreach pillar aura targets dajik'),
(14,9678,13137,0,5,1104,7,0,0,0,'','Shaman Vekjik - Show different gossip if player is hated, hostile or unfriendly with Frenzyheart Tribe');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND  `SourceEntry` IN(@GLINTINGDIRT,@LAFOO,@JALOOT,@MOODLE,@GOREGEK,@DAJIK,@ZEPIK,@MOSSWALKERBUNNY) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@LAFOO,0,0,9,0,12704,0,0,0,0,'','Lafoo SAI only activates if player is on and has not completed the Appeasing the Great rainstone'),
(22,1,@LAFOO,0,0,29,0,@GLINTINGDIRT,10,0,0,0,'','Execute SAI only if there is glinting dirt within 5 yards'),
(22,1,@LAFOO,0,1,9,0,12572,0,0,0,0,'','Lafoo SAI only activates if player is on and has not completed the Gods like shiny things'),
(22,1,@LAFOO,0,1,29,0,@GLINTINGDIRT,10,0,0,0,'','Execute SAI only if there is glinting dirt within 5 yards'),
(22,1,@JALOOT,0,0,9,0,12704,0,0,0,0,'','Jaloot SAI only activates if player is on and has not completed the Appeasing the Great rainstone'),
(22,1,@JALOOT,0,0,29,0,@GLINTINGDIRT,10,0,0,0,'','Execute SAI only if there is glinting dirt within 5 yards'),
(22,1,@MOODLE,0,0,9,0,12704,0,0,0,0,'','Moodle SAI only activates if player is on and has not completed the Appeasing the Great rainstone'),
(22,1,@MOODLE,0,0,29,0,@GLINTINGDIRT,10,0,0,0,'','Execute SAI only if there is glinting dirt within 5 yards'),
(22,1,@GLINTINGDIRT,0,0,29,1,@LAFOO,5,0,0,0,'','Execute SAI only if Lafoo within 2 yards'),
(22,1,@GLINTINGDIRT,0,1,29,1,@JALOOT,5,0,0,0,'','Execute SAI only if Jaloot within 2 yards'),
(22,1,@GLINTINGDIRT,0,2,29,1,@MOODLE,5,0,0,0,'','Execute SAI only if Moodle within 2 yards'),
(22,13,@MOODLE,0,0,23,1,4297,0,0,1,0,'','Moodle dont execute SAI in Mosswalker Village'),
(22,9,@GOREGEK,0,0,23,1,4303,0,0,1,0,'','Goregek dont execute SAI in Hardknuckle Clearing'),
(22,10,@ZEPIK,0,0,23,1,4306,0,0,1,0,'','Zepik dont execute SAI in Mistwhisper Refuge'),
(22,12,@GOREGEK,0,0,23,1,4303,0,0,0,0,'','Goregek execute SAI in only in Hardknuckle Clearing'),
(22,9,@DAJIK,0,0,23,1,4304,0,0,1,0,'','Dajik Dont execute SAI in Sapphire Hive'),
(22,9,@DAJIK,0,0,23,1,4303,0,0,1,0,'','Dajik execute SAI in Hardknuckle Clearing'),
(22,9,@DAJIK,0,0,23,1,4388,0,0,1,0,'','Dajik execute SAI in Wintergrasp River'),
(22,9,@DAJIK,0,0,23,1,4295,0,0,1,0,'','Dajik execute SAI in The Sundered Shard'),
(22,19,@DAJIK,0,0,23,1,4303,0,0,0,0,'','Dajik execute SAI only in Hardknuckle Clearing'),
(22,11,@LAFOO,0,0,23,1,4291,0,0,1,0,'','Lafoo dont execute sai in rainspeaker canopy'),
(22,13,@JALOOT,0,0,23,1,4291,0,0,1,0,'','Jaloot dont execute sai in rainspeaker canopy'),
(22,13,@JALOOT,0,1,23,1,4308,0,0,1,0,'','Jaloot dont execute sai in spearborn encampment'),
(22,13,@MOODLE,0,0,23,1,4291,0,0,1,0,'','Moodle dont execute sai in rainspeaker canopy'),
(22,9,@GOREGEK,0,0,23,1,4292,0,0,1,0,'','Goregek dont execute sai in frenzyheart hill'),
(22,9,@DAJIK,0,0,23,1,4292,0,0,1,0,'','Dajik dont execute sai in frenzyheart hill'),
(22,10,@ZEPIK,0,0,23,1,4292,0,0,1,0,'','Zepik dont execute sai in frenzyheart hill'),
(22,2,@MOSSWALKERBUNNY,0,0,1,0,@SHOLAZARGUARDIANHEARTBEAT,0,0,0,0,'','Mosswalker Bunny execute SAI only if player has sholazar guardian heartbeat aura');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= @HARDKNUCKLEMATRIARCH;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@HARDKNUCKLEMATRIARCH;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@HARDKNUCKLEMATRIARCH;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@HARDKNUCKLEMATRIARCH, 0, 0, 1, 4, 0, 100, 0, 0, 0, 0, 0, 11, 54287, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hardknuckle Matriarch - On Agro - Cast Enrage'),
(@HARDKNUCKLEMATRIARCH, 0, 1, 0,61, 0, 100, 0, 0, 0, 0, 0, 1 , 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hardknuckle Matriarch - Linked with Previous Event - Say'),
(@HARDKNUCKLEMATRIARCH, 0, 2, 0, 0, 0, 100, 0, 6000, 10000, 12000, 15000, 11 , 61580, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hardknuckle Matriarch - In Combat - Cast Cast Thunderstomp'),
(@HARDKNUCKLEMATRIARCH, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, @GOREGEK, 0, 50, 0, 0, 0, 0, 'Hardknuckle Matriarch - On Death Send Data to Goregek');

-- DELETE FROM `creature_ai_texts` WHERE `entry`= -738;
DELETE FROM `creature_text` WHERE `entry`=@HARDKNUCKLEMATRIARCH;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(@HARDKNUCKLEMATRIARCH, 0, 0, 'We are Not Amused', 12, 0, 100, 0, 0, 0, 'Hardknuckle Matriarch');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= @SAPPHIREQUEEN;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@SAPPHIREQUEEN;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SAPPHIREQUEEN;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@SAPPHIREQUEEN, 0, 0, 0, 0, 0, 100, 0, 6000, 9000, 9000, 14000, 11, 48193, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sapphire Hive Queen - IC - Cast Poison Stinger'),
(@SAPPHIREQUEEN, 0, 1, 0, 2, 0, 100, 0, 0, 30, 12000, 15000, 11, 54761, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sapphire Hive Queen - On 30% Hp - Cast Enrage'),
(@SAPPHIREQUEEN, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, @DAJIK, 0, 50, 0, 0, 0, 0, 'Sapphire Hive Queen - On Death - Set Data Dajik');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= @VENOMTIP;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@VENOMTIP;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@VENOMTIP;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@VENOMTIP, 0, 0, 0, 0, 0, 100, 0, 7000, 9000, 17000, 20000, 11, 61550, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Venomtip - IC - Cast Cobra Strike'),
(@VENOMTIP, 0, 1, 0, 9, 0, 100, 0, 0, 30, 7000, 12000, 11, 32330, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Venomtip - On Range - Cast Poison Spit'),
(@VENOMTIP, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, @LAFOO, 0, 50, 0, 0, 0, 0, 'Venomtip - On Death - Set Data Lafoo');
