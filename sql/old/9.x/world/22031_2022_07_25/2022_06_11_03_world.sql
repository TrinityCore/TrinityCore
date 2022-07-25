-- Gossip
DELETE FROM `gossip_menu` WHERE (`MenuID`=23796 AND `TextID`=37252);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23796, 37252, 43345); -- 149626 (Vanguard Battlemage)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=23796 AND `OptionID`=0) OR (`MenuID`=23796 AND `OptionID`=1);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(23796, 0, 0, 'I must help Khadgar. Send me to the Blasted Lands!', 168994, 1, 1, 0, 0, 0, 0, 0, NULL, 0, 44061),
(23796, 1, 0, 'I must help Khadgar. Send me to the Blasted Lands!', 168994, 1, 1, 0, 0, 0, 0, 0, NULL, 0, 44061);

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 23796 AND `SourceEntry` = 37252) OR (`SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 23796 AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 23796 AND `SourceEntry` = 1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(14, 23796, 37252, 0, 0, 47, 0, 34398, 10, 0, 0, 'Show Gossip Menu only if Quest 34398 IS taken/complete'),
(15, 23796, 0, 0, 0, 47, 0, 34398, 10, 0, 0, 'Show Gossip Menu Option 0 only if Quest 34398 IS taken/complete'),
(15, 23796, 0, 0, 0, 6, 0, 469, 0, 0, 0, 'Show Gossip Menu Option 0 only if Player is Alliance'),
(15, 23796, 1, 0, 1, 47, 0, 34398, 10, 0, 0, 'Show Gossip Menu Option 1 only if Quest 34398 IS taken/complete'),
(15, 23796, 1, 0, 1, 6, 0, 67, 0, 0, 0, 'Show Gossip Menu Option 1 only if Player is Horde');

-- SAI Script
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = (149626 /*Vanguard Battlemage*/);

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = 149626;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(149626, 0, 0, 1, 62, 0, 100, 0, 23796, 0, 0, 0, 33, 149625, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'OnGossipSelect 23796 0 - reward Credit 149625 - to Invoker'),
(149626, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 171248, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'SAI Link to 0 - Self Cast: 171248 - to Invoker'),
(149626, 0, 2, 3, 62, 0, 100, 0, 23796, 1, 0, 0, 33, 149625, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'OnGossipSelect 23796 1 - reward Credit 149625 - to Invoker'),
(149626, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 171229, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'SAI Link to 2 - Self Cast: 171229 - to Invoker');

-- Spell Target Position
DELETE FROM `spell_target_position` WHERE `ID` IN (171248, 171229);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(171248, 0, 0, -11265, -3628.56, 10.5727, 0),
(171229, 0, 0, -11788.7, -3855.65, 60.03, 0);
