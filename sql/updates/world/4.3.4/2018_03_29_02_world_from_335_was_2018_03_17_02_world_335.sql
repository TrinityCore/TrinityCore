/*
-- Quest "Onu is Meditating"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=961;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,961,0,0,14,0,944,0,0,1,0,0,"","Show quest 'Onu is Meditating' if quest 'The Master's Glaive' is taken"),
(19,0,961,0,0,14,0,949,0,0,0,0,0,"","Show quest 'Onu is Meditating' only if quest 'The Twilight Camp' is not taken and not rewarded"),
(19,0,961,0,0,2,0,5251,1,1,1,0,0,"","Show quest 'Onu is Meditating' only if player does not have item 'Phial of Scrying'");

DELETE FROM `quest_template_addon` WHERE `ID`=961;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(961,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1);

DELETE FROM `creature_text` WHERE `CreatureID`=3616 AND `GroupID`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3616,3,0,"%s continues his meditations...",16,0,100,0,0,0,1219,0,"Onu");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3616 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3616,0,1,0,20,0,100,0,961,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu - On Quest 'Onu is Meditating' Finished - Say Line 3");
*/
