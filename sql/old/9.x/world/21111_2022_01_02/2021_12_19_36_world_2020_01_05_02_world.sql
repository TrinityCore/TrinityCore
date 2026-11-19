-- 
UPDATE `creature_addon` SET `auras`="45187" WHERE `guid` IN ( 83999, 84002, 84003, 84004, 84005, 84006);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25063) AND `source_type`=0;
DELETE FROM `conditions` WHERE `SourceEntry`=25063 AND `SourceTypeOrReferenceId`=22;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=25063;
DELETE FROM `spell_scripts` WHERE `id`=45188;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(45188,0,0,15,45189,0,0,0,0,0,0);
