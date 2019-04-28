-- Condition for source Gossip menu option condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11451 AND `SourceEntry` IN (0, 1, 2, 3) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11451, 0, 0, 0, 8, 0, 25578, 0, 0, 0, 0, 0, '', 'Show gossip menu 11451 option id 0 if quest Return to Nordrassil has been rewarded.'),
(15, 11451, 1, 0, 0, 8, 0, 25578, 0, 0, 0, 0, 0, '', 'Show gossip menu 11451 option id 1 if quest Return to Nordrassil has been rewarded.'),
(15, 11451, 2, 0, 0, 8, 0, 25578, 0, 0, 0, 0, 0, '', 'Show gossip menu 11451 option id 2 if quest Return to Nordrassil has been rewarded.'),
(15, 11451, 3, 0, 0, 8, 0, 25578, 0, 0, 0, 0, 0, '', 'Show gossip menu 11451 option id 3 if quest Return to Nordrassil has been rewarded.');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (38917, 40178);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`) VALUES
(38917, 0, 0, 1),
(40178, 0, 0, 1);

DELETE FROM `spell_area` WHERE `spell`= 101311;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(101311,5625,25430,25324,0,0,2,1,74,11);

UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=40139;

DELETE FROM `spell_area` WHERE `spell`= 75243;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(75243,5032,25325,25578,0,0,2,1,74,1);

UPDATE `creature_template` SET `exp`= 3,`faction`= 35,`unit_class`= 2,`unit_flags`= 72 WHERE `entry`= 40180;

-- Captain Saynna Stormrunner SAI
SET @ENTRY := 39446;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25325,0,0,0,11,74895,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captain Saynna Stormrunner - Quest accepted - Cast 'Forcecast Summon Fandral'");

-- Creature Galrond of the Claw 40148 SAI
SET @ENTRY := 40148;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 42, 0, 100, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Set invible at 0 health or 100 percent health  // "),
(@ENTRY, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, 384466, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Attack Creature Baron Geddon 40147 (384466) // "),
(@ENTRY, 0, 2, 3, 8, 0, 100, 0, 75072, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Inferno Ping (75072) hit  - Self: Talk 0 // "),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: stop attacking // "),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5467.64, -2794.14, 1517.74, 0, " Linked - Self: Move to position (5467.64, -2794.14, 1517.74, 0) (point id 0) // "),
(@ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 7000, 7000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 7000 - 7000 ms // "),
(@ENTRY, 0, 7, 8, 59, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set react state to REACT_AGGRESSIVE // "),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 10, 384466, 0, 0, 0, 0, 0, 0, " Linked - Self: Attack Creature Baron Geddon 40147 (384466) // "),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 1000, 5000, 14000, 20000, 11, 74811, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1000 and 5000 ms (and later repeats every 14000 and 20000 ms) - Self: Cast spell Swipe (74811) on Victim // ");

UPDATE `spell_dbc` SET `RangeIndex`= 13 WHERE `Id`= 75193;

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160092;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectBasePoints`, `EffectMiscValue`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectIndex`, `EffectSpellId`, `Comment`) VALUES
(160092, 90, 0, 40334, 25, 0, 0, 75193, 'Weakening Credit Dummy - Effect 0');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_mh_weakening',
'spell_mh_inferno');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75192, 'spell_mh_weakening'),
(74813, 'spell_mh_inferno');
