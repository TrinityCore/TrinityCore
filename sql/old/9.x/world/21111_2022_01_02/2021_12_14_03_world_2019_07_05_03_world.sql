--
UPDATE `creature_template` SET `AIName`="", `ScriptName`="npc_ironhand_guardian" WHERE `entry`=8982;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8982 AND `source_type`=0;
