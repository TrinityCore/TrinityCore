-- Delorah texts
DELETE FROM `creature_text` WHERE `entry` = 33701;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33701, 0, 0, 'I heard a story or two of a Lore Keeper in Uldaman that fit your description. Do you serve a similar purpose?', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_1'),
(33701, 1, 0, 'Frontal defense systems? Is there something I should let Brann know before he has anyone attempt to enter the complex?', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_2'),
(33701, 2, 0, 'Can you detail the nature of these defense systems?', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_3'),
(33701, 3, 0, 'Got it. At least we don\'t have to deal with those orbital emplacements.', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_4'),
(33701, 4, 0, 'Rhydian, make sure you let Brann and Archmage Pentarus know about those defenses immediately.', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_5'),
(33701, 5, 0, 'And you mentioned an imprisoned entity? What is the nature of this entity and what is its status?', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_7'),
(33701, 7, 0, 'Yogg-Saron is here? It sounds like we really will have our hands full then.', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_8'),
(33701, 8, 0, 'What... What did you just do, $n?! Brann! Braaaaannn! ', 14, 0, 0, 0, 0, 0, 'Dellorah SAY_BRANN'),
(33701, 9, 0, 'Brann! $n just activated the orbital defense system! If we dont get out here soon, we re going to be toast!', 14, 0, 0, 0, 0, 0, 'Dellorah SAY_BRANN2');

-- Norgannon texts
DELETE FROM `creature_text` WHERE `entry` = 33686;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33686, 0, 0, ' I was constructed to serve as a repository for essential information regarding this complex. My primary functions include communicating the status of the frontal defense systems and assessing the status of the entity that this complex was built to imprison.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_1'),
(33686, 1, 0, 'Access to the interior of the complex is currently restricted. Primary defensive emplacements are active. Secondary systems are currently non-active.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_2'),
(33686, 2, 0, 'Compromise of complex detected, security override enabled - query permitted.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_3'),
(33686, 3, 0, 'Primary defensive emplacements consist of iron constructs and Storm Beacons, which will generate additional constructs as necessary. Secondary systems consist of orbital defense emplacements.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_4'),
(33686, 7, 0, 'Entity designate: Yogg-Saron. Security has been compromised. Prison operational status unknown. Unable to contact Watchers for notification purposes.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_8'),
(33686, 10, 0, 'Deactivate', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_DEACTIVATE');

-- Rhydian emotes
DELETE FROM `creature_text` WHERE `entry` = 33696;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33696, 6, 0, '%s nods.', 16, 0, 0, 0, 0, 0, 'Rhydian SAY_EVENT_6'),
(33696, 11, 0, '%s whispers something to Brann', 16, 0, 0, 0, 0, 0, 'Rhydian SAY_WHISPER');

-- Gountlet
UPDATE `creature_template` SET `ScriptName` = 'npc_gauntlet_generator' WHERE `entry` = 34159;
UPDATE `creature_template` SET `ScriptName`= 'npc_ulduar_lorekeeper' WHERE `entry`= 33686;
UPDATE `creature_template` SET `ScriptName` = 'npc_ulduar_warmage' WHERE entry = 33662;
UPDATE `creature_template` SET `ScriptName` = 'npc_bronzebeard_radio' WHERE entry = 34054;
UPDATE `creature_template` SET `ScriptName` = 'npc_ulduar_engineer' WHERE entry = 33626;

-- Spawns 10/25 NORMAL
DELETE FROM `creature` WHERE `guid` IN (12053578,12053579,12053580,12053581,12053582,12053583,12053584,12053585);
INSERT INTO `creature` VALUES 
('12053578', '27306', '603', '3', '1', '0', '0', '-665.945', '-5.68514', '518.75', '0.538015', '300', '0', '0', '42', '0', '0', '0', '0', '0'),
('12053579', '27306', '603', '3', '1', '0', '0', '-642', '-101.168', '518.75', '6.16147', '300', '0', '0', '42', '0', '0', '0', '0', '0'),
('12053580', '34054', '603', '3', '1', '0', '0', '-79.2613', '112.818', '433.792', '1.6148', '300', '0', '0', '75600', '0', '0', '0', '0', '0'),
('12053581', '34054', '603', '3', '1', '0', '0', '-225.065', '-274.866', '369.466', '1.59124', '300', '0', '0', '75600', '0', '0', '0', '0', '0'),
('12053582', '34054', '603', '3', '1', '0', '0', '83.5056', '-371', '410.819', '1.6423', '300', '0', '0', '75600', '0', '0', '0', '0', '0'),
('12053583', '34054', '603', '3', '1', '0', '0', '317.382', '318.532', '409.802', '3.01675', '300', '0', '0', '75600', '0', '0', '0', '0', '0'),
('12053584', '34054', '603', '3', '1', '0', '0', '138.118', '56.1308', '410.969', '5.81588', '300', '0', '0', '75600', '0', '0', '0', '0', '0'),
('12053585', '34054', '603', '3', '1', '0', '0', '130.321', '-127.606', '410.968', '5.25824', '300', '0', '0', '75600', '0', '0', '0', '0', '0');
