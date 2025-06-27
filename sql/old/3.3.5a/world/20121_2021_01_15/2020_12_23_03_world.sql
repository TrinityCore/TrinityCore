--
UPDATE `creature_model_info` SET `BoundingRadius`=0.004999999888241291, `CombatReach`=0.009999999776482582 WHERE `DisplayID`=13069;

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (39717,39715,39716,12786,12787,29668,29671,34952,29669,29670,34953,15650,28714,28701,32514,28721,28715,28727,28723,32516,29478,29491,29812,29714,28989,31851,28951,28776,29528,29497));

UPDATE `creature_addon` SET `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 26253);
UPDATE `creature_addon` SET `auras`='16428' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 11896); -- 11896 (Borelgore) - Virulent Poison Proc
UPDATE `creature_addon` SET `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 16378); -- 16378 (Argent Sentry) - Invisibility and Stealth Detection

DELETE FROM `creature_template_addon` WHERE `entry` IN (39717 /*39717 (Shooting Mechano-Tank) - Freeze Anim*/, 39715 /*39715 (Ejector Mechano-Tank) - Freeze Anim*/, 39675 /*39675 (Captain Tread Sparknozzle) - [DND] Persuaded*/, 39716 /*39716 (Scuttling Mechano-Tank) - Freeze Anim*/, 19445 /*19445 (Wounded Soldier) - Invisibility and Stealth Detection*/, 26253 /*26253 (Shattered Sun Peacekeeper) - Invisibility and Stealth Detection*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(39717, 0, 0, 0, 1, 0, '16245 25900'), -- 39717 (Shooting Mechano-Tank) - Freeze Anim
(39715, 0, 0, 0, 1, 0, '16245 25900'), -- 39715 (Ejector Mechano-Tank) - Freeze Anim
(39675, 0, 0, 0, 1, 0, '73954'), -- 39675 (Captain Tread Sparknozzle) - [DND] Persuaded
(39716, 0, 0, 0, 1, 0, '16245 25900'), -- 39716 (Scuttling Mechano-Tank) - Freeze Anim
(19445, 0, 0, 7, 1, 0, '18950'), -- 19445 (Wounded Soldier) - Invisibility and Stealth Detection
(26253, 0, 0, 0, 1, 0, '18950'); -- 26253 (Shattered Sun Peacekeeper) - Invisibility and Stealth Detection

UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='5301' WHERE `entry`=12786; -- 12786 (Guard Quine)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='5301' WHERE `entry`=12787; -- 12787 (Guard Hammon)
UPDATE `creature_template_addon` SET `auras`='28782' WHERE `entry`=29668;
UPDATE `creature_template_addon` SET `auras`='28782' WHERE `entry`=29671;
UPDATE `creature_template_addon` SET `auras`='28782' WHERE `entry`=34952;
UPDATE `creature_template_addon` SET `auras`='28782' WHERE `entry`=29669;
UPDATE `creature_template_addon` SET `auras`='28782' WHERE `entry`=29670;
UPDATE `creature_template_addon` SET `auras`='28782' WHERE `entry`=29667;
UPDATE `creature_template_addon` SET `auras`='28782' WHERE `entry`=29673;
UPDATE `creature_template_addon` SET `auras`='28782' WHERE `entry`=29675;
UPDATE `creature_template_addon` SET `auras`='28782' WHERE `entry`=34953;
UPDATE `creature_template_addon` SET `auras`='16575' WHERE `entry`=8535; -- 8535 (Putrid Shrieker)
UPDATE `creature_template_addon` SET `auras`='29119' WHERE `entry`=15650; -- 15650 (Crazed Dragonhawk)
UPDATE `creature_template_addon` SET `auras`='12896' WHERE `entry`=5993; -- 5993 (Helboar)
UPDATE `creature_template_addon` SET `auras`='32008' WHERE `entry`=18944; -- 18944 (Fel Soldier)
UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=19446; -- 19446 (Operations Officer)
UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=20513; -- 20513 (Honor Hold Defender)
UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=17557; -- 17557 (Lieutenant Chadwick)
UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=19392; -- 19392 (Watch Commander Leonus)
UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=17479; -- 17479 (Gunny)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=28714; -- 28714 (Ildine Sorrowspear)
UPDATE `creature_template_addon` SET `auras`='50200' WHERE `entry`=28701; -- 28701 (Timothy Jones)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=32514; -- 32514 (Vanessa Sellers)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=28721; -- 28721 (Tiffany Cartier)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=28715; -- 28715 (Endora Moorehead)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=33027; -- 33027 (Jessica Sellers)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=28727; -- 28727 (Edward Egan)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=28723; -- 28723 (Larana Drome)
UPDATE `creature_template_addon` SET `auras`='55474' WHERE `entry`=32516; -- 32516 (Washed-Up Mage)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=29478; -- 29478 (Jepetto Joybuzz)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=29491; -- 29491 (Karandonna)
UPDATE `creature_template_addon` SET `auras`='28782' WHERE `entry`=29812; -- 29812 ([DND] Dalaran Toy Store Plane String Bunny)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=29714; -- 29714 (Lucian Trias)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=28989; -- 28989 (Aemara)
UPDATE `creature_template_addon` SET `auras`='60190' WHERE `entry`=31851; -- 31851 (Wooly Mammoth)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=28951; -- 28951 (Breanni)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=28776; -- 28776 (Elizabeth Ross)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=29528; -- 29528 (Debbi Moore)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=29497; -- 29497 (Walther Whiteford)
UPDATE `creature_template_addon` SET `auras`='11984' WHERE `entry`=5858; -- 5858 (Greater Lava Spider)
UPDATE `creature_template_addon` SET `auras`='7276' WHERE `entry`=2260; -- 2260 (Syndicate Rogue)
UPDATE `creature_template_addon` SET `auras`='3417' WHERE `entry`=24819; -- 24819 (Anvilrage Enforcer)

UPDATE `creature_template_addon` SET `auras`='11441' WHERE `entry`=8606; -- 8606 (Living Decay)
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 8606;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8606 AND `source_type` = 0;

UPDATE `creature_template_addon` SET `auras`='8247' WHERE `entry`=1824; -- 1824 (Plague Lurker)
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 1824;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1824 AND `source_type` = 0;

UPDATE `creature_template_addon` SET `auras`='11964' WHERE `entry`=5983; -- 5983 (Bonepicker Felfeeder)
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 5983;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 5983 AND `source_type` = 0;

UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=19444; -- 19444 (Peasant Worker)
UPDATE `creature_addon` SET `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 19444);

UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=16842; -- 16842 (Honor Hold Defender)
UPDATE `creature_addon` SET `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 16842);

UPDATE `creature_template_addon` SET `auras`='5301' WHERE `entry`=19687; -- 19687 (Shattrath City Peacekeeper)
UPDATE `creature_addon` SET `auras`='5301' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 19687);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 32169;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32169 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32169,0,0,0,1,0,100,0,0,0,30000,30000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcanist Braedin - Out of Combat - Cast 'Frost Armor'");

UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=32724; -- 32724 (Warmage Mumplina)
UPDATE `creature_addon` SET `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 32724);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 32724;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32724 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32724,0,0,0,1,0,100,0,0,0,30000,30000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Mumplina - Out of Combat - Cast 'Frost Armor'");

UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=32722; -- 32722 (Warmage Lukems)
UPDATE `creature_addon` SET `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 32722);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 32722;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32722 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32722,0,0,0,1,0,100,0,0,0,30000,30000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Lukems - Out of Combat - Cast 'Frost Armor'");

-- Dup
DELETE FROM `creature` WHERE `guid` = 104493 AND `id` = 32606;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 32606;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32606 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 3260600 AND 3260604 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32606,0,0,0,11,0,100,0,0,0,0,0,0,88,3260600,3260604,0,0,0,0,1,0,0,0,0,0,0,0,0,"[DND] Cosmetic Book - On Respawn - Run Random Script"),

(3260600,9,0,0,0,0,100,0,0,0,0,0,0,11,61378,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"[DND] Cosmetic Book - On Script - Cast '[DND] Dalaran - Book_Dwarf_01 Visual'"),
(3260601,9,0,0,0,0,100,0,0,0,0,0,0,11,61403,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"[DND] Cosmetic Book - On Script - Cast '[DND] Dalaran - Book_Human_01 Visual'"),
(3260602,9,0,0,0,0,100,0,0,0,0,0,0,11,61404,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"[DND] Cosmetic Book - On Script - Cast '[DND] Dalaran - Book_Human_03 Visual'"),
(3260603,9,0,0,0,0,100,0,0,0,0,0,0,11,61405,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"[DND] Cosmetic Book - On Script - Cast '[DND] Dalaran -  Book_Human_04 Visual'"),
(3260604,9,0,0,0,0,100,0,0,0,0,0,0,11,61406,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"[DND] Cosmetic Book - On Script - Cast '[DND] Dalaran - Book_Troll_02 Visual'");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 32170;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 32170 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32170,0,0,0,1,0,100,0,0,0,30000,30000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Magister Surdiel - Out of Combat - Cast 'Frost Armor'");

UPDATE `creature_template_addon` SET `auras`='13589' WHERE `entry`=24818; -- 24818 (Anvilrage Taskmaster)
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24818 AND `source_type` = 0 AND `id` = 1;

UPDATE `creature_template_addon` SET `auras`='5301' WHERE `entry`=1423; -- 1423 (Stormwind Guard)
UPDATE `creature_addon` SET `auras`='5301' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 1423);

UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='18950' WHERE `entry`=14423; -- 14423 (Officer Jaxon)
UPDATE `creature_addon` SET `bytes2`=257, `auras`='18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 14423);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 35596;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35596 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(35596,0,0,0,1,0,100,0,0,0,30000,30000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcanist Iramhir - Out of Combat - Cast 'Frost Armor'");

DELETE FROM `creature_template_addon` WHERE `entry` IN (16354);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(16354, 0, 0, 0, 1, 0, '29363'); -- 16354 (Vampiric Mistbat) - Draining Touch
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (16354));
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 16354;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16354 AND `source_type` = 0;

DELETE FROM `creature_template_addon` WHERE `entry` IN (8532);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(8532, 0, 0, 0, 1, 0, '8876 12539'); -- 8532 (Diseased Flayer) - Thrash, Ghoul Rot
DELETE FROM `creature_addon` WHERE `path_id` = 0 AND `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (8532));
UPDATE `creature_addon` SET `bytes2`=1, `auras`='8876 12539' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 8532);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8532 AND `source_type` = 0 AND `id` = 1;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 8546 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8546,0,2,0,25,0,100,0,0,0,0,0,0,11,3417,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dark Adept - On Reset - Cast 'Thrash'");

-- No stealth
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8539 AND `source_type` = 0 AND `id` = 2; -- 8539 (Eyeless Watcher) - Stealth Detection
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8538 AND `source_type` = 0 AND `id` = 2; -- 8538 (Unseen Servant) - Stealth Detection

UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=29812; -- [DND] Dalaran Toy Store Plane String Bunny
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=12779; -- Archmage Gaiman
UPDATE `creature_template` SET `minlevel`=75, `maxlevel`=75, `unit_flags`=32768 WHERE `entry`=12786; -- Guard Quine
UPDATE `creature_template` SET `minlevel`=75, `maxlevel`=75, `unit_flags`=32768 WHERE `entry`=12787; -- Guard Hammon
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=19848; -- Harbinger Ennarth
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=12784; -- Lieutenant Jackspring
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=12778; -- Lieutenant Rachel Vaccar
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=35477; -- Little Adeline
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=12785; -- Sergeant Major Clate
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=12780; -- Sergeant Major Skyshadow
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=12781; -- Master Sergeant Biggins
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=39678; -- Toby Zeigear
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=7955; -- Milli Featherwhistle
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=39368; -- Drill Sergeant Steamcrank
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=39717; -- Shooting Mechano-Tank
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=39275; -- Gnomeregan Medic
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `unit_flags`=768 WHERE `entry`=39396; -- 'Thunderflash'
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=39386; -- Pilot Muzzlesprock
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=39715; -- Ejector Mechano-Tank
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=39675; -- Captain Tread Sparknozzle
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=39716; -- Scuttling Mechano-Tank
UPDATE `creature_template` SET `minlevel`=8, `maxlevel`=10, `unit_flags`=33536 WHERE `entry`=39349; -- Gnomeregan Trainee
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=37888; -- Frax Bucketdrop
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=17984; -- Power Source Invisible Bunny
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags2`=0 WHERE `entry`=25031; -- Pit Overlord
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=25033; -- Eredar Sorcerer
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=24972; -- Erratic Sentry
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=25172; -- Archmage Invisible Target
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=25163; -- Anchorite Kairthos
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=25108; -- Vindicator Kaalan
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=25035; -- Tyrael Flamekissed
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=25043; -- Sereth Duskbringer
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=25039; -- Kaalif
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=24975; -- Mar'nah
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=25950; -- Shaani
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=26092; -- Soryn
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags2`=2050 WHERE `entry`=25192; -- Bridge Marksman Target Bunny
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=24960; -- Wretched Devourer
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=25045; -- Sentinel
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=25112; -- Anchorite Ayuri
UPDATE `creature_template` SET `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=25037; -- Seraphina Bloodheart
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=25036; -- Caregiver Inaara
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24980; -- Crystal Ward
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24991; -- Converted Sentry Credit
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=25133; -- Astromancer Darnarian
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=25115; -- Shattered Sun Warrior (512 if tempsummon or something like that)
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=24938; -- Shattered Sun Marksman (512 if tempsummon or something like that)
UPDATE `creature_template` SET `minlevel`=55 WHERE `entry`=7671; -- Servant of Sevine
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18969; -- Melgromm Highmountain
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18986; -- Ironforge Paladin
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18972; -- Orgrimmar Shaman
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33024 WHERE `entry`=18950; -- Orgrimmar Grunt
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18966; -- Justinius the Harbinger
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18970; -- Darkspear Axe Thrower
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18965; -- Darnassian Archer
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=18948; -- Stormwind Soldier
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=21075; -- Infernal Target (Hyjal)
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=16897; -- Honor Hold Target Dummy Middle
UPDATE `creature_template` SET `maxlevel`=60 WHERE `entry`=16866; -- Injured Nethergarde Infantry
UPDATE `creature_template` SET `BaseAttackTime`=2000 WHERE `entry`=18827; -- Gan'arg Sapper
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags2`=2048 WHERE `entry`=18729; -- Infernal Rain (Hellfire)
UPDATE `creature_template` SET `minlevel`=62 WHERE `entry`=18539; -- Ashkaz
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=25580; -- Old Man Barlo
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=18750; -- Shimmerscale Eel
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=25143; -- Shattered Sun Veteran
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=25135; -- Shattered Sun Trainee
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=25136; -- Shattered Sun Trainee
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=25134; -- Shattered Sun Trainee
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=25137; -- Shattered Sun Trainee
UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry`=25142; -- Shattered Sun Marksman
UPDATE `creature_template` SET `speed_run`=2.285714387893676757 WHERE `entry`=25246; -- Lady Liadrin
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=29668; -- Arathi Basin Portal
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=29671; -- Strand of the Ancients Portal
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=34952; -- Isle of Conquest Portal
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=29669; -- Alterac Valley Portal
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=29670; -- Eye of the Storm Portal
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=29667; -- Warsong Gulch Portal
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=29641; -- Theresa Wolf
UPDATE `creature_template` SET `speed_run`=1.428571462631225585 WHERE `entry`=32653; -- Wounded Dalaran Serpent
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=28714; -- Ildine Sorrowspear
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=28706; -- Olisarra the Kind
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=29628; -- Angelique Butler
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=28995; -- Paldesse
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=28704; -- Dorothy Egan
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32744; -- Bakor the Gangly
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=28716; -- Palja Amboss
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=35498; -- Horace Hunderland
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=29505; -- Imindril Spearsong
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=35496; -- Rueben Lauren
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32731; -- Metopious Loreseeker
UPDATE `creature_template` SET `speed_run`=1.142857193946838378, `unit_flags2`=0 WHERE `entry`=32333; -- "Dapper" Danik Blackshaft
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=28990; -- Anthony Durain
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=32332; -- Ramik Slamwrench
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32329; -- Kanika Goldwell
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=29703; -- Sheddle Glossgleam
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=29673; -- Arathi Basin Portal
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=28708; -- Kizi Copperclip
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=29675; -- Eye of the Storm Portal
UPDATE `creature_template` SET `unit_flags`=768 WHERE `entry`=34953; -- Isle of Conquest Portal
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=29478; -- Jepetto Joybuzz
UPDATE `creature_template` SET `speed_run`=1 WHERE `entry`=29802; -- Cosmetic Toy Plane
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32676; -- Grindle Firespark
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32680; -- Fabioso the Fabulous
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32678; -- Emeline Fizzlefry
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.992062866687774658 WHERE `entry`=31755; -- Stabled Hunter Pet
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=28687; -- Amisi Azuregaze
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=31769; -- Stabled Hunter Pet
UPDATE `creature_template` SET `unit_flags2`=2050 WHERE `entry`=35608; -- [DND] Dalaran Argent Tournament Herald Bunny
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=29255; -- Sunreaver Guardian Mage
UPDATE `creature_template` SET `speed_run`=1.142857193946838378 WHERE `entry`=32689; -- Adorean Lew
UPDATE `creature_template` SET `speed_run`=0.952381432056427001 WHERE `entry`=31768; -- Stabled Hunter Pet
UPDATE `creature_template` SET `speed_run`=0.857142865657806396 WHERE `entry`=30095; -- Dalaran Sewer Turtle
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry`=37853; -- Instructor Razuvious Image
