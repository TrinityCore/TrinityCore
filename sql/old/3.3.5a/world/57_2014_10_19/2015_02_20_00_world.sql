--
DELETE FROM `conditions` WHERE `SourceEntry`=56727;
DELETE FROM `conditions` WHERE `SourceEntry`=36546 AND `SourceGroup`=1;
DELETE FROM `conditions` WHERE `SourceEntry`=58118;
DELETE FROM `conditions` WHERE `SourceEntry`=48397 AND `SourceTypeOrReferenceId`=13;
DELETE FROM `conditions` WHERE `SourceEntry`= 44997 AND `SourceTypeOrReferenceId`=13;
DELETE FROM `conditions` WHERE `SourceEntry`= 70529;
UPDATE `conditions` SET `SourceGroup`=1 WHERE `SourceEntry`=70471;
UPDATE `conditions` SET `SourceGroup`=1 WHERE `SourceEntry`=71310;
UPDATE `smart_scripts` SET `action_param2`=9715 WHERE  `entryorguid`=19172 AND `source_type`=0 AND `id`=10 AND `link`=0;
