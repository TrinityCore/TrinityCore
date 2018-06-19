-- Table `creature_template`
UPDATE `creature_template` SET `ScriptName` = '' WHERE (entry = 42387);
UPDATE `creature` SET `ScriptName` = 'npc_thug' WHERE guid=215115;
DELETE FROM creature WHERE guid = 214421;