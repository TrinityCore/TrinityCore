-- 
UPDATE `gameobject_template` SET `AIName`="" WHERE `entry`=190351;
DELETE FROM `smart_scripts` WHERE `entryorguid`=190351 AND `source_type`=1;
DELETE FROM `spell_scripts` WHERE `id`=50499;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(50499,0,0,15,50493,0,0,0,0,0,0);
