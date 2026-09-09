UPDATE `creature_template` SET `RegenHealth`=0, `ScriptName`='npc_pet_dk_risen_ghoul' WHERE `entry`=26125;
UPDATE `creature_template` SET `ScriptName`='npc_pet_dk_bloodworm' WHERE `entry`=28017;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_birth', 'spell_dk_blood_bond_periodic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1217740, 'spell_dk_birth'),
(1267044, 'spell_dk_blood_bond_periodic');
