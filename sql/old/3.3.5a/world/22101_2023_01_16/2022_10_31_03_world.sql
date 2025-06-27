-- Let felmyst to fly kek
UPDATE `creature_template_movement` SET `Swim` = 0, `Flight` = 1 WHERE `CreatureId` = 25038;

-- Attempt to make Demonic Vapor (Trail) trigger invisible to players
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=25267;

-- felmyst missing BREATH_EMOTE
DELETE FROM `creature_text` WHERE `CreatureID`=25038 AND `GroupID`=7;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(25038, 7, 0, '%s takes a deep breath.', 41, 0, 100, 0, 0, 0, 20021, 0, 'felmyst - BREATH_EMOTE');
