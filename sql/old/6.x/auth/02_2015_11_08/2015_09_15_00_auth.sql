UPDATE `battlenet_components` SET `Build`=20490 WHERE `Program`='WoW' AND `Platform`='base' AND `Build`=20444;
UPDATE `battlenet_components` SET `Build`=20490 WHERE `Program`='WoW' AND `Platform` IN ('Mc64','Win','Wn64') AND `Build`=20444;

UPDATE `realmlist` SET `gamebuild`=20490 WHERE `gamebuild`=20444;
