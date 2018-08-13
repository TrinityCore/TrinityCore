SET @NPC_HELIX_LUMBERING_OAF        := 42654;
SET @NPC_HELIX_GEARBREAKER          := 42655;
SET @NPC_SHADOWY_FIGURE             := 42662;
SET @NPC_UNUSED_TUNNELER_VISUAL     := 17234;
SET @NPC_QUARTERMASTER_LEWIS        :=   491;

-- problems:
-- the npc used to trigger the event is summoned by the event, thus retriggering and resummoning
-- It looks visually terrible, while still completing the quest, with double spawns and double text
-- the npcs are already spawned, and are spawned again by the script
-- solution, find an unused invisible dummy, spawn that and attach script to the dummy
-- remove unwanted permanent spawns

UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = @NPC_SHADOWY_FIGURE;
UPDATE `creature_template` SET `ScriptName` = 'npc_shadowy_tower' WHERE `entry` = @NPC_UNUSED_TUNNELER_VISUAL;
	
-- remove lumbering oaf and gearbreaker spawns
DELETE FROM `creature`
WHERE `id` in (@NPC_HELIX_LUMBERING_OAF,@NPC_HELIX_GEARBREAKER);

-- update our shadowy figure to be the invisible dummy
UPDATE `creature`
SET `id` = @NPC_UNUSED_TUNNELER_VISUAL,
`modelid` = 0,
spawndist = 0,
MovementType = 0
WHERE `id` = @NPC_SHADOWY_FIGURE;

-- fix up vendor quartermaster lewis
UPDATE `creature_template`
SET `family` = 0,
`type` = 7
WHERE `entry` = @NPC_QUARTERMASTER_LEWIS;

UPDATE `gossip_menu_option`
SET `OptionType` = 3,
`OptionNpcFlag` = 128
WHERE `MenuId` = 4107
AND `OptionIndex` = 0;
