-- 6XX Lothos Riftwaker Should offer access to Molten Core without completing "Attunement to the Core" quest
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5750;
