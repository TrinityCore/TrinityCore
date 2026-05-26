-- Column of Fire
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `unit_flags` = 33587200, `AIName` = 'SmartAI' WHERE `entry` = 24187;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24187 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24187,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Column of Fire - On AI Initialize - Set Reactstate Passive"),
(24187,0,1,0,11,0,100,0,0,0,0,0,0,11,43218,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Column of Fire - On Spawn - Cast 'Pillar of Fire'"),
(24187,0,2,0,11,0,100,0,0,0,0,0,0,11,40031,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Column of Fire - On Spawn - Cast 'Birth - No Visual (Instant Spawn)'");

-- Spirits
UPDATE `creature_template_addon` SET `auras` = '42466' WHERE `entry` IN (23877,23878,23879,23880);
UPDATE `creature_template` SET `ScriptName` = 'npc_zuljin_spirit' WHERE `entry` IN (23877,23878,23879,23880);

DELETE FROM `creature` WHERE `guid` IN (142227,142228,142229,142230) AND `id` IN (23877,23878,23879,23880);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(142227,23877,568,0,0,1,1,0,0,149.657440185546875,705.75,45.19477462768554687,3.106686115264892578,300,0,0,0,0,0,0,0,0,'',NULL,12340),
(142228,23878,568,0,0,1,1,0,0,134.599822998046875,724.3408203125,45.19470596313476562,4.066617012023925781,300,0,0,0,0,0,0,0,0,'',NULL,12340),
(142229,23879,568,0,0,1,1,0,0,91.13303375244140625,705.7529296875,45.19470977783203125,0.01745329238474369,300,0,0,0,0,0,0,0,0,'',NULL,12340),
(142230,23880,568,0,0,1,1,0,0,105.5264663696289062,724.92620849609375,45.19470596313476562,5.358160972595214843,300,0,0,0,0,0,0,0,0,'',NULL,12340);

DELETE FROM `creature_text` WHERE `CreatureID` = 23863 AND `GroupID` > 9;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23863,10,0,"%s absorbs the essence of the bear spirit!",16,0,100,0,0,0,22410,0,"Zul'jin EMOTE_BEAR_SPIRIT"),
(23863,11,0,"%s absorbs the essence of the eagle spirit!",16,0,100,0,0,0,22432,0,"Zul'jin EMOTE_EAGLE_SPIRIT"),
(23863,12,0,"%s absorbs the essence of the lynx spirit!",16,0,100,0,0,0,22433,0,"Zul'jin EMOTE_LYNX_SPIRIT"),
(23863,13,0,"%s absorbs the essence of the dragonhawk spirit!",16,0,100,0,0,0,22435,0,"Zul'jin EMOTE_DRAGONHAWK_SPIRIT");

DELETE FROM `creature_text` WHERE `CreatureID` IN (23877,23878,23879,23880);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23877,0,0,"%s shimmers and begins to fade away...",16,0,100,0,0,0,23604,0,"Amani Lynx Spirit"),
(23878,0,0,"%s shimmers and begins to fade away...",16,0,100,0,0,0,23604,0,"Amani Bear Spirit"),
(23879,0,0,"%s shimmers and begins to fade away...",16,0,100,0,0,0,23604,0,"Amani Dragonhawk Spirit"),
(23880,0,0,"%s shimmers and begins to fade away...",16,0,100,0,0,0,23604,0,"Amani Eagle Spirit");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (42542,42567);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,42542,0,0,31,0,3,23863,0,0,0,0,"","Group 0: Spell 'Cosmetic - Zul'Aman Spirit Drain' (Effect 0) targets creature 'Zul'jin'"),
(13,1,42567,0,0,31,0,3,23877,0,0,0,0,"","Group 0: Spell 'Cosmetic - Incinerate Blue' (Effect 0) targets creature 'Amani Lynx Spirit'"),
(13,1,42567,0,1,31,0,3,23878,0,0,0,0,"","Group 1: Spell 'Cosmetic - Incinerate Blue' (Effect 0) targets creature 'Amani Bear Spirit'"),
(13,1,42567,0,2,31,0,3,23879,0,0,0,0,"","Group 2: Spell 'Cosmetic - Incinerate Blue' (Effect 0) targets creature 'Amani Dragonhawk Spirit'"),
(13,1,42567,0,3,31,0,3,23880,0,0,0,0,"","Group 3: Spell 'Cosmetic - Incinerate Blue' (Effect 0) targets creature 'Amani Eagle Spirit'");

DELETE FROM `spell_script_names` WHERE `spell_id` = 42520 AND `ScriptName` = 'spell_gen_feign_death_all_flags';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42520, 'spell_gen_feign_death_all_flags');

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_zuljin_zap',
'spell_zuljin_claw_rage',
'spell_zuljin_claw_rage_periodic',
'spell_zuljin_lynx_rush');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42577, 'spell_zuljin_zap'),
(42583, 'spell_zuljin_claw_rage'),
(43149, 'spell_zuljin_claw_rage_periodic'),
(43152, 'spell_zuljin_lynx_rush');
