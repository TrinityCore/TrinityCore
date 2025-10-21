-- Quest 26800 Recruitment
SET @Saltain := 1740;
SET @Darnell := 49337;
SET @Corpse  := 49340;

UPDATE `creature_template`
  SET `npcflag` = 0x01000000,
      `unit_flags` = 0x00000100 | 0x00000200,
      `unit_flags3` = 0x01000000 | 0x00002000 | 0x00000010
WHERE `entry` = @Corpse;

UPDATE `creature_template_addon`
  SET `auras` = '58951 92230'
WHERE `entry` = @Corpse;

INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`)
VALUES (@Corpse, 91942, 1, 0);

DELETE FROM `smart_scripts`
WHERE `source_type` = 0 AND `entryorguid` IN (@Saltain, @Corpse);

DELETE FROM `smart_scripts`
WHERE `source_type` = 9 AND `entryorguid` IN (@Saltain*100, @Saltain*100+1);

INSERT INTO `smart_scripts`
(`entryorguid`,`source_type`,`id`,`link`,`Difficulties`,
 `event_type`,`event_phase_mask`,`event_chance`,`event_flags`,
 `event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`event_param_string`,
 `action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`action_param7`,`action_param_string`,
 `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_param_string`,
 `target_x`,`target_y`,`target_z`,`target_o`,`comment`)
VALUES
(@Saltain, 0, 0, 1, '', 19, 0, 100, 0, 26800, 0, 0, 0, 0, '', 12, @Darnell, 8, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Saltain - On Quest Accepted - Summon ''Darnell'''),
(@Saltain, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, @Darnell*100+1, 2, 0, 0, 0, 0, 0, NULL, 19, @Darnell, 20, 0, 0, NULL, 0, 0, 0, 0, 'Saltain - Link - Run Timed ActionList ''Darnell'''),
(@Saltain, 0, 2, 0, '', 20, 0, 100, 0, 26800, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 0, NULL, 11, @Corpse, 20, 0, 0, NULL, 0, 0, 0, 0, 'Saltain - On Quest Rewarded - Despawn ''Scarlet Corpse'''),
(@Saltain, 0, 3, 0, '', 20, 0, 100, 0, 26800, 0, 0, 0, 0, '', 41, 2000, 0, 0, 0, 0, 0, 0, NULL, 19, @Darnell, 20, 0, 0, NULL, 0, 0, 0, 0, 'Saltain - On Quest Rewarded - Despawn ''Darnell'''),
(@Darnell*100+1, 9, 0, 0, '', 0, 0, 100, 0, 200, 200, 0, 0, 0, '', 29, 2, 315, 0, 0, 0, 0, 0, NULL, 21, 3, 0, 0, 0, NULL, 0, 0, 0, 0, 'Darnell - Timed ActionList - Follow Player'),
(@Darnell*100+1, 9, 1, 0, '', 0, 0, 100, 0, 800, 800, 0, 0, 0, '', 1, 4, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Darnell - Timed ActionList - Say Group 4'),
(@Darnell*100+1, 9, 2, 0, '', 0, 0, 100, 0, 5000, 5000, 0, 0, 0, '', 1, 5, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Darnell - Timed ActionList - Say Group 5'),
(@Corpse, 0, 0, 0, '', 42, 0, 100, 512, 46598, 0, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scarlet Corpse - On Aura Removed - Despawn Self'),
(@Corpse, 0, 1, 2, '', 8, 0, 100, 0, 91942, 0, 1000, 1000, 0, '', 11, 46598, 0, 0, 0, 20, 0, 0, NULL, 19, @Darnell, 25, 0, 0, NULL, 0, 0, 0, 0, 'Scarlet Corpse - On Spellhit - Cast ''Ride Vehicle Hardcoded'''),
(@Corpse, 0, 2, 3, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 33, @Corpse, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scarlet Corpse - Link - Quest Credit'),
(@Corpse, 0, 3, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 83, 16777216, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Scarlet Corpse - Link - Remove NPCFlags');

DELETE FROM `conditions` WHERE `SourceEntry` = @Darnell;

INSERT INTO `conditions`
(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
 `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
 `ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
(18, @Corpse, 91942, 0, 0, 47, 0, 26800, 1 | 2 | 64, 0, '', 1, 0, 0, '', 'Scarlet Corpse - On Quest State - Spell Click Event Unvailable');