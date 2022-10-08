DELETE FROM `smart_scripts` WHERE `entryorguid` = 50047 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(50047, '0', '0', '0', '25', '0', '100', '0', '0', '0', '0', '0', '99', '20', '50', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'On reset, set my hp between 20 and 50%'),
(50047, '0', '1', '0', '8', '0', '100', '0', '93097', '0', '0', '0', '80', '5004700', '0', '2', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Injured Stormwind Infantry - On Spellhit - Run Script'),
(50047, '0', '1', '2', '8', '0', '100', '0', '93097', '0', '200', '200', '33', '50047', '0', '0', '0', '0', '0', '21', '5', '0', '0', '0', '0', '0', '0', 'Give Quest Credit to player'),
(50047, '0', '2', '0', '61', '0', '100', '0', '0', '0', '0', '0', '80', '5004700', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'On Spellhit, Start timed event');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 50047;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(50047, '93072', '1', '0'),
(50047, '93097', '0', '0');

DELETE FROM `creature_text` WHERE `entry` = 50047;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(50047, '0', '0', 'Bless you, hero!', '12', '0', '100', '2', '0', '0', 'Injured Stormwind Infantry'),
(50047, '0', '1', 'I live to fight another day!', '12', '0', '100', '4', '0', '0', 'Injured Stormwind Infantry'),
(50047, '0', '2', 'I... I\'m ok! I\'m ok!', '12', '0', '100', '4', '0', '0', 'Injured Stormwind Infantry'),
(50047, '0', '3', 'I will fear no evil!', '12', '0', '100', '4', '0', '0', 'Injured Stormwind Infantry'),
(50047, '0', '4', 'Thank the Light!', '12', '0', '100', '4', '0', '0', 'Injured Stormwind Infantry');

DELETE FROM creature_template WHERE entry=50047;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Mana_mod_extra`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (50047, 0, 0, 0, 0, 0, 32729, 0, 0, 0, 'Injured Stormwind Infantry', '', 'SkinAlliance', 0, 2, 3, 0, 0, 12, 12, 16777218, 1, 1.14286, 1.14286, 1, 0, 0, 0, 0, 0, 1, 2000, 2000, 1, 49920, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'npc_injured_stormwind_infantry', 13623);

DELETE FROM waypoints WHERE entry=5004700;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (5004700, 1, -8911.5, -129.354, 80.9921, 'Injured Stormwind Infantry Path');
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (5004700, 2, -8911.48, -140.565, 82.2136, 'Injured Stormwind Infantry Path');
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES (5004700, 3, -8902.5, -159.346, 81.9404, 'Injured Stormwind Infantry Path');

DELETE FROM waypoints WHERE entry=95100;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 951 AND `source_type` = 0;
UPDATE `creature` SET `spawndist`='5', `currentwaypoint`='0', `MovementType`='1' WHERE (`guid`='168355');
UPDATE `creature_template` SET `MovementType`='1', `InhabitType`='1' WHERE (`entry`='951');
DELETE FROM  achievement_criteria_data WHERE criteria_id=6455;
DELETE FROM  achievement_criteria_data WHERE criteria_id=6180;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `ScriptName`) VALUES ('6180', '11', '1', 'achievement_chromatic_champion');
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `ScriptName`) VALUES ('6455', '11', '1', 'achievement_show_me_you_moves');

DELETE FROM creature_questrelation WHERE id=50047;
UPDATE `quest_template` SET `RequiredSpellCast1`='0' WHERE (`Id`='26391');

DELETE FROM `creature` WHERE id = 42940;
SET @GUID := NULL; 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 0, '42940', '0', '0', '0', '1', '1', '0', '0', '-9052.89', '-350.264', '76.0264', '1.85005', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 1, '42940', '0', '0', '0', '1', '1', '0', '0', '-9058.35', '-362.297', '73.5421', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 2, '42940', '0', '0', '0', '1', '1', '0', '0', '-9080.02', '-337.257', '73.5351', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 3, '42940', '0', '0', '0', '1', '1', '0', '0', '-9118.25', '-325.915', '75.7834', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 4, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9059.74', '-383.828', '73.8753', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 5, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9062.45', '-289.75', '73.5968', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 6, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9043.54', '-318.595', '75.0545', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 7, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9052.89', '-350.264', '76.0264', '1.85005', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 8, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9079.92', '-364.234', '73.5351', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 9, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9026.71', '-332.488', '73.7978', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 10, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9015.17', '-332.109', '74.9659', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 11, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9052.04', '-323.182', '73.5352', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 12, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9093.61', '-358.816', '73.5358', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 13, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9103.62', '-321.069', '73.3702', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 14, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9091.7', '-324.214', '73.5365', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 15, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9068.94', '-380.991', '73.5561', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 16, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9058.92', '-304.924', '73.5485', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 17, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9092.81', '-302.844', '73.6411', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 18, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9077.85', '-350.727', '73.5351', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 19, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9058.35', '-362.297', '73.5421', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 20, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9078.2', '-288.556', '73.6935', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 21, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9067.02', '-328.793', '73.5351', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 22, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9032.04', '-309.823', '74.1019', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 23, '42940', '0', '0', '0', '1', '1', '11686', '0', '-9118.25', '-325.915', '75.7834', '0', '90', '0', '0', '42', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 24, '42940', '0', '0', '0', '1', '1', '0', '0', '-9067.02', '-328.793', '73.5351', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 25, '42940', '0', '0', '0', '1', '1', '0', '0', '-9015.17', '-332.109', '74.9659', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 26, '42940', '0', '0', '0', '1', '1', '0', '0', '-9021.13', '-325.656', '74.319', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 27, '42940', '0', '0', '0', '1', '1', '0', '0', '-9034.44', '-322.993', '73.6084', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 28, '42940', '0', '0', '0', '1', '1', '0', '0', '-9080.94', '-314.651', '73.534', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 29, '42940', '0', '0', '0', '1', '1', '0', '0', '-9032.04', '-309.823', '74.1019', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 30, '42940', '0', '0', '0', '1', '1', '0', '0', '-9058.92', '-304.924', '73.5485', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (@GUID + 31, '42940', '0', '0', '0', '1', '1', '0', '0', '-9064.43', '-278.839', '75.1965', '0', '90', '0', '0', '1', '0', '0', '0', '0', '0');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 42940 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42940, '0', '0', '0', '25', '0', '100', '0', '0', '0', '0', '0', '11', '80175', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Northshire Vineyards Fire Trigger - Cast Vineyard Fire'),
(42940, '0', '1', '0', '8', '0', '100', '1', '80208', '0', '0', '0', '80', '4294000', '0', '2', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Northshire Vineyards Fire Trigger - Run Script');

DELETE FROM `creature_questrelation` WHERE (`id`='42940') AND (`quest`='26391');
UPDATE `creature_template` SET `ScriptName`='npc_injured_soldier' WHERE (`entry`='50378');
UPDATE `creature_template` SET `ScriptName`='npc_stormwind_infantry' WHERE (`entry`='49869');
