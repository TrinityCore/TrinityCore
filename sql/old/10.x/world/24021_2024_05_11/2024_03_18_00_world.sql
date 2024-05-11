-- Template
UPDATE `creature_template` SET `npcflag`=1, `unit_flags3`=16777216 WHERE `entry`=139522; -- Scouting Map

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry`=139522;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(139522, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '274053'); -- 139522 (Scouting Map) - Quest Bang - Zone Choice Map

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=1948;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1948, 27, 2097, 0);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=139522 AND `MenuID`=22725);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(139522, 22725, 53584); -- Scouting Map

UPDATE `gossip_menu_option` SET `GossipOptionID`=48786, `OptionBroadcastTextID`=95541, `VerifiedBuild`=53584 WHERE (`MenuID`=22725 AND `OptionID`=0); -- OptionBroadcastTextID: 95541 - 96633 - 98823

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=14 AND `SourceGroup` = 22725 AND `SourceEntry` = 35144);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(14, 22725, 35144, 0, 0, 47, 0, 47189, 2|8|64, 0, 0, 'Allow Gossip Menu 22725 with TextID 35144 if Quest 47189 is in progress | complete | rewarded');

-- SAI
SET @ENTRY = 121235;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, '', 19, 0, 100, 0, 47099, 0, 0, 0, 85, 247532, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 47099 - Player who accepted quest: Cast spell 247532 on self'),
(@ENTRY, 0, 1, 2, '', 61, 0, 100, 0, 0, 0, 0, 0, 85, 247663, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 47099 - Player who accepted quest: Cast spell 247663 on self'),
(@ENTRY, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 85, 82238, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 47099 - Player who accepted quest: Cast spell 82238 on self'),
(@ENTRY, 0, 3, 0, '', 19, 0, 100, 0, 47189, 0, 0, 0, 85, 269191, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 47189 - Player who accepted quest: Cast spell 269191 on self');

SET @ENTRY = 139522;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, '', 62, 0, 100, 0, 22725, 0, 0, 0, 33, 139522, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Gossip menu select 22725 - reward KillCredit 139522 - to Invoker');
