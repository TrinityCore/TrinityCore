UPDATE `creature_template` SET `ScriptName`='mob_shu_water_spirit' WHERE `entry`='55212';
UPDATE `creature_template` SET `ScriptName`='npc_li_fei' WHERE `entry`='54135';
UPDATE `creature_template` SET `ScriptName`='boss_li_fei_fight' WHERE `entry`='54734';
DELETE FROM `creature` WHERE `id`='54734';
UPDATE `quest_template` SET `Method`='2' WHERE `Id`='29679';
UPDATE `quest_template` SET `RequiredNpcOrGoCount1`='5' WHERE `Id`='29679';
Delete FROM `creature` where `id` = '65493' and `guid` != '295874';