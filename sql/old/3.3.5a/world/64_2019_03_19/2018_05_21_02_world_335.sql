-- Tabetha
DELETE FROM `creature_text` WHERE `CreatureID`=6546 AND `GroupID` IN (1,2,3,4,5,6,7,8,9);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6546,1,0,"Ok, let's get this orb made...",12,0,100,0,0,0,2663,0,"Tabetha"),
(6546,2,0,"All right.  It's made!",12,0,100,1,0,0,2664,0,"Tabetha"),
(6546,3,0,"Stand back, and ... hold your breath.  I haven't done this in a while.",12,0,100,1,0,0,2708,0,"Tabetha"),
(6546,4,0,"It worked!  Amazing!  I guess I haven't lost my touch...",12,0,100,4,0,0,2709,0,"Tabetha"),
(6546,5,0,"Good luck out there, $n.",12,0,100,0,0,0,2624,0,"Tabetha"),
(6546,6,0,"I just have one thing to check...",12,0,100,0,0,0,2656,0,"Tabetha"),
(6546,7,0,"That's it!  It worked!",12,0,100,4,0,0,2657,0,"Tabetha"),
(6546,8,0,"Thanks for your patience, $n.",12,0,100,2,0,0,2658,0,"Tabetha"),
(6546,9,0,"I'll just keep this here until we need it...	",12,0,100,1,0,0,2659,0,"Tabetha");

DELETE FROM `smart_scripts` WHERE `entryorguid`=6546 AND `source_type`=0 AND `id` IN (1,2,6,7,8,9,10);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (654604,654605,654606) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6546,0,1,0,20,0,100,0,1957,0,0,0,41,0,600,0,0,0,0,14,28294,103680,0,0,0,0,0,"Tabetha - On Quest 'Mana Surges' Finished - Despawn Gameobject 'Mana Rift'"),
(6546,0,2,3,19,0,100,0,1957,0,0,0,70,600,0,0,0,0,0,14,28294,103680,0,0,0,0,0,"Tabetha - On Quest 'Mana Surges' Taken - Respawn Gameobject 'Mana Rift'"),
(6546,0,6,0,20,0,100,0,1957,0,0,0,80,654604,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Quest 'Mana Surges' Finished - Run Script"),
(6546,0,7,0,19,0,100,0,1952,0,0,0,80,654605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Quest 'Mage's Wand' Taken - Run Script"),
(6546,0,8,0,19,0,100,0,1957,0,0,0,11,9079,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Quest 'Mana Surges' Taken - Cast 'Create Rift'"),
(6546,0,9,0,19,0,100,0,1957,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Quest 'Mana Surges' Taken - Say Line 5"),
(6546,0,10,0,20,0,100,0,1947,0,0,0,80,654606,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Quest 'Journey to the Marsh' Finished - Run Script"),
(654604,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Remove Npc Flag Questgiver+Gossip"),
(654604,9,1,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 1"),
(654604,9,2,0,0,0,100,0,0,0,0,0,11,9156,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Cast 'Create Mage's Orb'"),
(654604,9,3,0,0,0,100,0,5500,5500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 2"),
(654604,9,4,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Add Npc Flag Questgiver+Gossip"),
(654605,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Remove Npc Flag Questgiver+Gossip"),
(654605,9,1,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 3"),
(654605,9,2,0,0,0,100,0,3000,3000,0,0,11,32990,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Cast 'Enchanting Cast Visual'"),
(654605,9,3,0,0,0,100,0,6000,6000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 4"),
(654605,9,4,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Add Npc Flag Questgiver+Gossip"),
(654606,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Remove Npc Flag Questgiver+Gossip"),
(654606,9,1,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 6"),
(654606,9,2,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.499598,"Tabetha - On Script - Set Orientation"),
(654606,9,3,0,0,0,100,0,1000,1000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Set Emote State 133"),
(654606,9,4,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Set Emote State 0"),
(654606,9,5,0,0,0,100,0,500,500,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 7"),
(654606,9,6,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.1293,"Tabetha - On Script - Set Orientation"),
(654606,9,7,0,0,0,100,0,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 8"),
(654606,9,9,0,0,0,100,0,5000,5000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 9"),
(654606,9,10,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tabetha - On Script - Add Npc Flag Questgiver+Gossip");

-- Mana Rift
UPDATE `gameobject` SET `spawntimesecs`=-600, `state`=1 WHERE `guid`=28294;

-- Mana Surge
DELETE FROM `smart_scripts` WHERE `entryorguid`=6550 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6550,0,3,0,54,0,100,0,0,0,0,0,11,9096,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mana Surge - On Just Summoned - Cast 'Rift SPawn Manifestation'");

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=6550 AND `ConditionTypeOrReference`=9;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,2,6550,0,0,9,0,1957,0,0,0,0,0,"","SAI triggers only if player has quest 'Mana Surges' taken");
