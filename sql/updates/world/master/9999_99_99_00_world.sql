-- Northshire Abbey scripts
-- Stormwind Infantry attacks Blackrock Worg
SET @ID := 49869;
UPDATE `creature_template` SET `scriptname` = "npc_stormwind_infantry", `ainame` = "" WHERE `entry` = @ID;

-- Blackrock Worg attacks Stormwind Infantry
SET @ID := 49871;
UPDATE `creature_template` SET `scriptname` = "npc_blackrock_worg", `ainame` = "" WHERE `entry` = @ID;
