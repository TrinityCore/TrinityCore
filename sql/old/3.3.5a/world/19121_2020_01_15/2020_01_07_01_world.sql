DELETE FROM `creature_text` WHERE `CreatureID`=17398;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_nascent_fel_orc' WHERE `entry`=17398;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_fel_orc_neophyte' WHERE `entry`=17429;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17398, 17429) AND `source_type`=0;
