ALTER TABLE characters
  ADD COLUMN `exploredZones` longtext AFTER activeSpec,
  ADD COLUMN `equipmentCache` longtext AFTER exploredZones,
  ADD COLUMN `ammoId` int(10) UNSIGNED NOT NULL default '0' AFTER equipmentCache,
  ADD COLUMN `knownTitles` longtext AFTER ammoId;

UPDATE characters SET
exploredZones = SUBSTRING(data,
length(SUBSTRING_INDEX(data, ' ', 1041))+2,
length(SUBSTRING_INDEX(data, ' ', 1168+1))- length(SUBSTRING_INDEX(data, ' ', 1041)) - 1),
equipmentCache = SUBSTRING(data,
length(SUBSTRING_INDEX(data, ' ', 283))+2,
length(SUBSTRING_INDEX(data, ' ', 320+1))- length(SUBSTRING_INDEX(data, ' ', 283)) - 1),
ammoId = SUBSTRING(data,
length(SUBSTRING_INDEX(data, ' ', 1198))+2,
length(SUBSTRING_INDEX(data, ' ', 1198+1))- length(SUBSTRING_INDEX(data, ' ', 1198)) - 1),
knownTitles = SUBSTRING(data,
length(SUBSTRING_INDEX(data, ' ', 626))+2,
length(SUBSTRING_INDEX(data, ' ', 631+1))- length(SUBSTRING_INDEX(data, ' ', 626)) - 1);

ALTER TABLE characters
  DROP COLUMN data;
