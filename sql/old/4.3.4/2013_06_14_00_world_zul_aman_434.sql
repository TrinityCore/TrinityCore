UPDATE `creature_template` SET `speed_walk`=2.5,`ScriptName`='npc_voljin_zulaman' WHERE `entry`=52924;

DELETE FROM `creature_template_addon` WHERE `entry`=52924;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(52924, 29261, 0x0, 0x1, '');

DELETE FROM `creature_equip_template` WHERE `entry`=52924;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(52924, 1, 53835, 0, 0);

DELETE FROM `creature_text` WHERE `entry` IN (52924,24363);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(52924, 0, 0, 'Follow me, $c. It be takin'' da both of us to open these gates.', 14, 0, 100, 1, 0, 0, 'Vol''jin - SAY_INTRO_1'),
(52924, 1, 0, 'Da ritual to open da gates be requirin'' both of us to hit da gong together.', 14, 0, 100, 1, 0, 0, 'Vol''jin - SAY_INTRO_3'),
(52924, 2, 0, 'Hear me, Zandalari schemers... Da Darkspears and our allies will deny you rulership of da Amani!', 14, 0, 100, 25, 0, 0, 'Vol''jin - SAY_INTRO_3'),
(52924, 3, 0, 'Da Amani know we''re here. Now is da time to attack! ', 14, 0, 100, 5, 0, 0, 'Vol''jin - SAY_INTRO_4'),
(52924, 4, 0, 'Perhaps we''re not ready yet. Speak to me again when you be wantin'' to open da gates.', 14, 0, 100, 1, 0, 0, 'Vol''jin - SAY_INTRO_FAIL'),
(24363, 0, 0, 'Da spirits gonna feast today! Begin da ceremonies, sacrifice da prisoners... make room for our new guests!', 14, 0, 100, 0, 0, 12053, 'Hex Lord Malacrass Trigger - SAY_HEXLOR_INTRO');
