--
UPDATE `creature_template` SET `ScriptName` = '', `AIName` = 'SmartAI' WHERE `entry` IN (22095, 22307, 18588);
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 19679;
UPDATE `gameobject_template` SET `ScriptName` = '', `AIName` = 'SmartGameObjectAI' WHERE `entry` = 185913;

DELETE FROM `gossip_menu` WHERE `MenuID` = 8021;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(8021, 9895, 0),
(8021, 9896, 0);

-- UPDATE `gossip_menu_option` SET `ActionMenuID` = 7731 WHERE `MenuID` = 7732 AND `OptionID` = 0;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` IN (22095, 22307, 18588)) OR (`source_type` = 1 AND `entryorguid` = 185913);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22095, 0, 0, 0, 6, 0, 75, 0, 0, 0, 0, 0, 11, 39130, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infested Root-Walker - On Just Died - Cast \'Summon Wood Mites\''),
(22095, 0, 1, 0, 0, 0, 100, 0, 15000, 20000, 32000, 38000, 11, 39000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infested Root-Walker - In Combat - Cast \'Regrowth\' (No Repeat)'),
(22307, 0, 0, 0, 6, 0, 75, 0, 0, 0, 0, 0, 11, 39134, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rotting Forest-Rager - On Just Died - Cast \'Summon Lots Of Wood Mites\''),
(22307, 0, 1, 0, 0, 0, 100, 0, 0, 5, 12000, 18000, 11, 15548, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rotting Forest-Rager - In Combat - Cast \'Thunderclap\' (No Repeat)'),
(18588, 0, 0, 0, 0, 0, 100, 0, 2000, 2000, 30000, 30000, 11, 6726, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Floon - In Combat - Cast \'Silence\''),
(18588, 0, 1, 0, 0, 0, 100, 0, 4000, 4000, 5000, 5000, 11, 9672, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Floon - In Combat - Cast \'Frostbolt\''),
(18588, 0, 2, 0, 0, 0, 100, 0, 9000, 9000, 20000, 20000, 11, 11831, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Floon - In Combat - Cast \'Frost Nova\''),
(18588, 0, 3, 4, 62, 0, 100, 0, 7731, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Floon - On Gossip Option 0 Selected - Close Gossip'),
(18588, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 2, 1738, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Floon - On Gossip Option 0 Selected - Set Faction Arrakoa'),
(18588, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Floon - On Gossip Option 0 Selected - Say Line 0'),
(18588, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Floon - On Gossip Option 0 Selected - Start Attacking'),
(18588, 0, 7, 0, 25, 0, 100, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Floon - On Reset - Set Default Faction'),
(185913, 1, 0, 4, 62, 0, 100, 0, 8660, 0, 0, 0, 85, 40632, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skull Pile - On Gossip Option 0 Selected - Invoker Cast \'Summon Gezzarak the Huntress\''),
(185913, 1, 1, 4, 62, 0, 100, 0, 8660, 1, 0, 0, 85, 40642, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skull Pile - On Gossip Option 1 Selected - Invoker Cast \'Summon Darkscreecher Akkarai\''),
(185913, 1, 2, 4, 62, 0, 100, 0, 8660, 2, 0, 0, 85, 40640, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skull Pile - On Gossip Option 2 Selected - Invoker Cast \'Summon Karrog\''),
(185913, 1, 3, 4, 62, 0, 100, 0, 8660, 3, 0, 0, 85, 40644, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skull Pile - On Gossip Option 3 Selected - Invoker Cast \'Summon Vakkiz the Windrager\''),
(185913, 1, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Skull Pile - On Gossip Option Selected - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (7732, 8660);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` = 8021;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 1 AND `SourceEntry` IN (22095, 22307) AND `SourceId` = 0;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 8660, 0, 0, 0, 9, 0, 11885, 0, 0, 0, 0, 0, '', 'Show gossip menu 8660 option id 0 if quest Adversarial Blood has been taken.'),
(15, 8660, 1, 0, 0, 9, 0, 11885, 0, 0, 0, 0, 0, '', 'Show gossip menu 8660 option id 1 if quest Adversarial Blood has been taken.'),
(15, 8660, 2, 0, 0, 9, 0, 11885, 0, 0, 0, 0, 0, '', 'Show gossip menu 8660 option id 2 if quest Adversarial Blood has been taken.'),
(15, 8660, 3, 0, 0, 9, 0, 11885, 0, 0, 0, 0, 0, '', 'Show gossip menu 8660 option id 3 if quest Adversarial Blood has been taken.'),
(15, 8660, 0, 0, 1, 8, 0, 11885, 0, 0, 0, 0, 0, '', 'Show gossip menu 8660 option id 0 if quest Adversarial Blood has been rewarded.'),
(15, 8660, 1, 0, 1, 8, 0, 11885, 0, 0, 0, 0, 0, '', 'Show gossip menu 8660 option id 1 if quest Adversarial Blood has been rewarded.'),
(15, 8660, 2, 0, 1, 8, 0, 11885, 0, 0, 0, 0, 0, '', 'Show gossip menu 8660 option id 2 if quest Adversarial Blood has been rewarded.'),
(15, 8660, 3, 0, 1, 8, 0, 11885, 0, 0, 0, 0, 0, '', 'Show gossip menu 8660 option id 3 if quest Adversarial Blood has been rewarded.'),
(14, 8021, 9896, 0, 0, 5, 0, 933, 240, 0, 0, 0, 0, '', 'Show gossip menu 8021 text id 9896 if player is at least Friendly with The Consortium.'),
(14, 8021, 9895, 0, 0, 5, 0, 933, 240, 0, 1, 0, 0, '', 'Show gossip menu 8021 text id 9895 if player is not at least Friendly with The Consortium.'),
(15, 8021, 0, 0, 0, 5, 0, 933, 240, 0, 0, 0, 0, '', 'Show gossip menu 8021 option id 0 if player is at least Friendly with The Consortium.'),
(15, 7732, 0, 0, 0, 9, 0, 10009, 0, 0, 0, 0, 0, '', 'Show gossip menu 7732 option id 0 if quest Crackin\' Some Skulls has been taken.'),
(22, 1, 22095, 0, 0, 32, 0, 16, 0, 0, 0, 0, 0, '', ' Id 0 of Creature SAI for Infested Root-Walker will execute if invoker is player.'),
(22, 1, 22307, 0, 0, 32, 0, 16, 0, 0, 0, 0, 0, '', ' Id 0 of Creature SAI for Rotting Forest-Rager will execute if invoker is player.');
