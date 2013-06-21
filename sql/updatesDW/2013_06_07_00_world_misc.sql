DELETE FROM `gameobject` WHERE `id` IN (196463,195365);

DELETE FROM `creature` WHERE `id` = 36365;

DELETE FROM `gameobject` WHERE `guid` IN (100165,100166,100167,100168,100169,100170,100171);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(100165, 196463, 1, 1, 1, 4937.43, -6471.59, 160.897, -1.22221, 0, 0, 0, 1, 180, 100, 1),
(100166, 195365, 1, 1, 1, 4853.46, -6509.91, 25.5878, -1.18682, 0, 0, 0, 1, 180, 100, 1),
(100167, 195365, 1, 1, 1, 4838.46, -6446.8, 19.1497, -1.53589, 0, 0, 0, 1, 180, 100, 1),
(100168, 195365, 1, 1, 1, 4993.52, -6433.77, 83.0947, 2.18166, 0, 0, 0, 1, 180, 100, 1),
(100169, 195365, 1, 1, 1, 4884.25, -6476.94, 108.023, -1.27409, 0, 0, 0, 1, 180, 100, 1),
(100170, 195365, 1, 1, 1, 4951.17, -6547.52, 37.4788, 0.383971, 0, 0, 0, 1, 180, 100, 1),
(100171, 195365, 1, 1, 1, 4974.07, -6470.35, 133.652, 1.36136, 0, 0, 0, 1, 180, 100, 1);

DELETE FROM `creature` WHERE `guid` = 300705;
INSERT INTO `creature` (`guid`, `id`, `map`, `zone`, `area`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(300705, 36365, 1, 0, 0, 1, 1, 0, 0, 4937.1, -6449.67, 160.629, 4.67583, 300, 0, 0, 285, 0, 0, 0, 0, 0);

DELETE FROM `creature_template` WHERE `entry` = 15351;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Mana_mod_extra`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(15351, 0, 0, 0, 0, 0, 27154, 0, 0, 0, 'Alliance Brigadier General', NULL, NULL, 6597, 80, 80, 2, 0, 1618, 1618, 131, 1, 1.14286, 1, 1, 422, 586, 0, 642, 4.6, 2000, 2000, 1, 2, 2048, 8, 0, 0, 0, 0, 0, 345, 509, 103, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 10, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, '', 12340);

UPDATE `creature_template` SET `faction_A` = '7', `faction_H` = '7', `mechanic_immune_mask` = '32' WHERE `entry` =44703;

DELETE FROM creature WHERE guid=45494;

DELETE FROM creature WHERE guid=31479;

UPDATE quest_template SET nextQuestId=24969 WHERE id=3095;

UPDATE quest_template SET MinLevel=5 WHERE id=24972;

DELETE FROM creature WHERE guid=63975;

DELETE FROM creature WHERE guid=63973;

DELETE FROM creature WHERE guid=31494;

DELETE FROM creature WHERE guid=64051;

DELETE FROM creature WHERE guid=64050;

DELETE FROM creature WHERE guid=31522;

UPDATE quest_template SET nextQuestId=24964 WHERE id=24962;

UPDATE quest_template SET nextQuestId=24967 WHERE id=3096;

UPDATE quest_template SET RequiredNpcOrGo1=44794 WHERE id=24965;

UPDATE quest_template SET RequiredNpcOrGo1=44794 WHERE id=24967;

UPDATE quest_template SET RequiredNpcOrGo1=44794 WHERE id=24968;
