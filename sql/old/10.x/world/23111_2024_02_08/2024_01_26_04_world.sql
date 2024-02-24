-- Fix Quest 24623 "Saving the Young"

-- Lost Bloodtalon Hatchling SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=39157;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (39157) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(39157,0,0,1,8,0,100,0,70874,0,80000,80000,0,33,39157,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Lost Bloodtalon Hatchling - On Spellhit - Give Killcredit'),
(39157,0,1,2,61,0,100,0,0,0,0,0,0,29,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Lost Bloodtalon Hatchling - On Spellhit - Follow Player'),
(39157,0,2,0,61,0,100,0,0,0,0,0,0,41,80000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Lost Bloodtalon Hatchling - On Spellhit - Force Despawn after 80s'),
(39157,0,3,0,8,0,30,0,70874,0,80000,80000,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Lost Bloodtalon Hatchling - On Spellhit - Say Text');

DELETE FROM `creature_text` WHERE `CreatureID`=39157;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39157, 0, 0, '%s yips in appreciation.', 16, 0, 100, 0, 0, 0, 37760, 0, 'Lost Bloodtalon Hatchling to Player'),
(39157, 0, 1, '%s bounces up and down.', 16, 0, 100, 0, 0, 0, 37761, 0, 'Lost Bloodtalon Hatchling to Player'),
(39157, 0, 2, '%s lets out a little screech.', 16, 0, 100, 0, 0, 0, 37762, 0, 'Lost Bloodtalon Hatchling to Player'),
(39157, 0, 3, '%s waves its horn at you.', 16, 0, 100, 0, 0, 0, 37763, 0, 'Lost Bloodtalon Hatchling to Player'),
(39157, 0, 4, '%s skips after you.', 16, 0, 100, 0, 0, 0, 37764, 0, 'Lost Bloodtalon Hatchling to Player'),
(39157, 0, 5, '%s almost falls on his face in excitement.', 16, 0, 100, 0, 0, 0, 37765, 0, 'Lost Bloodtalon Hatchling to Player'),
(39157, 0, 6, '%s taps his little claws on the ground as he runs to you.', 16, 0, 100, 0, 0, 0, 37766, 0, 'Lost Bloodtalon Hatchling to Player');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=70874 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 70874, 0, 0, 31, 0, 3, 39157, 0, 0, 0, 0, '', 'Spell Bloodtalon Whistle (effect 0) will hit the potential target of the spell if target is unit Lost Bloodtalon Hatchling.');
