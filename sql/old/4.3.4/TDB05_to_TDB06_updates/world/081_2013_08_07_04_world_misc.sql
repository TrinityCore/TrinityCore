-- Move boss_anzu from EAI to CPP
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'boss_anzu' WHERE `entry`=23035;
-- DELETE FROM creature_ai_scripts WHERE `creature_id`=23035; 4.x removed
DELETE FROM `creature_text` WHERE `entry`=23035;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(23035, 0, 0, 'Awaken, my children and assist your master!', 14, 0, 100, 0, 0, 0, 'Anzu - Summon Brood'),
(23035, 1, 0, 'Your spells... ke-kaw... are weak magics... easy to turn against you...', 15, 0, 100, 0, 0, 0, 'Anzu - Spell Bomb'),
(23035, 1, 1, 'Yes... cast your precious little spells, ak-a-ak!', 15, 0, 100, 0, 0, 0, 'Anzu - Spell Bomb');
