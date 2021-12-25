--
-- resolve branch id conflicts
UPDATE `trinity_string` SET `entry`=1212 WHERE `entry`=1184; -- move LANG_GUILD_INFO_LEVEL to free slot
UPDATE `trinity_string` SET `entry`=1184 WHERE `entry`=1192; -- move LANG_CHANGEACCOUNT_SUCCESS to 3.3.5 slot

UPDATE `trinity_string` SET `entry`=1213 WHERE `entry`=1185; -- move LANG_ACCOUNT_BNET_LINKED to free slot
UPDATE `trinity_string` SET `entry`=1185 WHERE `entry`=1193; -- move LANG_GROUP_NOT_IN_RAID_GROUP to 3.3.5 slot

UPDATE `trinity_string` SET `entry`=1214 WHERE `entry`=1186; -- move LANG_ACCOUNT_OR_BNET_DOES_NOT_EXIST to free slot
UPDATE `trinity_string` SET `entry`=1186 WHERE `entry`=1194; -- move LANG_GROUP_ROLE_CHANGED to 3.3.5 slot

UPDATE `trinity_string` SET `entry`=1215 WHERE `entry`=1187; -- move LANG_ACCOUNT_ALREADY_LINKED to free slot
UPDATE `trinity_string` SET `entry`=1187 WHERE `entry`=1195; -- move LANG_LEADER_CANNOT_BE_ASSISTANT to 3.3.5 slot

UPDATE `trinity_string` SET `entry`=1216 WHERE `entry`=1188; -- move LANG_ACCOUNT_BNET_UNLINKED to free slot
UPDATE `trinity_string` SET `entry`=1188 WHERE `entry`=1191; -- move LANG_BAN_EXISTS to 3.3.5 slot

UPDATE `trinity_string` SET `entry`=1217 WHERE `entry`=1189; -- move LANG_ACCOUNT_BNET_NOT_LINKED to free slot

UPDATE `trinity_string` SET `entry`=1218 WHERE `entry`=1190; -- move LANG_DISALLOW_TICKETS_CONFIG to free slot

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1189 AND 1197;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(1189, "No instances were found matching your input"),
(1190, "Multiple instances match your input - please be more specific:"),
(1191, "│ %04u - %s"),
(1192, "Specified map %u is not instanced"),
(1193, "Could not find entrance portal for map %u (%s)"),
(1194, "Could not find exit portal for map %u (%s)"),
(1195, "Teleported you to the entrance of mapid %u (%s)"),
(1196, "Teleported you to the starting location of mapid %u (%s)"),
(1197, "Failed to teleport you to mapid %u (%s) - missing attunement/expansion for parent map %u?");
