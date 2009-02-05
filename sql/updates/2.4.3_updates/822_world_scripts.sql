UPDATE `creature_template` SET `ScriptName`='npc_kayra_longmane' WHERE `entry`=17969;
DELETE FROM `creature_template_addon` WHERE `entry`=17969;
UPDATE `quest_template` SET specialflags=2 WHERE `entry`=9752;