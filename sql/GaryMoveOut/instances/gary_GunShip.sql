-- Move NPCs to proper locations
UPDATE `creature` SET  `position_x` =  '-558.109253', `position_y` =  '2205.420654', `position_z` = 199.969559, `orientation` = 3.004918 WHERE  `guid` = 200988;  -- VINDICATOR
UPDATE `creature` SET  `position_x` =  '-531.942566', `position_y` =  '2124.377930', `position_z` = 199.969681, `orientation` = 2.438634 WHERE  `guid` = 201041; -- Horde DEFENDER
UPDATE `creature` SET  `position_x` =  '-540.092224', `position_y` =  '2129.904785', `position_z` = 199.970352, `orientation` = 2.438634 WHERE  `guid` = 201076; -- Ally NPC, 
UPDATE `creature` SET  `position_x` =  '-562.132874', `position_y` =  '2195.537354', `position_z` = 199.969757, `orientation` = 1.466264 WHERE  `guid` = 201020; -- Ally sorcerer
DELETE FROM `creature` WHERE `guid` = 200896;
DELETE FROM `creature` WHERE `guid` = 200917;
DELETE FROM `creature` WHERE `guid` = 201176;

-- Texts
SET @PRIMALIST := 37030;
SET @INVOKER := 37033;
SET @DEFENDER := 37032;
SET @VINDICATOR := 37003;
SET @SORCERER := 37026;
SET @PROTECTOR := 36998;
SET @FROSTWYRM := 37230;
SET @SOUNDID :=0;
DELETE FROM `creature_text` WHERE `entry` IN (37030,37033,37032,37003,37026,36998,37230);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@PRIMALIST,0, 0, 'Thank the spirits for you, brothers and sisters. The Skybreaker has already left. Quickly now, to Orgrim''s Hammer! If you leave soon, you may be able to catch them.', 12, 0, 100, 0, 0, 17161, 'Kor''kron Primalist - SAY_FIRST_SQUAD_RESCUED_HORDE_0'),
(@INVOKER,  0, 0, 'This should be helpin''ya!', 12, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Invoker - SAY_FIRST_SQUAD_RESCUED_HORDE_1'),
(@INVOKER,  1, 0, '%s summons a Kor''kron Battle Standard.', 16, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Invoker - SAY_SUMMON_BATTLE_STANDARD'),
(@DEFENDER, 0, 0, 'Aka''Magosh, brave warriors. The alliance is in great number here.', 12, 0, 100, 0, 0, 17163, 'Kor''kron Defender - SAY_SECOND_SQUAD_RESCUED_HORDE_0'),
(@DEFENDER, 1, 0, 'Captain Saurfang will be pleased to see you aboard Orgrim''s Hammer. Make haste, we will secure the area until you are ready for take-off.', 12, 0, 100, 0, 0, @SOUNDID, 'Kor''kron Defender - SAY_SECOND_SQUAD_RESCUED_HORDE_1'),
(@DEFENDER, 2, 0, 'A screeching cry pierces the air above!',41, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_SUMMON_0'),
(@VINDICATOR, 0, 0, 'Thank goodness you arrived when you did, heroes. Orgrim''s Hammer has already left. Quickly now, to The Skybreaker! If you leave soon, you may be able to catch them.', 12, 0, 100, 0, 0, 17154, 'Skybreaker Vindicator - SAY_FIRST_SQUAD_RESCUED_ALLIANCE_0'),
(@SORCERER, 0, 0, 'This ought to help!', 12, 0, 100, 0, 0, 17155, 'Skybreaker Sorcerer - SAY_FIRST_SQUAD_RESCUED_ALLIANCE_1'),
(@SORCERER, 1, 0, '%s summons a Skybreaker Battle Standard.', 16, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Sorcerer - SAY_SUMMON_BATTLE_STANDARD'),
(@PROTECTOR,0, 0, 'You have my thanks. We were outnumbered until you arrived.', 12, 0, 100, 0, 0, 17157, 'Skybreaker Protector - SAY_SECOND_SQUAD_RESCUED_ALLIANCE_0'),
(@PROTECTOR,1, 0, 'Captain Muradin is waiting aboard The Skybreaker. We''ll secure the area until you are ready for take off.', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Protector - SAY_SECOND_SQUAD_RESCUED_ALLIANCE_1'),
(@PROTECTOR,2, 0, 'Skybreaker infantry, hold position!', 12, 0, 100, 0, 0, @SOUNDID, 'Skybreaker Protector - SAY_SECOND_SQUAD_RESCUED_ALLIANCE_2'),
(@PROTECTOR,3, 0, 'A screeching cry pierces the air above!',41, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_SUMMON_0'),
(@FROSTWYRM,0, 0, 'A Spire Frostwyrm lands just before Orgrim''s Hammer.', 16, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_LAND_H_1'),
(@FROSTWYRM,1, 0, 'A Spire Frostwyrm lands just before The Skybreaker. ', 16, 0, 100, 0, 0, @SOUNDID, 'Frostwyrm - SAY_FROSTWYRM_LAND_A_2');


UPDATE `creature_template` SET `ScriptName` = 'npc_korkron_defender' WHERE `entry` = 37032;
UPDATE `creature_template` SET `ScriptName` = 'npc_korkron_primalist' WHERE `entry` = 37030;
UPDATE `creature_template` SET `ScriptName` = 'npc_skybreaker_vindicator' WHERE `entry` = 37003;
UPDATE `creature_template` SET `ScriptName` = 'npc_skybreaker_protector' WHERE `entry` = 36998;
UPDATE `creature_template` SET `ScriptName` = 'npc_icc_spire_frostwyrm' WHERE `entry` = 37230;

-- Battle Standards Spells
UPDATE `creature_template` SET `unit_flags` = 33554564, `flags_extra` = 2 WHERE `entry` IN (37044, 37041);
UPDATE `creature_template` SET `faction_A` = 1801, `faction_H` = 1801 WHERE `entry` = 37044;
UPDATE `creature_template` SET `faction_A` = 1802, `faction_H` = 1802 WHERE `entry` = 37041;
DELETE FROM `creature_template_addon` WHERE `entry` IN (37044, 37041);
SET @KORKRON := 37044; -- Kor'kron Battle Standard
SET @SKYBREAKER := 37041; -- Skybreaker Battle Standard
SET @HSPELL := 69809;
SET @ASPELL := 69808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@KORKRON, @SKYBREAKER);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@KORKRON, @SKYBREAKER);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KORKRON ,0,0,0,54,0,100,1,0,0,0,0,11,@HSPELL,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Kor''kron Battle Standard - On spawn Cast spell 69809'),
(@SKYBREAKER,0,0,0,54,0,100,1,0,0,0,0,11,@ASPELL,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Skybreaker Battle Standard - On spawn Cast spell 69808');

-- Achievement GunShip
UPDATE `gameobject_template` SET `data4` = 1 WHERE `entry` IN (201814,201815,201816,201817);

-- Fix Rotting Frost Giant
UPDATE `creature` SET `spawntimesecs` =  '604800' WHERE `creature`.`id` =38494;
UPDATE `creature` SET `spawntimesecs` =  '604800' WHERE `creature`.`id` =38490;
UPDATE `creature_template` SET `rank` =  '1' WHERE `creature_template`.`entry` =38490;
UPDATE `creature_template` SET `rank` =  '1' WHERE `creature_template`.`entry` =38494;
UPDATE `gameobject_template` SET `IconName` = '',`castBarCaption` = '',`unk1` = '',`faction` = 0,`flags` = 50,`questItem1` = 0,`questItem2` = 0,`questItem3` = 0,`questItem4` = 0,`questItem5` = 0,`questItem6` = 0,`data2` = 0,`data3` = 1,`data4` = 0,`data5` = 0,`data6` = 0,`data7` = 0,`data8` = 0,`data9` = 0,`data10` = 0,`data11` = 1,`data12` = 0,`data13` = 1,`data14` = 0,`data15` = 1,`data16` = 0,`data17` = 0,`data18` = 0,`data19` = 0,`data20` = 0,`data21` = 0,`data22` = 0,`data23` = 0,`AIName` = '',`ScriptName` = '' WHERE `gameobject_template`.`entry` in (201872, 201874, 201873, 201875, 202177, 202180, 202178, 202179);
