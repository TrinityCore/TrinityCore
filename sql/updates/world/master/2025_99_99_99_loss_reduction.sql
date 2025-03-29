-- https://www.wowhead.com/quest=25179/loss-reduction
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=39270 AND `spell_id`=73705;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES (39270, 73705, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=39270 AND `SourceEntry`=73705;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 39270, 73705, 0, 0, 8, 0, 25173, 0, 0, '', 0, 0, 0, '', NULL),
(18, 39270, 73705, 0, 0, 8, 0, 25176, 0, 0, '', 0, 0, 0, '', NULL),
(18, 39270, 73705, 0, 0, 8, 0, 25179, 0, 0, '', 1, 0, 0, '', NULL);

UPDATE `creature_template_addon` SET `StandState`=7, `auras`='76143 73713' WHERE `entry`=39270;

DELETE FROM `creature_text` WHERE `CreatureID` = 39270 AND `GroupID` IN (1, 2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39270, 1, 0, 'You\'ve saved my life, $c.  Protect me for a few more moments while I recover.', 12, 1, 100, 0, 0, 0, 39301, 0, 'Injured Razor Hill Grunt to Player'),
(39270, 1, 1, 'For the Warchief!  You lead, I will follow.', 12, 1, 100, 0, 0, 0, 39302, 0, 'Injured Razor Hill Grunt to Player'),
(39270, 1, 2, 'I was supposed to die in battle... ah well, another day.  I will follow you until I recover.', 12, 1, 100, 0, 0, 0, 39300, 0, 'Injured Razor Hill Grunt to Player'),
(39270, 2, 0, 'It was an honor to watch you fight, $n.', 12, 1, 100, 0, 0, 0, 39305, 0, 'Injured Razor Hill Grunt to Player'),
(39270, 2, 1, 'Thank you again.  I will return to Razor Hill now.', 12, 1, 100, 0, 0, 0, 39304, 0, 'Injured Razor Hill Grunt to Player'),
(39270, 1, 3, 'Thank you, $r... I was close to death.  May I stay by your side for a moment?', 12, 1, 100, 0, 0, 0, 39299, 0, 'Injured Razor Hill Grunt to Player'),
(39270, 2, 2, 'You fight well.  I will leave you now.  Lok\'tar ogar!', 12, 1, 100, 0, 0, 0, 39306, 0, 'Injured Razor Hill Grunt to Player'),
(39270, 2, 3, 'I feel much better now.  For the Horde!', 12, 1, 100, 0, 0, 0, 39303, 0, 'Injured Razor Hill Grunt to Player');

 -- Timed list 3927000 smart ai
SET @ENTRY := 3927000;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Look at storedTarget[0]', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 93, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to STATE_STUN_NOSHEATHE (93)', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set npc flags NONE', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 'After 1.2 seconds - Self: Talk 1 to storedTarget[0]', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Follow storedTarget[0] by distance 0, angle 0', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 40000, 40000, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 40 seconds - Self: Set emote state to STATE_READY1H (333)', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 2 to storedTarget[0]', ''),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Follow None by distance 0, angle 0', ''),
(@ENTRY, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Set event phase to phase 3', ''),
(@ENTRY, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.48353, 'After 0 seconds - Self: Set orientation to 1.48353', ''),
(@ENTRY, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 6000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 6 s', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 3927000 AND `SourceId` = 9;
 -- Injured Razor Hill Grunt smart ai
SET @ENTRY := 39270;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 1, 100, 0, 2000, 5000, 6000, 25000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 25 seconds (2 - 5s initially) (OOC) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 2, 63, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On just created - Set event phase to phase 1', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 136, 1, 5, 35, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Set movement MOVE_RUN speed to 5.35', ''),
(@ENTRY, 0, 3, 4, 73, 1, 100, 0, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Set event phase to phase 2', ''),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Self: storedTarget[0] = Clicker', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Self: Set stand state to STAND', ''),
(@ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 1, 1200, 1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Trigger timed event timedEvent[1] in 1200 - 1200 ms // -meta_wait', ''),
(@ENTRY, 0, 7, 8, 59, 0, 100, 0, 1, 0, 0, 0, 0, 7, 25179, 0, 1, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - storedTarget[0]: Offer quest Loss Reduction (25179)', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 80, 3927000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[1] triggered - Self: Start timed action list id #Injured Razor Hill Grunt #0 (3927000) (update out of combat)', ''),
(@ENTRY, 0, 9, 10, 73, 1, 100, 0, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Set event phase to phase 2', ''),
(@ENTRY, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Self: storedTarget[0] = Clicker', ''),
(@ENTRY, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Self: Set stand state to STAND', ''),
(@ENTRY, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 67, 2, 1200, 1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On spellclick - Trigger timed event timedEvent[2] in 1200 - 1200 ms // -meta_wait', ''),
(@ENTRY, 0, 13, 14, 59, 0, 100, 0, 2, 0, 0, 0, 0, 33, 39270, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[2] triggered - storedTarget[0]: Give kill credit Injured Razor Hill Grunt (39270)', ''),
(@ENTRY, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 80, 3927000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On timed event timedEvent[2] triggered - Self: Start timed action list id #Injured Razor Hill Grunt #0 (3927000) (update out of combat)', ''),
(@ENTRY, 0, 15, 0, 34, 4, 100, 0, 16, 1006, 0, 0, 0, 114, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 30, 0, 0, 'On movement of type EFFECT_MOTION_TYPE inform, point 1006 - Self: Move forward by 30, left by 0, up by 0 yards', ''),
(@ENTRY, 0, 16, 0, 34, 0, 100, 0, 8, 1, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Despawn instantly', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 39270 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 4, 39270, 0, 0, 47, 0, 25179, 1, 0, '', 0, 'Action invoker has Loss Reduction (25179) in state none'),
(22, 10, 39270, 0, 0, 47, 0, 25179, 10, 0, '', 0, 'Action invoker has Loss Reduction (25179) in state complete, incomplete');


UPDATE `spell_script_names` SET `ScriptName`='spell_gen_low_health' WHERE `spell_id`=76143;
-- otherwise the aura change is overriden when setting spawn health
UPDATE `creature` SET `curHealthPct` = 10 WHERE `id` IN (39270);
