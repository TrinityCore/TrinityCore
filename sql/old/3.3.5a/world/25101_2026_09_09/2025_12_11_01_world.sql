-- Ahn'kahar Watcher will only spawn in heroic mode
UPDATE `creature` SET `spawnMask`=`spawnMask`&~1 WHERE `guid` IN (68283,68284) AND `id`=31104;
