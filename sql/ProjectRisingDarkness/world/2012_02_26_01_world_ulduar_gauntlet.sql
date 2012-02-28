-- Delorah texts
DELETE FROM `creature_text` WHERE `entry` = 33701;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33701, 0, 0, 'I heard a story or two of a Lore Keeper in Uldaman that fit your description. Do you serve a similar purpose?', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_1'),
(33701, 1, 0, 'Frontal defense systems? Is there something I should let Brann know before he has anyone attempt to enter the complex?', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_2'),
(33701, 2, 0, 'Can you detail the nature of these defense systems?', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_3'),
(33701, 3, 0, 'Got it. At least we don\'t have to deal with those orbital emplacements.', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_4'),
(33701, 4, 0, 'Rhydian, make sure you let Brann and Archmage Pentarus know about those defenses immediately.', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_5'),
(33701, 6, 0, 'And you mentioned an imprisoned entity? What is the nature of this entity and what is its status?', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_6'),
(33701, 7, 0, 'Yogg-Saron is here? It sounds like we really will have our hands full then.', 12, 0, 0, 0, 0, 0, 'Dellorah SAY_EVENT_8'),
(33701, 8, 0, 'What... What did you just do, $n?! Brann! Braaaaannn! ', 14, 0, 0, 0, 0, 0, 'Dellorah SAY_BRANN');

-- Norgannon texts
DELETE FROM `creature_text` WHERE `entry` = 33686;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33686, 0, 0, ' I was constructed to serve as a repository for essential information regarding this complex. My primary functions include communicating the status of the frontal defense systems and assessing the status of the entity that this complex was built to imprison.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_1'),
(33686, 1, 0, 'Access to the interior of the complex is currently restricted. Primary defensive emplacements are active. Secondary systems are currently non-active.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_2'),
(33686, 2, 0, 'Compromise of complex detected, security override enabled - query permitted.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_3'),
(33686, 3, 0, 'Primary defensive emplacements consist of iron constructs and Storm Beacons, which will generate additional constructs as necessary. Secondary systems consist of orbital defense emplacements.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_4'),
(33686, 7, 0, 'Entity designate: Yogg-Saron. Security has been compromised. Prison operational status unknown. Unable to contact Watchers for notification purposes.', 12, 0, 0, 0, 0, 0, 'Norgannon SAY_EVENT_8');

-- Lorekeeper gossip set by event
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=33686;
