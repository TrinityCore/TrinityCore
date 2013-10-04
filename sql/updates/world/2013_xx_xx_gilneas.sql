/* All data of gilneas */
-- First of all gilneas have 4 maps:
-- 638 [gilneas] -> starting zone with worgen attack
-- 654 [gilneas2] ->outside city forsaken invasion 
-- 655 - 656 -> after cataclism

-- worgen should start at map 638
UPDATE `playercreateinfo` SET  `map` = 638 WHERE `race` = 22;

-- move current creature spawns to correct place
UPDATE `creature` SET `map` = 638 WHERE `id` = 34850;
UPDATE `creature` SET `map` = 638 WHERE `id` = 34851;
UPDATE `creature` SET `map` = 638 WHERE `id` = 34864;
UPDATE `creature` SET `map` = 638 WHERE `id` = 34863;
UPDATE `creature` SET `map` = 638 WHERE `id` = 39095;
UPDATE `creature` SET `map` = 638 WHERE `id` = 44086;
UPDATE `creature` SET `map` = 638 WHERE `id` = 50260;

-- move current object spawns to correct place
UPDATE `gameobject` SET `map` = 638 WHERE `id` = 195581;
UPDATE `gameobject` SET `map` = 638 WHERE `id` = 195327;

-- scipts
UPDATE `creature_template` SET `ScriptName` = 'npc_prince_liam_greymane_1' WHERE `entry` = 34850;

DELETE FROM `creature_text` WHERE `entry` = 34850;
INSERT INTO `creature_text`(`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(34850, 0, 0, 'Stand ready, guards! We don''t know how many intruders we''re dealing with, but the Headlands are overrun and we''re cut off from the harbor towns. Expect to be outnumbered.', 14, 0, 100, 0, 0, 19614, 'PRINCE_LIAM_GREYMANE_1_TALK_1'),
(34850, 1, 0, 'I want the perimeter secured and the gates manned by two guards at all times. No one gets in, no one gets out.', 14, 0, 100, 0, 0, 19615, 'PRINCE_LIAM_GREYMANE_1_TALK_2'),
(34850, 2, 0, 'We protected Gilneas from the Scourge. We protected Gilneas during the Northgate rebellion. We will protect Gilneas from whatever this new threat may be.', 14, 0, 100, 0, 0, 19616, 'PRINCE_LIAM_GREYMANE_1_TALK_3');

UPDATE `creature` SET `phaseMask` = `phaseMask` | 2 WHERE `id` = 34863;
UPDATE `gameobject` SET `phaseMask` = `phaseMask` | 2 WHERE `id` = 195581;
UPDATE `gameobject` SET `phaseMask` = `phaseMask` | 2 WHERE `id` = 195327;
UPDATE `creature_template` SET `ScriptName` = 'npc_lieutenant_walden' WHERE `entry` = 34863;

-- Reserved for more data
