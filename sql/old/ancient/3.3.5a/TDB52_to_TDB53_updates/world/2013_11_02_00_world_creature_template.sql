-- Make invisible some visible Triggers
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (21052,21403,21334,21436,21437,21438,21439,21440);
