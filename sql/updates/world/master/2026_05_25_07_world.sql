--
DELETE FROM `spell_area` WHERE `spell` = 57940;

DELETE FROM `reference_loot_template` WHERE `Item` = 43228;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceEntry`= 43228;
