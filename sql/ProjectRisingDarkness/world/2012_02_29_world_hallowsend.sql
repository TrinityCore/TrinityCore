-- Fix item Tricky Treat para Achievements http://www.wowhead.com/achievement=288
UPDATE `item_template` SET `ScriptName`='item_hallowsend_tricky_treat' WHERE `entry`='33226';
-- Fix Npc para quest http://www.wowhead.com/quest=8358#comments al usar el emote /train
UPDATE `creature_template` SET `ScriptName`='npc_kali_remik' WHERE `entry`='11814';

-- Fix ModelID de npcs
UPDATE `creature_template` SET `modelid1`='11686' WHERE `entry`='23686';-- Headless Horseman Flame Bunny
UPDATE `creature_template` SET `modelid1`='21342' WHERE `entry`='24034';-- Headless Horseman - Wisp Invis

-- Fix Cubetas con agua para quest. (Water Bucket)
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (42339,42132);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`)
VALUES 
('42339','42322','1','Bucket Lands'),
('42132','42971','1','Headless Horseman - Start Fire');

-- Añadido a Disables Give Water Bucket para creaturas y pets.
-- 2 Spell disabled for creatures + 4 Spell disabled for pets
DELETE FROM `disables` WHERE `entry` =42322;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`) 
VALUES ('0','42322','6');

-- CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET            = 13,
-- CONDITION_SPELL_SCRIPT_TARGET     = 18, 
-- Añadida correcta condicion para cubeta de agua :) (Bucket Lands)
-- DELETE FROM `conditions` WHERE `SourceEntry`=42339;
-- INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- (13, 0, 42339, 1, 18, 1, 0, 0, 0, "", "Bucket Lands"),
-- (13, 0, 42339, 0, 18, 1, 23537, 0, 0, "", "Bucket Lands");

-- ScriptName
UPDATE `creature_template` SET `ScriptName`='npc_headless_horseman_fire',`equipment_id`='0' WHERE `entry`='23537';
UPDATE `creature_template` SET `ScriptName`='npc_shade_of_the_horseman',`unit_flags`= `unit_flags` | 0x2000000 WHERE `entry`='23543';

