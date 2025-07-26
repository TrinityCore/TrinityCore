-- Honor Hold Defender
SET @NPC=16842;
DELETE FROM `creature_equip_template` WHERE `CreatureID`=@NPC;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(@NPC, 1, 12944, 143, 0, 59185),
(@NPC, 2, 1903, 143, 0, 59185);
UPDATE `creature` SET `equipment_id`=2 WHERE `guid`=57933 AND `id`=@NPC;
UPDATE `creature` SET `equipment_id`=0,`npcflag`=`npcflag`|1 WHERE `guid`=57942 AND `id`=@NPC;
UPDATE `creature_template` SET `gossip_menu_id`=7300 WHERE `entry`=@NPC;
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=@NPC;
UPDATE `creature_addon` SET `PvpFlags`=1 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=@NPC);
UPDATE `gossip_menu` SET `VerifiedBuild`=59185 WHERE `MenuID`=7300 AND `TextID`=8656;
-- Stormwind Infantry
UPDATE `creature` SET `equipment_id`=0 WHERE `guid` IN (58143,58148,58146,58152,58145,58150,58144,58147,58141,58151) AND `id`=16864;
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=16864;
UPDATE `creature_addon` SET `PvpFlags`=1 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=16864);
-- Supply Officer Shandria
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=19314;
UPDATE `creature_template` SET `gossip_menu_id`=7957 WHERE `entry`=19314;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=10182, `VerifiedBuild`=59185 WHERE `MenuID`=7957 AND `OptionID`=0;
-- Corporal Ironridge
UPDATE `creature_template_addon` SET `PvpFlags`=1, `emote`=0 WHERE `entry`=21133;
