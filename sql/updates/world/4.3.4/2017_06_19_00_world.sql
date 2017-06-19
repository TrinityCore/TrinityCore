--
UPDATE `creature_template` SET `AIName`='NullCreatureAI' WHERE `entry` IN (27490,27894,28781,30413);
UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (9637,12999,47549);

UPDATE `creature` SET `spawndist`=5 WHERE `guid` IN (51879,51914);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=26391 AND `ConditionValue1`=31145;
