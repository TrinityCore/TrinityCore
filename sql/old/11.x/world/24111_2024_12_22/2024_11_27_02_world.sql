-- Gossips
UPDATE `gossip_menu` SET `VerifiedBuild`=57388 WHERE (`MenuID`=14988 AND `TextID`=21186) OR (`MenuID`=4342 AND `TextID`=5516);

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=14988 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(14988, 41023, 0, 0, 'I''m ready to go, General.', 67518, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57388);

UPDATE `gossip_menu_option` SET `VerifiedBuild`=57388 WHERE (`MenuID`=4342 AND `OptionID`=0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=14988 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,14988,0,0,0,47,0,29690,8,0,'',0,0,0,'','Show gossip option if quest 29690 is taken');

-- Quests
UPDATE `quest_poi` SET `VerifiedBuild`=57388 WHERE (`QuestID`=29690 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29690 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=57388 WHERE (`QuestID`=29690 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29690 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=57388 WHERE `ID`=29690;

DELETE FROM `quest_request_items` WHERE `ID`=29690;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29690, 0, 0, 0, 0, '', 57388); -- Into the Mists

UPDATE `creature_queststarter` SET `VerifiedBuild`=57388 WHERE (`id`=55054 AND `quest`=29690);

UPDATE `creature_questender` SET `VerifiedBuild`=57388 WHERE (`id`=55135 AND `quest`=29690) OR (`id`=55054 AND `quest`=31853);

-- Spells
DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID`=102930);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(102930, 0, 870, 3138.8701171875, -721.25, 325, 57388); -- Spell: 102930 (Teleport Player to Crash Site) Effect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `PositionX`=1445.2099609375, `PositionY`=-4499.56005859375, `PositionZ`=18.30999946594238281, `VerifiedBuild`=57388 WHERE (`ID`=123073 AND `EffectIndex`=0); -- Spell: 123073 (Portal: Orgrimmar) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_teleport_prep', 'spell_teleport_timer', 'spell_into_the_mists_scene_jf', 'spell_cancel_blackout', 'spell_into_the_mists_scene_end');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(130810, 'spell_teleport_prep'),
(132034, 'spell_teleport_timer'),
(121545, 'spell_into_the_mists_scene_jf'),
(130812, 'spell_cancel_blackout'),
(130723, 'spell_into_the_mists_scene_end');

-- Smart scripts
DELETE FROM `scene_template` WHERE `SceneId`=87;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`, `ScriptName`) VALUES
(87, 11, 228, 0, 'SmartScene');

DELETE FROM `areatrigger_scripts` WHERE `entry`=8045;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(8045, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=55054 AND `source_type`=0 AND `id` IN (3, 4);
DELETE FROM `smart_scripts` WHERE `entryorguid`=8045 AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=87 AND `source_type`=10;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(55054,0,3,4,'',62,0,100,0,14988,0,0,0,0,'',134,130810,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'General Nazgrim - On gossip option 0 selected - Invoker casts ''Teleport Prep'''),
(55054,0,4,0,'',61,0,100,0,0,0,0,0,0,'',72,0,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'General Nazgrim - Event linked - Close gossip'),

(8045,2,0,0,'',46,0,100,0,0,0,0,0,0,'',134,121545,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Areatrigger 8045 - On trigger - Invoker casts ''Into the Mists Scene - JF'''),

(87,10,0,0,'',81,0,100,0,0,0,0,0,0,'',134,130723,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Scene 87 - On scene complete - Invoker casts ''Into the Mists Scene End'''),
(87,10,1,0,'',80,0,100,0,0,0,0,0,0,'',134,130723,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Scene 87 - On scene cancel - Invoker casts ''Into the Mists Scene End''');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=30 AND `SourceEntry`=8045;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(30,0,8045,0,0,47,0,29690,8,0,'',0,0,0,'','Areatrigger 8045 triggers if quest 29690 is taken');
