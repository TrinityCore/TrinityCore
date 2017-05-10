UPDATE `battlenet_components` SET `Build`=20574 WHERE `Program`='WoW' AND `Platform`='base' AND `Build`=20490;
UPDATE `battlenet_components` SET `Build`=20574 WHERE `Program`='WoW' AND `Platform` IN ('Mc64','Win','Wn64') AND `Build`=20490;

UPDATE `realmlist` SET `gamebuild`=20574 WHERE `gamebuild`=20490;
