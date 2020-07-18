-- Quest "Samophlange (Part 2)"
-- Main Control Valve
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=4072;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4072 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4072,1,0,0,70,0,100,0,2,0,0,0,12,3285,1,180000,0,0,0,8,0,0,0,824.479,-2678.73,91.6667,6.04909,"Main Control Valve - On Gameobject State Changed - Summon Creature 'Venture Co. Peon'"),
(4072,1,1,0,70,0,100,0,2,0,0,0,12,3284,1,180000,0,0,0,8,0,0,0,826.776,-2674.53,91.6667,5.53466,"Main Control Valve - On Gameobject State Changed - Summon Creature 'Venture Co. Drudger'"),
(4072,1,2,0,70,0,100,0,2,0,0,0,1,0,0,0,0,0,0,19,3285,0,0,0,0,0,0,"Regulator Valve - On Gameobject State Changed - Say Line 0 (Venture Co. Peon)"),
(4072,1,3,0,70,0,100,0,2,0,0,0,1,0,0,0,0,0,0,19,3284,0,0,0,0,0,0,"Regulator Valve - On Gameobject State Changed - Say Line 0 (Venture Co. Drudger)");

-- Regulator Valve
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=61935;
DELETE FROM `smart_scripts` WHERE `entryorguid`=61935 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(61935,1,0,0,70,0,100,0,2,0,0,0,12,3285,1,180000,0,0,0,8,0,0,0,843.523,-2669.85,91.6668,4.39584,"Regulator Valve - On Gameobject State Changed - Summon Creature 'Venture Co. Peon'"),
(61935,1,1,0,70,0,100,0,2,0,0,0,1,0,0,0,0,0,0,19,3285,0,0,0,0,0,0,"Regulator Valve - On Gameobject State Changed - Say Line 0 (Venture Co. Peon)");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (3284,3285);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3284,0,0,"Get away from there!",12,0,100,0,0,0,4704,0,"Venture Co. Drudger"),
(3285,0,0,"Get away from there!",12,0,100,0,0,0,4704,0,"Venture Co. Peon");
