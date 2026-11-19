-- Source: Sniffs & https://www.youtube.com/watch?v=F-oYzmB7-84
UPDATE `creature_template` SET `ScriptName` = "" WHERE `entry` = 25862;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4894 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4894,2,0,1,46,0,100,0,4894,0,0,0,0,86,46231,0,19,25862,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Borean Tundra) - On Trigger - Cross Cast 'Mammoth Calf Escort Credit' (Khu'nok the Behemoth)"),
-- Will not work because is called instantly after spell cast with another emote
(4894,2,1,2,61,0,100,0,0,0,0,0,0,5,377,0,0,0,0,0,19,25862,0,0,0,0,0,0,0,"Areatrigger (Borean Tundra) - On Link - Play Emote 377 (Khu'nok the Behemoth)"),
(4894,2,2,0,61,0,100,0,0,0,0,0,0,4,9917,0,1,0,0,0,19,25862,0,0,0,0,0,0,0,"Areatrigger (Borean Tundra) - On Link - Play Sound 9917 (Khu'nok the Behemoth)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4894;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4894,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4894 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- We don't need to check if Calf is nearby https://www.wowhead.com/quest=11878/khunok-will-know#comments:id=1053786
(22,1,4894,2,0,9,0,11878,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player has taken quest 'Khu'nok Will Know'"),
(22,1,4894,2,0,28,0,11878,0,0,1,0,0,"","Group 0: Execute SAI (Action 0) if quest 'Khu'nok Will Know' is not completed");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 46237;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,46237,0,0,31,0,3,25861,0,0,0,0,"","Group 0: Spell 'Dismiss Orphaned Mammoth' targets creature 'Orphaned Mammoth Calf'"),
-- I don't know if it's needed
(13,1,46237,0,0,33,0,1,3,0,0,0,0,"","Group 0: Spell 'Dismiss Orphaned Mammoth' targets creature 'Orphaned Mammoth Calf' if owned by spell caster");

DELETE FROM `spell_scripts` WHERE `id` = 46237;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`Comment`) VALUES
(46237,0,0,18,3000,0,0,0,0,0,0,"Dismiss Orphaned Mammoth - On Effect Hit (Dummy) - Despawn (3000) (Orphaned Mammoth Calf)"),
-- Probably must be better syncronized by calling only when Calf despawns
(46237,0,3,14,46233,1,0,0,0,0,0,"Dismiss Orphaned Mammoth - On Effect Hit (Dummy) - Remove Aura 'Call Mammoth Orphan'");
