UPDATE `realmlist` SET `gamebuild`=19634 WHERE `id`=1;

UPDATE `battlenet_components` SET `Build`=19634 WHERE `Program`='WoW' AND `Platform`='base' AND `Build`=19057;
UPDATE `battlenet_components` SET `Build`=19702 WHERE `Program`='WoW' AND `Platform` IN ('Win','Wn64','Mc64') AND `Build`=19342;
