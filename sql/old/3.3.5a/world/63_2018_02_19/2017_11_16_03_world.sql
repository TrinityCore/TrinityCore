-- 
UPDATE `smart_scripts` SET `event_param1`=2000, `event_param2`=2000, `event_param3`=2000,`event_param4`=2000 WHERE `entryorguid` IN (3021900,3021901,3021902) AND `source_type`=9 AND `id`=5;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=30222;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30222 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30222,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Infiltrator - On Just Summoned - Say Line 0"),
(30222,0,1,0,6,0,100,0,0,0,0,0,41,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Stormforged Infiltrator - On Just Died - Despawn Ethereal Frostwarg");

DELETE FROM `creature_text` WHERE `CreatureID`=30222;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(30222,0,0,"Found me, did ya? Now ya gotta die!",12,0,100,0,0,0,30916,0,"Stormforged Infiltrator"),
(30222,0,1,"Die, friend of the frost!",12,0,100,0,0,0,30917,0,"Stormforged Infiltrator"),
(30222,0,2,"You won't live to speak of this!",12,0,100,0,0,0,30918,0,"Stormforged Infiltrator");
