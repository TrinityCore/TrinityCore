--
ALTER TABLE `broadcast_text` MODIFY `VerifiedBuild` int(11) NOT NULL DEFAULT '0';

UPDATE `broadcast_text` SET `Text`="$N, I've come to find out how rampant the effects of Fel Moss are throughout Darkshore. The corruption of Teldrassil and our surrounding lands really concerns the druids of the Cenarian Circle, and all Night elves.$B$BIt is my goal to find out why this has happened and to put an end to it.", `VerifiedBuild`=36325 WHERE `ID`=5608;
UPDATE `npc_text` SET `text0_0`="$N, I've come to find out how rampant the effects of Fel Moss are throughout Darkshore. The corruption of Teldrassil and our surrounding lands really concerns the druids of the Cenarian Circle, and all Night elves.$B$BIt is my goal to find out why this has happened and to put an end to it." WHERE `ID`=3334;
