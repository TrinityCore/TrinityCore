UPDATE `creature_template` SET `AIName`='', `ScriptName`='boss_nexus_commanders' WHERE `entry` IN(26796,26798);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(26796,26798) AND `source_type`=0;
