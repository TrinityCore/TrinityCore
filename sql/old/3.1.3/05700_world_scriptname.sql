-- Sunken temple (already in world_scripts_full.sql)
UPDATE `instance_template` SET `script`='instance_sunken_temple' WHERE `map`=109;
UPDATE `gameobject_template` SET `ScriptName`='go_atalai_statue' WHERE `entry` IN (148830,148831,148832,148833,148834,148835);

UPDATE `creature_template` SET `ScriptName`='boss_twilight_corrupter' WHERE `entry`=15625;

-- quest data: A pawn on the eternal board
-- Already in world_scripts_full.sql
UPDATE `gameobject_template` SET `ScriptName`='go_crystalline_tear' WHERE `entry`=180633;
UPDATE `creature_template` SET `ScriptName`='mob_qiraj_war_spawn' WHERE `entry` IN (15414,15422,15424,15423);
UPDATE `creature_template` SET `ScriptName`='npc_anachronos_the_ancient' WHERE `entry`=15381;
UPDATE `creature_template` SET `ScriptName`='npc_anachronos_quest_trigger' WHERE `entry`=15454;
