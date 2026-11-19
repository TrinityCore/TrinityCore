-- 
UPDATE `smart_scripts` SET `action_param1`=15000 WHERE `entryorguid`=30169 AND `source_type`=0 AND `id`=3;
DELETE FROM `spell_scripts` WHERE `id`=56099;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(56099,0,0,15,56135,2,0,0,0,0,0);
