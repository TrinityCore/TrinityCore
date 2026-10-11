-- Quest items from deprecated quest Id: 116 Dry Times are buyable from vendors on retail
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup` = 274 AND `SourceEntry` = 1942; -- Bottle of Moonshine
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup` = 277 AND `SourceEntry` = 1941; -- Cask of Merlot
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 23 AND `SourceGroup` = 465 AND `SourceEntry` = 1939; -- Skin of Sweet Rum
