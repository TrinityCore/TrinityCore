    /*//////////////////////////////////////////////////////////////////////
   //  FunSocietyWoW - SAI DEV                                           //
  //  Copyright 2018 FunSocietyWoW and Ashamane Core //
 //  All Rights Reserved                                                       //
//////////////////////////////////////////////////////////////////////////

/*#############
# Mardum Part - 2   #
#############*/

-- Anguish Jailer SAI
SET @ANGUISH_JAILER := 95226;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ANGUISH_JAILER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ANGUISH_JAILER AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ANGUISH_JAILER*100+00,@ANGUISH_JAILER*100+01,@ANGUISH_JAILER*100+02,@ANGUISH_JAILER*100+03) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ANGUISH_JAILER,0,0,0,0,0,100,0,1000,2000,3000,4000,11,200502,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anguish Jailer - In Combat - Cast 'Anguished Soul'"),
(@ANGUISH_JAILER,0,1,0,6,0,100,0,0,0,0,0,11,200521,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anguish Jailer - On Just Died - Cast 'Well of Souls Soul Visual'"),
(@ANGUISH_JAILER,0,2,0,26,0,75,1,0,10,0,0,87,@ANGUISH_JAILER*100+00,@ANGUISH_JAILER*100+01,@ANGUISH_JAILER*100+02,@ANGUISH_JAILER*100+03,0,0,1,0,0,0,0,0,0,0,"Anguish Jailer - In Combat LoS - Run Random Script (No Repeat)"),
(@ANGUISH_JAILER*100+00,9,0,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Anguish Jailer - On Script - Say Line 0"),
(@ANGUISH_JAILER*100+01,9,0,0,0,0,100,0,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Anguish Jailer - On Script - Say Line 1"),
(@ANGUISH_JAILER*100+02,9,0,0,0,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,0,0,0,0,0,0,0,0,"Anguish Jailer - On Script - Say Line 2"),
(@ANGUISH_JAILER*100+03,9,0,0,0,0,100,0,0,0,0,0,1,3,5000,0,0,0,0,0,0,0,0,0,0,0,0,"Anguish Jailer - On Script - Say Line 3");

DELETE FROM `creature_text` WHERE `CreatureID` = 95226;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(95226, 0, 0, 'I''ll crack open your flesh and feed upon your soul.', 12, 0, 100, 0, 0, 55016, 0, 'Anguish Jailer to Player'),
(95226, 1, 0, 'In this place, you are the hunted.', 12, 0, 100, 0, 0, 55053, 0, 'Anguish Jailer to Player'),
(95226, 2, 0, 'I am your judge, jury, and executioner.', 12, 0, 100, 0, 0, 55020, 0, 'Anguish Jailer to Player'),
(95226, 3, 0, 'Into my cage you go.', 12, 0, 100, 0, 0, 55017, 0, 'Anguish Jailer to Player');

-- Felguard Sentry SAI
SET @FELGUARD_SENTRY := 93112;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@FELGUARD_SENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FELGUARD_SENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@FELGUARD_SENTRY*100+01,@FELGUARD_SENTRY*100+02) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FELGUARD_SENTRY,0,1,0,10,0,100,1,1,10,0,0,87,@FELGUARD_SENTRY*100+01,@FELGUARD_SENTRY*100+02,0,0,0,0,1,0,0,0,0,0,0,0,"Felguard Sentry - Within 1-10 Range Out of Combat LoS - Run Random Script (No Repeat)"),
(@FELGUARD_SENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,200570,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felguard Sentry - In Combat - Cast 'Blazing Blade'"),
(@FELGUARD_SENTRY*100+01,9,0,0,0,0,100,0,100,100,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Felguard Sentry - On Script - Say Line 0"),
(@FELGUARD_SENTRY*100+02,9,0,0,0,0,100,0,100,100,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Felguard Sentry - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 93112;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(93112, 0, 0, 'The fel you wield will not be enough.', 12, 0, 100, 0, 0, 55190, 0, 'Felguard Sentry to Player'),
(93112, 1, 0, 'Die, Illidari fool.', 12, 0, 100, 0, 0, 55189, 0, 'Felguard Sentry to Player');

-- Sevis Brightflame 2 SAI
SET @SEVIS_BRIGHTFLAME_2 := 99917;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@SEVIS_BRIGHTFLAME_2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SEVIS_BRIGHTFLAME_2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SEVIS_BRIGHTFLAME_2,0,0,0,10,0,100,1,1,30,0,0,1,0,5000,0,0,0,0,18,30,0,0,0,0,0,0,"Sevis Brightflame - Within 1-30 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(@SEVIS_BRIGHTFLAME_2,0,1,0,52,0,100,0,1,99917,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Text 1 Over - Say Line 1"),
(@SEVIS_BRIGHTFLAME_2,0,2,0,52,0,100,0,2,99917,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Sevis Brightflame - On Text 2 Over - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID` = 99917;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(99917, 0, 0, '$n, hurry! You don''t have much time.', 12, 0, 100, 3, 0, 55345, 0, 'Sevis Brightflame to Player'),
(99917, 1, 0, 'Sevis looks down at the dying broken mystic.', 16, 0, 100, 3, 0, 55345, 0, 'Sevis Brightflame to Player'),
(99917, 2, 0, 'I will see you at the final gateway.', 12, 0, 100, 1, 0, 55347, 0, 'Sevis Brightflame to Player');

-- Colossal Infernal
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=954, `speed_walk`=4, `speed_run`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=16448, `unit_flags2`=1073743872, `unit_flags3`=0, `dynamicflags`=0, `VehicleId`=0, `HoverHeight`=1 WHERE `entry`=94492;

-- Mannethrel Darkstar SAI
SET @MANNETHREL_DARKSTAR := 93230;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@MANNETHREL_DARKSTAR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MANNETHREL_DARKSTAR AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MANNETHREL_DARKSTAR,0,0,0,63,0,100,512,0,0,0,0,58,5,242990,3000,1,5,0,1,0,0,0,0,0,0,0,"Mannethrel Darkstar - On Just Created - Install Caged Creature Part Template"),
(@MANNETHREL_DARKSTAR,0,1,0,10,0,100,1,1,10,30000,30000,1,0,5000,0,0,0,0,18,10,0,0,0,0,0,0,"Mannethrel Darkstar - Within 1-10 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(@MANNETHREL_DARKSTAR,0,2,0,52,0,100,0,0,93230,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mannethrel Darkstar - On Text 0 Over - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 93230;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(93230, 0, 0, 'So weak... hard to contain... my energy.', 12, 0, 100, 0, 0, 55310, 0, 'Mannethrel Darkstar to Player'),
(93230, 1, 0, 'I almost lost the fight against the fel energy inside me.', 12, 0, 100, 6, 0, 55311, 0, 'Mannethrel Darkstar to Player');

-- Belath Dawnblade SAI
SET @BELATH_DAWNBLADE := 94400;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@BELATH_DAWNBLADE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BELATH_DAWNBLADE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BELATH_DAWNBLADE,0,0,0,63,0,100,512,0,0,0,0,58,5,242989,3000,1,5,0,1,0,0,0,0,0,0,0,"Belath Dawnblade - On Just Created - Install Caged Creature Part Template"),
(@BELATH_DAWNBLADE,0,1,0,10,0,100,1,1,10,30000,30000,1,0,5000,0,0,0,0,18,10,0,0,0,0,0,0,"Belath Dawnblade - Within 1-10 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(@BELATH_DAWNBLADE,0,2,0,52,0,100,0,0,94400,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Belath Dawnblade - On Text 0 Over - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 94400;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(94400, 0, 0, 'I will destroy all of you.', 12, 0, 100, 0, 0, 55052, 0, 'Belath Dawnblade to Player'),
(94400, 1, 0, 'I will kill every last demon in my way.', 12, 0, 100, 5, 0, 55053, 0, 'Belath Dawnblade to Player');

-- Cyana Nightglaive SAI
SET @CYANA_NIGHTGLAIVE := 94377;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@CYANA_NIGHTGLAIVE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@CYANA_NIGHTGLAIVE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@CYANA_NIGHTGLAIVE,0,1,0,10,0,100,1,1,10,30000,30000,1,0,5000,0,0,0,0,18,10,0,0,0,0,0,0,"Cyana Nightglaive - Within 1-10 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(@CYANA_NIGHTGLAIVE,0,2,0,52,0,100,0,0,94377,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Cyana Nightglaive - On Text 0 Over - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 94377;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(94377, 0, 0, 'I... will not... give in!', 14, 0, 100, 0, 0, 55090, 0, 'Cyana Nightglaive to Player'),
(94377, 1, 0, 'I will never be taken prisoner again. Never!', 12, 0, 100, 5, 0, 55089, 0, 'Cyana Nightglaive to Player');

-- Izal Whitemoon SAI
SET @IZAL_WHITEMOON := 93117;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@IZAL_WHITEMOON;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@IZAL_WHITEMOON AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@IZAL_WHITEMOON,0,0,0,63,0,100,512,0,0,0,0,58,5,242987,3000,1,5,0,1,0,0,0,0,0,0,0,"Izal Whitemoon - On Just Created - Install Caged Creature Part Template"),
(@IZAL_WHITEMOON,0,1,0,10,0,100,1,1,10,30000,30000,1,0,5000,0,0,0,0,18,10,0,0,0,0,0,0,"Izal Whitemoon - Within 1-10 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(@IZAL_WHITEMOON,0,2,0,52,0,100,0,0,93117,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Izal Whitemoon - On Text 0 Over - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 93117;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(93117, 0, 0, 'The pain!', 12, 0, 100, 0, 0, 55226, 0, 'Izal Whitemoon to Player'),
(93117, 1, 0, 'A slight setback. I assure you it will not happen again.', 12, 0, 100, 274, 0, 55227, 0, 'Izal Whitemoon to Player');

-- Abyssal Basilisk SAI
SET @ABYSSAL_BASILISK := 101288;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ABYSSAL_BASILISK;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ABYSSAL_BASILISK AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ABYSSAL_BASILISK,0,0,0,0,0,100,0,5000,8000,12000,15000,11,200594,0,0,0,0,0,2,0,0,0,0,0,0,0,"Abyssal Basilisk - In Combat - Cast 'Fel Gaze'");

-- Foul Felstalker
SET @FOUL_FELSTALKER := 93115;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@FOUL_FELSTALKER;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@FOUL_FELSTALKER;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FOUL_FELSTALKER,0,0,0,0,0,100,0,5000,8000,12000,15000,11,200420,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foul Felstalker - In Combat - Cast 'Foul Fel'");

-- Some NPC set Random Move
UPDATE `creature` SET `guid`='20542259', `id`='101288', `position_x`='1713.74', `position_y`='1697.98', `position_z`='68.7694', `orientation`='3.11228', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542259');
UPDATE `creature` SET `guid`='20542101', `id`='101288', `position_x`='1704.68', `position_y`='1314.66', `position_z`='60.6473', `orientation`='5.37988', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542101');
UPDATE `creature` SET `guid`='20542099', `id`='101288', `position_x`='1766.75', `position_y`='1223.8', `position_z`='144.62', `orientation`='3.86106', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542099');
UPDATE `creature` SET `guid`='20542093', `id`='101288', `position_x`='1715.32', `position_y`='1181.14', `position_z`='103.545', `orientation`='2.42427', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542093');
UPDATE `creature` SET `guid`='20542083', `id`='101288', `position_x`='1689.46', `position_y`='1210.55', `position_z`='69.2249', `orientation`='2.12311', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542083');
UPDATE `creature` SET `guid`='20542078', `id`='101288', `position_x`='1649.93', `position_y`='1232.88', `position_z`='55.127', `orientation`='4.00853', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542078');
UPDATE `creature` SET `guid`='20542077', `id`='101288', `position_x`='1637.01', `position_y`='1262.48', `position_z`='50.5129', `orientation`='2.56132', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542077');
UPDATE `creature` SET `guid`='20542064', `id`='101288', `position_x`='1610.12', `position_y`='1277.9', `position_z`='27.6147', `orientation`='2.11909', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542064');
UPDATE `creature` SET `guid`='20542037', `id`='101288', `position_x`='1589.73', `position_y`='1117.85', `position_z`='74.8069', `orientation`='0.922022', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542037');
UPDATE `creature` SET `guid`='20542036', `id`='101288', `position_x`='1606.84', `position_y`='1097.35', `position_z`='66.8782', `orientation`='0.251955', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542036');
UPDATE `creature` SET `guid`='20542035', `id`='101288', `position_x`='1625.74', `position_y`='1069.15', `position_z`='88.9657', `orientation`='2.31953', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542035');
UPDATE `creature` SET `guid`='20542032', `id`='101288', `position_x`='1597.59', `position_y`='1068.52', `position_z`='70.0325', `orientation`='1.08257', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542032');
UPDATE `creature` SET `guid`='20542029', `id`='101288', `position_x`='1510.38', `position_y`='940.164', `position_z`='60.2', `orientation`='4.50542', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542029');
UPDATE `creature` SET `guid`='20542027', `id`='101288', `position_x`='1581.93', `position_y`='1048.27', `position_z`='59.5246', `orientation`='2.72944', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542027');
UPDATE `creature` SET `guid`='20542018', `id`='101288', `position_x`='1553.41', `position_y`='1080.85', `position_z`='63.205', `orientation`='4.58551', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542018');
UPDATE `creature` SET `guid`='20542007', `id`='101288', `position_x`='1471.21', `position_y`='994.149', `position_z`='62.4731', `orientation`='1.24748', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20542007');
UPDATE `creature` SET `guid`='20541539', `id`='101288', `position_x`='1536.11', `position_y`='1848.44', `position_z`='3.10782', `orientation`='5.4913', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541539');
UPDATE `creature` SET `guid`='20541538', `id`='101288', `position_x`='1540.92', `position_y`='1849.79', `position_z`='3.01148', `orientation`='4.86809', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541538');
UPDATE `creature` SET `guid`='20541536', `id`='101288', `position_x`='1546.59', `position_y`='1871.11', `position_z`='1.28776', `orientation`='2.94289', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541536');
UPDATE `creature` SET `guid`='20541531', `id`='101288', `position_x`='1519.44', `position_y`='1884.1', `position_z`='0.404917', `orientation`='3.47439', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541531');
UPDATE `creature` SET `guid`='20541520', `id`='101288', `position_x`='1446.23', `position_y`='1952.04', `position_z`='85.8111', `orientation`='3.70339', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541520');
UPDATE `creature` SET `guid`='20541518', `id`='101288', `position_x`='1436.96', `position_y`='1969.57', `position_z`='96.6942', `orientation`='0.333607', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541518');
UPDATE `creature` SET `guid`='20541516', `id`='101288', `position_x`='1356.09', `position_y`='2022.85', `position_z`='103.114', `orientation`='0.871825', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541516');
UPDATE `creature` SET `guid`='20541515', `id`='101288', `position_x`='1417.81', `position_y`='2018.74', `position_z`='101.764', `orientation`='0.932082', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541515');
UPDATE `creature` SET `guid`='20541510', `id`='101288', `position_x`='1456.72', `position_y`='2090.27', `position_z`='125.417', `orientation`='3.24817', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541510');
UPDATE `creature` SET `guid`='20541509', `id`='101288', `position_x`='1393.97', `position_y`='2056.16', `position_z`='104.569', `orientation`='4.17751', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541509');
UPDATE `creature` SET `guid`='20541505', `id`='101288', `position_x`='1430.72', `position_y`='2115.73', `position_z`='101.864', `orientation`='5.21028', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541505');
UPDATE `creature` SET `guid`='20541503', `id`='101288', `position_x`='1287.15', `position_y`='2122.23', `position_z`='92.585', `orientation`='6.14298', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541503');
UPDATE `creature` SET `guid`='20541501', `id`='101288', `position_x`='1323.2', `position_y`='2112.31', `position_z`='91.8364', `orientation`='1.25491', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541501');
UPDATE `creature` SET `guid`='20541495', `id`='101288', `position_x`='1421.49', `position_y`='2148.66', `position_z`='102.279', `orientation`='4.45864', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541495');
UPDATE `creature` SET `guid`='20541492', `id`='101288', `position_x`='1336.68', `position_y`='2132.84', `position_z`='93.9432', `orientation`='5.28258', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541492');
UPDATE `creature` SET `guid`='20541490', `id`='101288', `position_x`='1290.96', `position_y`='2195.9', `position_z`='57.6134', `orientation`='5.33473', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541490');
UPDATE `creature` SET `guid`='20541487', `id`='101288', `position_x`='1283.44', `position_y`='2264.21', `position_z`='33.0903', `orientation`='3.37153', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541487');
UPDATE `creature` SET `guid`='20541477', `id`='101288', `position_x`='1396.59', `position_y`='2251.77', `position_z`='80.2813', `orientation`='2.24382', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541477');
UPDATE `creature` SET `guid`='20541475', `id`='101288', `position_x`='1375.75', `position_y`='2233.89', `position_z`='90.0639', `orientation`='0.800239', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541475');
UPDATE `creature` SET `guid`='20541300', `id`='101288', `position_x`='850.407', `position_y`='2432.33', `position_z`='-61.9618', `orientation`='2.57052', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541300');
UPDATE `creature` SET `guid`='20541269', `id`='101288', `position_x`='613.706', `position_y`='2515.28', `position_z`='-81.2338', `orientation`='3.54405', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541269');
UPDATE `creature` SET `guid`='20541247', `id`='101288', `position_x`='717.226', `position_y`='2367.15', `position_z`='-61.5453', `orientation`='4.92195', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541247');
UPDATE `creature` SET `guid`='20541232', `id`='101288', `position_x`='805.54', `position_y`='2453.04', `position_z`='-58.9226', `orientation`='2.84138', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541232');
UPDATE `creature` SET `guid`='20541229', `id`='101288', `position_x`='675.63', `position_y`='2454.63', `position_z`='-72.3121', `orientation`='3.76014', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541229');
UPDATE `creature` SET `guid`='20541210', `id`='101288', `position_x`='758.781', `position_y`='2493.59', `position_z`='-67.5608', `orientation`='1.70538', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541210');
UPDATE `creature` SET `guid`='20541193', `id`='101288', `position_x`='691.399', `position_y`='2540.89', `position_z`='-77.6074', `orientation`='5.56709', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541193');
UPDATE `creature` SET `guid`='20541174', `id`='101288', `position_x`='776.128', `position_y`='2573.58', `position_z`='-70.8312', `orientation`='3.08229', `spawntimesecs`='120', `spawndist`='7', `MovementType`='1', `VerifiedBuild`='22423' WHERE (`guid`='20541174');