UPDATE `creature_template` SET `ScriptName`= '', `unit_flags`= 0x40 | 0x8000 | 0x2000000, `flags_extra`= 128 WHERE `entry`= 40790;
UPDATE `creature` SET `ScriptName`= 'npc_hoo_aggro_stalker_1' WHERE `guid`= 307307;
UPDATE `creature` SET `ScriptName`= 'npc_hoo_aggro_stalker_2' WHERE `guid`= 307365;
UPDATE `creature` SET `ScriptName`= 'npc_hoo_aggro_stalker_3' WHERE `guid`= 308039;

UPDATE `creature_template` SET `unit_flags`= 0x40 WHERE `entry` IN (39440, 49286, 40310, 49294, 40787, 49301, 42556, 49306);
DELETE FROM `creature_template_addon` WHERE `entry` IN (39440, 49286, 40310, 49294, 40787, 49301, 42556, 49306);

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 40790;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(40790, 0, 0, 1, 1);

DELETE FROM `creature` WHERE `guid` IN (307310, 307308, 307320, 307360, 307333, 307453, 307418, 307452, 307454, 307680, 307678, 307679);
DELETE FROM `creature_addon` WHERE `guid` IN (307310, 307308, 307320, 307360, 307333, 307453, 307418, 307452, 307454, 307680, 307678, 307679);
DELETE FROM `creature_formations` WHERE `LeaderGUID` IN (307307, 307365, 308039);

DELETE FROM `creature_summon_groups` WHERE `summonerId`= 40790 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`,`summonTime`) VALUES
-- 0
(40790, 0, 0, 42556, -496.333, 97.9983, 83.1642, 3.80482, 6, 60000),
(40790, 0, 0, 42556, -492.167, 80.0035, 82.4928, 2.11185, 6, 60000),
(40790, 0, 0, 39440, -519.724, 77.1198, 83.2052, 0.628318, 6, 60000),
-- 1
(40790, 0, 1, 42556, -514.592, 26.8125, 82.3194, 1.25664, 6, 60000),
(40790, 0, 1, 42556, -514.471, 47.0625, 83.2324, 4.92183, 6, 60000),
(40790, 0, 1, 42556, -489.51,  48.5156, 86.2949, 3.56047, 6, 60000),
(40790, 0, 1, 40787, -520.404, 35.3941, 84.3484, 1.25664, 6, 60000),
(40790, 0, 1, 40310, -492.373, 38.559,  83.9584, 1.95477, 6, 60000),
-- 2
(40790, 0, 2, 42556, -496.715, -12.2135, 83.0425, 2.23402, 6, 60000),
(40790, 0, 2, 42556, -522.835, -8.40451, 83.8212, 6.16101, 6, 60000),
(40790, 0, 2, 40311, -490.234, -18.5382, 83.1895, 1.8326, 6, 60000),
(40790, 0, 2, 39440, -524.488, -17.651, 83.6682, 0, 6, 60000);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hoo_submerge';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76084, 'spell_hoo_submerge');

-- Creature Venomous Skitterer 39440 SAI
SET @ENTRY := 39440;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 2400, 2400, 15000, 16000, 11, 75158, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 2400 min and 2400 max ms (repeat 15000 min 16000 max ms) - Self: Cast spell Surge (75158) on Random hostile // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 4000, 5000, 17000, 19000, 11, 74121, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 4000 min and 5000 max ms (repeat 17000 min 19000 max ms) - Self: Cast spell Debilitating Venom (74121) on Victim // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 9000, 10000, 30000, 31000, 11, 73963, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 9000 min and 10000 max ms (repeat 30000 min 31000 max ms) - Self: Cast spell Blinding Toxin (73963) on Victim // ");

-- Creature Jeweled Scarab 42556 SAI
SET @ENTRY := 42556;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 2400, 2400, 13000, 16000, 11, 83233, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 2400 min and 2400 max ms (repeat 13000 min 16000 max ms) - Self: Cast spell Surge (83233) on Random hostile // ");

-- Creature Blistering Scarab 40310 SAI
SET @ENTRY := 40310;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 3500, 4000, 11, 74122, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 4000 min and 4000 max ms (repeat 3500 min 4000 max ms) - Self: Cast spell Corrosive Spray (74122) on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7000, 8000, 10000, 11000, 11, 74542, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 7000 min and 8000 max ms (repeat 10000 min 11000 max ms) - Self: Cast spell Serrated Slash (74542) on Victim // ");

-- Creature Dustbone Horror 40787 SAI
SET @ENTRY := 40787;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 10000, 12000, 10000, 14000, 11, 75453, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 10000 min and 12000 max ms (repeat 10000 min 14000 max ms) - Self: Cast spell Smash (75453) on Victim // ");

-- Creature Dustbone Tormentor 40311 SAI
SET @ENTRY := 40311;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 43000, 45000, 11, 77357, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 6000 min and 6000 max ms (repeat 43000 min 45000 max ms) - Self: Cast spell Curse of Exhaustion (77357) on Random hostile // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7000, 7000, 2400, 2400, 11, 77570, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 7000 min and 7000 max ms (repeat 2400 min 2400 max ms) - Self: Cast spell Shadow Bolt (77570) on Victim // ");

-- Creature Dustbone Horror 40808 SAI
SET @ENTRY := 40808;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Set Invulnerability Health level // "),
(@ENTRY, 0, 1, 2, 2, 0, 100, 0, 0, 20, 60000, 60000, 46, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 20% (check every 60000 - 60000 ms) - Stop Attacking // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 76084, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Submerge (76084) on Self // "),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // "),
(@ENTRY, 0, 5, 0, 8, 0, 100, 0, 76084, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Submerge (76084) hit  - Self: Despawn in 3000 ms // "),
(@ENTRY, 0, 6, 0, 0, 0, 100, 0, 4000, 5000, 9000, 11000, 11, 75453, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 4000 min and 5000 max ms (repeat 9000 min 11000 max ms) - Self: Cast spell Smash (75453) on Victim // ");

DELETE FROM `creature_text` WHERE `CreatureID`= 40808;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(40808, 0, 0, '%s buries itself in the sand!', 16, 0, 100, 0, 0, 0, 42474, '');

UPDATE `creature_template` SET `mechanic_immune_mask`= `mechanic_immune_mask` | 0x800 WHERE `entry` IN (40808, 49302);
