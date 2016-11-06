-- Always for SMART_EVENT_JUST_SUMMONED (Creature can be summoned already charmed by player ie TempSummons)
UPDATE `smart_scripts` SET `event_flags`=`event_flags`|0x200 WHERE `source_type` = 0 AND `event_type`=54;

-- Event linked actions (Many levels of linked calls, do 8 times)
UPDATE `smart_scripts` `ss` LEFT JOIN `smart_scripts` `ssl` ON `ss`.`entryorguid` = `ssl`.`entryorguid` AND `ss`.`source_type` = `ssl`.`source_type` AND `ss`.`id` = `ssl`.`link` SET `ss`.`event_flags`=`ss`.`event_flags`|0x200 WHERE `ss`.`source_type`=0 AND
    `ss`.`event_type` = 61 AND (`ssl`.`event_flags` & 0x200) != 0;
UPDATE `smart_scripts` `ss` LEFT JOIN `smart_scripts` `ssl` ON `ss`.`entryorguid` = `ssl`.`entryorguid` AND `ss`.`source_type` = `ssl`.`source_type` AND `ss`.`id` = `ssl`.`link` SET `ss`.`event_flags`=`ss`.`event_flags`|0x200 WHERE `ss`.`source_type`=0 AND
    `ss`.`event_type` = 61 AND (`ssl`.`event_flags` & 0x200) != 0;
UPDATE `smart_scripts` `ss` LEFT JOIN `smart_scripts` `ssl` ON `ss`.`entryorguid` = `ssl`.`entryorguid` AND `ss`.`source_type` = `ssl`.`source_type` AND `ss`.`id` = `ssl`.`link` SET `ss`.`event_flags`=`ss`.`event_flags`|0x200 WHERE `ss`.`source_type`=0 AND
    `ss`.`event_type` = 61 AND (`ssl`.`event_flags` & 0x200) != 0;
UPDATE `smart_scripts` `ss` LEFT JOIN `smart_scripts` `ssl` ON `ss`.`entryorguid` = `ssl`.`entryorguid` AND `ss`.`source_type` = `ssl`.`source_type` AND `ss`.`id` = `ssl`.`link` SET `ss`.`event_flags`=`ss`.`event_flags`|0x200 WHERE `ss`.`source_type`=0 AND
    `ss`.`event_type` = 61 AND (`ssl`.`event_flags` & 0x200) != 0;
UPDATE `smart_scripts` `ss` LEFT JOIN `smart_scripts` `ssl` ON `ss`.`entryorguid` = `ssl`.`entryorguid` AND `ss`.`source_type` = `ssl`.`source_type` AND `ss`.`id` = `ssl`.`link` SET `ss`.`event_flags`=`ss`.`event_flags`|0x200 WHERE `ss`.`source_type`=0 AND
    `ss`.`event_type` = 61 AND (`ssl`.`event_flags` & 0x200) != 0;
UPDATE `smart_scripts` `ss` LEFT JOIN `smart_scripts` `ssl` ON `ss`.`entryorguid` = `ssl`.`entryorguid` AND `ss`.`source_type` = `ssl`.`source_type` AND `ss`.`id` = `ssl`.`link` SET `ss`.`event_flags`=`ss`.`event_flags`|0x200 WHERE `ss`.`source_type`=0 AND
    `ss`.`event_type` = 61 AND (`ssl`.`event_flags` & 0x200) != 0;
UPDATE `smart_scripts` `ss` LEFT JOIN `smart_scripts` `ssl` ON `ss`.`entryorguid` = `ssl`.`entryorguid` AND `ss`.`source_type` = `ssl`.`source_type` AND `ss`.`id` = `ssl`.`link` SET `ss`.`event_flags`=`ss`.`event_flags`|0x200 WHERE `ss`.`source_type`=0 AND
    `ss`.`event_type` = 61 AND (`ssl`.`event_flags` & 0x200) != 0;
UPDATE `smart_scripts` `ss` LEFT JOIN `smart_scripts` `ssl` ON `ss`.`entryorguid` = `ssl`.`entryorguid` AND `ss`.`source_type` = `ssl`.`source_type` AND `ss`.`id` = `ssl`.`link` SET `ss`.`event_flags`=`ss`.`event_flags`|0x200 WHERE `ss`.`source_type`=0 AND
    `ss`.`event_type` = 61 AND (`ssl`.`event_flags` & 0x200) != 0;

-- Vehicles
UPDATE `smart_scripts` SET `event_flags`=`event_flags`|0x200 WHERE `source_type` = 0 AND `entryorguid` IN (SELECT `entry` FROM `creature_template` WHERE `AIName` = "SmartAI" AND `VehicleId` != 0);
