-- Delorah texts
DELETE FROM `creature_text` WHERE `entry` = 33701;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33701, 0, 0, 'I heard a story or two of a Lore Keeper in Uldaman that fit your description. Do you serve a similar purpose?', 12, 0, 0, 0, 0, 0, ''),
(33701, 8, 0, 'What... What did you just do, $n?! Brann! Braaaaannn! ', 14, 0, 0, 0, 0, 0, '');

-- Lorekeeper gossip set by event
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=33686;
