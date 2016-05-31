UPDATE `instance_template` SET `script`='instance_the_stockade' WHERE `map`=34;
-- Bazil Thredd should be the last boss in the instance, not Dextren Ward
UPDATE `instance_encounters` SET `lastEncounterDungeon`=12 WHERE `entry`=539;
UPDATE `instance_encounters` SET `lastEncounterDungeon`=0 WHERE `entry`=540;
