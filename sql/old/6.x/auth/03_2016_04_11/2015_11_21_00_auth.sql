UPDATE `battlenet_components` SET `Build`=20726 WHERE `Program`='WoW' AND `Platform` IN ('base','Mc64','Win','Wn64') AND `Build`=20574;

UPDATE `realmlist` SET `gamebuild`=20726 WHERE `gamebuild`=20574;
