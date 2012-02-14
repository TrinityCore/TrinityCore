UPDATE `achievement_criteria_data` SET `value1`=423 WHERE `value1` IN (335,355) AND `type`=16;

-- Trigger extra flag for [DND] Holiday - Love - Bank/AH/Barber Bunny
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (38340,38341,38342);
