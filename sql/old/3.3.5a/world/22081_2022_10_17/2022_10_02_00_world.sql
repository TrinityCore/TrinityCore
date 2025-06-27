-- *** Quest "Not fit for death" ***
UPDATE `gameobject_template` SET `ScriptName` = 'go_caribou_trap' WHERE `entry` IN (187982,187995,187996,187997,187998,187999,188000,188001,188002,188003,188004,188005,188006,188007,188008);
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q11865_place_fake_fur';
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry`=25835;

-- Conditions missing comment
UPDATE `conditions` SET `Comment` = 'Spell Place Fake Fur (effect 0) will hit the potential target of the spell if target is gameobject Caribou Trap.' WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=46085;
