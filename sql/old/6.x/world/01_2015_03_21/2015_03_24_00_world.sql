-- Blood Theory
-- Rejuvenated Thunder Lizard SAI
SET @ENTRY := 35412;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,12000,14000,11,15611,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rejuvenated Thunder Lizard - In Combat - Cast 'Lizard Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,24000,27000,11,77601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rejuvenated Thunder Lizard - In Combat - Cast 'Lightning Nova'"),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,11,68292,2,0,0,0,0,1,0,0,0,0,0,0,0,"Rejuvenated Thunder Lizard - On Just Died - Cast 'Summon Blood-filled Leech'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=35412;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 3, 35412, 0, 0, 1, 1, 68290, 0, 0, 0, 0, 0, '', 'SAI triggers only if Creature has Aura "Leech Infestation"');

-- Blood-filled Leech SAI
SET @ENTRY := 36059;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood-filled Leech - On Just Summoned - Start Random Movement"),
(@ENTRY,0,1,0,8,0,100,0,68293,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood-filled Leech - On Spellhit 'Bloody Leech Cover' - Despawn Instant");
UPDATE `creature_template` SET `npcflag`=16777216 WHERE  `entry`=36059;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=36059;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(36059, 68291, 3, 0),
(36059, 68293, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=36059 AND `SourceEntry` IN (68291, 68293);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 36059, 68291, 0, 0, 8, 0, 14304, 0, 0, 1, 0, 0, '', 'Forbidden rewarded quest for spellclick'),
(18, 36059, 68291, 0, 0, 9, 0, 14304, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
(18, 36059, 68293, 0, 0, 8, 0, 14304, 0, 0, 1, 0, 0, '', 'Forbidden rewarded quest for spellclick'),
(18, 36059, 68293, 0, 0, 9, 0, 14304, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick');
