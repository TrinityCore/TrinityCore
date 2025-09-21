--

-- The Exorcism Bubbling Slimer Bunny (DND) smart ai

SET @ENTRY := 22505;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 39300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Cast spell  Quest - The Exorcism Bubbling Slimer (39300) on Self'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 146, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Set uninteractable'),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Set react state to Passive'),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Set rooted'),
(@ENTRY, 0, 4, 0, 60, 0, 100, 0, 5000, 10000, 15000, 30000, 12, 22506, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 15 - 30 seconds (5 - 10s initially) - Self: Summon creature Foul Purge (22506) at Self\'s position, moved by offset (0, 0, 0, 0) as summon type manual despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 22505 AND `SourceId` = 0;

-- Correct condition set, because previously you could start the event again even though the quest was finished.
    
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 8539;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8539, 1, 0, 'I am ready, Anchorite.  Let us begin the exorcism.', 20396, 1, 3, 0, 0, 0, 0, NULL, 0, 0);
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (8539));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(15, 8539, 1, 0, 0, 9, 0, 10935, 2, 0, 0, 'Player for which gossip text is shown has quest The Exorcism of Colonel Jules (10935) active');

-- Sleeping is not necessary here because a spell takes care of that
    
UPDATE `creature_template_addon` SET `StandState` = 0 WHERE `entry` = 22432;

-- Delete non-working Linked spell entry
    
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 39371;

 -- Darkness Released smart ai
SET @ENTRY := 22507;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 89, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Move randomly in radius 15 yards'),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 39371, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Gebetsperlen (39371) hit - Self: Die');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 22507 AND `SourceId` = 0;

-- Spellscript Entry

DELETE FROM `spell_script_names` WHERE `spell_id` = 39371;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (39371, 'spell_39322_prayer_beads');
