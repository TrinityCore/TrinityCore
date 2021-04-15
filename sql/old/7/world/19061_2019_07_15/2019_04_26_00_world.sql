--
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID` IN (25317);
DELETE FROM `quest_template_addon` WHERE `ID` IN (25584);
INSERT INTO `quest_template_addon` (`ID`,`PrevQuestID`,`ProvidedItemCount`) VALUES
(25584,25578,0);
DELETE FROM `quest_template_addon` WHERE `ID` IN (25472);
INSERT INTO `quest_template_addon` (`ID`,`PrevQuestID`,`ProvidedItemCount`) VALUES
(25472,25317,0);
DELETE FROM `quest_template_addon` WHERE `ID` IN (25430);
INSERT INTO `quest_template_addon` (`ID`,`PrevQuestID`,`ProvidedItemCount`) VALUES
(25430,25464,0);

-- Condition for source Gossip menu option condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11451 AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11451, 0, 0, 0, 8, 0, 25578, 0, 0, 0, 0, 0, '', 'Show gossip menu 11451 option id 0 if quest Return to Nordrassil has been rewarded.');

-- Condition for source Gossip menu option condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11451 AND `SourceEntry`=1 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11451, 1, 0, 0, 8, 0, 25578, 0, 0, 0, 0, 0, '', 'Show gossip menu 11451 option id 1 if quest Return to Nordrassil has been rewarded.');

-- Condition for source Gossip menu option condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11451 AND `SourceEntry`=2 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11451, 2, 0, 0, 8, 0, 25578, 0, 0, 0, 0, 0, '', 'Show gossip menu 11451 option id 2 if quest Return to Nordrassil has been rewarded.');

-- Condition for source Gossip menu option condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11451 AND `SourceEntry`=3 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11451, 3, 0, 0, 8, 0, 25578, 0, 0, 0, 0, 0, '', 'Show gossip menu 11451 option id 3 if quest Return to Nordrassil has been rewarded.');

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=38917;

DELETE FROM `spell_area` WHERE `spell`=101311;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,`quest_start_status`,`quest_end_status`) VALUES
(101311,5625,25430,25324,0,0,2,3,74,11);

UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=40139;

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=40178;

DELETE FROM `spell_area` WHERE `spell`=75243;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,`quest_start_status`,`quest_end_status`) VALUES
(75243,5032,25325,25578,0,0,2,3,74,1);

UPDATE `creature_template` SET `HealthScalingExpansion`=2,`faction`=35,`unit_class`=2,`unit_flags`=72 WHERE `entry`=40180;

DELETE FROM `creature_template_addon` WHERE `entry`=40180;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (40180,0,0,0,257,0, '76236');

-- Captain Saynna Stormrunner SAI
SET @ENTRY := 39446;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25325,0,0,0,11,74895,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captain Saynna Stormrunner - Quest accepted - Cast 'Forcecast Summon Fandral'");
