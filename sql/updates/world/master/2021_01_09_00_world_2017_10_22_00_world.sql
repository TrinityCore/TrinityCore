--
UPDATE `creature_template` SET `unit_flags`=512, `ScriptName`="npc_captain_tyralius" WHERE `entry`=20787;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=20825;
DELETE FROM `creature` WHERE `id` IN (20787, 20825);
