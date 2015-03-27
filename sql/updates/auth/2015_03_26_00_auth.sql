UPDATE `realmlist` SET `gamebuild`=19793 WHERE `id`=1;

UPDATE `battlenet_components` SET `Build`=19793 WHERE `Program`='WoW' AND `Platform`='base' AND `Build`=19634;
UPDATE `battlenet_components` SET `Build`=19802 WHERE `Program`='WoW' AND `Platform` IN ('Win','Wn64','Mc64') AND `Build`=19702;
