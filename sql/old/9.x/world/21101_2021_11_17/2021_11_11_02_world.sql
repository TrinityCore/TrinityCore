ALTER TABLE `areatrigger_create_properties` MODIFY `AnimId` int(11) NOT NULL DEFAULT '-1';

-- new 9.1.5 default
UPDATE `areatrigger_create_properties` SET `AnimId`=-1 WHERE `AnimId`=0;
