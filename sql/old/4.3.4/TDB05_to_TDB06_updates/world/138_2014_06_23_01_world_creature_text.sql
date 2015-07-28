UPDATE `creature_text` `A` INNER JOIN `broadcast_text` `B` ON `A`.`BroadcastTextID`=`B`.`ID` SET `A`.`Language`=`B`.`Language`;
