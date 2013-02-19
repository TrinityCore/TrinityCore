SET @Gossip :=9640;
SET @NPCText :=13047;

DELETE FROM `gossip_menu` WHERE `entry` = @Gossip;
INSERT INTO `gossip_menu` VALUES
(@Gossip,@NPCText);

DELETE FROM `gossip_menu_option` WHERE `menu_id` = @Gossip;
INSERT INTO `gossip_menu_option` VALUES
(@Gossip,0,0,"Soldier, you have new orders. You're to pull back and report to the sergeant!",1,1,0,0,0,0,NULL);

UPDATE `creature_template` SET `gossip_menu_id` = @Gossip, AIName = 'SmartAI', `npcflag` = `npcflag`|1 WHERE `entry` = 28041;

DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 28041;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28041 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28041*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` VALUES
(28041,0,0,0,0,0,100,0,8000,10000,8000,12000,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0,'Argent Soldier - Combat - Cast Sunder Armor'),
(28041,0,1,2,62,0,100,0,@Gossip,0,0,0,33,28041,0,0,0,0,0,7,0,0,0,0,0,0,0,'Argent Soldier - On Gossip - Credit'),
(28041,0,2,3,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Argent Soldier - Event Linked - Close Gossip'),
(28041,0,3,4,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Argent Soldier - Event Linked - NpcFlag Remove'),
(28041,0,4,0,61,0,100,0,0,0,0,0,80,2804100,0,2,0,0,0,1,0,0,0,0,0,0,0,'Argent Soldier - Event Linked - Run Script'),
(28041*100,9,0,0,0,0,100,0,6000,6000,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Argent Soldier - Script 6 Seconds - Unseen'),
(28041*100,9,1,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Argent Soldier - Script - Despawn');

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId= 15  AND SourceGroup=@Gossip;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, @Gossip, 0, 0, 0, 9, 0, 12504, 0, 0, 0, 0, '', NULL);
