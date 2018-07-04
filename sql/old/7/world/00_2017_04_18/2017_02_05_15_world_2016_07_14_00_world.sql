-- 
UPDATE `creature_equip_template` SET `itemID3`=5870 WHERE `CreatureID` IN (701);
UPDATE `smart_scripts` SET `action_param2`=`action_param2`|2 WHERE `source_type`=0 AND `entryorguid`=7856 AND `id`=0;
UPDATE `creature_equip_template` SET `itemID3`=5856 WHERE `CreatureID` IN (1162);
