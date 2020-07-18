-- 
UPDATE `creature_addon` SET `bytes2`=2 WHERE `path_id` > 0 AND `guid` IN ( SELECT `guid` FROM `creature` WHERE `id` IN (SELECT `CreatureID` FROM `creature_equip_template` WHERE `ItemID1`=0 AND `ItemID2`=0 AND `ItemID3`>0)) AND `bytes2`=0;
UPDATE `creature_addon` SET `bytes2`=1 WHERE `path_id` > 0 AND `guid` IN ( SELECT `guid` FROM `creature` WHERE `id` IN (SELECT `CreatureID` FROM `creature_equip_template` WHERE `ItemID1`>0)) AND `bytes2`=0;
