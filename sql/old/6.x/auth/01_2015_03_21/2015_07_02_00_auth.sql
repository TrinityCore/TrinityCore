UPDATE `realmlist` SET `gamebuild`=20182 WHERE `gamebuild`=19793;
UPDATE `battlenet_components` SET `Build`=20182 WHERE `Program`='WoW' AND `Platform`='base' AND `Build`=19793;
UPDATE `battlenet_components` SET `Build`=20182 WHERE `Program`='WoW' AND `Platform` IN ('Mc64','Win','Wn64') AND `Build`=19865;