-- 98686
-- Custom Trigger.
DELETE FROM `creature_template`WHERE `entry`=98686;
INSERT INTO `creature_template` (`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,`faction_A`,`faction_H`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`mindmg`,`maxdmg`,`dmgschool`,`attackpower`,`dmg_multiplier`,`baseattacktime`,`rangeattacktime`,`unit_class`,`unit_flags`,`dynamicflags`,`family`,`trainer_type`,`trainer_spell`,`trainer_class`,`trainer_race`,`minrangedmg`,`maxrangedmg`,`rangedattackpower`,`type`,`type_flags`,`lootid`,`pickpocketloot`,`skinloot`,`resistance1`,`resistance2`,`resistance3`,`resistance4`,`resistance5`,`resistance6`,`spell1`,`spell2`,`spell3`,`spell4`,`spell5`,`spell6`,`spell7`,`spell8`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,`InhabitType`,`Health_mod`,`Mana_mod`,`Armor_mod`,`RacialLeader`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`movementId`,`RegenHealth`,`equipment_id`,`mechanic_immune_mask`,`flags_extra`,`ScriptName`,`WDBVerified`) 
VALUES ('98686','0','0','0','0','0','4626','0','0','0','Custom Trigger Keeper','','','0','1','1','0','14','14','0','1','1.14286','1','0','1','2','0','0','1','2000','2000','1','33554432','0','0','0','0','0','0','1','2','0','10','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','0','0','0','0','0','0','0','0','1','0','0','0','npc_hallowend','1');

DELETE FROM `creature` WHERE `id` = 98686;
INSERT INTO `creature` (`guid`,`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`)
VALUES
(NULL, 98686, 530, 1, 1, 328, 0, '-4178.08', '-12499.8', '47.0984', '3.73379', 300, 0, 0, 42, 0, 0, 0, 0, 0),
(NULL, 98686, 1, 1, 1, 0, 0, '305.197', '-4728.36', '9.63175', '2.18494', 300, 0, 0, 42, 0, 0, 0, 0, 0),
(NULL, 98686, 0, 1, 1, 328, 0, '2261.87', '298.982', '34.1137', '1.26623', 300, 0, 0, 42, 0, 0, 0, 0, 0),
(NULL, 98686, 530, 1, 1, 328, 0, '9513.56', '-6810.1', '17.1184', '2.49493', 300, 0, 0, 42, 0, 0, 0, 0, 0),
(NULL, 98686, 0, 1, 1, 328, 0, '-9458.17', '56.5453', '56.0296', '1.39003', 300, 0, 0, 42, 0, 0, 0, 0, 0),
(NULL, 98686, 0, 1, 1, 0, 0, '-5589.21', -486, '397.038', '0.0537012', 300, 0, 0, 42, 0, 0, 0, 0, 0);
-- Linqueamos trigger solo al evento.
INSERT INTO `game_event_creature` VALUES
(12,(SELECT `guid` FROM `creature` WHERE `id` = 98686 limit 0,1));

-- Script go  http://www.wowhead.com/object=180574
DELETE FROM `gameobject_template` WHERE `entry` =180574;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`,`data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) values
('180574','2','6421','Wickerman Guardian Ember','','Using','','84','0','5','0','0','0','0','0','0','43','0','0','6535','0','0','19700','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','','1');
UPDATE `gameobject_template` SET `ScriptName` = 'go_wickerman_ember' WHERE `entry` =180574;


-- Wickerman Festival            
SET @GUID := 264000;
DELETE FROM `gameobject` WHERE `guid` IN (@GUID,@GUID+1,@GUID+2,@GUID+3,@GUID+4,@GUID+5,@GUID+6,@GUID+7,@GUID+8,@GUID+9,@GUID+10,@GUID+11);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GUID,180405,0,1,1,1746.02,516.679,38.9722,3,0,0,0.706252,0.707961,300,0,1),
(@GUID+1,180406,0,1,1,1719.52,523.045,36.8884,3.2,0,0,0.728141,0.685427,300,0,1),
(@GUID+2,180406,0,1,1,1727.75,474.81,63.6354,3.2,0,0,0.732164,0.681128,300,0,1),
(@GUID+3,180432,0,1,1,1750.14,507.759,38.9864,1.38773,0,0,0.639513,0.76878,300,0,1),
(@GUID+4,180432,0,1,1,1732.63,474.303,61.6563,1.64613,0,0,0.733233,0.679978,300,0,1),
(@GUID+5,180432,0,1,1,1712.21,508.029,37.924,1.32648,0,0,0.615674,0.788001,300,0,1),
(@GUID+6,180433,0,1,1,1731.39,509.227,41.2468,1.38772,0,0,0.639511,0.768782,300,0,1),
(@GUID+7,180434,0,1,1,1709.99,470.895,61.6553,1.51655,0,0,0.68767,0.726023,300,0,1),
(@GUID+8,180434,0,1,1,1705.36,520.442,35.0191,1.12151,0,0,0.531827,0.846853,300,0,1),
(@GUID+9,180434,0,1,1,1731.01,549.066,34.0198,4.63615,0,0,0.73354,-0.679646,300,0,1),
(@GUID+10,180434,0,1,1,1763.75,516.858,34.6317,5.72079,0,0,0.277505,-0.960724,300,0,1),
(@GUID+11,180434,0,1,1,1748.86,472.571,61.6563,4.67776,0,0,0.719244,-0.694758,300,0,1);
DELETE FROM `game_event_gameobject` WHERE `guid` IN (@GUID,@GUID+1,@GUID+2,@GUID+3,@GUID+4,@GUID+5,@GUID+6,@GUID+7,@GUID+8,@GUID+9,@GUID+10,@GUID+11);
INSERT INTO `game_event_gameobject` VALUES
(12,@GUID),
(12,@GUID+1),
(12,@GUID+2),
(12,@GUID+3),
(12,@GUID+4),
(12,@GUID+5),
(12,@GUID+6),
(12,@GUID+7),
(12,@GUID+8),
(12,@GUID+9),
(12,@GUID+10),
(12,@GUID+11);

SET @GUID := 10200000;
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1,@GUID+2,@GUID+3,@GUID+4);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID,15195,0,1,1,0,0,1722.9,550.575,34.8801,4.57359,300,0,0,45780,0,0,0,0,0),
(@GUID+1,15195,0,1,1,0,0,1714.36,512.773,37.0569,1.46233,300,0,0,45780,0,0,0,0,0),
(@GUID+2,15195,0,1,1,0,0,1753.36,510.961,37.3789,1.33431,300,0,0,45780,0,0,0,0,0),
(@GUID+3,15197,0,1,1,0,0,1733.16,521.039,36.2302,1.38301,300,0,0,15260,0,0,0,0,0),
(@GUID+4,15199,0,1,1,0,0,-821.925,-537.505,15.2772,3.56202,300,0,0,15260,0,0,0,0,0);
DELETE FROM `game_event_creature` WHERE `guid` IN (@GUID,@GUID+1,@GUID+2,@GUID+3,@GUID+4);
INSERT INTO `game_event_creature` VALUES
(12,@GUID),
(12,@GUID+1),
(12,@GUID+2),
(12,@GUID+3),
(12,@GUID+4);

DELETE FROM `areatrigger_involvedrelation` WHERE `id` =3991;
INSERT INTO `areatrigger_involvedrelation` (`id`, `quest`) 
VALUES (3991,1658);
DELETE FROM `event_scripts` WHERE `id` =9417;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) 
VALUES 
(9417,0,8,15415,0,0,0,0,0,0);
DELETE FROM `conditions` WHERE `SourceEntry` =24973;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) 
VALUES
(17,0,24973,0,30,180449,2,0,0,'',"Spell Clean Up Stink Bomb - Stink Bomb Cleaner");



UPDATE `creature_template` SET `ScriptName`='npc_wickerman_guardian' WHERE `entry`='15195';


-- Innkeeper Allison, Stormwind, update to cast on invoker
SET @INNKEEPER=6740;
UPDATE `smart_scripts` SET `target_type`=7 WHERE `entryorguid`=@INNKEEPER AND `id`=1;


-- Innkeeper Shaussly, Auberdine, Add menu option, Add SAI, Add condition
SET @GOSSIP=347;
SET @INNKEEPER=6737;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP, 2, 5, 'Make this inn your home.', 8, 65536, 0, 0, 0, 0, ''),
(@GOSSIP, 0, 0, 'Trick or Treat!', 1, 1, 0, 0, 0, 0, '');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@INNKEEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@INNKEEPER, 0, 0, 1, 62, 0, 100, 0, @GOSSIP, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Innkeeper Shaussly - On gossip option 0 select - Close gossip'),
(@INNKEEPER, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 24751, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Innkeeper Shaussly - On gossip option 0 select - Player cast Trick or Treat on self');
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, @GOSSIP, 0, 0, 12, 12, 0, 0, 0, '', NULL),
(15, @GOSSIP, 0, 0, 11, 24755, 0, 0, 0, '', NULL);


-- Caris Sunlance, Argent Tournament, Add menu option, Add SAI, Add condition
SET @GOSSIP=8903;
SET @INNKEEPER=33970;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP, 1, 5, 'Make this inn your home.', 8, 65536, 0, 0, 0, 0, ''),
(@GOSSIP, 0, 0, 'Trick or Treat!', 1, 1, 0, 0, 0, 0, '');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@INNKEEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@INNKEEPER, 0, 0, 1, 62, 0, 100, 0, @GOSSIP, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Caris Sunlance - On gossip option 0 select - Close gossip'),
(@INNKEEPER, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 24751, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Caris Sunlance - On gossip option 0 select - Player cast Trick or Treat on self');
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, @GOSSIP, 0, 0, 12, 12, 0, 0, 0, '', NULL),
(15, @GOSSIP, 0, 0, 11, 24755, 0, 0, 0, '', NULL);


-- Innkeeper Biribi, Allerian Stronghold, Add menu option, Add SAI, Add condition
SET @GOSSIP=7952;
SET @INNKEEPER=19296;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP, 1, 5, 'Make this inn your home.', 8, 65536, 0, 0, 0, 0, ''),
(@GOSSIP, 2, 1, 'I want to browse your goods', 3, 128, 0, 0, 0, 0, ''),
(@GOSSIP, 0, 0, 'Trick or Treat!', 1, 1, 0, 0, 0, 0, '');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@INNKEEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@INNKEEPER, 0, 0, 1, 62, 0, 100, 0, @GOSSIP, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Innkeeper Biribi - On gossip option 0 select - Close gossip'),
(@INNKEEPER, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 24751, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Innkeeper Biribi - On gossip option 0 select - Player cast Trick or Treat on self');
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, @GOSSIP, 0, 0, 12, 12, 0, 0, 0, '', 'Innkeeper Biribi - If Hallow\'s End show Gossip option 0'),
(15, @GOSSIP, 0, 0, 11, 24755, 0, 0, 0, '', NULL);


-- Initiate Brenners, Shadow Vault,Add menu option, Add SAI, Add condition
SET @GOSSIP=9895;
SET @INNKEEPER=30308;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP, 1, 5, 'Make this inn your home.', 8, 65536, 0, 0, 0, 0, ''),
(@GOSSIP, 0, 0, 'Trick or Treat!', 1, 1, 0, 0, 0, 0, '');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@INNKEEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@INNKEEPER, 0, 0, 1, 62, 0, 100, 0, @GOSSIP, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Initiate Brenners - On gossip option 0 select - Close gossip'),
(@INNKEEPER, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 24751, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Initiate Brenners - On gossip option 0 select - Player cast Trick or Treat on self');
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, @GOSSIP, 0, 0, 12, 12, 0, 0, 0, '', 'Initiate Brenners - If Hallow\'s End show Gossip option 0'),
(15, @GOSSIP, 0, 0, 11, 24755, 0, 0, 0, '', NULL);


-- Peon Gakra, Grom'arsh Crash-Sitee, Add menu option, Add SAI, Add condition
SET @GOSSIP=9944;
SET @INNKEEPER=29944;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP, 1, 5, 'Make this inn your home.', 8, 65536, 0, 0, 0, 0, ''),
(@GOSSIP, 2, 1, 'I want to browse your goods', 3, 128, 0, 0, 0, 0, ''),
(@GOSSIP, 0, 0, 'Trick or Treat!', 1, 1, 0, 0, 0, 0, '');
UPDATE `creature_template` SET `AIName`='SmartAI', `gossip_menu_id`=@GOSSIP WHERE `entry`=@INNKEEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@INNKEEPER, 0, 0, 1, 62, 0, 100, 0, @GOSSIP, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Peon Gakra - On gossip option 0 select - Close gossip'),
(@INNKEEPER, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 24751, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Peon Gakra - On gossip option 0 select - Player cast Trick or Treat on self');
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, @GOSSIP, 0, 0, 12, 12, 0, 0, 0, '', 'Peon Gakra - If Hallow\'s End show Gossip option 0'),
(15, @GOSSIP, 0, 0, 11, 24755, 0, 0, 0, '', NULL);
-- Jarin Dawnglow, Argent Tournament, Add SAI, shares gossip with Caris Sunlance
SET @INNKEEPER=33971;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@INNKEEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@INNKEEPER, 0, 0, 1, 62, 0, 100, 0, @GOSSIP, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Jarin Dawnglow - On gossip option 0 select - Close gossip'),
(@INNKEEPER, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 24751, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Jarin Dawnglow - On gossip option 0 select - Player cast Trick or Treat on self');


-- Flexing for Nougat (Alliance)
SET @INNKEEPER=6740;
SET @QUEST=8356;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@INNKEEPER, 0, 2, 0, 22, 0, 100, 0, 41, 0, 0, 0, 33, @INNKEEPER, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Innkeeper Allison - on /flex credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, @QUEST, 0, 12, 12, 0, 0, 0, '', NULL);


-- Chicken Clucking for a Mint (Alliance)
SET @INNKEEPER=5111;
SET @QUEST=8353;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@INNKEEPER, 0, 2, 0, 22, 0, 100, 0, 22, 0, 0, 0, 33, @INNKEEPER, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Innkeeper Firebrew - on /chicken credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, @QUEST, 0, 12, 12, 0, 0, 0, '', NULL);


-- Dancing for Marzipan (Alliance)
SET @INNKEEPER=6735;
SET @QUEST=8357;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@INNKEEPER, 0, 2, 0, 22, 0, 100, 0, 34, 0, 0, 0, 33, @INNKEEPER, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Innkeeper Saelienne - on /dance credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, @QUEST, 0, 12, 12, 0, 0, 0, '', NULL);


-- Incoming Gumdrop (Alliance)
SET @INNKEEPER=6826;
SET @QUEST=8355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@INNKEEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@INNKEEPER, 0, 0, 0, 22, 0, 100, 0, 264, 0, 0, 0, 33, @INNKEEPER, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Talvash del Kissel - on /train credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, @QUEST, 0, 12, 12, 0, 0, 0, '', NULL);


-- Flexing for Nougat (Horde)
SET @INNKEEPER=6929;
SET @QUEST=8359;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@INNKEEPER, 0, 2, 0, 22, 0, 100, 0, 41, 0, 0, 0, 33, @INNKEEPER, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Innkeeper Allison - on /flex credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, @QUEST, 0, 12, 12, 0, 0, 0, '', NULL);


-- Chicken Clucking for a Mint (Horde)
SET @INNKEEPER=6741;
SET @QUEST=8354;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@INNKEEPER, 0, 2, 0, 22, 0, 100, 0, 22, 0, 0, 0, 33, @INNKEEPER, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Innkeeper Firebrew - on /chicken credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, @QUEST, 0, 12, 12, 0, 0, 0, '', NULL);


-- Dancing for Marzipan (Horde)
SET @INNKEEPER=6746;
SET @QUEST=8360;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@INNKEEPER, 0, 2, 0, 22, 0, 100, 0, 34, 0, 0, 0, 33, @INNKEEPER, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Innkeeper Saelienne - on /dance credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, @QUEST, 0, 12, 12, 0, 0, 0, '', NULL);


-- Incoming Gumdrop (Horde)
SET @INNKEEPER=11814;
SET @QUEST=8358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@INNKEEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@INNKEEPER, 0, 0, 0, 22, 0, 100, 0, 264, 0, 0, 0, 33, @INNKEEPER, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Talvash del Kissel - on /train credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, @QUEST, 0, 12, 12, 0, 0, 0, '', NULL);

UPDATE `quest_template` SET `RewardSpellCast`=44242 WHERE `id` IN (12133,12155);


-- Fix Dungeon finder
UPDATE `instance_encounters` SET `creditType`=1,  `creditEntry`=59450  WHERE `entry` IN (692,693);


-- Tricks and Treats of Kalimdor (Visit the Candy Buckets in Kalimdor.)
DELETE FROM gameobject_questrelation WHERE quest IN (12345, 12377);
INSERT INTO gameobject_questrelation VALUES
(190035, 12345),
(190079, 12377);
DELETE FROM gameobject_involvedrelation WHERE quest IN (12345, 12377);
INSERT INTO gameobject_involvedrelation VALUES
(190035, 12345),
(190079, 12377);