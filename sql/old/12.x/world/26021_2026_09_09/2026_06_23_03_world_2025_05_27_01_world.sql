--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17826 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_swamplord_muselek' WHERE `entry` = 17826;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17827 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1782700 AND `source_type` = 9;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_claw' WHERE `entry` = 17827;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_swamplord_muselek_move_away_primer';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(31564, 'spell_swamplord_muselek_move_away_primer');

DELETE FROM `creature_formations` WHERE `leaderGUID` = 103246;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(103246,103246,0,0,3,0,0),
(103246,103431,0,0,3,0,0);

UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` IN (17827,20165);

DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (17894,17827,20165);
INSERT INTO `creature_template_gossip` (`CreatureID`,`MenuID`,`VerifiedBuild`) VALUES
(17894,7525,68256); -- Windcaller Claw
