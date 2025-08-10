-- Conversations
DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (20124,20125,20126,20127,20128));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(20124, 88649, 1251227, 0, 0, 0, 0, 0, 47213), -- Map: 2526 Entry: 196974 (Black Dragonflight Recruiter)
(20125, 88648, 1251225, 0, 0, 0, 0, 0, 47213), -- Map: 2526 Entry: 196977 (Bronze Dragonflight Recruiter)
(20126, 88645, 1251228, 0, 0, 0, 0, 0, 47213), -- Map: 2526 Entry: 196978 (Blue Dragonflight Recruiter)
(20127, 88644, 1251250, 0, 0, 0, 0, 0, 47213), -- Map: 2526 Entry: 196979 (Green Dragonflight Recruiter)
(20128, 88642, 1251240, 0, 0, 0, 0, 0, 47213); -- Map: 2526 Entry: 196981 (Red Dragonflight Recruiter)

DELETE FROM `conversation_template` WHERE `Id` IN (20124, 20125, 20126, 20127, 20128);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(20124, 51804, 0, 47213),
(20125, 51806, 0, 47213),
(20126, 51807, 0, 47213),
(20127, 51808, 0, 47213),
(20128, 51809, 0, 47213);

DELETE FROM `conversation_line_template` WHERE `Id` IN (51804, 51806, 51807, 51808, 51809);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(51804, 0, 0, 0, 47213),
(51806, 0, 0, 0, 47213),
(51807, 0, 0, 0, 47213),
(51808, 0, 0, 0, 47213),
(51809, 0, 0, 0, 47213);

-- Black Dragonflight Recruiter SAI
SET @ENTRY := 196974;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 1, 100, 30, 1, 10, 0, 0, 1, 143, 20124, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Black Dragonflight Recruiter - On line of sight (OOC, Player only) - Start conversation'),
(@ENTRY, 0, 1, 2, 62, 0, 100, 30, 29720, 0, 0, 0, 0, 11, 389516, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Black Dragonflight Recruiter - On gossip select - Cast Black Dragonflight Pledge Pin on player'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 30, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Black Dragonflight Recruiter - On gossip select - Close gossip');

-- Bronze Dragonflight Recruiter SAI
SET @ENTRY := 196977;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 1, 100, 30, 1, 10, 0, 0, 1, 143, 20125, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bronze Dragonflight Recruiter - On line of sight (OOC, Player only) - Start conversation'),
(@ENTRY, 0, 1, 2, 62, 0, 100, 30, 29736, 0, 0, 0, 0, 11, 389512, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bronze Dragonflight Recruiter - On gossip select - Cast Bronze Dragonflight Pledge Pin on player'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 30, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bronze Dragonflight Recruiter - On gossip select - Close gossip');

-- Blue Dragonflight Recruiter SAI
SET @ENTRY := 196978;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 1, 100, 30, 1, 10, 0, 0, 1, 143, 20126, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Blue Dragonflight Recruiter - On line of sight (OOC, Player only) - Start conversation'),
(@ENTRY, 0, 1, 2, 62, 0, 100, 30, 29737, 0, 0, 0, 0, 11, 389521, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Blue Dragonflight Recruiter - On gossip select - Cast Blue Dragonflight Pledge Pin on player'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 30, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Blue Dragonflight Recruiter - On gossip select - Close gossip');

-- Green Dragonflight Recruiter SAI
SET @ENTRY := 196979;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 1, 100, 30, 1, 10, 0, 0, 1, 143, 20127, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Green Dragonflight Recruiter - On line of sight (OOC, Player only) - Start conversation'),
(@ENTRY, 0, 1, 2, 62, 0, 100, 30, 29738, 0, 0, 0, 0, 11, 389536, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Green Dragonflight Recruiter - On gossip select - Cast Green Dragonflight Pledge Pin on player'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 30, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Green Dragonflight Recruiter - On gossip select - Close gossip');

-- Red Dragonflight Recruiter SAI
SET @ENTRY := 196981;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 1, 100, 30, 1, 10, 0, 0, 1, 143, 20128, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Red Dragonflight Recruiter - On line of sight (OOC, Player only) - Start conversation'),
(@ENTRY, 0, 1, 2, 62, 0, 100, 30, 29743, 0, 0, 0, 0, 11, 389501, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Red Dragonflight Recruiter - On gossip select - Cast Red Dragonflight Pledge Pin on player'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 30, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Red Dragonflight Recruiter - On gossip select - Close gossip');

-- Only one buff can be active at a time
SET @SPELL_GROUP_ID := 1124;
DELETE FROM `spell_group` WHERE `id`= @SPELL_GROUP_ID;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(@SPELL_GROUP_ID, 389501),
(@SPELL_GROUP_ID, 389512),
(@SPELL_GROUP_ID, 389516),
(@SPELL_GROUP_ID, 389521),
(@SPELL_GROUP_ID, 389536);

DELETE FROM `spell_group_stack_rules` WHERE `group_id`= @SPELL_GROUP_ID;
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(@SPELL_GROUP_ID, 1);

-- Minor correction to recently added waypoint
SET @CGUID := 1251277;
SET @PATH := (@CGUID) * 10;
SET @POINT := 22;
UPDATE `waypoint_data` SET `position_x`=1632.75, `position_y`=-2959.68 WHERE `id`= @PATH AND `point`= @POINT;
