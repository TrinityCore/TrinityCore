-- Birgitte Cranston
SET @NPC=5957;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @NPC;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = @NPC);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC,0,0,0,22,0,100,0,41,5000,5000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Birgitte Cranston - On Received Emote 'Flex' - Say Line 0"),
(@NPC,0,1,0,22,0,100,0,77,5000,5000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Birgitte Cranston - On Received Emote 'Rude' - Say Line 1"),
(@NPC,0,2,0,22,0,100,0,17,5000,5000,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Birgitte Cranston - On Received Emote 'Bow' - Play Emote 2"),
(@NPC,0,3,0,22,0,100,0,78,5000,5000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Birgitte Cranston - On Received Emote 'Salute' - Play Emote 66"),
(@NPC,0,4,0,22,0,100,0,101,5000,5000,0,0,5,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Birgitte Cranston - On Received Emote 'Wave' - Play Emote 3");

DELETE FROM `creature_text` WHERE `CreatureID`=@NPC;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC,0,0,"%s is not impressed.",16,0,100,11,0,0,1401,0,"Birgitte Cranston"),
(@NPC,1,0,"You're pushing it, $n.",12,0,100,0,0,0,1402,0,"Birgitte Cranston"),
(@NPC,1,1,"Don't make me go medieval on you.",12,0,100,0,0,0,1403,0,"Birgitte Cranston"),
(@NPC,1,2,"Keep it up, $n, and I'll beat some manners into you.",12,0,100,0,0,0,1404,0,"Birgitte Cranston");
