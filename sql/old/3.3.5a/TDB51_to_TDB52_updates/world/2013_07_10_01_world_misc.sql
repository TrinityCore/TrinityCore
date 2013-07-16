UPDATE `creature_template` SET `AIName`= '', `ScriptName` = 'npc_ashtongue_elementalist' WHERE `entry`=23523;
DELETE FROM smart_scripts WHERE entryorguid=23523;

UPDATE `creature_template` SET `AIName`= '', `ScriptName` = 'npc_ashtongue_spiritbinder' WHERE `entry`=23524;
DELETE FROM smart_scripts WHERE entryorguid=23524;
