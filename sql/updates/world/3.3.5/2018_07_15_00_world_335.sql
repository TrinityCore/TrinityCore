-- Quest "Resupplying the Excavation"
-- Areatrigger
DELETE FROM `areatrigger_involvedrelation` WHERE `id`=171;

DELETE FROM `areatrigger_scripts` WHERE `entry`=171;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(171,"SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryorguid`=171 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(171,2,0,0,46,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,8279,2057,0,0,0,0,0,"Areatrigger - On Trigger - Set Data to Huldar");

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=171;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,171,2,0,9,0,273,0,0,0,0,0,"","SAI triggers only if quest 'Resupplying the Excavation' is taken");

-- Huldar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2057;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2057 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (205700,205701) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2057,0,0,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huldar - On Respawn - Set Event Phase 1"),
(2057,0,1,0,38,1,100,0,1,1,0,0,0,80,205700,2,0,0,0,0,1,0,0,0,0,0,0,0,"Huldar - On Data Set - Run Script (Phase 1)"),
(2057,0,2,0,38,0,100,0,2,2,0,0,0,80,205701,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huldar - On Data Set - Run Script"),
(205700,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huldar - On Script - Set Event Phase 0"),
(205700,9,1,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huldar - On Script - Remove Npc Flag Questgiver+Gossip"),
(205700,9,2,0,0,0,100,0,0,0,0,0,0,12,1380,6,10000,0,0,0,8,0,0,0,-5762.05,-3437.35,305.971,2.01641,"Huldar - On Script - Summon Creature 'Saean'"),
(205701,9,0,0,0,0,100,0,1000,1000,0,0,0,15,273,0,0,0,0,0,18,50,0,0,0,0,0,0,"Huldar - On Script - Complete Quest 'Resupplying the Excavation'"),
(205701,9,1,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huldar - On Script - Add Npc Flag Questgiver+Gossip"),
(205701,9,2,0,0,0,100,0,30000,30000,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huldar - On Script - Set Event Phase 1");

-- Saean
UPDATE `creature_template` SET `faction`=35, `AIName`="SmartAI" WHERE `entry`=1380;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1380 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=138000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1380,0,0,0,54,0,100,0,0,0,0,0,0,80,138000,2,0,0,0,0,1,0,0,0,0,0,0,0,"Saean - Just Summoned - Run Script"),
(1380,0,1,0,6,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,19,2057,0,0,0,0,0,0,"Saean - On Just Died - Set Data to Huldar"),
(138000,9,0,0,0,0,100,0,4000,4000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saean - On Script - Say Line 0"),
(138000,9,1,0,0,0,100,0,2000,2000,0,0,0,2,54,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saean - On Script - Set Faction 54"),
(138000,9,2,0,0,0,100,0,0,0,0,0,0,12,1981,6,10000,0,0,0,8,0,0,0,-5759.24,-3442.57,305.453,2.00286,"Saean - On Script - Summon Creature 'Dark Iron Ambusher'"),
(138000,9,3,0,0,0,100,0,0,0,0,0,0,12,1981,6,10000,0,0,0,8,0,0,0,-5771.42,-3437.31,306.013,0.518455,"Saean - On Script - Summon Creature 'Dark Iron Ambusher'"),
(138000,9,4,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,2057,0,0,0,0,0,0,"Saean - On Script - Start Attacking"),
(138000,9,5,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,19,1379,0,0,0,0,0,0,"Saean - On Script - Say Line 0 (Miran)");

DELETE FROM `creature_text` WHERE `CreatureID` IN (1380,1379) AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1380,0,0,"Sorry, Huldar... But it seems I've misled you.",12,7,100,0,0,0,192,0,"Saean"),
(1379,0,0,"No two-bit traitor will stop the powder from getting to Ironband!",12,7,100,0,0,0,540,0,"Miran");

-- Dark Iron Ambusher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1981;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1981 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1981,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,25,20,0,0,0,0,0,0,"Dark Iron Ambusher - Just Summoned - Start Attacking");
