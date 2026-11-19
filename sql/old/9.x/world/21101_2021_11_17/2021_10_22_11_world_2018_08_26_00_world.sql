DELETE FROM `creature_template_addon` WHERE `entry` IN(23069,23336);
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_illidan_generic_fire' WHERE `entry` IN (23069,23259,23336);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23259,23069,23336) AND `source_type`=0;
