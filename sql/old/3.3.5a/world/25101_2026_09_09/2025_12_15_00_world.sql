--
UPDATE `quest_offer_reward` SET `Emote1`=0, `Emote2`=0, `Emote3`=0, `Emote4`=0, `RewardText`="Wintergarde is saved because of you, $N. To think that one woman could so swiftly turn the tides of battle is hard for most to comprehend; yet here we are - victorious! You have managed to restore the faith of these people and earned the respect of your commanding officers.$B$B<Halford salutes.>$B$BLord Fordragon has returned to Angrathar to prepare our forces for the destruction of the Wrathgate and has requested that you join him! I couldn't recommend a better soldier for the job, $N.", `VerifiedBuild`=12340 WHERE `ID`=12473;

UPDATE `gameobject` SET `position_x`=-8750.37, `position_y`=-2258.32, `position_z`=155.634, `orientation`=0.453786 WHERE `guid`=18679 AND `id`=1731;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=40969;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=10928;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10928 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES('10928','0','0','0','0','0','100','0','2000','4000','4000','7000','0','11','32202','0','0','0','0','0','2','0','0','0','0','0','0','0','0',"Succubus Minion - In Combat - Cast 'Lash of Pain'");

UPDATE `graveyard_zone` SET `GhostZone`=139, `Comment`="Western Plaguelands, Hearthglen - Eastern Plaguelands" WHERE `ID`=1451;

UPDATE `gameobject_template_addon` SET `faction`=474 WHERE `entry`=184085;

UPDATE `creature` SET `spawnMask`=`spawnMask`|1 WHERE `guid` IN (68283,68284) AND `id`=31104;

UPDATE `quest_template_addon` SET `PrevQuestID`=9898 WHERE `ID`=9899;

DELETE FROM `creature` WHERE `guid`=3564 AND `id`=1135;
DELETE FROM `spawn_group` WHERE `spawnType`=0 AND `spawnId`=3564;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES('3564','1135','0','0','0','1','1','0','0','-5625.61','-178.399','365.835','4.7822','300','0','0','120','0','0','0','0','0','',NULL,'0');
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES('2','0','3564');

UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|4 WHERE `entry` IN (31368, 29306);

UPDATE `npc_vendor` SET `incrtime`=9000 WHERE `entry`=14860 AND `item`=11027;

UPDATE `quest_template_addon` SET `PrevQuestID`=11239 WHERE `ID`=11432;
