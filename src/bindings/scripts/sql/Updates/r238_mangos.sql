-- revert previously bad sql
UPDATE `creature_template` SET `ScriptName` = '' WHERE `ScriptName` LIKE '%innkeeper%' AND `npcflag` & 128<>0;
