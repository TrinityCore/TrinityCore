--
UPDATE `creature_template` SET `ScriptName`='npc_anachronos_quest_trigger' WHERE `entry`=15454;
UPDATE `creature_template` SET `ScriptName`='npc_anachronos_the_ancient' WHERE `entry`=15381;
UPDATE `creature_template` SET `ScriptName`='npc_qiraj_war_spawn' WHERE `entry` IN (15414,15422,15423,15424);

INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10570, 11, 0, 0, 'achievement_he_feeds_on_your_tears'),
(10568, 11, 0, 0, 'achievement_he_feeds_on_your_tears');
